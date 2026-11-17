#ifndef __SOC_XPU_LP_CTRL_CFG_INTERFACE_H__
#define __SOC_XPU_LP_CTRL_CFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_ADDR(base) ((base) + (0x000UL))
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_ADDR(base) ((base) + (0x004UL))
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_ADDR(base) ((base) + (0x00CUL))
#define SOC_XPU_LP_CTRL_CFG_PEREN0_ADDR(base) ((base) + (0x010UL))
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_ADDR(base) ((base) + (0x014UL))
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_ADDR(base) ((base) + (0x018UL))
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_ADDR(base) ((base) + (0x01CUL))
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_ADDR(base) ((base) + (0x020UL))
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ADDR(base) ((base) + (0x050UL))
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ADDR(base) ((base) + (0x054UL))
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ADDR(base) ((base) + (0x058UL))
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_ADDR(base) ((base) + (0x024UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_ADDR(base) ((base) + (0x030UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT1_ADDR(base) ((base) + (0x03CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_ADDR(base) ((base) + (0x0A0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_1_ADDR(base) ((base) + (0x0A4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_NMI_SOFT_ADDR(base) ((base) + (0x0A8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_ADDR(base) ((base) + (0x0ACUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_ADDR(base) ((base) + (0x0B0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_START_ADDR_ADDR(base) ((base) + (0x0C0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_END_ADDR_ADDR(base) ((base) + (0x0C4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_START_ADDR_ADDR(base) ((base) + (0x0C8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_END_ADDR_ADDR(base) ((base) + (0x0CCUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_START_ADDR_ADDR(base) ((base) + (0x0D0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_END_ADDR_ADDR(base) ((base) + (0x0D4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_START_ADDR_ADDR(base) ((base) + (0x0D8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_END_ADDR_ADDR(base) ((base) + (0x0DCUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_RST_PC_ADDR(base) ((base) + (0x0E0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X1_ADDR(base) ((base) + (0x118UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X2_ADDR(base) ((base) + (0x11CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X3_ADDR(base) ((base) + (0x120UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X4_ADDR(base) ((base) + (0x124UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X5_ADDR(base) ((base) + (0x128UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X6_ADDR(base) ((base) + (0x12CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X7_ADDR(base) ((base) + (0x130UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X8_ADDR(base) ((base) + (0x134UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X9_ADDR(base) ((base) + (0x138UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X10_ADDR(base) ((base) + (0x13CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X11_ADDR(base) ((base) + (0x140UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X12_ADDR(base) ((base) + (0x144UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X13_ADDR(base) ((base) + (0x148UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X14_ADDR(base) ((base) + (0x14CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X15_ADDR(base) ((base) + (0x150UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X16_ADDR(base) ((base) + (0x154UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X17_ADDR(base) ((base) + (0x158UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X18_ADDR(base) ((base) + (0x15CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X19_ADDR(base) ((base) + (0x160UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X20_ADDR(base) ((base) + (0x164UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X21_ADDR(base) ((base) + (0x168UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X22_ADDR(base) ((base) + (0x16CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X23_ADDR(base) ((base) + (0x170UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X24_ADDR(base) ((base) + (0x174UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X25_ADDR(base) ((base) + (0x178UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X26_ADDR(base) ((base) + (0x17CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X27_ADDR(base) ((base) + (0x180UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X28_ADDR(base) ((base) + (0x184UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X29_ADDR(base) ((base) + (0x188UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X30_ADDR(base) ((base) + (0x18CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X31_ADDR(base) ((base) + (0x190UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MEM_CTRL1_ADDR(base) ((base) + (0x194UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_ADDR(base) ((base) + (0x300UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_ADDR(base) ((base) + (0x304UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_ADDR(base) ((base) + (0x308UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_MASK_ADDR(base) ((base) + (0x30CUL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_MASK_ADDR(base) ((base) + (0x310UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_MASK_ADDR(base) ((base) + (0x314UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_RAW_ADDR(base) ((base) + (0x318UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_RAW_ADDR(base) ((base) + (0x31CUL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_RAW_ADDR(base) ((base) + (0x320UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_ADDR(base) ((base) + (0x324UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_ADDR(base) ((base) + (0x328UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_ADDR(base) ((base) + (0x32CUL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_ADDR(base) ((base) + (0x330UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_ADDR(base) ((base) + (0x340UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_ADDR(base) ((base) + (0x334UL))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_ADDR(base) ((base) + (0x338UL))
#define SOC_XPU_LP_CTRL_CFG_INT_SYNC_CTRL_ADDR(base) ((base) + (0x33CUL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_ADDR(base) ((base) + (0x380UL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_ADDR(base) ((base) + (0x384UL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_ADDR(base) ((base) + (0x388UL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_ADDR(base) ((base) + (0x38CUL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_ADDR(base) ((base) + (0x390UL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_ADDR(base) ((base) + (0x394UL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_ADDR(base) ((base) + (0x398UL))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_ADDR(base) ((base) + (0x39CUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA0_ADDR(base) ((base) + (0x3A0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA1_ADDR(base) ((base) + (0x3A4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA2_ADDR(base) ((base) + (0x3A8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA3_ADDR(base) ((base) + (0x3ACUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA4_ADDR(base) ((base) + (0x3B0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA5_ADDR(base) ((base) + (0x3B4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA6_ADDR(base) ((base) + (0x3B8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA7_ADDR(base) ((base) + (0x3BCUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA8_ADDR(base) ((base) + (0x3C0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA9_ADDR(base) ((base) + (0x3C4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA10_ADDR(base) ((base) + (0x3C8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA11_ADDR(base) ((base) + (0x3CCUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA12_ADDR(base) ((base) + (0x3D0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA13_ADDR(base) ((base) + (0x3D4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA14_ADDR(base) ((base) + (0x3D8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA15_ADDR(base) ((base) + (0x3DCUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA16_ADDR(base) ((base) + (0x3E0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA17_ADDR(base) ((base) + (0x3E4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA18_ADDR(base) ((base) + (0x3E8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA19_ADDR(base) ((base) + (0x3ECUL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA20_ADDR(base) ((base) + (0x3F0UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA21_ADDR(base) ((base) + (0x3F4UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA22_ADDR(base) ((base) + (0x3F8UL))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA23_ADDR(base) ((base) + (0x3FCUL))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT1_ADDR(base) ((base) + (0x608UL))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT2_ADDR(base) ((base) + (0x60CUL))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT3_ADDR(base) ((base) + (0x610UL))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT4_ADDR(base) ((base) + (0x614UL))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT5_ADDR(base) ((base) + (0x618UL))
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG0_ADDR(base) ((base) + (0x658UL))
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG1_ADDR(base) ((base) + (0x65CUL))
#define SOC_XPU_LP_CTRL_CFG_H2P_BRG_CTRL_ADDR(base) ((base) + (0x660UL))
#define SOC_XPU_LP_CTRL_CFG_HUSER_MST_ADDR(base) ((base) + (0x664UL))
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_DBG_INFO_ADDR(base) ((base) + (0x670UL))
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_CTRL_ADDR(base) ((base) + (0x674UL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ADDR(base) ((base) + (0x678UL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL1_ADDR(base) ((base) + (0x67CUL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO1_ADDR(base) ((base) + (0x680UL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO2_ADDR(base) ((base) + (0x68CUL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ADDR(base) ((base) + (0x690UL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL3_ADDR(base) ((base) + (0x694UL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO3_ADDR(base) ((base) + (0x698UL))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO4_ADDR(base) ((base) + (0x69CUL))
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_ADDR(base) ((base) + (0x700UL))
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_ADDR(base) ((base) + (0x704UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_ADDR(base) ((base) + (0x708UL))
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_CTRL_DDRXPU_TO_UCE_ADDR(base) ((base) + (0x714UL))
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_ADDR(base) ((base) + (0x718UL))
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_ADDR(base) ((base) + (0x71CUL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_ADDR(base) ((base) + (0x728UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ADDR(base) ((base) + (0x7F8UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_0_ADDR(base) ((base) + (0x72CUL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_1_ADDR(base) ((base) + (0x738UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_2_ADDR(base) ((base) + (0x7FCUL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_ADDR(base) ((base) + (0x7A0UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_ADDR(base) ((base) + (0x7A4UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_2_ADDR(base) ((base) + (0x7A8UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_3_ADDR(base) ((base) + (0x7ACUL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_4_ADDR(base) ((base) + (0x7B0UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_ADDR(base) ((base) + (0x7B4UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_ADDR(base) ((base) + (0x7B8UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_7_ADDR(base) ((base) + (0x7D0UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_8_ADDR(base) ((base) + (0x7D4UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_9_ADDR(base) ((base) + (0x7D8UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_ADDR(base) ((base) + (0x7DCUL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_ADDR(base) ((base) + (0x7ECUL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_12_ADDR(base) ((base) + (0x7F0UL))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_13_ADDR(base) ((base) + (0x7F4UL))
#else
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_ADDR(base) ((base) + (0x000))
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_ADDR(base) ((base) + (0x004))
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_ADDR(base) ((base) + (0x00C))
#define SOC_XPU_LP_CTRL_CFG_PEREN0_ADDR(base) ((base) + (0x010))
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_ADDR(base) ((base) + (0x014))
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_ADDR(base) ((base) + (0x018))
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_ADDR(base) ((base) + (0x01C))
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_ADDR(base) ((base) + (0x020))
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ADDR(base) ((base) + (0x050))
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ADDR(base) ((base) + (0x054))
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ADDR(base) ((base) + (0x058))
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_ADDR(base) ((base) + (0x024))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_ADDR(base) ((base) + (0x030))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_ADDR(base) ((base) + (0x038))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT1_ADDR(base) ((base) + (0x03C))
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_ADDR(base) ((base) + (0x0A0))
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_1_ADDR(base) ((base) + (0x0A4))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_NMI_SOFT_ADDR(base) ((base) + (0x0A8))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_ADDR(base) ((base) + (0x0AC))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_ADDR(base) ((base) + (0x0B0))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_START_ADDR_ADDR(base) ((base) + (0x0C0))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_END_ADDR_ADDR(base) ((base) + (0x0C4))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_START_ADDR_ADDR(base) ((base) + (0x0C8))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_END_ADDR_ADDR(base) ((base) + (0x0CC))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_START_ADDR_ADDR(base) ((base) + (0x0D0))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_END_ADDR_ADDR(base) ((base) + (0x0D4))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_START_ADDR_ADDR(base) ((base) + (0x0D8))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_END_ADDR_ADDR(base) ((base) + (0x0DC))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_RST_PC_ADDR(base) ((base) + (0x0E0))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X1_ADDR(base) ((base) + (0x118))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X2_ADDR(base) ((base) + (0x11C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X3_ADDR(base) ((base) + (0x120))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X4_ADDR(base) ((base) + (0x124))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X5_ADDR(base) ((base) + (0x128))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X6_ADDR(base) ((base) + (0x12C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X7_ADDR(base) ((base) + (0x130))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X8_ADDR(base) ((base) + (0x134))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X9_ADDR(base) ((base) + (0x138))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X10_ADDR(base) ((base) + (0x13C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X11_ADDR(base) ((base) + (0x140))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X12_ADDR(base) ((base) + (0x144))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X13_ADDR(base) ((base) + (0x148))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X14_ADDR(base) ((base) + (0x14C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X15_ADDR(base) ((base) + (0x150))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X16_ADDR(base) ((base) + (0x154))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X17_ADDR(base) ((base) + (0x158))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X18_ADDR(base) ((base) + (0x15C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X19_ADDR(base) ((base) + (0x160))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X20_ADDR(base) ((base) + (0x164))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X21_ADDR(base) ((base) + (0x168))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X22_ADDR(base) ((base) + (0x16C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X23_ADDR(base) ((base) + (0x170))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X24_ADDR(base) ((base) + (0x174))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X25_ADDR(base) ((base) + (0x178))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X26_ADDR(base) ((base) + (0x17C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X27_ADDR(base) ((base) + (0x180))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X28_ADDR(base) ((base) + (0x184))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X29_ADDR(base) ((base) + (0x188))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X30_ADDR(base) ((base) + (0x18C))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X31_ADDR(base) ((base) + (0x190))
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MEM_CTRL1_ADDR(base) ((base) + (0x194))
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_ADDR(base) ((base) + (0x300))
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_ADDR(base) ((base) + (0x304))
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_ADDR(base) ((base) + (0x308))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_MASK_ADDR(base) ((base) + (0x30C))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_MASK_ADDR(base) ((base) + (0x310))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_MASK_ADDR(base) ((base) + (0x314))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_RAW_ADDR(base) ((base) + (0x318))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_RAW_ADDR(base) ((base) + (0x31C))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_RAW_ADDR(base) ((base) + (0x320))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_ADDR(base) ((base) + (0x324))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_ADDR(base) ((base) + (0x328))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_ADDR(base) ((base) + (0x32C))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_ADDR(base) ((base) + (0x330))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_ADDR(base) ((base) + (0x340))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_ADDR(base) ((base) + (0x334))
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_ADDR(base) ((base) + (0x338))
#define SOC_XPU_LP_CTRL_CFG_INT_SYNC_CTRL_ADDR(base) ((base) + (0x33C))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_ADDR(base) ((base) + (0x380))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_ADDR(base) ((base) + (0x384))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_ADDR(base) ((base) + (0x388))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_ADDR(base) ((base) + (0x38C))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_ADDR(base) ((base) + (0x390))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_ADDR(base) ((base) + (0x394))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_ADDR(base) ((base) + (0x398))
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_ADDR(base) ((base) + (0x39C))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA0_ADDR(base) ((base) + (0x3A0))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA1_ADDR(base) ((base) + (0x3A4))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA2_ADDR(base) ((base) + (0x3A8))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA3_ADDR(base) ((base) + (0x3AC))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA4_ADDR(base) ((base) + (0x3B0))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA5_ADDR(base) ((base) + (0x3B4))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA6_ADDR(base) ((base) + (0x3B8))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA7_ADDR(base) ((base) + (0x3BC))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA8_ADDR(base) ((base) + (0x3C0))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA9_ADDR(base) ((base) + (0x3C4))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA10_ADDR(base) ((base) + (0x3C8))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA11_ADDR(base) ((base) + (0x3CC))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA12_ADDR(base) ((base) + (0x3D0))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA13_ADDR(base) ((base) + (0x3D4))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA14_ADDR(base) ((base) + (0x3D8))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA15_ADDR(base) ((base) + (0x3DC))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA16_ADDR(base) ((base) + (0x3E0))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA17_ADDR(base) ((base) + (0x3E4))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA18_ADDR(base) ((base) + (0x3E8))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA19_ADDR(base) ((base) + (0x3EC))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA20_ADDR(base) ((base) + (0x3F0))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA21_ADDR(base) ((base) + (0x3F4))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA22_ADDR(base) ((base) + (0x3F8))
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA23_ADDR(base) ((base) + (0x3FC))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT1_ADDR(base) ((base) + (0x608))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT2_ADDR(base) ((base) + (0x60C))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT3_ADDR(base) ((base) + (0x610))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT4_ADDR(base) ((base) + (0x614))
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT5_ADDR(base) ((base) + (0x618))
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG0_ADDR(base) ((base) + (0x658))
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG1_ADDR(base) ((base) + (0x65C))
#define SOC_XPU_LP_CTRL_CFG_H2P_BRG_CTRL_ADDR(base) ((base) + (0x660))
#define SOC_XPU_LP_CTRL_CFG_HUSER_MST_ADDR(base) ((base) + (0x664))
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_DBG_INFO_ADDR(base) ((base) + (0x670))
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_CTRL_ADDR(base) ((base) + (0x674))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ADDR(base) ((base) + (0x678))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL1_ADDR(base) ((base) + (0x67C))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO1_ADDR(base) ((base) + (0x680))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO2_ADDR(base) ((base) + (0x68C))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ADDR(base) ((base) + (0x690))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL3_ADDR(base) ((base) + (0x694))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO3_ADDR(base) ((base) + (0x698))
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO4_ADDR(base) ((base) + (0x69C))
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_ADDR(base) ((base) + (0x700))
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_ADDR(base) ((base) + (0x704))
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_ADDR(base) ((base) + (0x708))
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_CTRL_DDRXPU_TO_UCE_ADDR(base) ((base) + (0x714))
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_ADDR(base) ((base) + (0x718))
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_ADDR(base) ((base) + (0x71C))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_ADDR(base) ((base) + (0x728))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ADDR(base) ((base) + (0x7F8))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_0_ADDR(base) ((base) + (0x72C))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_1_ADDR(base) ((base) + (0x738))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_2_ADDR(base) ((base) + (0x7FC))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_ADDR(base) ((base) + (0x7A0))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_ADDR(base) ((base) + (0x7A4))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_2_ADDR(base) ((base) + (0x7A8))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_3_ADDR(base) ((base) + (0x7AC))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_4_ADDR(base) ((base) + (0x7B0))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_ADDR(base) ((base) + (0x7B4))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_ADDR(base) ((base) + (0x7B8))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_7_ADDR(base) ((base) + (0x7D0))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_8_ADDR(base) ((base) + (0x7D4))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_9_ADDR(base) ((base) + (0x7D8))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_ADDR(base) ((base) + (0x7DC))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_ADDR(base) ((base) + (0x7EC))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_12_ADDR(base) ((base) + (0x7F0))
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_13_ADDR(base) ((base) + (0x7F4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_xpu_tcp : 1;
        unsigned int sc_gt_clk_lp_sensor : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
        unsigned int lpctrl_clk_div0_msk : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_sc_gt_clk_xpu_tcp_START (0)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_sc_gt_clk_xpu_tcp_END (0)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_sc_gt_clk_lp_sensor_START (1)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_sc_gt_clk_lp_sensor_END (1)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_lpctrl_clk_div0_msk_START (16)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV0_lpctrl_clk_div0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_xpu_tcp : 6;
        unsigned int div_lp_sensor : 2;
        unsigned int reserved_0 : 2;
        unsigned int div_apb : 2;
        unsigned int reserved_1 : 4;
        unsigned int lpctrl_clk_div1_msk : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_div_xpu_tcp_START (0)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_div_xpu_tcp_END (5)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_div_lp_sensor_START (6)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_div_lp_sensor_END (7)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_div_apb_START (10)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_div_apb_END (11)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_lpctrl_clk_div1_msk_START (16)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLK_DIV1_lpctrl_clk_div1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uart_clkrst_bypass : 1;
        unsigned int wdg_clkrst_bypass : 1;
        unsigned int timer_clkrst_bypass : 1;
        unsigned int lp_sensor_0_clkrst_bypass : 1;
        unsigned int xpu_ahb_clkrst_bypass : 1;
        unsigned int lpcs_clkrst_bypass : 1;
        unsigned int lp_sensor_1_clkrst_bypass : 1;
        unsigned int dig_tsensor_clkrst_bypass : 1;
        unsigned int tsensor_clkrst_bypass : 1;
        unsigned int tempc_clkrst_bypass : 1;
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
        unsigned int reserved_13 : 9;
    } reg;
} SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_uart_clkrst_bypass_START (0)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_uart_clkrst_bypass_END (0)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_wdg_clkrst_bypass_START (1)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_wdg_clkrst_bypass_END (1)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_timer_clkrst_bypass_START (2)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_timer_clkrst_bypass_END (2)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_lp_sensor_0_clkrst_bypass_START (3)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_lp_sensor_0_clkrst_bypass_END (3)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_xpu_ahb_clkrst_bypass_START (4)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_xpu_ahb_clkrst_bypass_END (4)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_lpcs_clkrst_bypass_START (5)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_lpcs_clkrst_bypass_END (5)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_lp_sensor_1_clkrst_bypass_START (6)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_lp_sensor_1_clkrst_bypass_END (6)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_dig_tsensor_clkrst_bypass_START (7)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_dig_tsensor_clkrst_bypass_END (7)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_tsensor_clkrst_bypass_START (8)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_tsensor_clkrst_bypass_END (8)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_tempc_clkrst_bypass_START (9)
#define SOC_XPU_LP_CTRL_CFG_LPCTRL_CLKRST_BYPASS0_tempc_clkrst_bypass_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_uart : 1;
        unsigned int gt_pclk_timer : 1;
        unsigned int gt_pclk_wdg : 1;
        unsigned int gt_pclk_lp_sensor_0_brg : 1;
        unsigned int gt_clk_lpcs : 1;
        unsigned int gt_pclk_lp_sensor_0 : 1;
        unsigned int gt_clk_lp_sensor_0 : 1;
        unsigned int gt_clk_xpu_tcp : 1;
        unsigned int gt_pclk_lp_sensor_1 : 1;
        unsigned int gt_clk_lp_sensor_1 : 1;
        unsigned int gt_pclk_lp_sensor_1_brg : 1;
        unsigned int gt_pclk_dig_tsensor : 1;
        unsigned int gt_pclk_tsensor : 1;
        unsigned int gt_pclk_tempc : 1;
        unsigned int gt_clksys_tempc : 1;
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
    } reg;
} SOC_XPU_LP_CTRL_CFG_PEREN0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_wdg_START (2)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_wdg_END (2)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_brg_START (3)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_brg_END (3)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_lpcs_START (4)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_lpcs_END (4)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_lp_sensor_0_START (6)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_lp_sensor_0_END (6)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_xpu_tcp_START (7)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_xpu_tcp_END (7)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_1_START (8)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_1_END (8)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_lp_sensor_1_START (9)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clk_lp_sensor_1_END (9)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_1_brg_START (10)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_lp_sensor_1_brg_END (10)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_dig_tsensor_START (11)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_dig_tsensor_END (11)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_tsensor_START (12)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_tsensor_END (12)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_tempc_START (13)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_pclk_tempc_END (13)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clksys_tempc_START (14)
#define SOC_XPU_LP_CTRL_CFG_PEREN0_gt_clksys_tempc_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_uart : 1;
        unsigned int gt_pclk_timer : 1;
        unsigned int gt_pclk_wdg : 1;
        unsigned int gt_pclk_lp_sensor_0_brg : 1;
        unsigned int gt_clk_lpcs : 1;
        unsigned int gt_pclk_lp_sensor_0 : 1;
        unsigned int gt_clk_lp_sensor_0 : 1;
        unsigned int gt_clk_xpu_tcp : 1;
        unsigned int gt_pclk_lp_sensor_1 : 1;
        unsigned int gt_clk_lp_sensor_1 : 1;
        unsigned int gt_pclk_lp_sensor_1_brg : 1;
        unsigned int gt_pclk_dig_tsensor : 1;
        unsigned int gt_pclk_tsensor : 1;
        unsigned int gt_pclk_tempc : 1;
        unsigned int gt_clksys_tempc : 1;
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
    } reg;
} SOC_XPU_LP_CTRL_CFG_PERDIS0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_wdg_START (2)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_wdg_END (2)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_0_brg_START (3)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_0_brg_END (3)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_lpcs_START (4)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_lpcs_END (4)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_lp_sensor_0_START (6)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_lp_sensor_0_END (6)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_xpu_tcp_START (7)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_xpu_tcp_END (7)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_1_START (8)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_1_END (8)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_lp_sensor_1_START (9)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clk_lp_sensor_1_END (9)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_1_brg_START (10)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_lp_sensor_1_brg_END (10)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_dig_tsensor_START (11)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_dig_tsensor_END (11)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_tsensor_START (12)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_tsensor_END (12)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_tempc_START (13)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_pclk_tempc_END (13)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clksys_tempc_START (14)
#define SOC_XPU_LP_CTRL_CFG_PERDIS0_gt_clksys_tempc_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_uart : 1;
        unsigned int gt_pclk_timer : 1;
        unsigned int gt_pclk_wdg : 1;
        unsigned int gt_pclk_lp_sensor_0_brg : 1;
        unsigned int gt_clk_lpcs : 1;
        unsigned int gt_pclk_lp_sensor_0 : 1;
        unsigned int gt_clk_lp_sensor_0 : 1;
        unsigned int gt_clk_xpu_tcp : 1;
        unsigned int gt_pclk_lp_sensor_1 : 1;
        unsigned int gt_clk_lp_sensor_1 : 1;
        unsigned int gt_pclk_lp_sensor_1_brg : 1;
        unsigned int gt_pclk_dig_tsensor : 1;
        unsigned int gt_pclk_tsensor : 1;
        unsigned int gt_pclk_tempc : 1;
        unsigned int gt_clksys_tempc : 1;
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
    } reg;
} SOC_XPU_LP_CTRL_CFG_PERCLKEN0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_wdg_START (2)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_wdg_END (2)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_0_brg_START (3)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_0_brg_END (3)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_lpcs_START (4)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_lpcs_END (4)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_lp_sensor_0_START (6)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_lp_sensor_0_END (6)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_xpu_tcp_START (7)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_xpu_tcp_END (7)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_1_START (8)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_1_END (8)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_lp_sensor_1_START (9)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clk_lp_sensor_1_END (9)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_1_brg_START (10)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_lp_sensor_1_brg_END (10)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_dig_tsensor_START (11)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_dig_tsensor_END (11)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_tsensor_START (12)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_tsensor_END (12)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_tempc_START (13)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_pclk_tempc_END (13)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clksys_tempc_START (14)
#define SOC_XPU_LP_CTRL_CFG_PERCLKEN0_gt_clksys_tempc_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_pclk_uart : 1;
        unsigned int st_pclk_timer : 1;
        unsigned int st_pclk_wdg : 1;
        unsigned int st_pclk_lp_sensor_0_brg_tmp : 1;
        unsigned int st_clk_lpcs : 1;
        unsigned int st_pclk_lp_sensor_0 : 1;
        unsigned int st_clk_lp_sensor_0 : 1;
        unsigned int st_clk_xpu_tcp : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_pclk_lp_sensor_1 : 1;
        unsigned int st_clk_lp_sensor_1 : 1;
        unsigned int st_pclk_lp_sensor_1_brg_tmp : 1;
        unsigned int st_pclk_dig_tsensor : 1;
        unsigned int st_pclk_tsensor : 1;
        unsigned int st_pclk_tempc : 1;
        unsigned int st_clksys_tempc : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_wdg_START (2)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_wdg_END (2)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_0_brg_tmp_START (3)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_0_brg_tmp_END (3)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_lpcs_START (4)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_lpcs_END (4)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_lp_sensor_0_START (6)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_lp_sensor_0_END (6)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_xpu_tcp_START (7)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_xpu_tcp_END (7)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_1_START (9)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_1_END (9)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_lp_sensor_1_START (10)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clk_lp_sensor_1_END (10)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_1_brg_tmp_START (11)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_lp_sensor_1_brg_tmp_END (11)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_dig_tsensor_START (12)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_dig_tsensor_END (12)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_tsensor_START (13)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_tsensor_END (13)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_tempc_START (14)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_pclk_tempc_END (14)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clksys_tempc_START (15)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT0_st_clksys_tempc_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_pclk_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int swdone_clk_lp_sensor_div : 1;
        unsigned int swdone_clk_xpu_tcp_div : 1;
        unsigned int st_pclk_sys_brg : 1;
        unsigned int autodiv_xpu_stat : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_swdone_pclk_div_START (0)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_swdone_pclk_div_END (0)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_swdone_clk_lp_sensor_div_START (2)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_swdone_clk_lp_sensor_div_END (2)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_swdone_clk_xpu_tcp_div_START (3)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_swdone_clk_xpu_tcp_div_END (3)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_st_pclk_sys_brg_START (4)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_st_pclk_sys_brg_END (4)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_autodiv_xpu_stat_START (5)
#define SOC_XPU_LP_CTRL_CFG_PERCLKSTAT1_autodiv_xpu_stat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_uart : 1;
        unsigned int ip_prst_timer : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_lpcs : 1;
        unsigned int ip_rst_xpu_tcp : 1;
        unsigned int ip_rst_lp_sensor_0 : 1;
        unsigned int ip_rst_lp_sensor_1 : 1;
        unsigned int ip_rst_dig_tsensor : 1;
        unsigned int ip_rst_tsensor : 1;
        unsigned int ip_rst_tempc : 1;
        unsigned int ip_rst_tempc_sys : 1;
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
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_RSTEN0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_prst_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_prst_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_prst_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_prst_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_lpcs_START (3)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_lpcs_END (3)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_xpu_tcp_START (4)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_xpu_tcp_END (4)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_lp_sensor_1_START (6)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_lp_sensor_1_END (6)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_dig_tsensor_START (7)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_dig_tsensor_END (7)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_tsensor_START (8)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_tsensor_END (8)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_tempc_START (9)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_tempc_END (9)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_tempc_sys_START (10)
#define SOC_XPU_LP_CTRL_CFG_RSTEN0_ip_rst_tempc_sys_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_uart : 1;
        unsigned int ip_prst_timer : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_lpcs : 1;
        unsigned int ip_rst_xpu_tcp : 1;
        unsigned int ip_rst_lp_sensor_0 : 1;
        unsigned int ip_rst_lp_sensor_1 : 1;
        unsigned int ip_rst_dig_tsensor : 1;
        unsigned int ip_rst_tsensor : 1;
        unsigned int ip_rst_tempc : 1;
        unsigned int ip_rst_tempc_sys : 1;
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
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_RSTDIS0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_prst_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_prst_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_prst_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_prst_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lpcs_START (3)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lpcs_END (3)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_xpu_tcp_START (4)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_xpu_tcp_END (4)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_1_START (6)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_lp_sensor_1_END (6)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_dig_tsensor_START (7)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_dig_tsensor_END (7)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_tsensor_START (8)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_tsensor_END (8)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_tempc_START (9)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_tempc_END (9)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_tempc_sys_START (10)
#define SOC_XPU_LP_CTRL_CFG_RSTDIS0_ip_rst_tempc_sys_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_uart : 1;
        unsigned int ip_prst_timer : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_lpcs : 1;
        unsigned int ip_rst_xpu_tcp : 1;
        unsigned int ip_rst_lp_sensor_0 : 1;
        unsigned int ip_rst_lp_sensor_1 : 1;
        unsigned int ip_rst_dig_tsensor : 1;
        unsigned int ip_rst_tsensor : 1;
        unsigned int ip_rst_tempc : 1;
        unsigned int ip_rst_tempc_sys : 1;
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
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_RSTSTAT0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_prst_uart_START (0)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_prst_uart_END (0)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_prst_timer_START (1)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_prst_timer_END (1)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_lpcs_START (3)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_lpcs_END (3)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_xpu_tcp_START (4)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_xpu_tcp_END (4)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_lp_sensor_0_START (5)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_lp_sensor_0_END (5)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_lp_sensor_1_START (6)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_lp_sensor_1_END (6)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_dig_tsensor_START (7)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_dig_tsensor_END (7)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_tsensor_START (8)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_tsensor_END (8)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_tempc_START (9)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_tempc_END (9)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_tempc_sys_START (10)
#define SOC_XPU_LP_CTRL_CFG_RSTSTAT0_ip_rst_tempc_sys_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpu_div_auto_reduce_bypass : 1;
        unsigned int xpu_auto_waitcfg_in : 10;
        unsigned int xpu_auto_waitcfg_out : 10;
        unsigned int xpu_div_auto_cfg : 6;
        unsigned int xpu_idle_bypass : 1;
        unsigned int xpu_bus_slv_idle_bypass : 1;
        unsigned int xpu_irqs_gather_bypass : 1;
        unsigned int xpu_autogt_bypass : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_div_auto_reduce_bypass_START (0)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_div_auto_reduce_bypass_END (0)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_auto_waitcfg_in_START (1)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_auto_waitcfg_in_END (10)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_auto_waitcfg_out_START (11)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_auto_waitcfg_out_END (20)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_div_auto_cfg_START (21)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_div_auto_cfg_END (26)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_idle_bypass_START (27)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_idle_bypass_END (27)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_bus_slv_idle_bypass_START (28)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_bus_slv_idle_bypass_END (28)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_irqs_gather_bypass_START (29)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_irqs_gather_bypass_END (29)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_autogt_bypass_START (30)
#define SOC_XPU_LP_CTRL_CFG_SC_AUTODIV0_xpu_autogt_bypass_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_idle_vote_flag : 1;
        unsigned int xpu_to_qic_idle_type_sel : 1;
        unsigned int reserved_0 : 19;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_qic_idle_vote_flag_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_qic_idle_vote_flag_END (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_xpu_to_qic_idle_type_sel_START (1)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_REG_xpu_to_qic_idle_type_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrxpu_minibus_busy : 1;
        unsigned int core_irqs_gather : 1;
        unsigned int core_busy : 1;
        unsigned int xpu_to_qic_idle_flag : 1;
        unsigned int xpu_core_idle_flag : 1;
        unsigned int qic_busy : 1;
        unsigned int xpu_tcp_bus_slv_idle_flag : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_ddrxpu_minibus_busy_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_ddrxpu_minibus_busy_END (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_core_irqs_gather_START (1)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_core_irqs_gather_END (1)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_core_busy_START (2)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_core_busy_END (2)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_xpu_to_qic_idle_flag_START (3)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_xpu_to_qic_idle_flag_END (3)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_xpu_core_idle_flag_START (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_xpu_core_idle_flag_END (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_qic_busy_START (5)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_qic_busy_END (5)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_xpu_tcp_bus_slv_idle_flag_START (6)
#define SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT0_xpu_tcp_bus_slv_idle_flag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 19;
        unsigned int reserved_3: 6;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_STAT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_stop_tmr : 1;
        unsigned int core_ra_wr_en : 1;
        unsigned int core_pc_valid : 1;
        unsigned int core_in_nmi_hdlr : 1;
        unsigned int core_hard_fault_mode : 1;
        unsigned int core_debug_mode : 1;
        unsigned int core_sleep_mode : 1;
        unsigned int core_lockup_mode : 1;
        unsigned int core_async_excption : 1;
        unsigned int core_async_excption_axim : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_stop_tmr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_stop_tmr_END (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_ra_wr_en_START (1)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_ra_wr_en_END (1)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_pc_valid_START (2)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_pc_valid_END (2)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_in_nmi_hdlr_START (3)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_in_nmi_hdlr_END (3)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_hard_fault_mode_START (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_hard_fault_mode_END (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_debug_mode_START (5)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_debug_mode_END (5)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_sleep_mode_START (6)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_sleep_mode_END (6)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_lockup_mode_START (7)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_lockup_mode_END (7)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_async_excption_START (8)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_async_excption_END (8)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_async_excption_axim_START (9)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_0_core_async_excption_axim_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pc : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_1_core_pc_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_CORE_STATUS_1_core_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nmi_soft : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_NMI_SOFT_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_NMI_SOFT_nmi_soft_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_NMI_SOFT_nmi_soft_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_async_excption_taken : 1;
        unsigned int reserved_0 : 3;
        unsigned int core_async_excp_handled_as_nmi_bypass : 1;
        unsigned int reserved_1 : 3;
        unsigned int core_nmi_not_to_lockup_bypass : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_async_excption_mask : 1;
        unsigned int reserved_3 : 3;
        unsigned int nmi_soft_mask : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_async_excption_taken_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_async_excption_taken_END (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_async_excp_handled_as_nmi_bypass_START (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_async_excp_handled_as_nmi_bypass_END (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_nmi_not_to_lockup_bypass_START (8)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_nmi_not_to_lockup_bypass_END (8)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_async_excption_mask_START (12)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_core_async_excption_mask_END (12)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_nmi_soft_mask_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL1_nmi_soft_mask_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_wait : 1;
        unsigned int reserved_0 : 3;
        unsigned int timer_int_req : 1;
        unsigned int reserved_1 : 3;
        unsigned int ext_int_vld : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_core_wait_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_core_wait_END (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_timer_int_req_START (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_timer_int_req_END (4)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_ext_int_vld_START (8)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_CTRL2_ext_int_vld_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_START_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_START_ADDR_itcm_rgn_start_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_START_ADDR_itcm_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int itcm_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_END_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_END_ADDR_itcm_rgn_end_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_ITCM_END_ADDR_itcm_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_START_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_START_ADDR_pmem_rgn_start_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_START_ADDR_pmem_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmem_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_END_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_END_ADDR_pmem_rgn_end_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_PMEM_END_ADDR_pmem_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmem_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_START_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_START_ADDR_mmem_rgn_start_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_START_ADDR_mmem_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmem_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_END_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_END_ADDR_mmem_rgn_end_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MMEM_END_ADDR_mmem_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_rgn_start_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_START_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_START_ADDR_sys_rgn_start_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_START_ADDR_sys_rgn_start_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_rgn_end_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_END_ADDR_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_END_ADDR_sys_rgn_end_addr_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_SYS_END_ADDR_sys_rgn_end_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int por_rst_pc : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_RST_PC_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_RST_PC_por_rst_pc_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_RST_PC_por_rst_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x1 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X1_core_irf_x1_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X1_core_irf_x1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x2 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X2_core_irf_x2_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X2_core_irf_x2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x3 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X3_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X3_core_irf_x3_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X3_core_irf_x3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x4 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X4_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X4_core_irf_x4_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X4_core_irf_x4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x5 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X5_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X5_core_irf_x5_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X5_core_irf_x5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x6 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X6_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X6_core_irf_x6_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X6_core_irf_x6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x7 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X7_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X7_core_irf_x7_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X7_core_irf_x7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x8 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X8_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X8_core_irf_x8_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X8_core_irf_x8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x9 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X9_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X9_core_irf_x9_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X9_core_irf_x9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x10 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X10_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X10_core_irf_x10_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X10_core_irf_x10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x11 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X11_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X11_core_irf_x11_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X11_core_irf_x11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x12 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X12_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X12_core_irf_x12_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X12_core_irf_x12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x13 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X13_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X13_core_irf_x13_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X13_core_irf_x13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x14 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X14_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X14_core_irf_x14_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X14_core_irf_x14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x15 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X15_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X15_core_irf_x15_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X15_core_irf_x15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x16 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X16_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X16_core_irf_x16_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X16_core_irf_x16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x17 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X17_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X17_core_irf_x17_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X17_core_irf_x17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x18 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X18_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X18_core_irf_x18_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X18_core_irf_x18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x19 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X19_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X19_core_irf_x19_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X19_core_irf_x19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x20 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X20_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X20_core_irf_x20_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X20_core_irf_x20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x21 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X21_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X21_core_irf_x21_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X21_core_irf_x21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x22 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X22_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X22_core_irf_x22_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X22_core_irf_x22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x23 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X23_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X23_core_irf_x23_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X23_core_irf_x23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x24 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X24_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X24_core_irf_x24_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X24_core_irf_x24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x25 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X25_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X25_core_irf_x25_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X25_core_irf_x25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x26 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X26_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X26_core_irf_x26_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X26_core_irf_x26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x27 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X27_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X27_core_irf_x27_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X27_core_irf_x27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x28 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X28_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X28_core_irf_x28_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X28_core_irf_x28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x29 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X29_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X29_core_irf_x29_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X29_core_irf_x29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x30 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X30_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X30_core_irf_x30_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X30_core_irf_x30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_irf_x31 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X31_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X31_core_irf_x31_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_IRF_X31_core_irf_x31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpu_tcp_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_TCP_MEM_CTRL1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MEM_CTRL1_xpu_tcp_mem_ctrl_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPU_TCP_MEM_CTRL1_xpu_tcp_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_to_acpu : 3;
        unsigned int intr_to_lpmcu : 2;
        unsigned int intr_fast_cfg_to_cpu_xpu_lp_ctrl : 4;
        unsigned int intr_fast_cfg_to_gpu_xpu_lp_ctrl : 4;
        unsigned int intr_fast_cfg_to_ddr_xpu_lp_ctrl : 5;
        unsigned int intr_fast_cfg_to_media_xpu_lp_ctrl : 5;
        unsigned int reserved : 1;
        unsigned int intr_fast_cfg_risc : 8;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_EN_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_to_acpu_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_to_acpu_END (2)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_to_lpmcu_START (3)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_to_lpmcu_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_cpu_xpu_lp_ctrl_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_cpu_xpu_lp_ctrl_END (8)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_gpu_xpu_lp_ctrl_START (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_gpu_xpu_lp_ctrl_END (12)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_ddr_xpu_lp_ctrl_START (13)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_ddr_xpu_lp_ctrl_END (17)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_media_xpu_lp_ctrl_START (18)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_to_media_xpu_lp_ctrl_END (22)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_risc_START (24)
#define SOC_XPU_LP_CTRL_CFG_INTR_EN_intr_fast_cfg_risc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_to_acpu : 3;
        unsigned int intr_to_lpmcu : 2;
        unsigned int intr_fast_cfg_to_cpu_xpu_lp_ctrl : 4;
        unsigned int intr_fast_cfg_to_gpu_xpu_lp_ctrl : 4;
        unsigned int intr_fast_cfg_to_ddr_xpu_lp_ctrl : 5;
        unsigned int intr_fast_cfg_to_media_xpu_lp_ctrl : 5;
        unsigned int reserved : 1;
        unsigned int intr_fast_cfg_risc : 8;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_DIS_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_to_acpu_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_to_acpu_END (2)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_to_lpmcu_START (3)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_to_lpmcu_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_cpu_xpu_lp_ctrl_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_cpu_xpu_lp_ctrl_END (8)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_gpu_xpu_lp_ctrl_START (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_gpu_xpu_lp_ctrl_END (12)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_ddr_xpu_lp_ctrl_START (13)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_ddr_xpu_lp_ctrl_END (17)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_media_xpu_lp_ctrl_START (18)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_to_media_xpu_lp_ctrl_END (22)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_risc_START (24)
#define SOC_XPU_LP_CTRL_CFG_INTR_DIS_intr_fast_cfg_risc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_to_acpu : 3;
        unsigned int intr_to_lpmcu : 2;
        unsigned int intr_fast_cfg_to_cpu_xpu_lp_ctrl : 4;
        unsigned int intr_fast_cfg_to_gpu_xpu_lp_ctrl : 4;
        unsigned int intr_fast_cfg_to_ddr_xpu_lp_ctrl : 5;
        unsigned int intr_fast_cfg_to_media_xpu_lp_ctrl : 5;
        unsigned int reserved : 1;
        unsigned int intr_fast_cfg_risc : 8;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_STAT_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_to_acpu_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_to_acpu_END (2)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_to_lpmcu_START (3)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_to_lpmcu_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_cpu_xpu_lp_ctrl_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_cpu_xpu_lp_ctrl_END (8)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_gpu_xpu_lp_ctrl_START (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_gpu_xpu_lp_ctrl_END (12)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_ddr_xpu_lp_ctrl_START (13)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_ddr_xpu_lp_ctrl_END (17)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_media_xpu_lp_ctrl_START (18)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_to_media_xpu_lp_ctrl_END (22)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_risc_START (24)
#define SOC_XPU_LP_CTRL_CFG_INTR_STAT_intr_fast_cfg_risc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_0to31_mask : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_MASK_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_MASK_intr_xpu_rv_0to31_mask_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_MASK_intr_xpu_rv_0to31_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_32to63_mask : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_MASK_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_MASK_intr_xpu_rv_32to63_mask_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_MASK_intr_xpu_rv_32to63_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_64to95_mask : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_MASK_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_MASK_intr_xpu_rv_64to95_mask_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_MASK_intr_xpu_rv_64to95_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_0to31_raw : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_RAW_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_RAW_intr_xpu_rv_0to31_raw_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_RAW_intr_xpu_rv_0to31_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_32to63_raw : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_RAW_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_RAW_intr_xpu_rv_32to63_raw_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_RAW_intr_xpu_rv_32to63_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_64to95_raw : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_RAW_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_RAW_intr_xpu_rv_64to95_raw_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_RAW_intr_xpu_rv_64to95_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_0to31 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_intr_xpu_rv_0to31_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_0TO31_intr_xpu_rv_0to31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_32to63 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_intr_xpu_rv_32to63_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_32TO63_intr_xpu_rv_32to63_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_rv_64to95 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_intr_xpu_rv_64to95_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_RV_64TO95_intr_xpu_rv_64to95_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_lp_ctrl_to_acpu_mask : 5;
        unsigned int intr_xpu_lp_ctrl_to_lpmcu_mask : 5;
        unsigned int intr_xpu_lp_ctrl_to_cpu_xpu_mask : 5;
        unsigned int reserved : 1;
        unsigned int intr_mask0_msk : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_acpu_mask_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_acpu_mask_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_lpmcu_mask_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_lpmcu_mask_END (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_cpu_xpu_mask_START (10)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_xpu_lp_ctrl_to_cpu_xpu_mask_END (14)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_mask0_msk_START (16)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK_intr_mask0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_lp_ctrl_to_gpu_xpu_mask : 5;
        unsigned int intr_xpu_lp_ctrl_to_ddr_xpu_mask : 5;
        unsigned int intr_xpu_lp_ctrl_to_media_xpu_mask : 5;
        unsigned int reserved : 1;
        unsigned int intr_mask1_msk : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_xpu_lp_ctrl_to_gpu_xpu_mask_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_xpu_lp_ctrl_to_gpu_xpu_mask_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_xpu_lp_ctrl_to_ddr_xpu_mask_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_xpu_lp_ctrl_to_ddr_xpu_mask_END (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_xpu_lp_ctrl_to_media_xpu_mask_START (10)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_xpu_lp_ctrl_to_media_xpu_mask_END (14)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_mask1_msk_START (16)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_MASK1_intr_mask1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_lp_ctrl_to_acpu_raw : 5;
        unsigned int intr_xpu_lp_ctrl_to_lpmcu_raw : 5;
        unsigned int intr_xpu_lp_ctrl_to_cpu_xpu_raw : 5;
        unsigned int intr_xpu_lp_ctrl_to_gpu_xpu_raw : 5;
        unsigned int intr_xpu_lp_ctrl_to_ddr_xpu_raw : 5;
        unsigned int intr_xpu_lp_ctrl_to_media_xpu_raw : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_acpu_raw_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_acpu_raw_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_lpmcu_raw_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_lpmcu_raw_END (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_cpu_xpu_raw_START (10)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_cpu_xpu_raw_END (14)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_gpu_xpu_raw_START (15)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_gpu_xpu_raw_END (19)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_ddr_xpu_raw_START (20)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_ddr_xpu_raw_END (24)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_media_xpu_raw_START (25)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_RAW_STAT_intr_xpu_lp_ctrl_to_media_xpu_raw_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_xpu_lp_ctrl_to_acpu : 5;
        unsigned int intr_xpu_lp_ctrl_to_lpmcu : 5;
        unsigned int intr_xpu_lp_ctrl_to_cpu_xpu : 5;
        unsigned int intr_xpu_lp_ctrl_to_gpu_xpu : 5;
        unsigned int intr_xpu_lp_ctrl_to_ddr_xpu : 5;
        unsigned int intr_xpu_lp_ctrl_to_media_xpu : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_acpu_START (0)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_acpu_END (4)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_lpmcu_START (5)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_lpmcu_END (9)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_cpu_xpu_START (10)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_cpu_xpu_END (14)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_gpu_xpu_START (15)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_gpu_xpu_END (19)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_ddr_xpu_START (20)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_ddr_xpu_END (24)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_media_xpu_START (25)
#define SOC_XPU_LP_CTRL_CFG_INTR_XPU_LP_CTRL_STAT_intr_xpu_lp_ctrl_to_media_xpu_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpu_sync_cg_bypass : 1;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_XPU_LP_CTRL_CFG_INT_SYNC_CTRL_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_INT_SYNC_CTRL_xpu_sync_cg_bypass_START (0)
#define SOC_XPU_LP_CTRL_CFG_INT_SYNC_CTRL_xpu_sync_cg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata0 : 16;
        unsigned int xpulpctrl_datamask0 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_xpulpctrl_bakdata0_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_xpulpctrl_bakdata0_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_xpulpctrl_datamask0_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA0_xpulpctrl_datamask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata1 : 16;
        unsigned int xpulpctrl_datamask1 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_xpulpctrl_bakdata1_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_xpulpctrl_bakdata1_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_xpulpctrl_datamask1_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA1_xpulpctrl_datamask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata2 : 16;
        unsigned int xpulpctrl_datamask2 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_xpulpctrl_bakdata2_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_xpulpctrl_bakdata2_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_xpulpctrl_datamask2_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA2_xpulpctrl_datamask2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata3 : 16;
        unsigned int xpulpctrl_datamask3 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_xpulpctrl_bakdata3_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_xpulpctrl_bakdata3_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_xpulpctrl_datamask3_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA3_xpulpctrl_datamask3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata4 : 16;
        unsigned int xpulpctrl_datamask4 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_xpulpctrl_bakdata4_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_xpulpctrl_bakdata4_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_xpulpctrl_datamask4_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA4_xpulpctrl_datamask4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata5 : 16;
        unsigned int xpulpctrl_datamask5 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_xpulpctrl_bakdata5_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_xpulpctrl_bakdata5_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_xpulpctrl_datamask5_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA5_xpulpctrl_datamask5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata6 : 16;
        unsigned int xpulpctrl_datamask6 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_xpulpctrl_bakdata6_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_xpulpctrl_bakdata6_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_xpulpctrl_datamask6_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA6_xpulpctrl_datamask6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xpulpctrl_bakdata7 : 16;
        unsigned int xpulpctrl_datamask7 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_xpulpctrl_bakdata7_START (0)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_xpulpctrl_bakdata7_END (15)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_xpulpctrl_datamask7_START (16)
#define SOC_XPU_LP_CTRL_CFG_XPULPCTRL_BAKDATA7_xpulpctrl_datamask7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_XPU_LP_CTRL_DATA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_mux_err_intr_apb_arb : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT1_apb_mux_err_intr_apb_arb_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT1_apb_mux_err_intr_apb_arb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_apb_slv0_apb_arb : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT2_dbg_info_apb_slv0_apb_arb_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT2_dbg_info_apb_slv0_apb_arb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_apb_slv1_apb_arb : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT3_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT3_dbg_info_apb_slv1_apb_arb_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT3_dbg_info_apb_slv1_apb_arb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_apb_slv0_apb_arb : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT4_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT4_dbg_data_apb_slv0_apb_arb_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT4_dbg_data_apb_slv0_apb_arb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_apb_slv1_apb_arb : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT5_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT5_dbg_data_apb_slv1_apb_arb_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_2TO1_STAT5_dbg_data_apb_slv1_apb_arb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_top_dvfs_cfg : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DVFS_CFG0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG0_gpu_top_dvfs_cfg_START (0)
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG0_gpu_top_dvfs_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpu_core_dvfs_cfg : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DVFS_CFG1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG1_gpu_core_dvfs_cfg_START (0)
#define SOC_XPU_LP_CTRL_CFG_DVFS_CFG1_gpu_core_dvfs_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_h2p : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_XPU_LP_CTRL_CFG_H2P_BRG_CTRL_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_H2P_BRG_CTRL_idle_h2p_START (0)
#define SOC_XPU_LP_CTRL_CFG_H2P_BRG_CTRL_idle_h2p_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int huser_mst : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_HUSER_MST_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_HUSER_MST_huser_mst_START (0)
#define SOC_XPU_LP_CTRL_CFG_HUSER_MST_huser_mst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_timeout_dbg_info : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_DBG_INFO_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_DBG_INFO_apb_timeout_dbg_info_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_DBG_INFO_apb_timeout_dbg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apb_timeout_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_CTRL_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_CTRL_apb_timeout_bypass_START (0)
#define SOC_XPU_LP_CTRL_CFG_APB_TIMEOUT_CTRL_apb_timeout_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_a_timeout_bypass : 1;
        unsigned int ahb_a_timeout_rsperr_en : 1;
        unsigned int ahb_a_timeout_clr : 1;
        unsigned int ahb_a_timeout_status : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_bypass_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_bypass_END (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_rsperr_en_START (1)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_rsperr_en_END (1)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_clr_START (2)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_clr_END (2)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_status_START (3)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL0_ahb_a_timeout_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_a_timeout_cnt_value : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL1_ahb_a_timeout_cnt_value_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL1_ahb_a_timeout_cnt_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_a_debuginfo0 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO1_ahb_a_debuginfo0_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO1_ahb_a_debuginfo0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_a_debuginfo1 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO2_ahb_a_debuginfo1_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO2_ahb_a_debuginfo1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_b_timeout_bypass : 1;
        unsigned int ahb_b_timeout_rsperr_en : 1;
        unsigned int ahb_b_timeout_clr : 1;
        unsigned int ahb_b_timeout_status : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_bypass_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_bypass_END (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_rsperr_en_START (1)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_rsperr_en_END (1)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_clr_START (2)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_clr_END (2)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_status_START (3)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL2_ahb_b_timeout_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_b_timeout_cnt_value : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL3_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL3_ahb_b_timeout_cnt_value_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_CTRL3_ahb_b_timeout_cnt_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_b_debuginfo0 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO3_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO3_ahb_b_debuginfo0_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO3_ahb_b_debuginfo0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ahb_b_debuginfo1 : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO4_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO4_ahb_b_debuginfo1_START (0)
#define SOC_XPU_LP_CTRL_CFG_AHB_TIMEOUT_DEBUG_INFO4_ahb_b_debuginfo1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmc_vol_idx_sftreq2 : 8;
        unsigned int pmc_vol_chg_sftreq2 : 1;
        unsigned int spmi_vol_sft_send_done2 : 1;
        unsigned int reserved_0 : 2;
        unsigned int pmc_vol_idx_sftreq3 : 8;
        unsigned int pmc_vol_chg_sftreq3 : 1;
        unsigned int spmi_vol_sft_send_done3 : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_idx_sftreq2_START (0)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_idx_sftreq2_END (7)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_chg_sftreq2_START (8)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_chg_sftreq2_END (8)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_spmi_vol_sft_send_done2_START (9)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_spmi_vol_sft_send_done2_END (9)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_idx_sftreq3_START (12)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_idx_sftreq3_END (19)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_chg_sftreq3_START (20)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_pmc_vol_chg_sftreq3_END (20)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_spmi_vol_sft_send_done3_START (21)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOLCFG1_spmi_vol_sft_send_done3_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sftcfg2_vol_idx_spmi : 8;
        unsigned int sftcfg2_vol_chg_spmi : 1;
        unsigned int sftcfg2_vol_ack_spmi : 1;
        unsigned int reserved_0 : 2;
        unsigned int sftcfg3_vol_idx_spmi : 8;
        unsigned int sftcfg3_vol_chg_spmi : 1;
        unsigned int sftcfg3_vol_ack_spmi : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg2_vol_idx_spmi_START (0)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg2_vol_idx_spmi_END (7)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg2_vol_chg_spmi_START (8)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg2_vol_chg_spmi_END (8)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg2_vol_ack_spmi_START (9)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg2_vol_ack_spmi_END (9)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg3_vol_idx_spmi_START (12)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg3_vol_idx_spmi_END (19)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg3_vol_chg_spmi_START (20)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg3_vol_chg_spmi_END (20)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg3_vol_ack_spmi_START (21)
#define SOC_XPU_LP_CTRL_CFG_SPMIVOL_STAT1_sftcfg3_vol_ack_spmi_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fer_buck_pgvok_ack_vddq : 1;
        unsigned int fer_buck_pgvok_ack_vdd2h : 1;
        unsigned int fer_buck_pgvok_ack_dmc : 1;
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 8;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 10;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_fer_buck_pgvok_ack_vddq_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_fer_buck_pgvok_ack_vddq_END (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_fer_buck_pgvok_ack_vdd2h_START (1)
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_fer_buck_pgvok_ack_vdd2h_END (1)
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_fer_buck_pgvok_ack_dmc_START (2)
#define SOC_XPU_LP_CTRL_CFG_DDR_VOL_FER_ACK_fer_buck_pgvok_ack_dmc_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prg_ctrl_ddrxpu_to_uce : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_UCE_PRG_CTRL_DDRXPU_TO_UCE_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_CTRL_DDRXPU_TO_UCE_uce_prg_ctrl_ddrxpu_to_uce_START (0)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_CTRL_DDRXPU_TO_UCE_uce_prg_ctrl_ddrxpu_to_uce_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prg_stat_uce_to_ddrxpu_a : 8;
        unsigned int uce_prg_stat_uce_to_ddrxpu_b : 8;
        unsigned int uce_prg_stat_uce_to_ddrxpu_c : 8;
        unsigned int uce_prg_stat_uce_to_ddrxpu_d : 8;
    } reg;
} SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_a_START (0)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_a_END (7)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_b_START (8)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_b_END (15)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_c_START (16)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_c_END (23)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_d_START (24)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_0_uce_prg_stat_uce_to_ddrxpu_d_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int uce_prg_stat_uce_to_ddrxpu_e : 8;
        unsigned int uce_prg_stat_uce_to_ddrxpu_f : 8;
        unsigned int uce_prg_stat_uce_to_ddrxpu_g : 8;
        unsigned int uce_prg_stat_uce_to_ddrxpu_h : 8;
    } reg;
} SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_e_START (0)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_e_END (7)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_f_START (8)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_f_END (15)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_g_START (16)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_g_END (23)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_h_START (24)
#define SOC_XPU_LP_CTRL_CFG_UCE_PRG_STAT_UCE_TO_DDRXPU_1_uce_prg_stat_uce_to_ddrxpu_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_mst_pri : 8;
        unsigned int hbus_slv_nonsec : 4;
        unsigned int hbus_slv_disable : 4;
        unsigned int hbus_ctrl_ddr_xctrl_mask : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_mst_pri_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_mst_pri_END (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_slv_nonsec_START (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_slv_nonsec_END (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_slv_disable_START (12)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_slv_disable_END (15)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_ctrl_ddr_xctrl_mask_START (16)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_hbus_ctrl_ddr_xctrl_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus2to1_mst_pri : 2;
        unsigned int hbus2to1_slv_disable : 1;
        unsigned int hbus2to1_ckg_en : 1;
        unsigned int hbus2to1_dlock_and_dbg_clr : 1;
        unsigned int unlock_port0_en : 1;
        unsigned int unlock_port1_en : 1;
        unsigned int unlock_port2_en : 1;
        unsigned int unlock_port4_en : 1;
        unsigned int unlock_port5_en : 1;
        unsigned int unlock_port6_en : 1;
        unsigned int unlock_hresp : 1;
        unsigned int ahbbus_dlock_and_dbg_clr : 1;
        unsigned int ddrxctrl_radio_mode : 1;
        unsigned int sync_with_cg_off : 1;
        unsigned int byp_mode : 1;
        unsigned int ddr_xctrl_mask1 : 16;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_mst_pri_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_mst_pri_END (1)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_slv_disable_START (2)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_slv_disable_END (2)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_ckg_en_START (3)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_ckg_en_END (3)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_dlock_and_dbg_clr_START (4)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_hbus2to1_dlock_and_dbg_clr_END (4)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port0_en_START (5)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port0_en_END (5)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port1_en_START (6)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port1_en_END (6)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port2_en_START (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port2_en_END (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port4_en_START (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port4_en_END (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port5_en_START (9)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port5_en_END (9)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port6_en_START (10)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_port6_en_END (10)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_hresp_START (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_unlock_hresp_END (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ahbbus_dlock_and_dbg_clr_START (12)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ahbbus_dlock_and_dbg_clr_END (12)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ddrxctrl_radio_mode_START (13)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ddrxctrl_radio_mode_END (13)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_sync_with_cg_off_START (14)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_sync_with_cg_off_END (14)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_byp_mode_START (15)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_byp_mode_END (15)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ddr_xctrl_mask1_START (16)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_MSK_CTRL_1_ddr_xctrl_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_CTRL_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_dlock_ahb : 6;
        unsigned int hbus_dlock_mstbusy : 2;
        unsigned int hbus_dcdrerr_secerr_slverr_viserr : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_hbus_dlock_ahb_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_hbus_dlock_ahb_END (5)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_hbus_dlock_mstbusy_START (6)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_hbus_dlock_mstbusy_END (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_hbus_dcdrerr_secerr_slverr_viserr_START (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_0_hbus_dcdrerr_secerr_slverr_viserr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_dbg_hnonsec : 1;
        unsigned int hbus_dbg_hexcl : 1;
        unsigned int hbus_dbg_hext_sel : 5;
        unsigned int hbus_dbg_exokay : 1;
        unsigned int hbus_dbg_hburst : 3;
        unsigned int hbus_dbg_hmastlock : 1;
        unsigned int hbus_dbg_hprot : 4;
        unsigned int hbus_dbg_hsize : 3;
        unsigned int hbus_dbg_hmaster : 4;
        unsigned int hbus_dbg_htrans : 2;
        unsigned int hbus_dbg_hwrite : 1;
        unsigned int hbus_dbg_hresp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hnonsec_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hnonsec_END (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hexcl_START (1)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hexcl_END (1)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hext_sel_START (2)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hext_sel_END (6)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_exokay_START (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_exokay_END (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hburst_START (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hburst_END (10)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hmastlock_START (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hmastlock_END (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hprot_START (12)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hprot_END (15)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hsize_START (16)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hsize_END (18)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hmaster_START (19)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hmaster_END (22)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_htrans_START (23)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_htrans_END (24)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hwrite_START (25)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hwrite_END (25)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hresp_START (26)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_1_hbus_dbg_hresp_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_dbg_haddr : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_2_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_2_hbus_dbg_haddr_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_2_hbus_dbg_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_dbg_hwdata : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_3_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_3_hbus_dbg_hwdata_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_3_hbus_dbg_hwdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_dbg_hrdata : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_4_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_4_hbus_dbg_hrdata_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_4_hbus_dbg_hrdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus_dbg_haddr_user : 16;
        unsigned int hbus_dbg_hwdata_user : 1;
        unsigned int hbus_dbg_hrdata_user : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_hbus_dbg_haddr_user_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_hbus_dbg_haddr_user_END (15)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_hbus_dbg_hwdata_user_START (16)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_hbus_dbg_hwdata_user_END (16)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_hbus_dbg_hrdata_user_START (17)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_5_hbus_dbg_hrdata_user_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idle_h2p : 1;
        unsigned int idle_minibus : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_idle_h2p_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_idle_h2p_END (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_idle_minibus_START (1)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_6_idle_minibus_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus2to1_dbg_haddr : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_7_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_7_hbus2to1_dbg_haddr_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_7_hbus2to1_dbg_haddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus2to1_dbg_hwdata : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_8_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_8_hbus2to1_dbg_hwdata_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_8_hbus2to1_dbg_hwdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus2to1_dbg_hrdata : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_9_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_9_hbus2to1_dbg_hrdata_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_9_hbus2to1_dbg_hrdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus2to1_dlock_ahb : 3;
        unsigned int hbus2to1_dlock_mstbusy : 2;
        unsigned int hbus2to1_dcdrerr_secerr_slverr_viserr : 4;
        unsigned int hbus2to1_dbg_hburst : 3;
        unsigned int hbus2to1_dbg_hmastlock : 1;
        unsigned int hbus2to1_dbg_hprot : 4;
        unsigned int hbus2to1_dbg_hsize : 3;
        unsigned int hbus2to1_dbg_hnonsec : 1;
        unsigned int hbus2to1_dbg_hexcl : 1;
        unsigned int hbus2to1_dbg_hmaster : 4;
        unsigned int hbus2to1_dbg_htrans : 2;
        unsigned int hbus2to1_dbg_hwrite : 1;
        unsigned int hbus2to1_dbg_hext_sel : 2;
        unsigned int hbus2to1_dbg_hexokay : 1;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dlock_ahb_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dlock_ahb_END (2)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dlock_mstbusy_START (3)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dlock_mstbusy_END (4)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dcdrerr_secerr_slverr_viserr_START (5)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dcdrerr_secerr_slverr_viserr_END (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hburst_START (9)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hburst_END (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hmastlock_START (12)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hmastlock_END (12)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hprot_START (13)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hprot_END (16)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hsize_START (17)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hsize_END (19)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hnonsec_START (20)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hnonsec_END (20)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hexcl_START (21)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hexcl_END (21)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hmaster_START (22)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hmaster_END (25)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_htrans_START (26)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_htrans_END (27)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hwrite_START (28)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hwrite_END (28)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hext_sel_START (29)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hext_sel_END (30)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hexokay_START (31)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_10_hbus2to1_dbg_hexokay_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hbus2to1_dbg_haddr_user : 8;
        unsigned int hbus2to1_dbg_hwdata_user : 1;
        unsigned int hbus2to1_dbg_hrdata_user : 1;
        unsigned int hbus2to1_dbg_hresp : 1;
        unsigned int hbus2to1_idle : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_UNION;
#endif
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_haddr_user_START (0)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_haddr_user_END (7)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_hwdata_user_START (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_hwdata_user_END (8)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_hrdata_user_START (9)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_hrdata_user_END (9)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_hresp_START (10)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_dbg_hresp_END (10)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_idle_START (11)
#define SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_11_hbus2to1_idle_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_XPU_LP_CTRL_CFG_DDR_XCTRL_STATUS_13_UNION;
#endif
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
