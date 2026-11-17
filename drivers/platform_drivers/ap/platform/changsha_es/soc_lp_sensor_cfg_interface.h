#ifndef __SOC_LP_SENSOR_CFG_INTERFACE_H__
#define __SOC_LP_SENSOR_CFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_ADDR(base) (base)
#define SOC_LP_SENSOR_CFG_PEREN0_ADDR(base) ((base) + 0x010UL)
#define SOC_LP_SENSOR_CFG_PERDIS0_ADDR(base) ((base) + 0x014UL)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_ADDR(base) ((base) + 0x018UL)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_ADDR(base) ((base) + 0x01CUL)
#define SOC_LP_SENSOR_CFG_PEREN1_ADDR(base) ((base) + 0x020UL)
#define SOC_LP_SENSOR_CFG_PERDIS1_ADDR(base) ((base) + 0x024UL)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_ADDR(base) ((base) + 0x028UL)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_ADDR(base) ((base) + 0x02CUL)
#define SOC_LP_SENSOR_CFG_RSTEN0_ADDR(base) ((base) + 0x040UL)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ADDR(base) ((base) + 0x044UL)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ADDR(base) ((base) + 0x048UL)
#define SOC_LP_SENSOR_CFG_RSTEN1_ADDR(base) ((base) + 0x050UL)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ADDR(base) ((base) + 0x054UL)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ADDR(base) ((base) + 0x058UL)
#define SOC_LP_SENSOR_CFG_HPM0_EN_ADDR(base) ((base) + 0x110UL)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_ADDR(base) ((base) + 0x114UL)
#define SOC_LP_SENSOR_CFG_HPM0_OPC2_ADDR(base) ((base) + 0x118UL)
#define SOC_LP_SENSOR_CFG_HPM1_EN_ADDR(base) ((base) + 0x120UL)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_ADDR(base) ((base) + 0x124UL)
#define SOC_LP_SENSOR_CFG_HPM1_OPC2_ADDR(base) ((base) + 0x128UL)
#define SOC_LP_SENSOR_CFG_HPM2_EN_ADDR(base) ((base) + 0x130UL)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_ADDR(base) ((base) + 0x134UL)
#define SOC_LP_SENSOR_CFG_HPM2_OPC2_ADDR(base) ((base) + 0x138UL)
#define SOC_LP_SENSOR_CFG_HPM3_EN_ADDR(base) ((base) + 0x140UL)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_ADDR(base) ((base) + 0x144UL)
#define SOC_LP_SENSOR_CFG_HPM3_OPC2_ADDR(base) ((base) + 0x148UL)
#define SOC_LP_SENSOR_CFG_HPM4_EN_ADDR(base) ((base) + 0x150UL)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_ADDR(base) ((base) + 0x154UL)
#define SOC_LP_SENSOR_CFG_HPM4_OPC2_ADDR(base) ((base) + 0x158UL)
#define SOC_LP_SENSOR_CFG_HPM5_EN_ADDR(base) ((base) + 0x160UL)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_ADDR(base) ((base) + 0x164UL)
#define SOC_LP_SENSOR_CFG_HPM5_OPC2_ADDR(base) ((base) + 0x168UL)
#define SOC_LP_SENSOR_CFG_HPM6_EN_ADDR(base) ((base) + 0x170UL)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_ADDR(base) ((base) + 0x174UL)
#define SOC_LP_SENSOR_CFG_HPM6_OPC2_ADDR(base) ((base) + 0x178UL)
#define SOC_LP_SENSOR_CFG_HPM7_EN_ADDR(base) ((base) + 0x180UL)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_ADDR(base) ((base) + 0x184UL)
#define SOC_LP_SENSOR_CFG_HPM7_OPC2_ADDR(base) ((base) + 0x188UL)
#define SOC_LP_SENSOR_CFG_HPM8_EN_ADDR(base) ((base) + 0x190UL)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_ADDR(base) ((base) + 0x194UL)
#define SOC_LP_SENSOR_CFG_HPM8_OPC2_ADDR(base) ((base) + 0x198UL)
#define SOC_LP_SENSOR_CFG_HPM9_EN_ADDR(base) ((base) + 0x1A0UL)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_ADDR(base) ((base) + 0x1A4UL)
#define SOC_LP_SENSOR_CFG_HPM9_OPC2_ADDR(base) ((base) + 0x1A8UL)
#define SOC_LP_SENSOR_CFG_HPM10_EN_ADDR(base) ((base) + 0x1B0UL)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_ADDR(base) ((base) + 0x1B4UL)
#define SOC_LP_SENSOR_CFG_HPM10_OPC2_ADDR(base) ((base) + 0x1B8UL)
#define SOC_LP_SENSOR_CFG_HPM11_EN_ADDR(base) ((base) + 0x1C0UL)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_ADDR(base) ((base) + 0x1C4UL)
#define SOC_LP_SENSOR_CFG_HPM11_OPC2_ADDR(base) ((base) + 0x1C8UL)
#define SOC_LP_SENSOR_CFG_HPM12_EN_ADDR(base) ((base) + 0x1D0UL)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_ADDR(base) ((base) + 0x1D4UL)
#define SOC_LP_SENSOR_CFG_HPM12_OPC2_ADDR(base) ((base) + 0x1D8UL)
#define SOC_LP_SENSOR_CFG_HPM13_EN_ADDR(base) ((base) + 0x1E0UL)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_ADDR(base) ((base) + 0x1E4UL)
#define SOC_LP_SENSOR_CFG_HPM13_OPC2_ADDR(base) ((base) + 0x1E8UL)
#define SOC_LP_SENSOR_CFG_HPM14_EN_ADDR(base) ((base) + 0x1F0UL)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_ADDR(base) ((base) + 0x1F4UL)
#define SOC_LP_SENSOR_CFG_HPM14_OPC2_ADDR(base) ((base) + 0x1F8UL)
#define SOC_LP_SENSOR_CFG_HPM15_EN_ADDR(base) ((base) + 0x200UL)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_ADDR(base) ((base) + 0x204UL)
#define SOC_LP_SENSOR_CFG_HPM15_OPC2_ADDR(base) ((base) + 0x208UL)
#define SOC_LP_SENSOR_CFG_HPM16_EN_ADDR(base) ((base) + 0x210UL)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_ADDR(base) ((base) + 0x214UL)
#define SOC_LP_SENSOR_CFG_HPM16_OPC2_ADDR(base) ((base) + 0x218UL)
#define SOC_LP_SENSOR_CFG_HPM17_EN_ADDR(base) ((base) + 0x220UL)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_ADDR(base) ((base) + 0x224UL)
#define SOC_LP_SENSOR_CFG_HPM17_OPC2_ADDR(base) ((base) + 0x228UL)
#define SOC_LP_SENSOR_CFG_HPM18_EN_ADDR(base) ((base) + 0x230UL)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_ADDR(base) ((base) + 0x234UL)
#define SOC_LP_SENSOR_CFG_HPM18_OPC2_ADDR(base) ((base) + 0x238UL)
#define SOC_LP_SENSOR_CFG_HPM19_EN_ADDR(base) ((base) + 0x240UL)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_ADDR(base) ((base) + 0x244UL)
#define SOC_LP_SENSOR_CFG_HPM19_OPC2_ADDR(base) ((base) + 0x248UL)
#define SOC_LP_SENSOR_CFG_HPM20_EN_ADDR(base) ((base) + 0x250UL)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_ADDR(base) ((base) + 0x254UL)
#define SOC_LP_SENSOR_CFG_HPM20_OPC2_ADDR(base) ((base) + 0x258UL)
#define SOC_LP_SENSOR_CFG_HPM21_EN_ADDR(base) ((base) + 0x260UL)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_ADDR(base) ((base) + 0x264UL)
#define SOC_LP_SENSOR_CFG_HPM21_OPC2_ADDR(base) ((base) + 0x268UL)
#define SOC_LP_SENSOR_CFG_HPM22_EN_ADDR(base) ((base) + 0x270UL)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_ADDR(base) ((base) + 0x274UL)
#define SOC_LP_SENSOR_CFG_HPM22_OPC2_ADDR(base) ((base) + 0x278UL)
#define SOC_LP_SENSOR_CFG_HPM23_EN_ADDR(base) ((base) + 0x280UL)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_ADDR(base) ((base) + 0x284UL)
#define SOC_LP_SENSOR_CFG_HPM23_OPC2_ADDR(base) ((base) + 0x288UL)
#define SOC_LP_SENSOR_CFG_HPM24_EN_ADDR(base) ((base) + 0x290UL)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_ADDR(base) ((base) + 0x294UL)
#define SOC_LP_SENSOR_CFG_HPM24_OPC2_ADDR(base) ((base) + 0x298UL)
#define SOC_LP_SENSOR_CFG_HPM25_EN_ADDR(base) ((base) + 0x2A0UL)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_ADDR(base) ((base) + 0x2A4UL)
#define SOC_LP_SENSOR_CFG_HPM25_OPC2_ADDR(base) ((base) + 0x2A8UL)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_ADDR(base) ((base) + 0x300UL)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_00_ADDR(base) ((base) + 0x304UL)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_ADDR(base) ((base) + 0x308UL)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_01_ADDR(base) ((base) + 0x30CUL)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_ADDR(base) ((base) + 0x310UL)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_02_ADDR(base) ((base) + 0x314UL)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_ADDR(base) ((base) + 0x318UL)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_03_ADDR(base) ((base) + 0x31CUL)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_ADDR(base) ((base) + 0x320UL)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_04_ADDR(base) ((base) + 0x324UL)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_ADDR(base) ((base) + 0x328UL)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_05_ADDR(base) ((base) + 0x32CUL)
#define SOC_LP_SENSOR_CFG_PCR_CTRL_ADDR(base) ((base) + 0x330UL)
#define SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_ADDR(base) ((base) + 0x334UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_ADDR(base) ((base) + 0x340UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_00_ADDR(base) ((base) + 0x344UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_ADDR(base) ((base) + 0x348UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_ADDR(base) ((base) + 0x34CUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_ADDR(base) ((base) + 0x350UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_ADDR(base) ((base) + 0x354UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_ADDR(base) ((base) + 0x358UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_ADDR(base) ((base) + 0x35CUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_ADDR(base) ((base) + 0x360UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_01_ADDR(base) ((base) + 0x364UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_ADDR(base) ((base) + 0x368UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_ADDR(base) ((base) + 0x36CUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_ADDR(base) ((base) + 0x370UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_ADDR(base) ((base) + 0x374UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_ADDR(base) ((base) + 0x378UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_ADDR(base) ((base) + 0x37CUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_ADDR(base) ((base) + 0x380UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_02_ADDR(base) ((base) + 0x384UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_ADDR(base) ((base) + 0x388UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_ADDR(base) ((base) + 0x38CUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_ADDR(base) ((base) + 0x390UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_ADDR(base) ((base) + 0x394UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_ADDR(base) ((base) + 0x398UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_ADDR(base) ((base) + 0x39CUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_ADDR(base) ((base) + 0x3A0UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_03_ADDR(base) ((base) + 0x3A4UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_ADDR(base) ((base) + 0x3A8UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_ADDR(base) ((base) + 0x3ACUL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_ADDR(base) ((base) + 0x3B0UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_ADDR(base) ((base) + 0x3B4UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_ADDR(base) ((base) + 0x3B8UL)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_ADDR(base) ((base) + 0x3BCUL)
#else
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_ADDR(base) (base)
#define SOC_LP_SENSOR_CFG_PEREN0_ADDR(base) ((base) + 0x010)
#define SOC_LP_SENSOR_CFG_PERDIS0_ADDR(base) ((base) + 0x014)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_ADDR(base) ((base) + 0x018)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_ADDR(base) ((base) + 0x01C)
#define SOC_LP_SENSOR_CFG_PEREN1_ADDR(base) ((base) + 0x020)
#define SOC_LP_SENSOR_CFG_PERDIS1_ADDR(base) ((base) + 0x024)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_ADDR(base) ((base) + 0x028)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_ADDR(base) ((base) + 0x02C)
#define SOC_LP_SENSOR_CFG_RSTEN0_ADDR(base) ((base) + 0x040)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ADDR(base) ((base) + 0x044)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ADDR(base) ((base) + 0x048)
#define SOC_LP_SENSOR_CFG_RSTEN1_ADDR(base) ((base) + 0x050)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ADDR(base) ((base) + 0x054)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ADDR(base) ((base) + 0x058)
#define SOC_LP_SENSOR_CFG_HPM0_EN_ADDR(base) ((base) + 0x110)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_ADDR(base) ((base) + 0x114)
#define SOC_LP_SENSOR_CFG_HPM0_OPC2_ADDR(base) ((base) + 0x118)
#define SOC_LP_SENSOR_CFG_HPM1_EN_ADDR(base) ((base) + 0x120)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_ADDR(base) ((base) + 0x124)
#define SOC_LP_SENSOR_CFG_HPM1_OPC2_ADDR(base) ((base) + 0x128)
#define SOC_LP_SENSOR_CFG_HPM2_EN_ADDR(base) ((base) + 0x130)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_ADDR(base) ((base) + 0x134)
#define SOC_LP_SENSOR_CFG_HPM2_OPC2_ADDR(base) ((base) + 0x138)
#define SOC_LP_SENSOR_CFG_HPM3_EN_ADDR(base) ((base) + 0x140)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_ADDR(base) ((base) + 0x144)
#define SOC_LP_SENSOR_CFG_HPM3_OPC2_ADDR(base) ((base) + 0x148)
#define SOC_LP_SENSOR_CFG_HPM4_EN_ADDR(base) ((base) + 0x150)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_ADDR(base) ((base) + 0x154)
#define SOC_LP_SENSOR_CFG_HPM4_OPC2_ADDR(base) ((base) + 0x158)
#define SOC_LP_SENSOR_CFG_HPM5_EN_ADDR(base) ((base) + 0x160)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_ADDR(base) ((base) + 0x164)
#define SOC_LP_SENSOR_CFG_HPM5_OPC2_ADDR(base) ((base) + 0x168)
#define SOC_LP_SENSOR_CFG_HPM6_EN_ADDR(base) ((base) + 0x170)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_ADDR(base) ((base) + 0x174)
#define SOC_LP_SENSOR_CFG_HPM6_OPC2_ADDR(base) ((base) + 0x178)
#define SOC_LP_SENSOR_CFG_HPM7_EN_ADDR(base) ((base) + 0x180)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_ADDR(base) ((base) + 0x184)
#define SOC_LP_SENSOR_CFG_HPM7_OPC2_ADDR(base) ((base) + 0x188)
#define SOC_LP_SENSOR_CFG_HPM8_EN_ADDR(base) ((base) + 0x190)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_ADDR(base) ((base) + 0x194)
#define SOC_LP_SENSOR_CFG_HPM8_OPC2_ADDR(base) ((base) + 0x198)
#define SOC_LP_SENSOR_CFG_HPM9_EN_ADDR(base) ((base) + 0x1A0)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_ADDR(base) ((base) + 0x1A4)
#define SOC_LP_SENSOR_CFG_HPM9_OPC2_ADDR(base) ((base) + 0x1A8)
#define SOC_LP_SENSOR_CFG_HPM10_EN_ADDR(base) ((base) + 0x1B0)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_ADDR(base) ((base) + 0x1B4)
#define SOC_LP_SENSOR_CFG_HPM10_OPC2_ADDR(base) ((base) + 0x1B8)
#define SOC_LP_SENSOR_CFG_HPM11_EN_ADDR(base) ((base) + 0x1C0)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_ADDR(base) ((base) + 0x1C4)
#define SOC_LP_SENSOR_CFG_HPM11_OPC2_ADDR(base) ((base) + 0x1C8)
#define SOC_LP_SENSOR_CFG_HPM12_EN_ADDR(base) ((base) + 0x1D0)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_ADDR(base) ((base) + 0x1D4)
#define SOC_LP_SENSOR_CFG_HPM12_OPC2_ADDR(base) ((base) + 0x1D8)
#define SOC_LP_SENSOR_CFG_HPM13_EN_ADDR(base) ((base) + 0x1E0)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_ADDR(base) ((base) + 0x1E4)
#define SOC_LP_SENSOR_CFG_HPM13_OPC2_ADDR(base) ((base) + 0x1E8)
#define SOC_LP_SENSOR_CFG_HPM14_EN_ADDR(base) ((base) + 0x1F0)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_ADDR(base) ((base) + 0x1F4)
#define SOC_LP_SENSOR_CFG_HPM14_OPC2_ADDR(base) ((base) + 0x1F8)
#define SOC_LP_SENSOR_CFG_HPM15_EN_ADDR(base) ((base) + 0x200)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_ADDR(base) ((base) + 0x204)
#define SOC_LP_SENSOR_CFG_HPM15_OPC2_ADDR(base) ((base) + 0x208)
#define SOC_LP_SENSOR_CFG_HPM16_EN_ADDR(base) ((base) + 0x210)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_ADDR(base) ((base) + 0x214)
#define SOC_LP_SENSOR_CFG_HPM16_OPC2_ADDR(base) ((base) + 0x218)
#define SOC_LP_SENSOR_CFG_HPM17_EN_ADDR(base) ((base) + 0x220)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_ADDR(base) ((base) + 0x224)
#define SOC_LP_SENSOR_CFG_HPM17_OPC2_ADDR(base) ((base) + 0x228)
#define SOC_LP_SENSOR_CFG_HPM18_EN_ADDR(base) ((base) + 0x230)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_ADDR(base) ((base) + 0x234)
#define SOC_LP_SENSOR_CFG_HPM18_OPC2_ADDR(base) ((base) + 0x238)
#define SOC_LP_SENSOR_CFG_HPM19_EN_ADDR(base) ((base) + 0x240)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_ADDR(base) ((base) + 0x244)
#define SOC_LP_SENSOR_CFG_HPM19_OPC2_ADDR(base) ((base) + 0x248)
#define SOC_LP_SENSOR_CFG_HPM20_EN_ADDR(base) ((base) + 0x250)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_ADDR(base) ((base) + 0x254)
#define SOC_LP_SENSOR_CFG_HPM20_OPC2_ADDR(base) ((base) + 0x258)
#define SOC_LP_SENSOR_CFG_HPM21_EN_ADDR(base) ((base) + 0x260)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_ADDR(base) ((base) + 0x264)
#define SOC_LP_SENSOR_CFG_HPM21_OPC2_ADDR(base) ((base) + 0x268)
#define SOC_LP_SENSOR_CFG_HPM22_EN_ADDR(base) ((base) + 0x270)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_ADDR(base) ((base) + 0x274)
#define SOC_LP_SENSOR_CFG_HPM22_OPC2_ADDR(base) ((base) + 0x278)
#define SOC_LP_SENSOR_CFG_HPM23_EN_ADDR(base) ((base) + 0x280)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_ADDR(base) ((base) + 0x284)
#define SOC_LP_SENSOR_CFG_HPM23_OPC2_ADDR(base) ((base) + 0x288)
#define SOC_LP_SENSOR_CFG_HPM24_EN_ADDR(base) ((base) + 0x290)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_ADDR(base) ((base) + 0x294)
#define SOC_LP_SENSOR_CFG_HPM24_OPC2_ADDR(base) ((base) + 0x298)
#define SOC_LP_SENSOR_CFG_HPM25_EN_ADDR(base) ((base) + 0x2A0)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_ADDR(base) ((base) + 0x2A4)
#define SOC_LP_SENSOR_CFG_HPM25_OPC2_ADDR(base) ((base) + 0x2A8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_ADDR(base) ((base) + 0x300)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_00_ADDR(base) ((base) + 0x304)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_ADDR(base) ((base) + 0x308)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_01_ADDR(base) ((base) + 0x30C)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_ADDR(base) ((base) + 0x310)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_02_ADDR(base) ((base) + 0x314)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_ADDR(base) ((base) + 0x318)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_03_ADDR(base) ((base) + 0x31C)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_ADDR(base) ((base) + 0x320)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_04_ADDR(base) ((base) + 0x324)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_ADDR(base) ((base) + 0x328)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_05_ADDR(base) ((base) + 0x32C)
#define SOC_LP_SENSOR_CFG_PCR_CTRL_ADDR(base) ((base) + 0x330)
#define SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_ADDR(base) ((base) + 0x334)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_ADDR(base) ((base) + 0x340)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_00_ADDR(base) ((base) + 0x344)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_ADDR(base) ((base) + 0x348)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_ADDR(base) ((base) + 0x34C)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_ADDR(base) ((base) + 0x350)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_ADDR(base) ((base) + 0x354)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_ADDR(base) ((base) + 0x358)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_ADDR(base) ((base) + 0x35C)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_ADDR(base) ((base) + 0x360)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_01_ADDR(base) ((base) + 0x364)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_ADDR(base) ((base) + 0x368)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_ADDR(base) ((base) + 0x36C)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_ADDR(base) ((base) + 0x370)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_ADDR(base) ((base) + 0x374)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_ADDR(base) ((base) + 0x378)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_ADDR(base) ((base) + 0x37C)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_ADDR(base) ((base) + 0x380)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_02_ADDR(base) ((base) + 0x384)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_ADDR(base) ((base) + 0x388)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_ADDR(base) ((base) + 0x38C)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_ADDR(base) ((base) + 0x390)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_ADDR(base) ((base) + 0x394)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_ADDR(base) ((base) + 0x398)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_ADDR(base) ((base) + 0x39C)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_ADDR(base) ((base) + 0x3A0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_03_ADDR(base) ((base) + 0x3A4)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_ADDR(base) ((base) + 0x3A8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_ADDR(base) ((base) + 0x3AC)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_ADDR(base) ((base) + 0x3B0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_ADDR(base) ((base) + 0x3B4)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_ADDR(base) ((base) + 0x3B8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_ADDR(base) ((base) + 0x3BC)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpm_00_clkrst_bypass : 1;
        unsigned int dpm_01_clkrst_bypass : 1;
        unsigned int dpm_02_clkrst_bypass : 1;
        unsigned int dpm_03_clkrst_bypass : 1;
        unsigned int dpm_04_clkrst_bypass : 1;
        unsigned int dpm_05_clkrst_bypass : 1;
        unsigned int dpm_06_clkrst_bypass : 1;
        unsigned int dpm_07_clkrst_bypass : 1;
        unsigned int dpm_08_clkrst_bypass : 1;
        unsigned int dpm_09_clkrst_bypass : 1;
        unsigned int dpm_10_clkrst_bypass : 1;
        unsigned int dpm_11_clkrst_bypass : 1;
        unsigned int dpm_12_clkrst_bypass : 1;
        unsigned int dpm_13_clkrst_bypass : 1;
        unsigned int dpm_14_clkrst_bypass : 1;
        unsigned int dpm_15_clkrst_bypass : 1;
        unsigned int pcr_00_clkrst_bypass : 1;
        unsigned int pcr_01_clkrst_bypass : 1;
        unsigned int pcr_02_clkrst_bypass : 1;
        unsigned int pcr_03_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int div_lp_sensor : 2;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_00_clkrst_bypass_START (0)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_00_clkrst_bypass_END (0)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_01_clkrst_bypass_START (1)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_01_clkrst_bypass_END (1)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_02_clkrst_bypass_START (2)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_02_clkrst_bypass_END (2)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_03_clkrst_bypass_START (3)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_03_clkrst_bypass_END (3)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_04_clkrst_bypass_START (4)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_04_clkrst_bypass_END (4)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_05_clkrst_bypass_START (5)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_05_clkrst_bypass_END (5)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_06_clkrst_bypass_START (6)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_06_clkrst_bypass_END (6)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_07_clkrst_bypass_START (7)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_07_clkrst_bypass_END (7)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_08_clkrst_bypass_START (8)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_08_clkrst_bypass_END (8)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_09_clkrst_bypass_START (9)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_09_clkrst_bypass_END (9)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_10_clkrst_bypass_START (10)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_10_clkrst_bypass_END (10)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_11_clkrst_bypass_START (11)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_11_clkrst_bypass_END (11)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_12_clkrst_bypass_START (12)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_12_clkrst_bypass_END (12)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_13_clkrst_bypass_START (13)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_13_clkrst_bypass_END (13)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_14_clkrst_bypass_START (14)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_14_clkrst_bypass_END (14)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_15_clkrst_bypass_START (15)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_dpm_15_clkrst_bypass_END (15)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_00_clkrst_bypass_START (16)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_00_clkrst_bypass_END (16)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_01_clkrst_bypass_START (17)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_01_clkrst_bypass_END (17)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_02_clkrst_bypass_START (18)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_02_clkrst_bypass_END (18)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_03_clkrst_bypass_START (19)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_pcr_03_clkrst_bypass_END (19)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_div_lp_sensor_START (21)
