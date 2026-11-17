#ifndef __PMIC_6563_v500_H__
#define __PMIC_6563_v500_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x0000UL))
#define COMMON_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x0001UL))
#define COMMON_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x0002UL))
#define COMMON_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x0003UL))
#define COMMON_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x0004UL))
#define COMMON_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x0005UL))
#define COMMON_PMIC_LOCK_ADDR(base) ((base) + (0x0006UL))
#define COMMON_PMIC_SYS_STATUS_ADDR(base) ((base) + (0x0007UL))
#define COMMON_PMIC_OCP_STATUS0_ADDR(base) ((base) + (0x0008UL))
#define COMMON_PMIC_OCP_STATUS1_ADDR(base) ((base) + (0x0009UL))
#define COMMON_PMIC_SCP_STATUS0_ADDR(base) ((base) + (0x000AUL))
#define COMMON_PMIC_A2D_BUCK_STATUS0_ADDR(base) ((base) + (0x000BUL))
#define COMMON_PMIC_A2D_BUCK_STATUS1_ADDR(base) ((base) + (0x000CUL))
#define COMMON_PMIC_RAMP_STATUS0_ADDR(base) ((base) + (0x000DUL))
#define COMMON_PMIC_RAMP_STATUS1_ADDR(base) ((base) + (0x000EUL))
#define COMMON_PMIC_POWER_STATUS0_ADDR(base) ((base) + (0x000FUL))
#define COMMON_PMIC_POWER_STATUS1_ADDR(base) ((base) + (0x0010UL))
#define COMMON_PMIC_SEL_STATUS_ADDR(base) ((base) + (0x0011UL))
#define COMMON_PMIC_BUCK1_VSET_ADDR(base) ((base) + (0x0015UL))
#define COMMON_PMIC_BUCK1_ONOFF_ADDR(base) ((base) + (0x0016UL))
#define COMMON_PMIC_BUCK2_VSET_ADDR(base) ((base) + (0x0017UL))
#define COMMON_PMIC_BUCK2_ONOFF_ADDR(base) ((base) + (0x0018UL))
#define COMMON_PMIC_BUCK3_VSET_ADDR(base) ((base) + (0x0019UL))
#define COMMON_PMIC_BUCK3_ONOFF_ADDR(base) ((base) + (0x001AUL))
#define COMMON_PMIC_LDO1_VSET_ADDR(base) ((base) + (0x001BUL))
#define COMMON_PMIC_LDO1_ONOFF_ADDR(base) ((base) + (0x001CUL))
#define COMMON_PMIC_LDO2_VSET_ADDR(base) ((base) + (0x001DUL))
#define COMMON_PMIC_LDO2_ONOFF_ADDR(base) ((base) + (0x001EUL))
#define COMMON_PMIC_LDO3_VSET_ADDR(base) ((base) + (0x001FUL))
#define COMMON_PMIC_LDO3_ONOFF_ADDR(base) ((base) + (0x0020UL))
#define COMMON_PMIC_LDO4_VSET_ADDR(base) ((base) + (0x0021UL))
#define COMMON_PMIC_LDO4_ONOFF_ADDR(base) ((base) + (0x0022UL))
#define COMMON_PMIC_LDO5_VSET_ADDR(base) ((base) + (0x0023UL))
#define COMMON_PMIC_LDO5_ONOFF_ADDR(base) ((base) + (0x0024UL))
#define COMMON_PMIC_LDO6_VSET_ADDR(base) ((base) + (0x0025UL))
#define COMMON_PMIC_LDO6_ONOFF_ADDR(base) ((base) + (0x0026UL))
#define COMMON_PMIC_LDO7_VSET_ADDR(base) ((base) + (0x0027UL))
#define COMMON_PMIC_LDO7_ONOFF_ADDR(base) ((base) + (0x0028UL))
#define COMMON_PMIC_LDO8_VSET_ADDR(base) ((base) + (0x0029UL))
#define COMMON_PMIC_LDO8_ONOFF_ADDR(base) ((base) + (0x002AUL))
#define COMMON_PMIC_LDO9_VSET_ADDR(base) ((base) + (0x002BUL))
#define COMMON_PMIC_LDO9_ONOFF_ADDR(base) ((base) + (0x002CUL))
#define COMMON_PMIC_PMUH_VSET_ADDR(base) ((base) + (0x002DUL))
#define COMMON_PMIC_PMUH_ONOFF_ADDR(base) ((base) + (0x002EUL))
#define COMMON_PMIC_PWR_ECO_ONOFF0_ADDR(base) ((base) + (0x002FUL))
#define COMMON_PMIC_PWR_ECO_ONOFF1_ADDR(base) ((base) + (0x0030UL))
#define COMMON_PMIC_BG_THSD_EN_ADDR(base) ((base) + (0x0031UL))
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x0035UL))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x0036UL))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ADDR(base) ((base) + (0x0037UL))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL2_ADDR(base) ((base) + (0x0038UL))
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_ADDR(base) ((base) + (0x0039UL))
#define COMMON_PMIC_SYS_MODE_CTRL0_ADDR(base) ((base) + (0x003AUL))
#define COMMON_PMIC_OCP_DEB_CTRL_ADDR(base) ((base) + (0x003DUL))
#define COMMON_PMIC_SCP_DEB_CTRL_ADDR(base) ((base) + (0x003EUL))
#define COMMON_PMIC_OTMP_DEB_CTRL_ADDR(base) ((base) + (0x003FUL))
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_ADDR(base) ((base) + (0x0040UL))
#define COMMON_PMIC_CORE_IO_DEB_CTRL_ADDR(base) ((base) + (0x0041UL))
#define COMMON_PMIC_ONECLICK_SEQ_EN_ADDR(base) ((base) + (0x0043UL))
#define COMMON_PMIC_ONECLICK_PU_STAGE0_ADDR(base) ((base) + (0x0044UL))
#define COMMON_PMIC_ONECLICK_PU_STAGE1_ADDR(base) ((base) + (0x0045UL))
#define COMMON_PMIC_ONECLICK_PU_STAGE2_ADDR(base) ((base) + (0x0046UL))
#define COMMON_PMIC_ONECLICK_PU_STAGE3_ADDR(base) ((base) + (0x0047UL))
#define COMMON_PMIC_ONECLICK_PD_STAGE0_ADDR(base) ((base) + (0x0048UL))
#define COMMON_PMIC_ONECLICK_PD_STAGE1_ADDR(base) ((base) + (0x0049UL))
#define COMMON_PMIC_ONECLICK_PD_STAGE2_ADDR(base) ((base) + (0x004AUL))
#define COMMON_PMIC_ONECLICK_PD_STAGE3_ADDR(base) ((base) + (0x004BUL))
#define COMMON_PMIC_ONECLICK_PU_CTRL_ADDR(base) ((base) + (0x004CUL))
#define COMMON_PMIC_ONECLICK_STATUS_ADDR(base) ((base) + (0x004EUL))
#define COMMON_PMIC_OSC_9M6_ON_CTRL_ADDR(base) ((base) + (0x0052UL))
#define COMMON_PMIC_OSC_9M6_OFF_CTRL_ADDR(base) ((base) + (0x0053UL))
#define COMMON_PMIC_XVS_IN_DEB_CTRL_ADDR(base) ((base) + (0x0054UL))
#define COMMON_PMIC_XVS_IN_CTRL_ADDR(base) ((base) + (0x0055UL))
#define COMMON_PMIC_RAMP_GT_DEBUG_ADDR(base) ((base) + (0x0056UL))
#define COMMON_PMIC_BUCK1_RAMP_CFG_ADDR(base) ((base) + (0x0057UL))
#define COMMON_PMIC_BUCK1_RAMP_STEP_CFG_ADDR(base) ((base) + (0x0058UL))
#define COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_ADDR(base) ((base) + (0x0059UL))
#define COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_ADDR(base) ((base) + (0x005AUL))
#define COMMON_PMIC_BUCK1_RU_DLY_CFG_ADDR(base) ((base) + (0x005BUL))
#define COMMON_PMIC_BUCK1_RD_DLY_CFG_ADDR(base) ((base) + (0x005CUL))
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_ADDR(base) ((base) + (0x005DUL))
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_ADDR(base) ((base) + (0x005EUL))
#define COMMON_PMIC_BUCK1_XVS_TGT_VSET_ADDR(base) ((base) + (0x005FUL))
#define COMMON_PMIC_BUCK2_RAMP_CFG_ADDR(base) ((base) + (0x0060UL))
#define COMMON_PMIC_BUCK2_RAMP_STEP_CFG_ADDR(base) ((base) + (0x0061UL))
#define COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_ADDR(base) ((base) + (0x0062UL))
#define COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_ADDR(base) ((base) + (0x0063UL))
#define COMMON_PMIC_BUCK2_RU_DLY_CFG_ADDR(base) ((base) + (0x0064UL))
#define COMMON_PMIC_BUCK2_RD_DLY_CFG_ADDR(base) ((base) + (0x0065UL))
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_ADDR(base) ((base) + (0x0066UL))
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_ADDR(base) ((base) + (0x0067UL))
#define COMMON_PMIC_BUCK3_RAMP_CFG_ADDR(base) ((base) + (0x0068UL))
#define COMMON_PMIC_BUCK3_RAMP_STEP_CFG_ADDR(base) ((base) + (0x0069UL))
#define COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_ADDR(base) ((base) + (0x006AUL))
#define COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_ADDR(base) ((base) + (0x006BUL))
#define COMMON_PMIC_BUCK3_RU_DLY_CFG_ADDR(base) ((base) + (0x006CUL))
#define COMMON_PMIC_BUCK3_RD_DLY_CFG_ADDR(base) ((base) + (0x006DUL))
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_ADDR(base) ((base) + (0x006EUL))
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_ADDR(base) ((base) + (0x006FUL))
#define COMMON_PMIC_LDO1_RAMP_CFG_ADDR(base) ((base) + (0x0070UL))
#define COMMON_PMIC_LDO1_RU_DLY_CFG_ADDR(base) ((base) + (0x0071UL))
#define COMMON_PMIC_LDO1_PD_DLY_CFG_ADDR(base) ((base) + (0x0072UL))
#define COMMON_PMIC_LDO3_RAMP_CFG_ADDR(base) ((base) + (0x0073UL))
#define COMMON_PMIC_LDO3_RU_DLY_CFG_ADDR(base) ((base) + (0x0074UL))
#define COMMON_PMIC_LDO3_PD_DLY_CFG_ADDR(base) ((base) + (0x0075UL))
#define COMMON_PMIC_LDO8_RAMP_CFG_ADDR(base) ((base) + (0x0076UL))
#define COMMON_PMIC_LDO8_RU_DLY_CFG_ADDR(base) ((base) + (0x0077UL))
#define COMMON_PMIC_LDO8_PD_DLY_CFG_ADDR(base) ((base) + (0x0078UL))
#define COMMON_PMIC_DIG_RAMP_STATUS_ADDR(base) ((base) + (0x0079UL))
#else
#define COMMON_PMIC_CHIP_VERSION_0_ADDR(base) ((base) + (0x0000))
#define COMMON_PMIC_CHIP_VERSION_1_ADDR(base) ((base) + (0x0001))
#define COMMON_PMIC_CHIP_VERSION_2_ADDR(base) ((base) + (0x0002))
#define COMMON_PMIC_CHIP_VERSION_3_ADDR(base) ((base) + (0x0003))
#define COMMON_PMIC_CHIP_VERSION_4_ADDR(base) ((base) + (0x0004))
#define COMMON_PMIC_CHIP_VERSION_5_ADDR(base) ((base) + (0x0005))
#define COMMON_PMIC_LOCK_ADDR(base) ((base) + (0x0006))
#define COMMON_PMIC_SYS_STATUS_ADDR(base) ((base) + (0x0007))
#define COMMON_PMIC_OCP_STATUS0_ADDR(base) ((base) + (0x0008))
#define COMMON_PMIC_OCP_STATUS1_ADDR(base) ((base) + (0x0009))
#define COMMON_PMIC_SCP_STATUS0_ADDR(base) ((base) + (0x000A))
#define COMMON_PMIC_A2D_BUCK_STATUS0_ADDR(base) ((base) + (0x000B))
#define COMMON_PMIC_A2D_BUCK_STATUS1_ADDR(base) ((base) + (0x000C))
#define COMMON_PMIC_RAMP_STATUS0_ADDR(base) ((base) + (0x000D))
#define COMMON_PMIC_RAMP_STATUS1_ADDR(base) ((base) + (0x000E))
#define COMMON_PMIC_POWER_STATUS0_ADDR(base) ((base) + (0x000F))
#define COMMON_PMIC_POWER_STATUS1_ADDR(base) ((base) + (0x0010))
#define COMMON_PMIC_SEL_STATUS_ADDR(base) ((base) + (0x0011))
#define COMMON_PMIC_BUCK1_VSET_ADDR(base) ((base) + (0x0015))
#define COMMON_PMIC_BUCK1_ONOFF_ADDR(base) ((base) + (0x0016))
#define COMMON_PMIC_BUCK2_VSET_ADDR(base) ((base) + (0x0017))
#define COMMON_PMIC_BUCK2_ONOFF_ADDR(base) ((base) + (0x0018))
#define COMMON_PMIC_BUCK3_VSET_ADDR(base) ((base) + (0x0019))
#define COMMON_PMIC_BUCK3_ONOFF_ADDR(base) ((base) + (0x001A))
#define COMMON_PMIC_LDO1_VSET_ADDR(base) ((base) + (0x001B))
#define COMMON_PMIC_LDO1_ONOFF_ADDR(base) ((base) + (0x001C))
#define COMMON_PMIC_LDO2_VSET_ADDR(base) ((base) + (0x001D))
#define COMMON_PMIC_LDO2_ONOFF_ADDR(base) ((base) + (0x001E))
#define COMMON_PMIC_LDO3_VSET_ADDR(base) ((base) + (0x001F))
#define COMMON_PMIC_LDO3_ONOFF_ADDR(base) ((base) + (0x0020))
#define COMMON_PMIC_LDO4_VSET_ADDR(base) ((base) + (0x0021))
#define COMMON_PMIC_LDO4_ONOFF_ADDR(base) ((base) + (0x0022))
#define COMMON_PMIC_LDO5_VSET_ADDR(base) ((base) + (0x0023))
#define COMMON_PMIC_LDO5_ONOFF_ADDR(base) ((base) + (0x0024))
#define COMMON_PMIC_LDO6_VSET_ADDR(base) ((base) + (0x0025))
#define COMMON_PMIC_LDO6_ONOFF_ADDR(base) ((base) + (0x0026))
#define COMMON_PMIC_LDO7_VSET_ADDR(base) ((base) + (0x0027))
#define COMMON_PMIC_LDO7_ONOFF_ADDR(base) ((base) + (0x0028))
#define COMMON_PMIC_LDO8_VSET_ADDR(base) ((base) + (0x0029))
#define COMMON_PMIC_LDO8_ONOFF_ADDR(base) ((base) + (0x002A))
#define COMMON_PMIC_LDO9_VSET_ADDR(base) ((base) + (0x002B))
#define COMMON_PMIC_LDO9_ONOFF_ADDR(base) ((base) + (0x002C))
#define COMMON_PMIC_PMUH_VSET_ADDR(base) ((base) + (0x002D))
#define COMMON_PMIC_PMUH_ONOFF_ADDR(base) ((base) + (0x002E))
#define COMMON_PMIC_PWR_ECO_ONOFF0_ADDR(base) ((base) + (0x002F))
#define COMMON_PMIC_PWR_ECO_ONOFF1_ADDR(base) ((base) + (0x0030))
#define COMMON_PMIC_BG_THSD_EN_ADDR(base) ((base) + (0x0031))
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x0035))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ADDR(base) ((base) + (0x0036))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ADDR(base) ((base) + (0x0037))
#define COMMON_PMIC_LDO_OCP_MODE_CTRL2_ADDR(base) ((base) + (0x0038))
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_ADDR(base) ((base) + (0x0039))
#define COMMON_PMIC_SYS_MODE_CTRL0_ADDR(base) ((base) + (0x003A))
#define COMMON_PMIC_OCP_DEB_CTRL_ADDR(base) ((base) + (0x003D))
#define COMMON_PMIC_SCP_DEB_CTRL_ADDR(base) ((base) + (0x003E))
#define COMMON_PMIC_OTMP_DEB_CTRL_ADDR(base) ((base) + (0x003F))
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_ADDR(base) ((base) + (0x0040))
#define COMMON_PMIC_CORE_IO_DEB_CTRL_ADDR(base) ((base) + (0x0041))
#define COMMON_PMIC_ONECLICK_SEQ_EN_ADDR(base) ((base) + (0x0043))
#define COMMON_PMIC_ONECLICK_PU_STAGE0_ADDR(base) ((base) + (0x0044))
#define COMMON_PMIC_ONECLICK_PU_STAGE1_ADDR(base) ((base) + (0x0045))
#define COMMON_PMIC_ONECLICK_PU_STAGE2_ADDR(base) ((base) + (0x0046))
#define COMMON_PMIC_ONECLICK_PU_STAGE3_ADDR(base) ((base) + (0x0047))
#define COMMON_PMIC_ONECLICK_PD_STAGE0_ADDR(base) ((base) + (0x0048))
#define COMMON_PMIC_ONECLICK_PD_STAGE1_ADDR(base) ((base) + (0x0049))
#define COMMON_PMIC_ONECLICK_PD_STAGE2_ADDR(base) ((base) + (0x004A))
#define COMMON_PMIC_ONECLICK_PD_STAGE3_ADDR(base) ((base) + (0x004B))
#define COMMON_PMIC_ONECLICK_PU_CTRL_ADDR(base) ((base) + (0x004C))
#define COMMON_PMIC_ONECLICK_STATUS_ADDR(base) ((base) + (0x004E))
#define COMMON_PMIC_OSC_9M6_ON_CTRL_ADDR(base) ((base) + (0x0052))
#define COMMON_PMIC_OSC_9M6_OFF_CTRL_ADDR(base) ((base) + (0x0053))
#define COMMON_PMIC_XVS_IN_DEB_CTRL_ADDR(base) ((base) + (0x0054))
#define COMMON_PMIC_XVS_IN_CTRL_ADDR(base) ((base) + (0x0055))
#define COMMON_PMIC_RAMP_GT_DEBUG_ADDR(base) ((base) + (0x0056))
#define COMMON_PMIC_BUCK1_RAMP_CFG_ADDR(base) ((base) + (0x0057))
#define COMMON_PMIC_BUCK1_RAMP_STEP_CFG_ADDR(base) ((base) + (0x0058))
#define COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_ADDR(base) ((base) + (0x0059))
#define COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_ADDR(base) ((base) + (0x005A))
#define COMMON_PMIC_BUCK1_RU_DLY_CFG_ADDR(base) ((base) + (0x005B))
#define COMMON_PMIC_BUCK1_RD_DLY_CFG_ADDR(base) ((base) + (0x005C))
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_ADDR(base) ((base) + (0x005D))
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_ADDR(base) ((base) + (0x005E))
#define COMMON_PMIC_BUCK1_XVS_TGT_VSET_ADDR(base) ((base) + (0x005F))
#define COMMON_PMIC_BUCK2_RAMP_CFG_ADDR(base) ((base) + (0x0060))
#define COMMON_PMIC_BUCK2_RAMP_STEP_CFG_ADDR(base) ((base) + (0x0061))
#define COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_ADDR(base) ((base) + (0x0062))
#define COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_ADDR(base) ((base) + (0x0063))
#define COMMON_PMIC_BUCK2_RU_DLY_CFG_ADDR(base) ((base) + (0x0064))
#define COMMON_PMIC_BUCK2_RD_DLY_CFG_ADDR(base) ((base) + (0x0065))
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_ADDR(base) ((base) + (0x0066))
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_ADDR(base) ((base) + (0x0067))
#define COMMON_PMIC_BUCK3_RAMP_CFG_ADDR(base) ((base) + (0x0068))
#define COMMON_PMIC_BUCK3_RAMP_STEP_CFG_ADDR(base) ((base) + (0x0069))
#define COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_ADDR(base) ((base) + (0x006A))
#define COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_ADDR(base) ((base) + (0x006B))
#define COMMON_PMIC_BUCK3_RU_DLY_CFG_ADDR(base) ((base) + (0x006C))
#define COMMON_PMIC_BUCK3_RD_DLY_CFG_ADDR(base) ((base) + (0x006D))
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_ADDR(base) ((base) + (0x006E))
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_ADDR(base) ((base) + (0x006F))
#define COMMON_PMIC_LDO1_RAMP_CFG_ADDR(base) ((base) + (0x0070))
#define COMMON_PMIC_LDO1_RU_DLY_CFG_ADDR(base) ((base) + (0x0071))
#define COMMON_PMIC_LDO1_PD_DLY_CFG_ADDR(base) ((base) + (0x0072))
#define COMMON_PMIC_LDO3_RAMP_CFG_ADDR(base) ((base) + (0x0073))
#define COMMON_PMIC_LDO3_RU_DLY_CFG_ADDR(base) ((base) + (0x0074))
#define COMMON_PMIC_LDO3_PD_DLY_CFG_ADDR(base) ((base) + (0x0075))
#define COMMON_PMIC_LDO8_RAMP_CFG_ADDR(base) ((base) + (0x0076))
#define COMMON_PMIC_LDO8_RU_DLY_CFG_ADDR(base) ((base) + (0x0077))
#define COMMON_PMIC_LDO8_PD_DLY_CFG_ADDR(base) ((base) + (0x0078))
#define COMMON_PMIC_DIG_RAMP_STATUS_ADDR(base) ((base) + (0x0079))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_EFUSE_LOCK_ADDR(base) ((base) + (0x0100UL))
#define COMMON_PMIC_EFUSE_CLK_CTRL_ADDR(base) ((base) + (0x0101UL))
#define COMMON_PMIC_EFUSE_LOOP_RD_CTRL_ADDR(base) ((base) + (0x0102UL))
#define COMMON_PMIC_EFUSE_WR_PULSE_CTRL_ADDR(base) ((base) + (0x0103UL))
#define COMMON_PMIC_EFUSE0_D_ADDR(base) ((base) + (0x0105UL))
#define COMMON_PMIC_EFUSE0_AEN_MODE_ADDR(base) ((base) + (0x0106UL))
#define COMMON_PMIC_EFUSE0_MODE_CTRL_ADDR(base) ((base) + (0x0107UL))
#define COMMON_PMIC_EFUSE0_RDEN_CFG_ADDR(base) ((base) + (0x0108UL))
#define COMMON_PMIC_EFUSE0_PGMEN_CFG_ADDR(base) ((base) + (0x0109UL))
#define COMMON_PMIC_EFUSE0_AEN_CFG_ADDR(base) ((base) + (0x010AUL))
#define COMMON_PMIC_EFUSE0_ADDR_L_ADDR(base) ((base) + (0x010BUL))
#define COMMON_PMIC_EFUSE0_ADDR_H_ADDR(base) ((base) + (0x010CUL))
#define COMMON_PMIC_EFUSE0_TESTBUS_EN_ADDR(base) ((base) + (0x010DUL))
#define COMMON_PMIC_EFUSE0_TESTBUS_SEL_ADDR(base) ((base) + (0x010EUL))
#define COMMON_PMIC_EFUSE0_TESTBUS_DATA_ADDR(base) ((base) + (0x010FUL))
#define COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x0110UL))
#define COMMON_PMIC_EFUSE0_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x0111UL))
#define COMMON_PMIC_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x0112UL))
#define COMMON_PMIC_EFUSE0_FSM_RESET_ADDR(base) ((base) + (0x0113UL))
#else
#define COMMON_PMIC_EFUSE_LOCK_ADDR(base) ((base) + (0x0100))
#define COMMON_PMIC_EFUSE_CLK_CTRL_ADDR(base) ((base) + (0x0101))
#define COMMON_PMIC_EFUSE_LOOP_RD_CTRL_ADDR(base) ((base) + (0x0102))
#define COMMON_PMIC_EFUSE_WR_PULSE_CTRL_ADDR(base) ((base) + (0x0103))
#define COMMON_PMIC_EFUSE0_D_ADDR(base) ((base) + (0x0105))
#define COMMON_PMIC_EFUSE0_AEN_MODE_ADDR(base) ((base) + (0x0106))
#define COMMON_PMIC_EFUSE0_MODE_CTRL_ADDR(base) ((base) + (0x0107))
#define COMMON_PMIC_EFUSE0_RDEN_CFG_ADDR(base) ((base) + (0x0108))
#define COMMON_PMIC_EFUSE0_PGMEN_CFG_ADDR(base) ((base) + (0x0109))
#define COMMON_PMIC_EFUSE0_AEN_CFG_ADDR(base) ((base) + (0x010A))
#define COMMON_PMIC_EFUSE0_ADDR_L_ADDR(base) ((base) + (0x010B))
#define COMMON_PMIC_EFUSE0_ADDR_H_ADDR(base) ((base) + (0x010C))
#define COMMON_PMIC_EFUSE0_TESTBUS_EN_ADDR(base) ((base) + (0x010D))
#define COMMON_PMIC_EFUSE0_TESTBUS_SEL_ADDR(base) ((base) + (0x010E))
#define COMMON_PMIC_EFUSE0_TESTBUS_DATA_ADDR(base) ((base) + (0x010F))
#define COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x0110))
#define COMMON_PMIC_EFUSE0_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x0111))
#define COMMON_PMIC_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x0112))
#define COMMON_PMIC_EFUSE0_FSM_RESET_ADDR(base) ((base) + (0x0113))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_EFUSE0_0_W_ADDR(base) ((base) + (0x0180UL))
#define COMMON_PMIC_EFUSE0_1_W_ADDR(base) ((base) + (0x0181UL))
#define COMMON_PMIC_EFUSE0_2_W_ADDR(base) ((base) + (0x0182UL))
#define COMMON_PMIC_EFUSE0_3_W_ADDR(base) ((base) + (0x0183UL))
#define COMMON_PMIC_EFUSE0_4_W_ADDR(base) ((base) + (0x0184UL))
#define COMMON_PMIC_EFUSE0_5_W_ADDR(base) ((base) + (0x0185UL))
#define COMMON_PMIC_EFUSE0_6_W_ADDR(base) ((base) + (0x0186UL))
#define COMMON_PMIC_EFUSE0_7_W_ADDR(base) ((base) + (0x0187UL))
#define COMMON_PMIC_EFUSE0_8_W_ADDR(base) ((base) + (0x0188UL))
#define COMMON_PMIC_EFUSE0_9_W_ADDR(base) ((base) + (0x0189UL))
#define COMMON_PMIC_EFUSE0_10_W_ADDR(base) ((base) + (0x018AUL))
#define COMMON_PMIC_EFUSE0_11_W_ADDR(base) ((base) + (0x018BUL))
#define COMMON_PMIC_EFUSE0_12_W_ADDR(base) ((base) + (0x018CUL))
#define COMMON_PMIC_EFUSE0_13_W_ADDR(base) ((base) + (0x018DUL))
#define COMMON_PMIC_EFUSE0_14_W_ADDR(base) ((base) + (0x018EUL))
#define COMMON_PMIC_EFUSE0_15_W_ADDR(base) ((base) + (0x018FUL))
#define COMMON_PMIC_EFUSE0_16_W_ADDR(base) ((base) + (0x0190UL))
#define COMMON_PMIC_EFUSE0_17_W_ADDR(base) ((base) + (0x0191UL))
#define COMMON_PMIC_EFUSE0_18_W_ADDR(base) ((base) + (0x0192UL))
#define COMMON_PMIC_EFUSE0_19_W_ADDR(base) ((base) + (0x0193UL))
#define COMMON_PMIC_EFUSE0_20_W_ADDR(base) ((base) + (0x0194UL))
#define COMMON_PMIC_EFUSE0_21_W_ADDR(base) ((base) + (0x0195UL))
#define COMMON_PMIC_EFUSE0_22_W_ADDR(base) ((base) + (0x0196UL))
#define COMMON_PMIC_EFUSE0_23_W_ADDR(base) ((base) + (0x0197UL))
#define COMMON_PMIC_EFUSE0_24_W_ADDR(base) ((base) + (0x0198UL))
#define COMMON_PMIC_EFUSE0_25_W_ADDR(base) ((base) + (0x0199UL))
#define COMMON_PMIC_EFUSE0_26_W_ADDR(base) ((base) + (0x019AUL))
#define COMMON_PMIC_EFUSE0_27_W_ADDR(base) ((base) + (0x019BUL))
#define COMMON_PMIC_EFUSE0_28_W_ADDR(base) ((base) + (0x019CUL))
#define COMMON_PMIC_EFUSE0_29_W_ADDR(base) ((base) + (0x019DUL))
#define COMMON_PMIC_EFUSE0_30_W_ADDR(base) ((base) + (0x019EUL))
#define COMMON_PMIC_EFUSE0_31_W_ADDR(base) ((base) + (0x019FUL))
#define COMMON_PMIC_EFUSE0_32_W_ADDR(base) ((base) + (0x01A0UL))
#define COMMON_PMIC_EFUSE0_33_W_ADDR(base) ((base) + (0x01A1UL))
#define COMMON_PMIC_EFUSE0_34_W_ADDR(base) ((base) + (0x01A2UL))
#define COMMON_PMIC_EFUSE0_35_W_ADDR(base) ((base) + (0x01A3UL))
#define COMMON_PMIC_EFUSE0_36_W_ADDR(base) ((base) + (0x01A4UL))
#define COMMON_PMIC_EFUSE0_37_W_ADDR(base) ((base) + (0x01A5UL))
#define COMMON_PMIC_EFUSE0_38_W_ADDR(base) ((base) + (0x01A6UL))
#define COMMON_PMIC_EFUSE0_39_W_ADDR(base) ((base) + (0x01A7UL))
#define COMMON_PMIC_EFUSE0_40_W_ADDR(base) ((base) + (0x01A8UL))
#define COMMON_PMIC_EFUSE0_41_W_ADDR(base) ((base) + (0x01A9UL))
#define COMMON_PMIC_EFUSE0_42_W_ADDR(base) ((base) + (0x01AAUL))
#define COMMON_PMIC_NP_EFUSE0_0_R_ADDR(base) ((base) + (0x01B0UL))
#define COMMON_PMIC_NP_EFUSE0_1_R_ADDR(base) ((base) + (0x01B1UL))
#define COMMON_PMIC_NP_EFUSE0_2_R_ADDR(base) ((base) + (0x01B2UL))
#define COMMON_PMIC_NP_EFUSE0_3_R_ADDR(base) ((base) + (0x01B3UL))
#define COMMON_PMIC_NP_EFUSE0_4_R_ADDR(base) ((base) + (0x01B4UL))
#define COMMON_PMIC_NP_EFUSE0_5_R_ADDR(base) ((base) + (0x01B5UL))
#define COMMON_PMIC_NP_EFUSE0_6_R_ADDR(base) ((base) + (0x01B6UL))
#define COMMON_PMIC_NP_EFUSE0_7_R_ADDR(base) ((base) + (0x01B7UL))
#define COMMON_PMIC_NP_EFUSE0_8_R_ADDR(base) ((base) + (0x01B8UL))
#define COMMON_PMIC_NP_EFUSE0_9_R_ADDR(base) ((base) + (0x01B9UL))
#define COMMON_PMIC_NP_EFUSE0_10_R_ADDR(base) ((base) + (0x01BAUL))
#define COMMON_PMIC_NP_EFUSE0_11_R_ADDR(base) ((base) + (0x01BBUL))
#define COMMON_PMIC_NP_EFUSE0_12_R_ADDR(base) ((base) + (0x01BCUL))
#define COMMON_PMIC_NP_EFUSE0_13_R_ADDR(base) ((base) + (0x01BDUL))
#define COMMON_PMIC_NP_EFUSE0_14_R_ADDR(base) ((base) + (0x01BEUL))
#define COMMON_PMIC_NP_EFUSE0_15_R_ADDR(base) ((base) + (0x01BFUL))
#define COMMON_PMIC_NP_EFUSE0_16_R_ADDR(base) ((base) + (0x01C0UL))
#define COMMON_PMIC_NP_EFUSE0_17_R_ADDR(base) ((base) + (0x01C1UL))
#define COMMON_PMIC_NP_EFUSE0_18_R_ADDR(base) ((base) + (0x01C2UL))
#define COMMON_PMIC_NP_EFUSE0_19_R_ADDR(base) ((base) + (0x01C3UL))
#define COMMON_PMIC_NP_EFUSE0_20_R_ADDR(base) ((base) + (0x01C4UL))
#define COMMON_PMIC_NP_EFUSE0_21_R_ADDR(base) ((base) + (0x01C5UL))
#define COMMON_PMIC_NP_EFUSE0_22_R_ADDR(base) ((base) + (0x01C6UL))
#define COMMON_PMIC_NP_EFUSE0_23_R_ADDR(base) ((base) + (0x01C7UL))
#define COMMON_PMIC_NP_EFUSE0_24_R_ADDR(base) ((base) + (0x01C8UL))
#define COMMON_PMIC_NP_EFUSE0_25_R_ADDR(base) ((base) + (0x01C9UL))
#define COMMON_PMIC_NP_EFUSE0_26_R_ADDR(base) ((base) + (0x01CAUL))
#define COMMON_PMIC_NP_EFUSE0_27_R_ADDR(base) ((base) + (0x01CBUL))
#define COMMON_PMIC_NP_EFUSE0_28_R_ADDR(base) ((base) + (0x01CCUL))
#define COMMON_PMIC_NP_EFUSE0_29_R_ADDR(base) ((base) + (0x01CDUL))
#define COMMON_PMIC_NP_EFUSE0_30_R_ADDR(base) ((base) + (0x01CEUL))
#define COMMON_PMIC_NP_EFUSE0_31_R_ADDR(base) ((base) + (0x01CFUL))
#define COMMON_PMIC_NP_EFUSE0_32_R_ADDR(base) ((base) + (0x01D0UL))
#define COMMON_PMIC_NP_EFUSE0_33_R_ADDR(base) ((base) + (0x01D1UL))
#define COMMON_PMIC_NP_EFUSE0_34_R_ADDR(base) ((base) + (0x01D2UL))
#define COMMON_PMIC_NP_EFUSE0_35_R_ADDR(base) ((base) + (0x01D3UL))
#define COMMON_PMIC_NP_EFUSE0_36_R_ADDR(base) ((base) + (0x01D4UL))
#define COMMON_PMIC_NP_EFUSE0_37_R_ADDR(base) ((base) + (0x01D5UL))
#define COMMON_PMIC_NP_EFUSE0_38_R_ADDR(base) ((base) + (0x01D6UL))
#define COMMON_PMIC_NP_EFUSE0_39_R_ADDR(base) ((base) + (0x01D7UL))
#define COMMON_PMIC_NP_EFUSE0_40_R_ADDR(base) ((base) + (0x01D8UL))
#define COMMON_PMIC_NP_EFUSE0_41_R_ADDR(base) ((base) + (0x01D9UL))
#define COMMON_PMIC_NP_EFUSE0_42_R_ADDR(base) ((base) + (0x01DAUL))
#define COMMON_PMIC_NP_EFUSE0_43_R_ADDR(base) ((base) + (0x01DBUL))
#define COMMON_PMIC_NP_EFUSE0_44_R_ADDR(base) ((base) + (0x01DCUL))
#define COMMON_PMIC_NP_EFUSE0_45_R_ADDR(base) ((base) + (0x01DDUL))
#define COMMON_PMIC_NP_EFUSE0_46_R_ADDR(base) ((base) + (0x01DEUL))
#define COMMON_PMIC_NP_EFUSE0_47_R_ADDR(base) ((base) + (0x01DFUL))
#define COMMON_PMIC_NP_EFUSE0_48_R_ADDR(base) ((base) + (0x01E0UL))
#define COMMON_PMIC_NP_EFUSE0_49_R_ADDR(base) ((base) + (0x01E1UL))
#define COMMON_PMIC_NP_EFUSE0_50_R_ADDR(base) ((base) + (0x01E2UL))
#define COMMON_PMIC_NP_EFUSE0_51_R_ADDR(base) ((base) + (0x01E3UL))
#define COMMON_PMIC_NP_EFUSE0_52_R_ADDR(base) ((base) + (0x01E4UL))
#define COMMON_PMIC_NP_EFUSE0_53_R_ADDR(base) ((base) + (0x01E5UL))
#define COMMON_PMIC_NP_EFUSE0_54_R_ADDR(base) ((base) + (0x01E6UL))
#define COMMON_PMIC_NP_EFUSE0_55_R_ADDR(base) ((base) + (0x01E7UL))
#define COMMON_PMIC_NP_EFUSE0_56_R_ADDR(base) ((base) + (0x01E8UL))
#define COMMON_PMIC_NP_EFUSE0_57_R_ADDR(base) ((base) + (0x01E9UL))
#define COMMON_PMIC_NP_EFUSE0_58_R_ADDR(base) ((base) + (0x01EAUL))
#define COMMON_PMIC_NP_EFUSE0_59_R_ADDR(base) ((base) + (0x01EBUL))
#define COMMON_PMIC_NP_EFUSE0_60_R_ADDR(base) ((base) + (0x01ECUL))
#define COMMON_PMIC_NP_EFUSE0_61_R_ADDR(base) ((base) + (0x01EDUL))
#define COMMON_PMIC_NP_EFUSE0_62_R_ADDR(base) ((base) + (0x01EEUL))
#define COMMON_PMIC_NP_EFUSE0_63_R_ADDR(base) ((base) + (0x01EFUL))
#else
#define COMMON_PMIC_EFUSE0_0_W_ADDR(base) ((base) + (0x0180))
#define COMMON_PMIC_EFUSE0_1_W_ADDR(base) ((base) + (0x0181))
#define COMMON_PMIC_EFUSE0_2_W_ADDR(base) ((base) + (0x0182))
#define COMMON_PMIC_EFUSE0_3_W_ADDR(base) ((base) + (0x0183))
#define COMMON_PMIC_EFUSE0_4_W_ADDR(base) ((base) + (0x0184))
#define COMMON_PMIC_EFUSE0_5_W_ADDR(base) ((base) + (0x0185))
#define COMMON_PMIC_EFUSE0_6_W_ADDR(base) ((base) + (0x0186))
#define COMMON_PMIC_EFUSE0_7_W_ADDR(base) ((base) + (0x0187))
#define COMMON_PMIC_EFUSE0_8_W_ADDR(base) ((base) + (0x0188))
#define COMMON_PMIC_EFUSE0_9_W_ADDR(base) ((base) + (0x0189))
#define COMMON_PMIC_EFUSE0_10_W_ADDR(base) ((base) + (0x018A))
#define COMMON_PMIC_EFUSE0_11_W_ADDR(base) ((base) + (0x018B))
#define COMMON_PMIC_EFUSE0_12_W_ADDR(base) ((base) + (0x018C))
#define COMMON_PMIC_EFUSE0_13_W_ADDR(base) ((base) + (0x018D))
#define COMMON_PMIC_EFUSE0_14_W_ADDR(base) ((base) + (0x018E))
#define COMMON_PMIC_EFUSE0_15_W_ADDR(base) ((base) + (0x018F))
#define COMMON_PMIC_EFUSE0_16_W_ADDR(base) ((base) + (0x0190))
#define COMMON_PMIC_EFUSE0_17_W_ADDR(base) ((base) + (0x0191))
#define COMMON_PMIC_EFUSE0_18_W_ADDR(base) ((base) + (0x0192))
#define COMMON_PMIC_EFUSE0_19_W_ADDR(base) ((base) + (0x0193))
#define COMMON_PMIC_EFUSE0_20_W_ADDR(base) ((base) + (0x0194))
#define COMMON_PMIC_EFUSE0_21_W_ADDR(base) ((base) + (0x0195))
#define COMMON_PMIC_EFUSE0_22_W_ADDR(base) ((base) + (0x0196))
#define COMMON_PMIC_EFUSE0_23_W_ADDR(base) ((base) + (0x0197))
#define COMMON_PMIC_EFUSE0_24_W_ADDR(base) ((base) + (0x0198))
#define COMMON_PMIC_EFUSE0_25_W_ADDR(base) ((base) + (0x0199))
#define COMMON_PMIC_EFUSE0_26_W_ADDR(base) ((base) + (0x019A))
#define COMMON_PMIC_EFUSE0_27_W_ADDR(base) ((base) + (0x019B))
#define COMMON_PMIC_EFUSE0_28_W_ADDR(base) ((base) + (0x019C))
#define COMMON_PMIC_EFUSE0_29_W_ADDR(base) ((base) + (0x019D))
#define COMMON_PMIC_EFUSE0_30_W_ADDR(base) ((base) + (0x019E))
#define COMMON_PMIC_EFUSE0_31_W_ADDR(base) ((base) + (0x019F))
#define COMMON_PMIC_EFUSE0_32_W_ADDR(base) ((base) + (0x01A0))
#define COMMON_PMIC_EFUSE0_33_W_ADDR(base) ((base) + (0x01A1))
#define COMMON_PMIC_EFUSE0_34_W_ADDR(base) ((base) + (0x01A2))
#define COMMON_PMIC_EFUSE0_35_W_ADDR(base) ((base) + (0x01A3))
#define COMMON_PMIC_EFUSE0_36_W_ADDR(base) ((base) + (0x01A4))
#define COMMON_PMIC_EFUSE0_37_W_ADDR(base) ((base) + (0x01A5))
#define COMMON_PMIC_EFUSE0_38_W_ADDR(base) ((base) + (0x01A6))
#define COMMON_PMIC_EFUSE0_39_W_ADDR(base) ((base) + (0x01A7))
#define COMMON_PMIC_EFUSE0_40_W_ADDR(base) ((base) + (0x01A8))
#define COMMON_PMIC_EFUSE0_41_W_ADDR(base) ((base) + (0x01A9))
#define COMMON_PMIC_EFUSE0_42_W_ADDR(base) ((base) + (0x01AA))
#define COMMON_PMIC_NP_EFUSE0_0_R_ADDR(base) ((base) + (0x01B0))
#define COMMON_PMIC_NP_EFUSE0_1_R_ADDR(base) ((base) + (0x01B1))
#define COMMON_PMIC_NP_EFUSE0_2_R_ADDR(base) ((base) + (0x01B2))
#define COMMON_PMIC_NP_EFUSE0_3_R_ADDR(base) ((base) + (0x01B3))
#define COMMON_PMIC_NP_EFUSE0_4_R_ADDR(base) ((base) + (0x01B4))
#define COMMON_PMIC_NP_EFUSE0_5_R_ADDR(base) ((base) + (0x01B5))
#define COMMON_PMIC_NP_EFUSE0_6_R_ADDR(base) ((base) + (0x01B6))
#define COMMON_PMIC_NP_EFUSE0_7_R_ADDR(base) ((base) + (0x01B7))
#define COMMON_PMIC_NP_EFUSE0_8_R_ADDR(base) ((base) + (0x01B8))
#define COMMON_PMIC_NP_EFUSE0_9_R_ADDR(base) ((base) + (0x01B9))
#define COMMON_PMIC_NP_EFUSE0_10_R_ADDR(base) ((base) + (0x01BA))
#define COMMON_PMIC_NP_EFUSE0_11_R_ADDR(base) ((base) + (0x01BB))
#define COMMON_PMIC_NP_EFUSE0_12_R_ADDR(base) ((base) + (0x01BC))
#define COMMON_PMIC_NP_EFUSE0_13_R_ADDR(base) ((base) + (0x01BD))
#define COMMON_PMIC_NP_EFUSE0_14_R_ADDR(base) ((base) + (0x01BE))
#define COMMON_PMIC_NP_EFUSE0_15_R_ADDR(base) ((base) + (0x01BF))
#define COMMON_PMIC_NP_EFUSE0_16_R_ADDR(base) ((base) + (0x01C0))
#define COMMON_PMIC_NP_EFUSE0_17_R_ADDR(base) ((base) + (0x01C1))
#define COMMON_PMIC_NP_EFUSE0_18_R_ADDR(base) ((base) + (0x01C2))
#define COMMON_PMIC_NP_EFUSE0_19_R_ADDR(base) ((base) + (0x01C3))
#define COMMON_PMIC_NP_EFUSE0_20_R_ADDR(base) ((base) + (0x01C4))
#define COMMON_PMIC_NP_EFUSE0_21_R_ADDR(base) ((base) + (0x01C5))
#define COMMON_PMIC_NP_EFUSE0_22_R_ADDR(base) ((base) + (0x01C6))
#define COMMON_PMIC_NP_EFUSE0_23_R_ADDR(base) ((base) + (0x01C7))
#define COMMON_PMIC_NP_EFUSE0_24_R_ADDR(base) ((base) + (0x01C8))
#define COMMON_PMIC_NP_EFUSE0_25_R_ADDR(base) ((base) + (0x01C9))
#define COMMON_PMIC_NP_EFUSE0_26_R_ADDR(base) ((base) + (0x01CA))
#define COMMON_PMIC_NP_EFUSE0_27_R_ADDR(base) ((base) + (0x01CB))
#define COMMON_PMIC_NP_EFUSE0_28_R_ADDR(base) ((base) + (0x01CC))
#define COMMON_PMIC_NP_EFUSE0_29_R_ADDR(base) ((base) + (0x01CD))
#define COMMON_PMIC_NP_EFUSE0_30_R_ADDR(base) ((base) + (0x01CE))
#define COMMON_PMIC_NP_EFUSE0_31_R_ADDR(base) ((base) + (0x01CF))
#define COMMON_PMIC_NP_EFUSE0_32_R_ADDR(base) ((base) + (0x01D0))
#define COMMON_PMIC_NP_EFUSE0_33_R_ADDR(base) ((base) + (0x01D1))
#define COMMON_PMIC_NP_EFUSE0_34_R_ADDR(base) ((base) + (0x01D2))
#define COMMON_PMIC_NP_EFUSE0_35_R_ADDR(base) ((base) + (0x01D3))
#define COMMON_PMIC_NP_EFUSE0_36_R_ADDR(base) ((base) + (0x01D4))
#define COMMON_PMIC_NP_EFUSE0_37_R_ADDR(base) ((base) + (0x01D5))
#define COMMON_PMIC_NP_EFUSE0_38_R_ADDR(base) ((base) + (0x01D6))
#define COMMON_PMIC_NP_EFUSE0_39_R_ADDR(base) ((base) + (0x01D7))
#define COMMON_PMIC_NP_EFUSE0_40_R_ADDR(base) ((base) + (0x01D8))
#define COMMON_PMIC_NP_EFUSE0_41_R_ADDR(base) ((base) + (0x01D9))
#define COMMON_PMIC_NP_EFUSE0_42_R_ADDR(base) ((base) + (0x01DA))
#define COMMON_PMIC_NP_EFUSE0_43_R_ADDR(base) ((base) + (0x01DB))
#define COMMON_PMIC_NP_EFUSE0_44_R_ADDR(base) ((base) + (0x01DC))
#define COMMON_PMIC_NP_EFUSE0_45_R_ADDR(base) ((base) + (0x01DD))
#define COMMON_PMIC_NP_EFUSE0_46_R_ADDR(base) ((base) + (0x01DE))
#define COMMON_PMIC_NP_EFUSE0_47_R_ADDR(base) ((base) + (0x01DF))
#define COMMON_PMIC_NP_EFUSE0_48_R_ADDR(base) ((base) + (0x01E0))
#define COMMON_PMIC_NP_EFUSE0_49_R_ADDR(base) ((base) + (0x01E1))
#define COMMON_PMIC_NP_EFUSE0_50_R_ADDR(base) ((base) + (0x01E2))
#define COMMON_PMIC_NP_EFUSE0_51_R_ADDR(base) ((base) + (0x01E3))
#define COMMON_PMIC_NP_EFUSE0_52_R_ADDR(base) ((base) + (0x01E4))
#define COMMON_PMIC_NP_EFUSE0_53_R_ADDR(base) ((base) + (0x01E5))
#define COMMON_PMIC_NP_EFUSE0_54_R_ADDR(base) ((base) + (0x01E6))
#define COMMON_PMIC_NP_EFUSE0_55_R_ADDR(base) ((base) + (0x01E7))
#define COMMON_PMIC_NP_EFUSE0_56_R_ADDR(base) ((base) + (0x01E8))
#define COMMON_PMIC_NP_EFUSE0_57_R_ADDR(base) ((base) + (0x01E9))
#define COMMON_PMIC_NP_EFUSE0_58_R_ADDR(base) ((base) + (0x01EA))
#define COMMON_PMIC_NP_EFUSE0_59_R_ADDR(base) ((base) + (0x01EB))
#define COMMON_PMIC_NP_EFUSE0_60_R_ADDR(base) ((base) + (0x01EC))
#define COMMON_PMIC_NP_EFUSE0_61_R_ADDR(base) ((base) + (0x01ED))
#define COMMON_PMIC_NP_EFUSE0_62_R_ADDR(base) ((base) + (0x01EE))
#define COMMON_PMIC_NP_EFUSE0_63_R_ADDR(base) ((base) + (0x01EF))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_IRQ_L2_RPT_0_ADDR(base) ((base) + (0x0200UL))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_ADDR(base) ((base) + (0x0201UL))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_ADDR(base) ((base) + (0x0202UL))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_ADDR(base) ((base) + (0x0203UL))
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_0_ADDR(base) ((base) + (0x0204UL))
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_ADDR(base) ((base) + (0x0205UL))
#define COMMON_PMIC_IRQ_L3_SYS_RPT_ADDR(base) ((base) + (0x0206UL))
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_ADDR(base) ((base) + (0x0207UL))
#else
#define COMMON_PMIC_IRQ_L2_RPT_0_ADDR(base) ((base) + (0x0200))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_ADDR(base) ((base) + (0x0201))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_ADDR(base) ((base) + (0x0202))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_ADDR(base) ((base) + (0x0203))
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_0_ADDR(base) ((base) + (0x0204))
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_ADDR(base) ((base) + (0x0205))
#define COMMON_PMIC_IRQ_L3_SYS_RPT_ADDR(base) ((base) + (0x0206))
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_ADDR(base) ((base) + (0x0207))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_IRQ_L2_MASK_0_ADDR(base) ((base) + (0x0240UL))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_ADDR(base) ((base) + (0x0241UL))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_ADDR(base) ((base) + (0x0242UL))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_ADDR(base) ((base) + (0x0243UL))
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_0_ADDR(base) ((base) + (0x0244UL))
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_ADDR(base) ((base) + (0x0245UL))
#define COMMON_PMIC_IRQ_L3_SYS_MASK_ADDR(base) ((base) + (0x0246UL))
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_ADDR(base) ((base) + (0x0247UL))
#else
#define COMMON_PMIC_IRQ_L2_MASK_0_ADDR(base) ((base) + (0x0240))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_ADDR(base) ((base) + (0x0241))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_ADDR(base) ((base) + (0x0242))
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_ADDR(base) ((base) + (0x0243))
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_0_ADDR(base) ((base) + (0x0244))
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_ADDR(base) ((base) + (0x0245))
#define COMMON_PMIC_IRQ_L3_SYS_MASK_ADDR(base) ((base) + (0x0246))
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_ADDR(base) ((base) + (0x0247))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_NP_OCP0_ADDR(base) ((base) + (0x0280UL))
#define COMMON_PMIC_NP_OCP1_ADDR(base) ((base) + (0x0281UL))
#define COMMON_PMIC_NP_SCP0_ADDR(base) ((base) + (0x0282UL))
#define COMMON_PMIC_NP_BUCK_TEMP0_ADDR(base) ((base) + (0x0283UL))
#define COMMON_PMIC_NP_RECORD0_ADDR(base) ((base) + (0x0284UL))
#define COMMON_PMIC_NP_RECORD1_ADDR(base) ((base) + (0x0285UL))
#define COMMON_PMIC_NP_RECORD2_ADDR(base) ((base) + (0x0286UL))
#define COMMON_PMIC_NP_ONECLICK_EVENT_ADDR(base) ((base) + (0x0287UL))
#define COMMON_PMIC_NP_RAMP_EVENT0_ADDR(base) ((base) + (0x0288UL))
#define COMMON_PMIC_NP_RAMP_EVENT1_ADDR(base) ((base) + (0x0289UL))
#else
#define COMMON_PMIC_NP_OCP0_ADDR(base) ((base) + (0x0280))
#define COMMON_PMIC_NP_OCP1_ADDR(base) ((base) + (0x0281))
#define COMMON_PMIC_NP_SCP0_ADDR(base) ((base) + (0x0282))
#define COMMON_PMIC_NP_BUCK_TEMP0_ADDR(base) ((base) + (0x0283))
#define COMMON_PMIC_NP_RECORD0_ADDR(base) ((base) + (0x0284))
#define COMMON_PMIC_NP_RECORD1_ADDR(base) ((base) + (0x0285))
#define COMMON_PMIC_NP_RECORD2_ADDR(base) ((base) + (0x0286))
#define COMMON_PMIC_NP_ONECLICK_EVENT_ADDR(base) ((base) + (0x0287))
#define COMMON_PMIC_NP_RAMP_EVENT0_ADDR(base) ((base) + (0x0288))
#define COMMON_PMIC_NP_RAMP_EVENT1_ADDR(base) ((base) + (0x0289))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_PMU_SOFT_RST_ADDR(base) ((base) + (0x0300UL))
#define COMMON_PMIC_NP_PD_MASK_ADDR(base) ((base) + (0x0301UL))
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_ADDR(base) ((base) + (0x0302UL))
#define COMMON_PMIC_NP_RC256K_CTRL_ADDR(base) ((base) + (0x0303UL))
#define COMMON_PMIC_NP_DATA_IO_DS0_ADDR(base) ((base) + (0x0304UL))
#define COMMON_PMIC_NP_DATA_IO_DS1_ADDR(base) ((base) + (0x0305UL))
#define COMMON_PMIC_NP_EFUSE_READ_SEL_ADDR(base) ((base) + (0x0306UL))
#define COMMON_PMIC_NP_DTEST_SEL_ADDR(base) ((base) + (0x0310UL))
#define COMMON_PMIC_NP_SYS_CTRL0_ADDR(base) ((base) + (0x0315UL))
#define COMMON_PMIC_NP_PMUD_CTRL0_ADDR(base) ((base) + (0x0316UL))
#define COMMON_PMIC_NP_PMUD_VSET_ADDR(base) ((base) + (0x0317UL))
#define COMMON_PMIC_NP_REF_CTRL0_ADDR(base) ((base) + (0x0318UL))
#define COMMON_PMIC_NP_REF_RSV0_ADDR(base) ((base) + (0x0319UL))
#define COMMON_PMIC_NP_REF_RSV1_ADDR(base) ((base) + (0x031AUL))
#define COMMON_PMIC_NP_BUCK1_CTRL0_ADDR(base) ((base) + (0x0320UL))
#define COMMON_PMIC_NP_BUCK1_CTRL1_ADDR(base) ((base) + (0x0321UL))
#define COMMON_PMIC_NP_BUCK1_RES0_ADDR(base) ((base) + (0x0322UL))
#define COMMON_PMIC_NP_BUCK1_RES1_ADDR(base) ((base) + (0x0323UL))
#define COMMON_PMIC_NP_BUCK2_CTRL0_ADDR(base) ((base) + (0x0324UL))
#define COMMON_PMIC_NP_BUCK2_CTRL1_ADDR(base) ((base) + (0x0325UL))
#define COMMON_PMIC_NP_BUCK2_RES0_ADDR(base) ((base) + (0x0326UL))
#define COMMON_PMIC_NP_BUCK2_RES1_ADDR(base) ((base) + (0x0327UL))
#define COMMON_PMIC_NP_BUCK3_CTRL0_ADDR(base) ((base) + (0x0328UL))
#define COMMON_PMIC_NP_BUCK3_CTRL1_ADDR(base) ((base) + (0x0329UL))
#define COMMON_PMIC_NP_BUCK3_RES0_ADDR(base) ((base) + (0x032AUL))
#define COMMON_PMIC_NP_BUCK3_RES1_ADDR(base) ((base) + (0x032BUL))
#define COMMON_PMIC_NP_BUCK_RSV0_ADDR(base) ((base) + (0x032CUL))
#define COMMON_PMIC_NP_BUCK_RSV1_ADDR(base) ((base) + (0x032DUL))
#define COMMON_PMIC_NP_BUCK_RSV2_ADDR(base) ((base) + (0x032EUL))
#define COMMON_PMIC_NP_BUCK_RSV3_ADDR(base) ((base) + (0x032FUL))
#define COMMON_PMIC_NP_LDO1_CTRL0_ADDR(base) ((base) + (0x0330UL))
#define COMMON_PMIC_NP_LDO2_CTRL0_ADDR(base) ((base) + (0x0331UL))
#define COMMON_PMIC_NP_LDO3_CTRL0_ADDR(base) ((base) + (0x0332UL))
#define COMMON_PMIC_NP_LDO4_CTRL0_ADDR(base) ((base) + (0x0333UL))
#define COMMON_PMIC_NP_LDO5_CTRL0_ADDR(base) ((base) + (0x0334UL))
#define COMMON_PMIC_NP_LDO6_CTRL0_ADDR(base) ((base) + (0x0335UL))
#define COMMON_PMIC_NP_LDO7_CTRL0_ADDR(base) ((base) + (0x0336UL))
#define COMMON_PMIC_NP_LDO8_CTRL0_ADDR(base) ((base) + (0x0337UL))
#define COMMON_PMIC_NP_LDO9_CTRL0_ADDR(base) ((base) + (0x0338UL))
#define COMMON_PMIC_NP_LDO_RSV0_ADDR(base) ((base) + (0x0339UL))
#define COMMON_PMIC_NP_LDO_RSV1_ADDR(base) ((base) + (0x033AUL))
#define COMMON_PMIC_NP_D2A_RES0_ADDR(base) ((base) + (0x033BUL))
#define COMMON_PMIC_NP_D2A_RES1_ADDR(base) ((base) + (0x033CUL))
#define COMMON_PMIC_NP_D2A_RES2_ADDR(base) ((base) + (0x033DUL))
#define COMMON_PMIC_NP_D2A_RES3_ADDR(base) ((base) + (0x033EUL))
#define COMMON_PMIC_NP_D2A_RES4_ADDR(base) ((base) + (0x033FUL))
#define COMMON_PMIC_NP_DEBUG_LOCK_ADDR(base) ((base) + (0x0340UL))
#define COMMON_PMIC_NP_SYS_DEBUG0_ADDR(base) ((base) + (0x0341UL))
#define COMMON_PMIC_NP_SYS_DEBUG1_ADDR(base) ((base) + (0x0342UL))
#define COMMON_PMIC_NP_SYS_DEBUG2_ADDR(base) ((base) + (0x0343UL))
#define COMMON_PMIC_NP_HRST_REG0_ADDR(base) ((base) + (0x0346UL))
#define COMMON_PMIC_NP_HRST_REG1_ADDR(base) ((base) + (0x0347UL))
#define COMMON_PMIC_NP_HRST_REG2_ADDR(base) ((base) + (0x0348UL))
#define COMMON_PMIC_NP_HRST_REG3_ADDR(base) ((base) + (0x0349UL))
#else
#define COMMON_PMIC_PMU_SOFT_RST_ADDR(base) ((base) + (0x0300))
#define COMMON_PMIC_NP_PD_MASK_ADDR(base) ((base) + (0x0301))
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_ADDR(base) ((base) + (0x0302))
#define COMMON_PMIC_NP_RC256K_CTRL_ADDR(base) ((base) + (0x0303))
#define COMMON_PMIC_NP_DATA_IO_DS0_ADDR(base) ((base) + (0x0304))
#define COMMON_PMIC_NP_DATA_IO_DS1_ADDR(base) ((base) + (0x0305))
#define COMMON_PMIC_NP_EFUSE_READ_SEL_ADDR(base) ((base) + (0x0306))
#define COMMON_PMIC_NP_DTEST_SEL_ADDR(base) ((base) + (0x0310))
#define COMMON_PMIC_NP_SYS_CTRL0_ADDR(base) ((base) + (0x0315))
#define COMMON_PMIC_NP_PMUD_CTRL0_ADDR(base) ((base) + (0x0316))
#define COMMON_PMIC_NP_PMUD_VSET_ADDR(base) ((base) + (0x0317))
#define COMMON_PMIC_NP_REF_CTRL0_ADDR(base) ((base) + (0x0318))
#define COMMON_PMIC_NP_REF_RSV0_ADDR(base) ((base) + (0x0319))
#define COMMON_PMIC_NP_REF_RSV1_ADDR(base) ((base) + (0x031A))
#define COMMON_PMIC_NP_BUCK1_CTRL0_ADDR(base) ((base) + (0x0320))
#define COMMON_PMIC_NP_BUCK1_CTRL1_ADDR(base) ((base) + (0x0321))
#define COMMON_PMIC_NP_BUCK1_RES0_ADDR(base) ((base) + (0x0322))
#define COMMON_PMIC_NP_BUCK1_RES1_ADDR(base) ((base) + (0x0323))
#define COMMON_PMIC_NP_BUCK2_CTRL0_ADDR(base) ((base) + (0x0324))
#define COMMON_PMIC_NP_BUCK2_CTRL1_ADDR(base) ((base) + (0x0325))
#define COMMON_PMIC_NP_BUCK2_RES0_ADDR(base) ((base) + (0x0326))
#define COMMON_PMIC_NP_BUCK2_RES1_ADDR(base) ((base) + (0x0327))
#define COMMON_PMIC_NP_BUCK3_CTRL0_ADDR(base) ((base) + (0x0328))
#define COMMON_PMIC_NP_BUCK3_CTRL1_ADDR(base) ((base) + (0x0329))
#define COMMON_PMIC_NP_BUCK3_RES0_ADDR(base) ((base) + (0x032A))
#define COMMON_PMIC_NP_BUCK3_RES1_ADDR(base) ((base) + (0x032B))
#define COMMON_PMIC_NP_BUCK_RSV0_ADDR(base) ((base) + (0x032C))
#define COMMON_PMIC_NP_BUCK_RSV1_ADDR(base) ((base) + (0x032D))
#define COMMON_PMIC_NP_BUCK_RSV2_ADDR(base) ((base) + (0x032E))
#define COMMON_PMIC_NP_BUCK_RSV3_ADDR(base) ((base) + (0x032F))
#define COMMON_PMIC_NP_LDO1_CTRL0_ADDR(base) ((base) + (0x0330))
#define COMMON_PMIC_NP_LDO2_CTRL0_ADDR(base) ((base) + (0x0331))
#define COMMON_PMIC_NP_LDO3_CTRL0_ADDR(base) ((base) + (0x0332))
#define COMMON_PMIC_NP_LDO4_CTRL0_ADDR(base) ((base) + (0x0333))
#define COMMON_PMIC_NP_LDO5_CTRL0_ADDR(base) ((base) + (0x0334))
#define COMMON_PMIC_NP_LDO6_CTRL0_ADDR(base) ((base) + (0x0335))
#define COMMON_PMIC_NP_LDO7_CTRL0_ADDR(base) ((base) + (0x0336))
#define COMMON_PMIC_NP_LDO8_CTRL0_ADDR(base) ((base) + (0x0337))
#define COMMON_PMIC_NP_LDO9_CTRL0_ADDR(base) ((base) + (0x0338))
#define COMMON_PMIC_NP_LDO_RSV0_ADDR(base) ((base) + (0x0339))
#define COMMON_PMIC_NP_LDO_RSV1_ADDR(base) ((base) + (0x033A))
#define COMMON_PMIC_NP_D2A_RES0_ADDR(base) ((base) + (0x033B))
#define COMMON_PMIC_NP_D2A_RES1_ADDR(base) ((base) + (0x033C))
#define COMMON_PMIC_NP_D2A_RES2_ADDR(base) ((base) + (0x033D))
#define COMMON_PMIC_NP_D2A_RES3_ADDR(base) ((base) + (0x033E))
#define COMMON_PMIC_NP_D2A_RES4_ADDR(base) ((base) + (0x033F))
#define COMMON_PMIC_NP_DEBUG_LOCK_ADDR(base) ((base) + (0x0340))
#define COMMON_PMIC_NP_SYS_DEBUG0_ADDR(base) ((base) + (0x0341))
#define COMMON_PMIC_NP_SYS_DEBUG1_ADDR(base) ((base) + (0x0342))
#define COMMON_PMIC_NP_SYS_DEBUG2_ADDR(base) ((base) + (0x0343))
#define COMMON_PMIC_NP_HRST_REG0_ADDR(base) ((base) + (0x0346))
#define COMMON_PMIC_NP_HRST_REG1_ADDR(base) ((base) + (0x0347))
#define COMMON_PMIC_NP_HRST_REG2_ADDR(base) ((base) + (0x0348))
#define COMMON_PMIC_NP_HRST_REG3_ADDR(base) ((base) + (0x0349))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_REF_CFG0_ADDR(base) ((base) + (0x0400UL))
#define COMMON_PMIC_REF_CFG1_ADDR(base) ((base) + (0x0401UL))
#define COMMON_PMIC_REF_CFG2_ADDR(base) ((base) + (0x0402UL))
#define COMMON_PMIC_REF_CFG3_ADDR(base) ((base) + (0x0403UL))
#define COMMON_PMIC_REF_RSV0_ADDR(base) ((base) + (0x0404UL))
#define COMMON_PMIC_REF_RSV1_ADDR(base) ((base) + (0x0405UL))
#define COMMON_PMIC_OSC_9M6_CFG0_ADDR(base) ((base) + (0x0406UL))
#define COMMON_PMIC_SYS_CTRL_CFG0_ADDR(base) ((base) + (0x0407UL))
#define COMMON_PMIC_SYS_CTRL_CFG1_ADDR(base) ((base) + (0x0408UL))
#define COMMON_PMIC_BUCK1_CFG0_ADDR(base) ((base) + (0x0409UL))
#define COMMON_PMIC_BUCK1_CFG1_ADDR(base) ((base) + (0x040AUL))
#define COMMON_PMIC_BUCK1_CFG2_ADDR(base) ((base) + (0x040BUL))
#define COMMON_PMIC_BUCK1_CFG3_ADDR(base) ((base) + (0x040CUL))
#define COMMON_PMIC_BUCK1_CFG4_ADDR(base) ((base) + (0x040DUL))
#define COMMON_PMIC_BUCK1_CFG5_ADDR(base) ((base) + (0x040EUL))
#define COMMON_PMIC_BUCK1_CFG6_ADDR(base) ((base) + (0x040FUL))
#define COMMON_PMIC_BUCK1_CFG7_ADDR(base) ((base) + (0x0410UL))
#define COMMON_PMIC_BUCK1_CFG8_ADDR(base) ((base) + (0x0411UL))
#define COMMON_PMIC_BUCK1_CFG9_ADDR(base) ((base) + (0x0412UL))
#define COMMON_PMIC_BUCK1_CFG10_ADDR(base) ((base) + (0x0413UL))
#define COMMON_PMIC_BUCK1_CFG11_ADDR(base) ((base) + (0x0414UL))
#define COMMON_PMIC_BUCK1_CFG12_ADDR(base) ((base) + (0x0415UL))
#define COMMON_PMIC_BUCK1_CFG13_ADDR(base) ((base) + (0x0416UL))
#define COMMON_PMIC_BUCK1_CFG14_ADDR(base) ((base) + (0x0417UL))
#define COMMON_PMIC_BUCK1_CFG15_ADDR(base) ((base) + (0x0418UL))
#define COMMON_PMIC_BUCK1_CFG16_ADDR(base) ((base) + (0x0419UL))
#define COMMON_PMIC_BUCK1_CFG17_ADDR(base) ((base) + (0x041AUL))
#define COMMON_PMIC_BUCK1_CFG18_ADDR(base) ((base) + (0x041BUL))
#define COMMON_PMIC_BUCK1_CFG19_ADDR(base) ((base) + (0x041CUL))
#define COMMON_PMIC_BUCK1_CFG20_ADDR(base) ((base) + (0x041DUL))
#define COMMON_PMIC_BUCK1_CFG21_ADDR(base) ((base) + (0x041EUL))
#define COMMON_PMIC_BUCK1_CFG22_ADDR(base) ((base) + (0x041FUL))
#define COMMON_PMIC_BUCK1_CFG23_ADDR(base) ((base) + (0x0420UL))
#define COMMON_PMIC_BUCK1_CFG24_ADDR(base) ((base) + (0x0421UL))
#define COMMON_PMIC_BUCK1_CFG25_ADDR(base) ((base) + (0x0422UL))
#define COMMON_PMIC_BUCK1_CFG26_ADDR(base) ((base) + (0x0423UL))
#define COMMON_PMIC_BUCK1_CFG27_ADDR(base) ((base) + (0x0424UL))
#define COMMON_PMIC_BUCK1_CFG28_ADDR(base) ((base) + (0x0425UL))
#define COMMON_PMIC_BUCK1_CFG29_ADDR(base) ((base) + (0x0426UL))
#define COMMON_PMIC_BUCK1_CFG30_ADDR(base) ((base) + (0x0427UL))
#define COMMON_PMIC_BUCK1_CFG31_ADDR(base) ((base) + (0x0428UL))
#define COMMON_PMIC_BUCK1_CFG32_ADDR(base) ((base) + (0x0429UL))
#define COMMON_PMIC_BUCK1_CFG33_ADDR(base) ((base) + (0x042AUL))
#define COMMON_PMIC_BUCK1_CFG34_ADDR(base) ((base) + (0x042BUL))
#define COMMON_PMIC_BUCK1_CFG35_ADDR(base) ((base) + (0x042CUL))
#define COMMON_PMIC_BUCK1_CFG36_ADDR(base) ((base) + (0x042DUL))
#define COMMON_PMIC_BUCK1_RSV_CFG0_ADDR(base) ((base) + (0x042EUL))
#define COMMON_PMIC_BUCK1_RSV_CFG1_ADDR(base) ((base) + (0x042FUL))
#define COMMON_PMIC_BUCK1_A2D_RSV0_ADDR(base) ((base) + (0x0430UL))
#define COMMON_PMIC_BUCK1_A2D_RSV1_ADDR(base) ((base) + (0x0431UL))
#define COMMON_PMIC_BUCK2_CFG0_ADDR(base) ((base) + (0x0432UL))
#define COMMON_PMIC_BUCK2_CFG1_ADDR(base) ((base) + (0x0433UL))
#define COMMON_PMIC_BUCK2_CFG2_ADDR(base) ((base) + (0x0434UL))
#define COMMON_PMIC_BUCK2_CFG3_ADDR(base) ((base) + (0x0435UL))
#define COMMON_PMIC_BUCK2_CFG4_ADDR(base) ((base) + (0x0436UL))
#define COMMON_PMIC_BUCK2_CFG5_ADDR(base) ((base) + (0x0437UL))
#define COMMON_PMIC_BUCK2_CFG6_ADDR(base) ((base) + (0x0438UL))
#define COMMON_PMIC_BUCK2_CFG7_ADDR(base) ((base) + (0x0439UL))
#define COMMON_PMIC_BUCK2_CFG8_ADDR(base) ((base) + (0x043AUL))
#define COMMON_PMIC_BUCK2_CFG9_ADDR(base) ((base) + (0x043BUL))
#define COMMON_PMIC_BUCK2_CFG10_ADDR(base) ((base) + (0x043CUL))
#define COMMON_PMIC_BUCK2_CFG11_ADDR(base) ((base) + (0x043DUL))
#define COMMON_PMIC_BUCK2_CFG12_ADDR(base) ((base) + (0x043EUL))
#define COMMON_PMIC_BUCK2_CFG13_ADDR(base) ((base) + (0x043FUL))
#define COMMON_PMIC_BUCK2_CFG14_ADDR(base) ((base) + (0x0440UL))
#define COMMON_PMIC_BUCK2_CFG15_ADDR(base) ((base) + (0x0441UL))
#define COMMON_PMIC_BUCK2_CFG16_ADDR(base) ((base) + (0x0442UL))
#define COMMON_PMIC_BUCK2_CFG17_ADDR(base) ((base) + (0x0443UL))
#define COMMON_PMIC_BUCK2_CFG18_ADDR(base) ((base) + (0x0444UL))
#define COMMON_PMIC_BUCK2_CFG19_ADDR(base) ((base) + (0x0445UL))
#define COMMON_PMIC_BUCK2_CFG20_ADDR(base) ((base) + (0x0446UL))
#define COMMON_PMIC_BUCK2_CFG21_ADDR(base) ((base) + (0x0447UL))
#define COMMON_PMIC_BUCK2_CFG22_ADDR(base) ((base) + (0x0448UL))
#define COMMON_PMIC_BUCK2_CFG23_ADDR(base) ((base) + (0x0449UL))
#define COMMON_PMIC_BUCK2_CFG24_ADDR(base) ((base) + (0x044AUL))
#define COMMON_PMIC_BUCK2_CFG25_ADDR(base) ((base) + (0x044BUL))
#define COMMON_PMIC_BUCK2_CFG26_ADDR(base) ((base) + (0x044CUL))
#define COMMON_PMIC_BUCK2_CFG27_ADDR(base) ((base) + (0x044DUL))
#define COMMON_PMIC_BUCK2_CFG28_ADDR(base) ((base) + (0x044EUL))
#define COMMON_PMIC_BUCK2_CFG29_ADDR(base) ((base) + (0x044FUL))
#define COMMON_PMIC_BUCK2_CFG30_ADDR(base) ((base) + (0x0450UL))
#define COMMON_PMIC_BUCK2_CFG31_ADDR(base) ((base) + (0x0451UL))
#define COMMON_PMIC_BUCK2_RSV_CFG0_ADDR(base) ((base) + (0x0452UL))
#define COMMON_PMIC_BUCK2_RSV_CFG1_ADDR(base) ((base) + (0x0453UL))
#define COMMON_PMIC_BUCK2_A2D_RSV0_ADDR(base) ((base) + (0x0454UL))
#define COMMON_PMIC_BUCK2_A2D_RSV1_ADDR(base) ((base) + (0x0455UL))
#define COMMON_PMIC_BUCK3_CFG0_ADDR(base) ((base) + (0x0456UL))
#define COMMON_PMIC_BUCK3_CFG1_ADDR(base) ((base) + (0x0457UL))
#define COMMON_PMIC_BUCK3_CFG2_ADDR(base) ((base) + (0x0458UL))
#define COMMON_PMIC_BUCK3_CFG3_ADDR(base) ((base) + (0x0459UL))
#define COMMON_PMIC_BUCK3_CFG4_ADDR(base) ((base) + (0x045AUL))
#define COMMON_PMIC_BUCK3_CFG5_ADDR(base) ((base) + (0x045BUL))
#define COMMON_PMIC_BUCK3_CFG6_ADDR(base) ((base) + (0x045CUL))
#define COMMON_PMIC_BUCK3_CFG7_ADDR(base) ((base) + (0x045DUL))
#define COMMON_PMIC_BUCK3_CFG8_ADDR(base) ((base) + (0x045EUL))
#define COMMON_PMIC_BUCK3_CFG9_ADDR(base) ((base) + (0x045FUL))
#define COMMON_PMIC_BUCK3_CFG10_ADDR(base) ((base) + (0x0460UL))
#define COMMON_PMIC_BUCK3_CFG11_ADDR(base) ((base) + (0x0461UL))
#define COMMON_PMIC_BUCK3_CFG12_ADDR(base) ((base) + (0x0462UL))
#define COMMON_PMIC_BUCK3_CFG13_ADDR(base) ((base) + (0x0463UL))
#define COMMON_PMIC_BUCK3_CFG14_ADDR(base) ((base) + (0x0464UL))
#define COMMON_PMIC_BUCK3_CFG15_ADDR(base) ((base) + (0x0465UL))
#define COMMON_PMIC_BUCK3_CFG16_ADDR(base) ((base) + (0x0466UL))
#define COMMON_PMIC_BUCK3_CFG17_ADDR(base) ((base) + (0x0467UL))
#define COMMON_PMIC_BUCK3_CFG18_ADDR(base) ((base) + (0x0468UL))
#define COMMON_PMIC_BUCK3_CFG19_ADDR(base) ((base) + (0x0469UL))
#define COMMON_PMIC_BUCK3_CFG20_ADDR(base) ((base) + (0x046AUL))
#define COMMON_PMIC_BUCK3_CFG21_ADDR(base) ((base) + (0x046BUL))
#define COMMON_PMIC_BUCK3_CFG22_ADDR(base) ((base) + (0x046CUL))
#define COMMON_PMIC_BUCK3_CFG23_ADDR(base) ((base) + (0x046DUL))
#define COMMON_PMIC_BUCK3_CFG24_ADDR(base) ((base) + (0x046EUL))
#define COMMON_PMIC_BUCK3_CFG25_ADDR(base) ((base) + (0x046FUL))
#define COMMON_PMIC_BUCK3_CFG26_ADDR(base) ((base) + (0x0470UL))
#define COMMON_PMIC_BUCK3_CFG27_ADDR(base) ((base) + (0x0471UL))
#define COMMON_PMIC_BUCK3_CFG28_ADDR(base) ((base) + (0x0472UL))
#define COMMON_PMIC_BUCK3_CFG29_ADDR(base) ((base) + (0x0473UL))
#define COMMON_PMIC_BUCK3_CFG30_ADDR(base) ((base) + (0x0474UL))
#define COMMON_PMIC_BUCK3_CFG31_ADDR(base) ((base) + (0x0475UL))
#define COMMON_PMIC_BUCK3_RSV_CFG0_ADDR(base) ((base) + (0x0476UL))
#define COMMON_PMIC_BUCK3_RSV_CFG1_ADDR(base) ((base) + (0x0477UL))
#define COMMON_PMIC_BUCK3_A2D_RSV0_ADDR(base) ((base) + (0x0478UL))
#define COMMON_PMIC_BUCK3_A2D_RSV1_ADDR(base) ((base) + (0x0479UL))
#define COMMON_PMIC_BUCK_CFG0_ADDR(base) ((base) + (0x047AUL))
#define COMMON_PMIC_BUCK_CFG1_ADDR(base) ((base) + (0x047BUL))
#define COMMON_PMIC_BUCK_CFG2_ADDR(base) ((base) + (0x047CUL))
#define COMMON_PMIC_BUCK_CFG3_ADDR(base) ((base) + (0x047DUL))
#define COMMON_PMIC_BUCK_CFG4_ADDR(base) ((base) + (0x047EUL))
#define COMMON_PMIC_BUCK_RSV_CFG0_ADDR(base) ((base) + (0x047FUL))
#define COMMON_PMIC_BUCK_RSV_CFG1_ADDR(base) ((base) + (0x0480UL))
#define COMMON_PMIC_BUCK_RSV_CFG2_ADDR(base) ((base) + (0x0481UL))
#define COMMON_PMIC_BUCK_RSV_CFG3_ADDR(base) ((base) + (0x0482UL))
#define COMMON_PMIC_BUCK_A2D_RSV0_ADDR(base) ((base) + (0x0483UL))
#define COMMON_PMIC_BUCK_A2D_RSV1_ADDR(base) ((base) + (0x0484UL))
#define COMMON_PMIC_ATEST_RSV_CFG0_ADDR(base) ((base) + (0x0485UL))
#define COMMON_PMIC_ATEST_RSV_CFG1_ADDR(base) ((base) + (0x0486UL))
#define COMMON_PMIC_ATEST_RSV_CFG2_ADDR(base) ((base) + (0x0487UL))
#define COMMON_PMIC_ATEST_RSV_CFG3_ADDR(base) ((base) + (0x0488UL))
#define COMMON_PMIC_D2A_RSV_CFG0_ADDR(base) ((base) + (0x0489UL))
#define COMMON_PMIC_D2A_RSV_CFG1_ADDR(base) ((base) + (0x048AUL))
#define COMMON_PMIC_D2A_RSV_CFG2_ADDR(base) ((base) + (0x048BUL))
#define COMMON_PMIC_D2A_RSV_CFG3_ADDR(base) ((base) + (0x048CUL))
#define COMMON_PMIC_A2D_RSV_0_ADDR(base) ((base) + (0x048DUL))
#define COMMON_PMIC_A2D_RSV_1_ADDR(base) ((base) + (0x048EUL))
#define COMMON_PMIC_LDO1_CFG0_ADDR(base) ((base) + (0x048FUL))
#define COMMON_PMIC_LDO1_CFG1_ADDR(base) ((base) + (0x0490UL))
#define COMMON_PMIC_LDO1_CFG2_ADDR(base) ((base) + (0x0491UL))
#define COMMON_PMIC_LDO2_CFG0_ADDR(base) ((base) + (0x0492UL))
#define COMMON_PMIC_LDO2_CFG1_ADDR(base) ((base) + (0x0493UL))
#define COMMON_PMIC_LDO2_CFG2_ADDR(base) ((base) + (0x0494UL))
#define COMMON_PMIC_LDO3_CFG0_ADDR(base) ((base) + (0x0495UL))
#define COMMON_PMIC_LDO3_CFG1_ADDR(base) ((base) + (0x0496UL))
#define COMMON_PMIC_LDO3_CFG2_ADDR(base) ((base) + (0x0497UL))
#define COMMON_PMIC_LDO4_CFG0_ADDR(base) ((base) + (0x0498UL))
#define COMMON_PMIC_LDO4_CFG1_ADDR(base) ((base) + (0x0499UL))
#define COMMON_PMIC_LDO4_CFG2_ADDR(base) ((base) + (0x049AUL))
#define COMMON_PMIC_LDO5_CFG0_ADDR(base) ((base) + (0x049BUL))
#define COMMON_PMIC_LDO5_CFG1_ADDR(base) ((base) + (0x049CUL))
#define COMMON_PMIC_LDO5_CFG2_ADDR(base) ((base) + (0x049DUL))
#define COMMON_PMIC_LDO6_CFG0_ADDR(base) ((base) + (0x049EUL))
#define COMMON_PMIC_LDO6_CFG1_ADDR(base) ((base) + (0x049FUL))
#define COMMON_PMIC_LDO6_CFG2_ADDR(base) ((base) + (0x04A0UL))
#define COMMON_PMIC_LDO7_CFG0_ADDR(base) ((base) + (0x04A1UL))
#define COMMON_PMIC_LDO7_CFG1_ADDR(base) ((base) + (0x04A2UL))
#define COMMON_PMIC_LDO8_CFG0_ADDR(base) ((base) + (0x04A3UL))
#define COMMON_PMIC_LDO8_CFG1_ADDR(base) ((base) + (0x04A4UL))
#define COMMON_PMIC_LDO8_CFG2_ADDR(base) ((base) + (0x04A5UL))
#define COMMON_PMIC_LDO9_CFG0_ADDR(base) ((base) + (0x04A6UL))
#define COMMON_PMIC_LDO9_CFG1_ADDR(base) ((base) + (0x04A7UL))
#define COMMON_PMIC_LDO9_CFG2_ADDR(base) ((base) + (0x04A8UL))
#define COMMON_PMIC_LDO_PMUH_CFG0_ADDR(base) ((base) + (0x04A9UL))
#define COMMON_PMIC_LDO_PMUH_CFG1_ADDR(base) ((base) + (0x04AAUL))
#define COMMON_PMIC_LDO_RES_CFG0_ADDR(base) ((base) + (0x04ABUL))
#define COMMON_PMIC_LDO_RES_CFG1_ADDR(base) ((base) + (0x04ACUL))
#define COMMON_PMIC_LDO_RES_CFG2_ADDR(base) ((base) + (0x04ADUL))
#define COMMON_PMIC_LDO_RES_CFG3_ADDR(base) ((base) + (0x04AEUL))
#define COMMON_PMIC_LDO_RES_CFG4_ADDR(base) ((base) + (0x04AFUL))
#define COMMON_PMIC_LDO_RES_CFG5_ADDR(base) ((base) + (0x04B0UL))
#define COMMON_PMIC_LDO_RES_CFG6_ADDR(base) ((base) + (0x04B1UL))
#define COMMON_PMIC_LDO_RES_CFG7_ADDR(base) ((base) + (0x04B2UL))
#else
#define COMMON_PMIC_REF_CFG0_ADDR(base) ((base) + (0x0400))
#define COMMON_PMIC_REF_CFG1_ADDR(base) ((base) + (0x0401))
#define COMMON_PMIC_REF_CFG2_ADDR(base) ((base) + (0x0402))
#define COMMON_PMIC_REF_CFG3_ADDR(base) ((base) + (0x0403))
#define COMMON_PMIC_REF_RSV0_ADDR(base) ((base) + (0x0404))
#define COMMON_PMIC_REF_RSV1_ADDR(base) ((base) + (0x0405))
#define COMMON_PMIC_OSC_9M6_CFG0_ADDR(base) ((base) + (0x0406))
#define COMMON_PMIC_SYS_CTRL_CFG0_ADDR(base) ((base) + (0x0407))
#define COMMON_PMIC_SYS_CTRL_CFG1_ADDR(base) ((base) + (0x0408))
#define COMMON_PMIC_BUCK1_CFG0_ADDR(base) ((base) + (0x0409))
#define COMMON_PMIC_BUCK1_CFG1_ADDR(base) ((base) + (0x040A))
#define COMMON_PMIC_BUCK1_CFG2_ADDR(base) ((base) + (0x040B))
#define COMMON_PMIC_BUCK1_CFG3_ADDR(base) ((base) + (0x040C))
#define COMMON_PMIC_BUCK1_CFG4_ADDR(base) ((base) + (0x040D))
#define COMMON_PMIC_BUCK1_CFG5_ADDR(base) ((base) + (0x040E))
#define COMMON_PMIC_BUCK1_CFG6_ADDR(base) ((base) + (0x040F))
#define COMMON_PMIC_BUCK1_CFG7_ADDR(base) ((base) + (0x0410))
#define COMMON_PMIC_BUCK1_CFG8_ADDR(base) ((base) + (0x0411))
#define COMMON_PMIC_BUCK1_CFG9_ADDR(base) ((base) + (0x0412))
#define COMMON_PMIC_BUCK1_CFG10_ADDR(base) ((base) + (0x0413))
#define COMMON_PMIC_BUCK1_CFG11_ADDR(base) ((base) + (0x0414))
#define COMMON_PMIC_BUCK1_CFG12_ADDR(base) ((base) + (0x0415))
#define COMMON_PMIC_BUCK1_CFG13_ADDR(base) ((base) + (0x0416))
#define COMMON_PMIC_BUCK1_CFG14_ADDR(base) ((base) + (0x0417))
#define COMMON_PMIC_BUCK1_CFG15_ADDR(base) ((base) + (0x0418))
#define COMMON_PMIC_BUCK1_CFG16_ADDR(base) ((base) + (0x0419))
#define COMMON_PMIC_BUCK1_CFG17_ADDR(base) ((base) + (0x041A))
#define COMMON_PMIC_BUCK1_CFG18_ADDR(base) ((base) + (0x041B))
#define COMMON_PMIC_BUCK1_CFG19_ADDR(base) ((base) + (0x041C))
#define COMMON_PMIC_BUCK1_CFG20_ADDR(base) ((base) + (0x041D))
#define COMMON_PMIC_BUCK1_CFG21_ADDR(base) ((base) + (0x041E))
#define COMMON_PMIC_BUCK1_CFG22_ADDR(base) ((base) + (0x041F))
#define COMMON_PMIC_BUCK1_CFG23_ADDR(base) ((base) + (0x0420))
#define COMMON_PMIC_BUCK1_CFG24_ADDR(base) ((base) + (0x0421))
#define COMMON_PMIC_BUCK1_CFG25_ADDR(base) ((base) + (0x0422))
#define COMMON_PMIC_BUCK1_CFG26_ADDR(base) ((base) + (0x0423))
#define COMMON_PMIC_BUCK1_CFG27_ADDR(base) ((base) + (0x0424))
#define COMMON_PMIC_BUCK1_CFG28_ADDR(base) ((base) + (0x0425))
#define COMMON_PMIC_BUCK1_CFG29_ADDR(base) ((base) + (0x0426))
#define COMMON_PMIC_BUCK1_CFG30_ADDR(base) ((base) + (0x0427))
#define COMMON_PMIC_BUCK1_CFG31_ADDR(base) ((base) + (0x0428))
#define COMMON_PMIC_BUCK1_CFG32_ADDR(base) ((base) + (0x0429))
#define COMMON_PMIC_BUCK1_CFG33_ADDR(base) ((base) + (0x042A))
#define COMMON_PMIC_BUCK1_CFG34_ADDR(base) ((base) + (0x042B))
#define COMMON_PMIC_BUCK1_CFG35_ADDR(base) ((base) + (0x042C))
#define COMMON_PMIC_BUCK1_CFG36_ADDR(base) ((base) + (0x042D))
#define COMMON_PMIC_BUCK1_RSV_CFG0_ADDR(base) ((base) + (0x042E))
#define COMMON_PMIC_BUCK1_RSV_CFG1_ADDR(base) ((base) + (0x042F))
#define COMMON_PMIC_BUCK1_A2D_RSV0_ADDR(base) ((base) + (0x0430))
#define COMMON_PMIC_BUCK1_A2D_RSV1_ADDR(base) ((base) + (0x0431))
#define COMMON_PMIC_BUCK2_CFG0_ADDR(base) ((base) + (0x0432))
#define COMMON_PMIC_BUCK2_CFG1_ADDR(base) ((base) + (0x0433))
#define COMMON_PMIC_BUCK2_CFG2_ADDR(base) ((base) + (0x0434))
#define COMMON_PMIC_BUCK2_CFG3_ADDR(base) ((base) + (0x0435))
#define COMMON_PMIC_BUCK2_CFG4_ADDR(base) ((base) + (0x0436))
#define COMMON_PMIC_BUCK2_CFG5_ADDR(base) ((base) + (0x0437))
#define COMMON_PMIC_BUCK2_CFG6_ADDR(base) ((base) + (0x0438))
#define COMMON_PMIC_BUCK2_CFG7_ADDR(base) ((base) + (0x0439))
#define COMMON_PMIC_BUCK2_CFG8_ADDR(base) ((base) + (0x043A))
#define COMMON_PMIC_BUCK2_CFG9_ADDR(base) ((base) + (0x043B))
#define COMMON_PMIC_BUCK2_CFG10_ADDR(base) ((base) + (0x043C))
#define COMMON_PMIC_BUCK2_CFG11_ADDR(base) ((base) + (0x043D))
#define COMMON_PMIC_BUCK2_CFG12_ADDR(base) ((base) + (0x043E))
#define COMMON_PMIC_BUCK2_CFG13_ADDR(base) ((base) + (0x043F))
#define COMMON_PMIC_BUCK2_CFG14_ADDR(base) ((base) + (0x0440))
#define COMMON_PMIC_BUCK2_CFG15_ADDR(base) ((base) + (0x0441))
#define COMMON_PMIC_BUCK2_CFG16_ADDR(base) ((base) + (0x0442))
#define COMMON_PMIC_BUCK2_CFG17_ADDR(base) ((base) + (0x0443))
#define COMMON_PMIC_BUCK2_CFG18_ADDR(base) ((base) + (0x0444))
#define COMMON_PMIC_BUCK2_CFG19_ADDR(base) ((base) + (0x0445))
#define COMMON_PMIC_BUCK2_CFG20_ADDR(base) ((base) + (0x0446))
#define COMMON_PMIC_BUCK2_CFG21_ADDR(base) ((base) + (0x0447))
#define COMMON_PMIC_BUCK2_CFG22_ADDR(base) ((base) + (0x0448))
#define COMMON_PMIC_BUCK2_CFG23_ADDR(base) ((base) + (0x0449))
#define COMMON_PMIC_BUCK2_CFG24_ADDR(base) ((base) + (0x044A))
#define COMMON_PMIC_BUCK2_CFG25_ADDR(base) ((base) + (0x044B))
#define COMMON_PMIC_BUCK2_CFG26_ADDR(base) ((base) + (0x044C))
#define COMMON_PMIC_BUCK2_CFG27_ADDR(base) ((base) + (0x044D))
#define COMMON_PMIC_BUCK2_CFG28_ADDR(base) ((base) + (0x044E))
#define COMMON_PMIC_BUCK2_CFG29_ADDR(base) ((base) + (0x044F))
#define COMMON_PMIC_BUCK2_CFG30_ADDR(base) ((base) + (0x0450))
#define COMMON_PMIC_BUCK2_CFG31_ADDR(base) ((base) + (0x0451))
#define COMMON_PMIC_BUCK2_RSV_CFG0_ADDR(base) ((base) + (0x0452))
#define COMMON_PMIC_BUCK2_RSV_CFG1_ADDR(base) ((base) + (0x0453))
#define COMMON_PMIC_BUCK2_A2D_RSV0_ADDR(base) ((base) + (0x0454))
#define COMMON_PMIC_BUCK2_A2D_RSV1_ADDR(base) ((base) + (0x0455))
#define COMMON_PMIC_BUCK3_CFG0_ADDR(base) ((base) + (0x0456))
#define COMMON_PMIC_BUCK3_CFG1_ADDR(base) ((base) + (0x0457))
#define COMMON_PMIC_BUCK3_CFG2_ADDR(base) ((base) + (0x0458))
#define COMMON_PMIC_BUCK3_CFG3_ADDR(base) ((base) + (0x0459))
#define COMMON_PMIC_BUCK3_CFG4_ADDR(base) ((base) + (0x045A))
#define COMMON_PMIC_BUCK3_CFG5_ADDR(base) ((base) + (0x045B))
#define COMMON_PMIC_BUCK3_CFG6_ADDR(base) ((base) + (0x045C))
#define COMMON_PMIC_BUCK3_CFG7_ADDR(base) ((base) + (0x045D))
#define COMMON_PMIC_BUCK3_CFG8_ADDR(base) ((base) + (0x045E))
#define COMMON_PMIC_BUCK3_CFG9_ADDR(base) ((base) + (0x045F))
#define COMMON_PMIC_BUCK3_CFG10_ADDR(base) ((base) + (0x0460))
#define COMMON_PMIC_BUCK3_CFG11_ADDR(base) ((base) + (0x0461))
#define COMMON_PMIC_BUCK3_CFG12_ADDR(base) ((base) + (0x0462))
#define COMMON_PMIC_BUCK3_CFG13_ADDR(base) ((base) + (0x0463))
#define COMMON_PMIC_BUCK3_CFG14_ADDR(base) ((base) + (0x0464))
#define COMMON_PMIC_BUCK3_CFG15_ADDR(base) ((base) + (0x0465))
#define COMMON_PMIC_BUCK3_CFG16_ADDR(base) ((base) + (0x0466))
#define COMMON_PMIC_BUCK3_CFG17_ADDR(base) ((base) + (0x0467))
#define COMMON_PMIC_BUCK3_CFG18_ADDR(base) ((base) + (0x0468))
#define COMMON_PMIC_BUCK3_CFG19_ADDR(base) ((base) + (0x0469))
#define COMMON_PMIC_BUCK3_CFG20_ADDR(base) ((base) + (0x046A))
#define COMMON_PMIC_BUCK3_CFG21_ADDR(base) ((base) + (0x046B))
#define COMMON_PMIC_BUCK3_CFG22_ADDR(base) ((base) + (0x046C))
#define COMMON_PMIC_BUCK3_CFG23_ADDR(base) ((base) + (0x046D))
#define COMMON_PMIC_BUCK3_CFG24_ADDR(base) ((base) + (0x046E))
#define COMMON_PMIC_BUCK3_CFG25_ADDR(base) ((base) + (0x046F))
#define COMMON_PMIC_BUCK3_CFG26_ADDR(base) ((base) + (0x0470))
#define COMMON_PMIC_BUCK3_CFG27_ADDR(base) ((base) + (0x0471))
#define COMMON_PMIC_BUCK3_CFG28_ADDR(base) ((base) + (0x0472))
#define COMMON_PMIC_BUCK3_CFG29_ADDR(base) ((base) + (0x0473))
#define COMMON_PMIC_BUCK3_CFG30_ADDR(base) ((base) + (0x0474))
#define COMMON_PMIC_BUCK3_CFG31_ADDR(base) ((base) + (0x0475))
#define COMMON_PMIC_BUCK3_RSV_CFG0_ADDR(base) ((base) + (0x0476))
#define COMMON_PMIC_BUCK3_RSV_CFG1_ADDR(base) ((base) + (0x0477))
#define COMMON_PMIC_BUCK3_A2D_RSV0_ADDR(base) ((base) + (0x0478))
#define COMMON_PMIC_BUCK3_A2D_RSV1_ADDR(base) ((base) + (0x0479))
#define COMMON_PMIC_BUCK_CFG0_ADDR(base) ((base) + (0x047A))
#define COMMON_PMIC_BUCK_CFG1_ADDR(base) ((base) + (0x047B))
#define COMMON_PMIC_BUCK_CFG2_ADDR(base) ((base) + (0x047C))
#define COMMON_PMIC_BUCK_CFG3_ADDR(base) ((base) + (0x047D))
#define COMMON_PMIC_BUCK_CFG4_ADDR(base) ((base) + (0x047E))
#define COMMON_PMIC_BUCK_RSV_CFG0_ADDR(base) ((base) + (0x047F))
#define COMMON_PMIC_BUCK_RSV_CFG1_ADDR(base) ((base) + (0x0480))
#define COMMON_PMIC_BUCK_RSV_CFG2_ADDR(base) ((base) + (0x0481))
#define COMMON_PMIC_BUCK_RSV_CFG3_ADDR(base) ((base) + (0x0482))
#define COMMON_PMIC_BUCK_A2D_RSV0_ADDR(base) ((base) + (0x0483))
#define COMMON_PMIC_BUCK_A2D_RSV1_ADDR(base) ((base) + (0x0484))
#define COMMON_PMIC_ATEST_RSV_CFG0_ADDR(base) ((base) + (0x0485))
#define COMMON_PMIC_ATEST_RSV_CFG1_ADDR(base) ((base) + (0x0486))
#define COMMON_PMIC_ATEST_RSV_CFG2_ADDR(base) ((base) + (0x0487))
#define COMMON_PMIC_ATEST_RSV_CFG3_ADDR(base) ((base) + (0x0488))
#define COMMON_PMIC_D2A_RSV_CFG0_ADDR(base) ((base) + (0x0489))
#define COMMON_PMIC_D2A_RSV_CFG1_ADDR(base) ((base) + (0x048A))
#define COMMON_PMIC_D2A_RSV_CFG2_ADDR(base) ((base) + (0x048B))
#define COMMON_PMIC_D2A_RSV_CFG3_ADDR(base) ((base) + (0x048C))
#define COMMON_PMIC_A2D_RSV_0_ADDR(base) ((base) + (0x048D))
#define COMMON_PMIC_A2D_RSV_1_ADDR(base) ((base) + (0x048E))
#define COMMON_PMIC_LDO1_CFG0_ADDR(base) ((base) + (0x048F))
#define COMMON_PMIC_LDO1_CFG1_ADDR(base) ((base) + (0x0490))
#define COMMON_PMIC_LDO1_CFG2_ADDR(base) ((base) + (0x0491))
#define COMMON_PMIC_LDO2_CFG0_ADDR(base) ((base) + (0x0492))
#define COMMON_PMIC_LDO2_CFG1_ADDR(base) ((base) + (0x0493))
#define COMMON_PMIC_LDO2_CFG2_ADDR(base) ((base) + (0x0494))
#define COMMON_PMIC_LDO3_CFG0_ADDR(base) ((base) + (0x0495))
#define COMMON_PMIC_LDO3_CFG1_ADDR(base) ((base) + (0x0496))
#define COMMON_PMIC_LDO3_CFG2_ADDR(base) ((base) + (0x0497))
#define COMMON_PMIC_LDO4_CFG0_ADDR(base) ((base) + (0x0498))
#define COMMON_PMIC_LDO4_CFG1_ADDR(base) ((base) + (0x0499))
#define COMMON_PMIC_LDO4_CFG2_ADDR(base) ((base) + (0x049A))
#define COMMON_PMIC_LDO5_CFG0_ADDR(base) ((base) + (0x049B))
#define COMMON_PMIC_LDO5_CFG1_ADDR(base) ((base) + (0x049C))
#define COMMON_PMIC_LDO5_CFG2_ADDR(base) ((base) + (0x049D))
#define COMMON_PMIC_LDO6_CFG0_ADDR(base) ((base) + (0x049E))
#define COMMON_PMIC_LDO6_CFG1_ADDR(base) ((base) + (0x049F))
#define COMMON_PMIC_LDO6_CFG2_ADDR(base) ((base) + (0x04A0))
#define COMMON_PMIC_LDO7_CFG0_ADDR(base) ((base) + (0x04A1))
#define COMMON_PMIC_LDO7_CFG1_ADDR(base) ((base) + (0x04A2))
#define COMMON_PMIC_LDO8_CFG0_ADDR(base) ((base) + (0x04A3))
#define COMMON_PMIC_LDO8_CFG1_ADDR(base) ((base) + (0x04A4))
#define COMMON_PMIC_LDO8_CFG2_ADDR(base) ((base) + (0x04A5))
#define COMMON_PMIC_LDO9_CFG0_ADDR(base) ((base) + (0x04A6))
#define COMMON_PMIC_LDO9_CFG1_ADDR(base) ((base) + (0x04A7))
#define COMMON_PMIC_LDO9_CFG2_ADDR(base) ((base) + (0x04A8))
#define COMMON_PMIC_LDO_PMUH_CFG0_ADDR(base) ((base) + (0x04A9))
#define COMMON_PMIC_LDO_PMUH_CFG1_ADDR(base) ((base) + (0x04AA))
#define COMMON_PMIC_LDO_RES_CFG0_ADDR(base) ((base) + (0x04AB))
#define COMMON_PMIC_LDO_RES_CFG1_ADDR(base) ((base) + (0x04AC))
#define COMMON_PMIC_LDO_RES_CFG2_ADDR(base) ((base) + (0x04AD))
#define COMMON_PMIC_LDO_RES_CFG3_ADDR(base) ((base) + (0x04AE))
#define COMMON_PMIC_LDO_RES_CFG4_ADDR(base) ((base) + (0x04AF))
#define COMMON_PMIC_LDO_RES_CFG5_ADDR(base) ((base) + (0x04B0))
#define COMMON_PMIC_LDO_RES_CFG6_ADDR(base) ((base) + (0x04B1))
#define COMMON_PMIC_LDO_RES_CFG7_ADDR(base) ((base) + (0x04B2))
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_FER_BASE (0x0500)
#define COMMON_PMIC_FER_CTRL_ADDR(base) ((base) + COMMON_FER_BASE + (0x0000UL))
#define COMMON_PMIC_FER_EVENT_LEVEL_ADDR(base) ((base) + COMMON_FER_BASE + (0x0001UL))
#define COMMON_PMIC_FER_BUCK_PG_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0002UL))
#define COMMON_PMIC_FER_BUCK_VOK_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0003UL))
#define COMMON_PMIC_FER_BUCK_OC_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0004UL))
#define COMMON_PMIC_FER_BUCK_OT_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0005UL))
#define COMMON_PMIC_FER_PMU_PSOK_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0006UL))
#define COMMON_PMIC_FER_PMU_IRQ_MSK0_ADDR(base) ((base) + COMMON_FER_BASE + (0x0007UL))
#define COMMON_PMIC_FER_PMU_IRQ_MSK1_ADDR(base) ((base) + COMMON_FER_BASE + (0x0008UL))
#define COMMON_PMIC_FER_BUF_BUCK_PGVOK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0009UL))
#define COMMON_PMIC_FER_BUF_BUCK_OCOT_ADDR(base) ((base) + COMMON_FER_BASE + (0x000AUL))
#define COMMON_PMIC_FER_BUF_PMU_PSOK_ADDR(base) ((base) + COMMON_FER_BASE + (0x000BUL))
#define COMMON_PMIC_FER_BUF_PMU_IRQ0_ADDR(base) ((base) + COMMON_FER_BASE + (0x000CUL))
#define COMMON_PMIC_FER_BUF_PMU_IRQ1_ADDR(base) ((base) + COMMON_FER_BASE + (0x000DUL))
#define COMMON_PMIC_FER_TRANS_ABIT_DATA_ADDR(base) ((base) + COMMON_FER_BASE + (0x000EUL))
#define COMMON_PMIC_FER_TRANS_ABIT_ADDR_ADDR(base) ((base) + COMMON_FER_BASE + (0x000FUL))
#define COMMON_PMIC_FER_TRANS_SRBIT_DATA_ADDR(base) ((base) + COMMON_FER_BASE + (0x0010UL))
#define COMMON_PMIC_FER_TRANS_SRBIT_ADDR_ADDR(base) ((base) + COMMON_FER_BASE + (0x0011UL))
#define COMMON_PMIC_SPMI_DEBUG0_ADDR(base) ((base) + COMMON_FER_BASE + (0x0040UL))
#define COMMON_PMIC_SPMI_DEBUG1_ADDR(base) ((base) + COMMON_FER_BASE + (0x0041UL))
#define COMMON_PMIC_SPMI_DEBUG2_ADDR(base) ((base) + COMMON_FER_BASE + (0x0042UL))
#define COMMON_PMIC_SPMI_DEBUG3_ADDR(base) ((base) + COMMON_FER_BASE + (0x0043UL))
#define COMMON_PMIC_SPMI_DEBUG4_ADDR(base) ((base) + COMMON_FER_BASE + (0x0044UL))
#define COMMON_PMIC_SPMI_DEBUG5_ADDR(base) ((base) + COMMON_FER_BASE + (0x0045UL))
#define COMMON_PMIC_SPMI_DEBUG6_ADDR(base) ((base) + COMMON_FER_BASE + (0x0046UL))
#define COMMON_PMIC_SPMI_DEBUG7_ADDR(base) ((base) + COMMON_FER_BASE + (0x0047UL))
#else
#define COMMON_PMIC_FER_CTRL_ADDR(base) ((base) + COMMON_FER_BASE + (0x0000))
#define COMMON_PMIC_FER_EVENT_LEVEL_ADDR(base) ((base) + COMMON_FER_BASE + (0x0001))
#define COMMON_PMIC_FER_BUCK_PG_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0002))
#define COMMON_PMIC_FER_BUCK_VOK_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0003))
#define COMMON_PMIC_FER_BUCK_OC_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0004))
#define COMMON_PMIC_FER_BUCK_OT_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0005))
#define COMMON_PMIC_FER_PMU_PSOK_MSK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0006))
#define COMMON_PMIC_FER_PMU_IRQ_MSK0_ADDR(base) ((base) + COMMON_FER_BASE + (0x0007))
#define COMMON_PMIC_FER_PMU_IRQ_MSK1_ADDR(base) ((base) + COMMON_FER_BASE + (0x0008))
#define COMMON_PMIC_FER_BUF_BUCK_PGVOK_ADDR(base) ((base) + COMMON_FER_BASE + (0x0009))
#define COMMON_PMIC_FER_BUF_BUCK_OCOT_ADDR(base) ((base) + COMMON_FER_BASE + (0x000A))
#define COMMON_PMIC_FER_BUF_PMU_PSOK_ADDR(base) ((base) + COMMON_FER_BASE + (0x000B))
#define COMMON_PMIC_FER_BUF_PMU_IRQ0_ADDR(base) ((base) + COMMON_FER_BASE + (0x000C))
#define COMMON_PMIC_FER_BUF_PMU_IRQ1_ADDR(base) ((base) + COMMON_FER_BASE + (0x000D))
#define COMMON_PMIC_FER_TRANS_ABIT_DATA_ADDR(base) ((base) + COMMON_FER_BASE + (0x000E))
#define COMMON_PMIC_FER_TRANS_ABIT_ADDR_ADDR(base) ((base) + COMMON_FER_BASE + (0x000F))
#define COMMON_PMIC_FER_TRANS_SRBIT_DATA_ADDR(base) ((base) + COMMON_FER_BASE + (0x0010))
#define COMMON_PMIC_FER_TRANS_SRBIT_ADDR_ADDR(base) ((base) + COMMON_FER_BASE + (0x0011))
#define COMMON_PMIC_SPMI_DEBUG0_ADDR(base) ((base) + COMMON_FER_BASE + (0x0040))
#define COMMON_PMIC_SPMI_DEBUG1_ADDR(base) ((base) + COMMON_FER_BASE + (0x0041))
#define COMMON_PMIC_SPMI_DEBUG2_ADDR(base) ((base) + COMMON_FER_BASE + (0x0042))
#define COMMON_PMIC_SPMI_DEBUG3_ADDR(base) ((base) + COMMON_FER_BASE + (0x0043))
#define COMMON_PMIC_SPMI_DEBUG4_ADDR(base) ((base) + COMMON_FER_BASE + (0x0044))
#define COMMON_PMIC_SPMI_DEBUG5_ADDR(base) ((base) + COMMON_FER_BASE + (0x0045))
#define COMMON_PMIC_SPMI_DEBUG6_ADDR(base) ((base) + COMMON_FER_BASE + (0x0046))
#define COMMON_PMIC_SPMI_DEBUG7_ADDR(base) ((base) + COMMON_FER_BASE + (0x0047))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num0 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_0_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_0_project_num0_START (0)
#define COMMON_PMIC_CHIP_VERSION_0_project_num0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num1 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_1_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_1_project_num1_START (0)
#define COMMON_PMIC_CHIP_VERSION_1_project_num1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num2 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_2_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_2_project_num2_START (0)
#define COMMON_PMIC_CHIP_VERSION_2_project_num2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char project_num3 : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_3_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_3_project_num3_START (0)
#define COMMON_PMIC_CHIP_VERSION_3_project_num3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char version : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_4_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_4_version_START (0)
#define COMMON_PMIC_CHIP_VERSION_4_version_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char chip_id : 8;
    } reg;
} COMMON_PMIC_CHIP_VERSION_5_UNION;
#endif
#define COMMON_PMIC_CHIP_VERSION_5_chip_id_START (0)
#define COMMON_PMIC_CHIP_VERSION_5_chip_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char lock : 8;
    } reg;
} COMMON_PMIC_LOCK_UNION;
#endif
#define COMMON_PMIC_LOCK_lock_START (0)
#define COMMON_PMIC_LOCK_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_thsd_otmp140_deb : 1;
        unsigned char st_thsd_otmp125_deb : 1;
        unsigned char st_vsys_pwroff_abs_d20nr : 1;
        unsigned char st_vsys_ov_deb : 1;
        unsigned char st_vin_ldo_1p95_vld_deb : 1;
        unsigned char st_pvdd3_sys3_vld_deb : 1;
        unsigned char st_pvdd3_sys3_ov_deb : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_SYS_STATUS_UNION;
#endif
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp140_deb_START (0)
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp140_deb_END (0)
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp125_deb_START (1)
#define COMMON_PMIC_SYS_STATUS_st_thsd_otmp125_deb_END (1)
#define COMMON_PMIC_SYS_STATUS_st_vsys_pwroff_abs_d20nr_START (2)
#define COMMON_PMIC_SYS_STATUS_st_vsys_pwroff_abs_d20nr_END (2)
#define COMMON_PMIC_SYS_STATUS_st_vsys_ov_deb_START (3)
#define COMMON_PMIC_SYS_STATUS_st_vsys_ov_deb_END (3)
#define COMMON_PMIC_SYS_STATUS_st_vin_ldo_1p95_vld_deb_START (4)
#define COMMON_PMIC_SYS_STATUS_st_vin_ldo_1p95_vld_deb_END (4)
#define COMMON_PMIC_SYS_STATUS_st_pvdd3_sys3_vld_deb_START (5)
#define COMMON_PMIC_SYS_STATUS_st_pvdd3_sys3_vld_deb_END (5)
#define COMMON_PMIC_SYS_STATUS_st_pvdd3_sys3_ov_deb_START (6)
#define COMMON_PMIC_SYS_STATUS_st_pvdd3_sys3_ov_deb_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b1_ocp : 1;
        unsigned char st_b2_ocp : 1;
        unsigned char st_b3_ocp : 1;
        unsigned char st_pmuh_ocp : 1;
        unsigned char st_ldo9_ocp : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_OCP_STATUS0_UNION;
#endif
#define COMMON_PMIC_OCP_STATUS0_st_b1_ocp_START (0)
#define COMMON_PMIC_OCP_STATUS0_st_b1_ocp_END (0)
#define COMMON_PMIC_OCP_STATUS0_st_b2_ocp_START (1)
#define COMMON_PMIC_OCP_STATUS0_st_b2_ocp_END (1)
#define COMMON_PMIC_OCP_STATUS0_st_b3_ocp_START (2)
#define COMMON_PMIC_OCP_STATUS0_st_b3_ocp_END (2)
#define COMMON_PMIC_OCP_STATUS0_st_pmuh_ocp_START (3)
#define COMMON_PMIC_OCP_STATUS0_st_pmuh_ocp_END (3)
#define COMMON_PMIC_OCP_STATUS0_st_ldo9_ocp_START (4)
#define COMMON_PMIC_OCP_STATUS0_st_ldo9_ocp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_ldo1_ocp : 1;
        unsigned char st_ldo2_ocp : 1;
        unsigned char st_ldo3_ocp : 1;
        unsigned char st_ldo4_ocp : 1;
        unsigned char st_ldo5_ocp : 1;
        unsigned char st_ldo6_ocp : 1;
        unsigned char st_ldo7_ocp : 1;
        unsigned char st_ldo8_ocp : 1;
    } reg;
} COMMON_PMIC_OCP_STATUS1_UNION;
#endif
#define COMMON_PMIC_OCP_STATUS1_st_ldo1_ocp_START (0)
#define COMMON_PMIC_OCP_STATUS1_st_ldo1_ocp_END (0)
#define COMMON_PMIC_OCP_STATUS1_st_ldo2_ocp_START (1)
#define COMMON_PMIC_OCP_STATUS1_st_ldo2_ocp_END (1)
#define COMMON_PMIC_OCP_STATUS1_st_ldo3_ocp_START (2)
#define COMMON_PMIC_OCP_STATUS1_st_ldo3_ocp_END (2)
#define COMMON_PMIC_OCP_STATUS1_st_ldo4_ocp_START (3)
#define COMMON_PMIC_OCP_STATUS1_st_ldo4_ocp_END (3)
#define COMMON_PMIC_OCP_STATUS1_st_ldo5_ocp_START (4)
#define COMMON_PMIC_OCP_STATUS1_st_ldo5_ocp_END (4)
#define COMMON_PMIC_OCP_STATUS1_st_ldo6_ocp_START (5)
#define COMMON_PMIC_OCP_STATUS1_st_ldo6_ocp_END (5)
#define COMMON_PMIC_OCP_STATUS1_st_ldo7_ocp_START (6)
#define COMMON_PMIC_OCP_STATUS1_st_ldo7_ocp_END (6)
#define COMMON_PMIC_OCP_STATUS1_st_ldo8_ocp_START (7)
#define COMMON_PMIC_OCP_STATUS1_st_ldo8_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b1_scp : 1;
        unsigned char st_b2_scp : 1;
        unsigned char st_b3_scp : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_SCP_STATUS0_UNION;
#endif
#define COMMON_PMIC_SCP_STATUS0_st_b1_scp_START (0)
#define COMMON_PMIC_SCP_STATUS0_st_b1_scp_END (0)
#define COMMON_PMIC_SCP_STATUS0_st_b2_scp_START (1)
#define COMMON_PMIC_SCP_STATUS0_st_b2_scp_END (1)
#define COMMON_PMIC_SCP_STATUS0_st_b3_scp_START (2)
#define COMMON_PMIC_SCP_STATUS0_st_b3_scp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ocp_state : 1;
        unsigned char b2_ocp_state : 1;
        unsigned char b3_ocp_state : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_A2D_BUCK_STATUS0_UNION;
#endif
#define COMMON_PMIC_A2D_BUCK_STATUS0_b1_ocp_state_START (0)
#define COMMON_PMIC_A2D_BUCK_STATUS0_b1_ocp_state_END (0)
#define COMMON_PMIC_A2D_BUCK_STATUS0_b2_ocp_state_START (1)
#define COMMON_PMIC_A2D_BUCK_STATUS0_b2_ocp_state_END (1)
#define COMMON_PMIC_A2D_BUCK_STATUS0_b3_ocp_state_START (2)
#define COMMON_PMIC_A2D_BUCK_STATUS0_b3_ocp_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ccm_state : 1;
        unsigned char b2_ccm_state : 1;
        unsigned char b3_ccm_state : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_A2D_BUCK_STATUS1_UNION;
#endif
#define COMMON_PMIC_A2D_BUCK_STATUS1_b1_ccm_state_START (0)
#define COMMON_PMIC_A2D_BUCK_STATUS1_b1_ccm_state_END (0)
#define COMMON_PMIC_A2D_BUCK_STATUS1_b2_ccm_state_START (1)
#define COMMON_PMIC_A2D_BUCK_STATUS1_b2_ccm_state_END (1)
#define COMMON_PMIC_A2D_BUCK_STATUS1_b3_ccm_state_START (2)
#define COMMON_PMIC_A2D_BUCK_STATUS1_b3_ccm_state_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b1_rampup_state : 1;
        unsigned char st_b1_rampdown_state : 1;
        unsigned char st_b2_rampup_state : 1;
        unsigned char st_b2_rampdown_state : 1;
        unsigned char st_b3_rampup_state : 1;
        unsigned char st_b3_rampdown_state : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_RAMP_STATUS0_UNION;
#endif
#define COMMON_PMIC_RAMP_STATUS0_st_b1_rampup_state_START (0)
#define COMMON_PMIC_RAMP_STATUS0_st_b1_rampup_state_END (0)
#define COMMON_PMIC_RAMP_STATUS0_st_b1_rampdown_state_START (1)
#define COMMON_PMIC_RAMP_STATUS0_st_b1_rampdown_state_END (1)
#define COMMON_PMIC_RAMP_STATUS0_st_b2_rampup_state_START (2)
#define COMMON_PMIC_RAMP_STATUS0_st_b2_rampup_state_END (2)
#define COMMON_PMIC_RAMP_STATUS0_st_b2_rampdown_state_START (3)
#define COMMON_PMIC_RAMP_STATUS0_st_b2_rampdown_state_END (3)
#define COMMON_PMIC_RAMP_STATUS0_st_b3_rampup_state_START (4)
#define COMMON_PMIC_RAMP_STATUS0_st_b3_rampup_state_END (4)
#define COMMON_PMIC_RAMP_STATUS0_st_b3_rampdown_state_START (5)
#define COMMON_PMIC_RAMP_STATUS0_st_b3_rampdown_state_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_ldo1_pull_down : 1;
        unsigned char st_ldo3_pull_down : 1;
        unsigned char st_ldo8_pull_down : 1;
        unsigned char reserved_0 : 1;
        unsigned char st_xvs_in_deb : 1;
        unsigned char reserved_1 : 3;
    } reg;
} COMMON_PMIC_RAMP_STATUS1_UNION;
#endif
#define COMMON_PMIC_RAMP_STATUS1_st_ldo1_pull_down_START (0)
#define COMMON_PMIC_RAMP_STATUS1_st_ldo1_pull_down_END (0)
#define COMMON_PMIC_RAMP_STATUS1_st_ldo3_pull_down_START (1)
#define COMMON_PMIC_RAMP_STATUS1_st_ldo3_pull_down_END (1)
#define COMMON_PMIC_RAMP_STATUS1_st_ldo8_pull_down_START (2)
#define COMMON_PMIC_RAMP_STATUS1_st_ldo8_pull_down_END (2)
#define COMMON_PMIC_RAMP_STATUS1_st_xvs_in_deb_START (4)
#define COMMON_PMIC_RAMP_STATUS1_st_xvs_in_deb_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_b1_en : 1;
        unsigned char st_b2_en : 1;
        unsigned char st_b3_en : 1;
        unsigned char st_ref_en : 1;
        unsigned char st_pmuh_en : 1;
        unsigned char st_ldo9_en : 1;
        unsigned char st_pmud_buck_en : 1;
        unsigned char st_pmud_state : 1;
    } reg;
} COMMON_PMIC_POWER_STATUS0_UNION;
#endif
#define COMMON_PMIC_POWER_STATUS0_st_b1_en_START (0)
#define COMMON_PMIC_POWER_STATUS0_st_b1_en_END (0)
#define COMMON_PMIC_POWER_STATUS0_st_b2_en_START (1)
#define COMMON_PMIC_POWER_STATUS0_st_b2_en_END (1)
#define COMMON_PMIC_POWER_STATUS0_st_b3_en_START (2)
#define COMMON_PMIC_POWER_STATUS0_st_b3_en_END (2)
#define COMMON_PMIC_POWER_STATUS0_st_ref_en_START (3)
#define COMMON_PMIC_POWER_STATUS0_st_ref_en_END (3)
#define COMMON_PMIC_POWER_STATUS0_st_pmuh_en_START (4)
#define COMMON_PMIC_POWER_STATUS0_st_pmuh_en_END (4)
#define COMMON_PMIC_POWER_STATUS0_st_ldo9_en_START (5)
#define COMMON_PMIC_POWER_STATUS0_st_ldo9_en_END (5)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_buck_en_START (6)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_buck_en_END (6)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_state_START (7)
#define COMMON_PMIC_POWER_STATUS0_st_pmud_state_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_ldo1_en : 1;
        unsigned char st_ldo2_en : 1;
        unsigned char st_ldo3_en : 1;
        unsigned char st_ldo4_en : 1;
        unsigned char st_ldo5_en : 1;
        unsigned char st_ldo6_en : 1;
        unsigned char st_ldo7_en : 1;
        unsigned char st_ldo8_en : 1;
    } reg;
} COMMON_PMIC_POWER_STATUS1_UNION;
#endif
#define COMMON_PMIC_POWER_STATUS1_st_ldo1_en_START (0)
#define COMMON_PMIC_POWER_STATUS1_st_ldo1_en_END (0)
#define COMMON_PMIC_POWER_STATUS1_st_ldo2_en_START (1)
#define COMMON_PMIC_POWER_STATUS1_st_ldo2_en_END (1)
#define COMMON_PMIC_POWER_STATUS1_st_ldo3_en_START (2)
#define COMMON_PMIC_POWER_STATUS1_st_ldo3_en_END (2)
#define COMMON_PMIC_POWER_STATUS1_st_ldo4_en_START (3)
#define COMMON_PMIC_POWER_STATUS1_st_ldo4_en_END (3)
#define COMMON_PMIC_POWER_STATUS1_st_ldo5_en_START (4)
#define COMMON_PMIC_POWER_STATUS1_st_ldo5_en_END (4)
#define COMMON_PMIC_POWER_STATUS1_st_ldo6_en_START (5)
#define COMMON_PMIC_POWER_STATUS1_st_ldo6_en_END (5)
#define COMMON_PMIC_POWER_STATUS1_st_ldo7_en_START (6)
#define COMMON_PMIC_POWER_STATUS1_st_ldo7_en_END (6)
#define COMMON_PMIC_POWER_STATUS1_st_ldo8_en_START (7)
#define COMMON_PMIC_POWER_STATUS1_st_ldo8_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_slave_id_sel_a2d : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_SEL_STATUS_UNION;
#endif
#define COMMON_PMIC_SEL_STATUS_st_slave_id_sel_a2d_START (0)
#define COMMON_PMIC_SEL_STATUS_st_slave_id_sel_a2d_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_vset_cfg : 8;
    } reg;
} COMMON_PMIC_BUCK1_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK1_VSET_b1_vset_cfg_START (0)
#define COMMON_PMIC_BUCK1_VSET_b1_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b1_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK1_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK1_ONOFF_reg_b1_en_START (0)
#define COMMON_PMIC_BUCK1_ONOFF_reg_b1_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_vset_cfg : 8;
    } reg;
} COMMON_PMIC_BUCK2_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK2_VSET_b2_vset_cfg_START (0)
#define COMMON_PMIC_BUCK2_VSET_b2_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b2_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK2_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK2_ONOFF_reg_b2_en_START (0)
#define COMMON_PMIC_BUCK2_ONOFF_reg_b2_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_vset_cfg : 8;
    } reg;
} COMMON_PMIC_BUCK3_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK3_VSET_b3_vset_cfg_START (0)
#define COMMON_PMIC_BUCK3_VSET_b3_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b3_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK3_ONOFF_UNION;
#endif
#define COMMON_PMIC_BUCK3_ONOFF_reg_b3_en_START (0)
#define COMMON_PMIC_BUCK3_ONOFF_reg_b3_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_vset_cfg : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO1_VSET_UNION;
#endif
#define COMMON_PMIC_LDO1_VSET_ldo1_vset_cfg_START (0)
#define COMMON_PMIC_LDO1_VSET_ldo1_vset_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo1_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO1_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO1_ONOFF_reg_ldo1_en_START (0)
#define COMMON_PMIC_LDO1_ONOFF_reg_ldo1_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_vset : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO2_VSET_UNION;
#endif
#define COMMON_PMIC_LDO2_VSET_ldo2_vset_START (0)
#define COMMON_PMIC_LDO2_VSET_ldo2_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo2_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO2_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO2_ONOFF_reg_ldo2_en_START (0)
#define COMMON_PMIC_LDO2_ONOFF_reg_ldo2_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_vset_cfg : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO3_VSET_UNION;
#endif
#define COMMON_PMIC_LDO3_VSET_ldo3_vset_cfg_START (0)
#define COMMON_PMIC_LDO3_VSET_ldo3_vset_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo3_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO3_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO3_ONOFF_reg_ldo3_en_START (0)
#define COMMON_PMIC_LDO3_ONOFF_reg_ldo3_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO4_VSET_UNION;
#endif
#define COMMON_PMIC_LDO4_VSET_ldo4_vset_START (0)
#define COMMON_PMIC_LDO4_VSET_ldo4_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo4_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO4_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO4_ONOFF_reg_ldo4_en_START (0)
#define COMMON_PMIC_LDO4_ONOFF_reg_ldo4_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO5_VSET_UNION;
#endif
#define COMMON_PMIC_LDO5_VSET_ldo5_vset_START (0)
#define COMMON_PMIC_LDO5_VSET_ldo5_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo5_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO5_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO5_ONOFF_reg_ldo5_en_START (0)
#define COMMON_PMIC_LDO5_ONOFF_reg_ldo5_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_vset : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_LDO6_VSET_UNION;
#endif
#define COMMON_PMIC_LDO6_VSET_ldo6_vset_START (0)
#define COMMON_PMIC_LDO6_VSET_ldo6_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo6_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO6_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO6_ONOFF_reg_ldo6_en_START (0)
#define COMMON_PMIC_LDO6_ONOFF_reg_ldo6_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo7_vset : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO7_VSET_UNION;
#endif
#define COMMON_PMIC_LDO7_VSET_ldo7_vset_START (0)
#define COMMON_PMIC_LDO7_VSET_ldo7_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo7_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO7_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO7_ONOFF_reg_ldo7_en_START (0)
#define COMMON_PMIC_LDO7_ONOFF_reg_ldo7_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_vset_cfg : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO8_VSET_UNION;
#endif
#define COMMON_PMIC_LDO8_VSET_ldo8_vset_cfg_START (0)
#define COMMON_PMIC_LDO8_VSET_ldo8_vset_cfg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo8_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO8_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO8_ONOFF_reg_ldo8_en_START (0)
#define COMMON_PMIC_LDO8_ONOFF_reg_ldo8_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo9_vset : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO9_VSET_UNION;
#endif
#define COMMON_PMIC_LDO9_VSET_ldo9_vset_START (0)
#define COMMON_PMIC_LDO9_VSET_ldo9_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo9_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO9_ONOFF_UNION;
#endif
#define COMMON_PMIC_LDO9_ONOFF_reg_ldo9_en_START (0)
#define COMMON_PMIC_LDO9_ONOFF_reg_ldo9_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_vset : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_PMUH_VSET_UNION;
#endif
#define COMMON_PMIC_PMUH_VSET_pmuh_vset_START (0)
#define COMMON_PMIC_PMUH_VSET_pmuh_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_pmuh_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_PMUH_ONOFF_UNION;
#endif
#define COMMON_PMIC_PMUH_ONOFF_reg_pmuh_en_START (0)
#define COMMON_PMIC_PMUH_ONOFF_reg_pmuh_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b1_eco_en : 1;
        unsigned char reg_b2_eco_en : 1;
        unsigned char reg_b3_eco_en : 1;
        unsigned char reg_ref_eco_en : 1;
        unsigned char reg_pmuh_eco_en : 1;
        unsigned char reg_ldo9_eco_en : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_PWR_ECO_ONOFF0_UNION;
#endif
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b1_eco_en_START (0)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b1_eco_en_END (0)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b2_eco_en_START (1)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b2_eco_en_END (1)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b3_eco_en_START (2)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_b3_eco_en_END (2)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_ref_eco_en_START (3)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_ref_eco_en_END (3)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_pmuh_eco_en_START (4)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_pmuh_eco_en_END (4)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_ldo9_eco_en_START (5)
#define COMMON_PMIC_PWR_ECO_ONOFF0_reg_ldo9_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_ldo1_eco_en : 1;
        unsigned char reg_ldo2_eco_en : 1;
        unsigned char reg_ldo3_eco_en : 1;
        unsigned char reg_ldo4_eco_en : 1;
        unsigned char reg_ldo5_eco_en : 1;
        unsigned char reg_ldo6_eco_en : 1;
        unsigned char reg_ldo7_eco_en : 1;
        unsigned char reg_ldo8_eco_en : 1;
    } reg;
} COMMON_PMIC_PWR_ECO_ONOFF1_UNION;
#endif
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo1_eco_en_START (0)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo1_eco_en_END (0)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo2_eco_en_START (1)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo2_eco_en_END (1)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo3_eco_en_START (2)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo3_eco_en_END (2)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo4_eco_en_START (3)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo4_eco_en_END (3)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo5_eco_en_START (4)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo5_eco_en_END (4)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo6_eco_en_START (5)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo6_eco_en_END (5)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo7_eco_en_START (6)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo7_eco_en_END (6)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo8_eco_en_START (7)
#define COMMON_PMIC_PWR_ECO_ONOFF1_reg_ldo8_eco_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char thsd_mode_sel : 1;
        unsigned char thsd_tmp_set : 2;
        unsigned char reg_thsd_en : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BG_THSD_EN_UNION;
#endif
#define COMMON_PMIC_BG_THSD_EN_thsd_mode_sel_START (0)
#define COMMON_PMIC_BG_THSD_EN_thsd_mode_sel_END (0)
#define COMMON_PMIC_BG_THSD_EN_thsd_tmp_set_START (1)
#define COMMON_PMIC_BG_THSD_EN_thsd_tmp_set_END (2)
#define COMMON_PMIC_BG_THSD_EN_reg_thsd_en_START (3)
#define COMMON_PMIC_BG_THSD_EN_reg_thsd_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ocp_auto_stop : 2;
        unsigned char b2_ocp_auto_stop : 2;
        unsigned char b3_ocp_auto_stop : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK_OCP_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b1_ocp_auto_stop_START (0)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b1_ocp_auto_stop_END (1)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b2_ocp_auto_stop_START (2)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b2_ocp_auto_stop_END (3)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b3_ocp_auto_stop_START (4)
#define COMMON_PMIC_BUCK_OCP_MODE_CTRL0_b3_ocp_auto_stop_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_ocp_auto_stop : 2;
        unsigned char ldo2_ocp_auto_stop : 2;
        unsigned char ldo3_ocp_auto_stop : 2;
        unsigned char ldo4_ocp_auto_stop : 2;
    } reg;
} COMMON_PMIC_LDO_OCP_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo1_ocp_auto_stop_START (0)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo1_ocp_auto_stop_END (1)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo2_ocp_auto_stop_START (2)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo2_ocp_auto_stop_END (3)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo3_ocp_auto_stop_START (4)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo3_ocp_auto_stop_END (5)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo4_ocp_auto_stop_START (6)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL0_ldo4_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_ocp_auto_stop : 2;
        unsigned char ldo6_ocp_auto_stop : 2;
        unsigned char ldo7_ocp_auto_stop : 2;
        unsigned char ldo8_ocp_auto_stop : 2;
    } reg;
} COMMON_PMIC_LDO_OCP_MODE_CTRL1_UNION;
#endif
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo5_ocp_auto_stop_START (0)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo5_ocp_auto_stop_END (1)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo6_ocp_auto_stop_START (2)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo6_ocp_auto_stop_END (3)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo7_ocp_auto_stop_START (4)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo7_ocp_auto_stop_END (5)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo8_ocp_auto_stop_START (6)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL1_ldo8_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo9_ocp_auto_stop : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_LDO_OCP_MODE_CTRL2_UNION;
#endif
#define COMMON_PMIC_LDO_OCP_MODE_CTRL2_ldo9_ocp_auto_stop_START (0)
#define COMMON_PMIC_LDO_OCP_MODE_CTRL2_ldo9_ocp_auto_stop_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_scp_auto_stop : 2;
        unsigned char b2_scp_auto_stop : 2;
        unsigned char b3_scp_auto_stop : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK_SCP_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b1_scp_auto_stop_START (0)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b1_scp_auto_stop_END (1)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b2_scp_auto_stop_START (2)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b2_scp_auto_stop_END (3)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b3_scp_auto_stop_START (4)
#define COMMON_PMIC_BUCK_SCP_MODE_CTRL0_b3_scp_auto_stop_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char vin_ldo_1p95_vld_auto_stop : 2;
        unsigned char pvdd3_sys3_ov_auto_stop : 2;
        unsigned char pvdd3_sys3_vld_auto_stop : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_SYS_MODE_CTRL0_UNION;
#endif
#define COMMON_PMIC_SYS_MODE_CTRL0_vin_ldo_1p95_vld_auto_stop_START (0)
#define COMMON_PMIC_SYS_MODE_CTRL0_vin_ldo_1p95_vld_auto_stop_END (1)
#define COMMON_PMIC_SYS_MODE_CTRL0_pvdd3_sys3_ov_auto_stop_START (2)
#define COMMON_PMIC_SYS_MODE_CTRL0_pvdd3_sys3_ov_auto_stop_END (3)
#define COMMON_PMIC_SYS_MODE_CTRL0_pvdd3_sys3_vld_auto_stop_START (4)
#define COMMON_PMIC_SYS_MODE_CTRL0_pvdd3_sys3_vld_auto_stop_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_ocp_deb_sel : 2;
        unsigned char en_buck_ocp_deb : 1;
        unsigned char ldo_ocp_deb_sel : 2;
        unsigned char en_ldo_ocp_deb : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_OCP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_OCP_DEB_CTRL_buck_ocp_deb_sel_START (0)
#define COMMON_PMIC_OCP_DEB_CTRL_buck_ocp_deb_sel_END (1)
#define COMMON_PMIC_OCP_DEB_CTRL_en_buck_ocp_deb_START (2)
#define COMMON_PMIC_OCP_DEB_CTRL_en_buck_ocp_deb_END (2)
#define COMMON_PMIC_OCP_DEB_CTRL_ldo_ocp_deb_sel_START (3)
#define COMMON_PMIC_OCP_DEB_CTRL_ldo_ocp_deb_sel_END (4)
#define COMMON_PMIC_OCP_DEB_CTRL_en_ldo_ocp_deb_START (5)
#define COMMON_PMIC_OCP_DEB_CTRL_en_ldo_ocp_deb_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_scp_deb_sel : 2;
        unsigned char en_buck_scp_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_SCP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_SCP_DEB_CTRL_buck_scp_deb_sel_START (0)
#define COMMON_PMIC_SCP_DEB_CTRL_buck_scp_deb_sel_END (1)
#define COMMON_PMIC_SCP_DEB_CTRL_en_buck_scp_deb_START (2)
#define COMMON_PMIC_SCP_DEB_CTRL_en_buck_scp_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char otmp140_deb_sel : 2;
        unsigned char otmp125_deb_sel : 1;
        unsigned char buck_temp_damage_deb_sel : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_OTMP_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp140_deb_sel_START (0)
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp140_deb_sel_END (1)
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp125_deb_sel_START (2)
#define COMMON_PMIC_OTMP_DEB_CTRL_otmp125_deb_sel_END (2)
#define COMMON_PMIC_OTMP_DEB_CTRL_buck_temp_damage_deb_sel_START (3)
#define COMMON_PMIC_OTMP_DEB_CTRL_buck_temp_damage_deb_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char vin_ldo_1p95_vld_deb_sel : 2;
        unsigned char pvdd3_sys3_ov_deb_sel : 2;
        unsigned char pvdd3_sys3_vld_deb_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_SYS_ABNOR_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_vin_ldo_1p95_vld_deb_sel_START (0)
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_vin_ldo_1p95_vld_deb_sel_END (1)
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_pvdd3_sys3_ov_deb_sel_START (2)
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_pvdd3_sys3_ov_deb_sel_END (3)
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_pvdd3_sys3_vld_deb_sel_START (4)
#define COMMON_PMIC_SYS_ABNOR_DEB_CTRL_pvdd3_sys3_vld_deb_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char core_io_vld_neg_deb_sel : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_CORE_IO_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_CORE_IO_DEB_CTRL_core_io_vld_neg_deb_sel_START (0)
#define COMMON_PMIC_CORE_IO_DEB_CTRL_core_io_vld_neg_deb_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_seq_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_ONECLICK_SEQ_EN_UNION;
#endif
#define COMMON_PMIC_ONECLICK_SEQ_EN_oneclick_seq_en_START (0)
#define COMMON_PMIC_ONECLICK_SEQ_EN_oneclick_seq_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_up_stage0 : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_ONECLICK_PU_STAGE0_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PU_STAGE0_oneclick_up_stage0_START (0)
#define COMMON_PMIC_ONECLICK_PU_STAGE0_oneclick_up_stage0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_up_stage1 : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_ONECLICK_PU_STAGE1_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PU_STAGE1_oneclick_up_stage1_START (0)
#define COMMON_PMIC_ONECLICK_PU_STAGE1_oneclick_up_stage1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_up_stage2 : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_ONECLICK_PU_STAGE2_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PU_STAGE2_oneclick_up_stage2_START (0)
#define COMMON_PMIC_ONECLICK_PU_STAGE2_oneclick_up_stage2_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_up_stage3 : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_ONECLICK_PU_STAGE3_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PU_STAGE3_oneclick_up_stage3_START (0)
#define COMMON_PMIC_ONECLICK_PU_STAGE3_oneclick_up_stage3_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_down_stage0 : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_ONECLICK_PD_STAGE0_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PD_STAGE0_oneclick_down_stage0_START (0)
#define COMMON_PMIC_ONECLICK_PD_STAGE0_oneclick_down_stage0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_down_stage1 : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_ONECLICK_PD_STAGE1_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PD_STAGE1_oneclick_down_stage1_START (0)
#define COMMON_PMIC_ONECLICK_PD_STAGE1_oneclick_down_stage1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_down_stage2 : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_ONECLICK_PD_STAGE2_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PD_STAGE2_oneclick_down_stage2_START (0)
#define COMMON_PMIC_ONECLICK_PD_STAGE2_oneclick_down_stage2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_down_stage3 : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_ONECLICK_PD_STAGE3_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PD_STAGE3_oneclick_down_stage3_START (0)
#define COMMON_PMIC_ONECLICK_PD_STAGE3_oneclick_down_stage3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char oneclick_ldo6_updn_ctrl : 1;
        unsigned char oneclick_ldo8_updn_ctrl : 1;
        unsigned char oneclick_buck1_updn_ctrl : 1;
        unsigned char oneclick_buck2_updn_ctrl : 1;
        unsigned char oneclick_ldo5_updn_ctrl : 1;
        unsigned char oneclick_ldo1_updn_ctrl : 1;
        unsigned char oneclick_ldo4_updn_ctrl : 1;
        unsigned char oneclick_buck3_updn_ctrl : 1;
    } reg;
} COMMON_PMIC_ONECLICK_PU_CTRL_UNION;
#endif
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo6_updn_ctrl_START (0)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo6_updn_ctrl_END (0)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo8_updn_ctrl_START (1)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo8_updn_ctrl_END (1)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_buck1_updn_ctrl_START (2)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_buck1_updn_ctrl_END (2)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_buck2_updn_ctrl_START (3)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_buck2_updn_ctrl_END (3)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo5_updn_ctrl_START (4)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo5_updn_ctrl_END (4)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo1_updn_ctrl_START (5)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo1_updn_ctrl_END (5)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo4_updn_ctrl_START (6)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_ldo4_updn_ctrl_END (6)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_buck3_updn_ctrl_START (7)
#define COMMON_PMIC_ONECLICK_PU_CTRL_oneclick_buck3_updn_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char st_oneclick_up_done : 1;
        unsigned char st_oneclick_down_done : 1;
        unsigned char st_oneclick_abnordown_done : 1;
        unsigned char reserved_0 : 1;
        unsigned char st_oneclick_cur_state : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_ONECLICK_STATUS_UNION;
#endif
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_up_done_START (0)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_up_done_END (0)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_down_done_START (1)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_down_done_END (1)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_abnordown_done_START (2)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_abnordown_done_END (2)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_cur_state_START (4)
#define COMMON_PMIC_ONECLICK_STATUS_st_oneclick_cur_state_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_9m6_on : 8;
    } reg;
} COMMON_PMIC_OSC_9M6_ON_CTRL_UNION;
#endif
#define COMMON_PMIC_OSC_9M6_ON_CTRL_reg_9m6_on_START (0)
#define COMMON_PMIC_OSC_9M6_ON_CTRL_reg_9m6_on_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_9m6_off : 8;
    } reg;
} COMMON_PMIC_OSC_9M6_OFF_CTRL_UNION;
#endif
#define COMMON_PMIC_OSC_9M6_OFF_CTRL_reg_9m6_off_START (0)
#define COMMON_PMIC_OSC_9M6_OFF_CTRL_reg_9m6_off_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char xvs_in_deb_sel : 2;
        unsigned char en_xvs_in_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_XVS_IN_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_XVS_IN_DEB_CTRL_xvs_in_deb_sel_START (0)
#define COMMON_PMIC_XVS_IN_DEB_CTRL_xvs_in_deb_sel_END (1)
#define COMMON_PMIC_XVS_IN_DEB_CTRL_en_xvs_in_deb_START (2)
#define COMMON_PMIC_XVS_IN_DEB_CTRL_en_xvs_in_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char xvs_in_en : 1;
        unsigned char xvs_in_mode : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_XVS_IN_CTRL_UNION;
#endif
#define COMMON_PMIC_XVS_IN_CTRL_xvs_in_en_START (0)
#define COMMON_PMIC_XVS_IN_CTRL_xvs_in_en_END (0)
#define COMMON_PMIC_XVS_IN_CTRL_xvs_in_mode_START (1)
#define COMMON_PMIC_XVS_IN_CTRL_xvs_in_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ramp_gt_debug : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_RAMP_GT_DEBUG_UNION;
#endif
#define COMMON_PMIC_RAMP_GT_DEBUG_ramp_gt_debug_START (0)
#define COMMON_PMIC_RAMP_GT_DEBUG_ramp_gt_debug_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_rampdown_rate : 3;
        unsigned char buck1_rampdown_en_cfg : 1;
        unsigned char buck1_rampup_rate : 3;
        unsigned char buck1_rampup_en_cfg : 1;
    } reg;
} COMMON_PMIC_BUCK1_RAMP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampdown_rate_START (0)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampdown_rate_END (2)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampdown_en_cfg_START (3)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampdown_en_cfg_END (3)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampup_rate_START (4)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampup_rate_END (6)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampup_en_cfg_START (7)
#define COMMON_PMIC_BUCK1_RAMP_CFG_buck1_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_ramp_step : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK1_RAMP_STEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RAMP_STEP_CFG_buck1_ramp_step_START (0)
#define COMMON_PMIC_BUCK1_RAMP_STEP_CFG_buck1_ramp_step_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_rampup_onestep_th : 6;
        unsigned char buck1_rampup_onestep_en : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_buck1_rampup_onestep_th_START (0)
#define COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_buck1_rampup_onestep_th_END (5)
#define COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_buck1_rampup_onestep_en_START (6)
#define COMMON_PMIC_BUCK1_RU_ONESTEP_CFG_buck1_rampup_onestep_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_rampdown_onestep_th : 6;
        unsigned char buck1_rampdown_onestep_en : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_buck1_rampdown_onestep_th_START (0)
#define COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_buck1_rampdown_onestep_th_END (5)
#define COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_buck1_rampdown_onestep_en_START (6)
#define COMMON_PMIC_BUCK1_RD_ONESTEP_CFG_buck1_rampdown_onestep_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck1_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK1_RU_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RU_DLY_CFG_buck1_dly_ru_off_cfg_START (0)
#define COMMON_PMIC_BUCK1_RU_DLY_CFG_buck1_dly_ru_off_cfg_END (2)
#define COMMON_PMIC_BUCK1_RU_DLY_CFG_buck1_dly_ru_on_cfg_START (4)
#define COMMON_PMIC_BUCK1_RU_DLY_CFG_buck1_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck1_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK1_RD_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RD_DLY_CFG_buck1_dly_rd_off_cfg_START (0)
#define COMMON_PMIC_BUCK1_RD_DLY_CFG_buck1_dly_rd_off_cfg_END (2)
#define COMMON_PMIC_BUCK1_RD_DLY_CFG_buck1_dly_rd_on_cfg_START (4)
#define COMMON_PMIC_BUCK1_RD_DLY_CFG_buck1_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_rampup_chg_rate : 2;
        unsigned char buck1_rampup_chg_vset : 3;
        unsigned char buck1_ru_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_RU_CHG_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_buck1_rampup_chg_rate_START (0)
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_buck1_rampup_chg_rate_END (1)
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_buck1_rampup_chg_vset_START (2)
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_buck1_rampup_chg_vset_END (4)
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_buck1_ru_nochg_rate_sel_START (5)
#define COMMON_PMIC_BUCK1_RU_CHG_CFG_buck1_ru_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_rampdown_chg_rate : 2;
        unsigned char buck1_rampdown_chg_vset : 3;
        unsigned char buck1_rd_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_RD_CHG_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_buck1_rampdown_chg_rate_START (0)
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_buck1_rampdown_chg_rate_END (1)
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_buck1_rampdown_chg_vset_START (2)
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_buck1_rampdown_chg_vset_END (4)
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_buck1_rd_nochg_rate_sel_START (5)
#define COMMON_PMIC_BUCK1_RD_CHG_CFG_buck1_rd_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_target_vset_cfg : 8;
    } reg;
} COMMON_PMIC_BUCK1_XVS_TGT_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK1_XVS_TGT_VSET_buck1_target_vset_cfg_START (0)
#define COMMON_PMIC_BUCK1_XVS_TGT_VSET_buck1_target_vset_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampdown_rate : 3;
        unsigned char buck2_rampdown_en_cfg : 1;
        unsigned char buck2_rampup_rate : 3;
        unsigned char buck2_rampup_en_cfg : 1;
    } reg;
} COMMON_PMIC_BUCK2_RAMP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_rate_START (0)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_rate_END (2)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_en_cfg_START (3)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampdown_en_cfg_END (3)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampup_rate_START (4)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampup_rate_END (6)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampup_en_cfg_START (7)
#define COMMON_PMIC_BUCK2_RAMP_CFG_buck2_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_ramp_step : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK2_RAMP_STEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RAMP_STEP_CFG_buck2_ramp_step_START (0)
#define COMMON_PMIC_BUCK2_RAMP_STEP_CFG_buck2_ramp_step_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampup_onestep_th : 6;
        unsigned char buck2_rampup_onestep_en : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_buck2_rampup_onestep_th_START (0)
#define COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_buck2_rampup_onestep_th_END (5)
#define COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_buck2_rampup_onestep_en_START (6)
#define COMMON_PMIC_BUCK2_RU_ONESTEP_CFG_buck2_rampup_onestep_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampdown_onestep_th : 6;
        unsigned char buck2_rampdown_onestep_en : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_buck2_rampdown_onestep_th_START (0)
#define COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_buck2_rampdown_onestep_th_END (5)
#define COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_buck2_rampdown_onestep_en_START (6)
#define COMMON_PMIC_BUCK2_RD_ONESTEP_CFG_buck2_rampdown_onestep_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck2_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK2_RU_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RU_DLY_CFG_buck2_dly_ru_off_cfg_START (0)
#define COMMON_PMIC_BUCK2_RU_DLY_CFG_buck2_dly_ru_off_cfg_END (2)
#define COMMON_PMIC_BUCK2_RU_DLY_CFG_buck2_dly_ru_on_cfg_START (4)
#define COMMON_PMIC_BUCK2_RU_DLY_CFG_buck2_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck2_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK2_RD_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RD_DLY_CFG_buck2_dly_rd_off_cfg_START (0)
#define COMMON_PMIC_BUCK2_RD_DLY_CFG_buck2_dly_rd_off_cfg_END (2)
#define COMMON_PMIC_BUCK2_RD_DLY_CFG_buck2_dly_rd_on_cfg_START (4)
#define COMMON_PMIC_BUCK2_RD_DLY_CFG_buck2_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampup_chg_rate : 2;
        unsigned char buck2_rampup_chg_vset : 3;
        unsigned char buck2_ru_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_RU_CHG_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_buck2_rampup_chg_rate_START (0)
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_buck2_rampup_chg_rate_END (1)
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_buck2_rampup_chg_vset_START (2)
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_buck2_rampup_chg_vset_END (4)
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_buck2_ru_nochg_rate_sel_START (5)
#define COMMON_PMIC_BUCK2_RU_CHG_CFG_buck2_ru_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck2_rampdown_chg_rate : 2;
        unsigned char buck2_rampdown_chg_vset : 3;
        unsigned char buck2_rd_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_RD_CHG_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_buck2_rampdown_chg_rate_START (0)
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_buck2_rampdown_chg_rate_END (1)
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_buck2_rampdown_chg_vset_START (2)
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_buck2_rampdown_chg_vset_END (4)
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_buck2_rd_nochg_rate_sel_START (5)
#define COMMON_PMIC_BUCK2_RD_CHG_CFG_buck2_rd_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampdown_rate : 3;
        unsigned char buck3_rampdown_en_cfg : 1;
        unsigned char buck3_rampup_rate : 3;
        unsigned char buck3_rampup_en_cfg : 1;
    } reg;
} COMMON_PMIC_BUCK3_RAMP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_rate_START (0)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_rate_END (2)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_en_cfg_START (3)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampdown_en_cfg_END (3)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampup_rate_START (4)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampup_rate_END (6)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampup_en_cfg_START (7)
#define COMMON_PMIC_BUCK3_RAMP_CFG_buck3_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_ramp_step : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK3_RAMP_STEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RAMP_STEP_CFG_buck3_ramp_step_START (0)
#define COMMON_PMIC_BUCK3_RAMP_STEP_CFG_buck3_ramp_step_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampup_onestep_th : 6;
        unsigned char buck3_rampup_onestep_en : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_buck3_rampup_onestep_th_START (0)
#define COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_buck3_rampup_onestep_th_END (5)
#define COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_buck3_rampup_onestep_en_START (6)
#define COMMON_PMIC_BUCK3_RU_ONESTEP_CFG_buck3_rampup_onestep_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampdown_onestep_th : 6;
        unsigned char buck3_rampdown_onestep_en : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_buck3_rampdown_onestep_th_START (0)
#define COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_buck3_rampdown_onestep_th_END (5)
#define COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_buck3_rampdown_onestep_en_START (6)
#define COMMON_PMIC_BUCK3_RD_ONESTEP_CFG_buck3_rampdown_onestep_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_dly_ru_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck3_dly_ru_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK3_RU_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RU_DLY_CFG_buck3_dly_ru_off_cfg_START (0)
#define COMMON_PMIC_BUCK3_RU_DLY_CFG_buck3_dly_ru_off_cfg_END (2)
#define COMMON_PMIC_BUCK3_RU_DLY_CFG_buck3_dly_ru_on_cfg_START (4)
#define COMMON_PMIC_BUCK3_RU_DLY_CFG_buck3_dly_ru_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_dly_rd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char buck3_dly_rd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_BUCK3_RD_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RD_DLY_CFG_buck3_dly_rd_off_cfg_START (0)
#define COMMON_PMIC_BUCK3_RD_DLY_CFG_buck3_dly_rd_off_cfg_END (2)
#define COMMON_PMIC_BUCK3_RD_DLY_CFG_buck3_dly_rd_on_cfg_START (4)
#define COMMON_PMIC_BUCK3_RD_DLY_CFG_buck3_dly_rd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampup_chg_rate : 2;
        unsigned char buck3_rampup_chg_vset : 3;
        unsigned char buck3_ru_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_RU_CHG_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_buck3_rampup_chg_rate_START (0)
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_buck3_rampup_chg_rate_END (1)
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_buck3_rampup_chg_vset_START (2)
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_buck3_rampup_chg_vset_END (4)
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_buck3_ru_nochg_rate_sel_START (5)
#define COMMON_PMIC_BUCK3_RU_CHG_CFG_buck3_ru_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck3_rampdown_chg_rate : 2;
        unsigned char buck3_rampdown_chg_vset : 3;
        unsigned char buck3_rd_nochg_rate_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_RD_CHG_CFG_UNION;
#endif
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_buck3_rampdown_chg_rate_START (0)
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_buck3_rampdown_chg_rate_END (1)
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_buck3_rampdown_chg_vset_START (2)
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_buck3_rampdown_chg_vset_END (4)
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_buck3_rd_nochg_rate_sel_START (5)
#define COMMON_PMIC_BUCK3_RD_CHG_CFG_buck3_rd_nochg_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_rampdown_rate : 3;
        unsigned char ldo1_rampdown_en_cfg : 1;
        unsigned char ldo1_rampup_rate : 3;
        unsigned char ldo1_rampup_en_cfg : 1;
    } reg;
} COMMON_PMIC_LDO1_RAMP_CFG_UNION;
#endif
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampdown_rate_START (0)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampdown_rate_END (2)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampdown_en_cfg_START (3)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampdown_en_cfg_END (3)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampup_rate_START (4)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampup_rate_END (6)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampup_en_cfg_START (7)
#define COMMON_PMIC_LDO1_RAMP_CFG_ldo1_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_dly_ru_on_cfg : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO1_RU_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_LDO1_RU_DLY_CFG_ldo1_dly_ru_on_cfg_START (0)
#define COMMON_PMIC_LDO1_RU_DLY_CFG_ldo1_dly_ru_on_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_dly_pd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char ldo1_dly_pd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_LDO1_PD_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_LDO1_PD_DLY_CFG_ldo1_dly_pd_off_cfg_START (0)
#define COMMON_PMIC_LDO1_PD_DLY_CFG_ldo1_dly_pd_off_cfg_END (2)
#define COMMON_PMIC_LDO1_PD_DLY_CFG_ldo1_dly_pd_on_cfg_START (4)
#define COMMON_PMIC_LDO1_PD_DLY_CFG_ldo1_dly_pd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_rampdown_rate : 3;
        unsigned char ldo3_rampdown_en_cfg : 1;
        unsigned char ldo3_rampup_rate : 3;
        unsigned char ldo3_rampup_en_cfg : 1;
    } reg;
} COMMON_PMIC_LDO3_RAMP_CFG_UNION;
#endif
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampdown_rate_START (0)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampdown_rate_END (2)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampdown_en_cfg_START (3)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampdown_en_cfg_END (3)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampup_rate_START (4)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampup_rate_END (6)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampup_en_cfg_START (7)
#define COMMON_PMIC_LDO3_RAMP_CFG_ldo3_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_dly_ru_on_cfg : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO3_RU_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_LDO3_RU_DLY_CFG_ldo3_dly_ru_on_cfg_START (0)
#define COMMON_PMIC_LDO3_RU_DLY_CFG_ldo3_dly_ru_on_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_dly_pd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char ldo3_dly_pd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_LDO3_PD_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_LDO3_PD_DLY_CFG_ldo3_dly_pd_off_cfg_START (0)
#define COMMON_PMIC_LDO3_PD_DLY_CFG_ldo3_dly_pd_off_cfg_END (2)
#define COMMON_PMIC_LDO3_PD_DLY_CFG_ldo3_dly_pd_on_cfg_START (4)
#define COMMON_PMIC_LDO3_PD_DLY_CFG_ldo3_dly_pd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_rampdown_rate : 3;
        unsigned char ldo8_rampdown_en_cfg : 1;
        unsigned char ldo8_rampup_rate : 3;
        unsigned char ldo8_rampup_en_cfg : 1;
    } reg;
} COMMON_PMIC_LDO8_RAMP_CFG_UNION;
#endif
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampdown_rate_START (0)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampdown_rate_END (2)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampdown_en_cfg_START (3)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampdown_en_cfg_END (3)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampup_rate_START (4)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampup_rate_END (6)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampup_en_cfg_START (7)
#define COMMON_PMIC_LDO8_RAMP_CFG_ldo8_rampup_en_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_dly_ru_on_cfg : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO8_RU_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_LDO8_RU_DLY_CFG_ldo8_dly_ru_on_cfg_START (0)
#define COMMON_PMIC_LDO8_RU_DLY_CFG_ldo8_dly_ru_on_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_dly_pd_off_cfg : 3;
        unsigned char reserved_0 : 1;
        unsigned char ldo8_dly_pd_on_cfg : 3;
        unsigned char reserved_1 : 1;
    } reg;
} COMMON_PMIC_LDO8_PD_DLY_CFG_UNION;
#endif
#define COMMON_PMIC_LDO8_PD_DLY_CFG_ldo8_dly_pd_off_cfg_START (0)
#define COMMON_PMIC_LDO8_PD_DLY_CFG_ldo8_dly_pd_off_cfg_END (2)
#define COMMON_PMIC_LDO8_PD_DLY_CFG_ldo8_dly_pd_on_cfg_START (4)
#define COMMON_PMIC_LDO8_PD_DLY_CFG_ldo8_dly_pd_on_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck1_ramp_state : 1;
        unsigned char buck2_ramp_state : 1;
        unsigned char buck3_ramp_state : 1;
        unsigned char ldo1_ramp_state : 1;
        unsigned char ldo3_ramp_state : 1;
        unsigned char ldo8_ramp_state : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_DIG_RAMP_STATUS_UNION;
#endif
#define COMMON_PMIC_DIG_RAMP_STATUS_buck1_ramp_state_START (0)
#define COMMON_PMIC_DIG_RAMP_STATUS_buck1_ramp_state_END (0)
#define COMMON_PMIC_DIG_RAMP_STATUS_buck2_ramp_state_START (1)
#define COMMON_PMIC_DIG_RAMP_STATUS_buck2_ramp_state_END (1)
#define COMMON_PMIC_DIG_RAMP_STATUS_buck3_ramp_state_START (2)
#define COMMON_PMIC_DIG_RAMP_STATUS_buck3_ramp_state_END (2)
#define COMMON_PMIC_DIG_RAMP_STATUS_ldo1_ramp_state_START (3)
#define COMMON_PMIC_DIG_RAMP_STATUS_ldo1_ramp_state_END (3)
#define COMMON_PMIC_DIG_RAMP_STATUS_ldo3_ramp_state_START (4)
#define COMMON_PMIC_DIG_RAMP_STATUS_ldo3_ramp_state_END (4)
#define COMMON_PMIC_DIG_RAMP_STATUS_ldo8_ramp_state_START (5)
#define COMMON_PMIC_DIG_RAMP_STATUS_ldo8_ramp_state_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_lock : 8;
    } reg;
} COMMON_PMIC_EFUSE_LOCK_UNION;
#endif
#define COMMON_PMIC_EFUSE_LOCK_efuse_lock_START (0)
#define COMMON_PMIC_EFUSE_LOCK_efuse_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_clk_ctrl : 8;
    } reg;
} COMMON_PMIC_EFUSE_CLK_CTRL_UNION;
#endif
#define COMMON_PMIC_EFUSE_CLK_CTRL_efuse_clk_ctrl_START (0)
#define COMMON_PMIC_EFUSE_CLK_CTRL_efuse_clk_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse_loop_rd_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_LOOP_RD_CTRL_UNION;
#endif
#define COMMON_PMIC_EFUSE_LOOP_RD_CTRL_sc_efuse_loop_rd_ctrl_START (0)
#define COMMON_PMIC_EFUSE_LOOP_RD_CTRL_sc_efuse_loop_rd_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse_wr_pulse : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_WR_PULSE_CTRL_UNION;
#endif
#define COMMON_PMIC_EFUSE_WR_PULSE_CTRL_efuse_wr_pulse_START (0)
#define COMMON_PMIC_EFUSE_WR_PULSE_CTRL_efuse_wr_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_data : 8;
    } reg;
} COMMON_PMIC_EFUSE0_D_UNION;
#endif
#define COMMON_PMIC_EFUSE0_D_efuse0_data_START (0)
#define COMMON_PMIC_EFUSE0_D_efuse0_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_aen_mode_sel : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_AEN_MODE_UNION;
#endif
#define COMMON_PMIC_EFUSE0_AEN_MODE_efuse0_aen_mode_sel_START (0)
#define COMMON_PMIC_EFUSE0_AEN_MODE_efuse0_aen_mode_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_prog_sel : 1;
        unsigned char efuse0_inctrl_sel : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_EFUSE0_MODE_CTRL_UNION;
#endif
#define COMMON_PMIC_EFUSE0_MODE_CTRL_efuse0_prog_sel_START (0)
#define COMMON_PMIC_EFUSE0_MODE_CTRL_efuse0_prog_sel_END (0)
#define COMMON_PMIC_EFUSE0_MODE_CTRL_efuse0_inctrl_sel_START (1)
#define COMMON_PMIC_EFUSE0_MODE_CTRL_efuse0_inctrl_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_rden_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_RDEN_CFG_UNION;
#endif
#define COMMON_PMIC_EFUSE0_RDEN_CFG_efuse0_rden_cfg_START (0)
#define COMMON_PMIC_EFUSE0_RDEN_CFG_efuse0_rden_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pgmen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_PGMEN_CFG_UNION;
#endif
#define COMMON_PMIC_EFUSE0_PGMEN_CFG_efuse0_pgmen_cfg_START (0)
#define COMMON_PMIC_EFUSE0_PGMEN_CFG_efuse0_pgmen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_aen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_AEN_CFG_UNION;
#endif
#define COMMON_PMIC_EFUSE0_AEN_CFG_efuse0_aen_cfg_START (0)
#define COMMON_PMIC_EFUSE0_AEN_CFG_efuse0_aen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_addr_l_cfg : 8;
    } reg;
} COMMON_PMIC_EFUSE0_ADDR_L_UNION;
#endif
#define COMMON_PMIC_EFUSE0_ADDR_L_efuse0_addr_l_cfg_START (0)
#define COMMON_PMIC_EFUSE0_ADDR_L_efuse0_addr_l_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_addr_h_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_ADDR_H_UNION;
#endif
#define COMMON_PMIC_EFUSE0_ADDR_H_efuse0_addr_h_cfg_START (0)
#define COMMON_PMIC_EFUSE0_ADDR_H_efuse0_addr_h_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_testbus_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_TESTBUS_EN_UNION;
#endif
#define COMMON_PMIC_EFUSE0_TESTBUS_EN_efuse0_testbus_en_START (0)
#define COMMON_PMIC_EFUSE0_TESTBUS_EN_efuse0_testbus_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_testbus_sel : 8;
    } reg;
} COMMON_PMIC_EFUSE0_TESTBUS_SEL_UNION;
#endif
#define COMMON_PMIC_EFUSE0_TESTBUS_SEL_efuse0_testbus_sel_START (0)
#define COMMON_PMIC_EFUSE0_TESTBUS_SEL_efuse0_testbus_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_testbus_data : 8;
    } reg;
} COMMON_PMIC_EFUSE0_TESTBUS_DATA_UNION;
#endif
#define COMMON_PMIC_EFUSE0_TESTBUS_DATA_efuse0_testbus_data_START (0)
#define COMMON_PMIC_EFUSE0_TESTBUS_DATA_efuse0_testbus_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_trim_pre_addr : 7;
        unsigned char sc_efuse0_trim_pre_we : 1;
    } reg;
} COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_UNION;
#endif
#define COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_addr_START (0)
#define COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_addr_END (6)
#define COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_we_START (7)
#define COMMON_PMIC_EFUSE0_PDOB_PRE_ADDR_WE_sc_efuse0_trim_pre_we_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_trim_pre_wdata : 8;
    } reg;
} COMMON_PMIC_EFUSE0_PDOB_PRE_WDATA_UNION;
#endif
#define COMMON_PMIC_EFUSE0_PDOB_PRE_WDATA_sc_efuse0_trim_pre_wdata_START (0)
#define COMMON_PMIC_EFUSE0_PDOB_PRE_WDATA_sc_efuse0_trim_pre_wdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_pdob_sel : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE_PDOB_SEL_UNION;
#endif
#define COMMON_PMIC_EFUSE_PDOB_SEL_sc_efuse0_pdob_sel_START (0)
#define COMMON_PMIC_EFUSE_PDOB_SEL_sc_efuse0_pdob_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sc_efuse0_state_reset : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_EFUSE0_FSM_RESET_UNION;
#endif
#define COMMON_PMIC_EFUSE0_FSM_RESET_sc_efuse0_state_reset_START (0)
#define COMMON_PMIC_EFUSE0_FSM_RESET_sc_efuse0_state_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob0_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_0_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_0_W_efuse0_pdob0_w_START (0)
#define COMMON_PMIC_EFUSE0_0_W_efuse0_pdob0_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob1_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_1_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_1_W_efuse0_pdob1_w_START (0)
#define COMMON_PMIC_EFUSE0_1_W_efuse0_pdob1_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob2_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_2_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_2_W_efuse0_pdob2_w_START (0)
#define COMMON_PMIC_EFUSE0_2_W_efuse0_pdob2_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob3_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_3_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_3_W_efuse0_pdob3_w_START (0)
#define COMMON_PMIC_EFUSE0_3_W_efuse0_pdob3_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob4_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_4_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_4_W_efuse0_pdob4_w_START (0)
#define COMMON_PMIC_EFUSE0_4_W_efuse0_pdob4_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob5_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_5_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_5_W_efuse0_pdob5_w_START (0)
#define COMMON_PMIC_EFUSE0_5_W_efuse0_pdob5_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob6_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_6_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_6_W_efuse0_pdob6_w_START (0)
#define COMMON_PMIC_EFUSE0_6_W_efuse0_pdob6_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob7_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_7_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_7_W_efuse0_pdob7_w_START (0)
#define COMMON_PMIC_EFUSE0_7_W_efuse0_pdob7_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob8_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_8_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_8_W_efuse0_pdob8_w_START (0)
#define COMMON_PMIC_EFUSE0_8_W_efuse0_pdob8_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob9_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_9_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_9_W_efuse0_pdob9_w_START (0)
#define COMMON_PMIC_EFUSE0_9_W_efuse0_pdob9_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob10_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_10_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_10_W_efuse0_pdob10_w_START (0)
#define COMMON_PMIC_EFUSE0_10_W_efuse0_pdob10_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob11_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_11_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_11_W_efuse0_pdob11_w_START (0)
#define COMMON_PMIC_EFUSE0_11_W_efuse0_pdob11_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob12_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_12_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_12_W_efuse0_pdob12_w_START (0)
#define COMMON_PMIC_EFUSE0_12_W_efuse0_pdob12_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob13_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_13_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_13_W_efuse0_pdob13_w_START (0)
#define COMMON_PMIC_EFUSE0_13_W_efuse0_pdob13_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob14_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_14_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_14_W_efuse0_pdob14_w_START (0)
#define COMMON_PMIC_EFUSE0_14_W_efuse0_pdob14_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob15_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_15_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_15_W_efuse0_pdob15_w_START (0)
#define COMMON_PMIC_EFUSE0_15_W_efuse0_pdob15_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob16_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_16_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_16_W_efuse0_pdob16_w_START (0)
#define COMMON_PMIC_EFUSE0_16_W_efuse0_pdob16_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob17_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_17_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_17_W_efuse0_pdob17_w_START (0)
#define COMMON_PMIC_EFUSE0_17_W_efuse0_pdob17_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob18_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_18_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_18_W_efuse0_pdob18_w_START (0)
#define COMMON_PMIC_EFUSE0_18_W_efuse0_pdob18_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob19_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_19_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_19_W_efuse0_pdob19_w_START (0)
#define COMMON_PMIC_EFUSE0_19_W_efuse0_pdob19_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob20_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_20_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_20_W_efuse0_pdob20_w_START (0)
#define COMMON_PMIC_EFUSE0_20_W_efuse0_pdob20_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob21_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_21_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_21_W_efuse0_pdob21_w_START (0)
#define COMMON_PMIC_EFUSE0_21_W_efuse0_pdob21_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob22_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_22_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_22_W_efuse0_pdob22_w_START (0)
#define COMMON_PMIC_EFUSE0_22_W_efuse0_pdob22_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob23_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_23_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_23_W_efuse0_pdob23_w_START (0)
#define COMMON_PMIC_EFUSE0_23_W_efuse0_pdob23_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob24_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_24_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_24_W_efuse0_pdob24_w_START (0)
#define COMMON_PMIC_EFUSE0_24_W_efuse0_pdob24_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob25_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_25_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_25_W_efuse0_pdob25_w_START (0)
#define COMMON_PMIC_EFUSE0_25_W_efuse0_pdob25_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob26_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_26_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_26_W_efuse0_pdob26_w_START (0)
#define COMMON_PMIC_EFUSE0_26_W_efuse0_pdob26_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob27_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_27_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_27_W_efuse0_pdob27_w_START (0)
#define COMMON_PMIC_EFUSE0_27_W_efuse0_pdob27_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob28_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_28_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_28_W_efuse0_pdob28_w_START (0)
#define COMMON_PMIC_EFUSE0_28_W_efuse0_pdob28_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob29_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_29_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_29_W_efuse0_pdob29_w_START (0)
#define COMMON_PMIC_EFUSE0_29_W_efuse0_pdob29_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob30_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_30_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_30_W_efuse0_pdob30_w_START (0)
#define COMMON_PMIC_EFUSE0_30_W_efuse0_pdob30_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob31_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_31_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_31_W_efuse0_pdob31_w_START (0)
#define COMMON_PMIC_EFUSE0_31_W_efuse0_pdob31_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob32_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_32_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_32_W_efuse0_pdob32_w_START (0)
#define COMMON_PMIC_EFUSE0_32_W_efuse0_pdob32_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob33_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_33_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_33_W_efuse0_pdob33_w_START (0)
#define COMMON_PMIC_EFUSE0_33_W_efuse0_pdob33_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob34_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_34_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_34_W_efuse0_pdob34_w_START (0)
#define COMMON_PMIC_EFUSE0_34_W_efuse0_pdob34_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob35_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_35_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_35_W_efuse0_pdob35_w_START (0)
#define COMMON_PMIC_EFUSE0_35_W_efuse0_pdob35_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob36_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_36_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_36_W_efuse0_pdob36_w_START (0)
#define COMMON_PMIC_EFUSE0_36_W_efuse0_pdob36_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob37_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_37_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_37_W_efuse0_pdob37_w_START (0)
#define COMMON_PMIC_EFUSE0_37_W_efuse0_pdob37_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob38_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_38_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_38_W_efuse0_pdob38_w_START (0)
#define COMMON_PMIC_EFUSE0_38_W_efuse0_pdob38_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob39_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_39_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_39_W_efuse0_pdob39_w_START (0)
#define COMMON_PMIC_EFUSE0_39_W_efuse0_pdob39_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob40_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_40_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_40_W_efuse0_pdob40_w_START (0)
#define COMMON_PMIC_EFUSE0_40_W_efuse0_pdob40_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char efuse0_pdob41_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_41_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_41_W_efuse0_pdob41_w_START (0)
#define COMMON_PMIC_EFUSE0_41_W_efuse0_pdob41_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse0_pdob42_w : 8;
    } reg;
} COMMON_PMIC_EFUSE0_42_W_UNION;
#endif
#define COMMON_PMIC_EFUSE0_42_W_np_efuse0_pdob42_w_START (0)
#define COMMON_PMIC_EFUSE0_42_W_np_efuse0_pdob42_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob0_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_0_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_0_R_np_efuse_pdob0_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_0_R_np_efuse_pdob0_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob1_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_1_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_1_R_np_efuse_pdob1_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_1_R_np_efuse_pdob1_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob2_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_2_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_2_R_np_efuse_pdob2_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_2_R_np_efuse_pdob2_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob3_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_3_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_3_R_np_efuse_pdob3_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_3_R_np_efuse_pdob3_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob4_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_4_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_4_R_np_efuse_pdob4_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_4_R_np_efuse_pdob4_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob5_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_5_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_5_R_np_efuse_pdob5_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_5_R_np_efuse_pdob5_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob6_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_6_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_6_R_np_efuse_pdob6_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_6_R_np_efuse_pdob6_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob7_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_7_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_7_R_np_efuse_pdob7_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_7_R_np_efuse_pdob7_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob8_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_8_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_8_R_np_efuse_pdob8_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_8_R_np_efuse_pdob8_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob9_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_9_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_9_R_np_efuse_pdob9_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_9_R_np_efuse_pdob9_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob10_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_10_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_10_R_np_efuse_pdob10_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_10_R_np_efuse_pdob10_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob11_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_11_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_11_R_np_efuse_pdob11_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_11_R_np_efuse_pdob11_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob12_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_12_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_12_R_np_efuse_pdob12_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_12_R_np_efuse_pdob12_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob13_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_13_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_13_R_np_efuse_pdob13_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_13_R_np_efuse_pdob13_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob14_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_14_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_14_R_np_efuse_pdob14_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_14_R_np_efuse_pdob14_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob15_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_15_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_15_R_np_efuse_pdob15_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_15_R_np_efuse_pdob15_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob16_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_16_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_16_R_np_efuse_pdob16_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_16_R_np_efuse_pdob16_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob17_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_17_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_17_R_np_efuse_pdob17_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_17_R_np_efuse_pdob17_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob18_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_18_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_18_R_np_efuse_pdob18_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_18_R_np_efuse_pdob18_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob19_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_19_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_19_R_np_efuse_pdob19_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_19_R_np_efuse_pdob19_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob20_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_20_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_20_R_np_efuse_pdob20_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_20_R_np_efuse_pdob20_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob21_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_21_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_21_R_np_efuse_pdob21_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_21_R_np_efuse_pdob21_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob22_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_22_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_22_R_np_efuse_pdob22_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_22_R_np_efuse_pdob22_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob23_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_23_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_23_R_np_efuse_pdob23_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_23_R_np_efuse_pdob23_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob24_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_24_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_24_R_np_efuse_pdob24_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_24_R_np_efuse_pdob24_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob25_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_25_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_25_R_np_efuse_pdob25_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_25_R_np_efuse_pdob25_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob26_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_26_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_26_R_np_efuse_pdob26_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_26_R_np_efuse_pdob26_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob27_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_27_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_27_R_np_efuse_pdob27_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_27_R_np_efuse_pdob27_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob28_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_28_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_28_R_np_efuse_pdob28_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_28_R_np_efuse_pdob28_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob29_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_29_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_29_R_np_efuse_pdob29_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_29_R_np_efuse_pdob29_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob30_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_30_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_30_R_np_efuse_pdob30_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_30_R_np_efuse_pdob30_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob31_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_31_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_31_R_np_efuse_pdob31_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_31_R_np_efuse_pdob31_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob32_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_32_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_32_R_np_efuse_pdob32_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_32_R_np_efuse_pdob32_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob33_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_33_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_33_R_np_efuse_pdob33_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_33_R_np_efuse_pdob33_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob34_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_34_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_34_R_np_efuse_pdob34_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_34_R_np_efuse_pdob34_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob35_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_35_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_35_R_np_efuse_pdob35_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_35_R_np_efuse_pdob35_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob36_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_36_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_36_R_np_efuse_pdob36_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_36_R_np_efuse_pdob36_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob37_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_37_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_37_R_np_efuse_pdob37_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_37_R_np_efuse_pdob37_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob38_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_38_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_38_R_np_efuse_pdob38_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_38_R_np_efuse_pdob38_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob39_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_39_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_39_R_np_efuse_pdob39_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_39_R_np_efuse_pdob39_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob40_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_40_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_40_R_np_efuse_pdob40_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_40_R_np_efuse_pdob40_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob41_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_41_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_41_R_np_efuse_pdob41_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_41_R_np_efuse_pdob41_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob42_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_42_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_42_R_np_efuse_pdob42_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_42_R_np_efuse_pdob42_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob43_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_43_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_43_R_np_efuse_pdob43_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_43_R_np_efuse_pdob43_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob44_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_44_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_44_R_np_efuse_pdob44_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_44_R_np_efuse_pdob44_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob45_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_45_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_45_R_np_efuse_pdob45_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_45_R_np_efuse_pdob45_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob46_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_46_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_46_R_np_efuse_pdob46_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_46_R_np_efuse_pdob46_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob47_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_47_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_47_R_np_efuse_pdob47_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_47_R_np_efuse_pdob47_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob48_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_48_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_48_R_np_efuse_pdob48_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_48_R_np_efuse_pdob48_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob49_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_49_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_49_R_np_efuse_pdob49_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_49_R_np_efuse_pdob49_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob50_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_50_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_50_R_np_efuse_pdob50_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_50_R_np_efuse_pdob50_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob51_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_51_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_51_R_np_efuse_pdob51_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_51_R_np_efuse_pdob51_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob52_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_52_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_52_R_np_efuse_pdob52_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_52_R_np_efuse_pdob52_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob53_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_53_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_53_R_np_efuse_pdob53_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_53_R_np_efuse_pdob53_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob54_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_54_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_54_R_np_efuse_pdob54_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_54_R_np_efuse_pdob54_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob55_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_55_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_55_R_np_efuse_pdob55_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_55_R_np_efuse_pdob55_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob56_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_56_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_56_R_np_efuse_pdob56_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_56_R_np_efuse_pdob56_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob57_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_57_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_57_R_np_efuse_pdob57_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_57_R_np_efuse_pdob57_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob58_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_58_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_58_R_np_efuse_pdob58_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_58_R_np_efuse_pdob58_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob59_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_59_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_59_R_np_efuse_pdob59_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_59_R_np_efuse_pdob59_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob60_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_60_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_60_R_np_efuse_pdob60_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_60_R_np_efuse_pdob60_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob61_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_61_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_61_R_np_efuse_pdob61_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_61_R_np_efuse_pdob61_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob62_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_62_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_62_R_np_efuse_pdob62_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_62_R_np_efuse_pdob62_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_pdob63_r : 8;
    } reg;
} COMMON_PMIC_NP_EFUSE0_63_R_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE0_63_R_np_efuse_pdob63_r_START (0)
#define COMMON_PMIC_NP_EFUSE0_63_R_np_efuse_pdob63_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_l2_0_rpt : 1;
        unsigned char irq_l2_1_rpt : 1;
        unsigned char irq_l2_2_rpt : 1;
        unsigned char irq_l2_3_rpt : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_IRQ_L2_RPT_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_0_rpt_START (0)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_0_rpt_END (0)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_1_rpt_START (1)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_1_rpt_END (1)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_2_rpt_START (2)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_2_rpt_END (2)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_3_rpt_START (3)
#define COMMON_PMIC_IRQ_L2_RPT_0_irq_l2_3_rpt_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_ocp_deb : 1;
        unsigned char irq_b2_ocp_deb : 1;
        unsigned char irq_b3_ocp_deb : 1;
        unsigned char irq_pmuh_ocp_deb : 1;
        unsigned char irq_ldo9_ocp_deb : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_b1_ocp_deb_START (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_b1_ocp_deb_END (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_b2_ocp_deb_START (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_b2_ocp_deb_END (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_b3_ocp_deb_START (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_b3_ocp_deb_END (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_pmuh_ocp_deb_START (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_pmuh_ocp_deb_END (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_ldo9_ocp_deb_START (4)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_0_irq_ldo9_ocp_deb_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ldo1_ocp_deb : 1;
        unsigned char irq_ldo2_ocp_deb : 1;
        unsigned char irq_ldo3_ocp_deb : 1;
        unsigned char irq_ldo4_ocp_deb : 1;
        unsigned char irq_ldo5_ocp_deb : 1;
        unsigned char irq_ldo6_ocp_deb : 1;
        unsigned char irq_ldo7_ocp_deb : 1;
        unsigned char irq_ldo8_ocp_deb : 1;
    } reg;
} COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo1_ocp_deb_START (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo1_ocp_deb_END (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo2_ocp_deb_START (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo2_ocp_deb_END (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo3_ocp_deb_START (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo3_ocp_deb_END (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo4_ocp_deb_START (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo4_ocp_deb_END (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo5_ocp_deb_START (4)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo5_ocp_deb_END (4)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo6_ocp_deb_START (5)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo6_ocp_deb_END (5)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo7_ocp_deb_START (6)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo7_ocp_deb_END (6)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo8_ocp_deb_START (7)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_1_irq_ldo8_ocp_deb_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_scp_deb : 1;
        unsigned char irq_b2_scp_deb : 1;
        unsigned char irq_b3_scp_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_irq_b1_scp_deb_START (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_irq_b1_scp_deb_END (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_irq_b2_scp_deb_START (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_irq_b2_scp_deb_END (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_irq_b3_scp_deb_START (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_RPT_2_irq_b3_scp_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_thsd_otmp125_deb : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_IRQ_L3_TEMP_RPT_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_0_irq_thsd_otmp125_deb_START (0)
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_0_irq_thsd_otmp125_deb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_temp_damage_deb : 1;
        unsigned char irq_b2_temp_damage_deb : 1;
        unsigned char irq_b3_temp_damage_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_IRQ_L3_TEMP_RPT_1_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_irq_b1_temp_damage_deb_START (0)
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_irq_b1_temp_damage_deb_END (0)
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_irq_b2_temp_damage_deb_START (1)
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_irq_b2_temp_damage_deb_END (1)
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_irq_b3_temp_damage_deb_START (2)
#define COMMON_PMIC_IRQ_L3_TEMP_RPT_1_irq_b3_temp_damage_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_vin_ldo_1p95_vld_deb : 1;
        unsigned char irq_pvdd3_sys3_ov_deb : 1;
        unsigned char irq_pvdd3_sys3_vld_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_IRQ_L3_SYS_RPT_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_SYS_RPT_irq_vin_ldo_1p95_vld_deb_START (0)
#define COMMON_PMIC_IRQ_L3_SYS_RPT_irq_vin_ldo_1p95_vld_deb_END (0)
#define COMMON_PMIC_IRQ_L3_SYS_RPT_irq_pvdd3_sys3_ov_deb_START (1)
#define COMMON_PMIC_IRQ_L3_SYS_RPT_irq_pvdd3_sys3_ov_deb_END (1)
#define COMMON_PMIC_IRQ_L3_SYS_RPT_irq_pvdd3_sys3_vld_deb_START (2)
#define COMMON_PMIC_IRQ_L3_SYS_RPT_irq_pvdd3_sys3_vld_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_ramp_chg : 1;
        unsigned char irq_b2_ramp_chg : 1;
        unsigned char irq_b3_ramp_chg : 1;
        unsigned char irq_ldo1_ramp_chg : 1;
        unsigned char irq_ldo3_ramp_chg : 1;
        unsigned char irq_ldo8_ramp_chg : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_IRQ_L3_RAMP_RPT_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_b1_ramp_chg_START (0)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_b1_ramp_chg_END (0)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_b2_ramp_chg_START (1)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_b2_ramp_chg_END (1)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_b3_ramp_chg_START (2)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_b3_ramp_chg_END (2)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_ldo1_ramp_chg_START (3)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_ldo1_ramp_chg_END (3)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_ldo3_ramp_chg_START (4)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_ldo3_ramp_chg_END (4)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_ldo8_ramp_chg_START (5)
#define COMMON_PMIC_IRQ_L3_RAMP_RPT_0_irq_ldo8_ramp_chg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_l2_0_mask : 1;
        unsigned char irq_l2_1_mask : 1;
        unsigned char irq_l2_2_mask : 1;
        unsigned char irq_l2_3_mask : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_IRQ_L2_MASK_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_0_mask_START (0)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_0_mask_END (0)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_1_mask_START (1)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_1_mask_END (1)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_2_mask_START (2)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_2_mask_END (2)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_3_mask_START (3)
#define COMMON_PMIC_IRQ_L2_MASK_0_irq_l2_3_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_ocp_deb_mk : 1;
        unsigned char irq_b2_ocp_deb_mk : 1;
        unsigned char irq_b3_ocp_deb_mk : 1;
        unsigned char irq_pmuh_ocp_deb_mk : 1;
        unsigned char irq_ldo9_ocp_deb_mk : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_b1_ocp_deb_mk_START (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_b1_ocp_deb_mk_END (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_b2_ocp_deb_mk_START (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_b2_ocp_deb_mk_END (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_b3_ocp_deb_mk_START (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_b3_ocp_deb_mk_END (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_pmuh_ocp_deb_mk_START (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_pmuh_ocp_deb_mk_END (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_ldo9_ocp_deb_mk_START (4)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_0_irq_ldo9_ocp_deb_mk_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_ldo1_ocp_deb_mk : 1;
        unsigned char irq_ldo2_ocp_deb_mk : 1;
        unsigned char irq_ldo3_ocp_deb_mk : 1;
        unsigned char irq_ldo4_ocp_deb_mk : 1;
        unsigned char irq_ldo5_ocp_deb_mk : 1;
        unsigned char irq_ldo6_ocp_deb_mk : 1;
        unsigned char irq_ldo7_ocp_deb_mk : 1;
        unsigned char irq_ldo8_ocp_deb_mk : 1;
    } reg;
} COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo1_ocp_deb_mk_START (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo1_ocp_deb_mk_END (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo2_ocp_deb_mk_START (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo2_ocp_deb_mk_END (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo3_ocp_deb_mk_START (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo3_ocp_deb_mk_END (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo4_ocp_deb_mk_START (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo4_ocp_deb_mk_END (3)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo5_ocp_deb_mk_START (4)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo5_ocp_deb_mk_END (4)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo6_ocp_deb_mk_START (5)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo6_ocp_deb_mk_END (5)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo7_ocp_deb_mk_START (6)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo7_ocp_deb_mk_END (6)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo8_ocp_deb_mk_START (7)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_1_irq_ldo8_ocp_deb_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_scp_deb_mk : 1;
        unsigned char irq_b2_scp_deb_mk : 1;
        unsigned char irq_b3_scp_deb_mk : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_irq_b1_scp_deb_mk_START (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_irq_b1_scp_deb_mk_END (0)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_irq_b2_scp_deb_mk_START (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_irq_b2_scp_deb_mk_END (1)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_irq_b3_scp_deb_mk_START (2)
#define COMMON_PMIC_IRQ_L3_BUCKLDO_MASK_2_irq_b3_scp_deb_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_thsd_otmp125_deb_mk : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_IRQ_L3_TEMP_MASK_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_0_irq_thsd_otmp125_deb_mk_START (0)
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_0_irq_thsd_otmp125_deb_mk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_temp_damage_deb_mk : 1;
        unsigned char irq_b2_temp_damage_deb_mk : 1;
        unsigned char irq_b3_temp_damage_deb_mk : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_IRQ_L3_TEMP_MASK_1_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_irq_b1_temp_damage_deb_mk_START (0)
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_irq_b1_temp_damage_deb_mk_END (0)
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_irq_b2_temp_damage_deb_mk_START (1)
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_irq_b2_temp_damage_deb_mk_END (1)
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_irq_b3_temp_damage_deb_mk_START (2)
#define COMMON_PMIC_IRQ_L3_TEMP_MASK_1_irq_b3_temp_damage_deb_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_vin_ldo_1p95_vld_deb_mk : 1;
        unsigned char irq_pvdd3_sys3_ov_deb_mk : 1;
        unsigned char irq_pvdd3_sys3_vld_deb_mk : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_IRQ_L3_SYS_MASK_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_SYS_MASK_irq_vin_ldo_1p95_vld_deb_mk_START (0)
#define COMMON_PMIC_IRQ_L3_SYS_MASK_irq_vin_ldo_1p95_vld_deb_mk_END (0)
#define COMMON_PMIC_IRQ_L3_SYS_MASK_irq_pvdd3_sys3_ov_deb_mk_START (1)
#define COMMON_PMIC_IRQ_L3_SYS_MASK_irq_pvdd3_sys3_ov_deb_mk_END (1)
#define COMMON_PMIC_IRQ_L3_SYS_MASK_irq_pvdd3_sys3_vld_deb_mk_START (2)
#define COMMON_PMIC_IRQ_L3_SYS_MASK_irq_pvdd3_sys3_vld_deb_mk_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char irq_b1_ramp_chg_mk : 1;
        unsigned char irq_b2_ramp_chg_mk : 1;
        unsigned char irq_b3_ramp_chg_mk : 1;
        unsigned char irq_ldo1_ramp_chg_mk : 1;
        unsigned char irq_ldo3_ramp_chg_mk : 1;
        unsigned char irq_ldo8_ramp_chg_mk : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_IRQ_L3_RAMP_MASK_0_UNION;
#endif
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_b1_ramp_chg_mk_START (0)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_b1_ramp_chg_mk_END (0)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_b2_ramp_chg_mk_START (1)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_b2_ramp_chg_mk_END (1)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_b3_ramp_chg_mk_START (2)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_b3_ramp_chg_mk_END (2)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_ldo1_ramp_chg_mk_START (3)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_ldo1_ramp_chg_mk_END (3)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_ldo3_ramp_chg_mk_START (4)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_ldo3_ramp_chg_mk_END (4)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_ldo8_ramp_chg_mk_START (5)
#define COMMON_PMIC_IRQ_L3_RAMP_MASK_0_irq_ldo8_ramp_chg_mk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_ocp_deb : 1;
        unsigned char np_b2_ocp_deb : 1;
        unsigned char np_b3_ocp_deb : 1;
        unsigned char np_pmuh_ocp_deb : 1;
        unsigned char np_ldo9_ocp_deb : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_NP_OCP0_UNION;
#endif
#define COMMON_PMIC_NP_OCP0_np_b1_ocp_deb_START (0)
#define COMMON_PMIC_NP_OCP0_np_b1_ocp_deb_END (0)
#define COMMON_PMIC_NP_OCP0_np_b2_ocp_deb_START (1)
#define COMMON_PMIC_NP_OCP0_np_b2_ocp_deb_END (1)
#define COMMON_PMIC_NP_OCP0_np_b3_ocp_deb_START (2)
#define COMMON_PMIC_NP_OCP0_np_b3_ocp_deb_END (2)
#define COMMON_PMIC_NP_OCP0_np_pmuh_ocp_deb_START (3)
#define COMMON_PMIC_NP_OCP0_np_pmuh_ocp_deb_END (3)
#define COMMON_PMIC_NP_OCP0_np_ldo9_ocp_deb_START (4)
#define COMMON_PMIC_NP_OCP0_np_ldo9_ocp_deb_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo1_ocp_deb : 1;
        unsigned char np_ldo2_ocp_deb : 1;
        unsigned char np_ldo3_ocp_deb : 1;
        unsigned char np_ldo4_ocp_deb : 1;
        unsigned char np_ldo5_ocp_deb : 1;
        unsigned char np_ldo6_ocp_deb : 1;
        unsigned char np_ldo7_ocp_deb : 1;
        unsigned char np_ldo8_ocp_deb : 1;
    } reg;
} COMMON_PMIC_NP_OCP1_UNION;
#endif
#define COMMON_PMIC_NP_OCP1_np_ldo1_ocp_deb_START (0)
#define COMMON_PMIC_NP_OCP1_np_ldo1_ocp_deb_END (0)
#define COMMON_PMIC_NP_OCP1_np_ldo2_ocp_deb_START (1)
#define COMMON_PMIC_NP_OCP1_np_ldo2_ocp_deb_END (1)
#define COMMON_PMIC_NP_OCP1_np_ldo3_ocp_deb_START (2)
#define COMMON_PMIC_NP_OCP1_np_ldo3_ocp_deb_END (2)
#define COMMON_PMIC_NP_OCP1_np_ldo4_ocp_deb_START (3)
#define COMMON_PMIC_NP_OCP1_np_ldo4_ocp_deb_END (3)
#define COMMON_PMIC_NP_OCP1_np_ldo5_ocp_deb_START (4)
#define COMMON_PMIC_NP_OCP1_np_ldo5_ocp_deb_END (4)
#define COMMON_PMIC_NP_OCP1_np_ldo6_ocp_deb_START (5)
#define COMMON_PMIC_NP_OCP1_np_ldo6_ocp_deb_END (5)
#define COMMON_PMIC_NP_OCP1_np_ldo7_ocp_deb_START (6)
#define COMMON_PMIC_NP_OCP1_np_ldo7_ocp_deb_END (6)
#define COMMON_PMIC_NP_OCP1_np_ldo8_ocp_deb_START (7)
#define COMMON_PMIC_NP_OCP1_np_ldo8_ocp_deb_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_scp_deb : 1;
        unsigned char np_b2_scp_deb : 1;
        unsigned char np_b3_scp_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_SCP0_UNION;
#endif
#define COMMON_PMIC_NP_SCP0_np_b1_scp_deb_START (0)
#define COMMON_PMIC_NP_SCP0_np_b1_scp_deb_END (0)
#define COMMON_PMIC_NP_SCP0_np_b2_scp_deb_START (1)
#define COMMON_PMIC_NP_SCP0_np_b2_scp_deb_END (1)
#define COMMON_PMIC_NP_SCP0_np_b3_scp_deb_START (2)
#define COMMON_PMIC_NP_SCP0_np_b3_scp_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_temp_damage_deb : 1;
        unsigned char np_b2_temp_damage_deb : 1;
        unsigned char np_b3_temp_damage_deb : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_BUCK_TEMP0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK_TEMP0_np_b1_temp_damage_deb_START (0)
#define COMMON_PMIC_NP_BUCK_TEMP0_np_b1_temp_damage_deb_END (0)
#define COMMON_PMIC_NP_BUCK_TEMP0_np_b2_temp_damage_deb_START (1)
#define COMMON_PMIC_NP_BUCK_TEMP0_np_b2_temp_damage_deb_END (1)
#define COMMON_PMIC_NP_BUCK_TEMP0_np_b3_temp_damage_deb_START (2)
#define COMMON_PMIC_NP_BUCK_TEMP0_np_b3_temp_damage_deb_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_ov_deb : 1;
        unsigned char np_vsys_pwroff_abs_sync : 1;
        unsigned char np_thsd_otmp140_deb : 1;
        unsigned char np_thsd_otmp125_deb : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_NP_RECORD0_UNION;
#endif
#define COMMON_PMIC_NP_RECORD0_np_vsys_ov_deb_START (0)
#define COMMON_PMIC_NP_RECORD0_np_vsys_ov_deb_END (0)
#define COMMON_PMIC_NP_RECORD0_np_vsys_pwroff_abs_sync_START (1)
#define COMMON_PMIC_NP_RECORD0_np_vsys_pwroff_abs_sync_END (1)
#define COMMON_PMIC_NP_RECORD0_np_thsd_otmp140_deb_START (2)
#define COMMON_PMIC_NP_RECORD0_np_thsd_otmp140_deb_END (2)
#define COMMON_PMIC_NP_RECORD0_np_thsd_otmp125_deb_START (3)
#define COMMON_PMIC_NP_RECORD0_np_thsd_otmp125_deb_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmud_short_n_sync : 1;
        unsigned char np_pmuh_short_n_sync : 1;
        unsigned char np_core_io_vld_f : 1;
        unsigned char np_vin_ldo_1p95_vld_deb : 1;
        unsigned char np_pvdd3_sys3_ov_deb : 1;
        unsigned char np_pvdd3_sys3_vld_deb : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_NP_RECORD1_UNION;
#endif
#define COMMON_PMIC_NP_RECORD1_np_pmud_short_n_sync_START (0)
#define COMMON_PMIC_NP_RECORD1_np_pmud_short_n_sync_END (0)
#define COMMON_PMIC_NP_RECORD1_np_pmuh_short_n_sync_START (1)
#define COMMON_PMIC_NP_RECORD1_np_pmuh_short_n_sync_END (1)
#define COMMON_PMIC_NP_RECORD1_np_core_io_vld_f_START (2)
#define COMMON_PMIC_NP_RECORD1_np_core_io_vld_f_END (2)
#define COMMON_PMIC_NP_RECORD1_np_vin_ldo_1p95_vld_deb_START (3)
#define COMMON_PMIC_NP_RECORD1_np_vin_ldo_1p95_vld_deb_END (3)
#define COMMON_PMIC_NP_RECORD1_np_pvdd3_sys3_ov_deb_START (4)
#define COMMON_PMIC_NP_RECORD1_np_pvdd3_sys3_ov_deb_END (4)
#define COMMON_PMIC_NP_RECORD1_np_pvdd3_sys3_vld_deb_START (5)
#define COMMON_PMIC_NP_RECORD1_np_pvdd3_sys3_vld_deb_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu_en_shutdown : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_NP_RECORD2_UNION;
#endif
#define COMMON_PMIC_NP_RECORD2_np_pmu_en_shutdown_START (0)
#define COMMON_PMIC_NP_RECORD2_np_pmu_en_shutdown_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_oneclick_up_abnor : 1;
        unsigned char np_oneclick_down_abnor : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_ONECLICK_EVENT_UNION;
#endif
#define COMMON_PMIC_NP_ONECLICK_EVENT_np_oneclick_up_abnor_START (0)
#define COMMON_PMIC_NP_ONECLICK_EVENT_np_oneclick_up_abnor_END (0)
#define COMMON_PMIC_NP_ONECLICK_EVENT_np_oneclick_down_abnor_START (1)
#define COMMON_PMIC_NP_ONECLICK_EVENT_np_oneclick_down_abnor_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_ramp_chg : 1;
        unsigned char np_b2_ramp_chg : 1;
        unsigned char np_b3_ramp_chg : 1;
        unsigned char np_ldo1_ramp_chg : 1;
        unsigned char np_ldo3_ramp_chg : 1;
        unsigned char np_ldo8_ramp_chg : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_NP_RAMP_EVENT0_UNION;
#endif
#define COMMON_PMIC_NP_RAMP_EVENT0_np_b1_ramp_chg_START (0)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_b1_ramp_chg_END (0)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_b2_ramp_chg_START (1)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_b2_ramp_chg_END (1)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_b3_ramp_chg_START (2)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_b3_ramp_chg_END (2)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_ldo1_ramp_chg_START (3)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_ldo1_ramp_chg_END (3)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_ldo3_ramp_chg_START (4)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_ldo3_ramp_chg_END (4)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_ldo8_ramp_chg_START (5)
#define COMMON_PMIC_NP_RAMP_EVENT0_np_ldo8_ramp_chg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_ramp_eco : 1;
        unsigned char np_b2_ramp_eco : 1;
        unsigned char np_b3_ramp_eco : 1;
        unsigned char np_ldo1_ramp_eco : 1;
        unsigned char np_ldo3_ramp_eco : 1;
        unsigned char np_ldo8_ramp_eco : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_NP_RAMP_EVENT1_UNION;
#endif
#define COMMON_PMIC_NP_RAMP_EVENT1_np_b1_ramp_eco_START (0)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_b1_ramp_eco_END (0)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_b2_ramp_eco_START (1)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_b2_ramp_eco_END (1)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_b3_ramp_eco_START (2)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_b3_ramp_eco_END (2)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_ldo1_ramp_eco_START (3)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_ldo1_ramp_eco_END (3)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_ldo3_ramp_eco_START (4)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_ldo3_ramp_eco_END (4)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_ldo8_ramp_eco_START (5)
#define COMMON_PMIC_NP_RAMP_EVENT1_np_ldo8_ramp_eco_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char soft_rst_n : 8;
    } reg;
} COMMON_PMIC_PMU_SOFT_RST_UNION;
#endif
#define COMMON_PMIC_PMU_SOFT_RST_soft_rst_n_START (0)
#define COMMON_PMIC_PMU_SOFT_RST_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_pwroff_abs_pd_mask : 1;
        unsigned char np_thsd_otmp140_pd_mask : 1;
        unsigned char np_vsys_ov_pd_mask : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_PD_MASK_UNION;
#endif
#define COMMON_PMIC_NP_PD_MASK_np_vsys_pwroff_abs_pd_mask_START (0)
#define COMMON_PMIC_NP_PD_MASK_np_vsys_pwroff_abs_pd_mask_END (0)
#define COMMON_PMIC_NP_PD_MASK_np_thsd_otmp140_pd_mask_START (1)
#define COMMON_PMIC_NP_PD_MASK_np_thsd_otmp140_pd_mask_END (1)
#define COMMON_PMIC_NP_PD_MASK_np_vsys_ov_pd_mask_START (2)
#define COMMON_PMIC_NP_PD_MASK_np_vsys_ov_pd_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu_en_pos_deb_sel : 3;
        unsigned char np_en_pmu_en_deb : 1;
        unsigned char np_pmu_en_neg_deb_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_NP_PMU_EN_DEB_CTRL_UNION;
#endif
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_np_pmu_en_pos_deb_sel_START (0)
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_np_pmu_en_pos_deb_sel_END (2)
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_np_en_pmu_en_deb_START (3)
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_np_en_pmu_en_deb_END (3)
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_np_pmu_en_neg_deb_sel_START (4)
#define COMMON_PMIC_NP_PMU_EN_DEB_CTRL_np_pmu_en_neg_deb_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_rc_clk_en_n : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_NP_RC256K_CTRL_UNION;
#endif
#define COMMON_PMIC_NP_RC256K_CTRL_np_rc_clk_en_n_START (0)
#define COMMON_PMIC_NP_RC256K_CTRL_np_rc_clk_en_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_spmi_data_ds : 2;
        unsigned char np_spmi_data_ds_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_DATA_IO_DS0_UNION;
#endif
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_START (0)
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_END (1)
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_sel_START (2)
#define COMMON_PMIC_NP_DATA_IO_DS0_np_spmi_data_ds_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmu_irq_n_ds : 2;
        unsigned char reserved_0 : 2;
        unsigned char reserved_1 : 2;
        unsigned char reserved_2 : 2;
    } reg;
} COMMON_PMIC_NP_DATA_IO_DS1_UNION;
#endif
#define COMMON_PMIC_NP_DATA_IO_DS1_np_pmu_irq_n_ds_START (0)
#define COMMON_PMIC_NP_DATA_IO_DS1_np_pmu_irq_n_ds_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_efuse_read_mux : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_NP_EFUSE_READ_SEL_UNION;
#endif
#define COMMON_PMIC_NP_EFUSE_READ_SEL_np_efuse_read_mux_START (0)
#define COMMON_PMIC_NP_EFUSE_READ_SEL_np_efuse_read_mux_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_dtest_sel : 8;
    } reg;
} COMMON_PMIC_NP_DTEST_SEL_UNION;
#endif
#define COMMON_PMIC_NP_DTEST_SEL_np_dtest_sel_START (0)
#define COMMON_PMIC_NP_DTEST_SEL_np_dtest_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_vsys_pwroff_abs_set : 3;
        unsigned char np_vsys_ov_set : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_NP_SYS_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_pwroff_abs_set_START (0)
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_pwroff_abs_set_END (2)
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_ov_set_START (3)
#define COMMON_PMIC_NP_SYS_CTRL0_np_vsys_ov_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reserved_0 : 2;
        unsigned char np_pmud_res_sel : 2;
        unsigned char np_pmud_buck_en : 1;
        unsigned char np_pmud_vsys_ctrl : 1;
        unsigned char reserved_1 : 2;
    } reg;
} COMMON_PMIC_NP_PMUD_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_res_sel_START (2)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_res_sel_END (3)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_buck_en_START (4)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_buck_en_END (4)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_vsys_ctrl_START (5)
#define COMMON_PMIC_NP_PMUD_CTRL0_np_pmud_vsys_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_pmud_vset : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_PMUD_VSET_UNION;
#endif
#define COMMON_PMIC_NP_PMUD_VSET_np_pmud_vset_START (0)
#define COMMON_PMIC_NP_PMUD_VSET_np_pmud_vset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_en_sst_end_shield : 1;
        unsigned char np_ref_eco_shield : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_REF_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_REF_CTRL0_np_ref_en_sst_end_shield_START (0)
#define COMMON_PMIC_NP_REF_CTRL0_np_ref_en_sst_end_shield_END (0)
#define COMMON_PMIC_NP_REF_CTRL0_np_ref_eco_shield_START (1)
#define COMMON_PMIC_NP_REF_CTRL0_np_ref_eco_shield_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_REF_RSV0_UNION;
#endif
#define COMMON_PMIC_NP_REF_RSV0_np_ref_reserve0_START (0)
#define COMMON_PMIC_NP_REF_RSV0_np_ref_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ref_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_REF_RSV1_UNION;
#endif
#define COMMON_PMIC_NP_REF_RSV1_np_ref_reserve1_START (0)
#define COMMON_PMIC_NP_REF_RSV1_np_ref_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_lxpd_ctrl : 1;
        unsigned char np_b1_lxpd_duty_ctrl : 1;
        unsigned char np_b1_lxpd_delay_sel : 2;
        unsigned char np_b1_lxpd_pull_ctrl : 1;
        unsigned char np_b1_lxpd_counter_ctrl : 1;
        unsigned char np_b1_offres_sel : 1;
        unsigned char np_b1_offres_ctrl : 1;
    } reg;
} COMMON_PMIC_NP_BUCK1_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_ctrl_START (0)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_ctrl_END (0)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_duty_ctrl_START (1)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_duty_ctrl_END (1)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_delay_sel_START (2)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_delay_sel_END (3)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_pull_ctrl_START (4)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_pull_ctrl_END (4)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_counter_ctrl_START (5)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_lxpd_counter_ctrl_END (5)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_offres_sel_START (6)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_offres_sel_END (6)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_offres_ctrl_START (7)
#define COMMON_PMIC_NP_BUCK1_CTRL0_np_b1_offres_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_buck_noroff_ctrl : 1;
        unsigned char np_b1_adj_clx : 2;
        unsigned char np_b1_xvs_fccm : 1;
        unsigned char np_b1_xvs_irdrop : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_NP_BUCK1_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_buck_noroff_ctrl_START (0)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_buck_noroff_ctrl_END (0)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_adj_clx_START (1)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_adj_clx_END (2)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_xvs_fccm_START (3)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_xvs_fccm_END (3)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_xvs_irdrop_START (4)
#define COMMON_PMIC_NP_BUCK1_CTRL1_np_b1_xvs_irdrop_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK1_RES0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK1_RES0_np_b1_reserve0_START (0)
#define COMMON_PMIC_NP_BUCK1_RES0_np_b1_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b1_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK1_RES1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK1_RES1_np_b1_reserve1_START (0)
#define COMMON_PMIC_NP_BUCK1_RES1_np_b1_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_lxpd_ctrl : 1;
        unsigned char np_b2_lxpd_duty_ctrl : 1;
        unsigned char np_b2_lxpd_delay_sel : 2;
        unsigned char np_b2_lxpd_pull_ctrl : 1;
        unsigned char np_b2_lxpd_counter_ctrl : 1;
        unsigned char np_b2_offres_sel : 1;
        unsigned char np_b2_offres_ctrl : 1;
    } reg;
} COMMON_PMIC_NP_BUCK2_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_ctrl_START (0)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_ctrl_END (0)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_duty_ctrl_START (1)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_duty_ctrl_END (1)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_delay_sel_START (2)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_delay_sel_END (3)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_pull_ctrl_START (4)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_pull_ctrl_END (4)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_counter_ctrl_START (5)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_lxpd_counter_ctrl_END (5)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_offres_sel_START (6)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_offres_sel_END (6)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_offres_ctrl_START (7)
#define COMMON_PMIC_NP_BUCK2_CTRL0_np_b2_offres_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_buck_noroff_ctrl : 1;
        unsigned char np_b2_adj_clx : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_BUCK2_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_buck_noroff_ctrl_START (0)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_buck_noroff_ctrl_END (0)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_adj_clx_START (1)
#define COMMON_PMIC_NP_BUCK2_CTRL1_np_b2_adj_clx_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK2_RES0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_RES0_np_b2_reserve0_START (0)
#define COMMON_PMIC_NP_BUCK2_RES0_np_b2_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b2_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK2_RES1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK2_RES1_np_b2_reserve1_START (0)
#define COMMON_PMIC_NP_BUCK2_RES1_np_b2_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_lxpd_ctrl : 1;
        unsigned char np_b3_lxpd_duty_ctrl : 1;
        unsigned char np_b3_lxpd_delay_sel : 2;
        unsigned char np_b3_lxpd_pull_ctrl : 1;
        unsigned char np_b3_lxpd_counter_ctrl : 1;
        unsigned char np_b3_offres_sel : 1;
        unsigned char np_b3_offres_ctrl : 1;
    } reg;
} COMMON_PMIC_NP_BUCK3_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_ctrl_START (0)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_ctrl_END (0)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_duty_ctrl_START (1)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_duty_ctrl_END (1)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_delay_sel_START (2)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_delay_sel_END (3)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_pull_ctrl_START (4)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_pull_ctrl_END (4)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_counter_ctrl_START (5)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_lxpd_counter_ctrl_END (5)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_offres_sel_START (6)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_offres_sel_END (6)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_offres_ctrl_START (7)
#define COMMON_PMIC_NP_BUCK3_CTRL0_np_b3_offres_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_buck_noroff_ctrl : 1;
        unsigned char np_b3_adj_clx : 2;
        unsigned char np_b3_da_out_adj : 1;
        unsigned char np_b3_da_enh_hvo : 1;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_NP_BUCK3_CTRL1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_buck_noroff_ctrl_START (0)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_buck_noroff_ctrl_END (0)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_adj_clx_START (1)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_adj_clx_END (2)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_da_out_adj_START (3)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_da_out_adj_END (3)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_da_enh_hvo_START (4)
#define COMMON_PMIC_NP_BUCK3_CTRL1_np_b3_da_enh_hvo_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK3_RES0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_RES0_np_b3_reserve0_START (0)
#define COMMON_PMIC_NP_BUCK3_RES0_np_b3_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_b3_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK3_RES1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK3_RES1_np_b3_reserve1_START (0)
#define COMMON_PMIC_NP_BUCK3_RES1_np_b3_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck_reserve4 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK_RSV0_UNION;
#endif
#define COMMON_PMIC_NP_BUCK_RSV0_np_buck_reserve4_START (0)
#define COMMON_PMIC_NP_BUCK_RSV0_np_buck_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck_reserve5 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK_RSV1_UNION;
#endif
#define COMMON_PMIC_NP_BUCK_RSV1_np_buck_reserve5_START (0)
#define COMMON_PMIC_NP_BUCK_RSV1_np_buck_reserve5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck_reserve6 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK_RSV2_UNION;
#endif
#define COMMON_PMIC_NP_BUCK_RSV2_np_buck_reserve6_START (0)
#define COMMON_PMIC_NP_BUCK_RSV2_np_buck_reserve6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_buck_reserve7 : 8;
    } reg;
} COMMON_PMIC_NP_BUCK_RSV3_UNION;
#endif
#define COMMON_PMIC_NP_BUCK_RSV3_np_buck_reserve7_START (0)
#define COMMON_PMIC_NP_BUCK_RSV3_np_buck_reserve7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo1_pdres_shield : 1;
        unsigned char np_ldo1_pd_set : 1;
        unsigned char np_ldo1_vset_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_LDO1_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO1_CTRL0_np_ldo1_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO1_CTRL0_np_ldo1_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO1_CTRL0_np_ldo1_pd_set_START (1)
#define COMMON_PMIC_NP_LDO1_CTRL0_np_ldo1_pd_set_END (1)
#define COMMON_PMIC_NP_LDO1_CTRL0_np_ldo1_vset_sel_START (2)
#define COMMON_PMIC_NP_LDO1_CTRL0_np_ldo1_vset_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo2_pdres_shield : 1;
        unsigned char np_ldo2_pd_set : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_LDO2_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO2_CTRL0_np_ldo2_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO2_CTRL0_np_ldo2_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO2_CTRL0_np_ldo2_pd_set_START (1)
#define COMMON_PMIC_NP_LDO2_CTRL0_np_ldo2_pd_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo3_pdres_shield : 1;
        unsigned char np_ldo3_pd_set : 1;
        unsigned char np_ldo3_vset_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_LDO3_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO3_CTRL0_np_ldo3_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO3_CTRL0_np_ldo3_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO3_CTRL0_np_ldo3_pd_set_START (1)
#define COMMON_PMIC_NP_LDO3_CTRL0_np_ldo3_pd_set_END (1)
#define COMMON_PMIC_NP_LDO3_CTRL0_np_ldo3_vset_sel_START (2)
#define COMMON_PMIC_NP_LDO3_CTRL0_np_ldo3_vset_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo4_pdres_shield : 1;
        unsigned char np_ldo4_pd_set : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_LDO4_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO4_CTRL0_np_ldo4_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO4_CTRL0_np_ldo4_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO4_CTRL0_np_ldo4_pd_set_START (1)
#define COMMON_PMIC_NP_LDO4_CTRL0_np_ldo4_pd_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo5_pdres_shield : 1;
        unsigned char np_ldo5_pd_set : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_LDO5_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO5_CTRL0_np_ldo5_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO5_CTRL0_np_ldo5_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO5_CTRL0_np_ldo5_pd_set_START (1)
#define COMMON_PMIC_NP_LDO5_CTRL0_np_ldo5_pd_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo6_pdres_shield : 1;
        unsigned char np_ldo6_pd_set : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_LDO6_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO6_CTRL0_np_ldo6_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO6_CTRL0_np_ldo6_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO6_CTRL0_np_ldo6_pd_set_START (1)
#define COMMON_PMIC_NP_LDO6_CTRL0_np_ldo6_pd_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo7_pdres_shield : 1;
        unsigned char np_ldo7_pd_set : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_LDO7_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO7_CTRL0_np_ldo7_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO7_CTRL0_np_ldo7_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO7_CTRL0_np_ldo7_pd_set_START (1)
#define COMMON_PMIC_NP_LDO7_CTRL0_np_ldo7_pd_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo8_pdres_shield : 1;
        unsigned char np_ldo8_pd_set : 1;
        unsigned char np_ldo8_vset_sel : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_LDO8_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO8_CTRL0_np_ldo8_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO8_CTRL0_np_ldo8_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO8_CTRL0_np_ldo8_pd_set_START (1)
#define COMMON_PMIC_NP_LDO8_CTRL0_np_ldo8_pd_set_END (1)
#define COMMON_PMIC_NP_LDO8_CTRL0_np_ldo8_vset_sel_START (2)
#define COMMON_PMIC_NP_LDO8_CTRL0_np_ldo8_vset_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo9_pdres_shield : 1;
        unsigned char np_ldo9_pd_set : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_NP_LDO9_CTRL0_UNION;
#endif
#define COMMON_PMIC_NP_LDO9_CTRL0_np_ldo9_pdres_shield_START (0)
#define COMMON_PMIC_NP_LDO9_CTRL0_np_ldo9_pdres_shield_END (0)
#define COMMON_PMIC_NP_LDO9_CTRL0_np_ldo9_pd_set_START (1)
#define COMMON_PMIC_NP_LDO9_CTRL0_np_ldo9_pd_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_LDO_RSV0_UNION;
#endif
#define COMMON_PMIC_NP_LDO_RSV0_np_ldo_reserve0_START (0)
#define COMMON_PMIC_NP_LDO_RSV0_np_ldo_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_ldo_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_LDO_RSV1_UNION;
#endif
#define COMMON_PMIC_NP_LDO_RSV1_np_ldo_reserve1_START (0)
#define COMMON_PMIC_NP_LDO_RSV1_np_ldo_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve0 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES0_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES0_np_d2a_reserve0_START (0)
#define COMMON_PMIC_NP_D2A_RES0_np_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve1 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES1_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES1_np_d2a_reserve1_START (0)
#define COMMON_PMIC_NP_D2A_RES1_np_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve2 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES2_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES2_np_d2a_reserve2_START (0)
#define COMMON_PMIC_NP_D2A_RES2_np_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve3 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES3_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES3_np_d2a_reserve3_START (0)
#define COMMON_PMIC_NP_D2A_RES3_np_d2a_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_d2a_reserve4 : 8;
    } reg;
} COMMON_PMIC_NP_D2A_RES4_UNION;
#endif
#define COMMON_PMIC_NP_D2A_RES4_np_d2a_reserve4_START (0)
#define COMMON_PMIC_NP_D2A_RES4_np_d2a_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_debug_lock : 8;
    } reg;
} COMMON_PMIC_NP_DEBUG_LOCK_UNION;
#endif
#define COMMON_PMIC_NP_DEBUG_LOCK_np_debug_lock_START (0)
#define COMMON_PMIC_NP_DEBUG_LOCK_np_debug_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_sys_debug0 : 8;
    } reg;
} COMMON_PMIC_NP_SYS_DEBUG0_UNION;
#endif
#define COMMON_PMIC_NP_SYS_DEBUG0_np_sys_debug0_START (0)
#define COMMON_PMIC_NP_SYS_DEBUG0_np_sys_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_sys_debug1 : 8;
    } reg;
} COMMON_PMIC_NP_SYS_DEBUG1_UNION;
#endif
#define COMMON_PMIC_NP_SYS_DEBUG1_np_sys_debug1_START (0)
#define COMMON_PMIC_NP_SYS_DEBUG1_np_sys_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_rc256k_debug : 1;
        unsigned char np_rc9m6_debug : 1;
        unsigned char np_ferclk_debug : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_NP_SYS_DEBUG2_UNION;
#endif
#define COMMON_PMIC_NP_SYS_DEBUG2_np_rc256k_debug_START (0)
#define COMMON_PMIC_NP_SYS_DEBUG2_np_rc256k_debug_END (0)
#define COMMON_PMIC_NP_SYS_DEBUG2_np_rc9m6_debug_START (1)
#define COMMON_PMIC_NP_SYS_DEBUG2_np_rc9m6_debug_END (1)
#define COMMON_PMIC_NP_SYS_DEBUG2_np_ferclk_debug_START (2)
#define COMMON_PMIC_NP_SYS_DEBUG2_np_ferclk_debug_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg0 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG0_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG0_np_hrst_reg0_START (0)
#define COMMON_PMIC_NP_HRST_REG0_np_hrst_reg0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg1 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG1_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG1_np_hrst_reg1_START (0)
#define COMMON_PMIC_NP_HRST_REG1_np_hrst_reg1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg2 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG2_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG2_np_hrst_reg2_START (0)
#define COMMON_PMIC_NP_HRST_REG2_np_hrst_reg2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char np_hrst_reg3 : 8;
    } reg;
} COMMON_PMIC_NP_HRST_REG3_UNION;
#endif
#define COMMON_PMIC_NP_HRST_REG3_np_hrst_reg3_START (0)
#define COMMON_PMIC_NP_HRST_REG3_np_hrst_reg3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_chop_buf_en : 1;
        unsigned char ref_1per_ibias_res : 6;
        unsigned char clb_cur_sel : 1;
    } reg;
} COMMON_PMIC_REF_CFG0_UNION;
#endif
#define COMMON_PMIC_REF_CFG0_ref_chop_buf_en_START (0)
#define COMMON_PMIC_REF_CFG0_ref_chop_buf_en_END (0)
#define COMMON_PMIC_REF_CFG0_ref_1per_ibias_res_START (1)
#define COMMON_PMIC_REF_CFG0_ref_1per_ibias_res_END (6)
#define COMMON_PMIC_REF_CFG0_clb_cur_sel_START (7)
#define COMMON_PMIC_REF_CFG0_clb_cur_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_res_sel_cfg : 1;
        unsigned char ref_rc_sel : 1;
        unsigned char ref_en_thsd_code : 1;
        unsigned char ref_chop_sel : 1;
        unsigned char ref_chop_clk_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_REF_CFG1_UNION;
#endif
#define COMMON_PMIC_REF_CFG1_ref_res_sel_cfg_START (0)
#define COMMON_PMIC_REF_CFG1_ref_res_sel_cfg_END (0)
#define COMMON_PMIC_REF_CFG1_ref_rc_sel_START (1)
#define COMMON_PMIC_REF_CFG1_ref_rc_sel_END (1)
#define COMMON_PMIC_REF_CFG1_ref_en_thsd_code_START (2)
#define COMMON_PMIC_REF_CFG1_ref_en_thsd_code_END (2)
#define COMMON_PMIC_REF_CFG1_ref_chop_sel_START (3)
#define COMMON_PMIC_REF_CFG1_ref_chop_sel_END (3)
#define COMMON_PMIC_REF_CFG1_ref_chop_clk_sel_START (4)
#define COMMON_PMIC_REF_CFG1_ref_chop_clk_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_ibias_sel : 1;
        unsigned char ref_ibias_trim_en : 2;
        unsigned char ref_out_sel : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_REF_CFG2_UNION;
#endif
#define COMMON_PMIC_REF_CFG2_ref_ibias_sel_START (0)
#define COMMON_PMIC_REF_CFG2_ref_ibias_sel_END (0)
#define COMMON_PMIC_REF_CFG2_ref_ibias_trim_en_START (1)
#define COMMON_PMIC_REF_CFG2_ref_ibias_trim_en_END (2)
#define COMMON_PMIC_REF_CFG2_ref_out_sel_START (3)
#define COMMON_PMIC_REF_CFG2_ref_out_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char tsensor_temp_sel : 2;
        unsigned char thsd_tmp_5c_sel : 1;
        unsigned char thsd_bg_sel : 1;
        unsigned char thsd_140c_sel : 2;
        unsigned char ref_vptat_sel : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_REF_CFG3_UNION;
#endif
#define COMMON_PMIC_REF_CFG3_tsensor_temp_sel_START (0)
#define COMMON_PMIC_REF_CFG3_tsensor_temp_sel_END (1)
#define COMMON_PMIC_REF_CFG3_thsd_tmp_5c_sel_START (2)
#define COMMON_PMIC_REF_CFG3_thsd_tmp_5c_sel_END (2)
#define COMMON_PMIC_REF_CFG3_thsd_bg_sel_START (3)
#define COMMON_PMIC_REF_CFG3_thsd_bg_sel_END (3)
#define COMMON_PMIC_REF_CFG3_thsd_140c_sel_START (4)
#define COMMON_PMIC_REF_CFG3_thsd_140c_sel_END (5)
#define COMMON_PMIC_REF_CFG3_ref_vptat_sel_START (6)
#define COMMON_PMIC_REF_CFG3_ref_vptat_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_reserve0 : 8;
    } reg;
} COMMON_PMIC_REF_RSV0_UNION;
#endif
#define COMMON_PMIC_REF_RSV0_ref_reserve0_START (0)
#define COMMON_PMIC_REF_RSV0_ref_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ref_reserve1 : 8;
    } reg;
} COMMON_PMIC_REF_RSV1_UNION;
#endif
#define COMMON_PMIC_REF_RSV1_ref_reserve1_START (0)
#define COMMON_PMIC_REF_RSV1_ref_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char osc_9m6_sel : 8;
    } reg;
} COMMON_PMIC_OSC_9M6_CFG0_UNION;
#endif
#define COMMON_PMIC_OSC_9M6_CFG0_osc_9m6_sel_START (0)
#define COMMON_PMIC_OSC_9M6_CFG0_osc_9m6_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sys_ctrl_reserve0 : 8;
    } reg;
} COMMON_PMIC_SYS_CTRL_CFG0_UNION;
#endif
#define COMMON_PMIC_SYS_CTRL_CFG0_sys_ctrl_reserve0_START (0)
#define COMMON_PMIC_SYS_CTRL_CFG0_sys_ctrl_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char sys_ctrl_reserve1 : 8;
    } reg;
} COMMON_PMIC_SYS_CTRL_CFG1_UNION;
#endif
#define COMMON_PMIC_SYS_CTRL_CFG1_sys_ctrl_reserve1_START (0)
#define COMMON_PMIC_SYS_CTRL_CFG1_sys_ctrl_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_negcur_en : 1;
        unsigned char b1_dmd_cmp_sel_nor : 1;
        unsigned char b1_dmd_cmp_sel_neg : 1;
        unsigned char b1_dmd_cmp_sel_eco : 1;
        unsigned char b1_dmd_blanking_sel : 1;
        unsigned char b1_dmd_bias_shield_nor : 1;
        unsigned char b1_dmd_bias_shield_eco : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_negcur_en_START (0)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_negcur_en_END (0)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_cmp_sel_nor_START (1)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_cmp_sel_nor_END (1)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_cmp_sel_neg_START (2)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_cmp_sel_neg_END (2)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_cmp_sel_eco_START (3)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_cmp_sel_eco_END (3)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_blanking_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_blanking_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_bias_shield_nor_START (5)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_bias_shield_nor_END (5)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_bias_shield_eco_START (6)
#define COMMON_PMIC_BUCK1_CFG0_b1_dmd_bias_shield_eco_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_reten_sel : 1;
        unsigned char b1_dmd_pwmn_shield : 1;
        unsigned char b1_dmd_negcur_sel : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BUCK1_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_reten_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_reten_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_pwmn_shield_START (1)
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_pwmn_shield_END (1)
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_negcur_sel_START (2)
#define COMMON_PMIC_BUCK1_CFG1_b1_dmd_negcur_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_sel_eco : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG2_b1_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK1_CFG2_b1_dmd_sel_eco_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmdcmp_pull : 1;
        unsigned char b1_dmd_test_ctrl : 1;
        unsigned char b1_dmd_test : 1;
        unsigned char b1_dmd_sel_nor : 5;
    } reg;
} COMMON_PMIC_BUCK1_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG3_b1_dmdcmp_pull_START (0)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmdcmp_pull_END (0)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_test_ctrl_START (1)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_test_ctrl_END (1)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_test_START (2)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_test_END (2)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_sel_nor_START (3)
#define COMMON_PMIC_BUCK1_CFG3_b1_dmd_sel_nor_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_pwr_drvnonlinear_ctrl : 1;
        unsigned char b1_pwr_drvngp_sel : 3;
        unsigned char b1_pwr_drvngn_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG4_b1_pwr_drvnonlinear_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG4_b1_pwr_drvnonlinear_ctrl_END (0)
#define COMMON_PMIC_BUCK1_CFG4_b1_pwr_drvngp_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG4_b1_pwr_drvngp_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG4_b1_pwr_drvngn_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG4_b1_pwr_drvngn_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_pwr_drvpgp_ccm_sel : 3;
        unsigned char b1_pwr_drvpgn_sel : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG5_b1_pwr_drvpgp_ccm_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG5_b1_pwr_drvpgp_ccm_sel_END (2)
#define COMMON_PMIC_BUCK1_CFG5_b1_pwr_drvpgn_sel_START (3)
#define COMMON_PMIC_BUCK1_CFG5_b1_pwr_drvpgn_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_pwr_dtp2n_delay_ctrl : 1;
        unsigned char b1_pwr_dtn2p_sel : 2;
        unsigned char b1_pwr_dtn2p_delay_ctrl : 1;
        unsigned char b1_pwr_dt_offlatch_sel : 1;
        unsigned char b1_pwr_drvpgp_dcm_sel : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dtp2n_delay_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dtp2n_delay_ctrl_END (0)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dtn2p_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dtn2p_sel_END (2)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dtn2p_delay_ctrl_START (3)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dtn2p_delay_ctrl_END (3)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dt_offlatch_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_dt_offlatch_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_drvpgp_dcm_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG6_b1_pwr_drvpgp_dcm_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_pwr_dtp2n_sel : 2;
        unsigned char b1_pwr_dtp2n_lxdet_ctrl : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK1_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG7_b1_pwr_dtp2n_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG7_b1_pwr_dtp2n_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG7_b1_pwr_dtp2n_lxdet_ctrl_START (2)
#define COMMON_PMIC_BUCK1_CFG7_b1_pwr_dtp2n_lxdet_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ramp_cap_shield : 1;
        unsigned char b1_ramp_cap_sel : 2;
        unsigned char b1_adj_rlx : 5;
    } reg;
} COMMON_PMIC_BUCK1_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG8_b1_ramp_cap_shield_START (0)
#define COMMON_PMIC_BUCK1_CFG8_b1_ramp_cap_shield_END (0)
#define COMMON_PMIC_BUCK1_CFG8_b1_ramp_cap_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG8_b1_ramp_cap_sel_END (2)
#define COMMON_PMIC_BUCK1_CFG8_b1_adj_rlx_START (3)
#define COMMON_PMIC_BUCK1_CFG8_b1_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_vofb_cap_sel : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK1_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG9_b1_vofb_cap_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG9_b1_vofb_cap_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_cmp_add_0p5u : 1;
        unsigned char b1_bias_reg_sel : 1;
        unsigned char b1_bias_ocp_sel : 3;
        unsigned char b1_bias_dmd_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG10_b1_cmp_add_0p5u_START (0)
#define COMMON_PMIC_BUCK1_CFG10_b1_cmp_add_0p5u_END (0)
#define COMMON_PMIC_BUCK1_CFG10_b1_bias_reg_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG10_b1_bias_reg_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG10_b1_bias_ocp_sel_START (2)
#define COMMON_PMIC_BUCK1_CFG10_b1_bias_ocp_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG10_b1_bias_dmd_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG10_b1_bias_dmd_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_ib_reduce_eco : 1;
        unsigned char b1_dmd_eco_cur : 1;
        unsigned char b1_cmp_ibias_volow : 1;
        unsigned char b1_cmp_eco_sel : 1;
        unsigned char b1_cmp_bias : 4;
    } reg;
} COMMON_PMIC_BUCK1_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG11_b1_dmd_ib_reduce_eco_START (0)
#define COMMON_PMIC_BUCK1_CFG11_b1_dmd_ib_reduce_eco_END (0)
#define COMMON_PMIC_BUCK1_CFG11_b1_dmd_eco_cur_START (1)
#define COMMON_PMIC_BUCK1_CFG11_b1_dmd_eco_cur_END (1)
#define COMMON_PMIC_BUCK1_CFG11_b1_cmp_ibias_volow_START (2)
#define COMMON_PMIC_BUCK1_CFG11_b1_cmp_ibias_volow_END (2)
#define COMMON_PMIC_BUCK1_CFG11_b1_cmp_eco_sel_START (3)
#define COMMON_PMIC_BUCK1_CFG11_b1_cmp_eco_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG11_b1_cmp_bias_START (4)
#define COMMON_PMIC_BUCK1_CFG11_b1_cmp_bias_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_rampamp_ibias_sel : 1;
        unsigned char b1_eco_i_sel : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK1_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG12_b1_rampamp_ibias_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG12_b1_rampamp_ibias_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG12_b1_eco_i_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG12_b1_eco_i_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_test_sel : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK1_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG13_b1_test_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG13_b1_test_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_rampup_unitgain : 1;
        unsigned char b1_rampdn_unitgain : 1;
        unsigned char b1_low_reg_r_ctrl : 1;
        unsigned char b1_ibias_noise_ctrl : 1;
        unsigned char b1_eabias_sel : 1;
        unsigned char b1_ampbias_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG14_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG14_b1_rampup_unitgain_START (0)
#define COMMON_PMIC_BUCK1_CFG14_b1_rampup_unitgain_END (0)
#define COMMON_PMIC_BUCK1_CFG14_b1_rampdn_unitgain_START (1)
#define COMMON_PMIC_BUCK1_CFG14_b1_rampdn_unitgain_END (1)
#define COMMON_PMIC_BUCK1_CFG14_b1_low_reg_r_ctrl_START (2)
#define COMMON_PMIC_BUCK1_CFG14_b1_low_reg_r_ctrl_END (2)
#define COMMON_PMIC_BUCK1_CFG14_b1_ibias_noise_ctrl_START (3)
#define COMMON_PMIC_BUCK1_CFG14_b1_ibias_noise_ctrl_END (3)
#define COMMON_PMIC_BUCK1_CFG14_b1_eabias_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG14_b1_eabias_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG14_b1_ampbias_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG14_b1_ampbias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reg_en : 1;
        unsigned char b1_reg_dr_ramp : 3;
        unsigned char b1_reg_dr : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG15_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG15_b1_reg_en_START (0)
#define COMMON_PMIC_BUCK1_CFG15_b1_reg_en_END (0)
#define COMMON_PMIC_BUCK1_CFG15_b1_reg_dr_ramp_START (1)
#define COMMON_PMIC_BUCK1_CFG15_b1_reg_dr_ramp_END (3)
#define COMMON_PMIC_BUCK1_CFG15_b1_reg_dr_START (4)
#define COMMON_PMIC_BUCK1_CFG15_b1_reg_dr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_regout_c_sel : 1;
        unsigned char b1_regop_c : 1;
        unsigned char b1_reg_zero_en : 1;
        unsigned char b1_reg_r : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG16_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG16_b1_regout_c_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG16_b1_regout_c_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG16_b1_regop_c_START (1)
#define COMMON_PMIC_BUCK1_CFG16_b1_regop_c_END (1)
#define COMMON_PMIC_BUCK1_CFG16_b1_reg_zero_en_START (2)
#define COMMON_PMIC_BUCK1_CFG16_b1_reg_zero_en_END (2)
#define COMMON_PMIC_BUCK1_CFG16_b1_reg_r_START (3)
#define COMMON_PMIC_BUCK1_CFG16_b1_reg_r_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_diff_vo_c : 4;
        unsigned char b1_da_constant_sft_sel : 1;
        unsigned char b1_da_buffer_bias_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG17_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG17_b1_da_diff_vo_c_START (0)
#define COMMON_PMIC_BUCK1_CFG17_b1_da_diff_vo_c_END (3)
#define COMMON_PMIC_BUCK1_CFG17_b1_da_constant_sft_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG17_b1_da_constant_sft_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG17_b1_da_buffer_bias_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG17_b1_da_buffer_bias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_diff_vo_r_base : 2;
        unsigned char b1_da_diff_vo_r : 3;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG18_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG18_b1_da_diff_vo_r_base_START (0)
#define COMMON_PMIC_BUCK1_CFG18_b1_da_diff_vo_r_base_END (1)
#define COMMON_PMIC_BUCK1_CFG18_b1_da_diff_vo_r_START (2)
#define COMMON_PMIC_BUCK1_CFG18_b1_da_diff_vo_r_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_diff_vref_r : 3;
        unsigned char b1_da_diff_vref_c : 4;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG19_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG19_b1_da_diff_vref_r_START (0)
#define COMMON_PMIC_BUCK1_CFG19_b1_da_diff_vref_r_END (2)
#define COMMON_PMIC_BUCK1_CFG19_b1_da_diff_vref_c_START (3)
#define COMMON_PMIC_BUCK1_CFG19_b1_da_diff_vref_c_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_ramp_buff_bias : 2;
        unsigned char b1_da_diff_vref_rset : 3;
        unsigned char b1_da_diff_vref_r_ramp : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG20_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG20_b1_da_ramp_buff_bias_START (0)
#define COMMON_PMIC_BUCK1_CFG20_b1_da_ramp_buff_bias_END (1)
#define COMMON_PMIC_BUCK1_CFG20_b1_da_diff_vref_rset_START (2)
#define COMMON_PMIC_BUCK1_CFG20_b1_da_diff_vref_rset_END (4)
#define COMMON_PMIC_BUCK1_CFG20_b1_da_diff_vref_r_ramp_START (5)
#define COMMON_PMIC_BUCK1_CFG20_b1_da_diff_vref_r_ramp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_rtr_cap_sel : 4;
        unsigned char b1_da_rampres_trim_ctrl : 2;
        unsigned char b1_da_ramp_ecobuffer_ctrl : 1;
        unsigned char b1_da_ramp_eco_ctrl : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG21_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG21_b1_da_rtr_cap_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_rtr_cap_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_rampres_trim_ctrl_START (4)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_rampres_trim_ctrl_END (5)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_ramp_ecobuffer_ctrl_START (6)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_ramp_ecobuffer_ctrl_END (6)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_ramp_eco_ctrl_START (7)
#define COMMON_PMIC_BUCK1_CFG21_b1_da_ramp_eco_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ramp_up_ctrl : 2;
        unsigned char b1_ramp_down_ctrl : 1;
        unsigned char b1_eco_pulse_ctrl : 1;
        unsigned char b1_da_vo_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG22_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG22_b1_ramp_up_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG22_b1_ramp_up_ctrl_END (1)
#define COMMON_PMIC_BUCK1_CFG22_b1_ramp_down_ctrl_START (2)
#define COMMON_PMIC_BUCK1_CFG22_b1_ramp_down_ctrl_END (2)
#define COMMON_PMIC_BUCK1_CFG22_b1_eco_pulse_ctrl_START (3)
#define COMMON_PMIC_BUCK1_CFG22_b1_eco_pulse_ctrl_END (3)
#define COMMON_PMIC_BUCK1_CFG22_b1_da_vo_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG22_b1_da_vo_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_rampstate_syn_ctrl : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK1_CFG23_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG23_b1_rampstate_syn_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG23_b1_rampstate_syn_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_cmp_tailbias_sel : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG24_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG24_b1_cmp_tailbias_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG24_b1_cmp_tailbias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ocp_sel : 2;
        unsigned char b1_ocp_middrv_sel : 2;
        unsigned char b1_ocp_middrv_ctrl : 1;
        unsigned char b1_ocp_delay : 1;
        unsigned char b1_ocp_counter_sel : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG25_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_middrv_sel_START (2)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_middrv_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_middrv_ctrl_START (4)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_middrv_ctrl_END (4)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_delay_START (5)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_delay_END (5)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_counter_sel_START (6)
#define COMMON_PMIC_BUCK1_CFG25_b1_ocp_counter_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_uv2p3_shield : 1;
        unsigned char b1_ramp_ocp_shield : 1;
        unsigned char b1_pocp_offset_trim_en : 2;
        unsigned char b1_ocpblanktime_sel : 1;
        unsigned char b1_ocpbias_ctrl : 1;
        unsigned char b1_ocp_toff : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG26_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG26_b1_uv2p3_shield_START (0)
#define COMMON_PMIC_BUCK1_CFG26_b1_uv2p3_shield_END (0)
#define COMMON_PMIC_BUCK1_CFG26_b1_ramp_ocp_shield_START (1)
#define COMMON_PMIC_BUCK1_CFG26_b1_ramp_ocp_shield_END (1)
#define COMMON_PMIC_BUCK1_CFG26_b1_pocp_offset_trim_en_START (2)
#define COMMON_PMIC_BUCK1_CFG26_b1_pocp_offset_trim_en_END (3)
#define COMMON_PMIC_BUCK1_CFG26_b1_ocpblanktime_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG26_b1_ocpblanktime_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG26_b1_ocpbias_ctrl_START (5)
#define COMMON_PMIC_BUCK1_CFG26_b1_ocpbias_ctrl_END (5)
#define COMMON_PMIC_BUCK1_CFG26_b1_ocp_toff_START (6)
#define COMMON_PMIC_BUCK1_CFG26_b1_ocp_toff_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_uv3v_ocpcut_sel : 1;
        unsigned char b1_short_ref_ctrl : 1;
        unsigned char b1_vo_range_sel : 1;
        unsigned char b1_code_vo_sel : 1;
        unsigned char b1_soft_pull_test_sel : 1;
        unsigned char b1_regen_ctrl : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG27_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG27_b1_uv3v_ocpcut_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG27_b1_uv3v_ocpcut_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG27_b1_short_ref_ctrl_START (1)
#define COMMON_PMIC_BUCK1_CFG27_b1_short_ref_ctrl_END (1)
#define COMMON_PMIC_BUCK1_CFG27_b1_vo_range_sel_START (2)
#define COMMON_PMIC_BUCK1_CFG27_b1_vo_range_sel_END (2)
#define COMMON_PMIC_BUCK1_CFG27_b1_code_vo_sel_START (3)
#define COMMON_PMIC_BUCK1_CFG27_b1_code_vo_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG27_b1_soft_pull_test_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG27_b1_soft_pull_test_sel_END (4)
#define COMMON_PMIC_BUCK1_CFG27_b1_regen_ctrl_START (5)
#define COMMON_PMIC_BUCK1_CFG27_b1_regen_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_dmd_ton : 3;
        unsigned char b1_dmd_off_ctrl : 1;
        unsigned char b1_dmd_bias_en_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG28_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG28_b1_dmd_ton_START (0)
#define COMMON_PMIC_BUCK1_CFG28_b1_dmd_ton_END (2)
#define COMMON_PMIC_BUCK1_CFG28_b1_dmd_off_ctrl_START (3)
#define COMMON_PMIC_BUCK1_CFG28_b1_dmd_off_ctrl_END (3)
#define COMMON_PMIC_BUCK1_CFG28_b1_dmd_bias_en_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG28_b1_dmd_bias_en_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_no_dmd_ton : 3;
        unsigned char b1_eco_maxton_sel : 1;
        unsigned char b1_dmd_ton_shield : 1;
        unsigned char b1_dmd_ton_negcur : 3;
    } reg;
} COMMON_PMIC_BUCK1_CFG29_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG29_b1_no_dmd_ton_START (0)
#define COMMON_PMIC_BUCK1_CFG29_b1_no_dmd_ton_END (2)
#define COMMON_PMIC_BUCK1_CFG29_b1_eco_maxton_sel_START (3)
#define COMMON_PMIC_BUCK1_CFG29_b1_eco_maxton_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG29_b1_dmd_ton_shield_START (4)
#define COMMON_PMIC_BUCK1_CFG29_b1_dmd_ton_shield_END (4)
#define COMMON_PMIC_BUCK1_CFG29_b1_dmd_ton_negcur_START (5)
#define COMMON_PMIC_BUCK1_CFG29_b1_dmd_ton_negcur_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_ton_cap_sel : 1;
        unsigned char b1_toff_sel : 1;
        unsigned char b1_ssend_cot_dis : 1;
        unsigned char b1_sel_min_ton : 1;
        unsigned char b1_ramp_sel : 2;
        unsigned char b1_ramp_ctrl_ton : 1;
        unsigned char b1_ocpsens_ctrl : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG30_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG30_b1_ton_cap_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG30_b1_ton_cap_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG30_b1_toff_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG30_b1_toff_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG30_b1_ssend_cot_dis_START (2)
#define COMMON_PMIC_BUCK1_CFG30_b1_ssend_cot_dis_END (2)
#define COMMON_PMIC_BUCK1_CFG30_b1_sel_min_ton_START (3)
#define COMMON_PMIC_BUCK1_CFG30_b1_sel_min_ton_END (3)
#define COMMON_PMIC_BUCK1_CFG30_b1_ramp_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG30_b1_ramp_sel_END (5)
#define COMMON_PMIC_BUCK1_CFG30_b1_ramp_ctrl_ton_START (6)
#define COMMON_PMIC_BUCK1_CFG30_b1_ramp_ctrl_ton_END (6)
#define COMMON_PMIC_BUCK1_CFG30_b1_ocpsens_ctrl_START (7)
#define COMMON_PMIC_BUCK1_CFG30_b1_ocpsens_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_toncap_ctrl : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK1_CFG31_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG31_b1_toncap_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG31_b1_toncap_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_loadline_ith_sel : 1;
        unsigned char b1_da_loadline_injpn_sel : 1;
        unsigned char b1_da_loadline_imax_set : 3;
        unsigned char b1_da_loadline_en_dig : 1;
        unsigned char b1_da_loadline_curr_ctrl : 1;
        unsigned char b1_da_loadline_atest : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG32_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_ith_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_ith_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_injpn_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_injpn_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_imax_set_START (2)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_imax_set_END (4)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_en_dig_START (5)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_en_dig_END (5)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_curr_ctrl_START (6)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_curr_ctrl_END (6)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_atest_START (7)
#define COMMON_PMIC_BUCK1_CFG32_b1_da_loadline_atest_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_da_loadline_vocfg_sel : 1;
        unsigned char b1_da_loadline_trim_sel : 1;
        unsigned char b1_da_loadline_set_t : 3;
        unsigned char b1_da_loadline_ramp_enable_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK1_CFG33_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_vocfg_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_vocfg_sel_END (0)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_trim_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_trim_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_set_t_START (2)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_set_t_END (4)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_ramp_enable_sel_START (5)
#define COMMON_PMIC_BUCK1_CFG33_b1_da_loadline_ramp_enable_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_crtsense_en : 1;
        unsigned char b1_crtsense_chpp_ctrl : 1;
        unsigned char b1_crtsense_chpp_clk_sel : 2;
        unsigned char b1_crtsense_avgcurr_filter_sel : 3;
        unsigned char b1_crtsense_atest : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG34_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_en_START (0)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_en_END (0)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_chpp_ctrl_START (1)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_chpp_ctrl_END (1)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_chpp_clk_sel_START (2)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_chpp_clk_sel_END (3)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_avgcurr_filter_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_avgcurr_filter_sel_END (6)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_atest_START (7)
#define COMMON_PMIC_BUCK1_CFG34_b1_crtsense_atest_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_crtsense_ratio_sel : 2;
        unsigned char b1_crtsense_pen : 1;
        unsigned char b1_crtsense_nen : 1;
        unsigned char b1_crtsense_gm_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK1_CFG35_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_ratio_sel_START (0)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_ratio_sel_END (1)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_pen_START (2)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_pen_END (2)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_nen_START (3)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_nen_END (3)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_gm_sel_START (4)
#define COMMON_PMIC_BUCK1_CFG35_b1_crtsense_gm_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_crtsense_swcs_filter_ctrl : 1;
        unsigned char b1_crtsense_res_sel : 3;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BUCK1_CFG36_UNION;
#endif
#define COMMON_PMIC_BUCK1_CFG36_b1_crtsense_swcs_filter_ctrl_START (0)
#define COMMON_PMIC_BUCK1_CFG36_b1_crtsense_swcs_filter_ctrl_END (0)
#define COMMON_PMIC_BUCK1_CFG36_b1_crtsense_res_sel_START (1)
#define COMMON_PMIC_BUCK1_CFG36_b1_crtsense_res_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK1_RSV_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK1_RSV_CFG0_b1_reserve0_START (0)
#define COMMON_PMIC_BUCK1_RSV_CFG0_b1_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK1_RSV_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK1_RSV_CFG1_b1_reserve1_START (0)
#define COMMON_PMIC_BUCK1_RSV_CFG1_b1_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_a2d_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK1_A2D_RSV0_UNION;
#endif
#define COMMON_PMIC_BUCK1_A2D_RSV0_b1_a2d_reserve0_START (0)
#define COMMON_PMIC_BUCK1_A2D_RSV0_b1_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b1_a2d_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK1_A2D_RSV1_UNION;
#endif
#define COMMON_PMIC_BUCK1_A2D_RSV1_b1_a2d_reserve1_START (0)
#define COMMON_PMIC_BUCK1_A2D_RSV1_b1_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_negcur_en : 1;
        unsigned char b2_dmd_cmp_sel_nor : 1;
        unsigned char b2_dmd_cmp_sel_neg : 1;
        unsigned char b2_dmd_cmp_sel_eco : 1;
        unsigned char b2_dmd_blanking_sel : 1;
        unsigned char b2_dmd_bias_shield_nor : 1;
        unsigned char b2_dmd_bias_shield_eco : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_negcur_en_START (0)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_negcur_en_END (0)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_cmp_sel_nor_START (1)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_cmp_sel_nor_END (1)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_cmp_sel_neg_START (2)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_cmp_sel_neg_END (2)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_cmp_sel_eco_START (3)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_cmp_sel_eco_END (3)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_blanking_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_blanking_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_bias_shield_nor_START (5)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_bias_shield_nor_END (5)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_bias_shield_eco_START (6)
#define COMMON_PMIC_BUCK2_CFG0_b2_dmd_bias_shield_eco_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_reten_sel : 1;
        unsigned char b2_dmd_pwmn_shield : 1;
        unsigned char b2_dmd_negcur_sel : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BUCK2_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_reten_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_reten_sel_END (0)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_pwmn_shield_START (1)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_pwmn_shield_END (1)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_negcur_sel_START (2)
#define COMMON_PMIC_BUCK2_CFG1_b2_dmd_negcur_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_sel_eco : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK2_CFG2_b2_dmd_sel_eco_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmdcmp_pull : 1;
        unsigned char b2_dmd_test_ctrl : 1;
        unsigned char b2_dmd_test : 1;
        unsigned char b2_dmd_sel_nor : 5;
    } reg;
} COMMON_PMIC_BUCK2_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG3_b2_dmdcmp_pull_START (0)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmdcmp_pull_END (0)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmd_test_ctrl_START (1)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmd_test_ctrl_END (1)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmd_test_START (2)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmd_test_END (2)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmd_sel_nor_START (3)
#define COMMON_PMIC_BUCK2_CFG3_b2_dmd_sel_nor_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_pwr_drvnonlinear_ctrl : 1;
        unsigned char b2_pwr_drvngp_sel : 3;
        unsigned char b2_pwr_drvngn_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG4_b2_pwr_drvnonlinear_ctrl_START (0)
#define COMMON_PMIC_BUCK2_CFG4_b2_pwr_drvnonlinear_ctrl_END (0)
#define COMMON_PMIC_BUCK2_CFG4_b2_pwr_drvngp_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG4_b2_pwr_drvngp_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG4_b2_pwr_drvngn_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG4_b2_pwr_drvngn_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_pwr_drvpgp_ccm_sel : 3;
        unsigned char b2_pwr_drvpgn_sel : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG5_b2_pwr_drvpgp_ccm_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG5_b2_pwr_drvpgp_ccm_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG5_b2_pwr_drvpgn_sel_START (3)
#define COMMON_PMIC_BUCK2_CFG5_b2_pwr_drvpgn_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_pwr_dtp2n_delay_ctrl : 1;
        unsigned char b2_pwr_dtn2p_sel : 2;
        unsigned char b2_pwr_dtn2p_delay_ctrl : 1;
        unsigned char b2_pwr_dt_offlatch_sel : 1;
        unsigned char b2_pwr_drvpgp_dcm_sel : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dtp2n_delay_ctrl_START (0)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dtp2n_delay_ctrl_END (0)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dtn2p_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dtn2p_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dtn2p_delay_ctrl_START (3)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dtn2p_delay_ctrl_END (3)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dt_offlatch_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_dt_offlatch_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_drvpgp_dcm_sel_START (5)
#define COMMON_PMIC_BUCK2_CFG6_b2_pwr_drvpgp_dcm_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_pwr_dtp2n_sel : 2;
        unsigned char b2_pwr_dtp2n_lxdet_ctrl : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK2_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG7_b2_pwr_dtp2n_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG7_b2_pwr_dtp2n_sel_END (1)
#define COMMON_PMIC_BUCK2_CFG7_b2_pwr_dtp2n_lxdet_ctrl_START (2)
#define COMMON_PMIC_BUCK2_CFG7_b2_pwr_dtp2n_lxdet_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ramp_cap_shield : 1;
        unsigned char b2_ramp_cap_sel : 2;
        unsigned char b2_adj_rlx : 5;
    } reg;
} COMMON_PMIC_BUCK2_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG8_b2_ramp_cap_shield_START (0)
#define COMMON_PMIC_BUCK2_CFG8_b2_ramp_cap_shield_END (0)
#define COMMON_PMIC_BUCK2_CFG8_b2_ramp_cap_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG8_b2_ramp_cap_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG8_b2_adj_rlx_START (3)
#define COMMON_PMIC_BUCK2_CFG8_b2_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_vofb_cap_sel : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK2_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG9_b2_vofb_cap_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG9_b2_vofb_cap_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_cmp_add_0p5u : 1;
        unsigned char b2_bias_reg_sel : 1;
        unsigned char b2_bias_ocp_sel : 3;
        unsigned char b2_bias_dmd_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG10_b2_cmp_add_0p5u_START (0)
#define COMMON_PMIC_BUCK2_CFG10_b2_cmp_add_0p5u_END (0)
#define COMMON_PMIC_BUCK2_CFG10_b2_bias_reg_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG10_b2_bias_reg_sel_END (1)
#define COMMON_PMIC_BUCK2_CFG10_b2_bias_ocp_sel_START (2)
#define COMMON_PMIC_BUCK2_CFG10_b2_bias_ocp_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG10_b2_bias_dmd_sel_START (5)
#define COMMON_PMIC_BUCK2_CFG10_b2_bias_dmd_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_ib_reduce_eco : 1;
        unsigned char b2_dmd_eco_cur : 1;
        unsigned char b2_cmp_ibias_volow : 1;
        unsigned char b2_cmp_eco_sel : 1;
        unsigned char b2_cmp_bias : 4;
    } reg;
} COMMON_PMIC_BUCK2_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG11_b2_dmd_ib_reduce_eco_START (0)
#define COMMON_PMIC_BUCK2_CFG11_b2_dmd_ib_reduce_eco_END (0)
#define COMMON_PMIC_BUCK2_CFG11_b2_dmd_eco_cur_START (1)
#define COMMON_PMIC_BUCK2_CFG11_b2_dmd_eco_cur_END (1)
#define COMMON_PMIC_BUCK2_CFG11_b2_cmp_ibias_volow_START (2)
#define COMMON_PMIC_BUCK2_CFG11_b2_cmp_ibias_volow_END (2)
#define COMMON_PMIC_BUCK2_CFG11_b2_cmp_eco_sel_START (3)
#define COMMON_PMIC_BUCK2_CFG11_b2_cmp_eco_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG11_b2_cmp_bias_START (4)
#define COMMON_PMIC_BUCK2_CFG11_b2_cmp_bias_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampamp_ibias_sel : 1;
        unsigned char b2_eco_i_sel : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK2_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG12_b2_rampamp_ibias_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG12_b2_rampamp_ibias_sel_END (0)
#define COMMON_PMIC_BUCK2_CFG12_b2_eco_i_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG12_b2_eco_i_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_test_sel : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK2_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG13_b2_test_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG13_b2_test_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampup_unitgain : 1;
        unsigned char b2_rampdn_unitgain : 1;
        unsigned char b2_low_reg_r_ctrl : 1;
        unsigned char b2_ibias_noise_ctrl : 1;
        unsigned char b2_eabias_sel : 1;
        unsigned char b2_ampbias_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG14_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG14_b2_rampup_unitgain_START (0)
#define COMMON_PMIC_BUCK2_CFG14_b2_rampup_unitgain_END (0)
#define COMMON_PMIC_BUCK2_CFG14_b2_rampdn_unitgain_START (1)
#define COMMON_PMIC_BUCK2_CFG14_b2_rampdn_unitgain_END (1)
#define COMMON_PMIC_BUCK2_CFG14_b2_low_reg_r_ctrl_START (2)
#define COMMON_PMIC_BUCK2_CFG14_b2_low_reg_r_ctrl_END (2)
#define COMMON_PMIC_BUCK2_CFG14_b2_ibias_noise_ctrl_START (3)
#define COMMON_PMIC_BUCK2_CFG14_b2_ibias_noise_ctrl_END (3)
#define COMMON_PMIC_BUCK2_CFG14_b2_eabias_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG14_b2_eabias_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG14_b2_ampbias_sel_START (5)
#define COMMON_PMIC_BUCK2_CFG14_b2_ampbias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reg_en : 1;
        unsigned char b2_reg_dr_ramp : 3;
        unsigned char b2_reg_dr : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG15_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG15_b2_reg_en_START (0)
#define COMMON_PMIC_BUCK2_CFG15_b2_reg_en_END (0)
#define COMMON_PMIC_BUCK2_CFG15_b2_reg_dr_ramp_START (1)
#define COMMON_PMIC_BUCK2_CFG15_b2_reg_dr_ramp_END (3)
#define COMMON_PMIC_BUCK2_CFG15_b2_reg_dr_START (4)
#define COMMON_PMIC_BUCK2_CFG15_b2_reg_dr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_regout_c_sel : 1;
        unsigned char b2_regop_c : 1;
        unsigned char b2_reg_zero_en : 1;
        unsigned char b2_reg_r : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG16_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG16_b2_regout_c_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG16_b2_regout_c_sel_END (0)
#define COMMON_PMIC_BUCK2_CFG16_b2_regop_c_START (1)
#define COMMON_PMIC_BUCK2_CFG16_b2_regop_c_END (1)
#define COMMON_PMIC_BUCK2_CFG16_b2_reg_zero_en_START (2)
#define COMMON_PMIC_BUCK2_CFG16_b2_reg_zero_en_END (2)
#define COMMON_PMIC_BUCK2_CFG16_b2_reg_r_START (3)
#define COMMON_PMIC_BUCK2_CFG16_b2_reg_r_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_da_diff_vo_c : 4;
        unsigned char b2_da_constant_sft_sel : 1;
        unsigned char b2_da_buffer_bias_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG17_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG17_b2_da_diff_vo_c_START (0)
#define COMMON_PMIC_BUCK2_CFG17_b2_da_diff_vo_c_END (3)
#define COMMON_PMIC_BUCK2_CFG17_b2_da_constant_sft_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG17_b2_da_constant_sft_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG17_b2_da_buffer_bias_sel_START (5)
#define COMMON_PMIC_BUCK2_CFG17_b2_da_buffer_bias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_da_diff_vo_r_base : 2;
        unsigned char b2_da_diff_vo_r : 3;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG18_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG18_b2_da_diff_vo_r_base_START (0)
#define COMMON_PMIC_BUCK2_CFG18_b2_da_diff_vo_r_base_END (1)
#define COMMON_PMIC_BUCK2_CFG18_b2_da_diff_vo_r_START (2)
#define COMMON_PMIC_BUCK2_CFG18_b2_da_diff_vo_r_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_da_diff_vref_r : 3;
        unsigned char b2_da_diff_vref_c : 4;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG19_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG19_b2_da_diff_vref_r_START (0)
#define COMMON_PMIC_BUCK2_CFG19_b2_da_diff_vref_r_END (2)
#define COMMON_PMIC_BUCK2_CFG19_b2_da_diff_vref_c_START (3)
#define COMMON_PMIC_BUCK2_CFG19_b2_da_diff_vref_c_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_da_ramp_buff_bias : 2;
        unsigned char b2_da_diff_vref_rset : 3;
        unsigned char b2_da_diff_vref_r_ramp : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG20_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG20_b2_da_ramp_buff_bias_START (0)
#define COMMON_PMIC_BUCK2_CFG20_b2_da_ramp_buff_bias_END (1)
#define COMMON_PMIC_BUCK2_CFG20_b2_da_diff_vref_rset_START (2)
#define COMMON_PMIC_BUCK2_CFG20_b2_da_diff_vref_rset_END (4)
#define COMMON_PMIC_BUCK2_CFG20_b2_da_diff_vref_r_ramp_START (5)
#define COMMON_PMIC_BUCK2_CFG20_b2_da_diff_vref_r_ramp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_da_rtr_cap_sel : 4;
        unsigned char b2_da_rampres_trim_ctrl : 2;
        unsigned char b2_da_ramp_ecobuffer_ctrl : 1;
        unsigned char b2_da_ramp_eco_ctrl : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG21_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG21_b2_da_rtr_cap_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_rtr_cap_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_rampres_trim_ctrl_START (4)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_rampres_trim_ctrl_END (5)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_ramp_ecobuffer_ctrl_START (6)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_ramp_ecobuffer_ctrl_END (6)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_ramp_eco_ctrl_START (7)
#define COMMON_PMIC_BUCK2_CFG21_b2_da_ramp_eco_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ramp_up_ctrl : 2;
        unsigned char b2_ramp_down_ctrl : 1;
        unsigned char b2_eco_pulse_ctrl : 1;
        unsigned char b2_da_vo_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG22_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG22_b2_ramp_up_ctrl_START (0)
#define COMMON_PMIC_BUCK2_CFG22_b2_ramp_up_ctrl_END (1)
#define COMMON_PMIC_BUCK2_CFG22_b2_ramp_down_ctrl_START (2)
#define COMMON_PMIC_BUCK2_CFG22_b2_ramp_down_ctrl_END (2)
#define COMMON_PMIC_BUCK2_CFG22_b2_eco_pulse_ctrl_START (3)
#define COMMON_PMIC_BUCK2_CFG22_b2_eco_pulse_ctrl_END (3)
#define COMMON_PMIC_BUCK2_CFG22_b2_da_vo_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG22_b2_da_vo_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_rampstate_syn_ctrl : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK2_CFG23_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG23_b2_rampstate_syn_ctrl_START (0)
#define COMMON_PMIC_BUCK2_CFG23_b2_rampstate_syn_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_cmp_tailbias_sel : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG24_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG24_b2_cmp_tailbias_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG24_b2_cmp_tailbias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ocp_sel : 2;
        unsigned char b2_ocp_middrv_sel : 2;
        unsigned char b2_ocp_middrv_ctrl : 1;
        unsigned char b2_ocp_delay : 1;
        unsigned char b2_ocp_counter_sel : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG25_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_sel_END (1)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_middrv_sel_START (2)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_middrv_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_middrv_ctrl_START (4)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_middrv_ctrl_END (4)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_delay_START (5)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_delay_END (5)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_counter_sel_START (6)
#define COMMON_PMIC_BUCK2_CFG25_b2_ocp_counter_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_uv2p3_shield : 1;
        unsigned char b2_ramp_ocp_shield : 1;
        unsigned char b2_pocp_offset_trim_en : 2;
        unsigned char b2_ocpblanktime_sel : 1;
        unsigned char b2_ocpbias_ctrl : 1;
        unsigned char b2_ocp_toff : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG26_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG26_b2_uv2p3_shield_START (0)
#define COMMON_PMIC_BUCK2_CFG26_b2_uv2p3_shield_END (0)
#define COMMON_PMIC_BUCK2_CFG26_b2_ramp_ocp_shield_START (1)
#define COMMON_PMIC_BUCK2_CFG26_b2_ramp_ocp_shield_END (1)
#define COMMON_PMIC_BUCK2_CFG26_b2_pocp_offset_trim_en_START (2)
#define COMMON_PMIC_BUCK2_CFG26_b2_pocp_offset_trim_en_END (3)
#define COMMON_PMIC_BUCK2_CFG26_b2_ocpblanktime_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG26_b2_ocpblanktime_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG26_b2_ocpbias_ctrl_START (5)
#define COMMON_PMIC_BUCK2_CFG26_b2_ocpbias_ctrl_END (5)
#define COMMON_PMIC_BUCK2_CFG26_b2_ocp_toff_START (6)
#define COMMON_PMIC_BUCK2_CFG26_b2_ocp_toff_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_uv3v_ocpcut_sel : 1;
        unsigned char b2_short_ref_ctrl : 1;
        unsigned char b2_vo_range_sel : 1;
        unsigned char b2_code_vo_sel : 1;
        unsigned char b2_soft_pull_test_sel : 1;
        unsigned char b2_regen_ctrl : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG27_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG27_b2_uv3v_ocpcut_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG27_b2_uv3v_ocpcut_sel_END (0)
#define COMMON_PMIC_BUCK2_CFG27_b2_short_ref_ctrl_START (1)
#define COMMON_PMIC_BUCK2_CFG27_b2_short_ref_ctrl_END (1)
#define COMMON_PMIC_BUCK2_CFG27_b2_vo_range_sel_START (2)
#define COMMON_PMIC_BUCK2_CFG27_b2_vo_range_sel_END (2)
#define COMMON_PMIC_BUCK2_CFG27_b2_code_vo_sel_START (3)
#define COMMON_PMIC_BUCK2_CFG27_b2_code_vo_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG27_b2_soft_pull_test_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG27_b2_soft_pull_test_sel_END (4)
#define COMMON_PMIC_BUCK2_CFG27_b2_regen_ctrl_START (5)
#define COMMON_PMIC_BUCK2_CFG27_b2_regen_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_dmd_ton : 3;
        unsigned char b2_dmd_off_ctrl : 1;
        unsigned char b2_dmd_bias_en_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK2_CFG28_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG28_b2_dmd_ton_START (0)
#define COMMON_PMIC_BUCK2_CFG28_b2_dmd_ton_END (2)
#define COMMON_PMIC_BUCK2_CFG28_b2_dmd_off_ctrl_START (3)
#define COMMON_PMIC_BUCK2_CFG28_b2_dmd_off_ctrl_END (3)
#define COMMON_PMIC_BUCK2_CFG28_b2_dmd_bias_en_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG28_b2_dmd_bias_en_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_no_dmd_ton : 3;
        unsigned char b2_eco_maxton_sel : 1;
        unsigned char b2_dmd_ton_shield : 1;
        unsigned char b2_dmd_ton_negcur : 3;
    } reg;
} COMMON_PMIC_BUCK2_CFG29_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG29_b2_no_dmd_ton_START (0)
#define COMMON_PMIC_BUCK2_CFG29_b2_no_dmd_ton_END (2)
#define COMMON_PMIC_BUCK2_CFG29_b2_eco_maxton_sel_START (3)
#define COMMON_PMIC_BUCK2_CFG29_b2_eco_maxton_sel_END (3)
#define COMMON_PMIC_BUCK2_CFG29_b2_dmd_ton_shield_START (4)
#define COMMON_PMIC_BUCK2_CFG29_b2_dmd_ton_shield_END (4)
#define COMMON_PMIC_BUCK2_CFG29_b2_dmd_ton_negcur_START (5)
#define COMMON_PMIC_BUCK2_CFG29_b2_dmd_ton_negcur_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_ton_cap_sel : 1;
        unsigned char b2_toff_sel : 1;
        unsigned char b2_ssend_cot_dis : 1;
        unsigned char b2_sel_min_ton : 1;
        unsigned char b2_ramp_sel : 2;
        unsigned char b2_ramp_ctrl_ton : 1;
        unsigned char b2_ocpsens_ctrl : 1;
    } reg;
} COMMON_PMIC_BUCK2_CFG30_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG30_b2_ton_cap_sel_START (0)
#define COMMON_PMIC_BUCK2_CFG30_b2_ton_cap_sel_END (0)
#define COMMON_PMIC_BUCK2_CFG30_b2_toff_sel_START (1)
#define COMMON_PMIC_BUCK2_CFG30_b2_toff_sel_END (1)
#define COMMON_PMIC_BUCK2_CFG30_b2_ssend_cot_dis_START (2)
#define COMMON_PMIC_BUCK2_CFG30_b2_ssend_cot_dis_END (2)
#define COMMON_PMIC_BUCK2_CFG30_b2_sel_min_ton_START (3)
#define COMMON_PMIC_BUCK2_CFG30_b2_sel_min_ton_END (3)
#define COMMON_PMIC_BUCK2_CFG30_b2_ramp_sel_START (4)
#define COMMON_PMIC_BUCK2_CFG30_b2_ramp_sel_END (5)
#define COMMON_PMIC_BUCK2_CFG30_b2_ramp_ctrl_ton_START (6)
#define COMMON_PMIC_BUCK2_CFG30_b2_ramp_ctrl_ton_END (6)
#define COMMON_PMIC_BUCK2_CFG30_b2_ocpsens_ctrl_START (7)
#define COMMON_PMIC_BUCK2_CFG30_b2_ocpsens_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_toncap_ctrl : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK2_CFG31_UNION;
#endif
#define COMMON_PMIC_BUCK2_CFG31_b2_toncap_ctrl_START (0)
#define COMMON_PMIC_BUCK2_CFG31_b2_toncap_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK2_RSV_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK2_RSV_CFG0_b2_reserve0_START (0)
#define COMMON_PMIC_BUCK2_RSV_CFG0_b2_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK2_RSV_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK2_RSV_CFG1_b2_reserve1_START (0)
#define COMMON_PMIC_BUCK2_RSV_CFG1_b2_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_a2d_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK2_A2D_RSV0_UNION;
#endif
#define COMMON_PMIC_BUCK2_A2D_RSV0_b2_a2d_reserve0_START (0)
#define COMMON_PMIC_BUCK2_A2D_RSV0_b2_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b2_a2d_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK2_A2D_RSV1_UNION;
#endif
#define COMMON_PMIC_BUCK2_A2D_RSV1_b2_a2d_reserve1_START (0)
#define COMMON_PMIC_BUCK2_A2D_RSV1_b2_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_negcur_en : 1;
        unsigned char b3_dmd_cmp_sel_nor : 1;
        unsigned char b3_dmd_cmp_sel_neg : 1;
        unsigned char b3_dmd_cmp_sel_eco : 1;
        unsigned char b3_dmd_blanking_sel : 1;
        unsigned char b3_dmd_bias_shield_nor : 1;
        unsigned char b3_dmd_bias_shield_eco : 1;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_negcur_en_START (0)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_negcur_en_END (0)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_cmp_sel_nor_START (1)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_cmp_sel_nor_END (1)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_cmp_sel_neg_START (2)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_cmp_sel_neg_END (2)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_cmp_sel_eco_START (3)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_cmp_sel_eco_END (3)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_blanking_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_blanking_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_bias_shield_nor_START (5)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_bias_shield_nor_END (5)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_bias_shield_eco_START (6)
#define COMMON_PMIC_BUCK3_CFG0_b3_dmd_bias_shield_eco_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_reten_sel : 1;
        unsigned char b3_dmd_pwmn_shield : 1;
        unsigned char b3_dmd_negcur_sel : 2;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BUCK3_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_reten_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_reten_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_pwmn_shield_START (1)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_pwmn_shield_END (1)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_negcur_sel_START (2)
#define COMMON_PMIC_BUCK3_CFG1_b3_dmd_negcur_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_sel_eco : 5;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_sel_eco_START (0)
#define COMMON_PMIC_BUCK3_CFG2_b3_dmd_sel_eco_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmdcmp_pull : 1;
        unsigned char b3_dmd_test_ctrl : 1;
        unsigned char b3_dmd_test : 1;
        unsigned char b3_dmd_sel_nor : 5;
    } reg;
} COMMON_PMIC_BUCK3_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG3_b3_dmdcmp_pull_START (0)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmdcmp_pull_END (0)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmd_test_ctrl_START (1)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmd_test_ctrl_END (1)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmd_test_START (2)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmd_test_END (2)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmd_sel_nor_START (3)
#define COMMON_PMIC_BUCK3_CFG3_b3_dmd_sel_nor_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_pwr_drvnonlinear_ctrl : 1;
        unsigned char b3_pwr_drvngp_sel : 3;
        unsigned char b3_pwr_drvngn_sel : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG4_b3_pwr_drvnonlinear_ctrl_START (0)
#define COMMON_PMIC_BUCK3_CFG4_b3_pwr_drvnonlinear_ctrl_END (0)
#define COMMON_PMIC_BUCK3_CFG4_b3_pwr_drvngp_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG4_b3_pwr_drvngp_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG4_b3_pwr_drvngn_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG4_b3_pwr_drvngn_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_pwr_drvpgp_ccm_sel : 3;
        unsigned char b3_pwr_drvpgn_sel : 3;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG5_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG5_b3_pwr_drvpgp_ccm_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG5_b3_pwr_drvpgp_ccm_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG5_b3_pwr_drvpgn_sel_START (3)
#define COMMON_PMIC_BUCK3_CFG5_b3_pwr_drvpgn_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_pwr_dtp2n_delay_ctrl : 1;
        unsigned char b3_pwr_dtn2p_sel : 2;
        unsigned char b3_pwr_dtn2p_delay_ctrl : 1;
        unsigned char b3_pwr_dt_offlatch_sel : 1;
        unsigned char b3_pwr_drvpgp_dcm_sel : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG6_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dtp2n_delay_ctrl_START (0)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dtp2n_delay_ctrl_END (0)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dtn2p_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dtn2p_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dtn2p_delay_ctrl_START (3)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dtn2p_delay_ctrl_END (3)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dt_offlatch_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_dt_offlatch_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_drvpgp_dcm_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG6_b3_pwr_drvpgp_dcm_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_pwr_dtp2n_sel : 2;
        unsigned char b3_pwr_dtp2n_lxdet_ctrl : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK3_CFG7_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG7_b3_pwr_dtp2n_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG7_b3_pwr_dtp2n_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG7_b3_pwr_dtp2n_lxdet_ctrl_START (2)
#define COMMON_PMIC_BUCK3_CFG7_b3_pwr_dtp2n_lxdet_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ramp_cap_shield : 1;
        unsigned char b3_ramp_cap_sel : 2;
        unsigned char b3_adj_rlx : 5;
    } reg;
} COMMON_PMIC_BUCK3_CFG8_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG8_b3_ramp_cap_shield_START (0)
#define COMMON_PMIC_BUCK3_CFG8_b3_ramp_cap_shield_END (0)
#define COMMON_PMIC_BUCK3_CFG8_b3_ramp_cap_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG8_b3_ramp_cap_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG8_b3_adj_rlx_START (3)
#define COMMON_PMIC_BUCK3_CFG8_b3_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_vofb_cap_sel : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK3_CFG9_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG9_b3_vofb_cap_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG9_b3_vofb_cap_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_cmp_add_0p5u : 1;
        unsigned char b3_bias_reg_sel : 1;
        unsigned char b3_bias_ocp_sel : 3;
        unsigned char b3_bias_dmd_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG10_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG10_b3_cmp_add_0p5u_START (0)
#define COMMON_PMIC_BUCK3_CFG10_b3_cmp_add_0p5u_END (0)
#define COMMON_PMIC_BUCK3_CFG10_b3_bias_reg_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG10_b3_bias_reg_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG10_b3_bias_ocp_sel_START (2)
#define COMMON_PMIC_BUCK3_CFG10_b3_bias_ocp_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG10_b3_bias_dmd_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG10_b3_bias_dmd_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_ib_reduce_eco : 1;
        unsigned char b3_dmd_eco_cur : 1;
        unsigned char b3_cmp_ibias_volow : 1;
        unsigned char b3_cmp_eco_sel : 1;
        unsigned char b3_cmp_bias : 4;
    } reg;
} COMMON_PMIC_BUCK3_CFG11_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG11_b3_dmd_ib_reduce_eco_START (0)
#define COMMON_PMIC_BUCK3_CFG11_b3_dmd_ib_reduce_eco_END (0)
#define COMMON_PMIC_BUCK3_CFG11_b3_dmd_eco_cur_START (1)
#define COMMON_PMIC_BUCK3_CFG11_b3_dmd_eco_cur_END (1)
#define COMMON_PMIC_BUCK3_CFG11_b3_cmp_ibias_volow_START (2)
#define COMMON_PMIC_BUCK3_CFG11_b3_cmp_ibias_volow_END (2)
#define COMMON_PMIC_BUCK3_CFG11_b3_cmp_eco_sel_START (3)
#define COMMON_PMIC_BUCK3_CFG11_b3_cmp_eco_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG11_b3_cmp_bias_START (4)
#define COMMON_PMIC_BUCK3_CFG11_b3_cmp_bias_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampamp_ibias_sel : 1;
        unsigned char b3_eco_i_sel : 1;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK3_CFG12_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG12_b3_rampamp_ibias_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG12_b3_rampamp_ibias_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG12_b3_eco_i_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG12_b3_eco_i_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_test_sel : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK3_CFG13_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG13_b3_test_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG13_b3_test_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampup_unitgain : 1;
        unsigned char b3_rampdn_unitgain : 1;
        unsigned char b3_low_reg_r_ctrl : 1;
        unsigned char b3_ibias_noise_ctrl : 1;
        unsigned char b3_eabias_sel : 1;
        unsigned char b3_ampbias_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG14_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG14_b3_rampup_unitgain_START (0)
#define COMMON_PMIC_BUCK3_CFG14_b3_rampup_unitgain_END (0)
#define COMMON_PMIC_BUCK3_CFG14_b3_rampdn_unitgain_START (1)
#define COMMON_PMIC_BUCK3_CFG14_b3_rampdn_unitgain_END (1)
#define COMMON_PMIC_BUCK3_CFG14_b3_low_reg_r_ctrl_START (2)
#define COMMON_PMIC_BUCK3_CFG14_b3_low_reg_r_ctrl_END (2)
#define COMMON_PMIC_BUCK3_CFG14_b3_ibias_noise_ctrl_START (3)
#define COMMON_PMIC_BUCK3_CFG14_b3_ibias_noise_ctrl_END (3)
#define COMMON_PMIC_BUCK3_CFG14_b3_eabias_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG14_b3_eabias_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG14_b3_ampbias_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG14_b3_ampbias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reg_en : 1;
        unsigned char b3_reg_dr_ramp : 3;
        unsigned char b3_reg_dr : 3;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG15_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG15_b3_reg_en_START (0)
#define COMMON_PMIC_BUCK3_CFG15_b3_reg_en_END (0)
#define COMMON_PMIC_BUCK3_CFG15_b3_reg_dr_ramp_START (1)
#define COMMON_PMIC_BUCK3_CFG15_b3_reg_dr_ramp_END (3)
#define COMMON_PMIC_BUCK3_CFG15_b3_reg_dr_START (4)
#define COMMON_PMIC_BUCK3_CFG15_b3_reg_dr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_regout_c_sel : 1;
        unsigned char b3_regop_c : 1;
        unsigned char b3_reg_zero_en : 1;
        unsigned char b3_reg_r : 2;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG16_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG16_b3_regout_c_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG16_b3_regout_c_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG16_b3_regop_c_START (1)
#define COMMON_PMIC_BUCK3_CFG16_b3_regop_c_END (1)
#define COMMON_PMIC_BUCK3_CFG16_b3_reg_zero_en_START (2)
#define COMMON_PMIC_BUCK3_CFG16_b3_reg_zero_en_END (2)
#define COMMON_PMIC_BUCK3_CFG16_b3_reg_r_START (3)
#define COMMON_PMIC_BUCK3_CFG16_b3_reg_r_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_da_diff_vo_c : 4;
        unsigned char b3_da_constant_sft_sel : 1;
        unsigned char b3_da_buffer_bias_sel : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG17_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG17_b3_da_diff_vo_c_START (0)
#define COMMON_PMIC_BUCK3_CFG17_b3_da_diff_vo_c_END (3)
#define COMMON_PMIC_BUCK3_CFG17_b3_da_constant_sft_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG17_b3_da_constant_sft_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG17_b3_da_buffer_bias_sel_START (5)
#define COMMON_PMIC_BUCK3_CFG17_b3_da_buffer_bias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_da_diff_vo_r_base : 2;
        unsigned char b3_da_diff_vo_r : 3;
        unsigned char reserved : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG18_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG18_b3_da_diff_vo_r_base_START (0)
#define COMMON_PMIC_BUCK3_CFG18_b3_da_diff_vo_r_base_END (1)
#define COMMON_PMIC_BUCK3_CFG18_b3_da_diff_vo_r_START (2)
#define COMMON_PMIC_BUCK3_CFG18_b3_da_diff_vo_r_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_da_diff_vref_r : 3;
        unsigned char b3_da_diff_vref_c : 4;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG19_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG19_b3_da_diff_vref_r_START (0)
#define COMMON_PMIC_BUCK3_CFG19_b3_da_diff_vref_r_END (2)
#define COMMON_PMIC_BUCK3_CFG19_b3_da_diff_vref_c_START (3)
#define COMMON_PMIC_BUCK3_CFG19_b3_da_diff_vref_c_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_da_ramp_buff_bias : 2;
        unsigned char b3_da_diff_vref_rset : 3;
        unsigned char b3_da_diff_vref_r_ramp : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG20_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG20_b3_da_ramp_buff_bias_START (0)
#define COMMON_PMIC_BUCK3_CFG20_b3_da_ramp_buff_bias_END (1)
#define COMMON_PMIC_BUCK3_CFG20_b3_da_diff_vref_rset_START (2)
#define COMMON_PMIC_BUCK3_CFG20_b3_da_diff_vref_rset_END (4)
#define COMMON_PMIC_BUCK3_CFG20_b3_da_diff_vref_r_ramp_START (5)
#define COMMON_PMIC_BUCK3_CFG20_b3_da_diff_vref_r_ramp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_da_rtr_cap_sel : 4;
        unsigned char b3_da_rampres_trim_ctrl : 2;
        unsigned char b3_da_ramp_ecobuffer_ctrl : 1;
        unsigned char b3_da_ramp_eco_ctrl : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG21_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG21_b3_da_rtr_cap_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_rtr_cap_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_rampres_trim_ctrl_START (4)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_rampres_trim_ctrl_END (5)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_ramp_ecobuffer_ctrl_START (6)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_ramp_ecobuffer_ctrl_END (6)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_ramp_eco_ctrl_START (7)
#define COMMON_PMIC_BUCK3_CFG21_b3_da_ramp_eco_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ramp_up_ctrl : 2;
        unsigned char b3_ramp_down_ctrl : 1;
        unsigned char b3_eco_pulse_ctrl : 1;
        unsigned char b3_da_vo_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG22_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG22_b3_ramp_up_ctrl_START (0)
#define COMMON_PMIC_BUCK3_CFG22_b3_ramp_up_ctrl_END (1)
#define COMMON_PMIC_BUCK3_CFG22_b3_ramp_down_ctrl_START (2)
#define COMMON_PMIC_BUCK3_CFG22_b3_ramp_down_ctrl_END (2)
#define COMMON_PMIC_BUCK3_CFG22_b3_eco_pulse_ctrl_START (3)
#define COMMON_PMIC_BUCK3_CFG22_b3_eco_pulse_ctrl_END (3)
#define COMMON_PMIC_BUCK3_CFG22_b3_da_vo_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG22_b3_da_vo_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_rampstate_syn_ctrl : 3;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_BUCK3_CFG23_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG23_b3_rampstate_syn_ctrl_START (0)
#define COMMON_PMIC_BUCK3_CFG23_b3_rampstate_syn_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_cmp_tailbias_sel : 6;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG24_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG24_b3_cmp_tailbias_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG24_b3_cmp_tailbias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ocp_sel : 2;
        unsigned char b3_ocp_middrv_sel : 2;
        unsigned char b3_ocp_middrv_ctrl : 1;
        unsigned char b3_ocp_delay : 1;
        unsigned char b3_ocp_counter_sel : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG25_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_middrv_sel_START (2)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_middrv_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_middrv_ctrl_START (4)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_middrv_ctrl_END (4)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_delay_START (5)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_delay_END (5)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_counter_sel_START (6)
#define COMMON_PMIC_BUCK3_CFG25_b3_ocp_counter_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_uv2p3_shield : 1;
        unsigned char b3_ramp_ocp_shield : 1;
        unsigned char b3_pocp_offset_trim_en : 2;
        unsigned char b3_ocpblanktime_sel : 1;
        unsigned char b3_ocpbias_ctrl : 1;
        unsigned char b3_ocp_toff : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG26_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG26_b3_uv2p3_shield_START (0)
#define COMMON_PMIC_BUCK3_CFG26_b3_uv2p3_shield_END (0)
#define COMMON_PMIC_BUCK3_CFG26_b3_ramp_ocp_shield_START (1)
#define COMMON_PMIC_BUCK3_CFG26_b3_ramp_ocp_shield_END (1)
#define COMMON_PMIC_BUCK3_CFG26_b3_pocp_offset_trim_en_START (2)
#define COMMON_PMIC_BUCK3_CFG26_b3_pocp_offset_trim_en_END (3)
#define COMMON_PMIC_BUCK3_CFG26_b3_ocpblanktime_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG26_b3_ocpblanktime_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG26_b3_ocpbias_ctrl_START (5)
#define COMMON_PMIC_BUCK3_CFG26_b3_ocpbias_ctrl_END (5)
#define COMMON_PMIC_BUCK3_CFG26_b3_ocp_toff_START (6)
#define COMMON_PMIC_BUCK3_CFG26_b3_ocp_toff_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_uv3v_ocpcut_sel : 1;
        unsigned char b3_short_ref_ctrl : 1;
        unsigned char b3_vo_range_sel : 1;
        unsigned char b3_code_vo_sel : 1;
        unsigned char b3_soft_pull_test_sel : 1;
        unsigned char b3_regen_ctrl : 1;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG27_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG27_b3_uv3v_ocpcut_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG27_b3_uv3v_ocpcut_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG27_b3_short_ref_ctrl_START (1)
#define COMMON_PMIC_BUCK3_CFG27_b3_short_ref_ctrl_END (1)
#define COMMON_PMIC_BUCK3_CFG27_b3_vo_range_sel_START (2)
#define COMMON_PMIC_BUCK3_CFG27_b3_vo_range_sel_END (2)
#define COMMON_PMIC_BUCK3_CFG27_b3_code_vo_sel_START (3)
#define COMMON_PMIC_BUCK3_CFG27_b3_code_vo_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG27_b3_soft_pull_test_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG27_b3_soft_pull_test_sel_END (4)
#define COMMON_PMIC_BUCK3_CFG27_b3_regen_ctrl_START (5)
#define COMMON_PMIC_BUCK3_CFG27_b3_regen_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_dmd_ton : 3;
        unsigned char b3_dmd_off_ctrl : 1;
        unsigned char b3_dmd_bias_en_sel : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_BUCK3_CFG28_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG28_b3_dmd_ton_START (0)
#define COMMON_PMIC_BUCK3_CFG28_b3_dmd_ton_END (2)
#define COMMON_PMIC_BUCK3_CFG28_b3_dmd_off_ctrl_START (3)
#define COMMON_PMIC_BUCK3_CFG28_b3_dmd_off_ctrl_END (3)
#define COMMON_PMIC_BUCK3_CFG28_b3_dmd_bias_en_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG28_b3_dmd_bias_en_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_no_dmd_ton : 3;
        unsigned char b3_eco_maxton_sel : 1;
        unsigned char b3_dmd_ton_shield : 1;
        unsigned char b3_dmd_ton_negcur : 3;
    } reg;
} COMMON_PMIC_BUCK3_CFG29_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG29_b3_no_dmd_ton_START (0)
#define COMMON_PMIC_BUCK3_CFG29_b3_no_dmd_ton_END (2)
#define COMMON_PMIC_BUCK3_CFG29_b3_eco_maxton_sel_START (3)
#define COMMON_PMIC_BUCK3_CFG29_b3_eco_maxton_sel_END (3)
#define COMMON_PMIC_BUCK3_CFG29_b3_dmd_ton_shield_START (4)
#define COMMON_PMIC_BUCK3_CFG29_b3_dmd_ton_shield_END (4)
#define COMMON_PMIC_BUCK3_CFG29_b3_dmd_ton_negcur_START (5)
#define COMMON_PMIC_BUCK3_CFG29_b3_dmd_ton_negcur_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_ton_cap_sel : 1;
        unsigned char b3_toff_sel : 1;
        unsigned char b3_ssend_cot_dis : 1;
        unsigned char b3_sel_min_ton : 1;
        unsigned char b3_ramp_sel : 2;
        unsigned char b3_ramp_ctrl_ton : 1;
        unsigned char b3_ocpsens_ctrl : 1;
    } reg;
} COMMON_PMIC_BUCK3_CFG30_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG30_b3_ton_cap_sel_START (0)
#define COMMON_PMIC_BUCK3_CFG30_b3_ton_cap_sel_END (0)
#define COMMON_PMIC_BUCK3_CFG30_b3_toff_sel_START (1)
#define COMMON_PMIC_BUCK3_CFG30_b3_toff_sel_END (1)
#define COMMON_PMIC_BUCK3_CFG30_b3_ssend_cot_dis_START (2)
#define COMMON_PMIC_BUCK3_CFG30_b3_ssend_cot_dis_END (2)
#define COMMON_PMIC_BUCK3_CFG30_b3_sel_min_ton_START (3)
#define COMMON_PMIC_BUCK3_CFG30_b3_sel_min_ton_END (3)
#define COMMON_PMIC_BUCK3_CFG30_b3_ramp_sel_START (4)
#define COMMON_PMIC_BUCK3_CFG30_b3_ramp_sel_END (5)
#define COMMON_PMIC_BUCK3_CFG30_b3_ramp_ctrl_ton_START (6)
#define COMMON_PMIC_BUCK3_CFG30_b3_ramp_ctrl_ton_END (6)
#define COMMON_PMIC_BUCK3_CFG30_b3_ocpsens_ctrl_START (7)
#define COMMON_PMIC_BUCK3_CFG30_b3_ocpsens_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_toncap_ctrl : 2;
        unsigned char reserved : 6;
    } reg;
} COMMON_PMIC_BUCK3_CFG31_UNION;
#endif
#define COMMON_PMIC_BUCK3_CFG31_b3_toncap_ctrl_START (0)
#define COMMON_PMIC_BUCK3_CFG31_b3_toncap_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK3_RSV_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK3_RSV_CFG0_b3_reserve0_START (0)
#define COMMON_PMIC_BUCK3_RSV_CFG0_b3_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK3_RSV_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK3_RSV_CFG1_b3_reserve1_START (0)
#define COMMON_PMIC_BUCK3_RSV_CFG1_b3_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_a2d_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK3_A2D_RSV0_UNION;
#endif
#define COMMON_PMIC_BUCK3_A2D_RSV0_b3_a2d_reserve0_START (0)
#define COMMON_PMIC_BUCK3_A2D_RSV0_b3_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b3_a2d_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK3_A2D_RSV1_UNION;
#endif
#define COMMON_PMIC_BUCK3_A2D_RSV1_b3_a2d_reserve1_START (0)
#define COMMON_PMIC_BUCK3_A2D_RSV1_b3_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_lx_trim_sel : 8;
    } reg;
} COMMON_PMIC_BUCK_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK_CFG0_buck_lx_trim_sel_START (0)
#define COMMON_PMIC_BUCK_CFG0_buck_lx_trim_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_lx_trim_ctrl : 1;
        unsigned char buck_short_ctrl : 1;
        unsigned char buck_en_regop_clamp : 1;
        unsigned char buck_dmd_clamp : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_BUCK_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK_CFG1_buck_lx_trim_ctrl_START (0)
#define COMMON_PMIC_BUCK_CFG1_buck_lx_trim_ctrl_END (0)
#define COMMON_PMIC_BUCK_CFG1_buck_short_ctrl_START (1)
#define COMMON_PMIC_BUCK_CFG1_buck_short_ctrl_END (1)
#define COMMON_PMIC_BUCK_CFG1_buck_en_regop_clamp_START (2)
#define COMMON_PMIC_BUCK_CFG1_buck_en_regop_clamp_END (2)
#define COMMON_PMIC_BUCK_CFG1_buck_dmd_clamp_START (3)
#define COMMON_PMIC_BUCK_CFG1_buck_dmd_clamp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_ocptrim_ctrl : 1;
        unsigned char buck_ocp_dis : 1;
        unsigned char buck_filter_ton : 2;
        unsigned char buck_eco_mode_sel : 1;
        unsigned char buck_eco_maxton_ctrl : 1;
        unsigned char buck_code_sync_sel : 1;
        unsigned char buck_cmp_filter : 1;
    } reg;
} COMMON_PMIC_BUCK_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK_CFG2_buck_ocptrim_ctrl_START (0)
#define COMMON_PMIC_BUCK_CFG2_buck_ocptrim_ctrl_END (0)
#define COMMON_PMIC_BUCK_CFG2_buck_ocp_dis_START (1)
#define COMMON_PMIC_BUCK_CFG2_buck_ocp_dis_END (1)
#define COMMON_PMIC_BUCK_CFG2_buck_filter_ton_START (2)
#define COMMON_PMIC_BUCK_CFG2_buck_filter_ton_END (3)
#define COMMON_PMIC_BUCK_CFG2_buck_eco_mode_sel_START (4)
#define COMMON_PMIC_BUCK_CFG2_buck_eco_mode_sel_END (4)
#define COMMON_PMIC_BUCK_CFG2_buck_eco_maxton_ctrl_START (5)
#define COMMON_PMIC_BUCK_CFG2_buck_eco_maxton_ctrl_END (5)
#define COMMON_PMIC_BUCK_CFG2_buck_code_sync_sel_START (6)
#define COMMON_PMIC_BUCK_CFG2_buck_code_sync_sel_END (6)
#define COMMON_PMIC_BUCK_CFG2_buck_cmp_filter_START (7)
#define COMMON_PMIC_BUCK_CFG2_buck_cmp_filter_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_pwr_rontst_sel : 2;
        unsigned char buck_pwr_ongating : 1;
        unsigned char buck_pwr_mostrim_sel : 1;
        unsigned char buck_pwr_drvdt_ctrl : 4;
    } reg;
} COMMON_PMIC_BUCK_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_rontst_sel_START (0)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_rontst_sel_END (1)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_ongating_START (2)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_ongating_END (2)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_mostrim_sel_START (3)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_mostrim_sel_END (3)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_drvdt_ctrl_START (4)
#define COMMON_PMIC_BUCK_CFG3_buck_pwr_drvdt_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_test_sel : 8;
    } reg;
} COMMON_PMIC_BUCK_CFG4_UNION;
#endif
#define COMMON_PMIC_BUCK_CFG4_buck_test_sel_START (0)
#define COMMON_PMIC_BUCK_CFG4_buck_test_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_reserve0 : 8;
    } reg;
} COMMON_PMIC_BUCK_RSV_CFG0_UNION;
#endif
#define COMMON_PMIC_BUCK_RSV_CFG0_buck_reserve0_START (0)
#define COMMON_PMIC_BUCK_RSV_CFG0_buck_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_reserve1 : 8;
    } reg;
} COMMON_PMIC_BUCK_RSV_CFG1_UNION;
#endif
#define COMMON_PMIC_BUCK_RSV_CFG1_buck_reserve1_START (0)
#define COMMON_PMIC_BUCK_RSV_CFG1_buck_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_reserve2 : 8;
    } reg;
} COMMON_PMIC_BUCK_RSV_CFG2_UNION;
#endif
#define COMMON_PMIC_BUCK_RSV_CFG2_buck_reserve2_START (0)
#define COMMON_PMIC_BUCK_RSV_CFG2_buck_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char buck_reserve3 : 8;
    } reg;
} COMMON_PMIC_BUCK_RSV_CFG3_UNION;
#endif
#define COMMON_PMIC_BUCK_RSV_CFG3_buck_reserve3_START (0)
#define COMMON_PMIC_BUCK_RSV_CFG3_buck_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve0_buck : 8;
    } reg;
} COMMON_PMIC_BUCK_A2D_RSV0_UNION;
#endif
#define COMMON_PMIC_BUCK_A2D_RSV0_a2d_reserve0_buck_START (0)
#define COMMON_PMIC_BUCK_A2D_RSV0_a2d_reserve0_buck_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve1_buck : 8;
    } reg;
} COMMON_PMIC_BUCK_A2D_RSV1_UNION;
#endif
#define COMMON_PMIC_BUCK_A2D_RSV1_a2d_reserve1_buck_START (0)
#define COMMON_PMIC_BUCK_A2D_RSV1_a2d_reserve1_buck_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve0 : 8;
    } reg;
} COMMON_PMIC_ATEST_RSV_CFG0_UNION;
#endif
#define COMMON_PMIC_ATEST_RSV_CFG0_atest_reserve0_START (0)
#define COMMON_PMIC_ATEST_RSV_CFG0_atest_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve1 : 8;
    } reg;
} COMMON_PMIC_ATEST_RSV_CFG1_UNION;
#endif
#define COMMON_PMIC_ATEST_RSV_CFG1_atest_reserve1_START (0)
#define COMMON_PMIC_ATEST_RSV_CFG1_atest_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve2 : 8;
    } reg;
} COMMON_PMIC_ATEST_RSV_CFG2_UNION;
#endif
#define COMMON_PMIC_ATEST_RSV_CFG2_atest_reserve2_START (0)
#define COMMON_PMIC_ATEST_RSV_CFG2_atest_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char atest_reserve3 : 8;
    } reg;
} COMMON_PMIC_ATEST_RSV_CFG3_UNION;
#endif
#define COMMON_PMIC_ATEST_RSV_CFG3_atest_reserve3_START (0)
#define COMMON_PMIC_ATEST_RSV_CFG3_atest_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve0 : 8;
    } reg;
} COMMON_PMIC_D2A_RSV_CFG0_UNION;
#endif
#define COMMON_PMIC_D2A_RSV_CFG0_d2a_reserve0_START (0)
#define COMMON_PMIC_D2A_RSV_CFG0_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve1 : 8;
    } reg;
} COMMON_PMIC_D2A_RSV_CFG1_UNION;
#endif
#define COMMON_PMIC_D2A_RSV_CFG1_d2a_reserve1_START (0)
#define COMMON_PMIC_D2A_RSV_CFG1_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve2 : 8;
    } reg;
} COMMON_PMIC_D2A_RSV_CFG2_UNION;
#endif
#define COMMON_PMIC_D2A_RSV_CFG2_d2a_reserve2_START (0)
#define COMMON_PMIC_D2A_RSV_CFG2_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char d2a_reserve3 : 8;
    } reg;
} COMMON_PMIC_D2A_RSV_CFG3_UNION;
#endif
#define COMMON_PMIC_D2A_RSV_CFG3_d2a_reserve3_START (0)
#define COMMON_PMIC_D2A_RSV_CFG3_d2a_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve0 : 8;
    } reg;
} COMMON_PMIC_A2D_RSV_0_UNION;
#endif
#define COMMON_PMIC_A2D_RSV_0_a2d_reserve0_START (0)
#define COMMON_PMIC_A2D_RSV_0_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char a2d_reserve1 : 8;
    } reg;
} COMMON_PMIC_A2D_RSV_1_UNION;
#endif
#define COMMON_PMIC_A2D_RSV_1_a2d_reserve1_START (0)
#define COMMON_PMIC_A2D_RSV_1_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_bw_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO1_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO1_CFG0_ldo1_bw_en_START (0)
#define COMMON_PMIC_LDO1_CFG0_ldo1_bw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_config : 8;
    } reg;
} COMMON_PMIC_LDO1_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO1_CFG1_ldo1_config_START (0)
#define COMMON_PMIC_LDO1_CFG1_ldo1_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo1_vgpr_en : 1;
        unsigned char ldo1_tran_set : 3;
        unsigned char ldo1_ocpd_set : 2;
        unsigned char ldo1_ocp_enn : 1;
        unsigned char ldo1_noise_set : 1;
    } reg;
} COMMON_PMIC_LDO1_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO1_CFG2_ldo1_vgpr_en_START (0)
#define COMMON_PMIC_LDO1_CFG2_ldo1_vgpr_en_END (0)
#define COMMON_PMIC_LDO1_CFG2_ldo1_tran_set_START (1)
#define COMMON_PMIC_LDO1_CFG2_ldo1_tran_set_END (3)
#define COMMON_PMIC_LDO1_CFG2_ldo1_ocpd_set_START (4)
#define COMMON_PMIC_LDO1_CFG2_ldo1_ocpd_set_END (5)
#define COMMON_PMIC_LDO1_CFG2_ldo1_ocp_enn_START (6)
#define COMMON_PMIC_LDO1_CFG2_ldo1_ocp_enn_END (6)
#define COMMON_PMIC_LDO1_CFG2_ldo1_noise_set_START (7)
#define COMMON_PMIC_LDO1_CFG2_ldo1_noise_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_psrr1_set : 4;
        unsigned char ldo2_psrr_en : 1;
        unsigned char ldo2_ocp_set : 2;
        unsigned char ldo2_ocp_enn : 1;
    } reg;
} COMMON_PMIC_LDO2_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO2_CFG0_ldo2_psrr1_set_START (0)
#define COMMON_PMIC_LDO2_CFG0_ldo2_psrr1_set_END (3)
#define COMMON_PMIC_LDO2_CFG0_ldo2_psrr_en_START (4)
#define COMMON_PMIC_LDO2_CFG0_ldo2_psrr_en_END (4)
#define COMMON_PMIC_LDO2_CFG0_ldo2_ocp_set_START (5)
#define COMMON_PMIC_LDO2_CFG0_ldo2_ocp_set_END (6)
#define COMMON_PMIC_LDO2_CFG0_ldo2_ocp_enn_START (7)
#define COMMON_PMIC_LDO2_CFG0_ldo2_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_psrr3_set : 4;
        unsigned char ldo2_psrr2_set : 4;
    } reg;
} COMMON_PMIC_LDO2_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO2_CFG1_ldo2_psrr3_set_START (0)
#define COMMON_PMIC_LDO2_CFG1_ldo2_psrr3_set_END (3)
#define COMMON_PMIC_LDO2_CFG1_ldo2_psrr2_set_START (4)
#define COMMON_PMIC_LDO2_CFG1_ldo2_psrr2_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo2_vrset : 3;
        unsigned char ldo2_stb_set : 3;
        unsigned char ldo2_sst_set : 2;
    } reg;
} COMMON_PMIC_LDO2_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO2_CFG2_ldo2_vrset_START (0)
#define COMMON_PMIC_LDO2_CFG2_ldo2_vrset_END (2)
#define COMMON_PMIC_LDO2_CFG2_ldo2_stb_set_START (3)
#define COMMON_PMIC_LDO2_CFG2_ldo2_stb_set_END (5)
#define COMMON_PMIC_LDO2_CFG2_ldo2_sst_set_START (6)
#define COMMON_PMIC_LDO2_CFG2_ldo2_sst_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_bw_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO3_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO3_CFG0_ldo3_bw_en_START (0)
#define COMMON_PMIC_LDO3_CFG0_ldo3_bw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_config : 8;
    } reg;
} COMMON_PMIC_LDO3_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO3_CFG1_ldo3_config_START (0)
#define COMMON_PMIC_LDO3_CFG1_ldo3_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo3_vgpr_en : 1;
        unsigned char ldo3_tran_set : 3;
        unsigned char ldo3_ocpd_set : 2;
        unsigned char ldo3_ocp_enn : 1;
        unsigned char ldo3_noise_set : 1;
    } reg;
} COMMON_PMIC_LDO3_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO3_CFG2_ldo3_vgpr_en_START (0)
#define COMMON_PMIC_LDO3_CFG2_ldo3_vgpr_en_END (0)
#define COMMON_PMIC_LDO3_CFG2_ldo3_tran_set_START (1)
#define COMMON_PMIC_LDO3_CFG2_ldo3_tran_set_END (3)
#define COMMON_PMIC_LDO3_CFG2_ldo3_ocpd_set_START (4)
#define COMMON_PMIC_LDO3_CFG2_ldo3_ocpd_set_END (5)
#define COMMON_PMIC_LDO3_CFG2_ldo3_ocp_enn_START (6)
#define COMMON_PMIC_LDO3_CFG2_ldo3_ocp_enn_END (6)
#define COMMON_PMIC_LDO3_CFG2_ldo3_noise_set_START (7)
#define COMMON_PMIC_LDO3_CFG2_ldo3_noise_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_psrr1_set : 4;
        unsigned char ldo4_psrr_en : 1;
        unsigned char ldo4_ocp_set : 2;
        unsigned char ldo4_ocp_enn : 1;
    } reg;
} COMMON_PMIC_LDO4_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO4_CFG0_ldo4_psrr1_set_START (0)
#define COMMON_PMIC_LDO4_CFG0_ldo4_psrr1_set_END (3)
#define COMMON_PMIC_LDO4_CFG0_ldo4_psrr_en_START (4)
#define COMMON_PMIC_LDO4_CFG0_ldo4_psrr_en_END (4)
#define COMMON_PMIC_LDO4_CFG0_ldo4_ocp_set_START (5)
#define COMMON_PMIC_LDO4_CFG0_ldo4_ocp_set_END (6)
#define COMMON_PMIC_LDO4_CFG0_ldo4_ocp_enn_START (7)
#define COMMON_PMIC_LDO4_CFG0_ldo4_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_sst_set : 3;
        unsigned char ldo4_sst_ctrl : 1;
        unsigned char ldo4_psrr2_set : 4;
    } reg;
} COMMON_PMIC_LDO4_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO4_CFG1_ldo4_sst_set_START (0)
#define COMMON_PMIC_LDO4_CFG1_ldo4_sst_set_END (2)
#define COMMON_PMIC_LDO4_CFG1_ldo4_sst_ctrl_START (3)
#define COMMON_PMIC_LDO4_CFG1_ldo4_sst_ctrl_END (3)
#define COMMON_PMIC_LDO4_CFG1_ldo4_psrr2_set_START (4)
#define COMMON_PMIC_LDO4_CFG1_ldo4_psrr2_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo4_vrset : 3;
        unsigned char ldo4_vbias_set : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_LDO4_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO4_CFG2_ldo4_vrset_START (0)
#define COMMON_PMIC_LDO4_CFG2_ldo4_vrset_END (2)
#define COMMON_PMIC_LDO4_CFG2_ldo4_vbias_set_START (3)
#define COMMON_PMIC_LDO4_CFG2_ldo4_vbias_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_psrr1_set : 4;
        unsigned char ldo5_psrr_en : 1;
        unsigned char ldo5_ocp_set : 2;
        unsigned char ldo5_ocp_enn : 1;
    } reg;
} COMMON_PMIC_LDO5_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO5_CFG0_ldo5_psrr1_set_START (0)
#define COMMON_PMIC_LDO5_CFG0_ldo5_psrr1_set_END (3)
#define COMMON_PMIC_LDO5_CFG0_ldo5_psrr_en_START (4)
#define COMMON_PMIC_LDO5_CFG0_ldo5_psrr_en_END (4)
#define COMMON_PMIC_LDO5_CFG0_ldo5_ocp_set_START (5)
#define COMMON_PMIC_LDO5_CFG0_ldo5_ocp_set_END (6)
#define COMMON_PMIC_LDO5_CFG0_ldo5_ocp_enn_START (7)
#define COMMON_PMIC_LDO5_CFG0_ldo5_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_sst_set : 3;
        unsigned char ldo5_sst_ctrl : 1;
        unsigned char ldo5_psrr2_set : 4;
    } reg;
} COMMON_PMIC_LDO5_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO5_CFG1_ldo5_sst_set_START (0)
#define COMMON_PMIC_LDO5_CFG1_ldo5_sst_set_END (2)
#define COMMON_PMIC_LDO5_CFG1_ldo5_sst_ctrl_START (3)
#define COMMON_PMIC_LDO5_CFG1_ldo5_sst_ctrl_END (3)
#define COMMON_PMIC_LDO5_CFG1_ldo5_psrr2_set_START (4)
#define COMMON_PMIC_LDO5_CFG1_ldo5_psrr2_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo5_vrset : 3;
        unsigned char ldo5_vbias_set : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_LDO5_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO5_CFG2_ldo5_vrset_START (0)
#define COMMON_PMIC_LDO5_CFG2_ldo5_vrset_END (2)
#define COMMON_PMIC_LDO5_CFG2_ldo5_vbias_set_START (3)
#define COMMON_PMIC_LDO5_CFG2_ldo5_vbias_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_psrr1_set : 4;
        unsigned char ldo6_psrr_en : 1;
        unsigned char ldo6_ocp_set : 2;
        unsigned char ldo6_ocp_enn : 1;
    } reg;
} COMMON_PMIC_LDO6_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO6_CFG0_ldo6_psrr1_set_START (0)
#define COMMON_PMIC_LDO6_CFG0_ldo6_psrr1_set_END (3)
#define COMMON_PMIC_LDO6_CFG0_ldo6_psrr_en_START (4)
#define COMMON_PMIC_LDO6_CFG0_ldo6_psrr_en_END (4)
#define COMMON_PMIC_LDO6_CFG0_ldo6_ocp_set_START (5)
#define COMMON_PMIC_LDO6_CFG0_ldo6_ocp_set_END (6)
#define COMMON_PMIC_LDO6_CFG0_ldo6_ocp_enn_START (7)
#define COMMON_PMIC_LDO6_CFG0_ldo6_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_sst_set : 3;
        unsigned char ldo6_sst_ctrl : 1;
        unsigned char ldo6_psrr2_set : 4;
    } reg;
} COMMON_PMIC_LDO6_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO6_CFG1_ldo6_sst_set_START (0)
#define COMMON_PMIC_LDO6_CFG1_ldo6_sst_set_END (2)
#define COMMON_PMIC_LDO6_CFG1_ldo6_sst_ctrl_START (3)
#define COMMON_PMIC_LDO6_CFG1_ldo6_sst_ctrl_END (3)
#define COMMON_PMIC_LDO6_CFG1_ldo6_psrr2_set_START (4)
#define COMMON_PMIC_LDO6_CFG1_ldo6_psrr2_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo6_vrset : 3;
        unsigned char ldo6_vbias_set : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_LDO6_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO6_CFG2_ldo6_vrset_START (0)
#define COMMON_PMIC_LDO6_CFG2_ldo6_vrset_END (2)
#define COMMON_PMIC_LDO6_CFG2_ldo6_vbias_set_START (3)
#define COMMON_PMIC_LDO6_CFG2_ldo6_vbias_set_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo7_config : 8;
    } reg;
} COMMON_PMIC_LDO7_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO7_CFG0_ldo7_config_START (0)
#define COMMON_PMIC_LDO7_CFG0_ldo7_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo7_ocp_test : 1;
        unsigned char ldo7_ocp_set : 2;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_LDO7_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_test_START (0)
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_test_END (0)
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_set_START (1)
#define COMMON_PMIC_LDO7_CFG1_ldo7_ocp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_bw_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_LDO8_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO8_CFG0_ldo8_bw_en_START (0)
#define COMMON_PMIC_LDO8_CFG0_ldo8_bw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_config : 8;
    } reg;
} COMMON_PMIC_LDO8_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO8_CFG1_ldo8_config_START (0)
#define COMMON_PMIC_LDO8_CFG1_ldo8_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo8_vgpr_en : 1;
        unsigned char ldo8_tran_set : 3;
        unsigned char ldo8_ocpd_set : 2;
        unsigned char ldo8_ocp_enn : 1;
        unsigned char ldo8_noise_set : 1;
    } reg;
} COMMON_PMIC_LDO8_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO8_CFG2_ldo8_vgpr_en_START (0)
#define COMMON_PMIC_LDO8_CFG2_ldo8_vgpr_en_END (0)
#define COMMON_PMIC_LDO8_CFG2_ldo8_tran_set_START (1)
#define COMMON_PMIC_LDO8_CFG2_ldo8_tran_set_END (3)
#define COMMON_PMIC_LDO8_CFG2_ldo8_ocpd_set_START (4)
#define COMMON_PMIC_LDO8_CFG2_ldo8_ocpd_set_END (5)
#define COMMON_PMIC_LDO8_CFG2_ldo8_ocp_enn_START (6)
#define COMMON_PMIC_LDO8_CFG2_ldo8_ocp_enn_END (6)
#define COMMON_PMIC_LDO8_CFG2_ldo8_noise_set_START (7)
#define COMMON_PMIC_LDO8_CFG2_ldo8_noise_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo9_psrr1_set : 4;
        unsigned char ldo9_psrr_en : 1;
        unsigned char ldo9_ocp_set : 2;
        unsigned char ldo9_ocp_enn : 1;
    } reg;
} COMMON_PMIC_LDO9_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO9_CFG0_ldo9_psrr1_set_START (0)
#define COMMON_PMIC_LDO9_CFG0_ldo9_psrr1_set_END (3)
#define COMMON_PMIC_LDO9_CFG0_ldo9_psrr_en_START (4)
#define COMMON_PMIC_LDO9_CFG0_ldo9_psrr_en_END (4)
#define COMMON_PMIC_LDO9_CFG0_ldo9_ocp_set_START (5)
#define COMMON_PMIC_LDO9_CFG0_ldo9_ocp_set_END (6)
#define COMMON_PMIC_LDO9_CFG0_ldo9_ocp_enn_START (7)
#define COMMON_PMIC_LDO9_CFG0_ldo9_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo9_psrr3_set : 4;
        unsigned char ldo9_psrr2_set : 4;
    } reg;
} COMMON_PMIC_LDO9_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO9_CFG1_ldo9_psrr3_set_START (0)
#define COMMON_PMIC_LDO9_CFG1_ldo9_psrr3_set_END (3)
#define COMMON_PMIC_LDO9_CFG1_ldo9_psrr2_set_START (4)
#define COMMON_PMIC_LDO9_CFG1_ldo9_psrr2_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo9_vrset : 3;
        unsigned char ldo9_stb_set : 3;
        unsigned char ldo9_sst_set : 2;
    } reg;
} COMMON_PMIC_LDO9_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO9_CFG2_ldo9_vrset_START (0)
#define COMMON_PMIC_LDO9_CFG2_ldo9_vrset_END (2)
#define COMMON_PMIC_LDO9_CFG2_ldo9_stb_set_START (3)
#define COMMON_PMIC_LDO9_CFG2_ldo9_stb_set_END (5)
#define COMMON_PMIC_LDO9_CFG2_ldo9_sst_set_START (6)
#define COMMON_PMIC_LDO9_CFG2_ldo9_sst_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_eco_shield : 1;
        unsigned char pmuh_config : 6;
        unsigned char reserved : 1;
    } reg;
} COMMON_PMIC_LDO_PMUH_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO_PMUH_CFG0_pmuh_eco_shield_START (0)
#define COMMON_PMIC_LDO_PMUH_CFG0_pmuh_eco_shield_END (0)
#define COMMON_PMIC_LDO_PMUH_CFG0_pmuh_config_START (1)
#define COMMON_PMIC_LDO_PMUH_CFG0_pmuh_config_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char pmuh_stb_set : 4;
        unsigned char pmuh_ocp_set : 2;
        unsigned char reserved : 2;
    } reg;
} COMMON_PMIC_LDO_PMUH_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO_PMUH_CFG1_pmuh_stb_set_START (0)
#define COMMON_PMIC_LDO_PMUH_CFG1_pmuh_stb_set_END (3)
#define COMMON_PMIC_LDO_PMUH_CFG1_pmuh_ocp_set_START (4)
#define COMMON_PMIC_LDO_PMUH_CFG1_pmuh_ocp_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve0 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG0_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG0_ldo_reserve0_START (0)
#define COMMON_PMIC_LDO_RES_CFG0_ldo_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve1 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG1_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG1_ldo_reserve1_START (0)
#define COMMON_PMIC_LDO_RES_CFG1_ldo_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve2 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG2_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG2_ldo_reserve2_START (0)
#define COMMON_PMIC_LDO_RES_CFG2_ldo_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve3 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG3_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG3_ldo_reserve3_START (0)
#define COMMON_PMIC_LDO_RES_CFG3_ldo_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve4 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG4_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG4_ldo_reserve4_START (0)
#define COMMON_PMIC_LDO_RES_CFG4_ldo_reserve4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve5 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG5_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG5_ldo_reserve5_START (0)
#define COMMON_PMIC_LDO_RES_CFG5_ldo_reserve5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve6 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG6_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG6_ldo_reserve6_START (0)
#define COMMON_PMIC_LDO_RES_CFG6_ldo_reserve6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char ldo_reserve7 : 8;
    } reg;
} COMMON_PMIC_LDO_RES_CFG7_UNION;
#endif
#define COMMON_PMIC_LDO_RES_CFG7_ldo_reserve7_START (0)
#define COMMON_PMIC_LDO_RES_CFG7_ldo_reserve7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_bypass : 1;
        unsigned char fer_test : 1;
        unsigned char fer_snapshot : 1;
        unsigned char reserved : 5;
    } reg;
} COMMON_PMIC_FER_CTRL_UNION;
#endif
#define COMMON_PMIC_FER_CTRL_fer_bypass_START (0)
#define COMMON_PMIC_FER_CTRL_fer_bypass_END (0)
#define COMMON_PMIC_FER_CTRL_fer_test_START (1)
#define COMMON_PMIC_FER_CTRL_fer_test_END (1)
#define COMMON_PMIC_FER_CTRL_fer_snapshot_START (2)
#define COMMON_PMIC_FER_CTRL_fer_snapshot_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_psok_level : 1;
        unsigned char fer_pmu_irq_level : 1;
        unsigned char fer_buck_ocot_level : 1;
        unsigned char fer_buck_pgvok_level : 1;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_FER_EVENT_LEVEL_UNION;
#endif
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_pmu_psok_level_START (0)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_pmu_psok_level_END (0)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_pmu_irq_level_START (1)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_pmu_irq_level_END (1)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_buck_ocot_level_START (2)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_buck_ocot_level_END (2)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_buck_pgvok_level_START (3)
#define COMMON_PMIC_FER_EVENT_LEVEL_fer_buck_pgvok_level_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_pg_msk : 8;
    } reg;
} COMMON_PMIC_FER_BUCK_PG_MSK_UNION;
#endif
#define COMMON_PMIC_FER_BUCK_PG_MSK_fer_buck_pg_msk_START (0)
#define COMMON_PMIC_FER_BUCK_PG_MSK_fer_buck_pg_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_vok_msk : 8;
    } reg;
} COMMON_PMIC_FER_BUCK_VOK_MSK_UNION;
#endif
#define COMMON_PMIC_FER_BUCK_VOK_MSK_fer_buck_vok_msk_START (0)
#define COMMON_PMIC_FER_BUCK_VOK_MSK_fer_buck_vok_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_oc_msk : 8;
    } reg;
} COMMON_PMIC_FER_BUCK_OC_MSK_UNION;
#endif
#define COMMON_PMIC_FER_BUCK_OC_MSK_fer_buck_oc_msk_START (0)
#define COMMON_PMIC_FER_BUCK_OC_MSK_fer_buck_oc_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buck_ot_msk : 8;
    } reg;
} COMMON_PMIC_FER_BUCK_OT_MSK_UNION;
#endif
#define COMMON_PMIC_FER_BUCK_OT_MSK_fer_buck_ot_msk_START (0)
#define COMMON_PMIC_FER_BUCK_OT_MSK_fer_buck_ot_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_psok_msk : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_FER_PMU_PSOK_MSK_UNION;
#endif
#define COMMON_PMIC_FER_PMU_PSOK_MSK_fer_pmu_psok_msk_START (0)
#define COMMON_PMIC_FER_PMU_PSOK_MSK_fer_pmu_psok_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_irq_msk0 : 8;
    } reg;
} COMMON_PMIC_FER_PMU_IRQ_MSK0_UNION;
#endif
#define COMMON_PMIC_FER_PMU_IRQ_MSK0_fer_pmu_irq_msk0_START (0)
#define COMMON_PMIC_FER_PMU_IRQ_MSK0_fer_pmu_irq_msk0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_pmu_irq_msk1 : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_FER_PMU_IRQ_MSK1_UNION;
#endif
#define COMMON_PMIC_FER_PMU_IRQ_MSK1_fer_pmu_irq_msk1_START (0)
#define COMMON_PMIC_FER_PMU_IRQ_MSK1_fer_pmu_irq_msk1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_buck_pgvok : 8;
    } reg;
} COMMON_PMIC_FER_BUF_BUCK_PGVOK_UNION;
#endif
#define COMMON_PMIC_FER_BUF_BUCK_PGVOK_fer_buf_buck_pgvok_START (0)
#define COMMON_PMIC_FER_BUF_BUCK_PGVOK_fer_buf_buck_pgvok_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_buck_ocot : 8;
    } reg;
} COMMON_PMIC_FER_BUF_BUCK_OCOT_UNION;
#endif
#define COMMON_PMIC_FER_BUF_BUCK_OCOT_fer_buf_buck_ocot_START (0)
#define COMMON_PMIC_FER_BUF_BUCK_OCOT_fer_buf_buck_ocot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_pmu_psok : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_FER_BUF_PMU_PSOK_UNION;
#endif
#define COMMON_PMIC_FER_BUF_PMU_PSOK_fer_buf_pmu_psok_START (0)
#define COMMON_PMIC_FER_BUF_PMU_PSOK_fer_buf_pmu_psok_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_pmu_irq0 : 8;
    } reg;
} COMMON_PMIC_FER_BUF_PMU_IRQ0_UNION;
#endif
#define COMMON_PMIC_FER_BUF_PMU_IRQ0_fer_buf_pmu_irq0_START (0)
#define COMMON_PMIC_FER_BUF_PMU_IRQ0_fer_buf_pmu_irq0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_buf_pmu_irq1 : 4;
        unsigned char reserved : 4;
    } reg;
} COMMON_PMIC_FER_BUF_PMU_IRQ1_UNION;
#endif
#define COMMON_PMIC_FER_BUF_PMU_IRQ1_fer_buf_pmu_irq1_START (0)
#define COMMON_PMIC_FER_BUF_PMU_IRQ1_fer_buf_pmu_irq1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_abit_data : 8;
    } reg;
} COMMON_PMIC_FER_TRANS_ABIT_DATA_UNION;
#endif
#define COMMON_PMIC_FER_TRANS_ABIT_DATA_fer_trans_abit_data_START (0)
#define COMMON_PMIC_FER_TRANS_ABIT_DATA_fer_trans_abit_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_abit_addr : 8;
    } reg;
} COMMON_PMIC_FER_TRANS_ABIT_ADDR_UNION;
#endif
#define COMMON_PMIC_FER_TRANS_ABIT_ADDR_fer_trans_abit_addr_START (0)
#define COMMON_PMIC_FER_TRANS_ABIT_ADDR_fer_trans_abit_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_srbit_data : 8;
    } reg;
} COMMON_PMIC_FER_TRANS_SRBIT_DATA_UNION;
#endif
#define COMMON_PMIC_FER_TRANS_SRBIT_DATA_fer_trans_srbit_data_START (0)
#define COMMON_PMIC_FER_TRANS_SRBIT_DATA_fer_trans_srbit_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char fer_trans_srbit_addr : 8;
    } reg;
} COMMON_PMIC_FER_TRANS_SRBIT_ADDR_UNION;
#endif
#define COMMON_PMIC_FER_TRANS_SRBIT_ADDR_fer_trans_srbit_addr_START (0)
#define COMMON_PMIC_FER_TRANS_SRBIT_ADDR_fer_trans_srbit_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug0 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG0_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG0_spmi_debug0_START (0)
#define COMMON_PMIC_SPMI_DEBUG0_spmi_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug1 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG1_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG1_spmi_debug1_START (0)
#define COMMON_PMIC_SPMI_DEBUG1_spmi_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug2 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG2_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG2_spmi_debug2_START (0)
#define COMMON_PMIC_SPMI_DEBUG2_spmi_debug2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug3 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG3_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG3_spmi_debug3_START (0)
#define COMMON_PMIC_SPMI_DEBUG3_spmi_debug3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug4 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG4_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG4_spmi_debug4_START (0)
#define COMMON_PMIC_SPMI_DEBUG4_spmi_debug4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug5 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG5_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG5_spmi_debug5_START (0)
#define COMMON_PMIC_SPMI_DEBUG5_spmi_debug5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug6 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG6_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG6_spmi_debug6_START (0)
#define COMMON_PMIC_SPMI_DEBUG6_spmi_debug6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char spmi_debug7 : 8;
    } reg;
} COMMON_PMIC_SPMI_DEBUG7_UNION;
#endif
#define COMMON_PMIC_SPMI_DEBUG7_spmi_debug7_START (0)
#define COMMON_PMIC_SPMI_DEBUG7_spmi_debug7_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
