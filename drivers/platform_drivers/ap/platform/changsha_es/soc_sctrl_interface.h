#ifndef __SOC_SCTRL_INTERFACE_H__
#define __SOC_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SCTRL_SCCTRL_ADDR(base) ((base) + (0xF00UL))
#define SOC_SCTRL_STD2LS_CTRL_ADDR(base) ((base) + (0xFB0UL))
#define SOC_SCTRL_DOZE_CTRL_ADDR(base) ((base) + (0xFC8UL))
#define SOC_SCTRL_SCSYSSTAT_ADDR(base) ((base) + (0xF04UL))
#define SOC_SCTRL_SYS_STAT_CTRL_0_ADDR(base) ((base) + (0xF14UL))
#define SOC_SCTRL_SYS_STAT_CTRL_1_ADDR(base) ((base) + (0xF18UL))
#define SOC_SCTRL_SYS_STAT_CTRL_2_ADDR(base) ((base) + (0xF1CUL))
#define SOC_SCTRL_SYS_STAT_CTRL_3_ADDR(base) ((base) + (0xFB4UL))
#define SOC_SCTRL_SYS_STAT_CTRL_4_ADDR(base) ((base) + (0xF10UL))
#define SOC_SCTRL_SYS_STAT_CTRL_5_ADDR(base) ((base) + (0xF20UL))
#define SOC_SCTRL_SYS_STAT_CTRL_6_ADDR(base) ((base) + (0xF24UL))
#define SOC_SCTRL_SC_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xF88UL))
#define SOC_SCTRL_SC_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xF8CUL))
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xF90UL))
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE60UL))
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE64UL))
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE68UL))
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE6CUL))
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE70UL))
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE74UL))
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE78UL))
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE7CUL))
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE80UL))
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE84UL))
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE88UL))
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE8CUL))
#define SOC_SCTRL_SC_PMU_PS_STAT_0_ADDR(base) ((base) + (0xF9CUL))
#define SOC_SCTRL_SC_PMU_PS_STAT_1_ADDR(base) ((base) + (0xF84UL))
#define SOC_SCTRL_SYS_SC_STAT_0_ADDR(base) ((base) + (0xF2CUL))
#define SOC_SCTRL_SYS_SC_STAT_1_ADDR(base) ((base) + (0xFE4UL))
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_ADDR(base) ((base) + (0xE90UL))
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_ADDR(base) ((base) + (0xE94UL))
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_ADDR(base) ((base) + (0xE98UL))
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_ADDR(base) ((base) + (0xE9CUL))
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_ADDR(base) ((base) + (0xEA0UL))
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_ADDR(base) ((base) + (0xFC0UL))
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_ADDR(base) ((base) + (0xFC4UL))
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL1_ADDR(base) ((base) + (0xEACUL))
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL1_ADDR(base) ((base) + (0xEB0UL))
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL1_ADDR(base) ((base) + (0xEB4UL))
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL1_ADDR(base) ((base) + (0xEB8UL))
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL1_ADDR(base) ((base) + (0xEBCUL))
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_ADDR(base) ((base) + (0xEC0UL))
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_ADDR(base) ((base) + (0xEC4UL))
#define SOC_SCTRL_SYS_STAT_CTRL_DBG_ADDR(base) ((base) + (0xEF0UL))
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xF94UL))
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xFD4UL))
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xFD8UL))
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xFBCUL))
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xFDCUL))
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xFE0UL))
#define SOC_SCTRL_SC_DOZE1_VOTE0_ADDR(base) ((base) + (0x028UL))
#define SOC_SCTRL_SC_DOZE1_VOTE1_ADDR(base) ((base) + (0x02CUL))
#define SOC_SCTRL_SC_DOZE1_VOTE2_ADDR(base) ((base) + (0x9A0UL))
#define SOC_SCTRL_SC_DOZE1_VOTE3_ADDR(base) ((base) + (0x9A4UL))
#define SOC_SCTRL_SC_DOZE2_VOTE0_ADDR(base) ((base) + (0x040UL))
#define SOC_SCTRL_SC_DOZE2_VOTE1_ADDR(base) ((base) + (0x044UL))
#define SOC_SCTRL_SC_DOZE2_VOTE2_ADDR(base) ((base) + (0x9A8UL))
#define SOC_SCTRL_SC_DOZE2_VOTE3_ADDR(base) ((base) + (0x9ACUL))
#define SOC_SCTRL_SW_INDICATORS_MASK0_ADDR(base) ((base) + (0xF40UL))
#define SOC_SCTRL_SW_INDICATORS_MASK1_ADDR(base) ((base) + (0xFE8UL))
#define SOC_SCTRL_SW_DDR_IDLE_MASK_ADDR(base) ((base) + (0xF44UL))
#define SOC_SCTRL_DOZE_COUNT_CTRL0_ADDR(base) ((base) + (0xF48UL))
#define SOC_SCTRL_DOZE_COUNT_CTRL_GPU_ADDR(base) ((base) + (0xF4CUL))
#define SOC_SCTRL_DOZE_COUNT_CTRL1_ADDR(base) ((base) + (0xFCCUL))
#define SOC_SCTRL_DOZE_COUNT_CTRL2_ADDR(base) ((base) + (0xFD0UL))
#define SOC_SCTRL_DOZE_COUNT_CTRL3_ADDR(base) ((base) + (0xEA4UL))
#define SOC_SCTRL_DOZE_COUNT_CTRL4_ADDR(base) ((base) + (0xEA8UL))
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_ADDR(base) ((base) + (0xE04UL))
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_ADDR(base) ((base) + (0xE08UL))
#define SOC_SCTRL_DOZE_ARB_STAT_0_ADDR(base) ((base) + (0xF98UL))
#define SOC_SCTRL_DOZE_ARB_STAT_1_ADDR(base) ((base) + (0xFA0UL))
#define SOC_SCTRL_DOZE_ARB_STAT_2_ADDR(base) ((base) + (0xFA4UL))
#define SOC_SCTRL_DOZE_ARB_STAT_3_ADDR(base) ((base) + (0xFA8UL))
#define SOC_SCTRL_DOZE_ARB_STAT_4_ADDR(base) ((base) + (0xFACUL))
#define SOC_SCTRL_DOZE_ARB_STAT_5_ADDR(base) ((base) + (0xFECUL))
#define SOC_SCTRL_DOZE_ARB_STAT_6_ADDR(base) ((base) + (0xFF0UL))
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_ADDR(base) ((base) + (0xFB8UL))
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_ADDR(base) ((base) + (0xF50UL))
#define SOC_SCTRL_SC_TCXO_CTRL_ADDR(base) ((base) + (0xF08UL))
#define SOC_SCTRL_SC_PERI_POWER_STAT_ADDR(base) ((base) + (0xF58UL))
#define SOC_SCTRL_SCPERIISOBYPASS_ADDR(base) ((base) + (0xF5CUL))
#define SOC_SCTRL_DOZE2_FLAG_STAT_ADDR(base) ((base) + (0xE0CUL))
#define SOC_SCTRL_SC_PERI_POWER_CTRL_0_ADDR(base) ((base) + (0xF70UL))
#define SOC_SCTRL_SC_PERI_POWER_CTRL_1_ADDR(base) ((base) + (0xF74UL))
#define SOC_SCTRL_SC_PERI_POWER_CTRL_2_ADDR(base) ((base) + (0xF78UL))
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_ADDR(base) ((base) + (0xF80UL))
#define SOC_SCTRL_SC_LP_STAT_ADDR(base) ((base) + (0x008UL))
#define SOC_SCTRL_SC_LP_STAT_CLR_ADDR(base) ((base) + (0x01CUL))
#define SOC_SCTRL_SC_LP_FLAG_ADDR(base) ((base) + (0x018UL))
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_ADDR(base) ((base) + (0x014UL))
#define SOC_SCTRL_SCEFUSEDATA2_ADDR(base) ((base) + (0x00CUL))
#define SOC_SCTRL_SCEFUSEDATA3_ADDR(base) ((base) + (0x010UL))
#define SOC_SCTRL_SCEFUSEDATA8_ADDR(base) ((base) + (0x060UL))
#define SOC_SCTRL_SCEFUSEDATA9_ADDR(base) ((base) + (0x064UL))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_POR_ADDR(base) ((base) + (0xE50UL))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_ADDR(base) ((base) + (0xE54UL))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_ADDR(base) ((base) + (0xE58UL))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_ADDR(base) ((base) + (0x024UL))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_ADDR(base) ((base) + (0x034UL))
#define SOC_SCTRL_SC_LP_DATA_ADDR(base) ((base) + (0x020UL))
#define SOC_SCTRL_SCLPSTATCFG_ADDR(base) ((base) + (0x038UL))
#define SOC_SCTRL_SC_ASP_PWRCFG0_ADDR(base) ((base) + (0x080UL))
#define SOC_SCTRL_SC_ASP_PWRCFG1_ADDR(base) ((base) + (0x084UL))
#define SOC_SCTRL_SCINT_GATHER_STAT_ADDR(base) ((base) + (0x0A0UL))
#define SOC_SCTRL_SCINT_MASK_ADDR(base) ((base) + (0x0A4UL))
#define SOC_SCTRL_SCINT_STAT_ADDR(base) ((base) + (0x0A8UL))
#define SOC_SCTRL_SCDRX_INT_CFG_ADDR(base) ((base) + (0x0ACUL))
#define SOC_SCTRL_SCLPMCUWFI_INT_ADDR(base) ((base) + (0x0B0UL))
#define SOC_SCTRL_SCINT_MASK1_ADDR(base) ((base) + (0x0B4UL))
#define SOC_SCTRL_SCINT_STAT1_ADDR(base) ((base) + (0x0B8UL))
#define SOC_SCTRL_SCINT_MASK2_ADDR(base) ((base) + (0x0BCUL))
#define SOC_SCTRL_SCINT_STAT2_ADDR(base) ((base) + (0x0C0UL))
#define SOC_SCTRL_SCINT_MASK3_ADDR(base) ((base) + (0x0C4UL))
#define SOC_SCTRL_SCINT_STAT3_ADDR(base) ((base) + (0x0C8UL))
#define SOC_SCTRL_SCINT_MASK4_ADDR(base) ((base) + (0x090UL))
#define SOC_SCTRL_SCINT_STAT4_ADDR(base) ((base) + (0x094UL))
#define SOC_SCTRL_SCINT_MASK5_ADDR(base) ((base) + (0x098UL))
#define SOC_SCTRL_SCINT_STAT5_ADDR(base) ((base) + (0x09CUL))
#define SOC_SCTRL_SCINT_INT_STD2LS_MASK_ADDR(base) ((base) + (0x0D0UL))
#define SOC_SCTRL_SCINT_INT_LS2STD_MASK_ADDR(base) ((base) + (0x0D4UL))
#define SOC_SCTRL_SCPERCTRL0_ADDR(base) ((base) + (0x300UL))
#define SOC_SCTRL_SCPERCTRL1_ADDR(base) ((base) + (0x304UL))
#define SOC_SCTRL_SCPERCTRL2_ADDR(base) ((base) + (0x308UL))
#define SOC_SCTRL_SCPERCTRL3_ADDR(base) ((base) + (0x30CUL))
#define SOC_SCTRL_SCPERCTRL4_ADDR(base) ((base) + (0x310UL))
#define SOC_SCTRL_SCPERCTRL5_ADDR(base) ((base) + (0x314UL))
#define SOC_SCTRL_SCPERCTRL6_ADDR(base) ((base) + (0x318UL))
#define SOC_SCTRL_SCPERCTRL7_ADDR(base) ((base) + (0x31CUL))
#define SOC_SCTRL_SCPERCTRL9_ADDR(base) ((base) + (0x324UL))
#define SOC_SCTRL_SCPERCTRL10_ADDR(base) ((base) + (0x328UL))
#define SOC_SCTRL_SCPERCTRL11_ADDR(base) ((base) + (0x32CUL))
#define SOC_SCTRL_SCPERCTRL12_ADDR(base) ((base) + (0x330UL))
#define SOC_SCTRL_SCPERCTRL13_ADDR(base) ((base) + (0x334UL))
#define SOC_SCTRL_SCPERCTRL14_ADDR(base) ((base) + (0x338UL))
#define SOC_SCTRL_SCPERCTRL15_ADDR(base) ((base) + (0x33CUL))
#define SOC_SCTRL_SCPERCTRL16_ADDR(base) ((base) + (0x340UL))
#define SOC_SCTRL_SCPERCTRL17_ADDR(base) ((base) + (0x344UL))
#define SOC_SCTRL_SCPERSTATUS0_ADDR(base) ((base) + (0x360UL))
#define SOC_SCTRL_SCPERSTATUS1_ADDR(base) ((base) + (0x364UL))
#define SOC_SCTRL_SCPERSTATUS2_ADDR(base) ((base) + (0x368UL))
#define SOC_SCTRL_SCPERSTATUS3_ADDR(base) ((base) + (0x36CUL))
#define SOC_SCTRL_SCPERSTATUS4_ADDR(base) ((base) + (0x370UL))
#define SOC_SCTRL_SCPERSTATUS5_ADDR(base) ((base) + (0x374UL))
#define SOC_SCTRL_SCPERSTATUS6_ADDR(base) ((base) + (0x378UL))
#define SOC_SCTRL_SCPERSTATUS7_ADDR(base) ((base) + (0x37CUL))
#define SOC_SCTRL_SCPERSTATUS8_ADDR(base) ((base) + (0x380UL))
#define SOC_SCTRL_SCPERSTATUS9_ADDR(base) ((base) + (0x384UL))
#define SOC_SCTRL_SCPERSTATUS10_ADDR(base) ((base) + (0x388UL))
#define SOC_SCTRL_SCPERSTATUS11_ADDR(base) ((base) + (0x38CUL))
#define SOC_SCTRL_SCPERSTATUS12_ADDR(base) ((base) + (0x390UL))
#define SOC_SCTRL_SCPERSTATUS13_ADDR(base) ((base) + (0x394UL))
#define SOC_SCTRL_SCPERSTATUS14_ADDR(base) ((base) + (0x398UL))
#define SOC_SCTRL_SCPERSTATUS15_ADDR(base) ((base) + (0x39CUL))
#define SOC_SCTRL_SCINNERSTAT_ADDR(base) ((base) + (0x3A0UL))
#define SOC_SCTRL_SCINNERCTRL_ADDR(base) ((base) + (0x3A4UL))
#define SOC_SCTRL_SCMRBBUSYSTAT_ADDR(base) ((base) + (0x3FCUL))
#define SOC_SCTRL_SCSWADDR_ADDR(base) ((base) + (0x400UL))
#define SOC_SCTRL_SCDDRADDR_ADDR(base) ((base) + (0x404UL))
#define SOC_SCTRL_SCDDRDATA_ADDR(base) ((base) + (0x408UL))
#define SOC_SCTRL_SCBAKDATA0_ADDR(base) ((base) + (0x40CUL))
#define SOC_SCTRL_SCBAKDATA1_ADDR(base) ((base) + (0x410UL))
#define SOC_SCTRL_SCBAKDATA2_ADDR(base) ((base) + (0x414UL))
#define SOC_SCTRL_SCBAKDATA3_ADDR(base) ((base) + (0x418UL))
#define SOC_SCTRL_SCBAKDATA4_ADDR(base) ((base) + (0x41CUL))
#define SOC_SCTRL_SCBAKDATA5_ADDR(base) ((base) + (0x420UL))
#define SOC_SCTRL_SCBAKDATA6_ADDR(base) ((base) + (0x424UL))
#define SOC_SCTRL_SCBAKDATA7_ADDR(base) ((base) + (0x428UL))
#define SOC_SCTRL_SCBAKDATA8_ADDR(base) ((base) + (0x42CUL))
#define SOC_SCTRL_SCBAKDATA9_ADDR(base) ((base) + (0x430UL))
#define SOC_SCTRL_SCBAKDATA10_ADDR(base) ((base) + (0x434UL))
#define SOC_SCTRL_SCBAKDATA11_ADDR(base) ((base) + (0x438UL))
#define SOC_SCTRL_SCBAKDATA12_ADDR(base) ((base) + (0x43CUL))
#define SOC_SCTRL_SCBAKDATA13_ADDR(base) ((base) + (0x440UL))
#define SOC_SCTRL_SCBAKDATA14_ADDR(base) ((base) + (0x444UL))
#define SOC_SCTRL_SCBAKDATA15_ADDR(base) ((base) + (0x448UL))
#define SOC_SCTRL_SCBAKDATA16_ADDR(base) ((base) + (0x44CUL))
#define SOC_SCTRL_SCBAKDATA17_ADDR(base) ((base) + (0x450UL))
#define SOC_SCTRL_SCBAKDATA18_ADDR(base) ((base) + (0x454UL))
#define SOC_SCTRL_SCBAKDATA19_ADDR(base) ((base) + (0x458UL))
#define SOC_SCTRL_SCBAKDATA20_ADDR(base) ((base) + (0x45CUL))
#define SOC_SCTRL_SCBAKDATA21_ADDR(base) ((base) + (0x460UL))
#define SOC_SCTRL_SCBAKDATA22_ADDR(base) ((base) + (0x464UL))
#define SOC_SCTRL_SCBAKDATA23_ADDR(base) ((base) + (0x468UL))
#define SOC_SCTRL_SCBAKDATA24_ADDR(base) ((base) + (0x46CUL))
#define SOC_SCTRL_SCBAKDATA25_ADDR(base) ((base) + (0x470UL))
#define SOC_SCTRL_SCBAKDATA26_ADDR(base) ((base) + (0x474UL))
#define SOC_SCTRL_SCBAKDATA27_ADDR(base) ((base) + (0x478UL))
#define SOC_SCTRL_SCBAKDATA28_ADDR(base) ((base) + (0x47CUL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS0_ADDR(base) ((base) + (0x480UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS1_ADDR(base) ((base) + (0x484UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS2_ADDR(base) ((base) + (0x488UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS3_ADDR(base) ((base) + (0x48CUL))
#define SOC_SCTRL_SCBAKDATA0_MSK_ADDR(base) ((base) + (0x4C0UL))
#define SOC_SCTRL_SCBAKDATA1_MSK_ADDR(base) ((base) + (0x4C4UL))
#define SOC_SCTRL_SCBAKDATA2_MSK_ADDR(base) ((base) + (0x4C8UL))
#define SOC_SCTRL_SCBAKDATA3_MSK_ADDR(base) ((base) + (0x4CCUL))
#define SOC_SCTRL_SCBAKDATA4_MSK_ADDR(base) ((base) + (0x4D0UL))
#define SOC_SCTRL_SCBAKDATA5_MSK_ADDR(base) ((base) + (0x4D4UL))
#define SOC_SCTRL_SCBAKDATA6_MSK_ADDR(base) ((base) + (0x4D8UL))
#define SOC_SCTRL_SCBAKDATA7_MSK_ADDR(base) ((base) + (0x4DCUL))
#define SOC_SCTRL_SCLPMCUCLKEN_ADDR(base) ((base) + (0x960UL))
#define SOC_SCTRL_SCLPMCUCLKDIS_ADDR(base) ((base) + (0x964UL))
#define SOC_SCTRL_SCLPMCUCLKSTAT_ADDR(base) ((base) + (0x968UL))
#define SOC_SCTRL_SCLPMCURSTEN_ADDR(base) ((base) + (0x970UL))
#define SOC_SCTRL_SCLPMCURSTDIS_ADDR(base) ((base) + (0x974UL))
#define SOC_SCTRL_SCLPMCURSTSTAT_ADDR(base) ((base) + (0x978UL))
#define SOC_SCTRL_SCLPMCUCTRL_ADDR(base) ((base) + (0x980UL))
#define SOC_SCTRL_SCLPMCUSTAT_ADDR(base) ((base) + (0x984UL))
#define SOC_SCTRL_SCLPMCURAMCTRL_ADDR(base) ((base) + (0x988UL))
#define SOC_SCTRL_SCBBPDRXSTAT0_ADDR(base) ((base) + (0x530UL))
#define SOC_SCTRL_SCBBPDRXSTAT1_ADDR(base) ((base) + (0x534UL))
#define SOC_SCTRL_SCBBPDRXSTAT2_ADDR(base) ((base) + (0x538UL))
#define SOC_SCTRL_SCBBPDRXSTAT3_ADDR(base) ((base) + (0x53CUL))
#define SOC_SCTRL_SCBBPDRXSTAT4_ADDR(base) ((base) + (0x540UL))
#define SOC_SCTRL_SCA53_EVENT_MASK_ADDR(base) ((base) + (0x550UL))
#define SOC_SCTRL_SCA57_EVENT_MASK_ADDR(base) ((base) + (0x554UL))
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_ADDR(base) ((base) + (0x558UL))
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_ADDR(base) ((base) + (0x55CUL))
#define SOC_SCTRL_SCMCPU_EVENT_MASK_ADDR(base) ((base) + (0x560UL))
#define SOC_SCTRL_SCISPA7_EVENT_MASK_ADDR(base) ((base) + (0x568UL))
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_ADDR(base) ((base) + (0x56CUL))
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_ADDR(base) ((base) + (0x570UL))
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_ADDR(base) ((base) + (0x574UL))
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_ADDR(base) ((base) + (0x578UL))
#define SOC_SCTRL_SCSILS_EVENT_MASK_ADDR(base) ((base) + (0x97CUL))
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_ADDR(base) ((base) + (0x544UL))
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_ADDR(base) ((base) + (0x548UL))
#define SOC_SCTRL_SCEVENT_STAT_ADDR(base) ((base) + (0x564UL))
#define SOC_SCTRL_SCIOMCUCLKCTRL_ADDR(base) ((base) + (0x880UL))
#define SOC_SCTRL_SCIOMCUCLKSTAT_ADDR(base) ((base) + (0x584UL))
#define SOC_SCTRL_SCIOMCUCTRL_ADDR(base) ((base) + (0x588UL))
#define SOC_SCTRL_SCIOMCUSTAT_ADDR(base) ((base) + (0x58CUL))
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_ADDR(base) ((base) + (0x500UL))
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_ADDR(base) ((base) + (0x504UL))
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_ADDR(base) ((base) + (0x508UL))
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_ADDR(base) ((base) + (0x50CUL))
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_ADDR(base) ((base) + (0x510UL))
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_ADDR(base) ((base) + (0x514UL))
#define SOC_SCTRL_SCMDMADDR0_NONSEC_ADDR(base) ((base) + (0x700UL))
#define SOC_SCTRL_SCMDMADDR1_NONSEC_ADDR(base) ((base) + (0x704UL))
#define SOC_SCTRL_SCMDMADDR2_NONSEC_ADDR(base) ((base) + (0x708UL))
#define SOC_SCTRL_SCMDMADDR3_NONSEC_ADDR(base) ((base) + (0x70CUL))
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_ADDR(base) ((base) + (0x8E8UL))
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_ADDR(base) ((base) + (0x8ECUL))
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_ADDR(base) ((base) + (0x8F0UL))
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_ADDR(base) ((base) + (0x8F4UL))
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_ADDR(base) ((base) + (0x8F8UL))
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_ADDR(base) ((base) + (0x8FCUL))
#define SOC_SCTRL_SCJTAG_SEL_ADDR(base) ((base) + (0x800UL))
#define SOC_SCTRL_SCCFG_DJTAG_ADDR(base) ((base) + (0x814UL))
#define SOC_SCTRL_SCCP15_DISABLE_ADDR(base) ((base) + (0x818UL))
#define SOC_SCTRL_SCCFG_ARM_DBGEN_ADDR(base) ((base) + (0x82CUL))
#define SOC_SCTRL_SCARM_DBGEN_STAT_ADDR(base) ((base) + (0x838UL))
#define SOC_SCTRL_SCEFUSECTRL_ADDR(base) ((base) + (0x83CUL))
#define SOC_SCTRL_SCEFUSESEL_ADDR(base) ((base) + (0x840UL))
#define SOC_SCTRL_SCCHIP_ID0_ADDR(base) ((base) + (0x848UL))
#define SOC_SCTRL_SCCHIP_ID1_ADDR(base) ((base) + (0x84CUL))
#define SOC_SCTRL_SCCPUSECCTRL_ADDR(base) ((base) + (0x850UL))
#define SOC_SCTRL_SCISPSECCTRL_ADDR(base) ((base) + (0x830UL))
#define SOC_SCTRL_SCJTAGSD_SW_SEL_ADDR(base) ((base) + (0x854UL))
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_ADDR(base) ((base) + (0x858UL))
#define SOC_SCTRL_SCJTAG_SD_SWD2JTAG_DFX_ADDR(base) ((base) + (0x870UL))
#define SOC_SCTRL_SCJTAG_SYS_SWD2JTAG_DFX_ADDR(base) ((base) + (0x874UL))
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_ADDR(base) ((base) + (0x85CUL))
#define SOC_SCTRL_SCARM_DBG_KEY0_ADDR(base) ((base) + (0x860UL))
#define SOC_SCTRL_SCARM_DBG_KEY1_ADDR(base) ((base) + (0x864UL))
#define SOC_SCTRL_SCARM_DBG_KEY2_ADDR(base) ((base) + (0x868UL))
#define SOC_SCTRL_SCARM_DBG_KEY3_ADDR(base) ((base) + (0x86CUL))
#define SOC_SCTRL_SCARM_DBG_KEY4_ADDR(base) ((base) + (0x884UL))
#define SOC_SCTRL_SCARM_DBG_KEY5_ADDR(base) ((base) + (0x888UL))
#define SOC_SCTRL_SCARM_DBG_KEY6_ADDR(base) ((base) + (0x88CUL))
#define SOC_SCTRL_SCARM_DBG_KEY7_ADDR(base) ((base) + (0x890UL))
#define SOC_SCTRL_SCSPMI1_ADDR0_ADDR(base) ((base) + (0x910UL))
#define SOC_SCTRL_SCSPMIADDR0_ADDR(base) ((base) + (0x920UL))
#define SOC_SCTRL_SCSPMIADDR1_ADDR(base) ((base) + (0x924UL))
#define SOC_SCTRL_SCSPMIADDR2_ADDR(base) ((base) + (0x928UL))
#define SOC_SCTRL_SCSPMIADDR3_ADDR(base) ((base) + (0x92CUL))
#define SOC_SCTRL_SCSPMIADDR4_ADDR(base) ((base) + (0x930UL))
#define SOC_SCTRL_SCSPMIADDR5_ADDR(base) ((base) + (0x934UL))
#define SOC_SCTRL_SCSPMIADDR6_ADDR(base) ((base) + (0x938UL))
#define SOC_SCTRL_SCSPMIADDR7_ADDR(base) ((base) + (0x93CUL))
#define SOC_SCTRL_SCSPMIADDR8_ADDR(base) ((base) + (0x940UL))
#define SOC_SCTRL_SCSPMIADDR9_ADDR(base) ((base) + (0x944UL))
#define SOC_SCTRL_SCSPMIADDR10_ADDR(base) ((base) + (0x948UL))
#define SOC_SCTRL_SCSPMIADDR11_ADDR(base) ((base) + (0x94CUL))
#define SOC_SCTRL_SCSPMIADDR12_ADDR(base) ((base) + (0x950UL))
#define SOC_SCTRL_SCSPMIADDR13_ADDR(base) ((base) + (0x954UL))
#define SOC_SCTRL_SCSPMIADDR14_ADDR(base) ((base) + (0x958UL))
#define SOC_SCTRL_SCSPMIADDR15_ADDR(base) ((base) + (0x95CUL))
#define SOC_SCTRL_SCHISEEGPIOLOCK_ADDR(base) ((base) + (0x894UL))
#define SOC_SCTRL_SCHISEESPILOCK_ADDR(base) ((base) + (0x898UL))
#define SOC_SCTRL_SCHISEEI2CLOCK_ADDR(base) ((base) + (0x89CUL))
#define SOC_SCTRL_SCHISEEIOSEL_ADDR(base) ((base) + (0x8A0UL))
#define SOC_SCTRL_SCPERCTRL0_SEC_ADDR(base) ((base) + (0x8A4UL))
#define SOC_SCTRL_SCPERCTRL1_SEC_ADDR(base) ((base) + (0x8B0UL))
#define SOC_SCTRL_SCPERCTRL2_SEC_ADDR(base) ((base) + (0x8B4UL))
#define SOC_SCTRL_SCPERCTRL3_SEC_ADDR(base) ((base) + (0x8B8UL))
#define SOC_SCTRL_SCPERCTRL4_SEC_ADDR(base) ((base) + (0x8BCUL))
#define SOC_SCTRL_SCPERCTRL5_SEC_ADDR(base) ((base) + (0x8E0UL))
#define SOC_SCTRL_SCPERSTATUS0_SEC_ADDR(base) ((base) + (0x8C0UL))
#define SOC_SCTRL_SCPERSTATUS1_SEC_ADDR(base) ((base) + (0x8C4UL))
#define SOC_SCTRL_SCPERSTATUS2_SEC_ADDR(base) ((base) + (0x8C8UL))
#define SOC_SCTRL_SCPERSTATUS3_SEC_ADDR(base) ((base) + (0x8CCUL))
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_ADDR(base) ((base) + (0x8D0UL))
#define SOC_SCTRL_SC_TCP_VOTE_STAT_ADDR(base) ((base) + (0x8D4UL))
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_ADDR(base) ((base) + (0x8D8UL))
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_ADDR(base) ((base) + (0x8DCUL))
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_ADDR(base) ((base) + (0x8E4UL))
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_ADDR(base) ((base) + (0x808UL))
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_ADDR(base) ((base) + (0x80CUL))
#define SOC_SCTRL_SCSOCID0_ADDR(base) ((base) + (0xE00UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED0_ADDR(base) ((base) + (0xE10UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED1_ADDR(base) ((base) + (0xE14UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED2_ADDR(base) ((base) + (0xE18UL))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED3_ADDR(base) ((base) + (0xE1CUL))
#define SOC_SCTRL_SC_NPU_LPCTRL0_SEC_ADDR(base) ((base) + (0xE20UL))
#define SOC_SCTRL_SC_NPU_LPCTRL1_SEC_ADDR(base) ((base) + (0xE24UL))
#define SOC_SCTRL_SC_NPU_LPCTRL2_SEC_ADDR(base) ((base) + (0xE28UL))
#define SOC_SCTRL_SC_NPU_LPCTRL3_SEC_ADDR(base) ((base) + (0xE2CUL))
#define SOC_SCTRL_SC_NPU_LPCTRL4_SEC_ADDR(base) ((base) + (0xE30UL))
#define SOC_SCTRL_SC_TRACKING_LOG0_ADDR(base) ((base) + (0xE40UL))
#define SOC_SCTRL_SC_TRACKING_LOG1_ADDR(base) ((base) + (0xE44UL))
#define SOC_SCTRL_SC_TRACKING_LOG2_ADDR(base) ((base) + (0xE48UL))
#define SOC_SCTRL_SC_TRACKING_LOG3_ADDR(base) ((base) + (0xE4CUL))
#define SOC_SCTRL_SC_EMU_VERSION_ADDR(base) ((base) + (0xE34UL))
#else
#define SOC_SCTRL_SCCTRL_ADDR(base) ((base) + (0xF00))
#define SOC_SCTRL_STD2LS_CTRL_ADDR(base) ((base) + (0xFB0))
#define SOC_SCTRL_DOZE_CTRL_ADDR(base) ((base) + (0xFC8))
#define SOC_SCTRL_SCSYSSTAT_ADDR(base) ((base) + (0xF04))
#define SOC_SCTRL_SYS_STAT_CTRL_0_ADDR(base) ((base) + (0xF14))
#define SOC_SCTRL_SYS_STAT_CTRL_1_ADDR(base) ((base) + (0xF18))
#define SOC_SCTRL_SYS_STAT_CTRL_2_ADDR(base) ((base) + (0xF1C))
#define SOC_SCTRL_SYS_STAT_CTRL_3_ADDR(base) ((base) + (0xFB4))
#define SOC_SCTRL_SYS_STAT_CTRL_4_ADDR(base) ((base) + (0xF10))
#define SOC_SCTRL_SYS_STAT_CTRL_5_ADDR(base) ((base) + (0xF20))
#define SOC_SCTRL_SYS_STAT_CTRL_6_ADDR(base) ((base) + (0xF24))
#define SOC_SCTRL_SC_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xF88))
#define SOC_SCTRL_SC_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xF8C))
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xF90))
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE60))
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE64))
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE68))
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE6C))
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE70))
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE74))
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE78))
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE7C))
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE80))
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xE84))
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xE88))
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xE8C))
#define SOC_SCTRL_SC_PMU_PS_STAT_0_ADDR(base) ((base) + (0xF9C))
#define SOC_SCTRL_SC_PMU_PS_STAT_1_ADDR(base) ((base) + (0xF84))
#define SOC_SCTRL_SYS_SC_STAT_0_ADDR(base) ((base) + (0xF2C))
#define SOC_SCTRL_SYS_SC_STAT_1_ADDR(base) ((base) + (0xFE4))
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_ADDR(base) ((base) + (0xE90))
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_ADDR(base) ((base) + (0xE94))
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_ADDR(base) ((base) + (0xE98))
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_ADDR(base) ((base) + (0xE9C))
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_ADDR(base) ((base) + (0xEA0))
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_ADDR(base) ((base) + (0xFC0))
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_ADDR(base) ((base) + (0xFC4))
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL1_ADDR(base) ((base) + (0xEAC))
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL1_ADDR(base) ((base) + (0xEB0))
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL1_ADDR(base) ((base) + (0xEB4))
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL1_ADDR(base) ((base) + (0xEB8))
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL1_ADDR(base) ((base) + (0xEBC))
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_ADDR(base) ((base) + (0xEC0))
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_ADDR(base) ((base) + (0xEC4))
#define SOC_SCTRL_SYS_STAT_CTRL_DBG_ADDR(base) ((base) + (0xEF0))
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xF94))
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xFD4))
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xFD8))
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_ADDR(base) ((base) + (0xFBC))
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_1_ADDR(base) ((base) + (0xFDC))
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_2_ADDR(base) ((base) + (0xFE0))
#define SOC_SCTRL_SC_DOZE1_VOTE0_ADDR(base) ((base) + (0x028))
#define SOC_SCTRL_SC_DOZE1_VOTE1_ADDR(base) ((base) + (0x02C))
#define SOC_SCTRL_SC_DOZE1_VOTE2_ADDR(base) ((base) + (0x9A0))
#define SOC_SCTRL_SC_DOZE1_VOTE3_ADDR(base) ((base) + (0x9A4))
#define SOC_SCTRL_SC_DOZE2_VOTE0_ADDR(base) ((base) + (0x040))
#define SOC_SCTRL_SC_DOZE2_VOTE1_ADDR(base) ((base) + (0x044))
#define SOC_SCTRL_SC_DOZE2_VOTE2_ADDR(base) ((base) + (0x9A8))
#define SOC_SCTRL_SC_DOZE2_VOTE3_ADDR(base) ((base) + (0x9AC))
#define SOC_SCTRL_SW_INDICATORS_MASK0_ADDR(base) ((base) + (0xF40))
#define SOC_SCTRL_SW_INDICATORS_MASK1_ADDR(base) ((base) + (0xFE8))
#define SOC_SCTRL_SW_DDR_IDLE_MASK_ADDR(base) ((base) + (0xF44))
#define SOC_SCTRL_DOZE_COUNT_CTRL0_ADDR(base) ((base) + (0xF48))
#define SOC_SCTRL_DOZE_COUNT_CTRL_GPU_ADDR(base) ((base) + (0xF4C))
#define SOC_SCTRL_DOZE_COUNT_CTRL1_ADDR(base) ((base) + (0xFCC))
#define SOC_SCTRL_DOZE_COUNT_CTRL2_ADDR(base) ((base) + (0xFD0))
#define SOC_SCTRL_DOZE_COUNT_CTRL3_ADDR(base) ((base) + (0xEA4))
#define SOC_SCTRL_DOZE_COUNT_CTRL4_ADDR(base) ((base) + (0xEA8))
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_ADDR(base) ((base) + (0xE04))
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_ADDR(base) ((base) + (0xE08))
#define SOC_SCTRL_DOZE_ARB_STAT_0_ADDR(base) ((base) + (0xF98))
#define SOC_SCTRL_DOZE_ARB_STAT_1_ADDR(base) ((base) + (0xFA0))
#define SOC_SCTRL_DOZE_ARB_STAT_2_ADDR(base) ((base) + (0xFA4))
#define SOC_SCTRL_DOZE_ARB_STAT_3_ADDR(base) ((base) + (0xFA8))
#define SOC_SCTRL_DOZE_ARB_STAT_4_ADDR(base) ((base) + (0xFAC))
#define SOC_SCTRL_DOZE_ARB_STAT_5_ADDR(base) ((base) + (0xFEC))
#define SOC_SCTRL_DOZE_ARB_STAT_6_ADDR(base) ((base) + (0xFF0))
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_ADDR(base) ((base) + (0xFB8))
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_ADDR(base) ((base) + (0xF50))
#define SOC_SCTRL_SC_TCXO_CTRL_ADDR(base) ((base) + (0xF08))
#define SOC_SCTRL_SC_PERI_POWER_STAT_ADDR(base) ((base) + (0xF58))
#define SOC_SCTRL_SCPERIISOBYPASS_ADDR(base) ((base) + (0xF5C))
#define SOC_SCTRL_DOZE2_FLAG_STAT_ADDR(base) ((base) + (0xE0C))
#define SOC_SCTRL_SC_PERI_POWER_CTRL_0_ADDR(base) ((base) + (0xF70))
#define SOC_SCTRL_SC_PERI_POWER_CTRL_1_ADDR(base) ((base) + (0xF74))
#define SOC_SCTRL_SC_PERI_POWER_CTRL_2_ADDR(base) ((base) + (0xF78))
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_ADDR(base) ((base) + (0xF80))
#define SOC_SCTRL_SC_LP_STAT_ADDR(base) ((base) + (0x008))
#define SOC_SCTRL_SC_LP_STAT_CLR_ADDR(base) ((base) + (0x01C))
#define SOC_SCTRL_SC_LP_FLAG_ADDR(base) ((base) + (0x018))
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_ADDR(base) ((base) + (0x014))
#define SOC_SCTRL_SCEFUSEDATA2_ADDR(base) ((base) + (0x00C))
#define SOC_SCTRL_SCEFUSEDATA3_ADDR(base) ((base) + (0x010))
#define SOC_SCTRL_SCEFUSEDATA8_ADDR(base) ((base) + (0x060))
#define SOC_SCTRL_SCEFUSEDATA9_ADDR(base) ((base) + (0x064))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_POR_ADDR(base) ((base) + (0xE50))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_ADDR(base) ((base) + (0xE54))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_ADDR(base) ((base) + (0xE58))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_ADDR(base) ((base) + (0x024))
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_ADDR(base) ((base) + (0x034))
#define SOC_SCTRL_SC_LP_DATA_ADDR(base) ((base) + (0x020))
#define SOC_SCTRL_SCLPSTATCFG_ADDR(base) ((base) + (0x038))
#define SOC_SCTRL_SC_ASP_PWRCFG0_ADDR(base) ((base) + (0x080))
#define SOC_SCTRL_SC_ASP_PWRCFG1_ADDR(base) ((base) + (0x084))
#define SOC_SCTRL_SCINT_GATHER_STAT_ADDR(base) ((base) + (0x0A0))
#define SOC_SCTRL_SCINT_MASK_ADDR(base) ((base) + (0x0A4))
#define SOC_SCTRL_SCINT_STAT_ADDR(base) ((base) + (0x0A8))
#define SOC_SCTRL_SCDRX_INT_CFG_ADDR(base) ((base) + (0x0AC))
#define SOC_SCTRL_SCLPMCUWFI_INT_ADDR(base) ((base) + (0x0B0))
#define SOC_SCTRL_SCINT_MASK1_ADDR(base) ((base) + (0x0B4))
#define SOC_SCTRL_SCINT_STAT1_ADDR(base) ((base) + (0x0B8))
#define SOC_SCTRL_SCINT_MASK2_ADDR(base) ((base) + (0x0BC))
#define SOC_SCTRL_SCINT_STAT2_ADDR(base) ((base) + (0x0C0))
#define SOC_SCTRL_SCINT_MASK3_ADDR(base) ((base) + (0x0C4))
#define SOC_SCTRL_SCINT_STAT3_ADDR(base) ((base) + (0x0C8))
#define SOC_SCTRL_SCINT_MASK4_ADDR(base) ((base) + (0x090))
#define SOC_SCTRL_SCINT_STAT4_ADDR(base) ((base) + (0x094))
#define SOC_SCTRL_SCINT_MASK5_ADDR(base) ((base) + (0x098))
#define SOC_SCTRL_SCINT_STAT5_ADDR(base) ((base) + (0x09C))
#define SOC_SCTRL_SCINT_INT_STD2LS_MASK_ADDR(base) ((base) + (0x0D0))
#define SOC_SCTRL_SCINT_INT_LS2STD_MASK_ADDR(base) ((base) + (0x0D4))
#define SOC_SCTRL_SCPERCTRL0_ADDR(base) ((base) + (0x300))
#define SOC_SCTRL_SCPERCTRL1_ADDR(base) ((base) + (0x304))
#define SOC_SCTRL_SCPERCTRL2_ADDR(base) ((base) + (0x308))
#define SOC_SCTRL_SCPERCTRL3_ADDR(base) ((base) + (0x30C))
#define SOC_SCTRL_SCPERCTRL4_ADDR(base) ((base) + (0x310))
#define SOC_SCTRL_SCPERCTRL5_ADDR(base) ((base) + (0x314))
#define SOC_SCTRL_SCPERCTRL6_ADDR(base) ((base) + (0x318))
#define SOC_SCTRL_SCPERCTRL7_ADDR(base) ((base) + (0x31C))
#define SOC_SCTRL_SCPERCTRL9_ADDR(base) ((base) + (0x324))
#define SOC_SCTRL_SCPERCTRL10_ADDR(base) ((base) + (0x328))
#define SOC_SCTRL_SCPERCTRL11_ADDR(base) ((base) + (0x32C))
#define SOC_SCTRL_SCPERCTRL12_ADDR(base) ((base) + (0x330))
#define SOC_SCTRL_SCPERCTRL13_ADDR(base) ((base) + (0x334))
#define SOC_SCTRL_SCPERCTRL14_ADDR(base) ((base) + (0x338))
#define SOC_SCTRL_SCPERCTRL15_ADDR(base) ((base) + (0x33C))
#define SOC_SCTRL_SCPERCTRL16_ADDR(base) ((base) + (0x340))
#define SOC_SCTRL_SCPERCTRL17_ADDR(base) ((base) + (0x344))
#define SOC_SCTRL_SCPERSTATUS0_ADDR(base) ((base) + (0x360))
#define SOC_SCTRL_SCPERSTATUS1_ADDR(base) ((base) + (0x364))
#define SOC_SCTRL_SCPERSTATUS2_ADDR(base) ((base) + (0x368))
#define SOC_SCTRL_SCPERSTATUS3_ADDR(base) ((base) + (0x36C))
#define SOC_SCTRL_SCPERSTATUS4_ADDR(base) ((base) + (0x370))
#define SOC_SCTRL_SCPERSTATUS5_ADDR(base) ((base) + (0x374))
#define SOC_SCTRL_SCPERSTATUS6_ADDR(base) ((base) + (0x378))
#define SOC_SCTRL_SCPERSTATUS7_ADDR(base) ((base) + (0x37C))
#define SOC_SCTRL_SCPERSTATUS8_ADDR(base) ((base) + (0x380))
#define SOC_SCTRL_SCPERSTATUS9_ADDR(base) ((base) + (0x384))
#define SOC_SCTRL_SCPERSTATUS10_ADDR(base) ((base) + (0x388))
#define SOC_SCTRL_SCPERSTATUS11_ADDR(base) ((base) + (0x38C))
#define SOC_SCTRL_SCPERSTATUS12_ADDR(base) ((base) + (0x390))
#define SOC_SCTRL_SCPERSTATUS13_ADDR(base) ((base) + (0x394))
#define SOC_SCTRL_SCPERSTATUS14_ADDR(base) ((base) + (0x398))
#define SOC_SCTRL_SCPERSTATUS15_ADDR(base) ((base) + (0x39C))
#define SOC_SCTRL_SCINNERSTAT_ADDR(base) ((base) + (0x3A0))
#define SOC_SCTRL_SCINNERCTRL_ADDR(base) ((base) + (0x3A4))
#define SOC_SCTRL_SCMRBBUSYSTAT_ADDR(base) ((base) + (0x3FC))
#define SOC_SCTRL_SCSWADDR_ADDR(base) ((base) + (0x400))
#define SOC_SCTRL_SCDDRADDR_ADDR(base) ((base) + (0x404))
#define SOC_SCTRL_SCDDRDATA_ADDR(base) ((base) + (0x408))
#define SOC_SCTRL_SCBAKDATA0_ADDR(base) ((base) + (0x40C))
#define SOC_SCTRL_SCBAKDATA1_ADDR(base) ((base) + (0x410))
#define SOC_SCTRL_SCBAKDATA2_ADDR(base) ((base) + (0x414))
#define SOC_SCTRL_SCBAKDATA3_ADDR(base) ((base) + (0x418))
#define SOC_SCTRL_SCBAKDATA4_ADDR(base) ((base) + (0x41C))
#define SOC_SCTRL_SCBAKDATA5_ADDR(base) ((base) + (0x420))
#define SOC_SCTRL_SCBAKDATA6_ADDR(base) ((base) + (0x424))
#define SOC_SCTRL_SCBAKDATA7_ADDR(base) ((base) + (0x428))
#define SOC_SCTRL_SCBAKDATA8_ADDR(base) ((base) + (0x42C))
#define SOC_SCTRL_SCBAKDATA9_ADDR(base) ((base) + (0x430))
#define SOC_SCTRL_SCBAKDATA10_ADDR(base) ((base) + (0x434))
#define SOC_SCTRL_SCBAKDATA11_ADDR(base) ((base) + (0x438))
#define SOC_SCTRL_SCBAKDATA12_ADDR(base) ((base) + (0x43C))
#define SOC_SCTRL_SCBAKDATA13_ADDR(base) ((base) + (0x440))
#define SOC_SCTRL_SCBAKDATA14_ADDR(base) ((base) + (0x444))
#define SOC_SCTRL_SCBAKDATA15_ADDR(base) ((base) + (0x448))
#define SOC_SCTRL_SCBAKDATA16_ADDR(base) ((base) + (0x44C))
#define SOC_SCTRL_SCBAKDATA17_ADDR(base) ((base) + (0x450))
#define SOC_SCTRL_SCBAKDATA18_ADDR(base) ((base) + (0x454))
#define SOC_SCTRL_SCBAKDATA19_ADDR(base) ((base) + (0x458))
#define SOC_SCTRL_SCBAKDATA20_ADDR(base) ((base) + (0x45C))
#define SOC_SCTRL_SCBAKDATA21_ADDR(base) ((base) + (0x460))
#define SOC_SCTRL_SCBAKDATA22_ADDR(base) ((base) + (0x464))
#define SOC_SCTRL_SCBAKDATA23_ADDR(base) ((base) + (0x468))
#define SOC_SCTRL_SCBAKDATA24_ADDR(base) ((base) + (0x46C))
#define SOC_SCTRL_SCBAKDATA25_ADDR(base) ((base) + (0x470))
#define SOC_SCTRL_SCBAKDATA26_ADDR(base) ((base) + (0x474))
#define SOC_SCTRL_SCBAKDATA27_ADDR(base) ((base) + (0x478))
#define SOC_SCTRL_SCBAKDATA28_ADDR(base) ((base) + (0x47C))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS0_ADDR(base) ((base) + (0x480))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS1_ADDR(base) ((base) + (0x484))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS2_ADDR(base) ((base) + (0x488))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS3_ADDR(base) ((base) + (0x48C))
#define SOC_SCTRL_SCBAKDATA0_MSK_ADDR(base) ((base) + (0x4C0))
#define SOC_SCTRL_SCBAKDATA1_MSK_ADDR(base) ((base) + (0x4C4))
#define SOC_SCTRL_SCBAKDATA2_MSK_ADDR(base) ((base) + (0x4C8))
#define SOC_SCTRL_SCBAKDATA3_MSK_ADDR(base) ((base) + (0x4CC))
#define SOC_SCTRL_SCBAKDATA4_MSK_ADDR(base) ((base) + (0x4D0))
#define SOC_SCTRL_SCBAKDATA5_MSK_ADDR(base) ((base) + (0x4D4))
#define SOC_SCTRL_SCBAKDATA6_MSK_ADDR(base) ((base) + (0x4D8))
#define SOC_SCTRL_SCBAKDATA7_MSK_ADDR(base) ((base) + (0x4DC))
#define SOC_SCTRL_SCLPMCUCLKEN_ADDR(base) ((base) + (0x960))
#define SOC_SCTRL_SCLPMCUCLKDIS_ADDR(base) ((base) + (0x964))
#define SOC_SCTRL_SCLPMCUCLKSTAT_ADDR(base) ((base) + (0x968))
#define SOC_SCTRL_SCLPMCURSTEN_ADDR(base) ((base) + (0x970))
#define SOC_SCTRL_SCLPMCURSTDIS_ADDR(base) ((base) + (0x974))
#define SOC_SCTRL_SCLPMCURSTSTAT_ADDR(base) ((base) + (0x978))
#define SOC_SCTRL_SCLPMCUCTRL_ADDR(base) ((base) + (0x980))
#define SOC_SCTRL_SCLPMCUSTAT_ADDR(base) ((base) + (0x984))
#define SOC_SCTRL_SCLPMCURAMCTRL_ADDR(base) ((base) + (0x988))
#define SOC_SCTRL_SCBBPDRXSTAT0_ADDR(base) ((base) + (0x530))
#define SOC_SCTRL_SCBBPDRXSTAT1_ADDR(base) ((base) + (0x534))
#define SOC_SCTRL_SCBBPDRXSTAT2_ADDR(base) ((base) + (0x538))
#define SOC_SCTRL_SCBBPDRXSTAT3_ADDR(base) ((base) + (0x53C))
#define SOC_SCTRL_SCBBPDRXSTAT4_ADDR(base) ((base) + (0x540))
#define SOC_SCTRL_SCA53_EVENT_MASK_ADDR(base) ((base) + (0x550))
#define SOC_SCTRL_SCA57_EVENT_MASK_ADDR(base) ((base) + (0x554))
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_ADDR(base) ((base) + (0x558))
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_ADDR(base) ((base) + (0x55C))
#define SOC_SCTRL_SCMCPU_EVENT_MASK_ADDR(base) ((base) + (0x560))
#define SOC_SCTRL_SCISPA7_EVENT_MASK_ADDR(base) ((base) + (0x568))
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_ADDR(base) ((base) + (0x56C))
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_ADDR(base) ((base) + (0x570))
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_ADDR(base) ((base) + (0x574))
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_ADDR(base) ((base) + (0x578))
#define SOC_SCTRL_SCSILS_EVENT_MASK_ADDR(base) ((base) + (0x97C))
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_ADDR(base) ((base) + (0x544))
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_ADDR(base) ((base) + (0x548))
#define SOC_SCTRL_SCEVENT_STAT_ADDR(base) ((base) + (0x564))
#define SOC_SCTRL_SCIOMCUCLKCTRL_ADDR(base) ((base) + (0x880))
#define SOC_SCTRL_SCIOMCUCLKSTAT_ADDR(base) ((base) + (0x584))
#define SOC_SCTRL_SCIOMCUCTRL_ADDR(base) ((base) + (0x588))
#define SOC_SCTRL_SCIOMCUSTAT_ADDR(base) ((base) + (0x58C))
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_ADDR(base) ((base) + (0x500))
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_ADDR(base) ((base) + (0x504))
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_ADDR(base) ((base) + (0x508))
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_ADDR(base) ((base) + (0x50C))
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_ADDR(base) ((base) + (0x510))
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_ADDR(base) ((base) + (0x514))
#define SOC_SCTRL_SCMDMADDR0_NONSEC_ADDR(base) ((base) + (0x700))
#define SOC_SCTRL_SCMDMADDR1_NONSEC_ADDR(base) ((base) + (0x704))
#define SOC_SCTRL_SCMDMADDR2_NONSEC_ADDR(base) ((base) + (0x708))
#define SOC_SCTRL_SCMDMADDR3_NONSEC_ADDR(base) ((base) + (0x70C))
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_ADDR(base) ((base) + (0x8E8))
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_ADDR(base) ((base) + (0x8EC))
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_ADDR(base) ((base) + (0x8F0))
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_ADDR(base) ((base) + (0x8F4))
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_ADDR(base) ((base) + (0x8F8))
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_ADDR(base) ((base) + (0x8FC))
#define SOC_SCTRL_SCJTAG_SEL_ADDR(base) ((base) + (0x800))
#define SOC_SCTRL_SCCFG_DJTAG_ADDR(base) ((base) + (0x814))
#define SOC_SCTRL_SCCP15_DISABLE_ADDR(base) ((base) + (0x818))
#define SOC_SCTRL_SCCFG_ARM_DBGEN_ADDR(base) ((base) + (0x82C))
#define SOC_SCTRL_SCARM_DBGEN_STAT_ADDR(base) ((base) + (0x838))
#define SOC_SCTRL_SCEFUSECTRL_ADDR(base) ((base) + (0x83C))
#define SOC_SCTRL_SCEFUSESEL_ADDR(base) ((base) + (0x840))
#define SOC_SCTRL_SCCHIP_ID0_ADDR(base) ((base) + (0x848))
#define SOC_SCTRL_SCCHIP_ID1_ADDR(base) ((base) + (0x84C))
#define SOC_SCTRL_SCCPUSECCTRL_ADDR(base) ((base) + (0x850))
#define SOC_SCTRL_SCISPSECCTRL_ADDR(base) ((base) + (0x830))
#define SOC_SCTRL_SCJTAGSD_SW_SEL_ADDR(base) ((base) + (0x854))
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_ADDR(base) ((base) + (0x858))
#define SOC_SCTRL_SCJTAG_SD_SWD2JTAG_DFX_ADDR(base) ((base) + (0x870))
#define SOC_SCTRL_SCJTAG_SYS_SWD2JTAG_DFX_ADDR(base) ((base) + (0x874))
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_ADDR(base) ((base) + (0x85C))
#define SOC_SCTRL_SCARM_DBG_KEY0_ADDR(base) ((base) + (0x860))
#define SOC_SCTRL_SCARM_DBG_KEY1_ADDR(base) ((base) + (0x864))
#define SOC_SCTRL_SCARM_DBG_KEY2_ADDR(base) ((base) + (0x868))
#define SOC_SCTRL_SCARM_DBG_KEY3_ADDR(base) ((base) + (0x86C))
#define SOC_SCTRL_SCARM_DBG_KEY4_ADDR(base) ((base) + (0x884))
#define SOC_SCTRL_SCARM_DBG_KEY5_ADDR(base) ((base) + (0x888))
#define SOC_SCTRL_SCARM_DBG_KEY6_ADDR(base) ((base) + (0x88C))
#define SOC_SCTRL_SCARM_DBG_KEY7_ADDR(base) ((base) + (0x890))
#define SOC_SCTRL_SCSPMI1_ADDR0_ADDR(base) ((base) + (0x910))
#define SOC_SCTRL_SCSPMIADDR0_ADDR(base) ((base) + (0x920))
#define SOC_SCTRL_SCSPMIADDR1_ADDR(base) ((base) + (0x924))
#define SOC_SCTRL_SCSPMIADDR2_ADDR(base) ((base) + (0x928))
#define SOC_SCTRL_SCSPMIADDR3_ADDR(base) ((base) + (0x92C))
#define SOC_SCTRL_SCSPMIADDR4_ADDR(base) ((base) + (0x930))
#define SOC_SCTRL_SCSPMIADDR5_ADDR(base) ((base) + (0x934))
#define SOC_SCTRL_SCSPMIADDR6_ADDR(base) ((base) + (0x938))
#define SOC_SCTRL_SCSPMIADDR7_ADDR(base) ((base) + (0x93C))
#define SOC_SCTRL_SCSPMIADDR8_ADDR(base) ((base) + (0x940))
#define SOC_SCTRL_SCSPMIADDR9_ADDR(base) ((base) + (0x944))
#define SOC_SCTRL_SCSPMIADDR10_ADDR(base) ((base) + (0x948))
#define SOC_SCTRL_SCSPMIADDR11_ADDR(base) ((base) + (0x94C))
#define SOC_SCTRL_SCSPMIADDR12_ADDR(base) ((base) + (0x950))
#define SOC_SCTRL_SCSPMIADDR13_ADDR(base) ((base) + (0x954))
#define SOC_SCTRL_SCSPMIADDR14_ADDR(base) ((base) + (0x958))
#define SOC_SCTRL_SCSPMIADDR15_ADDR(base) ((base) + (0x95C))
#define SOC_SCTRL_SCHISEEGPIOLOCK_ADDR(base) ((base) + (0x894))
#define SOC_SCTRL_SCHISEESPILOCK_ADDR(base) ((base) + (0x898))
#define SOC_SCTRL_SCHISEEI2CLOCK_ADDR(base) ((base) + (0x89C))
#define SOC_SCTRL_SCHISEEIOSEL_ADDR(base) ((base) + (0x8A0))
#define SOC_SCTRL_SCPERCTRL0_SEC_ADDR(base) ((base) + (0x8A4))
#define SOC_SCTRL_SCPERCTRL1_SEC_ADDR(base) ((base) + (0x8B0))
#define SOC_SCTRL_SCPERCTRL2_SEC_ADDR(base) ((base) + (0x8B4))
#define SOC_SCTRL_SCPERCTRL3_SEC_ADDR(base) ((base) + (0x8B8))
#define SOC_SCTRL_SCPERCTRL4_SEC_ADDR(base) ((base) + (0x8BC))
#define SOC_SCTRL_SCPERCTRL5_SEC_ADDR(base) ((base) + (0x8E0))
#define SOC_SCTRL_SCPERSTATUS0_SEC_ADDR(base) ((base) + (0x8C0))
#define SOC_SCTRL_SCPERSTATUS1_SEC_ADDR(base) ((base) + (0x8C4))
#define SOC_SCTRL_SCPERSTATUS2_SEC_ADDR(base) ((base) + (0x8C8))
#define SOC_SCTRL_SCPERSTATUS3_SEC_ADDR(base) ((base) + (0x8CC))
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_ADDR(base) ((base) + (0x8D0))
#define SOC_SCTRL_SC_TCP_VOTE_STAT_ADDR(base) ((base) + (0x8D4))
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_ADDR(base) ((base) + (0x8D8))
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_ADDR(base) ((base) + (0x8DC))
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_ADDR(base) ((base) + (0x8E4))
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_ADDR(base) ((base) + (0x808))
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_ADDR(base) ((base) + (0x80C))
#define SOC_SCTRL_SCSOCID0_ADDR(base) ((base) + (0xE00))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED0_ADDR(base) ((base) + (0xE10))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED1_ADDR(base) ((base) + (0xE14))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED2_ADDR(base) ((base) + (0xE18))
#define SOC_SCTRL_SCPERSTAT_POR_RESERVED3_ADDR(base) ((base) + (0xE1C))
#define SOC_SCTRL_SC_NPU_LPCTRL0_SEC_ADDR(base) ((base) + (0xE20))
#define SOC_SCTRL_SC_NPU_LPCTRL1_SEC_ADDR(base) ((base) + (0xE24))
#define SOC_SCTRL_SC_NPU_LPCTRL2_SEC_ADDR(base) ((base) + (0xE28))
#define SOC_SCTRL_SC_NPU_LPCTRL3_SEC_ADDR(base) ((base) + (0xE2C))
#define SOC_SCTRL_SC_NPU_LPCTRL4_SEC_ADDR(base) ((base) + (0xE30))
#define SOC_SCTRL_SC_TRACKING_LOG0_ADDR(base) ((base) + (0xE40))
#define SOC_SCTRL_SC_TRACKING_LOG1_ADDR(base) ((base) + (0xE44))
#define SOC_SCTRL_SC_TRACKING_LOG2_ADDR(base) ((base) + (0xE48))
#define SOC_SCTRL_SC_TRACKING_LOG3_ADDR(base) ((base) + (0xE4C))
#define SOC_SCTRL_SC_EMU_VERSION_ADDR(base) ((base) + (0xE34))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mode_ctrl_soft : 4;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int sys_mode : 4;
        unsigned int reserved_2 : 13;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 3;
    } reg;
} SOC_SCTRL_SCCTRL_UNION;
#endif
#define SOC_SCTRL_SCCTRL_mode_ctrl_soft_START (0)
#define SOC_SCTRL_SCCTRL_mode_ctrl_soft_END (3)
#define SOC_SCTRL_SCCTRL_sys_mode_START (8)
#define SOC_SCTRL_SCCTRL_sys_mode_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lightsleep_to_standby_req : 1;
        unsigned int standby_to_lightsleep_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SCTRL_STD2LS_CTRL_UNION;
#endif
#define SOC_SCTRL_STD2LS_CTRL_lightsleep_to_standby_req_START (0)
#define SOC_SCTRL_STD2LS_CTRL_lightsleep_to_standby_req_END (0)
#define SOC_SCTRL_STD2LS_CTRL_standby_to_lightsleep_req_START (1)
#define SOC_SCTRL_STD2LS_CTRL_standby_to_lightsleep_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_doze1_req : 1;
        unsigned int sw_doze2_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SCTRL_DOZE_CTRL_UNION;
#endif
#define SOC_SCTRL_DOZE_CTRL_sw_doze1_req_START (0)
#define SOC_SCTRL_DOZE_CTRL_sw_doze1_req_END (0)
#define SOC_SCTRL_DOZE_CTRL_sw_doze2_req_START (1)
#define SOC_SCTRL_DOZE_CTRL_sw_doze2_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 31;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SCTRL_SCSYSSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int mfc_sw_sft_req : 1;
        unsigned int hfc_sw_sft_req : 1;
        unsigned int mfc_hfc_sw_sft_ctrl_en : 1;
        unsigned int pll_sft_en : 1;
        unsigned int hfc_pll_sft_ctrl_en : 1;
        unsigned int ulppll_fsm_hw_en_sft : 1;
        unsigned int ulppll_fsm_hw_en_sft_ctrl_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int bus_pwrd_sft_req : 1;
        unsigned int bus_idle_sft_ctrl_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int sys_idle_gt_flag_sft_ctrl : 1;
        unsigned int ao2peri_clk_gt_sft_ctrl_en : 1;
        unsigned int sys_idle_gt_fll_src_peri_sft : 1;
        unsigned int ao2peri_clk_gt_fll_src_peri_sft_ctrl_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int peri_pwr_up_dn_sft_ctrl : 1;
        unsigned int peri_pwr_pdc_sft_ctrl_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int sc_sclk_sw2fll_sft_req : 1;
        unsigned int sclk_sw2fll_sft_ctrl_en : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int bus_clk_sw_sft_inuse : 1;
        unsigned int bus_clk_sw_sft_ctrl_en : 1;
        unsigned int reserved_8 : 1;
        unsigned int sc_gt_clk_ulppll_sft : 1;
        unsigned int gt_clk_ulppll_sft_ctrl_en : 1;
        unsigned int mfc_clk_sft_gt : 1;
        unsigned int mfc_clk_gt_sft_ctrl_en : 1;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_sw_sft_req_START (1)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_sw_sft_req_END (1)
#define SOC_SCTRL_SYS_STAT_CTRL_0_hfc_sw_sft_req_START (2)
#define SOC_SCTRL_SYS_STAT_CTRL_0_hfc_sw_sft_req_END (2)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_hfc_sw_sft_ctrl_en_START (3)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_hfc_sw_sft_ctrl_en_END (3)
#define SOC_SCTRL_SYS_STAT_CTRL_0_pll_sft_en_START (4)
#define SOC_SCTRL_SYS_STAT_CTRL_0_pll_sft_en_END (4)
#define SOC_SCTRL_SYS_STAT_CTRL_0_hfc_pll_sft_ctrl_en_START (5)
#define SOC_SCTRL_SYS_STAT_CTRL_0_hfc_pll_sft_ctrl_en_END (5)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ulppll_fsm_hw_en_sft_START (6)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ulppll_fsm_hw_en_sft_END (6)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ulppll_fsm_hw_en_sft_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ulppll_fsm_hw_en_sft_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_pwrd_sft_req_START (9)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_pwrd_sft_req_END (9)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_idle_sft_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_idle_sft_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sys_idle_gt_flag_sft_ctrl_START (12)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sys_idle_gt_flag_sft_ctrl_END (12)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ao2peri_clk_gt_sft_ctrl_en_START (13)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ao2peri_clk_gt_sft_ctrl_en_END (13)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sys_idle_gt_fll_src_peri_sft_START (14)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sys_idle_gt_fll_src_peri_sft_END (14)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ao2peri_clk_gt_fll_src_peri_sft_ctrl_en_START (15)
#define SOC_SCTRL_SYS_STAT_CTRL_0_ao2peri_clk_gt_fll_src_peri_sft_ctrl_en_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_0_peri_pwr_up_dn_sft_ctrl_START (17)
#define SOC_SCTRL_SYS_STAT_CTRL_0_peri_pwr_up_dn_sft_ctrl_END (17)
#define SOC_SCTRL_SYS_STAT_CTRL_0_peri_pwr_pdc_sft_ctrl_en_START (18)
#define SOC_SCTRL_SYS_STAT_CTRL_0_peri_pwr_pdc_sft_ctrl_en_END (18)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sc_sclk_sw2fll_sft_req_START (21)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sc_sclk_sw2fll_sft_req_END (21)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sclk_sw2fll_sft_ctrl_en_START (22)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sclk_sw2fll_sft_ctrl_en_END (22)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_clk_sw_sft_inuse_START (25)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_clk_sw_sft_inuse_END (25)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_clk_sw_sft_ctrl_en_START (26)
#define SOC_SCTRL_SYS_STAT_CTRL_0_bus_clk_sw_sft_ctrl_en_END (26)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sc_gt_clk_ulppll_sft_START (28)
#define SOC_SCTRL_SYS_STAT_CTRL_0_sc_gt_clk_ulppll_sft_END (28)
#define SOC_SCTRL_SYS_STAT_CTRL_0_gt_clk_ulppll_sft_ctrl_en_START (29)
#define SOC_SCTRL_SYS_STAT_CTRL_0_gt_clk_ulppll_sft_ctrl_en_END (29)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_clk_sft_gt_START (30)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_clk_sft_gt_END (30)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_clk_gt_sft_ctrl_en_START (31)
#define SOC_SCTRL_SYS_STAT_CTRL_0_mfc_clk_gt_sft_ctrl_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_sft_sel_clk_sys_pre : 1;
        unsigned int sft_sel_clk_sys_ctrl_en : 1;
        unsigned int sc_sft_clk_sys_gt_ctrl : 1;
        unsigned int sft_clk_sys_gt_ctrl_en : 1;
        unsigned int tsen_disable_sft_req : 1;
        unsigned int tsen_disable_sft_ctrl_en : 1;
        unsigned int sel_sys_idle_gt_clksys : 1;
        unsigned int sel_sys_idle_gt_32k : 1;
        unsigned int cpu_cluster_dvfs_ctrl_bypass : 7;
        unsigned int ulppll_en_dis_timeout_sel : 1;
        unsigned int cpu_dvfs_sft_req : 1;
        unsigned int cpu_dvfs_sft_ctrl_en : 1;
        unsigned int clk_sys_ctrl_sel : 1;
        unsigned int reserved : 1;
        unsigned int peri_sram_sft_ds : 1;
        unsigned int peri_sram_ds_sft_ctrl_en : 1;
        unsigned int usbphy_ref_clk_gt_sft : 1;
        unsigned int usbphy_ref_clk_gt_sft_ctrl_en : 1;
        unsigned int periph_cpu_clk_sft_sw : 1;
        unsigned int sel_periph_cpu_clk_sft_ctrl_en : 1;
        unsigned int sram_ds_exit_time : 6;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_1_sc_sft_sel_clk_sys_pre_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sc_sft_sel_clk_sys_pre_END (0)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sft_sel_clk_sys_ctrl_en_START (1)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sft_sel_clk_sys_ctrl_en_END (1)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sc_sft_clk_sys_gt_ctrl_START (2)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sc_sft_clk_sys_gt_ctrl_END (2)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sft_clk_sys_gt_ctrl_en_START (3)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sft_clk_sys_gt_ctrl_en_END (3)
#define SOC_SCTRL_SYS_STAT_CTRL_1_tsen_disable_sft_req_START (4)
#define SOC_SCTRL_SYS_STAT_CTRL_1_tsen_disable_sft_req_END (4)
#define SOC_SCTRL_SYS_STAT_CTRL_1_tsen_disable_sft_ctrl_en_START (5)
#define SOC_SCTRL_SYS_STAT_CTRL_1_tsen_disable_sft_ctrl_en_END (5)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sel_sys_idle_gt_clksys_START (6)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sel_sys_idle_gt_clksys_END (6)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sel_sys_idle_gt_32k_START (7)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sel_sys_idle_gt_32k_END (7)
#define SOC_SCTRL_SYS_STAT_CTRL_1_cpu_cluster_dvfs_ctrl_bypass_START (8)
#define SOC_SCTRL_SYS_STAT_CTRL_1_cpu_cluster_dvfs_ctrl_bypass_END (14)
#define SOC_SCTRL_SYS_STAT_CTRL_1_ulppll_en_dis_timeout_sel_START (15)
#define SOC_SCTRL_SYS_STAT_CTRL_1_ulppll_en_dis_timeout_sel_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_1_cpu_dvfs_sft_req_START (16)
#define SOC_SCTRL_SYS_STAT_CTRL_1_cpu_dvfs_sft_req_END (16)
#define SOC_SCTRL_SYS_STAT_CTRL_1_cpu_dvfs_sft_ctrl_en_START (17)
#define SOC_SCTRL_SYS_STAT_CTRL_1_cpu_dvfs_sft_ctrl_en_END (17)
#define SOC_SCTRL_SYS_STAT_CTRL_1_clk_sys_ctrl_sel_START (18)
#define SOC_SCTRL_SYS_STAT_CTRL_1_clk_sys_ctrl_sel_END (18)
#define SOC_SCTRL_SYS_STAT_CTRL_1_peri_sram_sft_ds_START (20)
#define SOC_SCTRL_SYS_STAT_CTRL_1_peri_sram_sft_ds_END (20)
#define SOC_SCTRL_SYS_STAT_CTRL_1_peri_sram_ds_sft_ctrl_en_START (21)
#define SOC_SCTRL_SYS_STAT_CTRL_1_peri_sram_ds_sft_ctrl_en_END (21)
#define SOC_SCTRL_SYS_STAT_CTRL_1_usbphy_ref_clk_gt_sft_START (22)
#define SOC_SCTRL_SYS_STAT_CTRL_1_usbphy_ref_clk_gt_sft_END (22)
#define SOC_SCTRL_SYS_STAT_CTRL_1_usbphy_ref_clk_gt_sft_ctrl_en_START (23)
#define SOC_SCTRL_SYS_STAT_CTRL_1_usbphy_ref_clk_gt_sft_ctrl_en_END (23)
#define SOC_SCTRL_SYS_STAT_CTRL_1_periph_cpu_clk_sft_sw_START (24)
#define SOC_SCTRL_SYS_STAT_CTRL_1_periph_cpu_clk_sft_sw_END (24)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sel_periph_cpu_clk_sft_ctrl_en_START (25)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sel_periph_cpu_clk_sft_ctrl_en_END (25)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sram_ds_exit_time_START (26)
#define SOC_SCTRL_SYS_STAT_CTRL_1_sram_ds_exit_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao2peri_clk_gt_on_time : 16;
        unsigned int ao2peri_clk_gt_off_time : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_2_ao2peri_clk_gt_on_time_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_2_ao2peri_clk_gt_on_time_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_2_ao2peri_clk_gt_off_time_START (16)
#define SOC_SCTRL_SYS_STAT_CTRL_2_ao2peri_clk_gt_off_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mfc_clk_gt_on_time : 16;
        unsigned int mfc_clk_gt_off_time : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_3_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_3_mfc_clk_gt_on_time_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_3_mfc_clk_gt_on_time_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_3_mfc_clk_gt_off_time_START (16)
#define SOC_SCTRL_SYS_STAT_CTRL_3_mfc_clk_gt_off_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_idle_enter_time : 16;
        unsigned int bus_idle_exit_time : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_4_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_4_bus_idle_enter_time_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_4_bus_idle_enter_time_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_4_bus_idle_exit_time_START (16)
#define SOC_SCTRL_SYS_STAT_CTRL_4_bus_idle_exit_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_dis_time : 8;
        unsigned int ulppll_en_time : 8;
        unsigned int ulppll_gt_on_time : 8;
        unsigned int ulppll_gt_off_time : 8;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_5_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_dis_time_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_dis_time_END (7)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_en_time_START (8)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_en_time_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_gt_on_time_START (16)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_gt_on_time_END (23)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_gt_off_time_START (24)
#define SOC_SCTRL_SYS_STAT_CTRL_5_ulppll_gt_off_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clksys_gt_off_time : 8;
        unsigned int clksys_gt_on_time : 8;
        unsigned int common_pll_sft_en : 8;
        unsigned int common_pll_sft_ctrl_en : 8;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_6_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_6_clksys_gt_off_time_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_6_clksys_gt_off_time_END (7)
#define SOC_SCTRL_SYS_STAT_CTRL_6_clksys_gt_on_time_START (8)
#define SOC_SCTRL_SYS_STAT_CTRL_6_clksys_gt_on_time_END (15)
#define SOC_SCTRL_SYS_STAT_CTRL_6_common_pll_sft_en_START (16)
#define SOC_SCTRL_SYS_STAT_CTRL_6_common_pll_sft_en_END (23)
#define SOC_SCTRL_SYS_STAT_CTRL_6_common_pll_sft_ctrl_en_START (24)
#define SOC_SCTRL_SYS_STAT_CTRL_6_common_pll_sft_ctrl_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst_pmu_ps_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SC_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_PMU_PS_CTRL_1_mst_pmu_ps_addr_START (0)
#define SOC_SCTRL_SC_PMU_PS_CTRL_1_mst_pmu_ps_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SC_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_PMU_PS_CTRL_2_slv_pmu_ps_addr_START (0)
#define SOC_SCTRL_SC_PMU_PS_CTRL_2_slv_pmu_ps_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sctrl_pmu_address_sft_ctrl_en : 1;
        unsigned int pmu_ps_lp_sft_ctrl_en : 1;
        unsigned int doze1_ps_skip_en : 1;
        unsigned int doze2_ps_skip_en : 1;
        unsigned int slv_pmu_ps_sft_idx : 8;
        unsigned int slv_pmu_ps_sft_chg : 1;
        unsigned int reserved_0 : 1;
        unsigned int fer_mst_pmu_ps_sft_req_clr : 1;
        unsigned int fer_mst_pmu_psok_sft_req_clr : 1;
        unsigned int mst_pmu_ps_sft_idx : 8;
        unsigned int mst_pmu_ps_sft_chg : 1;
        unsigned int fer_mst_pmu_psok_sft_req : 1;
        unsigned int fer_mst_pmu_psok_bypass : 1;
        unsigned int fer_clk_pmu_psok_bypass : 1;
        unsigned int mst_pmu_ps_bypass : 1;
        unsigned int clk_pmu_ps_bypass : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SCTRL_SC_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_sctrl_pmu_address_sft_ctrl_en_START (0)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_sctrl_pmu_address_sft_ctrl_en_END (0)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_pmu_ps_lp_sft_ctrl_en_START (1)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_pmu_ps_lp_sft_ctrl_en_END (1)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_doze1_ps_skip_en_START (2)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_doze1_ps_skip_en_END (2)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_doze2_ps_skip_en_START (3)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_doze2_ps_skip_en_END (3)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_slv_pmu_ps_sft_idx_START (4)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_slv_pmu_ps_sft_idx_END (11)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_slv_pmu_ps_sft_chg_START (12)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_slv_pmu_ps_sft_chg_END (12)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_ps_sft_req_clr_START (14)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_ps_sft_req_clr_END (14)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_psok_sft_req_clr_START (15)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_psok_sft_req_clr_END (15)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_mst_pmu_ps_sft_idx_START (16)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_mst_pmu_ps_sft_idx_END (23)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_mst_pmu_ps_sft_chg_START (24)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_mst_pmu_ps_sft_chg_END (24)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_psok_sft_req_START (25)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_psok_sft_req_END (25)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_psok_bypass_START (26)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_mst_pmu_psok_bypass_END (26)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_clk_pmu_psok_bypass_START (27)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_fer_clk_pmu_psok_bypass_END (27)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_mst_pmu_ps_bypass_START (28)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_mst_pmu_ps_bypass_END (28)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_clk_pmu_ps_bypass_START (29)
#define SOC_SCTRL_SC_PMU_PS_CTRL_0_clk_pmu_ps_bypass_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_lp_enter_deepsleep_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_enter_deepsleep_hrd_idx : 8;
        unsigned int slv_pmu_ps_lp_exit_deepsleep_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_exit_deepsleep_hrd_idx : 8;
    } reg;
} SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_deepsleep_hrd_idx_START (0)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_deepsleep_hrd_idx_END (7)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_deepsleep_hrd_idx_START (8)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_deepsleep_hrd_idx_END (15)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_deepsleep_hrd_idx_START (16)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_deepsleep_hrd_idx_END (23)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_deepsleep_hrd_idx_START (24)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_deepsleep_hrd_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_exit_deepsleep_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_1_pmu_ps_lp_exit_deepsleep_time_START (0)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_1_pmu_ps_lp_exit_deepsleep_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_enter_deepsleep_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_2_pmu_ps_lp_enter_deepsleep_time_START (0)
#define SOC_SCTRL_SC_DEEPSLEEP_PMU_PS_CTRL_2_pmu_ps_lp_enter_deepsleep_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_lp_enter_lightsleep_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_enter_lightsleep_hrd_idx : 8;
        unsigned int slv_pmu_ps_lp_exit_lightsleep_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_exit_lightsleep_hrd_idx : 8;
    } reg;
} SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_lightsleep_hrd_idx_START (0)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_lightsleep_hrd_idx_END (7)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_lightsleep_hrd_idx_START (8)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_lightsleep_hrd_idx_END (15)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_lightsleep_hrd_idx_START (16)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_lightsleep_hrd_idx_END (23)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_lightsleep_hrd_idx_START (24)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_lightsleep_hrd_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_exit_lightsleep_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_1_pmu_ps_lp_exit_lightsleep_time_START (0)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_1_pmu_ps_lp_exit_lightsleep_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_enter_lightsleep_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_2_pmu_ps_lp_enter_lightsleep_time_START (0)
#define SOC_SCTRL_SC_LIGHTSLEEP_PMU_PS_CTRL_2_pmu_ps_lp_enter_lightsleep_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_lp_enter_standby_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_enter_standby_hrd_idx : 8;
        unsigned int slv_pmu_ps_lp_exit_standby_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_exit_standby_hrd_idx : 8;
    } reg;
} SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_standby_hrd_idx_START (0)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_standby_hrd_idx_END (7)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_standby_hrd_idx_START (8)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_standby_hrd_idx_END (15)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_standby_hrd_idx_START (16)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_standby_hrd_idx_END (23)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_standby_hrd_idx_START (24)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_standby_hrd_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_exit_standby_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_1_pmu_ps_lp_exit_standby_time_START (0)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_1_pmu_ps_lp_exit_standby_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_enter_standby_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_2_pmu_ps_lp_enter_standby_time_START (0)
#define SOC_SCTRL_SC_STANDBY_PMU_PS_CTRL_2_pmu_ps_lp_enter_standby_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_lp_enter_std2ls_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_enter_std2ls_hrd_idx : 8;
        unsigned int slv_pmu_ps_lp_exit_ls2std_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_exit_ls2std_hrd_idx : 8;
    } reg;
} SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_std2ls_hrd_idx_START (0)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_std2ls_hrd_idx_END (7)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_std2ls_hrd_idx_START (8)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_std2ls_hrd_idx_END (15)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_ls2std_hrd_idx_START (16)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_ls2std_hrd_idx_END (23)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_ls2std_hrd_idx_START (24)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_ls2std_hrd_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_exit_ls2std_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_1_pmu_ps_lp_exit_ls2std_time_START (0)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_1_pmu_ps_lp_exit_ls2std_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_enter_std2ls_time : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_2_pmu_ps_lp_enter_std2ls_time_START (0)
#define SOC_SCTRL_SC_STD2LS_PMU_PS_CTRL_2_pmu_ps_lp_enter_std2ls_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_idx_spmi : 8;
        unsigned int slv_pmu_ps_chg_spmi : 1;
        unsigned int slv_pmu_ps_ack_spmi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int mst_pmu_ps_idx_spmi : 8;
        unsigned int mst_pmu_ps_chg_spmi : 1;
        unsigned int mst_pmu_ps_ack_spmi : 1;
        unsigned int fer_mst_pmu_psok_req : 1;
        unsigned int fer_mst_pmu_psok_ack : 1;
        unsigned int fer_pmu_ps_lp_exit_finish_flag : 1;
        unsigned int fer_pmu_ps_lp_enter_finish_flag : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int fer_mst_pmu_ps_lp_enter_finish_flag : 1;
        unsigned int fer_mst_pmu_ps_lp_exit_finish_flag : 1;
        unsigned int fer_err_flag : 1;
        unsigned int fer_err_flag_clr : 1;
    } reg;
} SOC_SCTRL_SC_PMU_PS_STAT_0_UNION;
#endif
#define SOC_SCTRL_SC_PMU_PS_STAT_0_slv_pmu_ps_idx_spmi_START (0)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_slv_pmu_ps_idx_spmi_END (7)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_slv_pmu_ps_chg_spmi_START (8)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_slv_pmu_ps_chg_spmi_END (8)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_slv_pmu_ps_ack_spmi_START (9)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_slv_pmu_ps_ack_spmi_END (9)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_mst_pmu_ps_idx_spmi_START (12)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_mst_pmu_ps_idx_spmi_END (19)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_mst_pmu_ps_chg_spmi_START (20)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_mst_pmu_ps_chg_spmi_END (20)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_mst_pmu_ps_ack_spmi_START (21)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_mst_pmu_ps_ack_spmi_END (21)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_psok_req_START (22)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_psok_req_END (22)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_psok_ack_START (23)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_psok_ack_END (23)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_pmu_ps_lp_exit_finish_flag_START (24)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_pmu_ps_lp_exit_finish_flag_END (24)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_pmu_ps_lp_enter_finish_flag_START (25)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_pmu_ps_lp_enter_finish_flag_END (25)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_ps_lp_enter_finish_flag_START (28)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_ps_lp_enter_finish_flag_END (28)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_ps_lp_exit_finish_flag_START (29)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_mst_pmu_ps_lp_exit_finish_flag_END (29)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_err_flag_START (30)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_err_flag_END (30)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_err_flag_clr_START (31)
#define SOC_SCTRL_SC_PMU_PS_STAT_0_fer_err_flag_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_addr : 20;
        unsigned int spmi_ctrl_state : 3;
        unsigned int reserved : 9;
    } reg;
} SOC_SCTRL_SC_PMU_PS_STAT_1_UNION;
#endif
#define SOC_SCTRL_SC_PMU_PS_STAT_1_pmu_addr_START (0)
#define SOC_SCTRL_SC_PMU_PS_STAT_1_pmu_addr_END (19)
#define SOC_SCTRL_SC_PMU_PS_STAT_1_spmi_ctrl_state_START (20)
#define SOC_SCTRL_SC_PMU_PS_STAT_1_spmi_ctrl_state_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_sc_mode : 5;
        unsigned int nxt_sc_mode : 5;
        unsigned int sc_gt_clk_mfc : 1;
        unsigned int mfc_sw_req : 1;
        unsigned int mfc_sw_ack : 1;
        unsigned int hfc_sw_req : 1;
        unsigned int hfc_sw_ack : 1;
        unsigned int sc_bus_clk_sw_inuse : 1;
        unsigned int sw_ack_clk_aonoc_sw : 2;
        unsigned int pll_en : 1;
        unsigned int spll_fsm_hw_stat : 1;
        unsigned int sys_sc_cnt_timeout : 1;
        unsigned int bus_pwrd_req : 1;
        unsigned int bus_pwrd_enter_ack : 1;
        unsigned int bus_pwrd_exit_ack : 1;
        unsigned int reserved : 1;
        unsigned int sys_idle_gt_flag : 1;
        unsigned int peri_pwr_up_dn : 1;
        unsigned int sc_io_ret : 1;
        unsigned int sc_sel_clk_sys_pre : 1;
        unsigned int sw_ack_clk_sys_pre : 2;
        unsigned int hw_tsen_disable_req : 1;
    } reg;
} SOC_SCTRL_SYS_SC_STAT_0_UNION;
#endif
#define SOC_SCTRL_SYS_SC_STAT_0_cur_sc_mode_START (0)
#define SOC_SCTRL_SYS_SC_STAT_0_cur_sc_mode_END (4)
#define SOC_SCTRL_SYS_SC_STAT_0_nxt_sc_mode_START (5)
#define SOC_SCTRL_SYS_SC_STAT_0_nxt_sc_mode_END (9)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_gt_clk_mfc_START (10)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_gt_clk_mfc_END (10)
#define SOC_SCTRL_SYS_SC_STAT_0_mfc_sw_req_START (11)
#define SOC_SCTRL_SYS_SC_STAT_0_mfc_sw_req_END (11)
#define SOC_SCTRL_SYS_SC_STAT_0_mfc_sw_ack_START (12)
#define SOC_SCTRL_SYS_SC_STAT_0_mfc_sw_ack_END (12)
#define SOC_SCTRL_SYS_SC_STAT_0_hfc_sw_req_START (13)
#define SOC_SCTRL_SYS_SC_STAT_0_hfc_sw_req_END (13)
#define SOC_SCTRL_SYS_SC_STAT_0_hfc_sw_ack_START (14)
#define SOC_SCTRL_SYS_SC_STAT_0_hfc_sw_ack_END (14)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_bus_clk_sw_inuse_START (15)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_bus_clk_sw_inuse_END (15)
#define SOC_SCTRL_SYS_SC_STAT_0_sw_ack_clk_aonoc_sw_START (16)
#define SOC_SCTRL_SYS_SC_STAT_0_sw_ack_clk_aonoc_sw_END (17)
#define SOC_SCTRL_SYS_SC_STAT_0_pll_en_START (18)
#define SOC_SCTRL_SYS_SC_STAT_0_pll_en_END (18)
#define SOC_SCTRL_SYS_SC_STAT_0_spll_fsm_hw_stat_START (19)
#define SOC_SCTRL_SYS_SC_STAT_0_spll_fsm_hw_stat_END (19)
#define SOC_SCTRL_SYS_SC_STAT_0_sys_sc_cnt_timeout_START (20)
#define SOC_SCTRL_SYS_SC_STAT_0_sys_sc_cnt_timeout_END (20)
#define SOC_SCTRL_SYS_SC_STAT_0_bus_pwrd_req_START (21)
#define SOC_SCTRL_SYS_SC_STAT_0_bus_pwrd_req_END (21)
#define SOC_SCTRL_SYS_SC_STAT_0_bus_pwrd_enter_ack_START (22)
#define SOC_SCTRL_SYS_SC_STAT_0_bus_pwrd_enter_ack_END (22)
#define SOC_SCTRL_SYS_SC_STAT_0_bus_pwrd_exit_ack_START (23)
#define SOC_SCTRL_SYS_SC_STAT_0_bus_pwrd_exit_ack_END (23)
#define SOC_SCTRL_SYS_SC_STAT_0_sys_idle_gt_flag_START (25)
#define SOC_SCTRL_SYS_SC_STAT_0_sys_idle_gt_flag_END (25)
#define SOC_SCTRL_SYS_SC_STAT_0_peri_pwr_up_dn_START (26)
#define SOC_SCTRL_SYS_SC_STAT_0_peri_pwr_up_dn_END (26)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_io_ret_START (27)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_io_ret_END (27)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_sel_clk_sys_pre_START (28)
#define SOC_SCTRL_SYS_SC_STAT_0_sc_sel_clk_sys_pre_END (28)
#define SOC_SCTRL_SYS_SC_STAT_0_sw_ack_clk_sys_pre_START (29)
#define SOC_SCTRL_SYS_SC_STAT_0_sw_ack_clk_sys_pre_END (30)
#define SOC_SCTRL_SYS_SC_STAT_0_hw_tsen_disable_req_START (31)
#define SOC_SCTRL_SYS_SC_STAT_0_hw_tsen_disable_req_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_peri_sram_ctrl_ds : 1;
        unsigned int cpu_dvfs_clk_sw_req : 1;
        unsigned int cpu_dvfs_clk_sw_finish_flag : 1;
        unsigned int cpu_dvfs_sc_doze_flag : 1;
        unsigned int gt_clk_usbphy_ref : 1;
        unsigned int sys_idle_gt_fll_src_peri : 1;
        unsigned int bus_idle_ack_timeout_err : 1;
        unsigned int bus_idle_ack_timeout_err_clr : 1;
        unsigned int spll_fsm_unlock_intr : 1;
        unsigned int enter_doze1_add_cnt : 10;
        unsigned int enter_doze2_add_cnt : 10;
        unsigned int enter_doze_cnt_clr : 1;
        unsigned int sw_ack_clk_periph_cpu_sw : 2;
    } reg;
} SOC_SCTRL_SYS_SC_STAT_1_UNION;
#endif
#define SOC_SCTRL_SYS_SC_STAT_1_sc_peri_sram_ctrl_ds_START (0)
#define SOC_SCTRL_SYS_SC_STAT_1_sc_peri_sram_ctrl_ds_END (0)
#define SOC_SCTRL_SYS_SC_STAT_1_cpu_dvfs_clk_sw_req_START (1)
#define SOC_SCTRL_SYS_SC_STAT_1_cpu_dvfs_clk_sw_req_END (1)
#define SOC_SCTRL_SYS_SC_STAT_1_cpu_dvfs_clk_sw_finish_flag_START (2)
#define SOC_SCTRL_SYS_SC_STAT_1_cpu_dvfs_clk_sw_finish_flag_END (2)
#define SOC_SCTRL_SYS_SC_STAT_1_cpu_dvfs_sc_doze_flag_START (3)
#define SOC_SCTRL_SYS_SC_STAT_1_cpu_dvfs_sc_doze_flag_END (3)
#define SOC_SCTRL_SYS_SC_STAT_1_gt_clk_usbphy_ref_START (4)
#define SOC_SCTRL_SYS_SC_STAT_1_gt_clk_usbphy_ref_END (4)
#define SOC_SCTRL_SYS_SC_STAT_1_sys_idle_gt_fll_src_peri_START (5)
#define SOC_SCTRL_SYS_SC_STAT_1_sys_idle_gt_fll_src_peri_END (5)
#define SOC_SCTRL_SYS_SC_STAT_1_bus_idle_ack_timeout_err_START (6)
#define SOC_SCTRL_SYS_SC_STAT_1_bus_idle_ack_timeout_err_END (6)
#define SOC_SCTRL_SYS_SC_STAT_1_bus_idle_ack_timeout_err_clr_START (7)
#define SOC_SCTRL_SYS_SC_STAT_1_bus_idle_ack_timeout_err_clr_END (7)
#define SOC_SCTRL_SYS_SC_STAT_1_spll_fsm_unlock_intr_START (8)
#define SOC_SCTRL_SYS_SC_STAT_1_spll_fsm_unlock_intr_END (8)
#define SOC_SCTRL_SYS_SC_STAT_1_enter_doze1_add_cnt_START (9)
#define SOC_SCTRL_SYS_SC_STAT_1_enter_doze1_add_cnt_END (18)
#define SOC_SCTRL_SYS_SC_STAT_1_enter_doze2_add_cnt_START (19)
#define SOC_SCTRL_SYS_SC_STAT_1_enter_doze2_add_cnt_END (28)
#define SOC_SCTRL_SYS_SC_STAT_1_enter_doze_cnt_clr_START (29)
#define SOC_SCTRL_SYS_SC_STAT_1_enter_doze_cnt_clr_END (29)
#define SOC_SCTRL_SYS_SC_STAT_1_sw_ack_clk_periph_cpu_sw_START (30)
#define SOC_SCTRL_SYS_SC_STAT_1_sw_ack_clk_periph_cpu_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mfc_clk_gt_en : 1;
        unsigned int hfc_pll_ctrl_en : 1;
        unsigned int hfc2mfc_sw_en : 1;
        unsigned int hfc_common_pll_ctrl_en : 4;
        unsigned int reserved : 9;
        unsigned int sys_stat_slow_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_SLOW_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_mfc_clk_gt_en_START (0)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_mfc_clk_gt_en_END (0)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_hfc_pll_ctrl_en_START (1)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_hfc_pll_ctrl_en_END (1)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_hfc2mfc_sw_en_START (2)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_hfc2mfc_sw_en_END (2)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_hfc_common_pll_ctrl_en_START (3)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_hfc_common_pll_ctrl_en_END (6)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_sys_stat_slow_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL_sys_stat_slow_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_idle_ctrl_en : 1;
        unsigned int bus_clk_sw_en : 1;
        unsigned int ao2peri_clk_gt_en : 1;
        unsigned int pmu_ps_lp_en : 1;
        unsigned int peri_pwr_ctrl_en : 1;
        unsigned int tcxo_ctrl_en : 1;
        unsigned int io_ret_ctrl_en : 1;
        unsigned int tsen_ctrl_en : 1;
        unsigned int sram_ds_ctrl_en : 1;
        unsigned int peri_sw_to_aoclk_ctrl_en : 1;
        unsigned int cpu_dvfs_doze1_ctrl_en : 1;
        unsigned int fll_clk_off_en : 1;
        unsigned int ulppll_dis_en : 1;
        unsigned int reserved : 3;
        unsigned int sys_stat_deepsleep_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_bus_idle_ctrl_en_START (0)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_bus_idle_ctrl_en_END (0)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_bus_clk_sw_en_START (1)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_bus_clk_sw_en_END (1)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_ao2peri_clk_gt_en_START (2)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_ao2peri_clk_gt_en_END (2)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_pmu_ps_lp_en_START (3)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_pmu_ps_lp_en_END (3)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_peri_pwr_ctrl_en_START (4)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_peri_pwr_ctrl_en_END (4)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_tcxo_ctrl_en_START (5)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_tcxo_ctrl_en_END (5)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_io_ret_ctrl_en_START (6)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_io_ret_ctrl_en_END (6)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_tsen_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_tsen_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_sram_ds_ctrl_en_START (8)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_sram_ds_ctrl_en_END (8)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_peri_sw_to_aoclk_ctrl_en_START (9)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_peri_sw_to_aoclk_ctrl_en_END (9)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_cpu_dvfs_doze1_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_cpu_dvfs_doze1_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_fll_clk_off_en_START (11)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_fll_clk_off_en_END (11)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_ulppll_dis_en_START (12)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_ulppll_dis_en_END (12)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_sys_stat_deepsleep_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL_sys_stat_deepsleep_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_idle_ctrl_en : 1;
        unsigned int bus_clk_sw_en : 1;
        unsigned int ao2peri_clk_gt_en : 1;
        unsigned int pmu_ps_lp_en : 1;
        unsigned int peri_pwr_ctrl_en : 1;
        unsigned int tcxo_ctrl_en : 1;
        unsigned int io_ret_ctrl_en : 1;
        unsigned int tsen_ctrl_en : 1;
        unsigned int sram_ds_ctrl_en : 1;
        unsigned int peri_sw_to_aoclk_ctrl_en : 1;
        unsigned int cpu_dvfs_doze1_ctrl_en : 1;
        unsigned int fll_clk_off_en : 1;
        unsigned int ulppll_dis_en : 1;
        unsigned int reserved : 3;
        unsigned int sys_stat_lightsleep_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_bus_idle_ctrl_en_START (0)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_bus_idle_ctrl_en_END (0)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_bus_clk_sw_en_START (1)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_bus_clk_sw_en_END (1)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_ao2peri_clk_gt_en_START (2)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_ao2peri_clk_gt_en_END (2)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_pmu_ps_lp_en_START (3)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_pmu_ps_lp_en_END (3)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_peri_pwr_ctrl_en_START (4)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_peri_pwr_ctrl_en_END (4)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_tcxo_ctrl_en_START (5)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_tcxo_ctrl_en_END (5)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_io_ret_ctrl_en_START (6)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_io_ret_ctrl_en_END (6)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_tsen_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_tsen_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_sram_ds_ctrl_en_START (8)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_sram_ds_ctrl_en_END (8)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_peri_sw_to_aoclk_ctrl_en_START (9)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_peri_sw_to_aoclk_ctrl_en_END (9)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_cpu_dvfs_doze1_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_cpu_dvfs_doze1_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_fll_clk_off_en_START (11)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_fll_clk_off_en_END (11)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_ulppll_dis_en_START (12)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_ulppll_dis_en_END (12)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_sys_stat_lightsleep_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL_sys_stat_lightsleep_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_idle_ctrl_en : 1;
        unsigned int bus_clk_sw_en : 1;
        unsigned int ao2peri_clk_gt_en : 1;
        unsigned int pmu_ps_lp_en : 1;
        unsigned int peri_pwr_ctrl_en : 1;
        unsigned int tcxo_ctrl_en : 1;
        unsigned int io_ret_ctrl_en : 1;
        unsigned int tsen_ctrl_en : 1;
        unsigned int sram_ds_ctrl_en : 1;
        unsigned int peri_sw_to_aoclk_ctrl_en : 1;
        unsigned int cpu_dvfs_doze1_ctrl_en : 1;
        unsigned int fll_clk_off_en : 1;
        unsigned int ulppll_dis_en : 1;
        unsigned int reserved : 3;
        unsigned int sys_stat_standby_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_STANDBY_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_bus_idle_ctrl_en_START (0)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_bus_idle_ctrl_en_END (0)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_bus_clk_sw_en_START (1)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_bus_clk_sw_en_END (1)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_ao2peri_clk_gt_en_START (2)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_ao2peri_clk_gt_en_END (2)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_pmu_ps_lp_en_START (3)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_pmu_ps_lp_en_END (3)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_peri_pwr_ctrl_en_START (4)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_peri_pwr_ctrl_en_END (4)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_tcxo_ctrl_en_START (5)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_tcxo_ctrl_en_END (5)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_io_ret_ctrl_en_START (6)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_io_ret_ctrl_en_END (6)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_tsen_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_tsen_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_sram_ds_ctrl_en_START (8)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_sram_ds_ctrl_en_END (8)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_peri_sw_to_aoclk_ctrl_en_START (9)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_peri_sw_to_aoclk_ctrl_en_END (9)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_cpu_dvfs_doze1_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_cpu_dvfs_doze1_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_fll_clk_off_en_START (11)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_fll_clk_off_en_END (11)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_ulppll_dis_en_START (12)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_ulppll_dis_en_END (12)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_sys_stat_standby_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL_sys_stat_standby_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_idle_ctrl_en : 1;
        unsigned int bus_clk_sw_en : 1;
        unsigned int ao2peri_clk_gt_en : 1;
        unsigned int pmu_ps_lp_en : 1;
        unsigned int peri_pwr_ctrl_en : 1;
        unsigned int tcxo_ctrl_en : 1;
        unsigned int io_ret_ctrl_en : 1;
        unsigned int tsen_ctrl_en : 1;
        unsigned int sram_ds_ctrl_en : 1;
        unsigned int peri_sw_to_aoclk_ctrl_en : 1;
        unsigned int cpu_dvfs_doze1_ctrl_en : 1;
        unsigned int fll_clk_off_en : 1;
        unsigned int ulppll_dis_en : 1;
        unsigned int reserved : 3;
        unsigned int sys_stat_ls2std_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LS2STD_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_bus_idle_ctrl_en_START (0)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_bus_idle_ctrl_en_END (0)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_bus_clk_sw_en_START (1)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_bus_clk_sw_en_END (1)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_ao2peri_clk_gt_en_START (2)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_ao2peri_clk_gt_en_END (2)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_pmu_ps_lp_en_START (3)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_pmu_ps_lp_en_END (3)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_peri_pwr_ctrl_en_START (4)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_peri_pwr_ctrl_en_END (4)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_tcxo_ctrl_en_START (5)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_tcxo_ctrl_en_END (5)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_io_ret_ctrl_en_START (6)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_io_ret_ctrl_en_END (6)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_tsen_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_tsen_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_sram_ds_ctrl_en_START (8)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_sram_ds_ctrl_en_END (8)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_peri_sw_to_aoclk_ctrl_en_START (9)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_peri_sw_to_aoclk_ctrl_en_END (9)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_cpu_dvfs_doze1_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_cpu_dvfs_doze1_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_fll_clk_off_en_START (11)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_fll_clk_off_en_END (11)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_ulppll_dis_en_START (12)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_ulppll_dis_en_END (12)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_sys_stat_ls2std_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL_sys_stat_ls2std_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mfc_clk_gt_en : 1;
        unsigned int hfc_pll_ctrl_en : 1;
        unsigned int hfc2mfc_sw_en : 1;
        unsigned int bus_idle_ctrl_en : 1;
        unsigned int bus_clk_sw_en : 1;
        unsigned int ao2peri_clk_gt_en : 1;
        unsigned int pmu_ps_lp_en : 1;
        unsigned int peri_pwr_ctrl_en : 1;
        unsigned int tcxo_ctrl_en : 1;
        unsigned int io_ret_ctrl_en : 1;
        unsigned int tsen_ctrl_en : 1;
        unsigned int sram_ds_ctrl_en : 1;
        unsigned int peri_sw_to_aoclk_ctrl_en : 1;
        unsigned int cpu_dvfs_doze1_ctrl_en : 1;
        unsigned int fll_clk_off_en : 1;
        unsigned int ulppll_dis_en : 1;
        unsigned int sys_stat_doze1_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_DOZE1_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_mfc_clk_gt_en_START (0)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_mfc_clk_gt_en_END (0)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_hfc_pll_ctrl_en_START (1)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_hfc_pll_ctrl_en_END (1)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_hfc2mfc_sw_en_START (2)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_hfc2mfc_sw_en_END (2)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_bus_idle_ctrl_en_START (3)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_bus_idle_ctrl_en_END (3)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_bus_clk_sw_en_START (4)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_bus_clk_sw_en_END (4)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_ao2peri_clk_gt_en_START (5)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_ao2peri_clk_gt_en_END (5)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_pmu_ps_lp_en_START (6)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_pmu_ps_lp_en_END (6)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_peri_pwr_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_peri_pwr_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_tcxo_ctrl_en_START (8)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_tcxo_ctrl_en_END (8)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_io_ret_ctrl_en_START (9)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_io_ret_ctrl_en_END (9)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_tsen_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_tsen_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_sram_ds_ctrl_en_START (11)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_sram_ds_ctrl_en_END (11)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_peri_sw_to_aoclk_ctrl_en_START (12)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_peri_sw_to_aoclk_ctrl_en_END (12)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_cpu_dvfs_doze1_ctrl_en_START (13)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_cpu_dvfs_doze1_ctrl_en_END (13)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_fll_clk_off_en_START (14)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_fll_clk_off_en_END (14)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_ulppll_dis_en_START (15)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_ulppll_dis_en_END (15)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_sys_stat_doze1_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL_sys_stat_doze1_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mfc_clk_gt_en : 1;
        unsigned int hfc_pll_ctrl_en : 1;
        unsigned int hfc2mfc_sw_en : 1;
        unsigned int bus_idle_ctrl_en : 1;
        unsigned int bus_clk_sw_en : 1;
        unsigned int ao2peri_clk_gt_en : 1;
        unsigned int pmu_ps_lp_en : 1;
        unsigned int peri_pwr_ctrl_en : 1;
        unsigned int tcxo_ctrl_en : 1;
        unsigned int io_ret_ctrl_en : 1;
        unsigned int tsen_ctrl_en : 1;
        unsigned int sram_ds_ctrl_en : 1;
        unsigned int peri_sw_to_aoclk_ctrl_en : 1;
        unsigned int cpu_dvfs_doze1_ctrl_en : 1;
        unsigned int fll_clk_off_en : 1;
        unsigned int ulppll_dis_en : 1;
        unsigned int sys_stat_doze2_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_DOZE2_CTRL_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_mfc_clk_gt_en_START (0)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_mfc_clk_gt_en_END (0)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_hfc_pll_ctrl_en_START (1)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_hfc_pll_ctrl_en_END (1)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_hfc2mfc_sw_en_START (2)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_hfc2mfc_sw_en_END (2)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_bus_idle_ctrl_en_START (3)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_bus_idle_ctrl_en_END (3)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_bus_clk_sw_en_START (4)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_bus_clk_sw_en_END (4)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_ao2peri_clk_gt_en_START (5)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_ao2peri_clk_gt_en_END (5)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_pmu_ps_lp_en_START (6)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_pmu_ps_lp_en_END (6)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_peri_pwr_ctrl_en_START (7)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_peri_pwr_ctrl_en_END (7)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_tcxo_ctrl_en_START (8)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_tcxo_ctrl_en_END (8)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_io_ret_ctrl_en_START (9)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_io_ret_ctrl_en_END (9)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_tsen_ctrl_en_START (10)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_tsen_ctrl_en_END (10)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_sram_ds_ctrl_en_START (11)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_sram_ds_ctrl_en_END (11)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_peri_sw_to_aoclk_ctrl_en_START (12)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_peri_sw_to_aoclk_ctrl_en_END (12)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_cpu_dvfs_doze1_ctrl_en_START (13)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_cpu_dvfs_doze1_ctrl_en_END (13)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_fll_clk_off_en_START (14)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_fll_clk_off_en_END (14)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_ulppll_dis_en_START (15)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_ulppll_dis_en_END (15)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_sys_stat_doze2_ctrl_msk_START (16)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL_sys_stat_doze2_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int sys_stat_slow_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_SLOW_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL1_sys_stat_slow_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_SLOW_CTRL1_sys_stat_slow_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int sys_stat_deepsleep_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL1_sys_stat_deepsleep_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_DEEPSLEEP_CTRL1_sys_stat_deepsleep_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int sys_stat_lightsleep_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL1_sys_stat_lightsleep_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_LIGHTSLEEP_CTRL1_sys_stat_lightsleep_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int sys_stat_standby_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_STANDBY_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL1_sys_stat_standby_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_STANDBY_CTRL1_sys_stat_standby_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int sys_stat_ls2std_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LS2STD_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL1_sys_stat_ls2std_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_LS2STD_CTRL1_sys_stat_ls2std_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hfc_common_pll_ctrl_en : 4;
        unsigned int reserved : 12;
        unsigned int sys_stat_doze1_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_hfc_common_pll_ctrl_en_START (0)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_hfc_common_pll_ctrl_en_END (3)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_sys_stat_doze1_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_DOZE1_CTRL1_sys_stat_doze1_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hfc_common_pll_ctrl_en : 4;
        unsigned int reserved : 12;
        unsigned int sys_stat_doze2_ctrl_msk1 : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_hfc_common_pll_ctrl_en_START (0)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_hfc_common_pll_ctrl_en_END (3)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_sys_stat_doze2_ctrl_msk1_START (16)
#define SOC_SCTRL_SYS_STAT_DOZE2_CTRL1_sys_stat_doze2_ctrl_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_output : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_SYS_STAT_CTRL_DBG_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_CTRL_DBG_sc_output_START (0)
#define SOC_SCTRL_SYS_STAT_CTRL_DBG_sc_output_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_lp_enter_doze1_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_enter_doze1_hrd_idx : 8;
        unsigned int slv_pmu_ps_lp_exit_doze1_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_exit_doze1_hrd_idx : 8;
    } reg;
} SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_doze1_hrd_idx_START (0)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_doze1_hrd_idx_END (7)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_doze1_hrd_idx_START (8)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_doze1_hrd_idx_END (15)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_doze1_hrd_idx_START (16)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_doze1_hrd_idx_END (23)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_doze1_hrd_idx_START (24)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_doze1_hrd_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_exit_doze1_time : 24;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_1_pmu_ps_lp_exit_doze1_time_START (0)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_1_pmu_ps_lp_exit_doze1_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_enter_doze1_time : 24;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_2_pmu_ps_lp_enter_doze1_time_START (0)
#define SOC_SCTRL_SC_DOZE1_PMU_PS_CTRL_2_pmu_ps_lp_enter_doze1_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_pmu_ps_lp_enter_doze2_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_enter_doze2_hrd_idx : 8;
        unsigned int slv_pmu_ps_lp_exit_doze2_hrd_idx : 8;
        unsigned int mst_pmu_ps_lp_exit_doze2_hrd_idx : 8;
    } reg;
} SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_doze2_hrd_idx_START (0)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_slv_pmu_ps_lp_enter_doze2_hrd_idx_END (7)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_doze2_hrd_idx_START (8)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_mst_pmu_ps_lp_enter_doze2_hrd_idx_END (15)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_doze2_hrd_idx_START (16)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_slv_pmu_ps_lp_exit_doze2_hrd_idx_END (23)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_doze2_hrd_idx_START (24)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_0_mst_pmu_ps_lp_exit_doze2_hrd_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_exit_doze2_time : 24;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_1_pmu_ps_lp_exit_doze2_time_START (0)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_1_pmu_ps_lp_exit_doze2_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_ps_lp_enter_doze2_time : 24;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_2_pmu_ps_lp_enter_doze2_time_START (0)
#define SOC_SCTRL_SC_DOZE2_PMU_PS_CTRL_2_pmu_ps_lp_enter_doze2_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze1_vote_reg : 16;
        unsigned int sc_doze1_vote0_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE1_VOTE0_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_VOTE0_doze1_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE1_VOTE0_doze1_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE1_VOTE0_sc_doze1_vote0_msk_START (16)
#define SOC_SCTRL_SC_DOZE1_VOTE0_sc_doze1_vote0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze1_vote_reg : 16;
        unsigned int sc_doze1_vote1_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE1_VOTE1_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_VOTE1_doze1_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE1_VOTE1_doze1_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE1_VOTE1_sc_doze1_vote1_msk_START (16)
#define SOC_SCTRL_SC_DOZE1_VOTE1_sc_doze1_vote1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze1_vote_reg : 16;
        unsigned int sc_doze1_vote2_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE1_VOTE2_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_VOTE2_doze1_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE1_VOTE2_doze1_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE1_VOTE2_sc_doze1_vote2_msk_START (16)
#define SOC_SCTRL_SC_DOZE1_VOTE2_sc_doze1_vote2_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze1_vote_reg : 16;
        unsigned int sc_doze1_vote3_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE1_VOTE3_UNION;
#endif
#define SOC_SCTRL_SC_DOZE1_VOTE3_doze1_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE1_VOTE3_doze1_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE1_VOTE3_sc_doze1_vote3_msk_START (16)
#define SOC_SCTRL_SC_DOZE1_VOTE3_sc_doze1_vote3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze2_vote_reg : 16;
        unsigned int sc_doze2_vote0_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE2_VOTE0_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_VOTE0_doze2_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE2_VOTE0_doze2_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE2_VOTE0_sc_doze2_vote0_msk_START (16)
#define SOC_SCTRL_SC_DOZE2_VOTE0_sc_doze2_vote0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze2_vote_reg : 16;
        unsigned int sc_doze2_vote1_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE2_VOTE1_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_VOTE1_doze2_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE2_VOTE1_doze2_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE2_VOTE1_sc_doze2_vote1_msk_START (16)
#define SOC_SCTRL_SC_DOZE2_VOTE1_sc_doze2_vote1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze2_vote_reg : 16;
        unsigned int sc_doze2_vote2_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE2_VOTE2_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_VOTE2_doze2_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE2_VOTE2_doze2_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE2_VOTE2_sc_doze2_vote2_msk_START (16)
#define SOC_SCTRL_SC_DOZE2_VOTE2_sc_doze2_vote2_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze2_vote_reg : 16;
        unsigned int sc_doze2_vote3_msk : 16;
    } reg;
} SOC_SCTRL_SC_DOZE2_VOTE3_UNION;
#endif
#define SOC_SCTRL_SC_DOZE2_VOTE3_doze2_vote_reg_START (0)
#define SOC_SCTRL_SC_DOZE2_VOTE3_doze2_vote_reg_END (15)
#define SOC_SCTRL_SC_DOZE2_VOTE3_sc_doze2_vote3_msk_START (16)
#define SOC_SCTRL_SC_DOZE2_VOTE3_sc_doze2_vote3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_lp_ctrl_idle_flag_mask : 1;
        unsigned int gpu_lp_ctrl_idle_flag_mask : 1;
        unsigned int ddr_lp_ctrl_idle_flag_mask : 1;
        unsigned int lpmcu_sleep_status_mask : 1;
        unsigned int media_lp_ctrl_idle_flag_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int cfgbus_nopending_comb_mask : 1;
        unsigned int center_crossbar_nopending_comb_mask : 1;
        unsigned int hsdt0bus_nopending_comb_mask : 1;
        unsigned int hsdt1bus_nopending_comb_mask : 1;
        unsigned int fcmbus_nopending_comb_mask : 1;
        unsigned int m1qic_nopending_comb_mask : 1;
        unsigned int qice_wrap_main_nopending_comb_mask : 1;
        unsigned int qice_wrap_sc_nopending_comb_mask : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ffts_taskempty_mask : 1;
        unsigned int ffts_idle_mask : 1;
        unsigned int dfa_doze_mask : 1;
        unsigned int modem_peri_mask : 1;
        unsigned int sdcu_idle_mask : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
    } reg;
} SOC_SCTRL_SW_INDICATORS_MASK0_UNION;
#endif
#define SOC_SCTRL_SW_INDICATORS_MASK0_cpu_lp_ctrl_idle_flag_mask_START (0)
#define SOC_SCTRL_SW_INDICATORS_MASK0_cpu_lp_ctrl_idle_flag_mask_END (0)
#define SOC_SCTRL_SW_INDICATORS_MASK0_gpu_lp_ctrl_idle_flag_mask_START (1)
#define SOC_SCTRL_SW_INDICATORS_MASK0_gpu_lp_ctrl_idle_flag_mask_END (1)
#define SOC_SCTRL_SW_INDICATORS_MASK0_ddr_lp_ctrl_idle_flag_mask_START (2)
#define SOC_SCTRL_SW_INDICATORS_MASK0_ddr_lp_ctrl_idle_flag_mask_END (2)
#define SOC_SCTRL_SW_INDICATORS_MASK0_lpmcu_sleep_status_mask_START (3)
#define SOC_SCTRL_SW_INDICATORS_MASK0_lpmcu_sleep_status_mask_END (3)
#define SOC_SCTRL_SW_INDICATORS_MASK0_media_lp_ctrl_idle_flag_mask_START (4)
#define SOC_SCTRL_SW_INDICATORS_MASK0_media_lp_ctrl_idle_flag_mask_END (4)
#define SOC_SCTRL_SW_INDICATORS_MASK0_cfgbus_nopending_comb_mask_START (9)
#define SOC_SCTRL_SW_INDICATORS_MASK0_cfgbus_nopending_comb_mask_END (9)
#define SOC_SCTRL_SW_INDICATORS_MASK0_center_crossbar_nopending_comb_mask_START (10)
#define SOC_SCTRL_SW_INDICATORS_MASK0_center_crossbar_nopending_comb_mask_END (10)
#define SOC_SCTRL_SW_INDICATORS_MASK0_hsdt0bus_nopending_comb_mask_START (11)
#define SOC_SCTRL_SW_INDICATORS_MASK0_hsdt0bus_nopending_comb_mask_END (11)
#define SOC_SCTRL_SW_INDICATORS_MASK0_hsdt1bus_nopending_comb_mask_START (12)
#define SOC_SCTRL_SW_INDICATORS_MASK0_hsdt1bus_nopending_comb_mask_END (12)
#define SOC_SCTRL_SW_INDICATORS_MASK0_fcmbus_nopending_comb_mask_START (13)
#define SOC_SCTRL_SW_INDICATORS_MASK0_fcmbus_nopending_comb_mask_END (13)
#define SOC_SCTRL_SW_INDICATORS_MASK0_m1qic_nopending_comb_mask_START (14)
#define SOC_SCTRL_SW_INDICATORS_MASK0_m1qic_nopending_comb_mask_END (14)
#define SOC_SCTRL_SW_INDICATORS_MASK0_qice_wrap_main_nopending_comb_mask_START (15)
#define SOC_SCTRL_SW_INDICATORS_MASK0_qice_wrap_main_nopending_comb_mask_END (15)
#define SOC_SCTRL_SW_INDICATORS_MASK0_qice_wrap_sc_nopending_comb_mask_START (16)
#define SOC_SCTRL_SW_INDICATORS_MASK0_qice_wrap_sc_nopending_comb_mask_END (16)
#define SOC_SCTRL_SW_INDICATORS_MASK0_ffts_taskempty_mask_START (21)
#define SOC_SCTRL_SW_INDICATORS_MASK0_ffts_taskempty_mask_END (21)
#define SOC_SCTRL_SW_INDICATORS_MASK0_ffts_idle_mask_START (22)
#define SOC_SCTRL_SW_INDICATORS_MASK0_ffts_idle_mask_END (22)
#define SOC_SCTRL_SW_INDICATORS_MASK0_dfa_doze_mask_START (23)
#define SOC_SCTRL_SW_INDICATORS_MASK0_dfa_doze_mask_END (23)
#define SOC_SCTRL_SW_INDICATORS_MASK0_modem_peri_mask_START (24)
#define SOC_SCTRL_SW_INDICATORS_MASK0_modem_peri_mask_END (24)
#define SOC_SCTRL_SW_INDICATORS_MASK0_sdcu_idle_mask_START (25)
#define SOC_SCTRL_SW_INDICATORS_MASK0_sdcu_idle_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int media1_mtcmos_ack_mask : 1;
        unsigned int dss_doze1_idle_indicator_mask : 1;
        unsigned int vdec_mtcmos_ack_mask : 1;
        unsigned int venc_mtcmos_ack_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int npu_top_iso_en_mask : 1;
        unsigned int gpu_top_iso_en_mask : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int media2_mtcmos_ack_mask : 1;
        unsigned int dpa_mtcmos_ack_mask : 1;
        unsigned int sdcu_mtcmos_ack_mask : 1;
        unsigned int gpu_idle_stat_mask : 1;
        unsigned int gpu_off_stat_mask : 1;
        unsigned int acpu_pc1_stat_mask : 1;
        unsigned int acpu_pc3_stat_mask : 1;
        unsigned int peri_dvs_profile_status_mask : 1;
        unsigned int m1_dvs_profile_status_mask : 1;
        unsigned int m2_dvs_profile_status_mask : 1;
        unsigned int hw_dss_dvfs_doze1_vote_mask : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_SCTRL_SW_INDICATORS_MASK1_UNION;
#endif
#define SOC_SCTRL_SW_INDICATORS_MASK1_media1_mtcmos_ack_mask_START (0)
#define SOC_SCTRL_SW_INDICATORS_MASK1_media1_mtcmos_ack_mask_END (0)
#define SOC_SCTRL_SW_INDICATORS_MASK1_dss_doze1_idle_indicator_mask_START (1)
#define SOC_SCTRL_SW_INDICATORS_MASK1_dss_doze1_idle_indicator_mask_END (1)
#define SOC_SCTRL_SW_INDICATORS_MASK1_vdec_mtcmos_ack_mask_START (2)
#define SOC_SCTRL_SW_INDICATORS_MASK1_vdec_mtcmos_ack_mask_END (2)
#define SOC_SCTRL_SW_INDICATORS_MASK1_venc_mtcmos_ack_mask_START (3)
#define SOC_SCTRL_SW_INDICATORS_MASK1_venc_mtcmos_ack_mask_END (3)
#define SOC_SCTRL_SW_INDICATORS_MASK1_npu_top_iso_en_mask_START (6)
#define SOC_SCTRL_SW_INDICATORS_MASK1_npu_top_iso_en_mask_END (6)
#define SOC_SCTRL_SW_INDICATORS_MASK1_gpu_top_iso_en_mask_START (7)
#define SOC_SCTRL_SW_INDICATORS_MASK1_gpu_top_iso_en_mask_END (7)
#define SOC_SCTRL_SW_INDICATORS_MASK1_media2_mtcmos_ack_mask_START (11)
#define SOC_SCTRL_SW_INDICATORS_MASK1_media2_mtcmos_ack_mask_END (11)
#define SOC_SCTRL_SW_INDICATORS_MASK1_dpa_mtcmos_ack_mask_START (12)
#define SOC_SCTRL_SW_INDICATORS_MASK1_dpa_mtcmos_ack_mask_END (12)
#define SOC_SCTRL_SW_INDICATORS_MASK1_sdcu_mtcmos_ack_mask_START (13)
#define SOC_SCTRL_SW_INDICATORS_MASK1_sdcu_mtcmos_ack_mask_END (13)
#define SOC_SCTRL_SW_INDICATORS_MASK1_gpu_idle_stat_mask_START (14)
#define SOC_SCTRL_SW_INDICATORS_MASK1_gpu_idle_stat_mask_END (14)
#define SOC_SCTRL_SW_INDICATORS_MASK1_gpu_off_stat_mask_START (15)
#define SOC_SCTRL_SW_INDICATORS_MASK1_gpu_off_stat_mask_END (15)
#define SOC_SCTRL_SW_INDICATORS_MASK1_acpu_pc1_stat_mask_START (16)
#define SOC_SCTRL_SW_INDICATORS_MASK1_acpu_pc1_stat_mask_END (16)
#define SOC_SCTRL_SW_INDICATORS_MASK1_acpu_pc3_stat_mask_START (17)
#define SOC_SCTRL_SW_INDICATORS_MASK1_acpu_pc3_stat_mask_END (17)
#define SOC_SCTRL_SW_INDICATORS_MASK1_peri_dvs_profile_status_mask_START (18)
#define SOC_SCTRL_SW_INDICATORS_MASK1_peri_dvs_profile_status_mask_END (18)
#define SOC_SCTRL_SW_INDICATORS_MASK1_m1_dvs_profile_status_mask_START (19)
#define SOC_SCTRL_SW_INDICATORS_MASK1_m1_dvs_profile_status_mask_END (19)
#define SOC_SCTRL_SW_INDICATORS_MASK1_m2_dvs_profile_status_mask_START (20)
#define SOC_SCTRL_SW_INDICATORS_MASK1_m2_dvs_profile_status_mask_END (20)
#define SOC_SCTRL_SW_INDICATORS_MASK1_hw_dss_dvfs_doze1_vote_mask_START (21)
#define SOC_SCTRL_SW_INDICATORS_MASK1_hw_dss_dvfs_doze1_vote_mask_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_dmc_a_ddrc_byp_stat_mask : 1;
        unsigned int adb_dmc_b_ddrc_byp_stat_mask : 1;
        unsigned int adb_dmc_c_ddrc_byp_stat_mask : 1;
        unsigned int adb_dmc_d_ddrc_byp_stat_mask : 1;
        unsigned int adb_dmc_a_ddrc_asref_stat_mask : 1;
        unsigned int adb_dmc_b_ddrc_asref_stat_mask : 1;
        unsigned int adb_dmc_c_ddrc_asref_stat_mask : 1;
        unsigned int adb_dmc_d_ddrc_asref_stat_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 16;
    } reg;
} SOC_SCTRL_SW_DDR_IDLE_MASK_UNION;
#endif
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_a_ddrc_byp_stat_mask_START (0)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_a_ddrc_byp_stat_mask_END (0)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_b_ddrc_byp_stat_mask_START (1)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_b_ddrc_byp_stat_mask_END (1)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_c_ddrc_byp_stat_mask_START (2)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_c_ddrc_byp_stat_mask_END (2)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_d_ddrc_byp_stat_mask_START (3)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_d_ddrc_byp_stat_mask_END (3)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_a_ddrc_asref_stat_mask_START (4)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_a_ddrc_asref_stat_mask_END (4)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_b_ddrc_asref_stat_mask_START (5)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_b_ddrc_asref_stat_mask_END (5)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_c_ddrc_asref_stat_mask_START (6)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_c_ddrc_asref_stat_mask_END (6)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_d_ddrc_asref_stat_mask_START (7)
#define SOC_SCTRL_SW_DDR_IDLE_MASK_adb_dmc_d_ddrc_asref_stat_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_acpu_pc1_filter : 12;
        unsigned int sw_acpu_pc3_filter : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_DOZE_COUNT_CTRL0_UNION;
#endif
#define SOC_SCTRL_DOZE_COUNT_CTRL0_sw_acpu_pc1_filter_START (0)
#define SOC_SCTRL_DOZE_COUNT_CTRL0_sw_acpu_pc1_filter_END (11)
#define SOC_SCTRL_DOZE_COUNT_CTRL0_sw_acpu_pc3_filter_START (12)
#define SOC_SCTRL_DOZE_COUNT_CTRL0_sw_acpu_pc3_filter_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_gpu_idle_doze1_filter : 12;
        unsigned int sw_gpu_off_doze2_filter : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_SCTRL_DOZE_COUNT_CTRL_GPU_UNION;
#endif
#define SOC_SCTRL_DOZE_COUNT_CTRL_GPU_sw_gpu_idle_doze1_filter_START (0)
#define SOC_SCTRL_DOZE_COUNT_CTRL_GPU_sw_gpu_idle_doze1_filter_END (11)
#define SOC_SCTRL_DOZE_COUNT_CTRL_GPU_sw_gpu_off_doze2_filter_START (12)
#define SOC_SCTRL_DOZE_COUNT_CTRL_GPU_sw_gpu_off_doze2_filter_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int normal_enter_time : 20;
        unsigned int doze_entry_pre_clkon_bypass : 1;
        unsigned int doze_ao2peri_clkgt_off_done_bypass : 1;
        unsigned int modem_doze1_hw_vote_bypass : 1;
        unsigned int dss_doze1_hw_vote_bypass : 1;
        unsigned int doze2_req_mask : 1;
        unsigned int doze1_req_mask : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_SCTRL_DOZE_COUNT_CTRL1_UNION;
#endif
#define SOC_SCTRL_DOZE_COUNT_CTRL1_normal_enter_time_START (0)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_normal_enter_time_END (19)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze_entry_pre_clkon_bypass_START (20)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze_entry_pre_clkon_bypass_END (20)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze_ao2peri_clkgt_off_done_bypass_START (21)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze_ao2peri_clkgt_off_done_bypass_END (21)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_modem_doze1_hw_vote_bypass_START (22)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_modem_doze1_hw_vote_bypass_END (22)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_dss_doze1_hw_vote_bypass_START (23)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_dss_doze1_hw_vote_bypass_END (23)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze2_req_mask_START (24)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze2_req_mask_END (24)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze1_req_mask_START (25)
#define SOC_SCTRL_DOZE_COUNT_CTRL1_doze1_req_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze_wakeup_time : 20;
        unsigned int intr_doze_timeout_wakeup_clr : 1;
        unsigned int intr_doze_timeout_wakeup : 1;
        unsigned int doze_filter_bypass : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_SCTRL_DOZE_COUNT_CTRL2_UNION;
#endif
#define SOC_SCTRL_DOZE_COUNT_CTRL2_doze_wakeup_time_START (0)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_doze_wakeup_time_END (19)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_intr_doze_timeout_wakeup_clr_START (20)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_intr_doze_timeout_wakeup_clr_END (20)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_intr_doze_timeout_wakeup_START (21)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_intr_doze_timeout_wakeup_END (21)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_doze_filter_bypass_START (22)
#define SOC_SCTRL_DOZE_COUNT_CTRL2_doze_filter_bypass_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_doze1_time : 32;
    } reg;
} SOC_SCTRL_DOZE_COUNT_CTRL3_UNION;
#endif
#define SOC_SCTRL_DOZE_COUNT_CTRL3_filter_doze1_time_START (0)
#define SOC_SCTRL_DOZE_COUNT_CTRL3_filter_doze1_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int filter_doze2_time : 32;
    } reg;
} SOC_SCTRL_DOZE_COUNT_CTRL4_UNION;
#endif
#define SOC_SCTRL_DOZE_COUNT_CTRL4_filter_doze2_time_START (0)
#define SOC_SCTRL_DOZE_COUNT_CTRL4_filter_doze2_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze1_req_waitcfg_in : 10;
        unsigned int doze1_req_waitcfg_out : 10;
        unsigned int bus_idle_doze_mask : 12;
    } reg;
} SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_UNION;
#endif
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_doze1_req_waitcfg_in_START (0)
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_doze1_req_waitcfg_in_END (9)
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_doze1_req_waitcfg_out_START (10)
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_doze1_req_waitcfg_out_END (19)
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_bus_idle_doze_mask_START (20)
#define SOC_SCTRL_DOZE1_DEBOUNCE_CTRL_bus_idle_doze_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze2_req_waitcfg_in : 10;
        unsigned int doze2_req_waitcfg_out : 10;
        unsigned int ip_idle_doze_mask : 12;
    } reg;
} SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_UNION;
#endif
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_doze2_req_waitcfg_in_START (0)
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_doze2_req_waitcfg_in_END (9)
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_doze2_req_waitcfg_out_START (10)
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_doze2_req_waitcfg_out_END (19)
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_ip_idle_doze_mask_START (20)
#define SOC_SCTRL_DOZE2_DEBOUNCE_CTRL_ip_idle_doze_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_idle_valid : 12;
        unsigned int master_idle_valid : 8;
        unsigned int ip_idle_valid : 12;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_0_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_0_bus_idle_valid_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_0_bus_idle_valid_END (11)
#define SOC_SCTRL_DOZE_ARB_STAT_0_master_idle_valid_START (12)
#define SOC_SCTRL_DOZE_ARB_STAT_0_master_idle_valid_END (19)
#define SOC_SCTRL_DOZE_ARB_STAT_0_ip_idle_valid_START (20)
#define SOC_SCTRL_DOZE_ARB_STAT_0_ip_idle_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze1_req_aft : 1;
        unsigned int doze2_req_aft : 1;
        unsigned int doze1_req : 1;
        unsigned int doze2_req : 1;
        unsigned int sw_doze1_vote_valid : 1;
        unsigned int sw_doze2_vote_valid : 1;
        unsigned int acpu_doze1_ok : 1;
        unsigned int acpu_doze2_ok : 1;
        unsigned int peri_profile_ok : 1;
        unsigned int others_pwroff_ok : 1;
        unsigned int media_doze1_ok : 1;
        unsigned int media_doze2_ok : 1;
        unsigned int modem_doze1_ok : 1;
        unsigned int modem_doze2_ok : 1;
        unsigned int gpu_lpcs_idle_ok : 1;
        unsigned int gpu_lpcs_off_ok : 1;
        unsigned int ddr_idle_valid : 16;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_1_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze1_req_aft_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze1_req_aft_END (0)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze2_req_aft_START (1)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze2_req_aft_END (1)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze1_req_START (2)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze1_req_END (2)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze2_req_START (3)
#define SOC_SCTRL_DOZE_ARB_STAT_1_doze2_req_END (3)
#define SOC_SCTRL_DOZE_ARB_STAT_1_sw_doze1_vote_valid_START (4)
#define SOC_SCTRL_DOZE_ARB_STAT_1_sw_doze1_vote_valid_END (4)
#define SOC_SCTRL_DOZE_ARB_STAT_1_sw_doze2_vote_valid_START (5)
#define SOC_SCTRL_DOZE_ARB_STAT_1_sw_doze2_vote_valid_END (5)
#define SOC_SCTRL_DOZE_ARB_STAT_1_acpu_doze1_ok_START (6)
#define SOC_SCTRL_DOZE_ARB_STAT_1_acpu_doze1_ok_END (6)
#define SOC_SCTRL_DOZE_ARB_STAT_1_acpu_doze2_ok_START (7)
#define SOC_SCTRL_DOZE_ARB_STAT_1_acpu_doze2_ok_END (7)
#define SOC_SCTRL_DOZE_ARB_STAT_1_peri_profile_ok_START (8)
#define SOC_SCTRL_DOZE_ARB_STAT_1_peri_profile_ok_END (8)
#define SOC_SCTRL_DOZE_ARB_STAT_1_others_pwroff_ok_START (9)
#define SOC_SCTRL_DOZE_ARB_STAT_1_others_pwroff_ok_END (9)
#define SOC_SCTRL_DOZE_ARB_STAT_1_media_doze1_ok_START (10)
#define SOC_SCTRL_DOZE_ARB_STAT_1_media_doze1_ok_END (10)
#define SOC_SCTRL_DOZE_ARB_STAT_1_media_doze2_ok_START (11)
#define SOC_SCTRL_DOZE_ARB_STAT_1_media_doze2_ok_END (11)
#define SOC_SCTRL_DOZE_ARB_STAT_1_modem_doze1_ok_START (12)
#define SOC_SCTRL_DOZE_ARB_STAT_1_modem_doze1_ok_END (12)
#define SOC_SCTRL_DOZE_ARB_STAT_1_modem_doze2_ok_START (13)
#define SOC_SCTRL_DOZE_ARB_STAT_1_modem_doze2_ok_END (13)
#define SOC_SCTRL_DOZE_ARB_STAT_1_gpu_lpcs_idle_ok_START (14)
#define SOC_SCTRL_DOZE_ARB_STAT_1_gpu_lpcs_idle_ok_END (14)
#define SOC_SCTRL_DOZE_ARB_STAT_1_gpu_lpcs_off_ok_START (15)
#define SOC_SCTRL_DOZE_ARB_STAT_1_gpu_lpcs_off_ok_END (15)
#define SOC_SCTRL_DOZE_ARB_STAT_1_ddr_idle_valid_START (16)
#define SOC_SCTRL_DOZE_ARB_STAT_1_ddr_idle_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_package_pwrmod_trans_req : 1;
        unsigned int cpu_package_pwrmod_trans_ack : 1;
        unsigned int cpu_package_pwrmod_trans_stat : 4;
        unsigned int masters_idle_indicators : 8;
        unsigned int bus_idle_status : 12;
        unsigned int reserved : 6;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_2_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_2_cpu_package_pwrmod_trans_req_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_2_cpu_package_pwrmod_trans_req_END (0)
#define SOC_SCTRL_DOZE_ARB_STAT_2_cpu_package_pwrmod_trans_ack_START (1)
#define SOC_SCTRL_DOZE_ARB_STAT_2_cpu_package_pwrmod_trans_ack_END (1)
#define SOC_SCTRL_DOZE_ARB_STAT_2_cpu_package_pwrmod_trans_stat_START (2)
#define SOC_SCTRL_DOZE_ARB_STAT_2_cpu_package_pwrmod_trans_stat_END (5)
#define SOC_SCTRL_DOZE_ARB_STAT_2_masters_idle_indicators_START (6)
#define SOC_SCTRL_DOZE_ARB_STAT_2_masters_idle_indicators_END (13)
#define SOC_SCTRL_DOZE_ARB_STAT_2_bus_idle_status_START (14)
#define SOC_SCTRL_DOZE_ARB_STAT_2_bus_idle_status_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_idle_indicators : 12;
        unsigned int ddr_idle_indicators : 16;
        unsigned int normal_enter_timeout : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_3_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_3_ip_idle_indicators_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_3_ip_idle_indicators_END (11)
#define SOC_SCTRL_DOZE_ARB_STAT_3_ddr_idle_indicators_START (12)
#define SOC_SCTRL_DOZE_ARB_STAT_3_ddr_idle_indicators_END (27)
#define SOC_SCTRL_DOZE_ARB_STAT_3_normal_enter_timeout_START (28)
#define SOC_SCTRL_DOZE_ARB_STAT_3_normal_enter_timeout_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwroff_indicators : 5;
        unsigned int pwron_indicators : 5;
        unsigned int media_pwron_indicator : 1;
        unsigned int dss_doze1_idle_indicator : 1;
        unsigned int media_others_pwron_indicator : 4;
        unsigned int little_cluster_pwrmod_trans_stat : 4;
        unsigned int middle_cluster_pwrmod_trans_stat : 4;
        unsigned int big_cluster_pwrmod_trans_stat : 4;
        unsigned int sw_ack_clk_periph_cpu_lit_sw : 2;
        unsigned int sw_ack_clk_periph_cpu_hc_sw : 2;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_4_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_4_pwroff_indicators_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_4_pwroff_indicators_END (4)
#define SOC_SCTRL_DOZE_ARB_STAT_4_pwron_indicators_START (5)
#define SOC_SCTRL_DOZE_ARB_STAT_4_pwron_indicators_END (9)
#define SOC_SCTRL_DOZE_ARB_STAT_4_media_pwron_indicator_START (10)
#define SOC_SCTRL_DOZE_ARB_STAT_4_media_pwron_indicator_END (10)
#define SOC_SCTRL_DOZE_ARB_STAT_4_dss_doze1_idle_indicator_START (11)
#define SOC_SCTRL_DOZE_ARB_STAT_4_dss_doze1_idle_indicator_END (11)
#define SOC_SCTRL_DOZE_ARB_STAT_4_media_others_pwron_indicator_START (12)
#define SOC_SCTRL_DOZE_ARB_STAT_4_media_others_pwron_indicator_END (15)
#define SOC_SCTRL_DOZE_ARB_STAT_4_little_cluster_pwrmod_trans_stat_START (16)
#define SOC_SCTRL_DOZE_ARB_STAT_4_little_cluster_pwrmod_trans_stat_END (19)
#define SOC_SCTRL_DOZE_ARB_STAT_4_middle_cluster_pwrmod_trans_stat_START (20)
#define SOC_SCTRL_DOZE_ARB_STAT_4_middle_cluster_pwrmod_trans_stat_END (23)
#define SOC_SCTRL_DOZE_ARB_STAT_4_big_cluster_pwrmod_trans_stat_START (24)
#define SOC_SCTRL_DOZE_ARB_STAT_4_big_cluster_pwrmod_trans_stat_END (27)
#define SOC_SCTRL_DOZE_ARB_STAT_4_sw_ack_clk_periph_cpu_lit_sw_START (28)
#define SOC_SCTRL_DOZE_ARB_STAT_4_sw_ack_clk_periph_cpu_lit_sw_END (29)
#define SOC_SCTRL_DOZE_ARB_STAT_4_sw_ack_clk_periph_cpu_hc_sw_START (30)
#define SOC_SCTRL_DOZE_ARB_STAT_4_sw_ack_clk_periph_cpu_hc_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int doze_timeout_cnt : 20;
        unsigned int filter_doze_timeout : 1;
        unsigned int intr_ip_bus_mdm_idle_invalid : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_5_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_5_doze_timeout_cnt_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_5_doze_timeout_cnt_END (19)
#define SOC_SCTRL_DOZE_ARB_STAT_5_filter_doze_timeout_START (20)
#define SOC_SCTRL_DOZE_ARB_STAT_5_filter_doze_timeout_END (20)
#define SOC_SCTRL_DOZE_ARB_STAT_5_intr_ip_bus_mdm_idle_invalid_START (21)
#define SOC_SCTRL_DOZE_ARB_STAT_5_intr_ip_bus_mdm_idle_invalid_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_pwrmod_trans_stat_lpcs_ack : 1;
        unsigned int gpu_pwrmod_trans_stat_lpcs_req : 1;
        unsigned int gpu_pwrmod_trans_stat_lpcs_req_ff2 : 1;
        unsigned int gpu_doze1_ok : 1;
        unsigned int gpu_doze2_ok : 1;
        unsigned int gpu_idle_stat : 1;
        unsigned int gpu_off_stat : 1;
        unsigned int gpu_idle_doze1_vote_mask : 1;
        unsigned int gpu_off_doze2_vote_mask : 1;
        unsigned int reserved : 3;
        unsigned int gpu_doze_cnt : 12;
        unsigned int cpu_lp_ctrl_force_idle_stat : 8;
    } reg;
} SOC_SCTRL_DOZE_ARB_STAT_6_UNION;
#endif
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_pwrmod_trans_stat_lpcs_ack_START (0)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_pwrmod_trans_stat_lpcs_ack_END (0)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_pwrmod_trans_stat_lpcs_req_START (1)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_pwrmod_trans_stat_lpcs_req_END (1)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_pwrmod_trans_stat_lpcs_req_ff2_START (2)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_pwrmod_trans_stat_lpcs_req_ff2_END (2)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_doze1_ok_START (3)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_doze1_ok_END (3)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_doze2_ok_START (4)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_doze2_ok_END (4)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_idle_stat_START (5)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_idle_stat_END (5)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_off_stat_START (6)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_off_stat_END (6)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_idle_doze1_vote_mask_START (7)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_idle_doze1_vote_mask_END (7)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_off_doze2_vote_mask_START (8)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_off_doze2_vote_mask_END (8)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_doze_cnt_START (12)
#define SOC_SCTRL_DOZE_ARB_STAT_6_gpu_doze_cnt_END (23)
#define SOC_SCTRL_DOZE_ARB_STAT_6_cpu_lp_ctrl_force_idle_stat_START (24)
#define SOC_SCTRL_DOZE_ARB_STAT_6_cpu_lp_ctrl_force_idle_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysbus_pwrd_sft_req : 1;
        unsigned int sysbus_pwrd_sft_ctrl_en : 1;
        unsigned int sysbus_pwrd_ack : 1;
        unsigned int aobus2sysbus_pwrd_sft_req : 1;
        unsigned int aobus2sysbus_pwrd_sft_ctrl_en : 1;
        unsigned int aobus2sysbus_pwrd_ack : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SCTRL_SYSBUS_PWRD_CTRL_UNION;
#endif
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_sysbus_pwrd_sft_req_START (0)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_sysbus_pwrd_sft_req_END (0)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_sysbus_pwrd_sft_ctrl_en_START (1)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_sysbus_pwrd_sft_ctrl_en_END (1)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_sysbus_pwrd_ack_START (2)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_sysbus_pwrd_ack_END (2)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_aobus2sysbus_pwrd_sft_req_START (3)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_aobus2sysbus_pwrd_sft_req_END (3)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_aobus2sysbus_pwrd_sft_ctrl_en_START (4)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_aobus2sysbus_pwrd_sft_ctrl_en_END (4)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_aobus2sysbus_pwrd_ack_START (5)
#define SOC_SCTRL_SYSBUS_PWRD_CTRL_aobus2sysbus_pwrd_ack_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_sft_sw2fll_req : 2;
        unsigned int sc_sw2fll_req_msk : 5;
        unsigned int reserved_0 : 1;
        unsigned int lfc_mode_fll_to_32k_sft_req : 1;
        unsigned int lfc_mode_fll_to_32k_sft_req_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int modem_doze1_mask : 1;
        unsigned int reserved_2 : 3;
        unsigned int sc_sclk_sw2fll_ctrl_msk : 16;
    } reg;
} SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_UNION;
#endif
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_sc_sft_sw2fll_req_START (0)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_sc_sft_sw2fll_req_END (1)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_sc_sw2fll_req_msk_START (2)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_sc_sw2fll_req_msk_END (6)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_lfc_mode_fll_to_32k_sft_req_START (8)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_lfc_mode_fll_to_32k_sft_req_END (8)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_lfc_mode_fll_to_32k_sft_req_en_START (9)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_lfc_mode_fll_to_32k_sft_req_en_END (9)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_modem_doze1_mask_START (12)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_modem_doze1_mask_END (12)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_sc_sclk_sw2fll_ctrl_msk_START (16)
#define SOC_SCTRL_SC_SCLK_SW2FLL_CTRL_sc_sclk_sw2fll_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcxo_on_time : 24;
        unsigned int tcxo_enable_sel : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_SCTRL_SC_TCXO_CTRL_UNION;
#endif
#define SOC_SCTRL_SC_TCXO_CTRL_tcxo_on_time_START (0)
#define SOC_SCTRL_SC_TCXO_CTRL_tcxo_on_time_END (23)
#define SOC_SCTRL_SC_TCXO_CTRL_tcxo_enable_sel_START (24)
#define SOC_SCTRL_SC_TCXO_CTRL_tcxo_enable_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pw_nxt_stat : 4;
        unsigned int pw_cur_stat : 4;
        unsigned int peri_iso_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 11;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SCTRL_SC_PERI_POWER_STAT_UNION;
#endif
#define SOC_SCTRL_SC_PERI_POWER_STAT_pw_nxt_stat_START (0)
#define SOC_SCTRL_SC_PERI_POWER_STAT_pw_nxt_stat_END (3)
#define SOC_SCTRL_SC_PERI_POWER_STAT_pw_cur_stat_START (4)
#define SOC_SCTRL_SC_PERI_POWER_STAT_pw_cur_stat_END (7)
#define SOC_SCTRL_SC_PERI_POWER_STAT_peri_iso_en_START (8)
#define SOC_SCTRL_SC_PERI_POWER_STAT_peri_iso_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_iso_dynamic_ctrl_bypass : 1;
        unsigned int reserved_0 : 3;
        unsigned int peri_rst_dynamic_ctrl_bypass : 1;
        unsigned int reserved_1 : 3;
        unsigned int peri_urst_flag_ctrl_bypass : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_SCTRL_SCPERIISOBYPASS_UNION;
#endif
#define SOC_SCTRL_SCPERIISOBYPASS_peri_iso_dynamic_ctrl_bypass_START (0)
#define SOC_SCTRL_SCPERIISOBYPASS_peri_iso_dynamic_ctrl_bypass_END (0)
#define SOC_SCTRL_SCPERIISOBYPASS_peri_rst_dynamic_ctrl_bypass_START (4)
#define SOC_SCTRL_SCPERIISOBYPASS_peri_rst_dynamic_ctrl_bypass_END (4)
#define SOC_SCTRL_SCPERIISOBYPASS_peri_urst_flag_ctrl_bypass_START (8)
#define SOC_SCTRL_SCPERIISOBYPASS_peri_urst_flag_ctrl_bypass_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int been_doze2_flag : 1;
        unsigned int reserved_0 : 27;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_SCTRL_DOZE2_FLAG_STAT_UNION;
#endif
#define SOC_SCTRL_DOZE2_FLAG_STAT_been_doze2_flag_START (0)
#define SOC_SCTRL_DOZE2_FLAG_STAT_been_doze2_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_clk_on_time : 16;
        unsigned int peri_clk_off_time : 16;
    } reg;
} SOC_SCTRL_SC_PERI_POWER_CTRL_0_UNION;
#endif
#define SOC_SCTRL_SC_PERI_POWER_CTRL_0_peri_clk_on_time_START (0)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_0_peri_clk_on_time_END (15)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_0_peri_clk_off_time_START (16)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_0_peri_clk_off_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_rst_on_time : 16;
        unsigned int peri_rst_off_time : 16;
    } reg;
} SOC_SCTRL_SC_PERI_POWER_CTRL_1_UNION;
#endif
#define SOC_SCTRL_SC_PERI_POWER_CTRL_1_peri_rst_on_time_START (0)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_1_peri_rst_on_time_END (15)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_1_peri_rst_off_time_START (16)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_1_peri_rst_off_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_iso_dis_time : 16;
        unsigned int peri_iso_en_time : 16;
    } reg;
} SOC_SCTRL_SC_PERI_POWER_CTRL_2_UNION;
#endif
#define SOC_SCTRL_SC_PERI_POWER_CTRL_2_peri_iso_dis_time_START (0)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_2_peri_iso_dis_time_END (15)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_2_peri_iso_en_time_START (16)
#define SOC_SCTRL_SC_PERI_POWER_CTRL_2_peri_iso_en_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resume_watchdog_time : 20;
        unsigned int resume_watchdog_bypass : 1;
        unsigned int resume_watchdog_stop_pulse : 1;
        unsigned int reserved_0 : 2;
        unsigned int resume_watchdog_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int sys_ctrl_wd_rst_req : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_UNION;
#endif
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_time_START (0)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_time_END (19)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_bypass_START (20)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_bypass_END (20)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_stop_pulse_START (21)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_stop_pulse_END (21)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_en_START (24)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_resume_watchdog_en_END (24)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_sys_ctrl_wd_rst_req_START (28)
#define SOC_SCTRL_SC_RESUME_WATCHDOG_CTRL_sys_ctrl_wd_rst_req_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deepsleeped : 1;
        unsigned int lightsleeped : 1;
        unsigned int standbyed : 1;
        unsigned int doze1ed : 1;
        unsigned int doze2ed : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 11;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_SCTRL_SC_LP_STAT_UNION;
#endif
#define SOC_SCTRL_SC_LP_STAT_deepsleeped_START (0)
#define SOC_SCTRL_SC_LP_STAT_deepsleeped_END (0)
#define SOC_SCTRL_SC_LP_STAT_lightsleeped_START (1)
#define SOC_SCTRL_SC_LP_STAT_lightsleeped_END (1)
#define SOC_SCTRL_SC_LP_STAT_standbyed_START (2)
#define SOC_SCTRL_SC_LP_STAT_standbyed_END (2)
#define SOC_SCTRL_SC_LP_STAT_doze1ed_START (3)
#define SOC_SCTRL_SC_LP_STAT_doze1ed_END (3)
#define SOC_SCTRL_SC_LP_STAT_doze2ed_START (4)
#define SOC_SCTRL_SC_LP_STAT_doze2ed_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deepsleeped_clr : 1;
        unsigned int lightsleeped_clr : 1;
        unsigned int standbyed_clr : 1;
        unsigned int doze1ed_clr : 1;
        unsigned int doze2ed_clr : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SCTRL_SC_LP_STAT_CLR_UNION;
#endif
#define SOC_SCTRL_SC_LP_STAT_CLR_deepsleeped_clr_START (0)
#define SOC_SCTRL_SC_LP_STAT_CLR_deepsleeped_clr_END (0)
#define SOC_SCTRL_SC_LP_STAT_CLR_lightsleeped_clr_START (1)
#define SOC_SCTRL_SC_LP_STAT_CLR_lightsleeped_clr_END (1)
#define SOC_SCTRL_SC_LP_STAT_CLR_standbyed_clr_START (2)
#define SOC_SCTRL_SC_LP_STAT_CLR_standbyed_clr_END (2)
#define SOC_SCTRL_SC_LP_STAT_CLR_doze1ed_clr_START (3)
#define SOC_SCTRL_SC_LP_STAT_CLR_doze1ed_clr_END (3)
#define SOC_SCTRL_SC_LP_STAT_CLR_doze2ed_clr_START (4)
#define SOC_SCTRL_SC_LP_STAT_CLR_doze2ed_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int system_stat_flag : 5;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int sc_lp_flag_msk : 16;
    } reg;
} SOC_SCTRL_SC_LP_FLAG_UNION;
#endif
#define SOC_SCTRL_SC_LP_FLAG_system_stat_flag_START (0)
#define SOC_SCTRL_SC_LP_FLAG_system_stat_flag_END (4)
#define SOC_SCTRL_SC_LP_FLAG_sc_lp_flag_msk_START (16)
#define SOC_SCTRL_SC_LP_FLAG_sc_lp_flag_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_wakeup_sctrl2m3_stat : 1;
        unsigned int intr_wakeup_sys_ff2 : 1;
        unsigned int intr_wakeup_sctrl2m3_en_at_suspend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_wakeup_sctrl2m3_clr_at_suspend : 1;
        unsigned int reserved_1 : 3;
        unsigned int intr_wakeup_sctrl2m3_en : 1;
        unsigned int reserved_2 : 22;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SCTRL_SC_INTR_WAKEUP_CTRL_UNION;
#endif
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_stat_START (0)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_stat_END (0)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sys_ff2_START (1)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sys_ff2_END (1)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_en_at_suspend_START (2)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_en_at_suspend_END (2)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_clr_at_suspend_START (4)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_clr_at_suspend_END (4)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_en_START (8)
#define SOC_SCTRL_SC_INTR_WAKEUP_CTRL_intr_wakeup_sctrl2m3_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCEFUSEDATA2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCEFUSEDATA3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCEFUSEDATA8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCEFUSEDATA9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SYS_STAT_LP_FLAG_POR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_stat_lp_flag_0_sec : 16;
        unsigned int sys_stat_lp_flag_0_sec_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_sys_stat_lp_flag_0_sec_START (0)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_sys_stat_lp_flag_0_sec_END (15)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_sys_stat_lp_flag_0_sec_msk_START (16)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_SEC_sys_stat_lp_flag_0_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_stat_lp_flag_1_sec : 16;
        unsigned int sys_stat_lp_flag_1_sec_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_sys_stat_lp_flag_1_sec_START (0)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_sys_stat_lp_flag_1_sec_END (15)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_sys_stat_lp_flag_1_sec_msk_START (16)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_SEC_sys_stat_lp_flag_1_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_stat_lp_flag_0_unsec : 16;
        unsigned int sys_stat_lp_flag_0_unsec_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_sys_stat_lp_flag_0_unsec_START (0)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_sys_stat_lp_flag_0_unsec_END (15)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_sys_stat_lp_flag_0_unsec_msk_START (16)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_0_UNSEC_sys_stat_lp_flag_0_unsec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_stat_lp_flag_1_unsec : 16;
        unsigned int sys_stat_lp_flag_1_unsec_msk : 16;
    } reg;
} SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_UNION;
#endif
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_sys_stat_lp_flag_1_unsec_START (0)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_sys_stat_lp_flag_1_unsec_END (15)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_sys_stat_lp_flag_1_unsec_msk_START (16)
#define SOC_SCTRL_SYS_STAT_LP_FLAG_1_UNSEC_sys_stat_lp_flag_1_unsec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_lp_data : 32;
    } reg;
} SOC_SCTRL_SC_LP_DATA_UNION;
#endif
#define SOC_SCTRL_SC_LP_DATA_sc_lp_data_START (0)
#define SOC_SCTRL_SC_LP_DATA_sc_lp_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lp_stat_cfg_s0 : 1;
        unsigned int lp_stat_cfg_s1 : 1;
        unsigned int lp_stat_cfg_s2 : 1;
        unsigned int lp_stat_cfg_s3 : 1;
        unsigned int lp_stat_cfg_s4 : 1;
        unsigned int reserved_0 : 26;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SCTRL_SCLPSTATCFG_UNION;
#endif
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s0_START (0)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s0_END (0)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s1_START (1)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s1_END (1)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s2_START (2)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s2_END (2)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s3_START (3)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s3_END (3)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s4_START (4)
#define SOC_SCTRL_SCLPSTATCFG_lp_stat_cfg_s4_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_asp_powerdn_msk : 1;
        unsigned int intr_asp_powerup_msk : 1;
        unsigned int vote_asp_powerupdn_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int asp_power_req_lpmcu : 2;
        unsigned int reserved_1 : 2;
        unsigned int asp_power_req_sft0 : 1;
        unsigned int asp_power_req_sft1 : 1;
        unsigned int asp_power_req_sft2 : 1;
        unsigned int asp_power_req_sft3 : 1;
        unsigned int reserved_2 : 4;
        unsigned int sc_asp_pwrcfg0_msk : 16;
    } reg;
} SOC_SCTRL_SC_ASP_PWRCFG0_UNION;
#endif
#define SOC_SCTRL_SC_ASP_PWRCFG0_intr_asp_powerdn_msk_START (0)
#define SOC_SCTRL_SC_ASP_PWRCFG0_intr_asp_powerdn_msk_END (0)
#define SOC_SCTRL_SC_ASP_PWRCFG0_intr_asp_powerup_msk_START (1)
#define SOC_SCTRL_SC_ASP_PWRCFG0_intr_asp_powerup_msk_END (1)
#define SOC_SCTRL_SC_ASP_PWRCFG0_vote_asp_powerupdn_bypass_START (2)
#define SOC_SCTRL_SC_ASP_PWRCFG0_vote_asp_powerupdn_bypass_END (2)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_lpmcu_START (4)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_lpmcu_END (5)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft0_START (8)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft0_END (8)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft1_START (9)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft1_END (9)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft2_START (10)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft2_END (10)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft3_START (11)
#define SOC_SCTRL_SC_ASP_PWRCFG0_asp_power_req_sft3_END (11)
#define SOC_SCTRL_SC_ASP_PWRCFG0_sc_asp_pwrcfg0_msk_START (16)
#define SOC_SCTRL_SC_ASP_PWRCFG0_sc_asp_pwrcfg0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_asp_powerdn_clr : 1;
        unsigned int intr_asp_powerup_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int intr_asp_powerdn_raw : 1;
        unsigned int intr_asp_powerup_raw : 1;
        unsigned int reserved_1 : 2;
        unsigned int intr_asp_powerdn : 1;
        unsigned int intr_asp_powerup : 1;
        unsigned int reserved_2 : 2;
        unsigned int asp_power_req_hifi_sync : 2;
        unsigned int reserved_3 : 2;
        unsigned int asp_power_req_hifi_stat : 2;
        unsigned int reserved_4 : 2;
        unsigned int asp_power_req_cpu_lit_sync : 2;
        unsigned int asp_power_req_cpu_hc_sync : 2;
        unsigned int asp_power_req : 1;
        unsigned int reserved_5 : 3;
        unsigned int curr_asp_power_stat : 2;
        unsigned int reserved_6 : 2;
    } reg;
} SOC_SCTRL_SC_ASP_PWRCFG1_UNION;
#endif
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerdn_clr_START (0)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerdn_clr_END (0)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerup_clr_START (1)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerup_clr_END (1)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerdn_raw_START (4)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerdn_raw_END (4)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerup_raw_START (5)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerup_raw_END (5)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerdn_START (8)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerdn_END (8)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerup_START (9)
#define SOC_SCTRL_SC_ASP_PWRCFG1_intr_asp_powerup_END (9)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_hifi_sync_START (12)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_hifi_sync_END (13)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_hifi_stat_START (16)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_hifi_stat_END (17)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_cpu_lit_sync_START (20)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_cpu_lit_sync_END (21)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_cpu_hc_sync_START (22)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_cpu_hc_sync_END (23)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_START (24)
#define SOC_SCTRL_SC_ASP_PWRCFG1_asp_power_req_END (24)
#define SOC_SCTRL_SC_ASP_PWRCFG1_curr_asp_power_stat_START (28)
#define SOC_SCTRL_SC_ASP_PWRCFG1_curr_asp_power_stat_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_wakeup_sys : 1;
        unsigned int int_ls2std_req : 1;
        unsigned int int_std2ls_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_SCTRL_SCINT_GATHER_STAT_UNION;
#endif
#define SOC_SCTRL_SCINT_GATHER_STAT_int_wakeup_sys_START (0)
#define SOC_SCTRL_SCINT_GATHER_STAT_int_wakeup_sys_END (0)
#define SOC_SCTRL_SCINT_GATHER_STAT_int_ls2std_req_START (1)
#define SOC_SCTRL_SCINT_GATHER_STAT_int_ls2std_req_END (1)
#define SOC_SCTRL_SCINT_GATHER_STAT_int_std2ls_req_START (2)
#define SOC_SCTRL_SCINT_GATHER_STAT_int_std2ls_req_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int intr_fer3_pmu_gic : 1;
        unsigned int intr_fer4_pmu_gic : 1;
        unsigned int intr_fer0_pmu_gic : 1;
        unsigned int intr_fer1_pmu_gic : 1;
        unsigned int intr_fer2_pmu_gic : 1;
        unsigned int rtc0_int : 1;
        unsigned int rtc1_int : 1;
        unsigned int timer00_int : 1;
        unsigned int timer01_int : 1;
        unsigned int timer10_int : 1;
        unsigned int timer11_int : 1;
        unsigned int timer20_int : 1;
        unsigned int timer21_int : 1;
        unsigned int timer30_int : 1;
        unsigned int timer31_int : 1;
        unsigned int timer40_int : 1;
        unsigned int timer41_int : 1;
        unsigned int timer50_int : 1;
        unsigned int timer51_int : 1;
        unsigned int timer60_int : 1;
        unsigned int timer61_int : 1;
        unsigned int timer70_int : 1;
        unsigned int timer71_int : 1;
        unsigned int timer80_int : 1;
        unsigned int timer81_int : 1;
        unsigned int intr_ipc_arm : 1;
        unsigned int intr_asp_watchdog : 1;
        unsigned int intr_iomcu_wdog : 1;
        unsigned int intr_iomcu_gpio_comb : 1;
        unsigned int intr_wakeup_iomcu : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SCTRL_SCINT_MASK_UNION;
#endif
#define SOC_SCTRL_SCINT_MASK_intr_fer3_pmu_gic_START (1)
#define SOC_SCTRL_SCINT_MASK_intr_fer3_pmu_gic_END (1)
#define SOC_SCTRL_SCINT_MASK_intr_fer4_pmu_gic_START (2)
#define SOC_SCTRL_SCINT_MASK_intr_fer4_pmu_gic_END (2)
#define SOC_SCTRL_SCINT_MASK_intr_fer0_pmu_gic_START (3)
#define SOC_SCTRL_SCINT_MASK_intr_fer0_pmu_gic_END (3)
#define SOC_SCTRL_SCINT_MASK_intr_fer1_pmu_gic_START (4)
#define SOC_SCTRL_SCINT_MASK_intr_fer1_pmu_gic_END (4)
#define SOC_SCTRL_SCINT_MASK_intr_fer2_pmu_gic_START (5)
#define SOC_SCTRL_SCINT_MASK_intr_fer2_pmu_gic_END (5)
#define SOC_SCTRL_SCINT_MASK_rtc0_int_START (6)
#define SOC_SCTRL_SCINT_MASK_rtc0_int_END (6)
#define SOC_SCTRL_SCINT_MASK_rtc1_int_START (7)
#define SOC_SCTRL_SCINT_MASK_rtc1_int_END (7)
#define SOC_SCTRL_SCINT_MASK_timer00_int_START (8)
#define SOC_SCTRL_SCINT_MASK_timer00_int_END (8)
#define SOC_SCTRL_SCINT_MASK_timer01_int_START (9)
#define SOC_SCTRL_SCINT_MASK_timer01_int_END (9)
#define SOC_SCTRL_SCINT_MASK_timer10_int_START (10)
#define SOC_SCTRL_SCINT_MASK_timer10_int_END (10)
#define SOC_SCTRL_SCINT_MASK_timer11_int_START (11)
#define SOC_SCTRL_SCINT_MASK_timer11_int_END (11)
#define SOC_SCTRL_SCINT_MASK_timer20_int_START (12)
#define SOC_SCTRL_SCINT_MASK_timer20_int_END (12)
#define SOC_SCTRL_SCINT_MASK_timer21_int_START (13)
#define SOC_SCTRL_SCINT_MASK_timer21_int_END (13)
#define SOC_SCTRL_SCINT_MASK_timer30_int_START (14)
#define SOC_SCTRL_SCINT_MASK_timer30_int_END (14)
#define SOC_SCTRL_SCINT_MASK_timer31_int_START (15)
#define SOC_SCTRL_SCINT_MASK_timer31_int_END (15)
#define SOC_SCTRL_SCINT_MASK_timer40_int_START (16)
#define SOC_SCTRL_SCINT_MASK_timer40_int_END (16)
#define SOC_SCTRL_SCINT_MASK_timer41_int_START (17)
#define SOC_SCTRL_SCINT_MASK_timer41_int_END (17)
#define SOC_SCTRL_SCINT_MASK_timer50_int_START (18)
#define SOC_SCTRL_SCINT_MASK_timer50_int_END (18)
#define SOC_SCTRL_SCINT_MASK_timer51_int_START (19)
#define SOC_SCTRL_SCINT_MASK_timer51_int_END (19)
#define SOC_SCTRL_SCINT_MASK_timer60_int_START (20)
#define SOC_SCTRL_SCINT_MASK_timer60_int_END (20)
#define SOC_SCTRL_SCINT_MASK_timer61_int_START (21)
#define SOC_SCTRL_SCINT_MASK_timer61_int_END (21)
#define SOC_SCTRL_SCINT_MASK_timer70_int_START (22)
#define SOC_SCTRL_SCINT_MASK_timer70_int_END (22)
#define SOC_SCTRL_SCINT_MASK_timer71_int_START (23)
#define SOC_SCTRL_SCINT_MASK_timer71_int_END (23)
#define SOC_SCTRL_SCINT_MASK_timer80_int_START (24)
#define SOC_SCTRL_SCINT_MASK_timer80_int_END (24)
#define SOC_SCTRL_SCINT_MASK_timer81_int_START (25)
#define SOC_SCTRL_SCINT_MASK_timer81_int_END (25)
#define SOC_SCTRL_SCINT_MASK_intr_ipc_arm_START (26)
#define SOC_SCTRL_SCINT_MASK_intr_ipc_arm_END (26)
#define SOC_SCTRL_SCINT_MASK_intr_asp_watchdog_START (27)
#define SOC_SCTRL_SCINT_MASK_intr_asp_watchdog_END (27)
#define SOC_SCTRL_SCINT_MASK_intr_iomcu_wdog_START (28)
#define SOC_SCTRL_SCINT_MASK_intr_iomcu_wdog_END (28)
#define SOC_SCTRL_SCINT_MASK_intr_iomcu_gpio_comb_START (29)
#define SOC_SCTRL_SCINT_MASK_intr_iomcu_gpio_comb_END (29)
#define SOC_SCTRL_SCINT_MASK_intr_wakeup_iomcu_START (30)
#define SOC_SCTRL_SCINT_MASK_intr_wakeup_iomcu_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int intr_fer3_pmu_gic : 1;
        unsigned int intr_fer4_pmu_gic : 1;
        unsigned int intr_fer0_pmu_gic : 1;
        unsigned int intr_fer1_pmu_gic : 1;
        unsigned int intr_fer2_pmu_gic : 1;
        unsigned int rtc0_int : 1;
        unsigned int rtc1_int : 1;
        unsigned int timer00_int : 1;
        unsigned int timer01_int : 1;
        unsigned int timer10_int : 1;
        unsigned int timer11_int : 1;
        unsigned int timer20_int : 1;
        unsigned int timer21_int : 1;
        unsigned int timer30_int : 1;
        unsigned int timer31_int : 1;
        unsigned int timer40_int : 1;
        unsigned int timer41_int : 1;
        unsigned int timer50_int : 1;
        unsigned int timer51_int : 1;
        unsigned int timer60_int : 1;
        unsigned int timer61_int : 1;
        unsigned int timer70_int : 1;
        unsigned int timer71_int : 1;
        unsigned int timer80_int : 1;
        unsigned int timer81_int : 1;
        unsigned int intr_ipc_arm : 1;
        unsigned int intr_asp_watchdog : 1;
        unsigned int intr_iomcu_wdog : 1;
        unsigned int intr_iomcu_gpio_comb : 1;
        unsigned int intr_wakeup_iomcu : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SCTRL_SCINT_STAT_UNION;
#endif
#define SOC_SCTRL_SCINT_STAT_intr_fer3_pmu_gic_START (1)
#define SOC_SCTRL_SCINT_STAT_intr_fer3_pmu_gic_END (1)
#define SOC_SCTRL_SCINT_STAT_intr_fer4_pmu_gic_START (2)
#define SOC_SCTRL_SCINT_STAT_intr_fer4_pmu_gic_END (2)
#define SOC_SCTRL_SCINT_STAT_intr_fer0_pmu_gic_START (3)
#define SOC_SCTRL_SCINT_STAT_intr_fer0_pmu_gic_END (3)
#define SOC_SCTRL_SCINT_STAT_intr_fer1_pmu_gic_START (4)
#define SOC_SCTRL_SCINT_STAT_intr_fer1_pmu_gic_END (4)
#define SOC_SCTRL_SCINT_STAT_intr_fer2_pmu_gic_START (5)
#define SOC_SCTRL_SCINT_STAT_intr_fer2_pmu_gic_END (5)
#define SOC_SCTRL_SCINT_STAT_rtc0_int_START (6)
#define SOC_SCTRL_SCINT_STAT_rtc0_int_END (6)
#define SOC_SCTRL_SCINT_STAT_rtc1_int_START (7)
#define SOC_SCTRL_SCINT_STAT_rtc1_int_END (7)
#define SOC_SCTRL_SCINT_STAT_timer00_int_START (8)
#define SOC_SCTRL_SCINT_STAT_timer00_int_END (8)
#define SOC_SCTRL_SCINT_STAT_timer01_int_START (9)
#define SOC_SCTRL_SCINT_STAT_timer01_int_END (9)
#define SOC_SCTRL_SCINT_STAT_timer10_int_START (10)
#define SOC_SCTRL_SCINT_STAT_timer10_int_END (10)
#define SOC_SCTRL_SCINT_STAT_timer11_int_START (11)
#define SOC_SCTRL_SCINT_STAT_timer11_int_END (11)
#define SOC_SCTRL_SCINT_STAT_timer20_int_START (12)
#define SOC_SCTRL_SCINT_STAT_timer20_int_END (12)
#define SOC_SCTRL_SCINT_STAT_timer21_int_START (13)
#define SOC_SCTRL_SCINT_STAT_timer21_int_END (13)
#define SOC_SCTRL_SCINT_STAT_timer30_int_START (14)
#define SOC_SCTRL_SCINT_STAT_timer30_int_END (14)
#define SOC_SCTRL_SCINT_STAT_timer31_int_START (15)
#define SOC_SCTRL_SCINT_STAT_timer31_int_END (15)
#define SOC_SCTRL_SCINT_STAT_timer40_int_START (16)
#define SOC_SCTRL_SCINT_STAT_timer40_int_END (16)
#define SOC_SCTRL_SCINT_STAT_timer41_int_START (17)
#define SOC_SCTRL_SCINT_STAT_timer41_int_END (17)
#define SOC_SCTRL_SCINT_STAT_timer50_int_START (18)
#define SOC_SCTRL_SCINT_STAT_timer50_int_END (18)
#define SOC_SCTRL_SCINT_STAT_timer51_int_START (19)
#define SOC_SCTRL_SCINT_STAT_timer51_int_END (19)
#define SOC_SCTRL_SCINT_STAT_timer60_int_START (20)
#define SOC_SCTRL_SCINT_STAT_timer60_int_END (20)
#define SOC_SCTRL_SCINT_STAT_timer61_int_START (21)
#define SOC_SCTRL_SCINT_STAT_timer61_int_END (21)
#define SOC_SCTRL_SCINT_STAT_timer70_int_START (22)
#define SOC_SCTRL_SCINT_STAT_timer70_int_END (22)
#define SOC_SCTRL_SCINT_STAT_timer71_int_START (23)
#define SOC_SCTRL_SCINT_STAT_timer71_int_END (23)
#define SOC_SCTRL_SCINT_STAT_timer80_int_START (24)
#define SOC_SCTRL_SCINT_STAT_timer80_int_END (24)
#define SOC_SCTRL_SCINT_STAT_timer81_int_START (25)
#define SOC_SCTRL_SCINT_STAT_timer81_int_END (25)
#define SOC_SCTRL_SCINT_STAT_intr_ipc_arm_START (26)
#define SOC_SCTRL_SCINT_STAT_intr_ipc_arm_END (26)
#define SOC_SCTRL_SCINT_STAT_intr_asp_watchdog_START (27)
#define SOC_SCTRL_SCINT_STAT_intr_asp_watchdog_END (27)
#define SOC_SCTRL_SCINT_STAT_intr_iomcu_wdog_START (28)
#define SOC_SCTRL_SCINT_STAT_intr_iomcu_wdog_END (28)
#define SOC_SCTRL_SCINT_STAT_intr_iomcu_gpio_comb_START (29)
#define SOC_SCTRL_SCINT_STAT_intr_iomcu_gpio_comb_END (29)
#define SOC_SCTRL_SCINT_STAT_intr_wakeup_iomcu_START (30)
#define SOC_SCTRL_SCINT_STAT_intr_wakeup_iomcu_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int drx0_int : 1;
        unsigned int drx1_int : 1;
        unsigned int drx2_int : 1;
        unsigned int drx3_int : 1;
        unsigned int drx4_int : 1;
        unsigned int reserved_0 : 1;
        unsigned int drx5_int : 1;
        unsigned int drx6_int : 1;
        unsigned int drx7_int : 1;
        unsigned int drx8_int : 1;
        unsigned int reserved_1 : 21;
        unsigned int intr_iomcu_gpio_comb : 1;
    } reg;
} SOC_SCTRL_SCDRX_INT_CFG_UNION;
#endif
#define SOC_SCTRL_SCDRX_INT_CFG_drx0_int_START (0)
#define SOC_SCTRL_SCDRX_INT_CFG_drx0_int_END (0)
#define SOC_SCTRL_SCDRX_INT_CFG_drx1_int_START (1)
#define SOC_SCTRL_SCDRX_INT_CFG_drx1_int_END (1)
#define SOC_SCTRL_SCDRX_INT_CFG_drx2_int_START (2)
#define SOC_SCTRL_SCDRX_INT_CFG_drx2_int_END (2)
#define SOC_SCTRL_SCDRX_INT_CFG_drx3_int_START (3)
#define SOC_SCTRL_SCDRX_INT_CFG_drx3_int_END (3)
#define SOC_SCTRL_SCDRX_INT_CFG_drx4_int_START (4)
#define SOC_SCTRL_SCDRX_INT_CFG_drx4_int_END (4)
#define SOC_SCTRL_SCDRX_INT_CFG_drx5_int_START (6)
#define SOC_SCTRL_SCDRX_INT_CFG_drx5_int_END (6)
#define SOC_SCTRL_SCDRX_INT_CFG_drx6_int_START (7)
#define SOC_SCTRL_SCDRX_INT_CFG_drx6_int_END (7)
#define SOC_SCTRL_SCDRX_INT_CFG_drx7_int_START (8)
#define SOC_SCTRL_SCDRX_INT_CFG_drx7_int_END (8)
#define SOC_SCTRL_SCDRX_INT_CFG_drx8_int_START (9)
#define SOC_SCTRL_SCDRX_INT_CFG_drx8_int_END (9)
#define SOC_SCTRL_SCDRX_INT_CFG_intr_iomcu_gpio_comb_START (31)
#define SOC_SCTRL_SCDRX_INT_CFG_intr_iomcu_gpio_comb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_wfi_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCTRL_SCLPMCUWFI_INT_UNION;
#endif
#define SOC_SCTRL_SCLPMCUWFI_INT_lpmcu_wfi_int_START (0)
#define SOC_SCTRL_SCLPMCUWFI_INT_lpmcu_wfi_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int intr_fer0_pmu_gic_spmi1 : 1;
        unsigned int intr_fer1_pmu_gic_spmi1 : 1;
        unsigned int intr_fer2_pmu_gic_spmi1 : 1;
        unsigned int intr_fer3_pmu_gic_spmi1 : 1;
        unsigned int intr_fer4_pmu_gic_spmi1 : 1;
        unsigned int intr_qic_probe_mspc : 1;
        unsigned int intr_qic_probe_iomcu : 1;
        unsigned int intr_qic_probe_asp : 1;
        unsigned int intr_qic_probe_ao : 1;
        unsigned int ao_ipc_mdm : 1;
        unsigned int ao_ipc_gic : 1;
        unsigned int ao_ipc_lpmcu : 1;
        unsigned int reserved_6 : 1;
        unsigned int ao_ipc_asp : 1;
        unsigned int reserved_7 : 1;
        unsigned int ao_ipc_iomcu : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int intr_sts_gpio_comb : 1;
        unsigned int intr_iodie_gpio_comb : 1;
        unsigned int ao_ioc : 1;
        unsigned int se_gpio1 : 1;
        unsigned int intr_iodie_gpio_se : 1;
        unsigned int intr_ao_wd : 1;
    } reg;
} SOC_SCTRL_SCINT_MASK1_UNION;
#endif
#define SOC_SCTRL_SCINT_MASK1_intr_fer0_pmu_gic_spmi1_START (6)
#define SOC_SCTRL_SCINT_MASK1_intr_fer0_pmu_gic_spmi1_END (6)
#define SOC_SCTRL_SCINT_MASK1_intr_fer1_pmu_gic_spmi1_START (7)
#define SOC_SCTRL_SCINT_MASK1_intr_fer1_pmu_gic_spmi1_END (7)
#define SOC_SCTRL_SCINT_MASK1_intr_fer2_pmu_gic_spmi1_START (8)
#define SOC_SCTRL_SCINT_MASK1_intr_fer2_pmu_gic_spmi1_END (8)
#define SOC_SCTRL_SCINT_MASK1_intr_fer3_pmu_gic_spmi1_START (9)
#define SOC_SCTRL_SCINT_MASK1_intr_fer3_pmu_gic_spmi1_END (9)
#define SOC_SCTRL_SCINT_MASK1_intr_fer4_pmu_gic_spmi1_START (10)
#define SOC_SCTRL_SCINT_MASK1_intr_fer4_pmu_gic_spmi1_END (10)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_mspc_START (11)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_mspc_END (11)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_iomcu_START (12)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_iomcu_END (12)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_asp_START (13)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_asp_END (13)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_ao_START (14)
#define SOC_SCTRL_SCINT_MASK1_intr_qic_probe_ao_END (14)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_mdm_START (15)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_mdm_END (15)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_gic_START (16)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_gic_END (16)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_lpmcu_START (17)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_lpmcu_END (17)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_asp_START (19)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_asp_END (19)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_iomcu_START (21)
#define SOC_SCTRL_SCINT_MASK1_ao_ipc_iomcu_END (21)
#define SOC_SCTRL_SCINT_MASK1_intr_sts_gpio_comb_START (26)
#define SOC_SCTRL_SCINT_MASK1_intr_sts_gpio_comb_END (26)
#define SOC_SCTRL_SCINT_MASK1_intr_iodie_gpio_comb_START (27)
#define SOC_SCTRL_SCINT_MASK1_intr_iodie_gpio_comb_END (27)
#define SOC_SCTRL_SCINT_MASK1_ao_ioc_START (28)
#define SOC_SCTRL_SCINT_MASK1_ao_ioc_END (28)
#define SOC_SCTRL_SCINT_MASK1_se_gpio1_START (29)
#define SOC_SCTRL_SCINT_MASK1_se_gpio1_END (29)
#define SOC_SCTRL_SCINT_MASK1_intr_iodie_gpio_se_START (30)
#define SOC_SCTRL_SCINT_MASK1_intr_iodie_gpio_se_END (30)
#define SOC_SCTRL_SCINT_MASK1_intr_ao_wd_START (31)
#define SOC_SCTRL_SCINT_MASK1_intr_ao_wd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int intr_fer0_pmu_gic_spmi1 : 1;
        unsigned int intr_fer1_pmu_gic_spmi1 : 1;
        unsigned int intr_fer2_pmu_gic_spmi1 : 1;
        unsigned int intr_fer3_pmu_gic_spmi1 : 1;
        unsigned int intr_fer4_pmu_gic_spmi1 : 1;
        unsigned int intr_qic_probe_mspc : 1;
        unsigned int intr_qic_probe_iomcu : 1;
        unsigned int intr_qic_probe_asp : 1;
        unsigned int intr_qic_probe_ao : 1;
        unsigned int ao_ipc_mdm : 1;
        unsigned int ao_ipc_gic : 1;
        unsigned int ao_ipc_lpmcu : 1;
        unsigned int reserved_6 : 1;
        unsigned int ao_ipc_asp : 1;
        unsigned int reserved_7 : 1;
        unsigned int ao_ipc_iomcu : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int intr_sts_gpio_comb : 1;
        unsigned int intr_iodie_gpio_comb : 1;
        unsigned int ao_ioc : 1;
        unsigned int se_gpio1 : 1;
        unsigned int intr_iodie_gpio_se : 1;
        unsigned int intr_ao_wd : 1;
    } reg;
} SOC_SCTRL_SCINT_STAT1_UNION;
#endif
#define SOC_SCTRL_SCINT_STAT1_intr_fer0_pmu_gic_spmi1_START (6)
#define SOC_SCTRL_SCINT_STAT1_intr_fer0_pmu_gic_spmi1_END (6)
#define SOC_SCTRL_SCINT_STAT1_intr_fer1_pmu_gic_spmi1_START (7)
#define SOC_SCTRL_SCINT_STAT1_intr_fer1_pmu_gic_spmi1_END (7)
#define SOC_SCTRL_SCINT_STAT1_intr_fer2_pmu_gic_spmi1_START (8)
#define SOC_SCTRL_SCINT_STAT1_intr_fer2_pmu_gic_spmi1_END (8)
#define SOC_SCTRL_SCINT_STAT1_intr_fer3_pmu_gic_spmi1_START (9)
#define SOC_SCTRL_SCINT_STAT1_intr_fer3_pmu_gic_spmi1_END (9)
#define SOC_SCTRL_SCINT_STAT1_intr_fer4_pmu_gic_spmi1_START (10)
#define SOC_SCTRL_SCINT_STAT1_intr_fer4_pmu_gic_spmi1_END (10)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_mspc_START (11)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_mspc_END (11)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_iomcu_START (12)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_iomcu_END (12)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_asp_START (13)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_asp_END (13)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_ao_START (14)
#define SOC_SCTRL_SCINT_STAT1_intr_qic_probe_ao_END (14)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_mdm_START (15)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_mdm_END (15)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_gic_START (16)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_gic_END (16)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_lpmcu_START (17)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_lpmcu_END (17)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_asp_START (19)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_asp_END (19)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_iomcu_START (21)
#define SOC_SCTRL_SCINT_STAT1_ao_ipc_iomcu_END (21)
#define SOC_SCTRL_SCINT_STAT1_intr_sts_gpio_comb_START (26)
#define SOC_SCTRL_SCINT_STAT1_intr_sts_gpio_comb_END (26)
#define SOC_SCTRL_SCINT_STAT1_intr_iodie_gpio_comb_START (27)
#define SOC_SCTRL_SCINT_STAT1_intr_iodie_gpio_comb_END (27)
#define SOC_SCTRL_SCINT_STAT1_ao_ioc_START (28)
#define SOC_SCTRL_SCINT_STAT1_ao_ioc_END (28)
#define SOC_SCTRL_SCINT_STAT1_se_gpio1_START (29)
#define SOC_SCTRL_SCINT_STAT1_se_gpio1_END (29)
#define SOC_SCTRL_SCINT_STAT1_intr_iodie_gpio_se_START (30)
#define SOC_SCTRL_SCINT_STAT1_intr_iodie_gpio_se_END (30)
#define SOC_SCTRL_SCINT_STAT1_intr_ao_wd_START (31)
#define SOC_SCTRL_SCINT_STAT1_intr_ao_wd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_irq_int0 : 1;
        unsigned int gic_irq_int1 : 1;
        unsigned int gic_irq_int2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_lpmcu_wdog : 1;
        unsigned int lpmcu_wfi_int : 1;
        unsigned int acpu_ppi_wakeup : 1;
        unsigned int intr_peri_gpio_wakeup : 5;
        unsigned int intr_ddrc_fatal_gic_lpmcu : 4;
        unsigned int reserved_1 : 14;
        unsigned int intr_ip_bus_mdm_idle_invalid : 1;
        unsigned int intr_doze_timeout_wakeup : 1;
    } reg;
} SOC_SCTRL_SCINT_MASK2_UNION;
#endif
#define SOC_SCTRL_SCINT_MASK2_gic_irq_int0_START (0)
#define SOC_SCTRL_SCINT_MASK2_gic_irq_int0_END (0)
#define SOC_SCTRL_SCINT_MASK2_gic_irq_int1_START (1)
#define SOC_SCTRL_SCINT_MASK2_gic_irq_int1_END (1)
#define SOC_SCTRL_SCINT_MASK2_gic_irq_int2_START (2)
#define SOC_SCTRL_SCINT_MASK2_gic_irq_int2_END (2)
#define SOC_SCTRL_SCINT_MASK2_intr_lpmcu_wdog_START (4)
#define SOC_SCTRL_SCINT_MASK2_intr_lpmcu_wdog_END (4)
#define SOC_SCTRL_SCINT_MASK2_lpmcu_wfi_int_START (5)
#define SOC_SCTRL_SCINT_MASK2_lpmcu_wfi_int_END (5)
#define SOC_SCTRL_SCINT_MASK2_acpu_ppi_wakeup_START (6)
#define SOC_SCTRL_SCINT_MASK2_acpu_ppi_wakeup_END (6)
#define SOC_SCTRL_SCINT_MASK2_intr_peri_gpio_wakeup_START (7)
#define SOC_SCTRL_SCINT_MASK2_intr_peri_gpio_wakeup_END (11)
#define SOC_SCTRL_SCINT_MASK2_intr_ddrc_fatal_gic_lpmcu_START (12)
#define SOC_SCTRL_SCINT_MASK2_intr_ddrc_fatal_gic_lpmcu_END (15)
#define SOC_SCTRL_SCINT_MASK2_intr_ip_bus_mdm_idle_invalid_START (30)
#define SOC_SCTRL_SCINT_MASK2_intr_ip_bus_mdm_idle_invalid_END (30)
#define SOC_SCTRL_SCINT_MASK2_intr_doze_timeout_wakeup_START (31)
#define SOC_SCTRL_SCINT_MASK2_intr_doze_timeout_wakeup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gic_irq_int0 : 1;
        unsigned int gic_irq_int1 : 1;
        unsigned int gic_irq_int2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_lpmcu_wdog : 1;
        unsigned int reserved_1 : 1;
        unsigned int acpu_ppi_wakeup : 1;
        unsigned int intr_peri_gpio_wakeup : 5;
        unsigned int intr_ddrc_fatal_gic_lpmcu : 4;
        unsigned int reserved_2 : 14;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_SCTRL_SCINT_STAT2_UNION;
#endif
#define SOC_SCTRL_SCINT_STAT2_gic_irq_int0_START (0)
#define SOC_SCTRL_SCINT_STAT2_gic_irq_int0_END (0)
#define SOC_SCTRL_SCINT_STAT2_gic_irq_int1_START (1)
#define SOC_SCTRL_SCINT_STAT2_gic_irq_int1_END (1)
#define SOC_SCTRL_SCINT_STAT2_gic_irq_int2_START (2)
#define SOC_SCTRL_SCINT_STAT2_gic_irq_int2_END (2)
#define SOC_SCTRL_SCINT_STAT2_intr_lpmcu_wdog_START (4)
#define SOC_SCTRL_SCINT_STAT2_intr_lpmcu_wdog_END (4)
#define SOC_SCTRL_SCINT_STAT2_acpu_ppi_wakeup_START (6)
#define SOC_SCTRL_SCINT_STAT2_acpu_ppi_wakeup_END (6)
#define SOC_SCTRL_SCINT_STAT2_intr_peri_gpio_wakeup_START (7)
#define SOC_SCTRL_SCINT_STAT2_intr_peri_gpio_wakeup_END (11)
#define SOC_SCTRL_SCINT_STAT2_intr_ddrc_fatal_gic_lpmcu_START (12)
#define SOC_SCTRL_SCINT_STAT2_intr_ddrc_fatal_gic_lpmcu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vad_int : 1;
        unsigned int mad_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SCTRL_SCINT_MASK3_UNION;
#endif
#define SOC_SCTRL_SCINT_MASK3_vad_int_START (0)
#define SOC_SCTRL_SCINT_MASK3_vad_int_END (0)
#define SOC_SCTRL_SCINT_MASK3_mad_int_START (1)
#define SOC_SCTRL_SCINT_MASK3_mad_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vad_int : 1;
        unsigned int mad_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SCTRL_SCINT_STAT3_UNION;
#endif
#define SOC_SCTRL_SCINT_STAT3_vad_int_START (0)
#define SOC_SCTRL_SCINT_STAT3_vad_int_END (0)
#define SOC_SCTRL_SCINT_STAT3_mad_int_START (1)
#define SOC_SCTRL_SCINT_STAT3_mad_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lte_drx_arm_wakeup_int : 1;
        unsigned int nrv_drx_arm_wakeup_int : 1;
        unsigned int g1_int_gbbp_to_cpu_on : 1;
        unsigned int g2_int_gbbp_to_cpu_on : 1;
        unsigned int w_cpu_int02 : 1;
        unsigned int intr_sdrx_wakeup : 1;
        unsigned int g3_int_gbbp_to_cpu_on : 1;
        unsigned int w_cpu_int02_2 : 1;
        unsigned int lte2_drx_arm_wakeup_int : 1;
        unsigned int ltev_drx_arm_wakeup_int : 1;
        unsigned int nr_drx_arm_wakeup_int : 1;
        unsigned int nr2_drx_arm_wakeup_int : 1;
        unsigned int scg_drx_arm_wakeup_int : 1;
        unsigned int tsp0_wakeup_intr : 1;
        unsigned int modem_doze1_wake : 1;
        unsigned int pdea_wakeup_intr_0 : 1;
        unsigned int pdea_wakeup_intr_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_SCTRL_SCINT_MASK4_UNION;
#endif
#define SOC_SCTRL_SCINT_MASK4_lte_drx_arm_wakeup_int_START (0)
#define SOC_SCTRL_SCINT_MASK4_lte_drx_arm_wakeup_int_END (0)
#define SOC_SCTRL_SCINT_MASK4_nrv_drx_arm_wakeup_int_START (1)
#define SOC_SCTRL_SCINT_MASK4_nrv_drx_arm_wakeup_int_END (1)
#define SOC_SCTRL_SCINT_MASK4_g1_int_gbbp_to_cpu_on_START (2)
#define SOC_SCTRL_SCINT_MASK4_g1_int_gbbp_to_cpu_on_END (2)
#define SOC_SCTRL_SCINT_MASK4_g2_int_gbbp_to_cpu_on_START (3)
#define SOC_SCTRL_SCINT_MASK4_g2_int_gbbp_to_cpu_on_END (3)
#define SOC_SCTRL_SCINT_MASK4_w_cpu_int02_START (4)
#define SOC_SCTRL_SCINT_MASK4_w_cpu_int02_END (4)
#define SOC_SCTRL_SCINT_MASK4_intr_sdrx_wakeup_START (5)
#define SOC_SCTRL_SCINT_MASK4_intr_sdrx_wakeup_END (5)
#define SOC_SCTRL_SCINT_MASK4_g3_int_gbbp_to_cpu_on_START (6)
#define SOC_SCTRL_SCINT_MASK4_g3_int_gbbp_to_cpu_on_END (6)
#define SOC_SCTRL_SCINT_MASK4_w_cpu_int02_2_START (7)
#define SOC_SCTRL_SCINT_MASK4_w_cpu_int02_2_END (7)
#define SOC_SCTRL_SCINT_MASK4_lte2_drx_arm_wakeup_int_START (8)
#define SOC_SCTRL_SCINT_MASK4_lte2_drx_arm_wakeup_int_END (8)
#define SOC_SCTRL_SCINT_MASK4_ltev_drx_arm_wakeup_int_START (9)
#define SOC_SCTRL_SCINT_MASK4_ltev_drx_arm_wakeup_int_END (9)
#define SOC_SCTRL_SCINT_MASK4_nr_drx_arm_wakeup_int_START (10)
#define SOC_SCTRL_SCINT_MASK4_nr_drx_arm_wakeup_int_END (10)
#define SOC_SCTRL_SCINT_MASK4_nr2_drx_arm_wakeup_int_START (11)
#define SOC_SCTRL_SCINT_MASK4_nr2_drx_arm_wakeup_int_END (11)
#define SOC_SCTRL_SCINT_MASK4_scg_drx_arm_wakeup_int_START (12)
#define SOC_SCTRL_SCINT_MASK4_scg_drx_arm_wakeup_int_END (12)
#define SOC_SCTRL_SCINT_MASK4_tsp0_wakeup_intr_START (13)
#define SOC_SCTRL_SCINT_MASK4_tsp0_wakeup_intr_END (13)
#define SOC_SCTRL_SCINT_MASK4_modem_doze1_wake_START (14)
#define SOC_SCTRL_SCINT_MASK4_modem_doze1_wake_END (14)
#define SOC_SCTRL_SCINT_MASK4_pdea_wakeup_intr_0_START (15)
#define SOC_SCTRL_SCINT_MASK4_pdea_wakeup_intr_0_END (15)
#define SOC_SCTRL_SCINT_MASK4_pdea_wakeup_intr_1_START (16)
#define SOC_SCTRL_SCINT_MASK4_pdea_wakeup_intr_1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lte_drx_arm_wakeup_int : 1;
        unsigned int nrv_drx_arm_wakeup_int : 1;
        unsigned int g1_int_gbbp_to_cpu_on : 1;
        unsigned int g2_int_gbbp_to_cpu_on : 1;
        unsigned int w_cpu_int02 : 1;
        unsigned int intr_sdrx_wakeup : 1;
        unsigned int g3_int_gbbp_to_cpu_on : 1;
        unsigned int w_cpu_int02_2 : 1;
        unsigned int lte2_drx_arm_wakeup_int : 1;
        unsigned int ltev_drx_arm_wakeup_int : 1;
        unsigned int nr_drx_arm_wakeup_int : 1;
        unsigned int nr2_drx_arm_wakeup_int : 1;
        unsigned int scg_drx_arm_wakeup_int : 1;
        unsigned int tsp0_wakeup_intr : 1;
        unsigned int modem_doze1_wake : 1;
        unsigned int pdea_wakeup_intr_0 : 1;
        unsigned int pdea_wakeup_intr_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_SCTRL_SCINT_STAT4_UNION;
#endif
#define SOC_SCTRL_SCINT_STAT4_lte_drx_arm_wakeup_int_START (0)
#define SOC_SCTRL_SCINT_STAT4_lte_drx_arm_wakeup_int_END (0)
#define SOC_SCTRL_SCINT_STAT4_nrv_drx_arm_wakeup_int_START (1)
#define SOC_SCTRL_SCINT_STAT4_nrv_drx_arm_wakeup_int_END (1)
#define SOC_SCTRL_SCINT_STAT4_g1_int_gbbp_to_cpu_on_START (2)
#define SOC_SCTRL_SCINT_STAT4_g1_int_gbbp_to_cpu_on_END (2)
#define SOC_SCTRL_SCINT_STAT4_g2_int_gbbp_to_cpu_on_START (3)
#define SOC_SCTRL_SCINT_STAT4_g2_int_gbbp_to_cpu_on_END (3)
#define SOC_SCTRL_SCINT_STAT4_w_cpu_int02_START (4)
#define SOC_SCTRL_SCINT_STAT4_w_cpu_int02_END (4)
#define SOC_SCTRL_SCINT_STAT4_intr_sdrx_wakeup_START (5)
#define SOC_SCTRL_SCINT_STAT4_intr_sdrx_wakeup_END (5)
#define SOC_SCTRL_SCINT_STAT4_g3_int_gbbp_to_cpu_on_START (6)
#define SOC_SCTRL_SCINT_STAT4_g3_int_gbbp_to_cpu_on_END (6)
#define SOC_SCTRL_SCINT_STAT4_w_cpu_int02_2_START (7)
#define SOC_SCTRL_SCINT_STAT4_w_cpu_int02_2_END (7)
#define SOC_SCTRL_SCINT_STAT4_lte2_drx_arm_wakeup_int_START (8)
#define SOC_SCTRL_SCINT_STAT4_lte2_drx_arm_wakeup_int_END (8)
#define SOC_SCTRL_SCINT_STAT4_ltev_drx_arm_wakeup_int_START (9)
#define SOC_SCTRL_SCINT_STAT4_ltev_drx_arm_wakeup_int_END (9)
#define SOC_SCTRL_SCINT_STAT4_nr_drx_arm_wakeup_int_START (10)
#define SOC_SCTRL_SCINT_STAT4_nr_drx_arm_wakeup_int_END (10)
#define SOC_SCTRL_SCINT_STAT4_nr2_drx_arm_wakeup_int_START (11)
#define SOC_SCTRL_SCINT_STAT4_nr2_drx_arm_wakeup_int_END (11)
#define SOC_SCTRL_SCINT_STAT4_scg_drx_arm_wakeup_int_START (12)
#define SOC_SCTRL_SCINT_STAT4_scg_drx_arm_wakeup_int_END (12)
#define SOC_SCTRL_SCINT_STAT4_tsp0_wakeup_intr_START (13)
#define SOC_SCTRL_SCINT_STAT4_tsp0_wakeup_intr_END (13)
#define SOC_SCTRL_SCINT_STAT4_modem_doze1_wake_START (14)
#define SOC_SCTRL_SCINT_STAT4_modem_doze1_wake_END (14)
#define SOC_SCTRL_SCINT_STAT4_pdea_wakeup_intr_0_START (15)
#define SOC_SCTRL_SCINT_STAT4_pdea_wakeup_intr_0_END (15)
#define SOC_SCTRL_SCINT_STAT4_pdea_wakeup_intr_1_START (16)
#define SOC_SCTRL_SCINT_STAT4_pdea_wakeup_intr_1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_timer130 : 1;
        unsigned int intr_timer131 : 1;
        unsigned int intr_timer140 : 1;
        unsigned int intr_timer141 : 1;
        unsigned int intr_timer150 : 1;
        unsigned int intr_timer151 : 1;
        unsigned int intr_timer160 : 1;
        unsigned int intr_timer161 : 1;
        unsigned int intr_timer170 : 1;
        unsigned int intr_timer171 : 1;
        unsigned int intr_pcie0_0_l12_wake_gic_lpmcu : 1;
        unsigned int intr_ao_wd1 : 1;
        unsigned int intr_wakeup_swing_enter_req : 1;
        unsigned int intr_wakeup_swing_exit_req : 1;
        unsigned int intr_lfc_mode_quit_to_sctrl_and_lpmcu : 1;
        unsigned int intr_usb3_sys_error_to_ao_wakeup : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_m7_ahb_dbg_timeout_lpmcu : 1;
        unsigned int intr_pcie0_1_l12_wake_gic_lpmcu : 1;
        unsigned int intr_pcie0_0_l2_wake_gic_lpmcu : 1;
        unsigned int intr_pcie0_1_l2_wake_gic_lpmcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int dss_doze1_wake : 1;
        unsigned int dss_doze1_wd_wake : 1;
        unsigned int freq_abnormal_int_0 : 1;
        unsigned int mdm_pll_unlock_intr_lpmcu : 1;
        unsigned int mdm_wdt_intr_merge_acpu_lpmcu : 1;
        unsigned int pdea_wdt_int : 1;
        unsigned int modem_bus_err : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_SCTRL_SCINT_MASK5_UNION;
#endif
#define SOC_SCTRL_SCINT_MASK5_intr_timer130_START (0)
#define SOC_SCTRL_SCINT_MASK5_intr_timer130_END (0)
#define SOC_SCTRL_SCINT_MASK5_intr_timer131_START (1)
#define SOC_SCTRL_SCINT_MASK5_intr_timer131_END (1)
#define SOC_SCTRL_SCINT_MASK5_intr_timer140_START (2)
#define SOC_SCTRL_SCINT_MASK5_intr_timer140_END (2)
#define SOC_SCTRL_SCINT_MASK5_intr_timer141_START (3)
#define SOC_SCTRL_SCINT_MASK5_intr_timer141_END (3)
#define SOC_SCTRL_SCINT_MASK5_intr_timer150_START (4)
#define SOC_SCTRL_SCINT_MASK5_intr_timer150_END (4)
#define SOC_SCTRL_SCINT_MASK5_intr_timer151_START (5)
#define SOC_SCTRL_SCINT_MASK5_intr_timer151_END (5)
#define SOC_SCTRL_SCINT_MASK5_intr_timer160_START (6)
#define SOC_SCTRL_SCINT_MASK5_intr_timer160_END (6)
#define SOC_SCTRL_SCINT_MASK5_intr_timer161_START (7)
#define SOC_SCTRL_SCINT_MASK5_intr_timer161_END (7)
#define SOC_SCTRL_SCINT_MASK5_intr_timer170_START (8)
#define SOC_SCTRL_SCINT_MASK5_intr_timer170_END (8)
#define SOC_SCTRL_SCINT_MASK5_intr_timer171_START (9)
#define SOC_SCTRL_SCINT_MASK5_intr_timer171_END (9)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_0_l12_wake_gic_lpmcu_START (10)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_0_l12_wake_gic_lpmcu_END (10)
#define SOC_SCTRL_SCINT_MASK5_intr_ao_wd1_START (11)
#define SOC_SCTRL_SCINT_MASK5_intr_ao_wd1_END (11)
#define SOC_SCTRL_SCINT_MASK5_intr_wakeup_swing_enter_req_START (12)
#define SOC_SCTRL_SCINT_MASK5_intr_wakeup_swing_enter_req_END (12)
#define SOC_SCTRL_SCINT_MASK5_intr_wakeup_swing_exit_req_START (13)
#define SOC_SCTRL_SCINT_MASK5_intr_wakeup_swing_exit_req_END (13)
#define SOC_SCTRL_SCINT_MASK5_intr_lfc_mode_quit_to_sctrl_and_lpmcu_START (14)
#define SOC_SCTRL_SCINT_MASK5_intr_lfc_mode_quit_to_sctrl_and_lpmcu_END (14)
#define SOC_SCTRL_SCINT_MASK5_intr_usb3_sys_error_to_ao_wakeup_START (15)
#define SOC_SCTRL_SCINT_MASK5_intr_usb3_sys_error_to_ao_wakeup_END (15)
#define SOC_SCTRL_SCINT_MASK5_intr_m7_ahb_dbg_timeout_lpmcu_START (17)
#define SOC_SCTRL_SCINT_MASK5_intr_m7_ahb_dbg_timeout_lpmcu_END (17)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_1_l12_wake_gic_lpmcu_START (18)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_1_l12_wake_gic_lpmcu_END (18)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_0_l2_wake_gic_lpmcu_START (19)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_0_l2_wake_gic_lpmcu_END (19)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_1_l2_wake_gic_lpmcu_START (20)
#define SOC_SCTRL_SCINT_MASK5_intr_pcie0_1_l2_wake_gic_lpmcu_END (20)
#define SOC_SCTRL_SCINT_MASK5_dss_doze1_wake_START (22)
#define SOC_SCTRL_SCINT_MASK5_dss_doze1_wake_END (22)
#define SOC_SCTRL_SCINT_MASK5_dss_doze1_wd_wake_START (23)
#define SOC_SCTRL_SCINT_MASK5_dss_doze1_wd_wake_END (23)
#define SOC_SCTRL_SCINT_MASK5_freq_abnormal_int_0_START (24)
#define SOC_SCTRL_SCINT_MASK5_freq_abnormal_int_0_END (24)
#define SOC_SCTRL_SCINT_MASK5_mdm_pll_unlock_intr_lpmcu_START (25)
#define SOC_SCTRL_SCINT_MASK5_mdm_pll_unlock_intr_lpmcu_END (25)
#define SOC_SCTRL_SCINT_MASK5_mdm_wdt_intr_merge_acpu_lpmcu_START (26)
#define SOC_SCTRL_SCINT_MASK5_mdm_wdt_intr_merge_acpu_lpmcu_END (26)
#define SOC_SCTRL_SCINT_MASK5_pdea_wdt_int_START (27)
#define SOC_SCTRL_SCINT_MASK5_pdea_wdt_int_END (27)
#define SOC_SCTRL_SCINT_MASK5_modem_bus_err_START (28)
#define SOC_SCTRL_SCINT_MASK5_modem_bus_err_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_timer130 : 1;
        unsigned int intr_timer131 : 1;
        unsigned int intr_timer140 : 1;
        unsigned int intr_timer141 : 1;
        unsigned int intr_timer150 : 1;
        unsigned int intr_timer151 : 1;
        unsigned int intr_timer160 : 1;
        unsigned int intr_timer161 : 1;
        unsigned int intr_timer170 : 1;
        unsigned int intr_timer171 : 1;
        unsigned int intr_pcie0_0_l12_wake_gic_lpmcu : 1;
        unsigned int intr_ao_wd1 : 1;
        unsigned int intr_wakeup_swing_enter_req : 1;
        unsigned int intr_wakeup_swing_exit_req : 1;
        unsigned int intr_lfc_mode_quit_to_sctrl_and_lpmcu : 1;
        unsigned int intr_usb3_sys_error_to_ao_wakeup : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_m7_ahb_dbg_timeout_lpmcu : 1;
        unsigned int intr_pcie0_1_l12_wake_gic_lpmcu : 1;
        unsigned int intr_pcie0_0_l2_wake_gic_lpmcu : 1;
        unsigned int intr_pcie0_1_l2_wake_gic_lpmcu : 1;
        unsigned int reserved_1 : 1;
        unsigned int dss_doze1_wake : 1;
        unsigned int dss_doze1_wd_wake : 1;
        unsigned int freq_abnormal_int_0 : 1;
        unsigned int mdm_pll_unlock_intr_lpmcu : 1;
        unsigned int mdm_wdt_intr_merge_acpu_lpmcu : 1;
        unsigned int pdea_wdt_int : 1;
        unsigned int modem_bus_err : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_SCTRL_SCINT_STAT5_UNION;
#endif
#define SOC_SCTRL_SCINT_STAT5_intr_timer130_START (0)
#define SOC_SCTRL_SCINT_STAT5_intr_timer130_END (0)
#define SOC_SCTRL_SCINT_STAT5_intr_timer131_START (1)
#define SOC_SCTRL_SCINT_STAT5_intr_timer131_END (1)
#define SOC_SCTRL_SCINT_STAT5_intr_timer140_START (2)
#define SOC_SCTRL_SCINT_STAT5_intr_timer140_END (2)
#define SOC_SCTRL_SCINT_STAT5_intr_timer141_START (3)
#define SOC_SCTRL_SCINT_STAT5_intr_timer141_END (3)
#define SOC_SCTRL_SCINT_STAT5_intr_timer150_START (4)
#define SOC_SCTRL_SCINT_STAT5_intr_timer150_END (4)
#define SOC_SCTRL_SCINT_STAT5_intr_timer151_START (5)
#define SOC_SCTRL_SCINT_STAT5_intr_timer151_END (5)
#define SOC_SCTRL_SCINT_STAT5_intr_timer160_START (6)
#define SOC_SCTRL_SCINT_STAT5_intr_timer160_END (6)
#define SOC_SCTRL_SCINT_STAT5_intr_timer161_START (7)
#define SOC_SCTRL_SCINT_STAT5_intr_timer161_END (7)
#define SOC_SCTRL_SCINT_STAT5_intr_timer170_START (8)
#define SOC_SCTRL_SCINT_STAT5_intr_timer170_END (8)
#define SOC_SCTRL_SCINT_STAT5_intr_timer171_START (9)
#define SOC_SCTRL_SCINT_STAT5_intr_timer171_END (9)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_0_l12_wake_gic_lpmcu_START (10)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_0_l12_wake_gic_lpmcu_END (10)
#define SOC_SCTRL_SCINT_STAT5_intr_ao_wd1_START (11)
#define SOC_SCTRL_SCINT_STAT5_intr_ao_wd1_END (11)
#define SOC_SCTRL_SCINT_STAT5_intr_wakeup_swing_enter_req_START (12)
#define SOC_SCTRL_SCINT_STAT5_intr_wakeup_swing_enter_req_END (12)
#define SOC_SCTRL_SCINT_STAT5_intr_wakeup_swing_exit_req_START (13)
#define SOC_SCTRL_SCINT_STAT5_intr_wakeup_swing_exit_req_END (13)
#define SOC_SCTRL_SCINT_STAT5_intr_lfc_mode_quit_to_sctrl_and_lpmcu_START (14)
#define SOC_SCTRL_SCINT_STAT5_intr_lfc_mode_quit_to_sctrl_and_lpmcu_END (14)
#define SOC_SCTRL_SCINT_STAT5_intr_usb3_sys_error_to_ao_wakeup_START (15)
#define SOC_SCTRL_SCINT_STAT5_intr_usb3_sys_error_to_ao_wakeup_END (15)
#define SOC_SCTRL_SCINT_STAT5_intr_m7_ahb_dbg_timeout_lpmcu_START (17)
#define SOC_SCTRL_SCINT_STAT5_intr_m7_ahb_dbg_timeout_lpmcu_END (17)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_1_l12_wake_gic_lpmcu_START (18)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_1_l12_wake_gic_lpmcu_END (18)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_0_l2_wake_gic_lpmcu_START (19)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_0_l2_wake_gic_lpmcu_END (19)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_1_l2_wake_gic_lpmcu_START (20)
#define SOC_SCTRL_SCINT_STAT5_intr_pcie0_1_l2_wake_gic_lpmcu_END (20)
#define SOC_SCTRL_SCINT_STAT5_dss_doze1_wake_START (22)
#define SOC_SCTRL_SCINT_STAT5_dss_doze1_wake_END (22)
#define SOC_SCTRL_SCINT_STAT5_dss_doze1_wd_wake_START (23)
#define SOC_SCTRL_SCINT_STAT5_dss_doze1_wd_wake_END (23)
#define SOC_SCTRL_SCINT_STAT5_freq_abnormal_int_0_START (24)
#define SOC_SCTRL_SCINT_STAT5_freq_abnormal_int_0_END (24)
#define SOC_SCTRL_SCINT_STAT5_mdm_pll_unlock_intr_lpmcu_START (25)
#define SOC_SCTRL_SCINT_STAT5_mdm_pll_unlock_intr_lpmcu_END (25)
#define SOC_SCTRL_SCINT_STAT5_mdm_wdt_intr_merge_acpu_lpmcu_START (26)
#define SOC_SCTRL_SCINT_STAT5_mdm_wdt_intr_merge_acpu_lpmcu_END (26)
#define SOC_SCTRL_SCINT_STAT5_pdea_wdt_int_START (27)
#define SOC_SCTRL_SCINT_STAT5_pdea_wdt_int_END (27)
#define SOC_SCTRL_SCINT_STAT5_modem_bus_err_START (28)
#define SOC_SCTRL_SCINT_STAT5_modem_bus_err_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_wakeup_swing_exit_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 19;
    } reg;
} SOC_SCTRL_SCINT_INT_STD2LS_MASK_UNION;
#endif
#define SOC_SCTRL_SCINT_INT_STD2LS_MASK_intr_wakeup_swing_exit_req_START (0)
#define SOC_SCTRL_SCINT_INT_STD2LS_MASK_intr_wakeup_swing_exit_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_wakeup_swing_enter_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 19;
    } reg;
} SOC_SCTRL_SCINT_INT_LS2STD_MASK_UNION;
#endif
#define SOC_SCTRL_SCINT_INT_LS2STD_MASK_intr_wakeup_swing_enter_req_START (0)
#define SOC_SCTRL_SCINT_INT_LS2STD_MASK_intr_wakeup_swing_enter_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_efusec_mem_ctrl : 26;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_SCTRL_SCPERCTRL0_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL0_sc_efusec_mem_ctrl_START (0)
#define SOC_SCTRL_SCPERCTRL0_sc_efusec_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERCTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int txp_jtag_bypass : 1;
        unsigned int reserved_3 : 5;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 4;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 6;
    } reg;
} SOC_SCTRL_SCPERCTRL2_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL2_txp_jtag_bypass_START (10)
#define SOC_SCTRL_SCPERCTRL2_txp_jtag_bypass_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int efusec2_timeout_bypass : 1;
        unsigned int cfg_byp_ulppll_dis_en : 1;
        unsigned int cfg_byp_fll_clk_off_pls : 1;
        unsigned int cfg_byp_fll_32k_sw : 1;
        unsigned int intr_qic_comb_doze_mask_bypass : 1;
        unsigned int intr_bus_timeout_doze_mask_bypass : 1;
        unsigned int reserved_0 : 2;
        unsigned int efusec_timeout_bypass : 1;
        unsigned int bbdrx_timeout_bypass : 1;
        unsigned int sleep_mode_cfgbus_bypass : 1;
        unsigned int sleep_mode_lpmcu_bypass : 1;
        unsigned int first_power_on_flag : 1;
        unsigned int sleep_mode_aobus_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int scperctrl3_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL3_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL3_efusec2_timeout_bypass_START (0)
#define SOC_SCTRL_SCPERCTRL3_efusec2_timeout_bypass_END (0)
#define SOC_SCTRL_SCPERCTRL3_cfg_byp_ulppll_dis_en_START (1)
#define SOC_SCTRL_SCPERCTRL3_cfg_byp_ulppll_dis_en_END (1)
#define SOC_SCTRL_SCPERCTRL3_cfg_byp_fll_clk_off_pls_START (2)
#define SOC_SCTRL_SCPERCTRL3_cfg_byp_fll_clk_off_pls_END (2)
#define SOC_SCTRL_SCPERCTRL3_cfg_byp_fll_32k_sw_START (3)
#define SOC_SCTRL_SCPERCTRL3_cfg_byp_fll_32k_sw_END (3)
#define SOC_SCTRL_SCPERCTRL3_intr_qic_comb_doze_mask_bypass_START (4)
#define SOC_SCTRL_SCPERCTRL3_intr_qic_comb_doze_mask_bypass_END (4)
#define SOC_SCTRL_SCPERCTRL3_intr_bus_timeout_doze_mask_bypass_START (5)
#define SOC_SCTRL_SCPERCTRL3_intr_bus_timeout_doze_mask_bypass_END (5)
#define SOC_SCTRL_SCPERCTRL3_efusec_timeout_bypass_START (8)
#define SOC_SCTRL_SCPERCTRL3_efusec_timeout_bypass_END (8)
#define SOC_SCTRL_SCPERCTRL3_bbdrx_timeout_bypass_START (9)
#define SOC_SCTRL_SCPERCTRL3_bbdrx_timeout_bypass_END (9)
#define SOC_SCTRL_SCPERCTRL3_sleep_mode_cfgbus_bypass_START (10)
#define SOC_SCTRL_SCPERCTRL3_sleep_mode_cfgbus_bypass_END (10)
#define SOC_SCTRL_SCPERCTRL3_sleep_mode_lpmcu_bypass_START (11)
#define SOC_SCTRL_SCPERCTRL3_sleep_mode_lpmcu_bypass_END (11)
#define SOC_SCTRL_SCPERCTRL3_first_power_on_flag_START (12)
#define SOC_SCTRL_SCPERCTRL3_first_power_on_flag_END (12)
#define SOC_SCTRL_SCPERCTRL3_sleep_mode_aobus_bypass_START (13)
#define SOC_SCTRL_SCPERCTRL3_sleep_mode_aobus_bypass_END (13)
#define SOC_SCTRL_SCPERCTRL3_scperctrl3_msk_START (16)
#define SOC_SCTRL_SCPERCTRL3_scperctrl3_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_cha_test_ctrl : 1;
        unsigned int ddr_chb_test_ctrl : 1;
        unsigned int ddr_chc_test_ctrl : 1;
        unsigned int ddr_chd_test_ctrl : 1;
        unsigned int xo_mode_a2d : 1;
        unsigned int reserved_0 : 3;
        unsigned int crc_value : 21;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SCTRL_SCPERCTRL4_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL4_ddr_cha_test_ctrl_START (0)
#define SOC_SCTRL_SCPERCTRL4_ddr_cha_test_ctrl_END (0)
#define SOC_SCTRL_SCPERCTRL4_ddr_chb_test_ctrl_START (1)
#define SOC_SCTRL_SCPERCTRL4_ddr_chb_test_ctrl_END (1)
#define SOC_SCTRL_SCPERCTRL4_ddr_chc_test_ctrl_START (2)
#define SOC_SCTRL_SCPERCTRL4_ddr_chc_test_ctrl_END (2)
#define SOC_SCTRL_SCPERCTRL4_ddr_chd_test_ctrl_START (3)
#define SOC_SCTRL_SCPERCTRL4_ddr_chd_test_ctrl_END (3)
#define SOC_SCTRL_SCPERCTRL4_xo_mode_a2d_START (4)
#define SOC_SCTRL_SCPERCTRL4_xo_mode_a2d_END (4)
#define SOC_SCTRL_SCPERCTRL4_crc_value_START (8)
#define SOC_SCTRL_SCPERCTRL4_crc_value_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int ao_hpm_clk_div : 7;
        unsigned int ao_hpm_en : 1;
        unsigned int ao_hpmx_en : 1;
        unsigned int ao_hpmx_opc_min_en : 1;
        unsigned int ao_hpm_opc_min_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int scperctrl5_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL5_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL5_ao_hpm_clk_div_START (3)
#define SOC_SCTRL_SCPERCTRL5_ao_hpm_clk_div_END (9)
#define SOC_SCTRL_SCPERCTRL5_ao_hpm_en_START (10)
#define SOC_SCTRL_SCPERCTRL5_ao_hpm_en_END (10)
#define SOC_SCTRL_SCPERCTRL5_ao_hpmx_en_START (11)
#define SOC_SCTRL_SCPERCTRL5_ao_hpmx_en_END (11)
#define SOC_SCTRL_SCPERCTRL5_ao_hpmx_opc_min_en_START (12)
#define SOC_SCTRL_SCPERCTRL5_ao_hpmx_opc_min_en_END (12)
#define SOC_SCTRL_SCPERCTRL5_ao_hpm_opc_min_en_START (13)
#define SOC_SCTRL_SCPERCTRL5_ao_hpm_opc_min_en_END (13)
#define SOC_SCTRL_SCPERCTRL5_scperctrl5_msk_START (16)
#define SOC_SCTRL_SCPERCTRL5_scperctrl5_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_fix_io_ret : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int peri_bootio_ret : 1;
        unsigned int peri_bootio_ret_mode : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 7;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 8;
    } reg;
} SOC_SCTRL_SCPERCTRL6_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL6_peri_fix_io_ret_START (0)
#define SOC_SCTRL_SCPERCTRL6_peri_fix_io_ret_END (0)
#define SOC_SCTRL_SCPERCTRL6_peri_bootio_ret_START (4)
#define SOC_SCTRL_SCPERCTRL6_peri_bootio_ret_END (4)
#define SOC_SCTRL_SCPERCTRL6_peri_bootio_ret_mode_START (5)
#define SOC_SCTRL_SCPERCTRL6_peri_bootio_ret_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sctrl2lm_hard_volt : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int sel_suspend_ao2syscache : 1;
        unsigned int reserved_7 : 1;
        unsigned int sleep_mode_to_peri_bypass : 1;
        unsigned int sleep_mode_to_hsdt_bypass : 1;
        unsigned int sleep_mode_to_cpu_crg_bypass : 1;
        unsigned int peri_nonbootio_ret_mode : 1;
        unsigned int sc_peri_nonboot_io_ret : 1;
        unsigned int pmu_powerhold_protect : 1;
        unsigned int scperctrl7_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL7_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL7_sctrl2lm_hard_volt_START (0)
#define SOC_SCTRL_SCPERCTRL7_sctrl2lm_hard_volt_END (0)
#define SOC_SCTRL_SCPERCTRL7_sel_suspend_ao2syscache_START (8)
#define SOC_SCTRL_SCPERCTRL7_sel_suspend_ao2syscache_END (8)
#define SOC_SCTRL_SCPERCTRL7_sleep_mode_to_peri_bypass_START (10)
#define SOC_SCTRL_SCPERCTRL7_sleep_mode_to_peri_bypass_END (10)
#define SOC_SCTRL_SCPERCTRL7_sleep_mode_to_hsdt_bypass_START (11)
#define SOC_SCTRL_SCPERCTRL7_sleep_mode_to_hsdt_bypass_END (11)
#define SOC_SCTRL_SCPERCTRL7_sleep_mode_to_cpu_crg_bypass_START (12)
#define SOC_SCTRL_SCPERCTRL7_sleep_mode_to_cpu_crg_bypass_END (12)
#define SOC_SCTRL_SCPERCTRL7_peri_nonbootio_ret_mode_START (13)
#define SOC_SCTRL_SCPERCTRL7_peri_nonbootio_ret_mode_END (13)
#define SOC_SCTRL_SCPERCTRL7_sc_peri_nonboot_io_ret_START (14)
#define SOC_SCTRL_SCPERCTRL7_sc_peri_nonboot_io_ret_END (14)
#define SOC_SCTRL_SCPERCTRL7_pmu_powerhold_protect_START (15)
#define SOC_SCTRL_SCPERCTRL7_pmu_powerhold_protect_END (15)
#define SOC_SCTRL_SCPERCTRL7_scperctrl7_msk_START (16)
#define SOC_SCTRL_SCPERCTRL7_scperctrl7_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_apb_bbp_on : 1;
        unsigned int rst_19m_bbp_on : 1;
        unsigned int rst_32k_bbp_on : 1;
        unsigned int reserved_0 : 1;
        unsigned int rst_bbp_dbg_timer : 1;
        unsigned int rst_bbp_guc_timer : 1;
        unsigned int reserved_1 : 1;
        unsigned int bbp_on_ctrl : 25;
    } reg;
} SOC_SCTRL_SCPERCTRL9_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL9_rst_apb_bbp_on_START (0)
#define SOC_SCTRL_SCPERCTRL9_rst_apb_bbp_on_END (0)
#define SOC_SCTRL_SCPERCTRL9_rst_19m_bbp_on_START (1)
#define SOC_SCTRL_SCPERCTRL9_rst_19m_bbp_on_END (1)
#define SOC_SCTRL_SCPERCTRL9_rst_32k_bbp_on_START (2)
#define SOC_SCTRL_SCPERCTRL9_rst_32k_bbp_on_END (2)
#define SOC_SCTRL_SCPERCTRL9_rst_bbp_dbg_timer_START (4)
#define SOC_SCTRL_SCPERCTRL9_rst_bbp_dbg_timer_END (4)
#define SOC_SCTRL_SCPERCTRL9_rst_bbp_guc_timer_START (5)
#define SOC_SCTRL_SCPERCTRL9_rst_bbp_guc_timer_END (5)
#define SOC_SCTRL_SCPERCTRL9_bbp_on_ctrl_START (7)
#define SOC_SCTRL_SCPERCTRL9_bbp_on_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddra_acctl_ioctrl_henl_in : 1;
        unsigned int ddrb_acctl_ioctrl_henl_in : 1;
        unsigned int ddrc_acctl_ioctrl_henl_in : 1;
        unsigned int ddrd_acctl_ioctrl_henl_in : 1;
        unsigned int ddra_pll_en_lat : 1;
        unsigned int ddrb_pll_en_lat : 1;
        unsigned int ddrc_pll_en_lat : 1;
        unsigned int ddrd_pll_en_lat : 1;
        unsigned int ddrac_ioctl_ocldo_lhen_in : 1;
        unsigned int ddrbd_ioctl_ocldo_lhen_in : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 4;
    } reg;
} SOC_SCTRL_SCPERCTRL10_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL10_ddra_acctl_ioctrl_henl_in_START (0)
#define SOC_SCTRL_SCPERCTRL10_ddra_acctl_ioctrl_henl_in_END (0)
#define SOC_SCTRL_SCPERCTRL10_ddrb_acctl_ioctrl_henl_in_START (1)
#define SOC_SCTRL_SCPERCTRL10_ddrb_acctl_ioctrl_henl_in_END (1)
#define SOC_SCTRL_SCPERCTRL10_ddrc_acctl_ioctrl_henl_in_START (2)
#define SOC_SCTRL_SCPERCTRL10_ddrc_acctl_ioctrl_henl_in_END (2)
#define SOC_SCTRL_SCPERCTRL10_ddrd_acctl_ioctrl_henl_in_START (3)
#define SOC_SCTRL_SCPERCTRL10_ddrd_acctl_ioctrl_henl_in_END (3)
#define SOC_SCTRL_SCPERCTRL10_ddra_pll_en_lat_START (4)
#define SOC_SCTRL_SCPERCTRL10_ddra_pll_en_lat_END (4)
#define SOC_SCTRL_SCPERCTRL10_ddrb_pll_en_lat_START (5)
#define SOC_SCTRL_SCPERCTRL10_ddrb_pll_en_lat_END (5)
#define SOC_SCTRL_SCPERCTRL10_ddrc_pll_en_lat_START (6)
#define SOC_SCTRL_SCPERCTRL10_ddrc_pll_en_lat_END (6)
#define SOC_SCTRL_SCPERCTRL10_ddrd_pll_en_lat_START (7)
#define SOC_SCTRL_SCPERCTRL10_ddrd_pll_en_lat_END (7)
#define SOC_SCTRL_SCPERCTRL10_ddrac_ioctl_ocldo_lhen_in_START (8)
#define SOC_SCTRL_SCPERCTRL10_ddrac_ioctl_ocldo_lhen_in_END (8)
#define SOC_SCTRL_SCPERCTRL10_ddrbd_ioctl_ocldo_lhen_in_START (9)
#define SOC_SCTRL_SCPERCTRL10_ddrbd_ioctl_ocldo_lhen_in_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_SCTRL_SCPERCTRL11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 3;
        unsigned int reserved_3: 21;
    } reg;
} SOC_SCTRL_SCPERCTRL12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_SCTRL_SCPERCTRL13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERCTRL14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERCTRL15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int avs_en0 : 1;
        unsigned int avs_en1 : 1;
        unsigned int avs_en2 : 1;
        unsigned int avs_en3 : 1;
        unsigned int avs_en4 : 1;
        unsigned int avs_en5 : 1;
        unsigned int avs_en6 : 1;
        unsigned int avs_en7 : 1;
        unsigned int avs_en8 : 1;
        unsigned int avs_en9 : 1;
        unsigned int avs_en10 : 1;
        unsigned int avs_en11 : 1;
        unsigned int avs_en12 : 1;
        unsigned int avs_en13 : 1;
        unsigned int avs_en14 : 1;
        unsigned int avs_en15 : 1;
        unsigned int scperctrl16_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL16_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL16_avs_en0_START (0)
#define SOC_SCTRL_SCPERCTRL16_avs_en0_END (0)
#define SOC_SCTRL_SCPERCTRL16_avs_en1_START (1)
#define SOC_SCTRL_SCPERCTRL16_avs_en1_END (1)
#define SOC_SCTRL_SCPERCTRL16_avs_en2_START (2)
#define SOC_SCTRL_SCPERCTRL16_avs_en2_END (2)
#define SOC_SCTRL_SCPERCTRL16_avs_en3_START (3)
#define SOC_SCTRL_SCPERCTRL16_avs_en3_END (3)
#define SOC_SCTRL_SCPERCTRL16_avs_en4_START (4)
#define SOC_SCTRL_SCPERCTRL16_avs_en4_END (4)
#define SOC_SCTRL_SCPERCTRL16_avs_en5_START (5)
#define SOC_SCTRL_SCPERCTRL16_avs_en5_END (5)
#define SOC_SCTRL_SCPERCTRL16_avs_en6_START (6)
#define SOC_SCTRL_SCPERCTRL16_avs_en6_END (6)
#define SOC_SCTRL_SCPERCTRL16_avs_en7_START (7)
#define SOC_SCTRL_SCPERCTRL16_avs_en7_END (7)
#define SOC_SCTRL_SCPERCTRL16_avs_en8_START (8)
#define SOC_SCTRL_SCPERCTRL16_avs_en8_END (8)
#define SOC_SCTRL_SCPERCTRL16_avs_en9_START (9)
#define SOC_SCTRL_SCPERCTRL16_avs_en9_END (9)
#define SOC_SCTRL_SCPERCTRL16_avs_en10_START (10)
#define SOC_SCTRL_SCPERCTRL16_avs_en10_END (10)
#define SOC_SCTRL_SCPERCTRL16_avs_en11_START (11)
#define SOC_SCTRL_SCPERCTRL16_avs_en11_END (11)
#define SOC_SCTRL_SCPERCTRL16_avs_en12_START (12)
#define SOC_SCTRL_SCPERCTRL16_avs_en12_END (12)
#define SOC_SCTRL_SCPERCTRL16_avs_en13_START (13)
#define SOC_SCTRL_SCPERCTRL16_avs_en13_END (13)
#define SOC_SCTRL_SCPERCTRL16_avs_en14_START (14)
#define SOC_SCTRL_SCPERCTRL16_avs_en14_END (14)
#define SOC_SCTRL_SCPERCTRL16_avs_en15_START (15)
#define SOC_SCTRL_SCPERCTRL16_avs_en15_END (15)
#define SOC_SCTRL_SCPERCTRL16_scperctrl16_msk_START (16)
#define SOC_SCTRL_SCPERCTRL16_scperctrl16_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi1_avs_en0 : 1;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int sel_suspend_ao2syscache_core_crg_apb_inuse : 1;
        unsigned int sel_suspend_ao2syscache_lpmcu_invar_inuse : 1;
        unsigned int sel_suspend_ao2syscache_ddr_inuse : 1;
        unsigned int sel_suspend_ao2syscache_sysbus_inuse : 1;
        unsigned int sel_suspend_ao2syscache_hsdt_subsys_inuse : 1;
        unsigned int sel_suspend_ao2syscache_center_crossbar_inuse : 1;
        unsigned int sel_suspend_ao1syscache_cpu_gic_inuse : 1;
        unsigned int mddrc_syscache_retention_flag : 1;
        unsigned int hifi_load_image_flag : 1;
        unsigned int asp_imgld_flag : 1;
        unsigned int scperctrl17_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL17_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL17_spmi1_avs_en0_START (0)
#define SOC_SCTRL_SCPERCTRL17_spmi1_avs_en0_END (0)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_core_crg_apb_inuse_START (6)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_core_crg_apb_inuse_END (6)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_lpmcu_invar_inuse_START (7)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_lpmcu_invar_inuse_END (7)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_ddr_inuse_START (8)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_ddr_inuse_END (8)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_sysbus_inuse_START (9)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_sysbus_inuse_END (9)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_hsdt_subsys_inuse_START (10)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_hsdt_subsys_inuse_END (10)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_center_crossbar_inuse_START (11)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao2syscache_center_crossbar_inuse_END (11)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao1syscache_cpu_gic_inuse_START (12)
#define SOC_SCTRL_SCPERCTRL17_sel_suspend_ao1syscache_cpu_gic_inuse_END (12)
#define SOC_SCTRL_SCPERCTRL17_mddrc_syscache_retention_flag_START (13)
#define SOC_SCTRL_SCPERCTRL17_mddrc_syscache_retention_flag_END (13)
#define SOC_SCTRL_SCPERCTRL17_hifi_load_image_flag_START (14)
#define SOC_SCTRL_SCPERCTRL17_hifi_load_image_flag_END (14)
#define SOC_SCTRL_SCPERCTRL17_asp_imgld_flag_START (15)
#define SOC_SCTRL_SCPERCTRL17_asp_imgld_flag_END (15)
#define SOC_SCTRL_SCPERCTRL17_scperctrl17_msk_START (16)
#define SOC_SCTRL_SCPERCTRL17_scperctrl17_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 10;
        unsigned int reserved_5 : 10;
        unsigned int bbp_apb_bus_slv_stat : 1;
    } reg;
} SOC_SCTRL_SCPERSTATUS0_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS0_bbp_apb_bus_slv_stat_START (31)
#define SOC_SCTRL_SCPERSTATUS0_bbp_apb_bus_slv_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTATUS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 10;
        unsigned int reserved_2: 10;
        unsigned int reserved_3: 2;
    } reg;
} SOC_SCTRL_SCPERSTATUS2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTATUS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bbdrx_timeout_dbg_info : 32;
    } reg;
} SOC_SCTRL_SCPERSTATUS4_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS4_bbdrx_timeout_dbg_info_START (0)
#define SOC_SCTRL_SCPERSTATUS4_bbdrx_timeout_dbg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int mdm_tsp_dbg_ack : 1;
        unsigned int reserved_6 : 1;
        unsigned int repair_finish : 1;
        unsigned int reserved_7 : 1;
        unsigned int cfg_ispa7_dbgen_dx : 4;
    } reg;
} SOC_SCTRL_SCPERSTATUS5_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS5_mdm_tsp_dbg_ack_START (24)
#define SOC_SCTRL_SCPERSTATUS5_mdm_tsp_dbg_ack_END (24)
#define SOC_SCTRL_SCPERSTATUS5_repair_finish_START (26)
#define SOC_SCTRL_SCPERSTATUS5_repair_finish_END (26)
#define SOC_SCTRL_SCPERSTATUS5_cfg_ispa7_dbgen_dx_START (28)
#define SOC_SCTRL_SCPERSTATUS5_cfg_ispa7_dbgen_dx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int sc_cfg_arm_dbgen_dx : 4;
        unsigned int sc_cfg_mcu_dbgen_dx : 4;
        unsigned int audio_mmbuf_ctrl_to_sctrl : 8;
    } reg;
} SOC_SCTRL_SCPERSTATUS6_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS6_sc_cfg_arm_dbgen_dx_START (16)
#define SOC_SCTRL_SCPERSTATUS6_sc_cfg_arm_dbgen_dx_END (19)
#define SOC_SCTRL_SCPERSTATUS6_sc_cfg_mcu_dbgen_dx_START (20)
#define SOC_SCTRL_SCPERSTATUS6_sc_cfg_mcu_dbgen_dx_END (23)
#define SOC_SCTRL_SCPERSTATUS6_audio_mmbuf_ctrl_to_sctrl_START (24)
#define SOC_SCTRL_SCPERSTATUS6_audio_mmbuf_ctrl_to_sctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 2;
        unsigned int reserved_3: 2;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 8;
    } reg;
} SOC_SCTRL_SCPERSTATUS7_UNION;
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
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 6;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 14;
    } reg;
} SOC_SCTRL_SCPERSTATUS8_UNION;
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
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 7;
    } reg;
} SOC_SCTRL_SCPERSTATUS9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_arc_watchdog_reset : 1;
        unsigned int pcie0_100ms_idle_timeout_intr : 1;
        unsigned int pcie1_100ms_idle_timeout_intr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int iomcu_core_stalled : 1;
        unsigned int iomcu_sys_tf_half_r : 1;
        unsigned int reserved_4 : 13;
        unsigned int reserved_5 : 10;
    } reg;
} SOC_SCTRL_SCPERSTATUS10_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS10_iomcu_arc_watchdog_reset_START (0)
#define SOC_SCTRL_SCPERSTATUS10_iomcu_arc_watchdog_reset_END (0)
#define SOC_SCTRL_SCPERSTATUS10_pcie0_100ms_idle_timeout_intr_START (1)
#define SOC_SCTRL_SCPERSTATUS10_pcie0_100ms_idle_timeout_intr_END (1)
#define SOC_SCTRL_SCPERSTATUS10_pcie1_100ms_idle_timeout_intr_START (2)
#define SOC_SCTRL_SCPERSTATUS10_pcie1_100ms_idle_timeout_intr_END (2)
#define SOC_SCTRL_SCPERSTATUS10_iomcu_core_stalled_START (7)
#define SOC_SCTRL_SCPERSTATUS10_iomcu_core_stalled_END (7)
#define SOC_SCTRL_SCPERSTATUS10_iomcu_sys_tf_half_r_START (8)
#define SOC_SCTRL_SCPERSTATUS10_iomcu_sys_tf_half_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 10;
        unsigned int reserved_2: 10;
        unsigned int reserved_3: 2;
    } reg;
} SOC_SCTRL_SCPERSTATUS11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int intr_wakeup_swing_enter_req : 1;
        unsigned int intr_wakeup_swing_exit_req : 1;
        unsigned int reserved_4 : 26;
    } reg;
} SOC_SCTRL_SCPERSTATUS12_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS12_intr_wakeup_swing_enter_req_START (4)
#define SOC_SCTRL_SCPERSTATUS12_intr_wakeup_swing_enter_req_END (4)
#define SOC_SCTRL_SCPERSTATUS12_intr_wakeup_swing_exit_req_START (5)
#define SOC_SCTRL_SCPERSTATUS12_intr_wakeup_swing_exit_req_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_hpm_opc : 10;
        unsigned int ao_hpm_opc_vld : 1;
        unsigned int reserved_0 : 1;
        unsigned int ao_hpmx_opc : 10;
        unsigned int ao_hpmx_opc_vld : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_SCTRL_SCPERSTATUS13_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS13_ao_hpm_opc_START (0)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpm_opc_END (9)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpm_opc_vld_START (10)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpm_opc_vld_END (10)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpmx_opc_START (12)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpmx_opc_END (21)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpmx_opc_vld_START (22)
#define SOC_SCTRL_SCPERSTATUS13_ao_hpmx_opc_vld_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 10;
        unsigned int ao_hpm_opc_min : 10;
        unsigned int ao_hpmx_opc_min : 10;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SCTRL_SCPERSTATUS14_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS14_ao_hpm_opc_min_START (10)
#define SOC_SCTRL_SCPERSTATUS14_ao_hpm_opc_min_END (19)
#define SOC_SCTRL_SCPERSTATUS14_ao_hpmx_opc_min_START (20)
#define SOC_SCTRL_SCPERSTATUS14_ao_hpmx_opc_min_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_reset_state : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 6;
        unsigned int reserved_10 : 16;
    } reg;
} SOC_SCTRL_SCPERSTATUS15_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS15_ddr_reset_state_START (0)
#define SOC_SCTRL_SCPERSTATUS15_ddr_reset_state_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int memory_repair_bypass : 1;
        unsigned int hardw_ctrl_sel0 : 1;
        unsigned int boot_mode : 2;
        unsigned int ufs_qspi_sel_pre : 2;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
        unsigned int reserved_2 : 1;
        unsigned int ufs_qspi_sel : 1;
        unsigned int ate_mode : 5;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 6;
        unsigned int reserved_5 : 4;
    } reg;
} SOC_SCTRL_SCINNERSTAT_UNION;
#endif
#define SOC_SCTRL_SCINNERSTAT_memory_repair_bypass_START (0)
#define SOC_SCTRL_SCINNERSTAT_memory_repair_bypass_END (0)
#define SOC_SCTRL_SCINNERSTAT_hardw_ctrl_sel0_START (1)
#define SOC_SCTRL_SCINNERSTAT_hardw_ctrl_sel0_END (1)
#define SOC_SCTRL_SCINNERSTAT_boot_mode_START (2)
#define SOC_SCTRL_SCINNERSTAT_boot_mode_END (3)
#define SOC_SCTRL_SCINNERSTAT_ufs_qspi_sel_pre_START (4)
#define SOC_SCTRL_SCINNERSTAT_ufs_qspi_sel_pre_END (5)
#define SOC_SCTRL_SCINNERSTAT_ufs_qspi_sel_START (15)
#define SOC_SCTRL_SCINNERSTAT_ufs_qspi_sel_END (15)
#define SOC_SCTRL_SCINNERSTAT_ate_mode_START (16)
#define SOC_SCTRL_SCINNERSTAT_ate_mode_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mali_dbgack_byp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCTRL_SCINNERCTRL_UNION;
#endif
#define SOC_SCTRL_SCINNERCTRL_mali_dbgack_byp_START (0)
#define SOC_SCTRL_SCINNERCTRL_mali_dbgack_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mrb_busy_flag : 32;
    } reg;
} SOC_SCTRL_SCMRBBUSYSTAT_UNION;
#endif
#define SOC_SCTRL_SCMRBBUSYSTAT_mrb_busy_flag_START (0)
#define SOC_SCTRL_SCMRBBUSYSTAT_mrb_busy_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swaddr : 32;
    } reg;
} SOC_SCTRL_SCSWADDR_UNION;
#endif
#define SOC_SCTRL_SCSWADDR_swaddr_START (0)
#define SOC_SCTRL_SCSWADDR_swaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrtrainaddr : 32;
    } reg;
} SOC_SCTRL_SCDDRADDR_UNION;
#endif
#define SOC_SCTRL_SCDDRADDR_ddrtrainaddr_START (0)
#define SOC_SCTRL_SCDDRADDR_ddrtrainaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrtraindata : 32;
    } reg;
} SOC_SCTRL_SCDDRDATA_UNION;
#endif
#define SOC_SCTRL_SCDDRDATA_ddrtraindata_START (0)
#define SOC_SCTRL_SCDDRDATA_ddrtraindata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA0_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA0_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA0_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA1_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA1_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA1_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA2_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA2_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA2_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA3_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA3_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA3_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA4_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA4_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA4_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA5_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA5_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA5_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA6_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA6_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA6_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA7_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA7_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA7_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA8_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA8_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA8_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA9_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA9_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA9_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA10_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA10_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA10_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA11_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA11_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA11_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA12_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA12_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA12_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA13_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA13_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA13_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA14_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA14_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA14_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA15_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA15_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA15_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA16_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA16_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA16_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA17_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA17_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA17_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA18_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA18_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA18_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA19_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA19_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA19_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA20_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA20_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA20_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA21_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA21_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA21_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA22_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA22_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA22_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA23_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA23_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA23_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA24_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA24_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA24_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA25_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA25_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA25_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA26_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA26_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA26_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA27_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA27_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA27_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA28_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA28_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA28_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED_NS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata0_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA0_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA0_MSK_scbakdata0_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA0_MSK_scbakdata0_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata1_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA1_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA1_MSK_scbakdata1_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA1_MSK_scbakdata1_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata2_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA2_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA2_MSK_scbakdata2_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA2_MSK_scbakdata2_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata3_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA3_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA3_MSK_scbakdata3_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA3_MSK_scbakdata3_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata4_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA4_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA4_MSK_scbakdata4_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA4_MSK_scbakdata4_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata5_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA5_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA5_MSK_scbakdata5_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA5_MSK_scbakdata5_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata6_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA6_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA6_MSK_scbakdata6_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA6_MSK_scbakdata6_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int scbakdata7_msk_msk : 16;
    } reg;
} SOC_SCTRL_SCBAKDATA7_MSK_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA7_MSK_scbakdata7_msk_msk_START (16)
#define SOC_SCTRL_SCBAKDATA7_MSK_scbakdata7_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dapclkoff_sys_n : 1;
        unsigned int auto_clkgt_h2p_lpperi_en : 1;
        unsigned int tcm_clk_clkoff_sys_n : 1;
        unsigned int ram_clk_clkoff_sys_n : 1;
        unsigned int aon_clk_clkoff_sys_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int tsen_clk_clkoff_sys_n : 1;
        unsigned int pmc_clk_clkoff_sys_n : 1;
        unsigned int uart_clk_clkoff_sys_n : 1;
        unsigned int funcmbist_clk_clkoff_sys_n : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcrg_clk_clkoff_sys_n : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tim_clk_clkoff_sys_n : 1;
        unsigned int cssys_clk_clkoff_sys_n : 1;
        unsigned int spi_clk_clkoff_sys_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCLPMCUCLKEN_UNION;
#endif
#define SOC_SCTRL_SCLPMCUCLKEN_dapclkoff_sys_n_START (0)
#define SOC_SCTRL_SCLPMCUCLKEN_dapclkoff_sys_n_END (0)
#define SOC_SCTRL_SCLPMCUCLKEN_auto_clkgt_h2p_lpperi_en_START (1)
#define SOC_SCTRL_SCLPMCUCLKEN_auto_clkgt_h2p_lpperi_en_END (1)
#define SOC_SCTRL_SCLPMCUCLKEN_tcm_clk_clkoff_sys_n_START (2)
#define SOC_SCTRL_SCLPMCUCLKEN_tcm_clk_clkoff_sys_n_END (2)
#define SOC_SCTRL_SCLPMCUCLKEN_ram_clk_clkoff_sys_n_START (3)
#define SOC_SCTRL_SCLPMCUCLKEN_ram_clk_clkoff_sys_n_END (3)
#define SOC_SCTRL_SCLPMCUCLKEN_aon_clk_clkoff_sys_n_START (4)
#define SOC_SCTRL_SCLPMCUCLKEN_aon_clk_clkoff_sys_n_END (4)
#define SOC_SCTRL_SCLPMCUCLKEN_tsen_clk_clkoff_sys_n_START (6)
#define SOC_SCTRL_SCLPMCUCLKEN_tsen_clk_clkoff_sys_n_END (6)
#define SOC_SCTRL_SCLPMCUCLKEN_pmc_clk_clkoff_sys_n_START (7)
#define SOC_SCTRL_SCLPMCUCLKEN_pmc_clk_clkoff_sys_n_END (7)
#define SOC_SCTRL_SCLPMCUCLKEN_uart_clk_clkoff_sys_n_START (8)
#define SOC_SCTRL_SCLPMCUCLKEN_uart_clk_clkoff_sys_n_END (8)
#define SOC_SCTRL_SCLPMCUCLKEN_funcmbist_clk_clkoff_sys_n_START (9)
#define SOC_SCTRL_SCLPMCUCLKEN_funcmbist_clk_clkoff_sys_n_END (9)
#define SOC_SCTRL_SCLPMCUCLKEN_pcrg_clk_clkoff_sys_n_START (11)
#define SOC_SCTRL_SCLPMCUCLKEN_pcrg_clk_clkoff_sys_n_END (11)
#define SOC_SCTRL_SCLPMCUCLKEN_tim_clk_clkoff_sys_n_START (14)
#define SOC_SCTRL_SCLPMCUCLKEN_tim_clk_clkoff_sys_n_END (14)
#define SOC_SCTRL_SCLPMCUCLKEN_cssys_clk_clkoff_sys_n_START (15)
#define SOC_SCTRL_SCLPMCUCLKEN_cssys_clk_clkoff_sys_n_END (15)
#define SOC_SCTRL_SCLPMCUCLKEN_spi_clk_clkoff_sys_n_START (16)
#define SOC_SCTRL_SCLPMCUCLKEN_spi_clk_clkoff_sys_n_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dapclkoff_sys_n : 1;
        unsigned int auto_clkgt_h2p_lpperi_en : 1;
        unsigned int tcm_clk_clkoff_sys_n : 1;
        unsigned int ram_clk_clkoff_sys_n : 1;
        unsigned int aon_clk_clkoff_sys_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int tsen_clk_clkoff_sys_n : 1;
        unsigned int pmc_clk_clkoff_sys_n : 1;
        unsigned int uart_clk_clkoff_sys_n : 1;
        unsigned int funcmbist_clk_clkoff_sys_n : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcrg_clk_clkoff_sys_n : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tim_clk_clkoff_sys_n : 1;
        unsigned int cssys_clk_clkoff_sys_n : 1;
        unsigned int spi_clk_clkoff_sys_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCLPMCUCLKDIS_UNION;
#endif
#define SOC_SCTRL_SCLPMCUCLKDIS_dapclkoff_sys_n_START (0)
#define SOC_SCTRL_SCLPMCUCLKDIS_dapclkoff_sys_n_END (0)
#define SOC_SCTRL_SCLPMCUCLKDIS_auto_clkgt_h2p_lpperi_en_START (1)
#define SOC_SCTRL_SCLPMCUCLKDIS_auto_clkgt_h2p_lpperi_en_END (1)
#define SOC_SCTRL_SCLPMCUCLKDIS_tcm_clk_clkoff_sys_n_START (2)
#define SOC_SCTRL_SCLPMCUCLKDIS_tcm_clk_clkoff_sys_n_END (2)
#define SOC_SCTRL_SCLPMCUCLKDIS_ram_clk_clkoff_sys_n_START (3)
#define SOC_SCTRL_SCLPMCUCLKDIS_ram_clk_clkoff_sys_n_END (3)
#define SOC_SCTRL_SCLPMCUCLKDIS_aon_clk_clkoff_sys_n_START (4)
#define SOC_SCTRL_SCLPMCUCLKDIS_aon_clk_clkoff_sys_n_END (4)
#define SOC_SCTRL_SCLPMCUCLKDIS_tsen_clk_clkoff_sys_n_START (6)
#define SOC_SCTRL_SCLPMCUCLKDIS_tsen_clk_clkoff_sys_n_END (6)
#define SOC_SCTRL_SCLPMCUCLKDIS_pmc_clk_clkoff_sys_n_START (7)
#define SOC_SCTRL_SCLPMCUCLKDIS_pmc_clk_clkoff_sys_n_END (7)
#define SOC_SCTRL_SCLPMCUCLKDIS_uart_clk_clkoff_sys_n_START (8)
#define SOC_SCTRL_SCLPMCUCLKDIS_uart_clk_clkoff_sys_n_END (8)
#define SOC_SCTRL_SCLPMCUCLKDIS_funcmbist_clk_clkoff_sys_n_START (9)
#define SOC_SCTRL_SCLPMCUCLKDIS_funcmbist_clk_clkoff_sys_n_END (9)
#define SOC_SCTRL_SCLPMCUCLKDIS_pcrg_clk_clkoff_sys_n_START (11)
#define SOC_SCTRL_SCLPMCUCLKDIS_pcrg_clk_clkoff_sys_n_END (11)
#define SOC_SCTRL_SCLPMCUCLKDIS_tim_clk_clkoff_sys_n_START (14)
#define SOC_SCTRL_SCLPMCUCLKDIS_tim_clk_clkoff_sys_n_END (14)
#define SOC_SCTRL_SCLPMCUCLKDIS_cssys_clk_clkoff_sys_n_START (15)
#define SOC_SCTRL_SCLPMCUCLKDIS_cssys_clk_clkoff_sys_n_END (15)
#define SOC_SCTRL_SCLPMCUCLKDIS_spi_clk_clkoff_sys_n_START (16)
#define SOC_SCTRL_SCLPMCUCLKDIS_spi_clk_clkoff_sys_n_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dapclkoff_sys_n : 1;
        unsigned int auto_clkgt_h2p_lpperi_en : 1;
        unsigned int tcm_clk_clkoff_sys_n : 1;
        unsigned int ram_clk_clkoff_sys_n : 1;
        unsigned int aon_clk_clkoff_sys_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int tsen_clk_clkoff_sys_n : 1;
        unsigned int pmc_clk_clkoff_sys_n : 1;
        unsigned int uart_clk_clkoff_sys_n : 1;
        unsigned int funcmbist_clk_clkoff_sys_n : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcrg_clk_clkoff_sys_n : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tim_clk_clkoff_sys_n : 1;
        unsigned int cssys_clk_clkoff_sys_n : 1;
        unsigned int spi_clk_clkoff_sys_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCLPMCUCLKSTAT_UNION;
#endif
#define SOC_SCTRL_SCLPMCUCLKSTAT_dapclkoff_sys_n_START (0)
#define SOC_SCTRL_SCLPMCUCLKSTAT_dapclkoff_sys_n_END (0)
#define SOC_SCTRL_SCLPMCUCLKSTAT_auto_clkgt_h2p_lpperi_en_START (1)
#define SOC_SCTRL_SCLPMCUCLKSTAT_auto_clkgt_h2p_lpperi_en_END (1)
#define SOC_SCTRL_SCLPMCUCLKSTAT_tcm_clk_clkoff_sys_n_START (2)
#define SOC_SCTRL_SCLPMCUCLKSTAT_tcm_clk_clkoff_sys_n_END (2)
#define SOC_SCTRL_SCLPMCUCLKSTAT_ram_clk_clkoff_sys_n_START (3)
#define SOC_SCTRL_SCLPMCUCLKSTAT_ram_clk_clkoff_sys_n_END (3)
#define SOC_SCTRL_SCLPMCUCLKSTAT_aon_clk_clkoff_sys_n_START (4)
#define SOC_SCTRL_SCLPMCUCLKSTAT_aon_clk_clkoff_sys_n_END (4)
#define SOC_SCTRL_SCLPMCUCLKSTAT_tsen_clk_clkoff_sys_n_START (6)
#define SOC_SCTRL_SCLPMCUCLKSTAT_tsen_clk_clkoff_sys_n_END (6)
#define SOC_SCTRL_SCLPMCUCLKSTAT_pmc_clk_clkoff_sys_n_START (7)
#define SOC_SCTRL_SCLPMCUCLKSTAT_pmc_clk_clkoff_sys_n_END (7)
#define SOC_SCTRL_SCLPMCUCLKSTAT_uart_clk_clkoff_sys_n_START (8)
#define SOC_SCTRL_SCLPMCUCLKSTAT_uart_clk_clkoff_sys_n_END (8)
#define SOC_SCTRL_SCLPMCUCLKSTAT_funcmbist_clk_clkoff_sys_n_START (9)
#define SOC_SCTRL_SCLPMCUCLKSTAT_funcmbist_clk_clkoff_sys_n_END (9)
#define SOC_SCTRL_SCLPMCUCLKSTAT_pcrg_clk_clkoff_sys_n_START (11)
#define SOC_SCTRL_SCLPMCUCLKSTAT_pcrg_clk_clkoff_sys_n_END (11)
#define SOC_SCTRL_SCLPMCUCLKSTAT_tim_clk_clkoff_sys_n_START (14)
#define SOC_SCTRL_SCLPMCUCLKSTAT_tim_clk_clkoff_sys_n_END (14)
#define SOC_SCTRL_SCLPMCUCLKSTAT_cssys_clk_clkoff_sys_n_START (15)
#define SOC_SCTRL_SCLPMCUCLKSTAT_cssys_clk_clkoff_sys_n_END (15)
#define SOC_SCTRL_SCLPMCUCLKSTAT_spi_clk_clkoff_sys_n_START (16)
#define SOC_SCTRL_SCLPMCUCLKSTAT_spi_clk_clkoff_sys_n_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_software_req : 1;
        unsigned int coresight_soft_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int tcm_soft_rst_req : 1;
        unsigned int ram_soft_rst_req : 1;
        unsigned int aon_soft_rst_req : 1;
        unsigned int ccrg_soft_rst_req : 1;
        unsigned int tsen_soft_rst_req : 1;
        unsigned int pmc_soft_rst_req : 1;
        unsigned int uart_soft_rst_req : 1;
        unsigned int funcmbist_soft_rst_req : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcrg_soft_rst_req : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tim_soft_rst_req : 1;
        unsigned int cssys_soft_rst_req : 1;
        unsigned int spi_soft_rst_req : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_SCTRL_SCLPMCURSTEN_UNION;
#endif
#define SOC_SCTRL_SCLPMCURSTEN_rst_software_req_START (0)
#define SOC_SCTRL_SCLPMCURSTEN_rst_software_req_END (0)
#define SOC_SCTRL_SCLPMCURSTEN_coresight_soft_rst_req_START (1)
#define SOC_SCTRL_SCLPMCURSTEN_coresight_soft_rst_req_END (1)
#define SOC_SCTRL_SCLPMCURSTEN_tcm_soft_rst_req_START (3)
#define SOC_SCTRL_SCLPMCURSTEN_tcm_soft_rst_req_END (3)
#define SOC_SCTRL_SCLPMCURSTEN_ram_soft_rst_req_START (4)
#define SOC_SCTRL_SCLPMCURSTEN_ram_soft_rst_req_END (4)
#define SOC_SCTRL_SCLPMCURSTEN_aon_soft_rst_req_START (5)
#define SOC_SCTRL_SCLPMCURSTEN_aon_soft_rst_req_END (5)
#define SOC_SCTRL_SCLPMCURSTEN_ccrg_soft_rst_req_START (6)
#define SOC_SCTRL_SCLPMCURSTEN_ccrg_soft_rst_req_END (6)
#define SOC_SCTRL_SCLPMCURSTEN_tsen_soft_rst_req_START (7)
#define SOC_SCTRL_SCLPMCURSTEN_tsen_soft_rst_req_END (7)
#define SOC_SCTRL_SCLPMCURSTEN_pmc_soft_rst_req_START (8)
#define SOC_SCTRL_SCLPMCURSTEN_pmc_soft_rst_req_END (8)
#define SOC_SCTRL_SCLPMCURSTEN_uart_soft_rst_req_START (9)
#define SOC_SCTRL_SCLPMCURSTEN_uart_soft_rst_req_END (9)
#define SOC_SCTRL_SCLPMCURSTEN_funcmbist_soft_rst_req_START (10)
#define SOC_SCTRL_SCLPMCURSTEN_funcmbist_soft_rst_req_END (10)
#define SOC_SCTRL_SCLPMCURSTEN_pcrg_soft_rst_req_START (12)
#define SOC_SCTRL_SCLPMCURSTEN_pcrg_soft_rst_req_END (12)
#define SOC_SCTRL_SCLPMCURSTEN_tim_soft_rst_req_START (15)
#define SOC_SCTRL_SCLPMCURSTEN_tim_soft_rst_req_END (15)
#define SOC_SCTRL_SCLPMCURSTEN_cssys_soft_rst_req_START (16)
#define SOC_SCTRL_SCLPMCURSTEN_cssys_soft_rst_req_END (16)
#define SOC_SCTRL_SCLPMCURSTEN_spi_soft_rst_req_START (17)
#define SOC_SCTRL_SCLPMCURSTEN_spi_soft_rst_req_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_software_req : 1;
        unsigned int coresight_soft_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int tcm_soft_rst_req : 1;
        unsigned int ram_soft_rst_req : 1;
        unsigned int aon_soft_rst_req : 1;
        unsigned int ccrg_soft_rst_req : 1;
        unsigned int tsen_soft_rst_req : 1;
        unsigned int pmc_soft_rst_req : 1;
        unsigned int uart_soft_rst_req : 1;
        unsigned int funcmbist_soft_rst_req : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcrg_soft_rst_req : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tim_soft_rst_req : 1;
        unsigned int cssys_soft_rst_req : 1;
        unsigned int spi_soft_rst_req : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_SCTRL_SCLPMCURSTDIS_UNION;
#endif
#define SOC_SCTRL_SCLPMCURSTDIS_rst_software_req_START (0)
#define SOC_SCTRL_SCLPMCURSTDIS_rst_software_req_END (0)
#define SOC_SCTRL_SCLPMCURSTDIS_coresight_soft_rst_req_START (1)
#define SOC_SCTRL_SCLPMCURSTDIS_coresight_soft_rst_req_END (1)
#define SOC_SCTRL_SCLPMCURSTDIS_tcm_soft_rst_req_START (3)
#define SOC_SCTRL_SCLPMCURSTDIS_tcm_soft_rst_req_END (3)
#define SOC_SCTRL_SCLPMCURSTDIS_ram_soft_rst_req_START (4)
#define SOC_SCTRL_SCLPMCURSTDIS_ram_soft_rst_req_END (4)
#define SOC_SCTRL_SCLPMCURSTDIS_aon_soft_rst_req_START (5)
#define SOC_SCTRL_SCLPMCURSTDIS_aon_soft_rst_req_END (5)
#define SOC_SCTRL_SCLPMCURSTDIS_ccrg_soft_rst_req_START (6)
#define SOC_SCTRL_SCLPMCURSTDIS_ccrg_soft_rst_req_END (6)
#define SOC_SCTRL_SCLPMCURSTDIS_tsen_soft_rst_req_START (7)
#define SOC_SCTRL_SCLPMCURSTDIS_tsen_soft_rst_req_END (7)
#define SOC_SCTRL_SCLPMCURSTDIS_pmc_soft_rst_req_START (8)
#define SOC_SCTRL_SCLPMCURSTDIS_pmc_soft_rst_req_END (8)
#define SOC_SCTRL_SCLPMCURSTDIS_uart_soft_rst_req_START (9)
#define SOC_SCTRL_SCLPMCURSTDIS_uart_soft_rst_req_END (9)
#define SOC_SCTRL_SCLPMCURSTDIS_funcmbist_soft_rst_req_START (10)
#define SOC_SCTRL_SCLPMCURSTDIS_funcmbist_soft_rst_req_END (10)
#define SOC_SCTRL_SCLPMCURSTDIS_pcrg_soft_rst_req_START (12)
#define SOC_SCTRL_SCLPMCURSTDIS_pcrg_soft_rst_req_END (12)
#define SOC_SCTRL_SCLPMCURSTDIS_tim_soft_rst_req_START (15)
#define SOC_SCTRL_SCLPMCURSTDIS_tim_soft_rst_req_END (15)
#define SOC_SCTRL_SCLPMCURSTDIS_cssys_soft_rst_req_START (16)
#define SOC_SCTRL_SCLPMCURSTDIS_cssys_soft_rst_req_END (16)
#define SOC_SCTRL_SCLPMCURSTDIS_spi_soft_rst_req_START (17)
#define SOC_SCTRL_SCLPMCURSTDIS_spi_soft_rst_req_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_software_req : 1;
        unsigned int coresight_soft_rst_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int tcm_soft_rst_req : 1;
        unsigned int ram_soft_rst_req : 1;
        unsigned int aon_soft_rst_req : 1;
        unsigned int ccrg_soft_rst_req : 1;
        unsigned int tsen_soft_rst_req : 1;
        unsigned int pmc_soft_rst_req : 1;
        unsigned int uart_soft_rst_req : 1;
        unsigned int funcmbist_soft_rst_req : 1;
        unsigned int reserved_1 : 1;
        unsigned int pcrg_soft_rst_req : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tim_soft_rst_req : 1;
        unsigned int cssys_soft_rst_req : 1;
        unsigned int spi_soft_rst_req : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_SCTRL_SCLPMCURSTSTAT_UNION;
#endif
#define SOC_SCTRL_SCLPMCURSTSTAT_rst_software_req_START (0)
#define SOC_SCTRL_SCLPMCURSTSTAT_rst_software_req_END (0)
#define SOC_SCTRL_SCLPMCURSTSTAT_coresight_soft_rst_req_START (1)
#define SOC_SCTRL_SCLPMCURSTSTAT_coresight_soft_rst_req_END (1)
#define SOC_SCTRL_SCLPMCURSTSTAT_tcm_soft_rst_req_START (3)
#define SOC_SCTRL_SCLPMCURSTSTAT_tcm_soft_rst_req_END (3)
#define SOC_SCTRL_SCLPMCURSTSTAT_ram_soft_rst_req_START (4)
#define SOC_SCTRL_SCLPMCURSTSTAT_ram_soft_rst_req_END (4)
#define SOC_SCTRL_SCLPMCURSTSTAT_aon_soft_rst_req_START (5)
#define SOC_SCTRL_SCLPMCURSTSTAT_aon_soft_rst_req_END (5)
#define SOC_SCTRL_SCLPMCURSTSTAT_ccrg_soft_rst_req_START (6)
#define SOC_SCTRL_SCLPMCURSTSTAT_ccrg_soft_rst_req_END (6)
#define SOC_SCTRL_SCLPMCURSTSTAT_tsen_soft_rst_req_START (7)
#define SOC_SCTRL_SCLPMCURSTSTAT_tsen_soft_rst_req_END (7)
#define SOC_SCTRL_SCLPMCURSTSTAT_pmc_soft_rst_req_START (8)
#define SOC_SCTRL_SCLPMCURSTSTAT_pmc_soft_rst_req_END (8)
#define SOC_SCTRL_SCLPMCURSTSTAT_uart_soft_rst_req_START (9)
#define SOC_SCTRL_SCLPMCURSTSTAT_uart_soft_rst_req_END (9)
#define SOC_SCTRL_SCLPMCURSTSTAT_funcmbist_soft_rst_req_START (10)
#define SOC_SCTRL_SCLPMCURSTSTAT_funcmbist_soft_rst_req_END (10)
#define SOC_SCTRL_SCLPMCURSTSTAT_pcrg_soft_rst_req_START (12)
#define SOC_SCTRL_SCLPMCURSTSTAT_pcrg_soft_rst_req_END (12)
#define SOC_SCTRL_SCLPMCURSTSTAT_tim_soft_rst_req_START (15)
#define SOC_SCTRL_SCLPMCURSTSTAT_tim_soft_rst_req_END (15)
#define SOC_SCTRL_SCLPMCURSTSTAT_cssys_soft_rst_req_START (16)
#define SOC_SCTRL_SCLPMCURSTSTAT_cssys_soft_rst_req_END (16)
#define SOC_SCTRL_SCLPMCURSTSTAT_spi_soft_rst_req_START (17)
#define SOC_SCTRL_SCLPMCURSTSTAT_spi_soft_rst_req_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int mpudisable : 1;
        unsigned int nmi_in : 1;
        unsigned int bus_div_clk_sel : 2;
        unsigned int sysresetreq_en : 1;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 12;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_SCTRL_SCLPMCUCTRL_UNION;
#endif
#define SOC_SCTRL_SCLPMCUCTRL_mpudisable_START (1)
#define SOC_SCTRL_SCLPMCUCTRL_mpudisable_END (1)
#define SOC_SCTRL_SCLPMCUCTRL_nmi_in_START (2)
#define SOC_SCTRL_SCLPMCUCTRL_nmi_in_END (2)
#define SOC_SCTRL_SCLPMCUCTRL_bus_div_clk_sel_START (3)
#define SOC_SCTRL_SCLPMCUCTRL_bus_div_clk_sel_END (4)
#define SOC_SCTRL_SCLPMCUCTRL_sysresetreq_en_START (5)
#define SOC_SCTRL_SCLPMCUCTRL_sysresetreq_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysresetreq_sign_out_stat : 1;
        unsigned int sleeping : 1;
        unsigned int lockup : 1;
        unsigned int halted : 1;
        unsigned int m3_lp_bus_slv_idle_flag : 1;
        unsigned int in_nmi_hdlr : 1;
        unsigned int hard_fault_mode : 1;
        unsigned int lpmcu_lp_h2p_idle : 1;
        unsigned int lpmcu_bus_idle : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 19;
    } reg;
} SOC_SCTRL_SCLPMCUSTAT_UNION;
#endif
#define SOC_SCTRL_SCLPMCUSTAT_sysresetreq_sign_out_stat_START (0)
#define SOC_SCTRL_SCLPMCUSTAT_sysresetreq_sign_out_stat_END (0)
#define SOC_SCTRL_SCLPMCUSTAT_sleeping_START (1)
#define SOC_SCTRL_SCLPMCUSTAT_sleeping_END (1)
#define SOC_SCTRL_SCLPMCUSTAT_lockup_START (2)
#define SOC_SCTRL_SCLPMCUSTAT_lockup_END (2)
#define SOC_SCTRL_SCLPMCUSTAT_halted_START (3)
#define SOC_SCTRL_SCLPMCUSTAT_halted_END (3)
#define SOC_SCTRL_SCLPMCUSTAT_m3_lp_bus_slv_idle_flag_START (4)
#define SOC_SCTRL_SCLPMCUSTAT_m3_lp_bus_slv_idle_flag_END (4)
#define SOC_SCTRL_SCLPMCUSTAT_in_nmi_hdlr_START (5)
#define SOC_SCTRL_SCLPMCUSTAT_in_nmi_hdlr_END (5)
#define SOC_SCTRL_SCLPMCUSTAT_hard_fault_mode_START (6)
#define SOC_SCTRL_SCLPMCUSTAT_hard_fault_mode_END (6)
#define SOC_SCTRL_SCLPMCUSTAT_lpmcu_lp_h2p_idle_START (7)
#define SOC_SCTRL_SCLPMCUSTAT_lpmcu_lp_h2p_idle_END (7)
#define SOC_SCTRL_SCLPMCUSTAT_lpmcu_bus_idle_START (8)
#define SOC_SCTRL_SCLPMCUSTAT_lpmcu_bus_idle_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpramctrl_sel : 1;
        unsigned int lpram0_mod : 2;
        unsigned int lpram1_mod : 2;
        unsigned int lpram2_mod : 2;
        unsigned int lpram3_mod : 2;
        unsigned int lpram0ctrl_soft : 3;
        unsigned int lpram1ctrl_soft : 3;
        unsigned int lpram2ctrl_soft : 3;
        unsigned int lpram3ctrl_soft : 3;
        unsigned int memrep_ram_mod : 2;
        unsigned int memrep_ramctrl_soft : 3;
        unsigned int reserved : 6;
    } reg;
} SOC_SCTRL_SCLPMCURAMCTRL_UNION;
#endif
#define SOC_SCTRL_SCLPMCURAMCTRL_lpramctrl_sel_START (0)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpramctrl_sel_END (0)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram0_mod_START (1)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram0_mod_END (2)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram1_mod_START (3)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram1_mod_END (4)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram2_mod_START (5)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram2_mod_END (6)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram3_mod_START (7)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram3_mod_END (8)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram0ctrl_soft_START (9)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram0ctrl_soft_END (11)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram1ctrl_soft_START (12)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram1ctrl_soft_END (14)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram2ctrl_soft_START (15)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram2ctrl_soft_END (17)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram3ctrl_soft_START (18)
#define SOC_SCTRL_SCLPMCURAMCTRL_lpram3ctrl_soft_END (20)
#define SOC_SCTRL_SCLPMCURAMCTRL_memrep_ram_mod_START (21)
#define SOC_SCTRL_SCLPMCURAMCTRL_memrep_ram_mod_END (22)
#define SOC_SCTRL_SCLPMCURAMCTRL_memrep_ramctrl_soft_START (23)
#define SOC_SCTRL_SCLPMCURAMCTRL_memrep_ramctrl_soft_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int g2_gdrx_depsleep_flag : 1;
        unsigned int g1_gdrx_depsleep_flag : 1;
        unsigned int wdrx_deepsleep_flag : 1;
        unsigned int cdrx_deepsleep_flag_1x : 1;
        unsigned int cdrx_deepsleep_flag_evdo : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SCTRL_SCBBPDRXSTAT0_UNION;
#endif
#define SOC_SCTRL_SCBBPDRXSTAT0_g2_gdrx_depsleep_flag_START (0)
#define SOC_SCTRL_SCBBPDRXSTAT0_g2_gdrx_depsleep_flag_END (0)
#define SOC_SCTRL_SCBBPDRXSTAT0_g1_gdrx_depsleep_flag_START (1)
#define SOC_SCTRL_SCBBPDRXSTAT0_g1_gdrx_depsleep_flag_END (1)
#define SOC_SCTRL_SCBBPDRXSTAT0_wdrx_deepsleep_flag_START (2)
#define SOC_SCTRL_SCBBPDRXSTAT0_wdrx_deepsleep_flag_END (2)
#define SOC_SCTRL_SCBBPDRXSTAT0_cdrx_deepsleep_flag_1x_START (3)
#define SOC_SCTRL_SCBBPDRXSTAT0_cdrx_deepsleep_flag_1x_END (3)
#define SOC_SCTRL_SCBBPDRXSTAT0_cdrx_deepsleep_flag_evdo_START (4)
#define SOC_SCTRL_SCBBPDRXSTAT0_cdrx_deepsleep_flag_evdo_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldrx2dbg_abs_timer1 : 32;
    } reg;
} SOC_SCTRL_SCBBPDRXSTAT1_UNION;
#endif
#define SOC_SCTRL_SCBBPDRXSTAT1_ldrx2dbg_abs_timer1_START (0)
#define SOC_SCTRL_SCBBPDRXSTAT1_ldrx2dbg_abs_timer1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldrx2dbg_abs_timer2 : 32;
    } reg;
} SOC_SCTRL_SCBBPDRXSTAT2_UNION;
#endif
#define SOC_SCTRL_SCBBPDRXSTAT2_ldrx2dbg_abs_timer2_START (0)
#define SOC_SCTRL_SCBBPDRXSTAT2_ldrx2dbg_abs_timer2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldrx2dbg_abs_timer_sleep1 : 32;
    } reg;
} SOC_SCTRL_SCBBPDRXSTAT3_UNION;
#endif
#define SOC_SCTRL_SCBBPDRXSTAT3_ldrx2dbg_abs_timer_sleep1_START (0)
#define SOC_SCTRL_SCBBPDRXSTAT3_ldrx2dbg_abs_timer_sleep1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldrx2dbg_abs_timer_sleep2 : 32;
    } reg;
} SOC_SCTRL_SCBBPDRXSTAT4_UNION;
#endif
#define SOC_SCTRL_SCBBPDRXSTAT4_ldrx2dbg_abs_timer_sleep2_START (0)
#define SOC_SCTRL_SCBBPDRXSTAT4_ldrx2dbg_abs_timer_sleep2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCA53_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCA53_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCA53_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCA53_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCA53_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCA53_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCA53_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCA53_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCA53_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCA53_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCA53_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCA53_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCA53_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCA53_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCA53_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCA53_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCA53_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCA53_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCA53_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCA53_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCA53_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCA53_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCA53_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCA53_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCA53_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCA53_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCA53_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCA57_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCA57_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCA57_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCA57_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCA57_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCA57_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCA57_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCA57_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCA57_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCA57_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCA57_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCA57_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCA57_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCA57_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCA57_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCA57_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCA57_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCA57_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCA57_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCA57_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCA57_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCA57_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCA57_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCA57_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCA57_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCA57_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCA57_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCIOMCU_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCIOMCU_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCLPMCU_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCLPMCU_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCMCPU_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCMCPU_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCMCPU_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCISPA7_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCISPA7_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCISPA7_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCHIFD_UL_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCHIFD_UL_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCNPU_AICPU_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCNPU_TSCPU_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCNPU_ARCHS_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCSILS_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCSILS_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCSILS_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCSILS_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCSILS_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCSILS_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCSILS_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCSILS_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCSILS_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCSILS_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCSILS_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCSILS_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCSILS_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCSILS_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCSILS_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCSILS_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCSILS_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCSILS_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCSILS_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCSILS_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCSILS_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCSILS_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCSILS_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCSILS_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCSILS_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCSILS_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCSILS_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCMDM5G_L2HAC_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event_mask : 1;
        unsigned int a57_event_mask : 1;
        unsigned int iomcu_event_mask : 1;
        unsigned int lpmcu_event_mask : 1;
        unsigned int mcpu_event_mask : 1;
        unsigned int ispa7_event_mask : 1;
        unsigned int hifd_ul_event_mask : 1;
        unsigned int sils_event_mask : 1;
        unsigned int npu_archs_event_mask : 1;
        unsigned int npu_tscpu_event_mask : 1;
        unsigned int npu_aicpu_event_mask : 1;
        unsigned int mdm5g_l2hac_event_mask : 1;
        unsigned int mdm5g_ccpu5g_event_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_UNION;
#endif
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_a53_event_mask_START (0)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_a53_event_mask_END (0)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_a57_event_mask_START (1)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_a57_event_mask_END (1)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_iomcu_event_mask_START (2)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_iomcu_event_mask_END (2)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_lpmcu_event_mask_START (3)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_lpmcu_event_mask_END (3)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_mcpu_event_mask_START (4)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_mcpu_event_mask_END (4)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_ispa7_event_mask_START (5)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_ispa7_event_mask_END (5)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_hifd_ul_event_mask_START (6)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_hifd_ul_event_mask_END (6)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_sils_event_mask_START (7)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_sils_event_mask_END (7)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_npu_archs_event_mask_START (8)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_npu_archs_event_mask_END (8)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_npu_tscpu_event_mask_START (9)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_npu_tscpu_event_mask_END (9)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_npu_aicpu_event_mask_START (10)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_npu_aicpu_event_mask_END (10)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_mdm5g_l2hac_event_mask_START (11)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_mdm5g_l2hac_event_mask_END (11)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_mdm5g_ccpu5g_event_mask_START (12)
#define SOC_SCTRL_SCMDM5G_CCPU5G_EVENT_MASK_mdm5g_ccpu5g_event_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_event : 1;
        unsigned int a57_event : 1;
        unsigned int iomcu_event : 1;
        unsigned int lpmcu_event : 1;
        unsigned int mcpu_event : 1;
        unsigned int ispa7_event : 1;
        unsigned int hifd_ul_event : 1;
        unsigned int sils_event : 1;
        unsigned int npu_archs_event : 1;
        unsigned int npu_tscpu_event : 1;
        unsigned int npu_aicpu_event : 1;
        unsigned int mdm5g_l2hac_event : 1;
        unsigned int mdm5g_ccpu5g_event : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_SCTRL_SCEVENT_STAT_UNION;
#endif
#define SOC_SCTRL_SCEVENT_STAT_a53_event_START (0)
#define SOC_SCTRL_SCEVENT_STAT_a53_event_END (0)
#define SOC_SCTRL_SCEVENT_STAT_a57_event_START (1)
#define SOC_SCTRL_SCEVENT_STAT_a57_event_END (1)
#define SOC_SCTRL_SCEVENT_STAT_iomcu_event_START (2)
#define SOC_SCTRL_SCEVENT_STAT_iomcu_event_END (2)
#define SOC_SCTRL_SCEVENT_STAT_lpmcu_event_START (3)
#define SOC_SCTRL_SCEVENT_STAT_lpmcu_event_END (3)
#define SOC_SCTRL_SCEVENT_STAT_mcpu_event_START (4)
#define SOC_SCTRL_SCEVENT_STAT_mcpu_event_END (4)
#define SOC_SCTRL_SCEVENT_STAT_ispa7_event_START (5)
#define SOC_SCTRL_SCEVENT_STAT_ispa7_event_END (5)
#define SOC_SCTRL_SCEVENT_STAT_hifd_ul_event_START (6)
#define SOC_SCTRL_SCEVENT_STAT_hifd_ul_event_END (6)
#define SOC_SCTRL_SCEVENT_STAT_sils_event_START (7)
#define SOC_SCTRL_SCEVENT_STAT_sils_event_END (7)
#define SOC_SCTRL_SCEVENT_STAT_npu_archs_event_START (8)
#define SOC_SCTRL_SCEVENT_STAT_npu_archs_event_END (8)
#define SOC_SCTRL_SCEVENT_STAT_npu_tscpu_event_START (9)
#define SOC_SCTRL_SCEVENT_STAT_npu_tscpu_event_END (9)
#define SOC_SCTRL_SCEVENT_STAT_npu_aicpu_event_START (10)
#define SOC_SCTRL_SCEVENT_STAT_npu_aicpu_event_END (10)
#define SOC_SCTRL_SCEVENT_STAT_mdm5g_l2hac_event_START (11)
#define SOC_SCTRL_SCEVENT_STAT_mdm5g_l2hac_event_END (11)
#define SOC_SCTRL_SCEVENT_STAT_mdm5g_ccpu5g_event_START (12)
#define SOC_SCTRL_SCEVENT_STAT_mdm5g_ccpu5g_event_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_iomcu_pll_div : 1;
        unsigned int gt_iomcu_sys_div : 1;
        unsigned int gt_clk_qcr_iomcubus : 1;
        unsigned int reserved : 13;
        unsigned int sciomcuclkctrl_msk : 16;
    } reg;
} SOC_SCTRL_SCIOMCUCLKCTRL_UNION;
#endif
#define SOC_SCTRL_SCIOMCUCLKCTRL_gt_iomcu_pll_div_START (0)
#define SOC_SCTRL_SCIOMCUCLKCTRL_gt_iomcu_pll_div_END (0)
#define SOC_SCTRL_SCIOMCUCLKCTRL_gt_iomcu_sys_div_START (1)
#define SOC_SCTRL_SCIOMCUCLKCTRL_gt_iomcu_sys_div_END (1)
#define SOC_SCTRL_SCIOMCUCLKCTRL_gt_clk_qcr_iomcubus_START (2)
#define SOC_SCTRL_SCIOMCUCLKCTRL_gt_clk_qcr_iomcubus_END (2)
#define SOC_SCTRL_SCIOMCUCLKCTRL_sciomcuclkctrl_msk_START (16)
#define SOC_SCTRL_SCIOMCUCLKCTRL_sciomcuclkctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_pll_ctrl : 1;
        unsigned int iomcu_pll_div_ctrl : 1;
        unsigned int iomcu_sys_div_ctrl : 1;
        unsigned int gt_iomcu_pll_div_stat : 1;
        unsigned int gt_iomcu_sys_div_stat : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SCTRL_SCIOMCUCLKSTAT_UNION;
#endif
#define SOC_SCTRL_SCIOMCUCLKSTAT_iomcu_pll_ctrl_START (0)
#define SOC_SCTRL_SCIOMCUCLKSTAT_iomcu_pll_ctrl_END (0)
#define SOC_SCTRL_SCIOMCUCLKSTAT_iomcu_pll_div_ctrl_START (1)
#define SOC_SCTRL_SCIOMCUCLKSTAT_iomcu_pll_div_ctrl_END (1)
#define SOC_SCTRL_SCIOMCUCLKSTAT_iomcu_sys_div_ctrl_START (2)
#define SOC_SCTRL_SCIOMCUCLKSTAT_iomcu_sys_div_ctrl_END (2)
#define SOC_SCTRL_SCIOMCUCLKSTAT_gt_iomcu_pll_div_stat_START (3)
#define SOC_SCTRL_SCIOMCUCLKSTAT_gt_iomcu_pll_div_stat_END (3)
#define SOC_SCTRL_SCIOMCUCLKSTAT_gt_iomcu_sys_div_stat_START (4)
#define SOC_SCTRL_SCIOMCUCLKSTAT_gt_iomcu_sys_div_stat_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int nmi_in : 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 29;
    } reg;
} SOC_SCTRL_SCIOMCUCTRL_UNION;
#endif
#define SOC_SCTRL_SCIOMCUCTRL_nmi_in_START (1)
#define SOC_SCTRL_SCIOMCUCTRL_nmi_in_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_sysresetreq : 1;
        unsigned int iomcu_m7_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int m7_sc_stat : 9;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int iomcu_stat : 10;
    } reg;
} SOC_SCTRL_SCIOMCUSTAT_UNION;
#endif
#define SOC_SCTRL_SCIOMCUSTAT_iomcu_sysresetreq_START (0)
#define SOC_SCTRL_SCIOMCUSTAT_iomcu_sysresetreq_END (0)
#define SOC_SCTRL_SCIOMCUSTAT_iomcu_m7_state_START (1)
#define SOC_SCTRL_SCIOMCUSTAT_iomcu_m7_state_END (3)
#define SOC_SCTRL_SCIOMCUSTAT_m7_sc_stat_START (7)
#define SOC_SCTRL_SCIOMCUSTAT_m7_sc_stat_END (15)
#define SOC_SCTRL_SCIOMCUSTAT_iomcu_stat_START (22)
#define SOC_SCTRL_SCIOMCUSTAT_iomcu_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_cmd0 : 1;
        unsigned int resource0lock_id0 : 3;
        unsigned int resource0lock_cmd1 : 1;
        unsigned int resource0lock_id1 : 3;
        unsigned int resource0lock_cmd2 : 1;
        unsigned int resource0lock_id2 : 3;
        unsigned int resource0lock_cmd3 : 1;
        unsigned int resource0lock_id3 : 3;
        unsigned int resource0lock_cmd4 : 1;
        unsigned int resource0lock_id4 : 3;
        unsigned int resource0lock_cmd5 : 1;
        unsigned int resource0lock_id5 : 3;
        unsigned int resource0lock_cmd6 : 1;
        unsigned int resource0lock_id6 : 3;
        unsigned int resource0lock_cmd7 : 1;
        unsigned int resource0lock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd0_START (0)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd0_END (0)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id0_START (1)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id0_END (3)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd1_START (4)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd1_END (4)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id1_START (5)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id1_END (7)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd2_START (8)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd2_END (8)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id2_START (9)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id2_END (11)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd3_START (12)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd3_END (12)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id3_START (13)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id3_END (15)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd4_START (16)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd4_END (16)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id4_START (17)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id4_END (19)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd5_START (20)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd5_END (20)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id5_START (21)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id5_END (23)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd6_START (24)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd6_END (24)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id6_START (25)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id6_END (27)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd7_START (28)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_cmd7_END (28)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id7_START (29)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_0_resource0lock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0unlock_cmd0 : 1;
        unsigned int resource0unlock_id0 : 3;
        unsigned int resource0unlock_cmd1 : 1;
        unsigned int resource0unlock_id1 : 3;
        unsigned int resource0unlock_cmd2 : 1;
        unsigned int resource0unlock_id2 : 3;
        unsigned int resource0unlock_cmd3 : 1;
        unsigned int resource0unlock_id3 : 3;
        unsigned int resource0unlock_cmd4 : 1;
        unsigned int resource0unlock_id4 : 3;
        unsigned int resource0unlock_cmd5 : 1;
        unsigned int resource0unlock_id5 : 3;
        unsigned int resource0unlock_cmd6 : 1;
        unsigned int resource0unlock_id6 : 3;
        unsigned int resource0unlock_cmd7 : 1;
        unsigned int resource0unlock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_UNION;
#endif
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd0_START (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd0_END (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id0_START (1)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id0_END (3)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd1_START (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd1_END (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id1_START (5)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id1_END (7)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd2_START (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd2_END (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id2_START (9)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id2_END (11)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd3_START (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd3_END (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id3_START (13)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id3_END (15)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd4_START (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd4_END (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id4_START (17)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id4_END (19)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd5_START (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd5_END (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id5_START (21)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id5_END (23)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd6_START (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd6_END (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id6_START (25)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id6_END (27)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd7_START (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_cmd7_END (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id7_START (29)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_0_resource0unlock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_st0 : 1;
        unsigned int resource0lock_st_id0 : 3;
        unsigned int resource0lock_st1 : 1;
        unsigned int resource0lock_st_id1 : 3;
        unsigned int resource0lock_st2 : 1;
        unsigned int resource0lock_st_id2 : 3;
        unsigned int resource0lock_st3 : 1;
        unsigned int resource0lock_st_id3 : 3;
        unsigned int resource0lock_st4 : 1;
        unsigned int resource0lock_st_id4 : 3;
        unsigned int resource0lock_st5 : 1;
        unsigned int resource0lock_st_id5 : 3;
        unsigned int resource0lock_st6 : 1;
        unsigned int resource0lock_st_id6 : 3;
        unsigned int resource0lock_st7 : 1;
        unsigned int resource0lock_st_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st0_START (0)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st0_END (0)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id0_START (1)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id0_END (3)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st1_START (4)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st1_END (4)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id1_START (5)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id1_END (7)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st2_START (8)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st2_END (8)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id2_START (9)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id2_END (11)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st3_START (12)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st3_END (12)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id3_START (13)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id3_END (15)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st4_START (16)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st4_END (16)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id4_START (17)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id4_END (19)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st5_START (20)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st5_END (20)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id5_START (21)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id5_END (23)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st6_START (24)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st6_END (24)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id6_START (25)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id6_END (27)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st7_START (28)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st7_END (28)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id7_START (29)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_0_resource0lock_st_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_cmd0 : 1;
        unsigned int resource0lock_id0 : 3;
        unsigned int resource0lock_cmd1 : 1;
        unsigned int resource0lock_id1 : 3;
        unsigned int resource0lock_cmd2 : 1;
        unsigned int resource0lock_id2 : 3;
        unsigned int resource0lock_cmd3 : 1;
        unsigned int resource0lock_id3 : 3;
        unsigned int resource0lock_cmd4 : 1;
        unsigned int resource0lock_id4 : 3;
        unsigned int resource0lock_cmd5 : 1;
        unsigned int resource0lock_id5 : 3;
        unsigned int resource0lock_cmd6 : 1;
        unsigned int resource0lock_id6 : 3;
        unsigned int resource0lock_cmd7 : 1;
        unsigned int resource0lock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd0_START (0)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd0_END (0)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id0_START (1)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id0_END (3)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd1_START (4)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd1_END (4)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id1_START (5)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id1_END (7)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd2_START (8)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd2_END (8)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id2_START (9)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id2_END (11)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd3_START (12)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd3_END (12)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id3_START (13)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id3_END (15)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd4_START (16)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd4_END (16)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id4_START (17)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id4_END (19)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd5_START (20)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd5_END (20)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id5_START (21)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id5_END (23)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd6_START (24)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd6_END (24)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id6_START (25)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id6_END (27)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd7_START (28)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_cmd7_END (28)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id7_START (29)
#define SOC_SCTRL_SC_LOCK_CFG_UNSEC_1_resource0lock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0unlock_cmd0 : 1;
        unsigned int resource0unlock_id0 : 3;
        unsigned int resource0unlock_cmd1 : 1;
        unsigned int resource0unlock_id1 : 3;
        unsigned int resource0unlock_cmd2 : 1;
        unsigned int resource0unlock_id2 : 3;
        unsigned int resource0unlock_cmd3 : 1;
        unsigned int resource0unlock_id3 : 3;
        unsigned int resource0unlock_cmd4 : 1;
        unsigned int resource0unlock_id4 : 3;
        unsigned int resource0unlock_cmd5 : 1;
        unsigned int resource0unlock_id5 : 3;
        unsigned int resource0unlock_cmd6 : 1;
        unsigned int resource0unlock_id6 : 3;
        unsigned int resource0unlock_cmd7 : 1;
        unsigned int resource0unlock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_UNION;
#endif
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd0_START (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd0_END (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id0_START (1)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id0_END (3)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd1_START (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd1_END (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id1_START (5)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id1_END (7)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd2_START (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd2_END (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id2_START (9)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id2_END (11)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd3_START (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd3_END (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id3_START (13)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id3_END (15)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd4_START (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd4_END (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id4_START (17)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id4_END (19)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd5_START (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd5_END (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id5_START (21)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id5_END (23)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd6_START (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd6_END (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id6_START (25)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id6_END (27)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd7_START (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_cmd7_END (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id7_START (29)
#define SOC_SCTRL_SC_UNLOCK_CFG_UNSEC_1_resource0unlock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_st0 : 1;
        unsigned int resource0lock_st_id0 : 3;
        unsigned int resource0lock_st1 : 1;
        unsigned int resource0lock_st_id1 : 3;
        unsigned int resource0lock_st2 : 1;
        unsigned int resource0lock_st_id2 : 3;
        unsigned int resource0lock_st3 : 1;
        unsigned int resource0lock_st_id3 : 3;
        unsigned int resource0lock_st4 : 1;
        unsigned int resource0lock_st_id4 : 3;
        unsigned int resource0lock_st5 : 1;
        unsigned int resource0lock_st_id5 : 3;
        unsigned int resource0lock_st6 : 1;
        unsigned int resource0lock_st_id6 : 3;
        unsigned int resource0lock_st7 : 1;
        unsigned int resource0lock_st_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st0_START (0)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st0_END (0)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id0_START (1)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id0_END (3)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st1_START (4)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st1_END (4)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id1_START (5)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id1_END (7)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st2_START (8)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st2_END (8)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id2_START (9)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id2_END (11)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st3_START (12)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st3_END (12)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id3_START (13)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id3_END (15)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st4_START (16)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st4_END (16)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id4_START (17)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id4_END (19)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st5_START (20)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st5_END (20)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id5_START (21)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id5_END (23)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st6_START (24)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st6_END (24)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id6_START (25)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id6_END (27)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st7_START (28)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st7_END (28)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id7_START (29)
#define SOC_SCTRL_SC_LOCK_STAT_UNSEC_1_resource0lock_st_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 31;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SCTRL_SCMDMADDR0_NONSEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 31;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SCTRL_SCMDMADDR1_NONSEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 31;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SCTRL_SCMDMADDR2_NONSEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 31;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SCTRL_SCMDMADDR3_NONSEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_cmd0 : 1;
        unsigned int resource0lock_id0 : 3;
        unsigned int resource0lock_cmd1 : 1;
        unsigned int resource0lock_id1 : 3;
        unsigned int resource0lock_cmd2 : 1;
        unsigned int resource0lock_id2 : 3;
        unsigned int resource0lock_cmd3 : 1;
        unsigned int resource0lock_id3 : 3;
        unsigned int resource0lock_cmd4 : 1;
        unsigned int resource0lock_id4 : 3;
        unsigned int resource0lock_cmd5 : 1;
        unsigned int resource0lock_id5 : 3;
        unsigned int resource0lock_cmd6 : 1;
        unsigned int resource0lock_id6 : 3;
        unsigned int resource0lock_cmd7 : 1;
        unsigned int resource0lock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_CFG_SEC_0_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd0_START (0)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd0_END (0)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id0_START (1)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id0_END (3)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd1_START (4)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd1_END (4)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id1_START (5)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id1_END (7)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd2_START (8)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd2_END (8)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id2_START (9)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id2_END (11)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd3_START (12)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd3_END (12)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id3_START (13)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id3_END (15)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd4_START (16)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd4_END (16)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id4_START (17)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id4_END (19)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd5_START (20)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd5_END (20)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id5_START (21)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id5_END (23)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd6_START (24)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd6_END (24)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id6_START (25)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id6_END (27)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd7_START (28)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_cmd7_END (28)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id7_START (29)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_0_resource0lock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0unlock_cmd0 : 1;
        unsigned int resource0unlock_id0 : 3;
        unsigned int resource0unlock_cmd1 : 1;
        unsigned int resource0unlock_id1 : 3;
        unsigned int resource0unlock_cmd2 : 1;
        unsigned int resource0unlock_id2 : 3;
        unsigned int resource0unlock_cmd3 : 1;
        unsigned int resource0unlock_id3 : 3;
        unsigned int resource0unlock_cmd4 : 1;
        unsigned int resource0unlock_id4 : 3;
        unsigned int resource0unlock_cmd5 : 1;
        unsigned int resource0unlock_id5 : 3;
        unsigned int resource0unlock_cmd6 : 1;
        unsigned int resource0unlock_id6 : 3;
        unsigned int resource0unlock_cmd7 : 1;
        unsigned int resource0unlock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_UNION;
#endif
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd0_START (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd0_END (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id0_START (1)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id0_END (3)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd1_START (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd1_END (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id1_START (5)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id1_END (7)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd2_START (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd2_END (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id2_START (9)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id2_END (11)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd3_START (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd3_END (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id3_START (13)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id3_END (15)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd4_START (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd4_END (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id4_START (17)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id4_END (19)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd5_START (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd5_END (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id5_START (21)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id5_END (23)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd6_START (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd6_END (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id6_START (25)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id6_END (27)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd7_START (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_cmd7_END (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id7_START (29)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_0_resource0unlock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_st0 : 1;
        unsigned int resource0lock_st_id0 : 3;
        unsigned int resource0lock_st1 : 1;
        unsigned int resource0lock_st_id1 : 3;
        unsigned int resource0lock_st2 : 1;
        unsigned int resource0lock_st_id2 : 3;
        unsigned int resource0lock_st3 : 1;
        unsigned int resource0lock_st_id3 : 3;
        unsigned int resource0lock_st4 : 1;
        unsigned int resource0lock_st_id4 : 3;
        unsigned int resource0lock_st5 : 1;
        unsigned int resource0lock_st_id5 : 3;
        unsigned int resource0lock_st6 : 1;
        unsigned int resource0lock_st_id6 : 3;
        unsigned int resource0lock_st7 : 1;
        unsigned int resource0lock_st_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_STAT_SEC_0_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st0_START (0)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st0_END (0)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id0_START (1)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id0_END (3)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st1_START (4)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st1_END (4)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id1_START (5)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id1_END (7)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st2_START (8)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st2_END (8)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id2_START (9)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id2_END (11)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st3_START (12)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st3_END (12)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id3_START (13)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id3_END (15)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st4_START (16)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st4_END (16)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id4_START (17)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id4_END (19)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st5_START (20)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st5_END (20)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id5_START (21)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id5_END (23)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st6_START (24)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st6_END (24)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id6_START (25)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id6_END (27)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st7_START (28)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st7_END (28)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id7_START (29)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_0_resource0lock_st_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_cmd0 : 1;
        unsigned int resource0lock_id0 : 3;
        unsigned int resource0lock_cmd1 : 1;
        unsigned int resource0lock_id1 : 3;
        unsigned int resource0lock_cmd2 : 1;
        unsigned int resource0lock_id2 : 3;
        unsigned int resource0lock_cmd3 : 1;
        unsigned int resource0lock_id3 : 3;
        unsigned int resource0lock_cmd4 : 1;
        unsigned int resource0lock_id4 : 3;
        unsigned int resource0lock_cmd5 : 1;
        unsigned int resource0lock_id5 : 3;
        unsigned int resource0lock_cmd6 : 1;
        unsigned int resource0lock_id6 : 3;
        unsigned int resource0lock_cmd7 : 1;
        unsigned int resource0lock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_CFG_SEC_1_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd0_START (0)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd0_END (0)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id0_START (1)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id0_END (3)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd1_START (4)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd1_END (4)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id1_START (5)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id1_END (7)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd2_START (8)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd2_END (8)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id2_START (9)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id2_END (11)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd3_START (12)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd3_END (12)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id3_START (13)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id3_END (15)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd4_START (16)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd4_END (16)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id4_START (17)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id4_END (19)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd5_START (20)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd5_END (20)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id5_START (21)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id5_END (23)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd6_START (24)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd6_END (24)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id6_START (25)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id6_END (27)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd7_START (28)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_cmd7_END (28)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id7_START (29)
#define SOC_SCTRL_SC_LOCK_CFG_SEC_1_resource0lock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0unlock_cmd0 : 1;
        unsigned int resource0unlock_id0 : 3;
        unsigned int resource0unlock_cmd1 : 1;
        unsigned int resource0unlock_id1 : 3;
        unsigned int resource0unlock_cmd2 : 1;
        unsigned int resource0unlock_id2 : 3;
        unsigned int resource0unlock_cmd3 : 1;
        unsigned int resource0unlock_id3 : 3;
        unsigned int resource0unlock_cmd4 : 1;
        unsigned int resource0unlock_id4 : 3;
        unsigned int resource0unlock_cmd5 : 1;
        unsigned int resource0unlock_id5 : 3;
        unsigned int resource0unlock_cmd6 : 1;
        unsigned int resource0unlock_id6 : 3;
        unsigned int resource0unlock_cmd7 : 1;
        unsigned int resource0unlock_id7 : 3;
    } reg;
} SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_UNION;
#endif
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd0_START (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd0_END (0)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id0_START (1)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id0_END (3)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd1_START (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd1_END (4)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id1_START (5)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id1_END (7)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd2_START (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd2_END (8)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id2_START (9)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id2_END (11)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd3_START (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd3_END (12)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id3_START (13)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id3_END (15)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd4_START (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd4_END (16)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id4_START (17)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id4_END (19)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd5_START (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd5_END (20)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id5_START (21)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id5_END (23)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd6_START (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd6_END (24)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id6_START (25)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id6_END (27)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd7_START (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_cmd7_END (28)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id7_START (29)
#define SOC_SCTRL_SC_UNLOCK_CFG_SEC_1_resource0unlock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int resource0lock_st0 : 1;
        unsigned int resource0lock_st_id0 : 3;
        unsigned int resource0lock_st1 : 1;
        unsigned int resource0lock_st_id1 : 3;
        unsigned int resource0lock_st2 : 1;
        unsigned int resource0lock_st_id2 : 3;
        unsigned int resource0lock_st3 : 1;
        unsigned int resource0lock_st_id3 : 3;
        unsigned int resource0lock_st4 : 1;
        unsigned int resource0lock_st_id4 : 3;
        unsigned int resource0lock_st5 : 1;
        unsigned int resource0lock_st_id5 : 3;
        unsigned int resource0lock_st6 : 1;
        unsigned int resource0lock_st_id6 : 3;
        unsigned int resource0lock_st7 : 1;
        unsigned int resource0lock_st_id7 : 3;
    } reg;
} SOC_SCTRL_SC_LOCK_STAT_SEC_1_UNION;
#endif
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st0_START (0)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st0_END (0)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id0_START (1)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id0_END (3)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st1_START (4)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st1_END (4)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id1_START (5)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id1_END (7)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st2_START (8)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st2_END (8)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id2_START (9)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id2_END (11)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st3_START (12)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st3_END (12)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id3_START (13)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id3_END (15)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st4_START (16)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st4_END (16)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id4_START (17)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id4_END (19)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st5_START (20)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st5_END (20)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id5_START (21)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id5_END (23)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st6_START (24)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st6_END (24)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id6_START (25)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id6_END (27)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st7_START (28)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st7_END (28)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id7_START (29)
#define SOC_SCTRL_SC_LOCK_STAT_SEC_1_resource0lock_st_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 29;
    } reg;
} SOC_SCTRL_SCJTAG_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_djtag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCTRL_SCCFG_DJTAG_UNION;
#endif
#define SOC_SCTRL_SCCFG_DJTAG_cfg_djtag_START (0)
#define SOC_SCTRL_SCCFG_DJTAG_cfg_djtag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_cp15disable0 : 1;
        unsigned int a53_cp15disable1 : 1;
        unsigned int a53_cp15disable2 : 1;
        unsigned int a53_cp15disable3 : 1;
        unsigned int a57_cp15disable0 : 1;
        unsigned int a57_cp15disable1 : 1;
        unsigned int a57_cp15disable2 : 1;
        unsigned int a57_cp15disable3 : 1;
        unsigned int ispa7cp15disable : 1;
        unsigned int gicdisable : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_SCTRL_SCCP15_DISABLE_UNION;
#endif
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable0_START (0)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable0_END (0)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable1_START (1)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable1_END (1)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable2_START (2)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable2_END (2)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable3_START (3)
#define SOC_SCTRL_SCCP15_DISABLE_a53_cp15disable3_END (3)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable0_START (4)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable0_END (4)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable1_START (5)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable1_END (5)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable2_START (6)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable2_END (6)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable3_START (7)
#define SOC_SCTRL_SCCP15_DISABLE_a57_cp15disable3_END (7)
#define SOC_SCTRL_SCCP15_DISABLE_ispa7cp15disable_START (8)
#define SOC_SCTRL_SCCP15_DISABLE_ispa7cp15disable_END (8)
#define SOC_SCTRL_SCCP15_DISABLE_gicdisable_START (9)
#define SOC_SCTRL_SCCP15_DISABLE_gicdisable_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_arm_dbgen : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCTRL_SCCFG_ARM_DBGEN_UNION;
#endif
#define SOC_SCTRL_SCCFG_ARM_DBGEN_cfg_arm_dbgen_START (0)
#define SOC_SCTRL_SCCFG_ARM_DBGEN_cfg_arm_dbgen_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbgen_wr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCTRL_SCARM_DBGEN_STAT_UNION;
#endif
#define SOC_SCTRL_SCARM_DBGEN_STAT_arm_dbgen_wr_START (0)
#define SOC_SCTRL_SCARM_DBGEN_STAT_arm_dbgen_wr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_efuse_pad_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCTRL_SCEFUSECTRL_UNION;
#endif
#define SOC_SCTRL_SCEFUSECTRL_sys_efuse_pad_sel_START (0)
#define SOC_SCTRL_SCEFUSECTRL_sys_efuse_pad_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_SCTRL_SCEFUSESEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int CHIP_ID0 : 32;
    } reg;
} SOC_SCTRL_SCCHIP_ID0_UNION;
#endif
#define SOC_SCTRL_SCCHIP_ID0_CHIP_ID0_START (0)
#define SOC_SCTRL_SCCHIP_ID0_CHIP_ID0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int CHIP_ID1 : 32;
    } reg;
} SOC_SCTRL_SCCHIP_ID1_UNION;
#endif
#define SOC_SCTRL_SCCHIP_ID1_CHIP_ID1_START (0)
#define SOC_SCTRL_SCCHIP_ID1_CHIP_ID1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a53_cryptodisable : 3;
        unsigned int a53_sc_cfg : 5;
        unsigned int reserved : 24;
    } reg;
} SOC_SCTRL_SCCPUSECCTRL_UNION;
#endif
#define SOC_SCTRL_SCCPUSECCTRL_a53_cryptodisable_START (0)
#define SOC_SCTRL_SCCPUSECCTRL_a53_cryptodisable_END (2)
#define SOC_SCTRL_SCCPUSECCTRL_a53_sc_cfg_START (3)
#define SOC_SCTRL_SCCPUSECCTRL_a53_sc_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int isp_cryptodisable : 3;
        unsigned int isp_sc_cfg : 5;
        unsigned int reserved : 24;
    } reg;
} SOC_SCTRL_SCISPSECCTRL_UNION;
#endif
#define SOC_SCTRL_SCISPSECCTRL_isp_cryptodisable_START (0)
#define SOC_SCTRL_SCISPSECCTRL_isp_cryptodisable_END (2)
#define SOC_SCTRL_SCISPSECCTRL_isp_sc_cfg_START (3)
#define SOC_SCTRL_SCISPSECCTRL_isp_sc_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int jtagsd_sw_sel : 8;
        unsigned int auth_pass : 1;
        unsigned int arm_dbgen_wr1 : 1;
        unsigned int jtag_sd_swd_sel : 1;
        unsigned int jtag_sd_watcher_bypass : 1;
        unsigned int jtag_sd_watcher_tms_tie1 : 1;
        unsigned int reserved : 12;
        unsigned int jtag_sim_hwselmd : 2;
        unsigned int jtag_sd_hwselmd : 2;
        unsigned int gpio_sd_sim_sel : 1;
        unsigned int jtag_sim_mode : 1;
        unsigned int jtag_sd_mode : 1;
    } reg;
} SOC_SCTRL_SCJTAGSD_SW_SEL_UNION;
#endif
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtagsd_sw_sel_START (0)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtagsd_sw_sel_END (7)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_auth_pass_START (8)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_auth_pass_END (8)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_arm_dbgen_wr1_START (9)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_arm_dbgen_wr1_END (9)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_swd_sel_START (10)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_swd_sel_END (10)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_watcher_bypass_START (11)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_watcher_bypass_END (11)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_watcher_tms_tie1_START (12)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_watcher_tms_tie1_END (12)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sim_hwselmd_START (25)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sim_hwselmd_END (26)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_hwselmd_START (27)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_hwselmd_END (28)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_gpio_sd_sim_sel_START (29)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_gpio_sd_sim_sel_END (29)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sim_mode_START (30)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sim_mode_END (30)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_mode_START (31)
#define SOC_SCTRL_SCJTAGSD_SW_SEL_jtag_sd_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int jtagsys_sw_sel : 8;
        unsigned int jtag_sys_swd_sel : 1;
        unsigned int jtag_sys_watcher_bypass : 1;
        unsigned int jtag_sys_watcher_tms_tie1 : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SCTRL_SCJTAGSYS_SW_SEL_UNION;
#endif
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtagsys_sw_sel_START (0)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtagsys_sw_sel_END (7)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtag_sys_swd_sel_START (8)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtag_sys_swd_sel_END (8)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtag_sys_watcher_bypass_START (9)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtag_sys_watcher_bypass_END (9)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtag_sys_watcher_tms_tie1_START (10)
#define SOC_SCTRL_SCJTAGSYS_SW_SEL_jtag_sys_watcher_tms_tie1_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCJTAG_SD_SWD2JTAG_DFX_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCJTAG_SYS_SWD2JTAG_DFX_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_iomcu_enable_syscache_gen : 1;
        unsigned int intr_iomcu_enable_syscache_clr : 1;
        unsigned int intr_iomcu_enable_syscache_msk : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_iomcu_enable_syscache_raw : 1;
        unsigned int intr_iomcu_enable_syscache_stat : 1;
        unsigned int reserved_1 : 2;
        unsigned int intr_iomcu_disable_syscache_gen : 1;
        unsigned int intr_iomcu_disable_syscache_clr : 1;
        unsigned int intr_iomcu_disable_syscache_msk : 1;
        unsigned int reserved_2 : 1;
        unsigned int intr_iomcu_disable_syscache_raw : 1;
        unsigned int intr_iomcu_disable_syscache_stat : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_SCTRL_SC_INTR_SYSCACHE_SEC_UNION;
#endif
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_gen_START (0)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_gen_END (0)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_clr_START (1)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_clr_END (1)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_msk_START (2)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_msk_END (2)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_raw_START (4)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_raw_END (4)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_stat_START (5)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_enable_syscache_stat_END (5)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_gen_START (8)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_gen_END (8)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_clr_START (9)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_clr_END (9)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_msk_START (10)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_msk_END (10)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_raw_START (12)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_raw_END (12)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_stat_START (13)
#define SOC_SCTRL_SC_INTR_SYSCACHE_SEC_intr_iomcu_disable_syscache_stat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key0 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY0_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY0_arm_dbg_key0_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY0_arm_dbg_key0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key1 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY1_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY1_arm_dbg_key1_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY1_arm_dbg_key1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key2 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY2_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY2_arm_dbg_key2_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY2_arm_dbg_key2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key3 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY3_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY3_arm_dbg_key3_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY3_arm_dbg_key3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key4 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY4_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY4_arm_dbg_key4_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY4_arm_dbg_key4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key5 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY5_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY5_arm_dbg_key5_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY5_arm_dbg_key5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key6 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY6_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY6_arm_dbg_key6_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY6_arm_dbg_key6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arm_dbg_key7 : 32;
    } reg;
} SOC_SCTRL_SCARM_DBG_KEY7_UNION;
#endif
#define SOC_SCTRL_SCARM_DBG_KEY7_arm_dbg_key7_START (0)
#define SOC_SCTRL_SCARM_DBG_KEY7_arm_dbg_key7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi1_avs_addr0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMI1_ADDR0_UNION;
#endif
#define SOC_SCTRL_SCSPMI1_ADDR0_spmi1_avs_addr0_START (0)
#define SOC_SCTRL_SCSPMI1_ADDR0_spmi1_avs_addr0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR0_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR0_spmi_avs_addr0_START (0)
#define SOC_SCTRL_SCSPMIADDR0_spmi_avs_addr0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR1_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR1_spmi_avs_addr1_START (0)
#define SOC_SCTRL_SCSPMIADDR1_spmi_avs_addr1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR2_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR2_spmi_avs_addr2_START (0)
#define SOC_SCTRL_SCSPMIADDR2_spmi_avs_addr2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR3_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR3_spmi_avs_addr3_START (0)
#define SOC_SCTRL_SCSPMIADDR3_spmi_avs_addr3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR4_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR4_spmi_avs_addr4_START (0)
#define SOC_SCTRL_SCSPMIADDR4_spmi_avs_addr4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR5_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR5_spmi_avs_addr5_START (0)
#define SOC_SCTRL_SCSPMIADDR5_spmi_avs_addr5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR6_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR6_spmi_avs_addr6_START (0)
#define SOC_SCTRL_SCSPMIADDR6_spmi_avs_addr6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR7_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR7_spmi_avs_addr7_START (0)
#define SOC_SCTRL_SCSPMIADDR7_spmi_avs_addr7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr8 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR8_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR8_spmi_avs_addr8_START (0)
#define SOC_SCTRL_SCSPMIADDR8_spmi_avs_addr8_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr9 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR9_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR9_spmi_avs_addr9_START (0)
#define SOC_SCTRL_SCSPMIADDR9_spmi_avs_addr9_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr10 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR10_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR10_spmi_avs_addr10_START (0)
#define SOC_SCTRL_SCSPMIADDR10_spmi_avs_addr10_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr11 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR11_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR11_spmi_avs_addr11_START (0)
#define SOC_SCTRL_SCSPMIADDR11_spmi_avs_addr11_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr12 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR12_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR12_spmi_avs_addr12_START (0)
#define SOC_SCTRL_SCSPMIADDR12_spmi_avs_addr12_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr13 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR13_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR13_spmi_avs_addr13_START (0)
#define SOC_SCTRL_SCSPMIADDR13_spmi_avs_addr13_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr14 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR14_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR14_spmi_avs_addr14_START (0)
#define SOC_SCTRL_SCSPMIADDR14_spmi_avs_addr14_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spmi_avs_addr15 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SCTRL_SCSPMIADDR15_UNION;
#endif
#define SOC_SCTRL_SCSPMIADDR15_spmi_avs_addr15_START (0)
#define SOC_SCTRL_SCSPMIADDR15_spmi_avs_addr15_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCHISEEGPIOLOCK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCHISEESPILOCK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCHISEEI2CLOCK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisee_gpio1_io_sel : 1;
        unsigned int hisee_gpio2_io_sel : 1;
        unsigned int hisee_gpio3_io_sel : 1;
        unsigned int hisee_spi_io_sel : 1;
        unsigned int hisee_i2c_io_sel : 1;
        unsigned int reserved_0 : 26;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SCTRL_SCHISEEIOSEL_UNION;
#endif
#define SOC_SCTRL_SCHISEEIOSEL_hisee_gpio1_io_sel_START (0)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_gpio1_io_sel_END (0)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_gpio2_io_sel_START (1)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_gpio2_io_sel_END (1)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_gpio3_io_sel_START (2)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_gpio3_io_sel_END (2)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_spi_io_sel_START (3)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_spi_io_sel_END (3)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_i2c_io_sel_START (4)
#define SOC_SCTRL_SCHISEEIOSEL_hisee_i2c_io_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 2;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 13;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 2;
        unsigned int reserved_9: 4;
        unsigned int reserved_10: 4;
    } reg;
} SOC_SCTRL_SCPERCTRL0_SEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 19;
        unsigned int reserved_2: 7;
    } reg;
} SOC_SCTRL_SCPERCTRL1_SEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_arc_dbg_port_sel : 1;
        unsigned int lpmcu_arc_halt_req_a : 1;
        unsigned int lpmcu_arc_run_req_a : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 8;
        unsigned int scperctrl2_sec_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL2_SEC_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL2_SEC_lpmcu_arc_dbg_port_sel_START (0)
#define SOC_SCTRL_SCPERCTRL2_SEC_lpmcu_arc_dbg_port_sel_END (0)
#define SOC_SCTRL_SCPERCTRL2_SEC_lpmcu_arc_halt_req_a_START (1)
#define SOC_SCTRL_SCPERCTRL2_SEC_lpmcu_arc_halt_req_a_END (1)
#define SOC_SCTRL_SCPERCTRL2_SEC_lpmcu_arc_run_req_a_START (2)
#define SOC_SCTRL_SCPERCTRL2_SEC_lpmcu_arc_run_req_a_END (2)
#define SOC_SCTRL_SCPERCTRL2_SEC_scperctrl2_sec_msk_START (16)
#define SOC_SCTRL_SCPERCTRL2_SEC_scperctrl2_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 3;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 28;
    } reg;
} SOC_SCTRL_SCPERCTRL3_SEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisee_gpio1_ack : 4;
        unsigned int hisee_gpio2_ack : 4;
        unsigned int hisee_gpio3_ack : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_SCTRL_SCPERCTRL4_SEC_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL4_SEC_hisee_gpio1_ack_START (0)
#define SOC_SCTRL_SCPERCTRL4_SEC_hisee_gpio1_ack_END (3)
#define SOC_SCTRL_SCPERCTRL4_SEC_hisee_gpio2_ack_START (4)
#define SOC_SCTRL_SCPERCTRL4_SEC_hisee_gpio2_ack_END (7)
#define SOC_SCTRL_SCPERCTRL4_SEC_hisee_gpio3_ack_START (8)
#define SOC_SCTRL_SCPERCTRL4_SEC_hisee_gpio3_ack_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 4;
        unsigned int iomcu_debug_sel : 1;
        unsigned int scperctrl5_sec_msk : 16;
    } reg;
} SOC_SCTRL_SCPERCTRL5_SEC_UNION;
#endif
#define SOC_SCTRL_SCPERCTRL5_SEC_iomcu_debug_sel_START (15)
#define SOC_SCTRL_SCPERCTRL5_SEC_iomcu_debug_sel_END (15)
#define SOC_SCTRL_SCPERCTRL5_SEC_scperctrl5_sec_msk_START (16)
#define SOC_SCTRL_SCPERCTRL5_SEC_scperctrl5_sec_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arc_run_ack : 1;
        unsigned int arc_halt_ack : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 8;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 9;
        unsigned int reserved_12 : 1;
    } reg;
} SOC_SCTRL_SCPERSTATUS0_SEC_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS0_SEC_arc_run_ack_START (0)
#define SOC_SCTRL_SCPERSTATUS0_SEC_arc_run_ack_END (0)
#define SOC_SCTRL_SCPERSTATUS0_SEC_arc_halt_ack_START (1)
#define SOC_SCTRL_SCPERSTATUS0_SEC_arc_halt_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hisee_reserve_out_bit2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCTRL_SCPERSTATUS1_SEC_UNION;
#endif
#define SOC_SCTRL_SCPERSTATUS1_SEC_hisee_reserve_out_bit2_START (0)
#define SOC_SCTRL_SCPERSTATUS1_SEC_hisee_reserve_out_bit2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTATUS2_SEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTATUS3_SEC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vote_req_0 : 7;
        unsigned int vote_en_0 : 1;
        unsigned int vote_req_1 : 7;
        unsigned int vote_en_1 : 1;
        unsigned int sc_tcp_vote_req_0_msk : 16;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_REQ_0_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_req_0_START (0)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_req_0_END (6)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_en_0_START (7)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_en_0_END (7)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_req_1_START (8)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_req_1_END (14)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_en_1_START (15)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_vote_en_1_END (15)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_sc_tcp_vote_req_0_msk_START (16)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_0_sc_tcp_vote_req_0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vote_close_req_0 : 1;
        unsigned int vote_open_req_0 : 1;
        unsigned int vote_close_ack_sync_0 : 1;
        unsigned int vote_open_ack_sync_0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int cur_path_stat_0 : 3;
        unsigned int vote_close_req_1 : 1;
        unsigned int vote_open_req_1 : 1;
        unsigned int vote_close_ack_sync_1 : 1;
        unsigned int vote_open_ack_sync_1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cur_path_stat_1 : 3;
        unsigned int vote_close_req_2 : 1;
        unsigned int vote_open_req_2 : 1;
        unsigned int vote_close_ack_sync_2 : 1;
        unsigned int vote_open_ack_sync_2 : 1;
        unsigned int reserved_2 : 1;
        unsigned int cur_path_stat_2 : 3;
        unsigned int vote_close_req_3 : 1;
        unsigned int vote_open_req_3 : 1;
        unsigned int vote_close_ack_sync_3 : 1;
        unsigned int vote_open_ack_sync_3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int cur_path_stat_3 : 3;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_STAT_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_0_START (0)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_0_END (0)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_0_START (1)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_0_END (1)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_0_START (2)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_0_END (2)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_0_START (3)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_0_END (3)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_0_START (5)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_0_END (7)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_1_START (8)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_1_END (8)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_1_START (9)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_1_END (9)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_1_START (10)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_1_END (10)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_1_START (11)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_1_END (11)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_1_START (13)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_1_END (15)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_2_START (16)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_2_END (16)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_2_START (17)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_2_END (17)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_2_START (18)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_2_END (18)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_2_START (19)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_2_END (19)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_2_START (21)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_2_END (23)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_3_START (24)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_req_3_END (24)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_3_START (25)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_req_3_END (25)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_3_START (26)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_close_ack_sync_3_END (26)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_3_START (27)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_vote_open_ack_sync_3_END (27)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_3_START (29)
#define SOC_SCTRL_SC_TCP_VOTE_STAT_cur_path_stat_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tcp_busy_stat_sync : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int int_wakeup_sys_ff2 : 1;
        unsigned int reserved_6 : 1;
        unsigned int mad_int_sync : 1;
        unsigned int reserved_7 : 21;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_CTRL0_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_tcp_busy_stat_sync_START (4)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_tcp_busy_stat_sync_END (4)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_int_wakeup_sys_ff2_START (7)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_int_wakeup_sys_ff2_END (7)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_mad_int_sync_START (9)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL0_mad_int_sync_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vote_req_2 : 7;
        unsigned int vote_en_2 : 1;
        unsigned int vote_req_3 : 7;
        unsigned int vote_en_3 : 1;
        unsigned int sc_tcp_vote_req_1_msk : 16;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_REQ_1_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_req_2_START (0)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_req_2_END (6)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_en_2_START (7)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_en_2_END (7)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_req_3_START (8)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_req_3_END (14)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_en_3_START (15)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_vote_en_3_END (15)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_sc_tcp_vote_req_1_msk_START (16)
#define SOC_SCTRL_SC_TCP_VOTE_REQ_1_sc_tcp_vote_req_1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vote_mng_sw2_path_open_req_0 : 1;
        unsigned int vote_mng_sw2_path_close_req_0 : 1;
        unsigned int vote_mng_sw2_path_open_req_1 : 1;
        unsigned int vote_mng_sw2_path_close_req_1 : 1;
        unsigned int vote_mng_sw2_path_open_req_2 : 1;
        unsigned int vote_mng_sw2_path_close_req_2 : 1;
        unsigned int vote_mng_sw2_path_open_req_3 : 1;
        unsigned int vote_mng_sw2_path_close_req_3 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_CTRL1_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_0_START (0)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_0_END (0)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_0_START (1)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_0_END (1)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_1_START (2)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_1_END (2)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_1_START (3)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_1_END (3)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_2_START (4)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_2_END (4)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_2_START (5)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_2_END (5)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_3_START (6)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_open_req_3_END (6)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_3_START (7)
#define SOC_SCTRL_SC_TCP_VOTE_CTRL1_vote_mng_sw2_path_close_req_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vote_req_3_add0 : 16;
        unsigned int sc_tcp_vote_req3_add0_msk : 16;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_vote_req_3_add0_START (0)
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_vote_req_3_add0_END (15)
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_sc_tcp_vote_req3_add0_msk_START (16)
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD0_sc_tcp_vote_req3_add0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vote_req_3_add1 : 16;
        unsigned int sc_tcp_vote_req3_add1_msk : 16;
    } reg;
} SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_UNION;
#endif
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_vote_req_3_add1_START (0)
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_vote_req_3_add1_END (15)
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_sc_tcp_vote_req3_add1_msk_START (16)
#define SOC_SCTRL_SC_TCP_VOTE_REQ3_ADD1_sc_tcp_vote_req3_add1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int version_code : 16;
        unsigned int chip_code : 16;
    } reg;
} SOC_SCTRL_SCSOCID0_UNION;
#endif
#define SOC_SCTRL_SCSOCID0_version_code_START (0)
#define SOC_SCTRL_SCSOCID0_version_code_END (15)
#define SOC_SCTRL_SCSOCID0_chip_code_START (16)
#define SOC_SCTRL_SCSOCID0_chip_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SCPERSTAT_POR_RESERVED3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpdata : 32;
    } reg;
} SOC_SCTRL_SC_NPU_LPCTRL0_SEC_UNION;
#endif
#define SOC_SCTRL_SC_NPU_LPCTRL0_SEC_lpdata_START (0)
#define SOC_SCTRL_SC_NPU_LPCTRL0_SEC_lpdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpdata : 32;
    } reg;
} SOC_SCTRL_SC_NPU_LPCTRL1_SEC_UNION;
#endif
#define SOC_SCTRL_SC_NPU_LPCTRL1_SEC_lpdata_START (0)
#define SOC_SCTRL_SC_NPU_LPCTRL1_SEC_lpdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpdata : 32;
    } reg;
} SOC_SCTRL_SC_NPU_LPCTRL2_SEC_UNION;
#endif
#define SOC_SCTRL_SC_NPU_LPCTRL2_SEC_lpdata_START (0)
#define SOC_SCTRL_SC_NPU_LPCTRL2_SEC_lpdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpdata : 32;
    } reg;
} SOC_SCTRL_SC_NPU_LPCTRL3_SEC_UNION;
#endif
#define SOC_SCTRL_SC_NPU_LPCTRL3_SEC_lpdata_START (0)
#define SOC_SCTRL_SC_NPU_LPCTRL3_SEC_lpdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpdata : 32;
    } reg;
} SOC_SCTRL_SC_NPU_LPCTRL4_SEC_UNION;
#endif
#define SOC_SCTRL_SC_NPU_LPCTRL4_SEC_lpdata_START (0)
#define SOC_SCTRL_SC_NPU_LPCTRL4_SEC_lpdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SC_TRACKING_LOG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SC_TRACKING_LOG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SC_TRACKING_LOG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SCTRL_SC_TRACKING_LOG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_emu_version : 32;
    } reg;
} SOC_SCTRL_SC_EMU_VERSION_UNION;
#endif
#define SOC_SCTRL_SC_EMU_VERSION_sc_emu_version_START (0)
#define SOC_SCTRL_SC_EMU_VERSION_sc_emu_version_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