#define SOC_LP_SENSOR_CFG_LPCTRL_CLKRST_BYPASS0_div_lp_sensor_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dpm_00 : 1;
        unsigned int gt_clk_dpm_01 : 1;
        unsigned int gt_clk_dpm_02 : 1;
        unsigned int gt_clk_dpm_03 : 1;
        unsigned int gt_clk_dpm_04 : 1;
        unsigned int gt_clk_dpm_05 : 1;
        unsigned int gt_clk_dpm_06 : 1;
        unsigned int gt_clk_dpm_07 : 1;
        unsigned int gt_clk_dpm_08 : 1;
        unsigned int gt_clk_dpm_09 : 1;
        unsigned int gt_clk_dpm_10 : 1;
        unsigned int gt_clk_dpm_11 : 1;
        unsigned int gt_clk_dpm_12 : 1;
        unsigned int gt_clk_dpm_13 : 1;
        unsigned int gt_clk_dpm_14 : 1;
        unsigned int gt_clk_dpm_15 : 1;
        unsigned int gt_pclk_dpm_00 : 1;
        unsigned int gt_pclk_dpm_01 : 1;
        unsigned int gt_pclk_dpm_02 : 1;
        unsigned int gt_pclk_dpm_03 : 1;
        unsigned int gt_pclk_dpm_04 : 1;
        unsigned int gt_pclk_dpm_05 : 1;
        unsigned int gt_pclk_dpm_06 : 1;
        unsigned int gt_pclk_dpm_07 : 1;
        unsigned int gt_pclk_dpm_08 : 1;
        unsigned int gt_pclk_dpm_09 : 1;
        unsigned int gt_pclk_dpm_10 : 1;
        unsigned int gt_pclk_dpm_11 : 1;
        unsigned int gt_pclk_dpm_12 : 1;
        unsigned int gt_pclk_dpm_13 : 1;
        unsigned int gt_pclk_dpm_14 : 1;
        unsigned int gt_pclk_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_PEREN0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_00_START (0)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_00_END (0)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_01_START (1)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_01_END (1)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_02_START (2)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_02_END (2)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_03_START (3)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_03_END (3)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_04_START (4)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_04_END (4)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_05_START (5)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_05_END (5)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_06_START (6)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_06_END (6)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_07_START (7)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_07_END (7)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_08_START (8)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_08_END (8)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_09_START (9)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_09_END (9)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_10_START (10)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_10_END (10)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_11_START (11)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_11_END (11)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_12_START (12)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_12_END (12)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_13_START (13)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_13_END (13)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_14_START (14)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_14_END (14)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_15_START (15)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_clk_dpm_15_END (15)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_PEREN0_gt_pclk_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dpm_00 : 1;
        unsigned int gt_clk_dpm_01 : 1;
        unsigned int gt_clk_dpm_02 : 1;
        unsigned int gt_clk_dpm_03 : 1;
        unsigned int gt_clk_dpm_04 : 1;
        unsigned int gt_clk_dpm_05 : 1;
        unsigned int gt_clk_dpm_06 : 1;
        unsigned int gt_clk_dpm_07 : 1;
        unsigned int gt_clk_dpm_08 : 1;
        unsigned int gt_clk_dpm_09 : 1;
        unsigned int gt_clk_dpm_10 : 1;
        unsigned int gt_clk_dpm_11 : 1;
        unsigned int gt_clk_dpm_12 : 1;
        unsigned int gt_clk_dpm_13 : 1;
        unsigned int gt_clk_dpm_14 : 1;
        unsigned int gt_clk_dpm_15 : 1;
        unsigned int gt_pclk_dpm_00 : 1;
        unsigned int gt_pclk_dpm_01 : 1;
        unsigned int gt_pclk_dpm_02 : 1;
        unsigned int gt_pclk_dpm_03 : 1;
        unsigned int gt_pclk_dpm_04 : 1;
        unsigned int gt_pclk_dpm_05 : 1;
        unsigned int gt_pclk_dpm_06 : 1;
        unsigned int gt_pclk_dpm_07 : 1;
        unsigned int gt_pclk_dpm_08 : 1;
        unsigned int gt_pclk_dpm_09 : 1;
        unsigned int gt_pclk_dpm_10 : 1;
        unsigned int gt_pclk_dpm_11 : 1;
        unsigned int gt_pclk_dpm_12 : 1;
        unsigned int gt_pclk_dpm_13 : 1;
        unsigned int gt_pclk_dpm_14 : 1;
        unsigned int gt_pclk_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_PERDIS0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_00_START (0)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_00_END (0)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_01_START (1)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_01_END (1)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_02_START (2)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_02_END (2)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_03_START (3)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_03_END (3)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_04_START (4)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_04_END (4)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_05_START (5)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_05_END (5)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_06_START (6)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_06_END (6)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_07_START (7)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_07_END (7)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_08_START (8)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_08_END (8)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_09_START (9)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_09_END (9)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_10_START (10)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_10_END (10)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_11_START (11)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_11_END (11)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_12_START (12)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_12_END (12)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_13_START (13)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_13_END (13)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_14_START (14)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_14_END (14)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_15_START (15)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_clk_dpm_15_END (15)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_PERDIS0_gt_pclk_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dpm_00 : 1;
        unsigned int gt_clk_dpm_01 : 1;
        unsigned int gt_clk_dpm_02 : 1;
        unsigned int gt_clk_dpm_03 : 1;
        unsigned int gt_clk_dpm_04 : 1;
        unsigned int gt_clk_dpm_05 : 1;
        unsigned int gt_clk_dpm_06 : 1;
        unsigned int gt_clk_dpm_07 : 1;
        unsigned int gt_clk_dpm_08 : 1;
        unsigned int gt_clk_dpm_09 : 1;
        unsigned int gt_clk_dpm_10 : 1;
        unsigned int gt_clk_dpm_11 : 1;
        unsigned int gt_clk_dpm_12 : 1;
        unsigned int gt_clk_dpm_13 : 1;
        unsigned int gt_clk_dpm_14 : 1;
        unsigned int gt_clk_dpm_15 : 1;
        unsigned int gt_pclk_dpm_00 : 1;
        unsigned int gt_pclk_dpm_01 : 1;
        unsigned int gt_pclk_dpm_02 : 1;
        unsigned int gt_pclk_dpm_03 : 1;
        unsigned int gt_pclk_dpm_04 : 1;
        unsigned int gt_pclk_dpm_05 : 1;
        unsigned int gt_pclk_dpm_06 : 1;
        unsigned int gt_pclk_dpm_07 : 1;
        unsigned int gt_pclk_dpm_08 : 1;
        unsigned int gt_pclk_dpm_09 : 1;
        unsigned int gt_pclk_dpm_10 : 1;
        unsigned int gt_pclk_dpm_11 : 1;
        unsigned int gt_pclk_dpm_12 : 1;
        unsigned int gt_pclk_dpm_13 : 1;
        unsigned int gt_pclk_dpm_14 : 1;
        unsigned int gt_pclk_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_PERCLKEN0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_00_START (0)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_00_END (0)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_01_START (1)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_01_END (1)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_02_START (2)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_02_END (2)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_03_START (3)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_03_END (3)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_04_START (4)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_04_END (4)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_05_START (5)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_05_END (5)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_06_START (6)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_06_END (6)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_07_START (7)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_07_END (7)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_08_START (8)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_08_END (8)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_09_START (9)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_09_END (9)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_10_START (10)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_10_END (10)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_11_START (11)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_11_END (11)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_12_START (12)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_12_END (12)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_13_START (13)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_13_END (13)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_14_START (14)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_14_END (14)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_15_START (15)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_clk_dpm_15_END (15)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_PERCLKEN0_gt_pclk_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_dpm_00 : 1;
        unsigned int st_clk_dpm_01 : 1;
        unsigned int st_clk_dpm_02 : 1;
        unsigned int st_clk_dpm_03 : 1;
        unsigned int st_clk_dpm_04 : 1;
        unsigned int st_clk_dpm_05 : 1;
        unsigned int st_clk_dpm_06 : 1;
        unsigned int st_clk_dpm_07 : 1;
        unsigned int st_clk_dpm_08 : 1;
        unsigned int st_clk_dpm_09 : 1;
        unsigned int st_clk_dpm_10 : 1;
        unsigned int st_clk_dpm_11 : 1;
        unsigned int st_clk_dpm_12 : 1;
        unsigned int st_clk_dpm_13 : 1;
        unsigned int st_clk_dpm_14 : 1;
        unsigned int st_clk_dpm_15 : 1;
        unsigned int st_pclk_dpm_00 : 1;
        unsigned int st_pclk_dpm_01 : 1;
        unsigned int st_pclk_dpm_02 : 1;
        unsigned int st_pclk_dpm_03 : 1;
        unsigned int st_pclk_dpm_04 : 1;
        unsigned int st_pclk_dpm_05 : 1;
        unsigned int st_pclk_dpm_06 : 1;
        unsigned int st_pclk_dpm_07 : 1;
        unsigned int st_pclk_dpm_08 : 1;
        unsigned int st_pclk_dpm_09 : 1;
        unsigned int st_pclk_dpm_10 : 1;
        unsigned int st_pclk_dpm_11 : 1;
        unsigned int st_pclk_dpm_12 : 1;
        unsigned int st_pclk_dpm_13 : 1;
        unsigned int st_pclk_dpm_14 : 1;
        unsigned int st_pclk_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_PERCLKSTAT0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_00_START (0)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_00_END (0)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_01_START (1)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_01_END (1)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_02_START (2)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_02_END (2)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_03_START (3)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_03_END (3)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_04_START (4)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_04_END (4)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_05_START (5)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_05_END (5)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_06_START (6)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_06_END (6)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_07_START (7)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_07_END (7)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_08_START (8)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_08_END (8)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_09_START (9)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_09_END (9)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_10_START (10)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_10_END (10)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_11_START (11)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_11_END (11)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_12_START (12)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_12_END (12)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_13_START (13)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_13_END (13)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_14_START (14)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_14_END (14)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_15_START (15)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_clk_dpm_15_END (15)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT0_st_pclk_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_pcr_00 : 1;
        unsigned int gt_clk_pcr_01 : 1;
        unsigned int gt_clk_pcr_02 : 1;
        unsigned int gt_clk_pcr_03 : 1;
        unsigned int gt_pclk_pcr_00 : 1;
        unsigned int gt_pclk_pcr_01 : 1;
        unsigned int gt_pclk_pcr_02 : 1;
        unsigned int gt_pclk_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hpm : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_pasensor_00 : 1;
        unsigned int gt_clk_pasensor_01 : 1;
        unsigned int gt_clk_pasensor_02 : 1;
        unsigned int gt_clk_pasensor_03 : 1;
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
} SOC_LP_SENSOR_CFG_PEREN1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_00_START (4)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_00_END (4)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_01_START (5)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_01_END (5)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_02_START (6)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_02_END (6)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_03_START (7)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_pclk_pcr_03_END (7)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_hpm_START (10)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_hpm_END (10)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_00_START (14)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_00_END (14)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_01_START (15)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_01_END (15)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_02_START (16)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_02_END (16)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_03_START (17)
#define SOC_LP_SENSOR_CFG_PEREN1_gt_clk_pasensor_03_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_pcr_00 : 1;
        unsigned int gt_clk_pcr_01 : 1;
        unsigned int gt_clk_pcr_02 : 1;
        unsigned int gt_clk_pcr_03 : 1;
        unsigned int gt_pclk_pcr_00 : 1;
        unsigned int gt_pclk_pcr_01 : 1;
        unsigned int gt_pclk_pcr_02 : 1;
        unsigned int gt_pclk_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hpm : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_pasensor_00 : 1;
        unsigned int gt_clk_pasensor_01 : 1;
        unsigned int gt_clk_pasensor_02 : 1;
        unsigned int gt_clk_pasensor_03 : 1;
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
} SOC_LP_SENSOR_CFG_PERDIS1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_00_START (4)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_00_END (4)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_01_START (5)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_01_END (5)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_02_START (6)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_02_END (6)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_03_START (7)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_pclk_pcr_03_END (7)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_hpm_START (10)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_hpm_END (10)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_00_START (14)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_00_END (14)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_01_START (15)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_01_END (15)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_02_START (16)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_02_END (16)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_03_START (17)
#define SOC_LP_SENSOR_CFG_PERDIS1_gt_clk_pasensor_03_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_pcr_00 : 1;
        unsigned int gt_clk_pcr_01 : 1;
        unsigned int gt_clk_pcr_02 : 1;
        unsigned int gt_clk_pcr_03 : 1;
        unsigned int gt_pclk_pcr_00 : 1;
        unsigned int gt_pclk_pcr_01 : 1;
        unsigned int gt_pclk_pcr_02 : 1;
        unsigned int gt_pclk_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_hpm : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_pasensor_00 : 1;
        unsigned int gt_clk_pasensor_01 : 1;
        unsigned int gt_clk_pasensor_02 : 1;
        unsigned int gt_clk_pasensor_03 : 1;
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
} SOC_LP_SENSOR_CFG_PERCLKEN1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_00_START (4)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_00_END (4)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_01_START (5)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_01_END (5)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_02_START (6)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_02_END (6)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_03_START (7)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_pclk_pcr_03_END (7)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_hpm_START (10)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_hpm_END (10)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_00_START (14)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_00_END (14)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_01_START (15)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_01_END (15)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_02_START (16)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_02_END (16)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_03_START (17)
#define SOC_LP_SENSOR_CFG_PERCLKEN1_gt_clk_pasensor_03_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_pcr_00 : 1;
        unsigned int st_clk_pcr_01 : 1;
        unsigned int st_clk_pcr_02 : 1;
        unsigned int st_clk_pcr_03 : 1;
        unsigned int st_pclk_pcr_00 : 1;
        unsigned int st_pclk_pcr_01 : 1;
        unsigned int st_pclk_pcr_02 : 1;
        unsigned int st_pclk_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_hpm : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_pasensor_00 : 1;
        unsigned int st_clk_pasensor_01 : 1;
        unsigned int st_clk_pasensor_02 : 1;
        unsigned int st_clk_pasensor_03 : 1;
        unsigned int reserved_5 : 1;
        unsigned int swdone_clk_lp_sensor_div : 1;
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
} SOC_LP_SENSOR_CFG_PERCLKSTAT1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_00_START (4)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_00_END (4)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_01_START (5)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_01_END (5)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_02_START (6)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_02_END (6)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_03_START (7)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_pclk_pcr_03_END (7)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_hpm_START (10)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_hpm_END (10)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_00_START (14)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_00_END (14)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_01_START (15)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_01_END (15)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_02_START (16)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_02_END (16)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_03_START (17)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_st_clk_pasensor_03_END (17)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_swdone_clk_lp_sensor_div_START (19)
#define SOC_LP_SENSOR_CFG_PERCLKSTAT1_swdone_clk_lp_sensor_div_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_hpm_00 : 1;
        unsigned int ip_rst_hpm_01 : 1;
        unsigned int ip_rst_hpm_02 : 1;
        unsigned int ip_rst_hpm_03 : 1;
        unsigned int ip_rst_hpm_04 : 1;
        unsigned int ip_rst_hpm_05 : 1;
        unsigned int ip_rst_hpm_06 : 1;
        unsigned int ip_rst_hpm_07 : 1;
        unsigned int ip_rst_hpm_08 : 1;
        unsigned int ip_rst_hpm_09 : 1;
        unsigned int ip_rst_hpm_10 : 1;
        unsigned int ip_rst_hpm_11 : 1;
        unsigned int ip_rst_hpm_12 : 1;
        unsigned int ip_rst_hpm_13 : 1;
        unsigned int ip_rst_hpm_14 : 1;
        unsigned int ip_rst_hpm_15 : 1;
        unsigned int ip_rst_hpm_16 : 1;
        unsigned int ip_rst_hpm_17 : 1;
        unsigned int ip_rst_hpm_18 : 1;
        unsigned int ip_rst_hpm_19 : 1;
        unsigned int ip_rst_hpm_20 : 1;
        unsigned int ip_rst_hpm_21 : 1;
        unsigned int ip_rst_hpm_22 : 1;
        unsigned int ip_rst_hpm_23 : 1;
        unsigned int ip_rst_hpm_24 : 1;
        unsigned int ip_rst_hpm_25 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_RSTEN0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_00_START (0)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_00_END (0)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_01_START (1)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_01_END (1)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_02_START (2)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_02_END (2)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_03_START (3)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_03_END (3)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_04_START (4)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_04_END (4)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_05_START (5)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_05_END (5)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_06_START (6)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_06_END (6)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_07_START (7)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_07_END (7)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_08_START (8)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_08_END (8)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_09_START (9)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_09_END (9)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_10_START (10)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_10_END (10)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_11_START (11)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_11_END (11)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_12_START (12)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_12_END (12)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_13_START (13)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_13_END (13)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_14_START (14)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_14_END (14)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_15_START (15)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_15_END (15)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_16_START (16)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_16_END (16)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_17_START (17)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_17_END (17)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_18_START (18)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_18_END (18)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_19_START (19)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_19_END (19)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_20_START (20)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_20_END (20)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_21_START (21)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_21_END (21)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_22_START (22)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_22_END (22)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_23_START (23)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_23_END (23)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_24_START (24)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_24_END (24)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_25_START (25)
#define SOC_LP_SENSOR_CFG_RSTEN0_ip_rst_hpm_25_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_hpm_00 : 1;
        unsigned int ip_rst_hpm_01 : 1;
        unsigned int ip_rst_hpm_02 : 1;
        unsigned int ip_rst_hpm_03 : 1;
        unsigned int ip_rst_hpm_04 : 1;
        unsigned int ip_rst_hpm_05 : 1;
        unsigned int ip_rst_hpm_06 : 1;
        unsigned int ip_rst_hpm_07 : 1;
        unsigned int ip_rst_hpm_08 : 1;
        unsigned int ip_rst_hpm_09 : 1;
        unsigned int ip_rst_hpm_10 : 1;
        unsigned int ip_rst_hpm_11 : 1;
        unsigned int ip_rst_hpm_12 : 1;
        unsigned int ip_rst_hpm_13 : 1;
        unsigned int ip_rst_hpm_14 : 1;
        unsigned int ip_rst_hpm_15 : 1;
        unsigned int ip_rst_hpm_16 : 1;
        unsigned int ip_rst_hpm_17 : 1;
        unsigned int ip_rst_hpm_18 : 1;
        unsigned int ip_rst_hpm_19 : 1;
        unsigned int ip_rst_hpm_20 : 1;
        unsigned int ip_rst_hpm_21 : 1;
        unsigned int ip_rst_hpm_22 : 1;
        unsigned int ip_rst_hpm_23 : 1;
        unsigned int ip_rst_hpm_24 : 1;
        unsigned int ip_rst_hpm_25 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_RSTDIS0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_00_START (0)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_00_END (0)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_01_START (1)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_01_END (1)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_02_START (2)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_02_END (2)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_03_START (3)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_03_END (3)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_04_START (4)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_04_END (4)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_05_START (5)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_05_END (5)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_06_START (6)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_06_END (6)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_07_START (7)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_07_END (7)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_08_START (8)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_08_END (8)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_09_START (9)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_09_END (9)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_10_START (10)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_10_END (10)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_11_START (11)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_11_END (11)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_12_START (12)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_12_END (12)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_13_START (13)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_13_END (13)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_14_START (14)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_14_END (14)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_15_START (15)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_15_END (15)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_16_START (16)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_16_END (16)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_17_START (17)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_17_END (17)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_18_START (18)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_18_END (18)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_19_START (19)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_19_END (19)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_20_START (20)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_20_END (20)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_21_START (21)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_21_END (21)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_22_START (22)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_22_END (22)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_23_START (23)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_23_END (23)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_24_START (24)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_24_END (24)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_25_START (25)
#define SOC_LP_SENSOR_CFG_RSTDIS0_ip_rst_hpm_25_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_hpm_00 : 1;
        unsigned int ip_rst_hpm_01 : 1;
        unsigned int ip_rst_hpm_02 : 1;
        unsigned int ip_rst_hpm_03 : 1;
        unsigned int ip_rst_hpm_04 : 1;
        unsigned int ip_rst_hpm_05 : 1;
        unsigned int ip_rst_hpm_06 : 1;
        unsigned int ip_rst_hpm_07 : 1;
        unsigned int ip_rst_hpm_08 : 1;
        unsigned int ip_rst_hpm_09 : 1;
        unsigned int ip_rst_hpm_10 : 1;
        unsigned int ip_rst_hpm_11 : 1;
        unsigned int ip_rst_hpm_12 : 1;
        unsigned int ip_rst_hpm_13 : 1;
        unsigned int ip_rst_hpm_14 : 1;
        unsigned int ip_rst_hpm_15 : 1;
        unsigned int ip_rst_hpm_16 : 1;
        unsigned int ip_rst_hpm_17 : 1;
        unsigned int ip_rst_hpm_18 : 1;
        unsigned int ip_rst_hpm_19 : 1;
        unsigned int ip_rst_hpm_20 : 1;
        unsigned int ip_rst_hpm_21 : 1;
        unsigned int ip_rst_hpm_22 : 1;
        unsigned int ip_rst_hpm_23 : 1;
        unsigned int ip_rst_hpm_24 : 1;
        unsigned int ip_rst_hpm_25 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_RSTSTAT0_UNION;
#endif
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_00_START (0)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_00_END (0)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_01_START (1)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_01_END (1)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_02_START (2)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_02_END (2)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_03_START (3)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_03_END (3)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_04_START (4)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_04_END (4)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_05_START (5)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_05_END (5)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_06_START (6)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_06_END (6)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_07_START (7)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_07_END (7)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_08_START (8)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_08_END (8)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_09_START (9)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_09_END (9)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_10_START (10)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_10_END (10)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_11_START (11)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_11_END (11)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_12_START (12)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_12_END (12)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_13_START (13)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_13_END (13)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_14_START (14)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_14_END (14)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_15_START (15)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_15_END (15)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_16_START (16)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_16_END (16)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_17_START (17)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_17_END (17)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_18_START (18)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_18_END (18)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_19_START (19)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_19_END (19)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_20_START (20)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_20_END (20)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_21_START (21)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_21_END (21)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_22_START (22)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_22_END (22)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_23_START (23)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_23_END (23)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_24_START (24)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_24_END (24)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_25_START (25)
#define SOC_LP_SENSOR_CFG_RSTSTAT0_ip_rst_hpm_25_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_pcr_00 : 1;
        unsigned int ip_prst_pcr_01 : 1;
        unsigned int ip_prst_pcr_02 : 1;
        unsigned int ip_prst_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_pasensor_00 : 1;
        unsigned int ip_rst_pasensor_01 : 1;
        unsigned int ip_rst_pasensor_02 : 1;
        unsigned int ip_rst_pasensor_03 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_prst_dpm_00 : 1;
        unsigned int ip_prst_dpm_01 : 1;
        unsigned int ip_prst_dpm_02 : 1;
        unsigned int ip_prst_dpm_03 : 1;
        unsigned int ip_prst_dpm_04 : 1;
        unsigned int ip_prst_dpm_05 : 1;
        unsigned int ip_prst_dpm_06 : 1;
        unsigned int ip_prst_dpm_07 : 1;
        unsigned int ip_prst_dpm_08 : 1;
        unsigned int ip_prst_dpm_09 : 1;
        unsigned int ip_prst_dpm_10 : 1;
        unsigned int ip_prst_dpm_11 : 1;
        unsigned int ip_prst_dpm_12 : 1;
        unsigned int ip_prst_dpm_13 : 1;
        unsigned int ip_prst_dpm_14 : 1;
        unsigned int ip_prst_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_RSTEN1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_00_START (9)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_00_END (9)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_01_START (10)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_01_END (10)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_02_START (11)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_02_END (11)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_03_START (12)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_rst_pasensor_03_END (12)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_RSTEN1_ip_prst_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_pcr_00 : 1;
        unsigned int ip_prst_pcr_01 : 1;
        unsigned int ip_prst_pcr_02 : 1;
        unsigned int ip_prst_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_pasensor_00 : 1;
        unsigned int ip_rst_pasensor_01 : 1;
        unsigned int ip_rst_pasensor_02 : 1;
        unsigned int ip_rst_pasensor_03 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_prst_dpm_00 : 1;
        unsigned int ip_prst_dpm_01 : 1;
        unsigned int ip_prst_dpm_02 : 1;
        unsigned int ip_prst_dpm_03 : 1;
        unsigned int ip_prst_dpm_04 : 1;
        unsigned int ip_prst_dpm_05 : 1;
        unsigned int ip_prst_dpm_06 : 1;
        unsigned int ip_prst_dpm_07 : 1;
        unsigned int ip_prst_dpm_08 : 1;
        unsigned int ip_prst_dpm_09 : 1;
        unsigned int ip_prst_dpm_10 : 1;
        unsigned int ip_prst_dpm_11 : 1;
        unsigned int ip_prst_dpm_12 : 1;
        unsigned int ip_prst_dpm_13 : 1;
        unsigned int ip_prst_dpm_14 : 1;
        unsigned int ip_prst_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_RSTDIS1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_00_START (9)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_00_END (9)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_01_START (10)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_01_END (10)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_02_START (11)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_02_END (11)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_03_START (12)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_rst_pasensor_03_END (12)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_RSTDIS1_ip_prst_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_pcr_00 : 1;
        unsigned int ip_prst_pcr_01 : 1;
        unsigned int ip_prst_pcr_02 : 1;
        unsigned int ip_prst_pcr_03 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ip_rst_pasensor_00 : 1;
        unsigned int ip_rst_pasensor_01 : 1;
        unsigned int ip_rst_pasensor_02 : 1;
        unsigned int ip_rst_pasensor_03 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_prst_dpm_00 : 1;
        unsigned int ip_prst_dpm_01 : 1;
        unsigned int ip_prst_dpm_02 : 1;
        unsigned int ip_prst_dpm_03 : 1;
        unsigned int ip_prst_dpm_04 : 1;
        unsigned int ip_prst_dpm_05 : 1;
        unsigned int ip_prst_dpm_06 : 1;
        unsigned int ip_prst_dpm_07 : 1;
        unsigned int ip_prst_dpm_08 : 1;
        unsigned int ip_prst_dpm_09 : 1;
        unsigned int ip_prst_dpm_10 : 1;
        unsigned int ip_prst_dpm_11 : 1;
        unsigned int ip_prst_dpm_12 : 1;
        unsigned int ip_prst_dpm_13 : 1;
        unsigned int ip_prst_dpm_14 : 1;
        unsigned int ip_prst_dpm_15 : 1;
    } reg;
} SOC_LP_SENSOR_CFG_RSTSTAT1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_00_START (0)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_00_END (0)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_01_START (1)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_01_END (1)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_02_START (2)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_02_END (2)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_03_START (3)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_pcr_03_END (3)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_00_START (9)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_00_END (9)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_01_START (10)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_01_END (10)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_02_START (11)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_02_END (11)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_03_START (12)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_rst_pasensor_03_END (12)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_00_START (16)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_00_END (16)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_01_START (17)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_01_END (17)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_02_START (18)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_02_END (18)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_03_START (19)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_03_END (19)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_04_START (20)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_04_END (20)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_05_START (21)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_05_END (21)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_06_START (22)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_06_END (22)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_07_START (23)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_07_END (23)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_08_START (24)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_08_END (24)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_09_START (25)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_09_END (25)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_10_START (26)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_10_END (26)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_11_START (27)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_11_END (27)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_12_START (28)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_12_END (28)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_13_START (29)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_13_END (29)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_14_START (30)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_14_END (30)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_15_START (31)
#define SOC_LP_SENSOR_CFG_RSTSTAT1_ip_prst_dpm_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_00 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_00 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_00 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_00 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_00 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM0_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_START (0)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpm_clk_div_00_END (6)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpm_en_00_START (8)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpm_en_00_END (8)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpm_opc_min_en_00_START (12)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpm_opc_min_en_00_END (12)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_en_00_START (16)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_en_00_END (16)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_opc_min_en_00_START (20)
#define SOC_LP_SENSOR_CFG_HPM0_EN_hpmx_opc_min_en_00_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_00 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_00 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_00 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_00 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM0_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_00_START (0)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_00_END (9)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_vld_00_START (12)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpm_opc_vld_00_END (12)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_00_START (16)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_00_END (25)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_vld_00_START (28)
#define SOC_LP_SENSOR_CFG_HPM0_OPC1_hpmx_opc_vld_00_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_00 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_00 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM0_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM0_OPC2_hpm_opc_min_00_START (0)
#define SOC_LP_SENSOR_CFG_HPM0_OPC2_hpm_opc_min_00_END (9)
#define SOC_LP_SENSOR_CFG_HPM0_OPC2_hpmx_opc_min_00_START (16)
#define SOC_LP_SENSOR_CFG_HPM0_OPC2_hpmx_opc_min_00_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_01 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_01 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_01 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_01 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_01 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM1_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_START (0)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpm_clk_div_01_END (6)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpm_en_01_START (8)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpm_en_01_END (8)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpm_opc_min_en_01_START (12)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpm_opc_min_en_01_END (12)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_en_01_START (16)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_en_01_END (16)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_opc_min_en_01_START (20)
#define SOC_LP_SENSOR_CFG_HPM1_EN_hpmx_opc_min_en_01_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_01 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_01 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_01 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_01 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM1_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_01_START (0)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_01_END (9)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_vld_01_START (12)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpm_opc_vld_01_END (12)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_01_START (16)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_01_END (25)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_vld_01_START (28)
#define SOC_LP_SENSOR_CFG_HPM1_OPC1_hpmx_opc_vld_01_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_01 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_01 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM1_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM1_OPC2_hpm_opc_min_01_START (0)
#define SOC_LP_SENSOR_CFG_HPM1_OPC2_hpm_opc_min_01_END (9)
#define SOC_LP_SENSOR_CFG_HPM1_OPC2_hpmx_opc_min_01_START (16)
#define SOC_LP_SENSOR_CFG_HPM1_OPC2_hpmx_opc_min_01_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_02 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_02 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_02 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_02 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_02 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM2_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_START (0)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpm_clk_div_02_END (6)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpm_en_02_START (8)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpm_en_02_END (8)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpm_opc_min_en_02_START (12)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpm_opc_min_en_02_END (12)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_en_02_START (16)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_en_02_END (16)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_opc_min_en_02_START (20)
#define SOC_LP_SENSOR_CFG_HPM2_EN_hpmx_opc_min_en_02_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_02 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_02 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_02 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_02 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM2_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_02_START (0)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_02_END (9)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_vld_02_START (12)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpm_opc_vld_02_END (12)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_02_START (16)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_02_END (25)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_vld_02_START (28)
#define SOC_LP_SENSOR_CFG_HPM2_OPC1_hpmx_opc_vld_02_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_02 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_02 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM2_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM2_OPC2_hpm_opc_min_02_START (0)
#define SOC_LP_SENSOR_CFG_HPM2_OPC2_hpm_opc_min_02_END (9)
#define SOC_LP_SENSOR_CFG_HPM2_OPC2_hpmx_opc_min_02_START (16)
#define SOC_LP_SENSOR_CFG_HPM2_OPC2_hpmx_opc_min_02_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_03 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_03 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_03 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_03 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_03 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM3_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_START (0)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpm_clk_div_03_END (6)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpm_en_03_START (8)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpm_en_03_END (8)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpm_opc_min_en_03_START (12)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpm_opc_min_en_03_END (12)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_en_03_START (16)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_en_03_END (16)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_opc_min_en_03_START (20)
#define SOC_LP_SENSOR_CFG_HPM3_EN_hpmx_opc_min_en_03_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_03 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_03 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_03 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_03 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM3_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_03_START (0)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_03_END (9)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_vld_03_START (12)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpm_opc_vld_03_END (12)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_03_START (16)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_03_END (25)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_vld_03_START (28)
#define SOC_LP_SENSOR_CFG_HPM3_OPC1_hpmx_opc_vld_03_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_03 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_03 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM3_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM3_OPC2_hpm_opc_min_03_START (0)
#define SOC_LP_SENSOR_CFG_HPM3_OPC2_hpm_opc_min_03_END (9)
#define SOC_LP_SENSOR_CFG_HPM3_OPC2_hpmx_opc_min_03_START (16)
#define SOC_LP_SENSOR_CFG_HPM3_OPC2_hpmx_opc_min_03_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_04 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_04 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_04 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_04 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_04 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM4_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_START (0)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpm_clk_div_04_END (6)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpm_en_04_START (8)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpm_en_04_END (8)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpm_opc_min_en_04_START (12)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpm_opc_min_en_04_END (12)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_en_04_START (16)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_en_04_END (16)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_opc_min_en_04_START (20)
#define SOC_LP_SENSOR_CFG_HPM4_EN_hpmx_opc_min_en_04_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_04 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_04 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_04 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_04 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM4_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_04_START (0)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_04_END (9)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_vld_04_START (12)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpm_opc_vld_04_END (12)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_04_START (16)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_04_END (25)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_vld_04_START (28)
#define SOC_LP_SENSOR_CFG_HPM4_OPC1_hpmx_opc_vld_04_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_04 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_04 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM4_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM4_OPC2_hpm_opc_min_04_START (0)
#define SOC_LP_SENSOR_CFG_HPM4_OPC2_hpm_opc_min_04_END (9)
#define SOC_LP_SENSOR_CFG_HPM4_OPC2_hpmx_opc_min_04_START (16)
#define SOC_LP_SENSOR_CFG_HPM4_OPC2_hpmx_opc_min_04_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_05 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_05 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_05 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_05 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_05 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM5_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_START (0)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpm_clk_div_05_END (6)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpm_en_05_START (8)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpm_en_05_END (8)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpm_opc_min_en_05_START (12)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpm_opc_min_en_05_END (12)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_en_05_START (16)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_en_05_END (16)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_opc_min_en_05_START (20)
#define SOC_LP_SENSOR_CFG_HPM5_EN_hpmx_opc_min_en_05_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_05 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_05 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_05 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_05 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM5_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_05_START (0)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_05_END (9)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_vld_05_START (12)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpm_opc_vld_05_END (12)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_05_START (16)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_05_END (25)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_vld_05_START (28)
#define SOC_LP_SENSOR_CFG_HPM5_OPC1_hpmx_opc_vld_05_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_05 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_05 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM5_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM5_OPC2_hpm_opc_min_05_START (0)
#define SOC_LP_SENSOR_CFG_HPM5_OPC2_hpm_opc_min_05_END (9)
#define SOC_LP_SENSOR_CFG_HPM5_OPC2_hpmx_opc_min_05_START (16)
#define SOC_LP_SENSOR_CFG_HPM5_OPC2_hpmx_opc_min_05_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_06 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_06 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_06 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_06 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_06 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM6_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_START (0)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpm_clk_div_06_END (6)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpm_en_06_START (8)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpm_en_06_END (8)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpm_opc_min_en_06_START (12)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpm_opc_min_en_06_END (12)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_en_06_START (16)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_en_06_END (16)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_opc_min_en_06_START (20)
#define SOC_LP_SENSOR_CFG_HPM6_EN_hpmx_opc_min_en_06_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_06 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_06 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_06 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_06 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM6_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_06_START (0)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_06_END (9)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_vld_06_START (12)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpm_opc_vld_06_END (12)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_06_START (16)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_06_END (25)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_vld_06_START (28)
#define SOC_LP_SENSOR_CFG_HPM6_OPC1_hpmx_opc_vld_06_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_06 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_06 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM6_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM6_OPC2_hpm_opc_min_06_START (0)
#define SOC_LP_SENSOR_CFG_HPM6_OPC2_hpm_opc_min_06_END (9)
#define SOC_LP_SENSOR_CFG_HPM6_OPC2_hpmx_opc_min_06_START (16)
#define SOC_LP_SENSOR_CFG_HPM6_OPC2_hpmx_opc_min_06_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_07 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_07 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_07 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_07 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_07 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM7_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_START (0)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpm_clk_div_07_END (6)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpm_en_07_START (8)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpm_en_07_END (8)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpm_opc_min_en_07_START (12)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpm_opc_min_en_07_END (12)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_en_07_START (16)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_en_07_END (16)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_opc_min_en_07_START (20)
#define SOC_LP_SENSOR_CFG_HPM7_EN_hpmx_opc_min_en_07_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_07 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_07 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_07 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_07 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM7_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_07_START (0)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_07_END (9)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_vld_07_START (12)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpm_opc_vld_07_END (12)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_07_START (16)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_07_END (25)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_vld_07_START (28)
#define SOC_LP_SENSOR_CFG_HPM7_OPC1_hpmx_opc_vld_07_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_07 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_07 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM7_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM7_OPC2_hpm_opc_min_07_START (0)
#define SOC_LP_SENSOR_CFG_HPM7_OPC2_hpm_opc_min_07_END (9)
#define SOC_LP_SENSOR_CFG_HPM7_OPC2_hpmx_opc_min_07_START (16)
#define SOC_LP_SENSOR_CFG_HPM7_OPC2_hpmx_opc_min_07_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_08 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_08 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_08 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_08 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_08 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM8_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_START (0)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpm_clk_div_08_END (6)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpm_en_08_START (8)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpm_en_08_END (8)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpm_opc_min_en_08_START (12)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpm_opc_min_en_08_END (12)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_en_08_START (16)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_en_08_END (16)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_opc_min_en_08_START (20)
#define SOC_LP_SENSOR_CFG_HPM8_EN_hpmx_opc_min_en_08_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_08 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_08 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_08 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_08 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM8_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_08_START (0)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_08_END (9)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_vld_08_START (12)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpm_opc_vld_08_END (12)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_08_START (16)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_08_END (25)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_vld_08_START (28)
#define SOC_LP_SENSOR_CFG_HPM8_OPC1_hpmx_opc_vld_08_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_08 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_08 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM8_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM8_OPC2_hpm_opc_min_08_START (0)
#define SOC_LP_SENSOR_CFG_HPM8_OPC2_hpm_opc_min_08_END (9)
#define SOC_LP_SENSOR_CFG_HPM8_OPC2_hpmx_opc_min_08_START (16)
#define SOC_LP_SENSOR_CFG_HPM8_OPC2_hpmx_opc_min_08_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_09 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_09 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_09 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_09 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_09 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM9_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpm_clk_div_09_START (0)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpm_clk_div_09_END (6)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpm_en_09_START (8)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpm_en_09_END (8)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpm_opc_min_en_09_START (12)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpm_opc_min_en_09_END (12)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpmx_en_09_START (16)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpmx_en_09_END (16)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpmx_opc_min_en_09_START (20)
#define SOC_LP_SENSOR_CFG_HPM9_EN_hpmx_opc_min_en_09_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_09 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_09 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_09 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_09 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM9_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_09_START (0)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_09_END (9)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_vld_09_START (12)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpm_opc_vld_09_END (12)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_09_START (16)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_09_END (25)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_vld_09_START (28)
#define SOC_LP_SENSOR_CFG_HPM9_OPC1_hpmx_opc_vld_09_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_09 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_09 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM9_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM9_OPC2_hpm_opc_min_09_START (0)
#define SOC_LP_SENSOR_CFG_HPM9_OPC2_hpm_opc_min_09_END (9)
#define SOC_LP_SENSOR_CFG_HPM9_OPC2_hpmx_opc_min_09_START (16)
#define SOC_LP_SENSOR_CFG_HPM9_OPC2_hpmx_opc_min_09_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_10 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_10 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_10 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_10 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_10 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM10_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpm_clk_div_10_START (0)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpm_clk_div_10_END (6)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpm_en_10_START (8)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpm_en_10_END (8)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpm_opc_min_en_10_START (12)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpm_opc_min_en_10_END (12)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpmx_en_10_START (16)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpmx_en_10_END (16)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpmx_opc_min_en_10_START (20)
#define SOC_LP_SENSOR_CFG_HPM10_EN_hpmx_opc_min_en_10_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_10 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_10 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_10 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_10 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM10_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_10_START (0)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_10_END (9)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_vld_10_START (12)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpm_opc_vld_10_END (12)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_10_START (16)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_10_END (25)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_vld_10_START (28)
#define SOC_LP_SENSOR_CFG_HPM10_OPC1_hpmx_opc_vld_10_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_10 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM10_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM10_OPC2_hpm_opc_min_10_START (0)
#define SOC_LP_SENSOR_CFG_HPM10_OPC2_hpm_opc_min_10_END (9)
#define SOC_LP_SENSOR_CFG_HPM10_OPC2_hpmx_opc_min_10_START (16)
#define SOC_LP_SENSOR_CFG_HPM10_OPC2_hpmx_opc_min_10_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_11 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_11 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_11 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_11 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_11 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM11_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpm_clk_div_11_START (0)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpm_clk_div_11_END (6)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpm_en_11_START (8)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpm_en_11_END (8)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpm_opc_min_en_11_START (12)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpm_opc_min_en_11_END (12)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpmx_en_11_START (16)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpmx_en_11_END (16)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpmx_opc_min_en_11_START (20)
#define SOC_LP_SENSOR_CFG_HPM11_EN_hpmx_opc_min_en_11_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_11 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_11 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_11 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_11 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM11_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_11_START (0)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_11_END (9)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_vld_11_START (12)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpm_opc_vld_11_END (12)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_11_START (16)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_11_END (25)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_vld_11_START (28)
#define SOC_LP_SENSOR_CFG_HPM11_OPC1_hpmx_opc_vld_11_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_11 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM11_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM11_OPC2_hpm_opc_min_11_START (0)
#define SOC_LP_SENSOR_CFG_HPM11_OPC2_hpm_opc_min_11_END (9)
#define SOC_LP_SENSOR_CFG_HPM11_OPC2_hpmx_opc_min_11_START (16)
#define SOC_LP_SENSOR_CFG_HPM11_OPC2_hpmx_opc_min_11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_12 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_12 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_12 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_12 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_12 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM12_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpm_clk_div_12_START (0)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpm_clk_div_12_END (6)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpm_en_12_START (8)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpm_en_12_END (8)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpm_opc_min_en_12_START (12)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpm_opc_min_en_12_END (12)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpmx_en_12_START (16)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpmx_en_12_END (16)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpmx_opc_min_en_12_START (20)
#define SOC_LP_SENSOR_CFG_HPM12_EN_hpmx_opc_min_en_12_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_12 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_12 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_12 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_12 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM12_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpm_opc_12_START (0)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpm_opc_12_END (9)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpm_opc_vld_12_START (12)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpm_opc_vld_12_END (12)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpmx_opc_12_START (16)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpmx_opc_12_END (25)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpmx_opc_vld_12_START (28)
#define SOC_LP_SENSOR_CFG_HPM12_OPC1_hpmx_opc_vld_12_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_12 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM12_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM12_OPC2_hpm_opc_min_12_START (0)
#define SOC_LP_SENSOR_CFG_HPM12_OPC2_hpm_opc_min_12_END (9)
#define SOC_LP_SENSOR_CFG_HPM12_OPC2_hpmx_opc_min_12_START (16)
#define SOC_LP_SENSOR_CFG_HPM12_OPC2_hpmx_opc_min_12_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_13 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_13 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_13 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_13 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_13 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM13_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpm_clk_div_13_START (0)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpm_clk_div_13_END (6)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpm_en_13_START (8)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpm_en_13_END (8)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpm_opc_min_en_13_START (12)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpm_opc_min_en_13_END (12)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpmx_en_13_START (16)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpmx_en_13_END (16)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpmx_opc_min_en_13_START (20)
#define SOC_LP_SENSOR_CFG_HPM13_EN_hpmx_opc_min_en_13_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_13 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_13 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_13 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_13 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM13_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpm_opc_13_START (0)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpm_opc_13_END (9)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpm_opc_vld_13_START (12)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpm_opc_vld_13_END (12)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpmx_opc_13_START (16)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpmx_opc_13_END (25)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpmx_opc_vld_13_START (28)
#define SOC_LP_SENSOR_CFG_HPM13_OPC1_hpmx_opc_vld_13_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_13 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM13_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM13_OPC2_hpm_opc_min_13_START (0)
#define SOC_LP_SENSOR_CFG_HPM13_OPC2_hpm_opc_min_13_END (9)
#define SOC_LP_SENSOR_CFG_HPM13_OPC2_hpmx_opc_min_13_START (16)
#define SOC_LP_SENSOR_CFG_HPM13_OPC2_hpmx_opc_min_13_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_14 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_14 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_14 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_14 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_14 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM14_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpm_clk_div_14_START (0)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpm_clk_div_14_END (6)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpm_en_14_START (8)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpm_en_14_END (8)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpm_opc_min_en_14_START (12)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpm_opc_min_en_14_END (12)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpmx_en_14_START (16)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpmx_en_14_END (16)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpmx_opc_min_en_14_START (20)
#define SOC_LP_SENSOR_CFG_HPM14_EN_hpmx_opc_min_en_14_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_14 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_14 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_14 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_14 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM14_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpm_opc_14_START (0)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpm_opc_14_END (9)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpm_opc_vld_14_START (12)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpm_opc_vld_14_END (12)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpmx_opc_14_START (16)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpmx_opc_14_END (25)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpmx_opc_vld_14_START (28)
#define SOC_LP_SENSOR_CFG_HPM14_OPC1_hpmx_opc_vld_14_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_14 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_14 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM14_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM14_OPC2_hpm_opc_min_14_START (0)
#define SOC_LP_SENSOR_CFG_HPM14_OPC2_hpm_opc_min_14_END (9)
#define SOC_LP_SENSOR_CFG_HPM14_OPC2_hpmx_opc_min_14_START (16)
#define SOC_LP_SENSOR_CFG_HPM14_OPC2_hpmx_opc_min_14_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_15 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_15 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_15 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_15 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_15 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM15_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpm_clk_div_15_START (0)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpm_clk_div_15_END (6)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpm_en_15_START (8)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpm_en_15_END (8)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpm_opc_min_en_15_START (12)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpm_opc_min_en_15_END (12)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpmx_en_15_START (16)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpmx_en_15_END (16)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpmx_opc_min_en_15_START (20)
#define SOC_LP_SENSOR_CFG_HPM15_EN_hpmx_opc_min_en_15_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_15 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_15 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_15 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_15 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM15_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpm_opc_15_START (0)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpm_opc_15_END (9)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpm_opc_vld_15_START (12)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpm_opc_vld_15_END (12)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpmx_opc_15_START (16)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpmx_opc_15_END (25)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpmx_opc_vld_15_START (28)
#define SOC_LP_SENSOR_CFG_HPM15_OPC1_hpmx_opc_vld_15_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_15 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_15 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM15_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM15_OPC2_hpm_opc_min_15_START (0)
#define SOC_LP_SENSOR_CFG_HPM15_OPC2_hpm_opc_min_15_END (9)
#define SOC_LP_SENSOR_CFG_HPM15_OPC2_hpmx_opc_min_15_START (16)
#define SOC_LP_SENSOR_CFG_HPM15_OPC2_hpmx_opc_min_15_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_16 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_16 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_16 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_16 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_16 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM16_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpm_clk_div_16_START (0)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpm_clk_div_16_END (6)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpm_en_16_START (8)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpm_en_16_END (8)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpm_opc_min_en_16_START (12)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpm_opc_min_en_16_END (12)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpmx_en_16_START (16)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpmx_en_16_END (16)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpmx_opc_min_en_16_START (20)
#define SOC_LP_SENSOR_CFG_HPM16_EN_hpmx_opc_min_en_16_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_16 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_16 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_16 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_16 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM16_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpm_opc_16_START (0)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpm_opc_16_END (9)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpm_opc_vld_16_START (12)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpm_opc_vld_16_END (12)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpmx_opc_16_START (16)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpmx_opc_16_END (25)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpmx_opc_vld_16_START (28)
#define SOC_LP_SENSOR_CFG_HPM16_OPC1_hpmx_opc_vld_16_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_16 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_16 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM16_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM16_OPC2_hpm_opc_min_16_START (0)
#define SOC_LP_SENSOR_CFG_HPM16_OPC2_hpm_opc_min_16_END (9)
#define SOC_LP_SENSOR_CFG_HPM16_OPC2_hpmx_opc_min_16_START (16)
#define SOC_LP_SENSOR_CFG_HPM16_OPC2_hpmx_opc_min_16_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_17 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_17 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_17 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_17 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_17 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM17_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpm_clk_div_17_START (0)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpm_clk_div_17_END (6)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpm_en_17_START (8)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpm_en_17_END (8)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpm_opc_min_en_17_START (12)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpm_opc_min_en_17_END (12)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpmx_en_17_START (16)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpmx_en_17_END (16)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpmx_opc_min_en_17_START (20)
#define SOC_LP_SENSOR_CFG_HPM17_EN_hpmx_opc_min_en_17_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_17 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_17 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_17 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_17 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM17_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpm_opc_17_START (0)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpm_opc_17_END (9)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpm_opc_vld_17_START (12)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpm_opc_vld_17_END (12)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpmx_opc_17_START (16)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpmx_opc_17_END (25)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpmx_opc_vld_17_START (28)
#define SOC_LP_SENSOR_CFG_HPM17_OPC1_hpmx_opc_vld_17_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_17 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_17 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM17_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM17_OPC2_hpm_opc_min_17_START (0)
#define SOC_LP_SENSOR_CFG_HPM17_OPC2_hpm_opc_min_17_END (9)
#define SOC_LP_SENSOR_CFG_HPM17_OPC2_hpmx_opc_min_17_START (16)
#define SOC_LP_SENSOR_CFG_HPM17_OPC2_hpmx_opc_min_17_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_18 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_18 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_18 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_18 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_18 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM18_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpm_clk_div_18_START (0)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpm_clk_div_18_END (6)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpm_en_18_START (8)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpm_en_18_END (8)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpm_opc_min_en_18_START (12)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpm_opc_min_en_18_END (12)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpmx_en_18_START (16)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpmx_en_18_END (16)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpmx_opc_min_en_18_START (20)
#define SOC_LP_SENSOR_CFG_HPM18_EN_hpmx_opc_min_en_18_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_18 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_18 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_18 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_18 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM18_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpm_opc_18_START (0)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpm_opc_18_END (9)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpm_opc_vld_18_START (12)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpm_opc_vld_18_END (12)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpmx_opc_18_START (16)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpmx_opc_18_END (25)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpmx_opc_vld_18_START (28)
#define SOC_LP_SENSOR_CFG_HPM18_OPC1_hpmx_opc_vld_18_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_18 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_18 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM18_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM18_OPC2_hpm_opc_min_18_START (0)
#define SOC_LP_SENSOR_CFG_HPM18_OPC2_hpm_opc_min_18_END (9)
#define SOC_LP_SENSOR_CFG_HPM18_OPC2_hpmx_opc_min_18_START (16)
#define SOC_LP_SENSOR_CFG_HPM18_OPC2_hpmx_opc_min_18_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_19 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_19 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_19 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_19 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_19 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM19_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpm_clk_div_19_START (0)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpm_clk_div_19_END (6)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpm_en_19_START (8)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpm_en_19_END (8)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpm_opc_min_en_19_START (12)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpm_opc_min_en_19_END (12)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpmx_en_19_START (16)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpmx_en_19_END (16)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpmx_opc_min_en_19_START (20)
#define SOC_LP_SENSOR_CFG_HPM19_EN_hpmx_opc_min_en_19_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_19 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_19 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_19 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_19 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM19_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpm_opc_19_START (0)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpm_opc_19_END (9)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpm_opc_vld_19_START (12)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpm_opc_vld_19_END (12)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpmx_opc_19_START (16)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpmx_opc_19_END (25)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpmx_opc_vld_19_START (28)
#define SOC_LP_SENSOR_CFG_HPM19_OPC1_hpmx_opc_vld_19_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_19 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_19 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM19_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM19_OPC2_hpm_opc_min_19_START (0)
#define SOC_LP_SENSOR_CFG_HPM19_OPC2_hpm_opc_min_19_END (9)
#define SOC_LP_SENSOR_CFG_HPM19_OPC2_hpmx_opc_min_19_START (16)
#define SOC_LP_SENSOR_CFG_HPM19_OPC2_hpmx_opc_min_19_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_20 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_20 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_20 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_20 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_20 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM20_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpm_clk_div_20_START (0)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpm_clk_div_20_END (6)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpm_en_20_START (8)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpm_en_20_END (8)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpm_opc_min_en_20_START (12)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpm_opc_min_en_20_END (12)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpmx_en_20_START (16)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpmx_en_20_END (16)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpmx_opc_min_en_20_START (20)
#define SOC_LP_SENSOR_CFG_HPM20_EN_hpmx_opc_min_en_20_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_20 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_20 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_20 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_20 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM20_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpm_opc_20_START (0)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpm_opc_20_END (9)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpm_opc_vld_20_START (12)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpm_opc_vld_20_END (12)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpmx_opc_20_START (16)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpmx_opc_20_END (25)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpmx_opc_vld_20_START (28)
#define SOC_LP_SENSOR_CFG_HPM20_OPC1_hpmx_opc_vld_20_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_20 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_20 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM20_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM20_OPC2_hpm_opc_min_20_START (0)
#define SOC_LP_SENSOR_CFG_HPM20_OPC2_hpm_opc_min_20_END (9)
#define SOC_LP_SENSOR_CFG_HPM20_OPC2_hpmx_opc_min_20_START (16)
#define SOC_LP_SENSOR_CFG_HPM20_OPC2_hpmx_opc_min_20_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_21 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_21 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_21 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_21 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_21 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM21_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpm_clk_div_21_START (0)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpm_clk_div_21_END (6)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpm_en_21_START (8)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpm_en_21_END (8)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpm_opc_min_en_21_START (12)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpm_opc_min_en_21_END (12)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpmx_en_21_START (16)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpmx_en_21_END (16)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpmx_opc_min_en_21_START (20)
#define SOC_LP_SENSOR_CFG_HPM21_EN_hpmx_opc_min_en_21_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_21 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_21 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_21 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_21 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM21_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpm_opc_21_START (0)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpm_opc_21_END (9)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpm_opc_vld_21_START (12)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpm_opc_vld_21_END (12)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpmx_opc_21_START (16)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpmx_opc_21_END (25)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpmx_opc_vld_21_START (28)
#define SOC_LP_SENSOR_CFG_HPM21_OPC1_hpmx_opc_vld_21_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_21 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_21 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM21_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM21_OPC2_hpm_opc_min_21_START (0)
#define SOC_LP_SENSOR_CFG_HPM21_OPC2_hpm_opc_min_21_END (9)
#define SOC_LP_SENSOR_CFG_HPM21_OPC2_hpmx_opc_min_21_START (16)
#define SOC_LP_SENSOR_CFG_HPM21_OPC2_hpmx_opc_min_21_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_22 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_22 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_22 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_22 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_22 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM22_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpm_clk_div_22_START (0)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpm_clk_div_22_END (6)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpm_en_22_START (8)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpm_en_22_END (8)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpm_opc_min_en_22_START (12)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpm_opc_min_en_22_END (12)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpmx_en_22_START (16)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpmx_en_22_END (16)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpmx_opc_min_en_22_START (20)
#define SOC_LP_SENSOR_CFG_HPM22_EN_hpmx_opc_min_en_22_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_22 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_22 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_22 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_22 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM22_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpm_opc_22_START (0)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpm_opc_22_END (9)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpm_opc_vld_22_START (12)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpm_opc_vld_22_END (12)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpmx_opc_22_START (16)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpmx_opc_22_END (25)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpmx_opc_vld_22_START (28)
#define SOC_LP_SENSOR_CFG_HPM22_OPC1_hpmx_opc_vld_22_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_22 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_22 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM22_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM22_OPC2_hpm_opc_min_22_START (0)
#define SOC_LP_SENSOR_CFG_HPM22_OPC2_hpm_opc_min_22_END (9)
#define SOC_LP_SENSOR_CFG_HPM22_OPC2_hpmx_opc_min_22_START (16)
#define SOC_LP_SENSOR_CFG_HPM22_OPC2_hpmx_opc_min_22_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_23 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_23 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_23 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_23 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_23 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM23_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpm_clk_div_23_START (0)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpm_clk_div_23_END (6)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpm_en_23_START (8)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpm_en_23_END (8)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpm_opc_min_en_23_START (12)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpm_opc_min_en_23_END (12)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpmx_en_23_START (16)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpmx_en_23_END (16)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpmx_opc_min_en_23_START (20)
#define SOC_LP_SENSOR_CFG_HPM23_EN_hpmx_opc_min_en_23_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_23 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_23 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_23 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_23 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM23_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpm_opc_23_START (0)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpm_opc_23_END (9)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpm_opc_vld_23_START (12)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpm_opc_vld_23_END (12)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpmx_opc_23_START (16)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpmx_opc_23_END (25)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpmx_opc_vld_23_START (28)
#define SOC_LP_SENSOR_CFG_HPM23_OPC1_hpmx_opc_vld_23_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_23 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_23 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM23_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM23_OPC2_hpm_opc_min_23_START (0)
#define SOC_LP_SENSOR_CFG_HPM23_OPC2_hpm_opc_min_23_END (9)
#define SOC_LP_SENSOR_CFG_HPM23_OPC2_hpmx_opc_min_23_START (16)
#define SOC_LP_SENSOR_CFG_HPM23_OPC2_hpmx_opc_min_23_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_24 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_24 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_24 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_24 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_24 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM24_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpm_clk_div_24_START (0)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpm_clk_div_24_END (6)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpm_en_24_START (8)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpm_en_24_END (8)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpm_opc_min_en_24_START (12)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpm_opc_min_en_24_END (12)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpmx_en_24_START (16)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpmx_en_24_END (16)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpmx_opc_min_en_24_START (20)
#define SOC_LP_SENSOR_CFG_HPM24_EN_hpmx_opc_min_en_24_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_24 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_24 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_24 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_24 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM24_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpm_opc_24_START (0)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpm_opc_24_END (9)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpm_opc_vld_24_START (12)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpm_opc_vld_24_END (12)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpmx_opc_24_START (16)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpmx_opc_24_END (25)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpmx_opc_vld_24_START (28)
#define SOC_LP_SENSOR_CFG_HPM24_OPC1_hpmx_opc_vld_24_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_24 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_24 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM24_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM24_OPC2_hpm_opc_min_24_START (0)
#define SOC_LP_SENSOR_CFG_HPM24_OPC2_hpm_opc_min_24_END (9)
#define SOC_LP_SENSOR_CFG_HPM24_OPC2_hpmx_opc_min_24_START (16)
#define SOC_LP_SENSOR_CFG_HPM24_OPC2_hpmx_opc_min_24_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_clk_div_25 : 7;
        unsigned int reserved_0 : 1;
        unsigned int hpm_en_25 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_opc_min_en_25 : 1;
        unsigned int reserved_2 : 3;
        unsigned int hpmx_en_25 : 1;
        unsigned int reserved_3 : 3;
        unsigned int hpmx_opc_min_en_25 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPM25_EN_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpm_clk_div_25_START (0)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpm_clk_div_25_END (6)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpm_en_25_START (8)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpm_en_25_END (8)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpm_opc_min_en_25_START (12)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpm_opc_min_en_25_END (12)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpmx_en_25_START (16)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpmx_en_25_END (16)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpmx_opc_min_en_25_START (20)
#define SOC_LP_SENSOR_CFG_HPM25_EN_hpmx_opc_min_en_25_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_25 : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_vld_25 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc_25 : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld_25 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_HPM25_OPC1_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpm_opc_25_START (0)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpm_opc_25_END (9)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpm_opc_vld_25_START (12)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpm_opc_vld_25_END (12)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpmx_opc_25_START (16)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpmx_opc_25_END (25)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpmx_opc_vld_25_START (28)
#define SOC_LP_SENSOR_CFG_HPM25_OPC1_hpmx_opc_vld_25_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpm_opc_min_25 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hpmx_opc_min_25 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LP_SENSOR_CFG_HPM25_OPC2_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPM25_OPC2_hpm_opc_min_25_START (0)
#define SOC_LP_SENSOR_CFG_HPM25_OPC2_hpm_opc_min_25_END (9)
#define SOC_LP_SENSOR_CFG_HPM25_OPC2_hpmx_opc_min_25_START (16)
#define SOC_LP_SENSOR_CFG_HPM25_OPC2_hpmx_opc_min_25_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_en_00 : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmp_opc_vld_00 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmp_opc_00 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_CTRL_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_hpmp_en_00_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_hpmp_en_00_END (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_hpmp_opc_vld_00_START (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_hpmp_opc_vld_00_END (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_hpmp_opc_00_START (8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_00_hpmp_opc_00_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_dl_trim_00 : 32;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_00_hpmp_dl_trim_00_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_00_hpmp_dl_trim_00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_en_01 : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmp_opc_vld_01 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmp_opc_01 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_CTRL_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_hpmp_en_01_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_hpmp_en_01_END (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_hpmp_opc_vld_01_START (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_hpmp_opc_vld_01_END (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_hpmp_opc_01_START (8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_01_hpmp_opc_01_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_dl_trim_01 : 32;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_01_hpmp_dl_trim_01_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_01_hpmp_dl_trim_01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_en_02 : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmp_opc_vld_02 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmp_opc_02 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_CTRL_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_hpmp_en_02_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_hpmp_en_02_END (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_hpmp_opc_vld_02_START (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_hpmp_opc_vld_02_END (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_hpmp_opc_02_START (8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_02_hpmp_opc_02_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_dl_trim_02 : 32;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_02_hpmp_dl_trim_02_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_02_hpmp_dl_trim_02_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_en_03 : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmp_opc_vld_03 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmp_opc_03 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_CTRL_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_hpmp_en_03_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_hpmp_en_03_END (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_hpmp_opc_vld_03_START (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_hpmp_opc_vld_03_END (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_hpmp_opc_03_START (8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_03_hpmp_opc_03_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_dl_trim : 32;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_03_hpmp_dl_trim_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_03_hpmp_dl_trim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_en_04 : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmp_opc_vld_04 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmp_opc_04 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_CTRL_04_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_hpmp_en_04_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_hpmp_en_04_END (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_hpmp_opc_vld_04_START (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_hpmp_opc_vld_04_END (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_hpmp_opc_04_START (8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_04_hpmp_opc_04_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_dl_trim_04 : 32;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_04_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_04_hpmp_dl_trim_04_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_04_hpmp_dl_trim_04_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_en_05 : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmp_opc_vld_05 : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmp_opc_05 : 10;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_CTRL_05_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_hpmp_en_05_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_hpmp_en_05_END (0)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_hpmp_opc_vld_05_START (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_hpmp_opc_vld_05_END (4)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_hpmp_opc_05_START (8)
#define SOC_LP_SENSOR_CFG_HPMP_CTRL_05_hpmp_opc_05_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hpmp_dl_trim_05 : 32;
    } reg;
} SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_05_UNION;
#endif
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_05_hpmp_dl_trim_05_START (0)
#define SOC_LP_SENSOR_CFG_HPMP_DL_TRIM_05_hpmp_dl_trim_05_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pcr_gpio_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_LP_SENSOR_CFG_PCR_CTRL_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PCR_CTRL_pcr_gpio_sel_START (0)
#define SOC_LP_SENSOR_CFG_PCR_CTRL_pcr_gpio_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dpm_clk_sel : 1;
        unsigned int reserved : 15;
        unsigned int lp_sensor_ctrl_dpmamask : 16;
    } reg;
} SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_UNION;
#endif
#define SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_dpm_clk_sel_START (0)
#define SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_dpm_clk_sel_END (0)
#define SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_lp_sensor_ctrl_dpmamask_START (16)
#define SOC_LP_SENSOR_CFG_LP_SENSOR_CTRL_DPM_lp_sensor_ctrl_dpmamask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_cfg_valid_00 : 1;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_cmd_00 : 2;
        unsigned int reserved_1 : 2;
        unsigned int pasensor_en_00 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_ctrl_00 : 6;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_cfg_valid_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_cfg_valid_00_END (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_cmd_00_START (4)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_cmd_00_END (5)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_en_00_START (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_en_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_ctrl_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_00_pasensor_ctrl_00_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_msg_00 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_00_pasensor_msg_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_00_pasensor_msg_00_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_svt_00 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_svt_00 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_svt_00 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_svt_00 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_hci_a_out_svt_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_hci_a_out_svt_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_hci_o_out_svt_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_hci_o_out_svt_00_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_valid_svt_00_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_valid_svt_00_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_cfg_ready_svt_00_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_00_pasensor_cfg_ready_svt_00_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_svt_00 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_svt_00 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_pasensor_nbti_a_out_svt_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_pasensor_nbti_a_out_svt_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_pasensor_nbti_o_out_svt_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_00_pasensor_nbti_o_out_svt_00_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_lvt_00 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_lvt_00 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_lvt_00 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_lvt_00 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_hci_a_out_lvt_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_hci_a_out_lvt_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_hci_o_out_lvt_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_hci_o_out_lvt_00_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_valid_lvt_00_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_valid_lvt_00_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_cfg_ready_lvt_00_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_00_pasensor_cfg_ready_lvt_00_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_lvt_00 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_lvt_00 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_pasensor_nbti_a_out_lvt_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_pasensor_nbti_a_out_lvt_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_pasensor_nbti_o_out_lvt_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_00_pasensor_nbti_o_out_lvt_00_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_ulvt_00 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_ulvt_00 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_ulvt_00 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_ulvt_00 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_hci_a_out_ulvt_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_hci_a_out_ulvt_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_hci_o_out_ulvt_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_hci_o_out_ulvt_00_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_valid_ulvt_00_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_valid_ulvt_00_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_cfg_ready_ulvt_00_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_00_pasensor_cfg_ready_ulvt_00_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_ulvt_00 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_ulvt_00 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_pasensor_nbti_a_out_ulvt_00_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_pasensor_nbti_a_out_ulvt_00_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_pasensor_nbti_o_out_ulvt_00_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_00_pasensor_nbti_o_out_ulvt_00_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_cfg_valid_01 : 1;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_cmd_01 : 2;
        unsigned int reserved_1 : 2;
        unsigned int pasensor_en_01 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_ctrl_01 : 6;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_cfg_valid_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_cfg_valid_01_END (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_cmd_01_START (4)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_cmd_01_END (5)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_en_01_START (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_en_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_ctrl_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_01_pasensor_ctrl_01_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_msg_01 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_01_pasensor_msg_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_01_pasensor_msg_01_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_svt_01 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_svt_01 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_svt_01 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_svt_01 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_hci_a_out_svt_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_hci_a_out_svt_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_hci_o_out_svt_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_hci_o_out_svt_01_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_valid_svt_01_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_valid_svt_01_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_cfg_ready_svt_01_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_01_pasensor_cfg_ready_svt_01_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_svt_01 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_svt_01 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_pasensor_nbti_a_out_svt_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_pasensor_nbti_a_out_svt_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_pasensor_nbti_o_out_svt_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_01_pasensor_nbti_o_out_svt_01_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_lvt_01 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_lvt_01 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_lvt_01 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_lvt_01 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_hci_a_out_lvt_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_hci_a_out_lvt_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_hci_o_out_lvt_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_hci_o_out_lvt_01_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_valid_lvt_01_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_valid_lvt_01_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_cfg_ready_lvt_01_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_01_pasensor_cfg_ready_lvt_01_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_lvt_01 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_lvt_01 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_pasensor_nbti_a_out_lvt_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_pasensor_nbti_a_out_lvt_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_pasensor_nbti_o_out_lvt_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_01_pasensor_nbti_o_out_lvt_01_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_ulvt_01 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_ulvt_01 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_ulvt_01 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_ulvt_01 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_hci_a_out_ulvt_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_hci_a_out_ulvt_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_hci_o_out_ulvt_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_hci_o_out_ulvt_01_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_valid_ulvt_01_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_valid_ulvt_01_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_cfg_ready_ulvt_01_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_01_pasensor_cfg_ready_ulvt_01_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_ulvt_01 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_ulvt_01 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_pasensor_nbti_a_out_ulvt_01_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_pasensor_nbti_a_out_ulvt_01_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_pasensor_nbti_o_out_ulvt_01_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_01_pasensor_nbti_o_out_ulvt_01_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_cfg_valid_02 : 1;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_cmd_02 : 2;
        unsigned int reserved_1 : 2;
        unsigned int pasensor_en_02 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_ctrl_02 : 6;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_cfg_valid_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_cfg_valid_02_END (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_cmd_02_START (4)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_cmd_02_END (5)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_en_02_START (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_en_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_ctrl_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_02_pasensor_ctrl_02_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_msg_02 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_02_pasensor_msg_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_02_pasensor_msg_02_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_svt_02 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_svt_02 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_svt_02 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_svt_02 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_hci_a_out_svt_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_hci_a_out_svt_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_hci_o_out_svt_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_hci_o_out_svt_02_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_valid_svt_02_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_valid_svt_02_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_cfg_ready_svt_02_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_02_pasensor_cfg_ready_svt_02_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_svt_02 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_svt_02 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_pasensor_nbti_a_out_svt_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_pasensor_nbti_a_out_svt_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_pasensor_nbti_o_out_svt_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_02_pasensor_nbti_o_out_svt_02_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_lvt_02 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_lvt_02 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_lvt_02 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_lvt_02 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_hci_a_out_lvt_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_hci_a_out_lvt_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_hci_o_out_lvt_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_hci_o_out_lvt_02_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_valid_lvt_02_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_valid_lvt_02_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_cfg_ready_lvt_02_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_02_pasensor_cfg_ready_lvt_02_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_lvt_02 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_lvt_02 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_pasensor_nbti_a_out_lvt_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_pasensor_nbti_a_out_lvt_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_pasensor_nbti_o_out_lvt_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_02_pasensor_nbti_o_out_lvt_02_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_ulvt_02 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_ulvt_02 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_ulvt_02 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_ulvt_02 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_hci_a_out_ulvt_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_hci_a_out_ulvt_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_hci_o_out_ulvt_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_hci_o_out_ulvt_02_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_valid_ulvt_02_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_valid_ulvt_02_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_cfg_ready_ulvt_02_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_02_pasensor_cfg_ready_ulvt_02_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_ulvt_02 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_ulvt_02 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_pasensor_nbti_a_out_ulvt_02_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_pasensor_nbti_a_out_ulvt_02_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_pasensor_nbti_o_out_ulvt_02_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_02_pasensor_nbti_o_out_ulvt_02_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_cfg_valid_03 : 1;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_cmd_03 : 2;
        unsigned int reserved_1 : 2;
        unsigned int pasensor_en_03 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_ctrl_03 : 6;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_cfg_valid_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_cfg_valid_03_END (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_cmd_03_START (4)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_cmd_03_END (5)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_en_03_START (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_en_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_ctrl_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL1_03_pasensor_ctrl_03_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_msg_03 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_03_pasensor_msg_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_CTRL2_03_pasensor_msg_03_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_svt_03 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_svt_03 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_svt_03 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_svt_03 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_hci_a_out_svt_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_hci_a_out_svt_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_hci_o_out_svt_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_hci_o_out_svt_03_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_valid_svt_03_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_valid_svt_03_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_cfg_ready_svt_03_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT1_03_pasensor_cfg_ready_svt_03_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_svt_03 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_svt_03 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_pasensor_nbti_a_out_svt_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_pasensor_nbti_a_out_svt_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_pasensor_nbti_o_out_svt_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_SVT_STAT2_03_pasensor_nbti_o_out_svt_03_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_lvt_03 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_lvt_03 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_lvt_03 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_lvt_03 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_hci_a_out_lvt_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_hci_a_out_lvt_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_hci_o_out_lvt_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_hci_o_out_lvt_03_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_valid_lvt_03_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_valid_lvt_03_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_cfg_ready_lvt_03_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT1_03_pasensor_cfg_ready_lvt_03_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_lvt_03 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_lvt_03 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_pasensor_nbti_a_out_lvt_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_pasensor_nbti_a_out_lvt_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_pasensor_nbti_o_out_lvt_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_LVT_STAT2_03_pasensor_nbti_o_out_lvt_03_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_hci_a_out_ulvt_03 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out_ulvt_03 : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid_ulvt_03 : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready_ulvt_03 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_hci_a_out_ulvt_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_hci_a_out_ulvt_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_hci_o_out_ulvt_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_hci_o_out_ulvt_03_END (20)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_valid_ulvt_03_START (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_valid_ulvt_03_END (24)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_cfg_ready_ulvt_03_START (28)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT1_03_pasensor_cfg_ready_ulvt_03_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pasensor_nbti_a_out_ulvt_03 : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out_ulvt_03 : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_UNION;
#endif
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_pasensor_nbti_a_out_ulvt_03_START (0)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_pasensor_nbti_a_out_ulvt_03_END (8)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_pasensor_nbti_o_out_ulvt_03_START (12)
#define SOC_LP_SENSOR_CFG_PASENSOR_ULVT_STAT2_03_pasensor_nbti_o_out_ulvt_03_END (20)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
