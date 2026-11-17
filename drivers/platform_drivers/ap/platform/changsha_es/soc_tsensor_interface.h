#ifndef __SOC_TSENSOR_INTERFACE_H__
#define __SOC_TSENSOR_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TSENSOR_TEMP_FLASH_FLAG_ADDR(base,m) ((base) + (0x000+0x300*(m)))
#define SOC_TSENSOR_TEMP_DET_EN_ADDR(base,m) ((base) + (0x0004+0x300*(m)))
#define SOC_TSENSOR_TEMP_CONFIG_ADDR(base,m) ((base) + (0x0008+0x300*(m)))
#define SOC_TSENSOR_TEMP_ADDR(base,m) ((base) + (0x000C+0x300*(m)))
#define SOC_TSENSOR_TSC_MODE_ADDR(base,m) ((base) + (0x0010+0x300*(m)))
#define SOC_TSENSOR_TEMP_RSV_CTRL_ADDR(base,m) ((base) + (0x0014+0x300*(m)))
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_ADDR(base,m) ((base) + (0x0018+0x300*(m)))
#define SOC_TSENSOR_TEMP_HIGH_TH_ADDR(base,m) ((base) + (0x001C+0x300*(m)))
#define SOC_TSENSOR_TEMP_LOW_TH_ADDR(base,m) ((base) + (0x0020+0x300*(m)))
#define SOC_TSENSOR_TEMP_RST_TH_ADDR(base,m) ((base) + (0x0024+0x300*(m)))
#define SOC_TSENSOR_TEMP_LAG_ADDR(base,m) ((base) + (0x0028+0x300*(m)))
#define SOC_TSENSOR_TEMP_INT_MSK_ADDR(base,m) ((base) + (0x002C+0x300*(m)))
#define SOC_TSENSOR_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x0030+0x300*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_H_ADDR(base,m) ((base) + (0x0034+0x300*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_H_ADDR(base,m) ((base) + (0x0038+0x300*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_L_ADDR(base,m) ((base) + (0x003C+0x300*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_L_ADDR(base,m) ((base) + (0x0040+0x300*(m)))
#define SOC_TSENSOR_TEMP_RST_MSK_ADDR(base,m) ((base) + (0x0044+0x300*(m)))
#define SOC_TSENSOR_TS_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0048+0x300*(m)))
#define SOC_TSENSOR_TS_EN2DIS_CLR_ADDR(base,m) ((base) + (0x004C+0x300*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0050+0x300*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ADDR(base,m) ((base) + (0x0054+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION_ADDR(base,m) ((base) + (0x0060+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION1_ADDR(base,m) ((base) + (0x0064+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION2_ADDR(base,m) ((base) + (0x0068+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION3_ADDR(base,m) ((base) + (0x006C+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION4_ADDR(base,m) ((base) + (0x0070+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION5_ADDR(base,m) ((base) + (0x0074+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION6_ADDR(base,m) ((base) + (0x0078+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION7_ADDR(base,m) ((base) + (0x007C+0x300*(m)))
#define SOC_TSENSOR_TEMP01_ADDR(base,m) ((base) + (0x0080+0x300*(m)))
#define SOC_TSENSOR_TEMP23_ADDR(base,m) ((base) + (0x0084+0x300*(m)))
#define SOC_TSENSOR_TEMP45_ADDR(base,m) ((base) + (0x0088+0x300*(m)))
#define SOC_TSENSOR_TEMP67_ADDR(base,m) ((base) + (0x008C+0x300*(m)))
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_ADDR(base,m) ((base) + (0x0090+0x300*(m)))
#define SOC_TSENSOR_RST_TEMP_STAT_ADDR(base,m) ((base) + (0x0094+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_ADDR(base,m) ((base) + (0x0098+0x300*(m)))
#define SOC_TSENSOR_TEMP_ORIG_ADDR(base,m) ((base) + (0x009C+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN01_ADDR(base,m) ((base) + (0x00A0+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN23_ADDR(base,m) ((base) + (0x00A4+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN45_ADDR(base,m) ((base) + (0x00A8+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN67_ADDR(base,m) ((base) + (0x00AC+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX01_ADDR(base,m) ((base) + (0x00B0+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX23_ADDR(base,m) ((base) + (0x00B4+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX45_ADDR(base,m) ((base) + (0x00B8+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX67_ADDR(base,m) ((base) + (0x00BC+0x300*(m)))
#define SOC_TSENSOR_PARAM_A_ADDR(base,m) ((base) + (0x0058+0x300*(m)))
#define SOC_TSENSOR_PARAM_B_ADDR(base,m) ((base) + (0x005C+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE0_SIGNED_ADDR(base,m) ((base) + (0x00C0+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE1_SIGNED_ADDR(base,m) ((base) + (0x00C4+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE2_SIGNED_ADDR(base,m) ((base) + (0x00C8+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE3_SIGNED_ADDR(base,m) ((base) + (0x00CC+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE4_SIGNED_ADDR(base,m) ((base) + (0x00D0+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE5_SIGNED_ADDR(base,m) ((base) + (0x00D4+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE6_SIGNED_ADDR(base,m) ((base) + (0x00D8+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE7_SIGNED_ADDR(base,m) ((base) + (0x00DC+0x300*(m)))
#define SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_ADDR(base,m) ((base) + (0x00E0+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_0_ADDR(base,m) ((base) + (0x00E4+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_1_ADDR(base,m) ((base) + (0x00E8+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_2_ADDR(base,m) ((base) + (0x00EC+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_3_ADDR(base,m) ((base) + (0x00F0+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_4_ADDR(base,m) ((base) + (0x00F4+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_5_ADDR(base,m) ((base) + (0x00F8+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_6_ADDR(base,m) ((base) + (0x00FC+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_7_ADDR(base,m) ((base) + (0x0100+0x300*(m)))
#define SOC_TSENSOR_TARGET_DBG_ADC_TH_ADDR(base,m) ((base) + (0x0104+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_ADDR(base,m) ((base) + (0x0108+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_ADDR(base,m) ((base) + (0x010C+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_0_ADDR(base,m) ((base) + (0x0110+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_1_ADDR(base,m) ((base) + (0x0114+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_2_ADDR(base,m) ((base) + (0x0118+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_3_ADDR(base,m) ((base) + (0x011C+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_4_ADDR(base,m) ((base) + (0x0120+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_5_ADDR(base,m) ((base) + (0x0124+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_6_ADDR(base,m) ((base) + (0x0128+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_7_ADDR(base,m) ((base) + (0x012C+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_ADDR(base,m) ((base) + (0x0130+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_ADDR(base,m) ((base) + (0x0134+0x300*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_ADDR(base,m) ((base) + (0x0138+0x300*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_ADDR(base,m) ((base) + (0x013C+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_TH_1_ADDR(base,m) ((base) + (0x0140+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_TH_2_ADDR(base,m) ((base) + (0x0144+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_TH_3_ADDR(base,m) ((base) + (0x0148+0x300*(m)))
#define SOC_TSENSOR_TSEN_MASK_ADDR(base) ((base) + (0x0F00UL))
#define SOC_TSENSOR_THERMAL_CTRL_ADDR(base) ((base) + (0x0F04UL))
#define SOC_TSENSOR_HOT_REG0_ADDR(base) ((base) + (0x0F08UL))
#define SOC_TSENSOR_HOT_REG1_ADDR(base) ((base) + (0x0F0CUL))
#define SOC_TSENSOR_TEMP_HOTSPOT_TH_ADDR(base) ((base) + (0x0F10UL))
#define SOC_TSENSOR_TEMP_VALUE_SEL0_ADDR(base) ((base) + (0x0F14UL))
#define SOC_TSENSOR_TEMP_VALUE_SEL1_ADDR(base) ((base) + (0x0F18UL))
#define SOC_TSENSOR_TEMP_VALUE_SEL2_ADDR(base) ((base) + (0x0F1CUL))
#define SOC_TSENSOR_TEMP_VALID_EXTEND_ADDR(base) ((base) + (0x0F20UL))
#else
#define SOC_TSENSOR_TEMP_FLASH_FLAG_ADDR(base,m) ((base) + (0x000+0x300*(m)))
#define SOC_TSENSOR_TEMP_DET_EN_ADDR(base,m) ((base) + (0x0004+0x300*(m)))
#define SOC_TSENSOR_TEMP_CONFIG_ADDR(base,m) ((base) + (0x0008+0x300*(m)))
#define SOC_TSENSOR_TEMP_ADDR(base,m) ((base) + (0x000C+0x300*(m)))
#define SOC_TSENSOR_TSC_MODE_ADDR(base,m) ((base) + (0x0010+0x300*(m)))
#define SOC_TSENSOR_TEMP_RSV_CTRL_ADDR(base,m) ((base) + (0x0014+0x300*(m)))
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_ADDR(base,m) ((base) + (0x0018+0x300*(m)))
#define SOC_TSENSOR_TEMP_HIGH_TH_ADDR(base,m) ((base) + (0x001C+0x300*(m)))
#define SOC_TSENSOR_TEMP_LOW_TH_ADDR(base,m) ((base) + (0x0020+0x300*(m)))
#define SOC_TSENSOR_TEMP_RST_TH_ADDR(base,m) ((base) + (0x0024+0x300*(m)))
#define SOC_TSENSOR_TEMP_LAG_ADDR(base,m) ((base) + (0x0028+0x300*(m)))
#define SOC_TSENSOR_TEMP_INT_MSK_ADDR(base,m) ((base) + (0x002C+0x300*(m)))
#define SOC_TSENSOR_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x0030+0x300*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_H_ADDR(base,m) ((base) + (0x0034+0x300*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_H_ADDR(base,m) ((base) + (0x0038+0x300*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_L_ADDR(base,m) ((base) + (0x003C+0x300*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_L_ADDR(base,m) ((base) + (0x0040+0x300*(m)))
#define SOC_TSENSOR_TEMP_RST_MSK_ADDR(base,m) ((base) + (0x0044+0x300*(m)))
#define SOC_TSENSOR_TS_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0048+0x300*(m)))
#define SOC_TSENSOR_TS_EN2DIS_CLR_ADDR(base,m) ((base) + (0x004C+0x300*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0050+0x300*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ADDR(base,m) ((base) + (0x0054+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION_ADDR(base,m) ((base) + (0x0060+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION1_ADDR(base,m) ((base) + (0x0064+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION2_ADDR(base,m) ((base) + (0x0068+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION3_ADDR(base,m) ((base) + (0x006C+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION4_ADDR(base,m) ((base) + (0x0070+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION5_ADDR(base,m) ((base) + (0x0074+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION6_ADDR(base,m) ((base) + (0x0078+0x300*(m)))
#define SOC_TSENSOR_CALIBRATION7_ADDR(base,m) ((base) + (0x007C+0x300*(m)))
#define SOC_TSENSOR_TEMP01_ADDR(base,m) ((base) + (0x0080+0x300*(m)))
#define SOC_TSENSOR_TEMP23_ADDR(base,m) ((base) + (0x0084+0x300*(m)))
#define SOC_TSENSOR_TEMP45_ADDR(base,m) ((base) + (0x0088+0x300*(m)))
#define SOC_TSENSOR_TEMP67_ADDR(base,m) ((base) + (0x008C+0x300*(m)))
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_ADDR(base,m) ((base) + (0x0090+0x300*(m)))
#define SOC_TSENSOR_RST_TEMP_STAT_ADDR(base,m) ((base) + (0x0094+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_ADDR(base,m) ((base) + (0x0098+0x300*(m)))
#define SOC_TSENSOR_TEMP_ORIG_ADDR(base,m) ((base) + (0x009C+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN01_ADDR(base,m) ((base) + (0x00A0+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN23_ADDR(base,m) ((base) + (0x00A4+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN45_ADDR(base,m) ((base) + (0x00A8+0x300*(m)))
#define SOC_TSENSOR_TEMP_MIN67_ADDR(base,m) ((base) + (0x00AC+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX01_ADDR(base,m) ((base) + (0x00B0+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX23_ADDR(base,m) ((base) + (0x00B4+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX45_ADDR(base,m) ((base) + (0x00B8+0x300*(m)))
#define SOC_TSENSOR_TEMP_MAX67_ADDR(base,m) ((base) + (0x00BC+0x300*(m)))
#define SOC_TSENSOR_PARAM_A_ADDR(base,m) ((base) + (0x0058+0x300*(m)))
#define SOC_TSENSOR_PARAM_B_ADDR(base,m) ((base) + (0x005C+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE0_SIGNED_ADDR(base,m) ((base) + (0x00C0+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE1_SIGNED_ADDR(base,m) ((base) + (0x00C4+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE2_SIGNED_ADDR(base,m) ((base) + (0x00C8+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE3_SIGNED_ADDR(base,m) ((base) + (0x00CC+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE4_SIGNED_ADDR(base,m) ((base) + (0x00D0+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE5_SIGNED_ADDR(base,m) ((base) + (0x00D4+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE6_SIGNED_ADDR(base,m) ((base) + (0x00D8+0x300*(m)))
#define SOC_TSENSOR_TEMP_VALUE7_SIGNED_ADDR(base,m) ((base) + (0x00DC+0x300*(m)))
#define SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_ADDR(base,m) ((base) + (0x00E0+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_0_ADDR(base,m) ((base) + (0x00E4+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_1_ADDR(base,m) ((base) + (0x00E8+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_2_ADDR(base,m) ((base) + (0x00EC+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_3_ADDR(base,m) ((base) + (0x00F0+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_4_ADDR(base,m) ((base) + (0x00F4+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_5_ADDR(base,m) ((base) + (0x00F8+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_6_ADDR(base,m) ((base) + (0x00FC+0x300*(m)))
#define SOC_TSENSOR_TEMP_OUT_DBG_7_ADDR(base,m) ((base) + (0x0100+0x300*(m)))
#define SOC_TSENSOR_TARGET_DBG_ADC_TH_ADDR(base,m) ((base) + (0x0104+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_ADDR(base,m) ((base) + (0x0108+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_ADDR(base,m) ((base) + (0x010C+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_0_ADDR(base,m) ((base) + (0x0110+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_1_ADDR(base,m) ((base) + (0x0114+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_2_ADDR(base,m) ((base) + (0x0118+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_3_ADDR(base,m) ((base) + (0x011C+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_4_ADDR(base,m) ((base) + (0x0120+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_5_ADDR(base,m) ((base) + (0x0124+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_6_ADDR(base,m) ((base) + (0x0128+0x300*(m)))
#define SOC_TSENSOR_DELTA_ADC_INFO_7_ADDR(base,m) ((base) + (0x012C+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_ADDR(base,m) ((base) + (0x0130+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_ADDR(base,m) ((base) + (0x0134+0x300*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_ADDR(base,m) ((base) + (0x0138+0x300*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_ADDR(base,m) ((base) + (0x013C+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_TH_1_ADDR(base,m) ((base) + (0x0140+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_TH_2_ADDR(base,m) ((base) + (0x0144+0x300*(m)))
#define SOC_TSENSOR_TEMP_SLOPE_TH_3_ADDR(base,m) ((base) + (0x0148+0x300*(m)))
#define SOC_TSENSOR_TSEN_MASK_ADDR(base) ((base) + (0x0F00))
#define SOC_TSENSOR_THERMAL_CTRL_ADDR(base) ((base) + (0x0F04))
#define SOC_TSENSOR_HOT_REG0_ADDR(base) ((base) + (0x0F08))
#define SOC_TSENSOR_HOT_REG1_ADDR(base) ((base) + (0x0F0C))
#define SOC_TSENSOR_TEMP_HOTSPOT_TH_ADDR(base) ((base) + (0x0F10))
#define SOC_TSENSOR_TEMP_VALUE_SEL0_ADDR(base) ((base) + (0x0F14))
#define SOC_TSENSOR_TEMP_VALUE_SEL1_ADDR(base) ((base) + (0x0F18))
#define SOC_TSENSOR_TEMP_VALUE_SEL2_ADDR(base) ((base) + (0x0F1C))
#define SOC_TSENSOR_TEMP_VALID_EXTEND_ADDR(base) ((base) + (0x0F20))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_flash_flag : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_FLASH_FLAG_UNION;
#endif
#define SOC_TSENSOR_TEMP_FLASH_FLAG_temp_flash_flag_START (0)
#define SOC_TSENSOR_TEMP_FLASH_FLAG_temp_flash_flag_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_det_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_DET_EN_UNION;
#endif
#define SOC_TSENSOR_TEMP_DET_EN_temp_det_en_START (0)
#define SOC_TSENSOR_TEMP_DET_EN_temp_det_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sample_num : 8;
        unsigned int temp_clk_sel : 1;
        unsigned int temp_cfg : 16;
        unsigned int temp_ct_sel : 2;
        unsigned int temp_calib : 1;
        unsigned int temp_calib_vmode_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_TSENSOR_TEMP_CONFIG_UNION;
#endif
#define SOC_TSENSOR_TEMP_CONFIG_sample_num_START (0)
#define SOC_TSENSOR_TEMP_CONFIG_sample_num_END (7)
#define SOC_TSENSOR_TEMP_CONFIG_temp_clk_sel_START (8)
#define SOC_TSENSOR_TEMP_CONFIG_temp_clk_sel_END (8)
#define SOC_TSENSOR_TEMP_CONFIG_temp_cfg_START (9)
#define SOC_TSENSOR_TEMP_CONFIG_temp_cfg_END (24)
#define SOC_TSENSOR_TEMP_CONFIG_temp_ct_sel_START (25)
#define SOC_TSENSOR_TEMP_CONFIG_temp_ct_sel_END (26)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_START (27)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_END (27)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_vmode_en_START (28)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_vmode_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp : 16;
        unsigned int temp_num : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_TEMP_UNION;
#endif
#define SOC_TSENSOR_TEMP_temp_START (0)
#define SOC_TSENSOR_TEMP_temp_END (15)
#define SOC_TSENSOR_TEMP_temp_num_START (16)
#define SOC_TSENSOR_TEMP_temp_num_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_det_mode : 1;
        unsigned int temp_remote_softsel : 3;
        unsigned int tsensor_num : 4;
        unsigned int disable_delay : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TSC_MODE_UNION;
#endif
#define SOC_TSENSOR_TSC_MODE_temp_det_mode_START (0)
#define SOC_TSENSOR_TSC_MODE_temp_det_mode_END (0)
#define SOC_TSENSOR_TSC_MODE_temp_remote_softsel_START (1)
#define SOC_TSENSOR_TSC_MODE_temp_remote_softsel_END (3)
#define SOC_TSENSOR_TSC_MODE_tsensor_num_START (4)
#define SOC_TSENSOR_TSC_MODE_tsensor_num_END (7)
#define SOC_TSENSOR_TSC_MODE_disable_delay_START (8)
#define SOC_TSENSOR_TSC_MODE_disable_delay_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_th_over_h_xor_bypass : 8;
        unsigned int temp_th_over_h_rising_bypass : 8;
        unsigned int temp_th_over_l_xor_bypass : 8;
        unsigned int temp_th_over_l_rising_bypass : 8;
    } reg;
} SOC_TSENSOR_TEMP_RSV_CTRL_UNION;
#endif
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_h_xor_bypass_START (0)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_h_xor_bypass_END (7)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_h_rising_bypass_START (8)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_h_rising_bypass_END (15)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_l_xor_bypass_START (16)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_l_xor_bypass_END (23)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_l_rising_bypass_START (24)
#define SOC_TSENSOR_TEMP_RSV_CTRL_temp_th_over_l_rising_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_update_signal_msk0 : 1;
        unsigned int temp_update_signal_msk1 : 1;
        unsigned int temp_update_signal_msk2 : 1;
        unsigned int temp_update_signal_msk3 : 1;
        unsigned int temp_update_signal_msk4 : 1;
        unsigned int temp_update_signal_msk5 : 1;
        unsigned int temp_update_signal_msk6 : 1;
        unsigned int temp_update_signal_msk7 : 1;
        unsigned int reserved : 8;
        unsigned int temp_update_flag_msk_bitmsk : 16;
    } reg;
} SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk0_START (0)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk0_END (0)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk1_START (1)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk1_END (1)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk2_START (2)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk2_END (2)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk3_START (3)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk3_END (3)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk4_START (4)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk4_END (4)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk5_START (5)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk5_END (5)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk6_START (6)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk6_END (6)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk7_START (7)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_signal_msk7_END (7)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_flag_msk_bitmsk_START (16)
#define SOC_TSENSOR_TEMP_UPDATE_FLAG_MSK_temp_update_flag_msk_bitmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_HIGH_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_HIGH_TH_temp_th_START (0)
#define SOC_TSENSOR_TEMP_HIGH_TH_temp_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_low_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_LOW_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_LOW_TH_temp_low_th_START (0)
#define SOC_TSENSOR_TEMP_LOW_TH_temp_low_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rst_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_RST_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_RST_TH_temp_rst_th_START (0)
#define SOC_TSENSOR_TEMP_RST_TH_temp_rst_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_lag : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_TSENSOR_TEMP_LAG_UNION;
#endif
#define SOC_TSENSOR_TEMP_LAG_temp_lag_START (0)
#define SOC_TSENSOR_TEMP_LAG_temp_lag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_int_h_msk0 : 1;
        unsigned int temp_int_h_msk1 : 1;
        unsigned int temp_int_h_msk2 : 1;
        unsigned int temp_int_h_msk3 : 1;
        unsigned int temp_int_h_msk4 : 1;
        unsigned int temp_int_h_msk5 : 1;
        unsigned int temp_int_h_msk6 : 1;
        unsigned int temp_int_h_msk7 : 1;
        unsigned int temp_int_l_msk0 : 1;
        unsigned int temp_int_l_msk1 : 1;
        unsigned int temp_int_l_msk2 : 1;
        unsigned int temp_int_l_msk3 : 1;
        unsigned int temp_int_l_msk4 : 1;
        unsigned int temp_int_l_msk5 : 1;
        unsigned int temp_int_l_msk6 : 1;
        unsigned int temp_int_l_msk7 : 1;
        unsigned int temp_int_msk_msk : 16;
    } reg;
} SOC_TSENSOR_TEMP_INT_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk0_START (0)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk0_END (0)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk1_START (1)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk1_END (1)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk2_START (2)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk2_END (2)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk3_START (3)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk3_END (3)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk4_START (4)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk4_END (4)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk5_START (5)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk5_END (5)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk6_START (6)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk6_END (6)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk7_START (7)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_h_msk7_END (7)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk0_START (8)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk0_END (8)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk1_START (9)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk1_END (9)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk2_START (10)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk2_END (10)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk3_START (11)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk3_END (11)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk4_START (12)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk4_END (12)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk5_START (13)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk5_END (13)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk6_START (14)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk6_END (14)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk7_START (15)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_l_msk7_END (15)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk_msk_START (16)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_int_h_clr0 : 1;
        unsigned int temp_int_h_clr1 : 1;
        unsigned int temp_int_h_clr2 : 1;
        unsigned int temp_int_h_clr3 : 1;
        unsigned int temp_int_h_clr4 : 1;
        unsigned int temp_int_h_clr5 : 1;
        unsigned int temp_int_h_clr6 : 1;
        unsigned int temp_int_h_clr7 : 1;
        unsigned int temp_int_l_clr0 : 1;
        unsigned int temp_int_l_clr1 : 1;
        unsigned int temp_int_l_clr2 : 1;
        unsigned int temp_int_l_clr3 : 1;
        unsigned int temp_int_l_clr4 : 1;
        unsigned int temp_int_l_clr5 : 1;
        unsigned int temp_int_l_clr6 : 1;
        unsigned int temp_int_l_clr7 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_INT_CLR_UNION;
#endif
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr0_START (0)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr0_END (0)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr1_START (1)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr1_END (1)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr2_START (2)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr2_END (2)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr3_START (3)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr3_END (3)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr4_START (4)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr4_END (4)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr5_START (5)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr5_END (5)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr6_START (6)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr6_END (6)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr7_START (7)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_h_clr7_END (7)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr0_START (8)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr0_END (8)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr1_START (9)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr1_END (9)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr2_START (10)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr2_END (10)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr3_START (11)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr3_END (11)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr4_START (12)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr4_END (12)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr5_START (13)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr5_END (13)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr6_START (14)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr6_END (14)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr7_START (15)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_l_clr7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rawint_h0 : 1;
        unsigned int temp_rawint_h1 : 1;
        unsigned int temp_rawint_h2 : 1;
        unsigned int temp_rawint_h3 : 1;
        unsigned int temp_rawint_h4 : 1;
        unsigned int temp_rawint_h5 : 1;
        unsigned int temp_rawint_h6 : 1;
        unsigned int temp_rawint_h7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_H_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h0_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h0_END (0)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h1_START (1)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h1_END (1)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h2_START (2)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h2_END (2)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h3_START (3)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h3_END (3)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h4_START (4)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h4_END (4)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h5_START (5)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h5_END (5)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h6_START (6)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h6_END (6)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h7_START (7)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_mskint_h0 : 1;
        unsigned int temp_mskint_h1 : 1;
        unsigned int temp_mskint_h2 : 1;
        unsigned int temp_mskint_h3 : 1;
        unsigned int temp_mskint_h4 : 1;
        unsigned int temp_mskint_h5 : 1;
        unsigned int temp_mskint_h6 : 1;
        unsigned int temp_mskint_h7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_H_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h0_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h0_END (0)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h1_START (1)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h1_END (1)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h2_START (2)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h2_END (2)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h3_START (3)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h3_END (3)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h4_START (4)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h4_END (4)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h5_START (5)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h5_END (5)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h6_START (6)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h6_END (6)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h7_START (7)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rawint_l0 : 1;
        unsigned int temp_rawint_l1 : 1;
        unsigned int temp_rawint_l2 : 1;
        unsigned int temp_rawint_l3 : 1;
        unsigned int temp_rawint_l4 : 1;
        unsigned int temp_rawint_l5 : 1;
        unsigned int temp_rawint_l6 : 1;
        unsigned int temp_rawint_l7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_L_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l0_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l0_END (0)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l1_START (1)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l1_END (1)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l2_START (2)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l2_END (2)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l3_START (3)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l3_END (3)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l4_START (4)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l4_END (4)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l5_START (5)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l5_END (5)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l6_START (6)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l6_END (6)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l7_START (7)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_mskint_l0 : 1;
        unsigned int temp_mskint_l1 : 1;
        unsigned int temp_mskint_l2 : 1;
        unsigned int temp_mskint_l3 : 1;
        unsigned int temp_mskint_l4 : 1;
        unsigned int temp_mskint_l5 : 1;
        unsigned int temp_mskint_l6 : 1;
        unsigned int temp_mskint_l7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_L_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l0_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l0_END (0)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l1_START (1)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l1_END (1)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l2_START (2)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l2_END (2)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l3_START (3)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l3_END (3)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l4_START (4)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l4_END (4)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l5_START (5)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l5_END (5)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l6_START (6)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l6_END (6)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l7_START (7)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rst_msk : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_RST_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_RST_MSK_temp_rst_msk_START (0)
#define SOC_TSENSOR_TEMP_RST_MSK_temp_rst_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_sensor_en2dis_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TS_EN2DIS_MSK_UNION;
#endif
#define SOC_TSENSOR_TS_EN2DIS_MSK_t_sensor_en2dis_msk_START (0)
#define SOC_TSENSOR_TS_EN2DIS_MSK_t_sensor_en2dis_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int t_sensor_en2dis_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TS_EN2DIS_CLR_UNION;
#endif
#define SOC_TSENSOR_TS_EN2DIS_CLR_t_sensor_en2dis_clr_START (0)
#define SOC_TSENSOR_TS_EN2DIS_CLR_t_sensor_en2dis_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_ctrl_en2dis_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TSC_EN2DIS_MSK_UNION;
#endif
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ts_ctrl_en2dis_msk_START (0)
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ts_ctrl_en2dis_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_ctrl_en2dis_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TSC_EN2DIS_CLR_UNION;
#endif
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ts_ctrl_en2dis_clr_START (0)
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ts_ctrl_en2dis_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int local_sensorerror : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION_local_sensorerror_START (0)
#define SOC_TSENSOR_CALIBRATION_local_sensorerror_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION1_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION1_remote_sensorerror1_START (0)
#define SOC_TSENSOR_CALIBRATION1_remote_sensorerror1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION2_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION2_remote_sensorerror2_START (0)
#define SOC_TSENSOR_CALIBRATION2_remote_sensorerror2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror3 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION3_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION3_remote_sensorerror3_START (0)
#define SOC_TSENSOR_CALIBRATION3_remote_sensorerror3_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror4 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION4_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION4_remote_sensorerror4_START (0)
#define SOC_TSENSOR_CALIBRATION4_remote_sensorerror4_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror5 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION5_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION5_remote_sensorerror5_START (0)
#define SOC_TSENSOR_CALIBRATION5_remote_sensorerror5_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror6 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION6_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION6_remote_sensorerror6_START (0)
#define SOC_TSENSOR_CALIBRATION6_remote_sensorerror6_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_sensorerror7 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION7_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION7_remote_sensorerror7_START (0)
#define SOC_TSENSOR_CALIBRATION7_remote_sensorerror7_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp0 : 16;
        unsigned int temp1 : 16;
    } reg;
} SOC_TSENSOR_TEMP01_UNION;
#endif
#define SOC_TSENSOR_TEMP01_temp0_START (0)
#define SOC_TSENSOR_TEMP01_temp0_END (15)
#define SOC_TSENSOR_TEMP01_temp1_START (16)
#define SOC_TSENSOR_TEMP01_temp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp2 : 16;
        unsigned int temp3 : 16;
    } reg;
} SOC_TSENSOR_TEMP23_UNION;
#endif
#define SOC_TSENSOR_TEMP23_temp2_START (0)
#define SOC_TSENSOR_TEMP23_temp2_END (15)
#define SOC_TSENSOR_TEMP23_temp3_START (16)
#define SOC_TSENSOR_TEMP23_temp3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp4 : 16;
        unsigned int temp5 : 16;
    } reg;
} SOC_TSENSOR_TEMP45_UNION;
#endif
#define SOC_TSENSOR_TEMP45_temp4_START (0)
#define SOC_TSENSOR_TEMP45_temp4_END (15)
#define SOC_TSENSOR_TEMP45_temp5_START (16)
#define SOC_TSENSOR_TEMP45_temp5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp6 : 16;
        unsigned int temp7 : 16;
    } reg;
} SOC_TSENSOR_TEMP67_UNION;
#endif
#define SOC_TSENSOR_TEMP67_temp6_START (0)
#define SOC_TSENSOR_TEMP67_temp6_END (15)
#define SOC_TSENSOR_TEMP67_temp7_START (16)
#define SOC_TSENSOR_TEMP67_temp7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int remote_bypass0 : 1;
        unsigned int remote_bypass1 : 1;
        unsigned int remote_bypass2 : 1;
        unsigned int remote_bypass3 : 1;
        unsigned int remote_bypass4 : 1;
        unsigned int remote_bypass5 : 1;
        unsigned int remote_bypass6 : 1;
        unsigned int remote_bypass7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_REMOTE_FAIL_FLAG_UNION;
#endif
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass0_START (0)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass0_END (0)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass1_START (1)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass1_END (1)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass2_START (2)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass2_END (2)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass3_START (3)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass3_END (3)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass4_START (4)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass4_END (4)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass5_START (5)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass5_END (5)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass6_START (6)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass6_END (6)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass7_START (7)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_tempstat : 16;
        unsigned int rst_remote_sel_stat : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_RST_TEMP_STAT_UNION;
#endif
#define SOC_TSENSOR_RST_TEMP_STAT_rst_tempstat_START (0)
#define SOC_TSENSOR_RST_TEMP_STAT_rst_tempstat_END (15)
#define SOC_TSENSOR_RST_TEMP_STAT_rst_remote_sel_stat_START (16)
#define SOC_TSENSOR_RST_TEMP_STAT_rst_remote_sel_stat_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_smpl_st_en : 1;
        unsigned int temp_dbgclk_en : 1;
        unsigned int temp_thermal_st_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TSENSOR_TEMP_MAINTAIN_CTRL_UNION;
#endif
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_temp_smpl_st_en_START (0)
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_temp_smpl_st_en_END (0)
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_temp_dbgclk_en_START (1)
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_temp_dbgclk_en_END (1)
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_temp_thermal_st_en_START (2)
#define SOC_TSENSOR_TEMP_MAINTAIN_CTRL_temp_thermal_st_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_orig : 16;
        unsigned int temp_num_orig : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_TEMP_ORIG_UNION;
#endif
#define SOC_TSENSOR_TEMP_ORIG_temp_orig_START (0)
#define SOC_TSENSOR_TEMP_ORIG_temp_orig_END (15)
#define SOC_TSENSOR_TEMP_ORIG_temp_num_orig_START (16)
#define SOC_TSENSOR_TEMP_ORIG_temp_num_orig_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_min0 : 16;
        unsigned int temp_min1 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MIN01_UNION;
#endif
#define SOC_TSENSOR_TEMP_MIN01_temp_min0_START (0)
#define SOC_TSENSOR_TEMP_MIN01_temp_min0_END (15)
#define SOC_TSENSOR_TEMP_MIN01_temp_min1_START (16)
#define SOC_TSENSOR_TEMP_MIN01_temp_min1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_min2 : 16;
        unsigned int temp_min3 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MIN23_UNION;
#endif
#define SOC_TSENSOR_TEMP_MIN23_temp_min2_START (0)
#define SOC_TSENSOR_TEMP_MIN23_temp_min2_END (15)
#define SOC_TSENSOR_TEMP_MIN23_temp_min3_START (16)
#define SOC_TSENSOR_TEMP_MIN23_temp_min3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_min4 : 16;
        unsigned int temp_min5 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MIN45_UNION;
#endif
#define SOC_TSENSOR_TEMP_MIN45_temp_min4_START (0)
#define SOC_TSENSOR_TEMP_MIN45_temp_min4_END (15)
#define SOC_TSENSOR_TEMP_MIN45_temp_min5_START (16)
#define SOC_TSENSOR_TEMP_MIN45_temp_min5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_min6 : 16;
        unsigned int temp_min7 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MIN67_UNION;
#endif
#define SOC_TSENSOR_TEMP_MIN67_temp_min6_START (0)
#define SOC_TSENSOR_TEMP_MIN67_temp_min6_END (15)
#define SOC_TSENSOR_TEMP_MIN67_temp_min7_START (16)
#define SOC_TSENSOR_TEMP_MIN67_temp_min7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_max0 : 16;
        unsigned int temp_max1 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MAX01_UNION;
#endif
#define SOC_TSENSOR_TEMP_MAX01_temp_max0_START (0)
#define SOC_TSENSOR_TEMP_MAX01_temp_max0_END (15)
#define SOC_TSENSOR_TEMP_MAX01_temp_max1_START (16)
#define SOC_TSENSOR_TEMP_MAX01_temp_max1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_max2 : 16;
        unsigned int temp_max3 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MAX23_UNION;
#endif
#define SOC_TSENSOR_TEMP_MAX23_temp_max2_START (0)
#define SOC_TSENSOR_TEMP_MAX23_temp_max2_END (15)
#define SOC_TSENSOR_TEMP_MAX23_temp_max3_START (16)
#define SOC_TSENSOR_TEMP_MAX23_temp_max3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_max4 : 16;
        unsigned int temp_max5 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MAX45_UNION;
#endif
#define SOC_TSENSOR_TEMP_MAX45_temp_max4_START (0)
#define SOC_TSENSOR_TEMP_MAX45_temp_max4_END (15)
#define SOC_TSENSOR_TEMP_MAX45_temp_max5_START (16)
#define SOC_TSENSOR_TEMP_MAX45_temp_max5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_max6 : 16;
        unsigned int temp_max7 : 16;
    } reg;
} SOC_TSENSOR_TEMP_MAX67_UNION;
#endif
#define SOC_TSENSOR_TEMP_MAX67_temp_max6_START (0)
#define SOC_TSENSOR_TEMP_MAX67_temp_max6_END (15)
#define SOC_TSENSOR_TEMP_MAX67_temp_max7_START (16)
#define SOC_TSENSOR_TEMP_MAX67_temp_max7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int param_a : 32;
    } reg;
} SOC_TSENSOR_PARAM_A_UNION;
#endif
#define SOC_TSENSOR_PARAM_A_param_a_START (0)
#define SOC_TSENSOR_PARAM_A_param_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int param_b : 32;
    } reg;
} SOC_TSENSOR_PARAM_B_UNION;
#endif
#define SOC_TSENSOR_PARAM_B_param_b_START (0)
#define SOC_TSENSOR_PARAM_B_param_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value0_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE0_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE0_SIGNED_temp_value0_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE0_SIGNED_temp_value0_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value1_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE1_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE1_SIGNED_temp_value1_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE1_SIGNED_temp_value1_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value2_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE2_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE2_SIGNED_temp_value2_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE2_SIGNED_temp_value2_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value3_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE3_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE3_SIGNED_temp_value3_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE3_SIGNED_temp_value3_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value4_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE4_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE4_SIGNED_temp_value4_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE4_SIGNED_temp_value4_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value5_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE5_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE5_SIGNED_temp_value5_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE5_SIGNED_temp_value5_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value6_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE6_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE6_SIGNED_temp_value6_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE6_SIGNED_temp_value6_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value7_signed : 32;
    } reg;
} SOC_TSENSOR_TEMP_VALUE7_SIGNED_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE7_SIGNED_temp_value7_signed_START (0)
#define SOC_TSENSOR_TEMP_VALUE7_SIGNED_temp_value7_signed_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int target_dbg_remote_sel : 3;
        unsigned int reserved_0 : 13;
        unsigned int temp_out_dbg16 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_UNION;
#endif
#define SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_target_dbg_remote_sel_START (0)
#define SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_target_dbg_remote_sel_END (2)
#define SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_temp_out_dbg16_START (16)
#define SOC_TSENSOR_TARGET_DBG_REMOTE_SEL_temp_out_dbg16_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg0 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg1 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_0_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_0_temp_out_dbg0_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_0_temp_out_dbg0_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_0_temp_out_dbg1_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_0_temp_out_dbg1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg2 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg3 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_1_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_1_temp_out_dbg2_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_1_temp_out_dbg2_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_1_temp_out_dbg3_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_1_temp_out_dbg3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg4 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg5 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_2_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_2_temp_out_dbg4_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_2_temp_out_dbg4_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_2_temp_out_dbg5_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_2_temp_out_dbg5_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg6 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg7 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_3_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_3_temp_out_dbg6_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_3_temp_out_dbg6_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_3_temp_out_dbg7_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_3_temp_out_dbg7_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg8 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg9 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_4_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_4_temp_out_dbg8_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_4_temp_out_dbg8_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_4_temp_out_dbg9_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_4_temp_out_dbg9_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg10 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg11 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_5_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_5_temp_out_dbg10_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_5_temp_out_dbg10_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_5_temp_out_dbg11_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_5_temp_out_dbg11_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg12 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg13 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_6_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_6_temp_out_dbg12_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_6_temp_out_dbg12_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_6_temp_out_dbg13_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_6_temp_out_dbg13_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_out_dbg14 : 11;
        unsigned int reserved_0 : 5;
        unsigned int temp_out_dbg15 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_TSENSOR_TEMP_OUT_DBG_7_UNION;
#endif
#define SOC_TSENSOR_TEMP_OUT_DBG_7_temp_out_dbg14_START (0)
#define SOC_TSENSOR_TEMP_OUT_DBG_7_temp_out_dbg14_END (10)
#define SOC_TSENSOR_TEMP_OUT_DBG_7_temp_out_dbg15_START (16)
#define SOC_TSENSOR_TEMP_OUT_DBG_7_temp_out_dbg15_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int target_dbg_adc_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TARGET_DBG_ADC_TH_UNION;
#endif
#define SOC_TSENSOR_TARGET_DBG_ADC_TH_target_dbg_adc_th_START (0)
#define SOC_TSENSOR_TARGET_DBG_ADC_TH_target_dbg_adc_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_max_local : 8;
        unsigned int delta_adc_max_remote0 : 8;
        unsigned int delta_adc_max_remote1 : 8;
        unsigned int delta_adc_max_remote2 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_local_START (0)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_local_END (7)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_remote0_START (8)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_remote0_END (15)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_remote1_START (16)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_remote1_END (23)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_remote2_START (24)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_0_delta_adc_max_remote2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_max_remote3 : 8;
        unsigned int delta_adc_max_remote4 : 8;
        unsigned int delta_adc_max_remote5 : 8;
        unsigned int delta_adc_max_remote6 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote3_START (0)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote3_END (7)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote4_START (8)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote4_END (15)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote5_START (16)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote5_END (23)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote6_START (24)
#define SOC_TSENSOR_DELTA_ADC_MAX_INFO_1_delta_adc_max_remote6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_local : 8;
        unsigned int delta_adc_ff2_local : 8;
        unsigned int delta_adc_ff3_local : 8;
        unsigned int delta_adc_ff4_local : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_0_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff1_local_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff1_local_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff2_local_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff2_local_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff3_local_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff3_local_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff4_local_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_0_delta_adc_ff4_local_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote0 : 8;
        unsigned int delta_adc_ff2_remote0 : 8;
        unsigned int delta_adc_ff3_remote0 : 8;
        unsigned int delta_adc_ff4_remote0 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_1_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff1_remote0_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff1_remote0_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff2_remote0_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff2_remote0_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff3_remote0_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff3_remote0_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff4_remote0_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_1_delta_adc_ff4_remote0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote1 : 8;
        unsigned int delta_adc_ff2_remote1 : 8;
        unsigned int delta_adc_ff3_remote1 : 8;
        unsigned int delta_adc_ff4_remote1 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_2_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff1_remote1_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff1_remote1_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff2_remote1_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff2_remote1_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff3_remote1_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff3_remote1_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff4_remote1_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_2_delta_adc_ff4_remote1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote2 : 8;
        unsigned int delta_adc_ff2_remote2 : 8;
        unsigned int delta_adc_ff3_remote2 : 8;
        unsigned int delta_adc_ff4_remote2 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_3_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff1_remote2_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff1_remote2_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff2_remote2_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff2_remote2_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff3_remote2_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff3_remote2_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff4_remote2_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_3_delta_adc_ff4_remote2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote3 : 8;
        unsigned int delta_adc_ff2_remote3 : 8;
        unsigned int delta_adc_ff3_remote3 : 8;
        unsigned int delta_adc_ff4_remote3 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_4_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff1_remote3_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff1_remote3_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff2_remote3_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff2_remote3_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff3_remote3_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff3_remote3_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff4_remote3_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_4_delta_adc_ff4_remote3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote4 : 8;
        unsigned int delta_adc_ff2_remote4 : 8;
        unsigned int delta_adc_ff3_remote4 : 8;
        unsigned int delta_adc_ff4_remote4 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_5_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff1_remote4_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff1_remote4_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff2_remote4_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff2_remote4_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff3_remote4_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff3_remote4_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff4_remote4_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_5_delta_adc_ff4_remote4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote5 : 8;
        unsigned int delta_adc_ff2_remote5 : 8;
        unsigned int delta_adc_ff3_remote5 : 8;
        unsigned int delta_adc_ff4_remote5 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_6_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff1_remote5_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff1_remote5_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff2_remote5_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff2_remote5_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff3_remote5_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff3_remote5_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff4_remote5_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_6_delta_adc_ff4_remote5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int delta_adc_ff1_remote6 : 8;
        unsigned int delta_adc_ff2_remote6 : 8;
        unsigned int delta_adc_ff3_remote6 : 8;
        unsigned int delta_adc_ff4_remote6 : 8;
    } reg;
} SOC_TSENSOR_DELTA_ADC_INFO_7_UNION;
#endif
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff1_remote6_START (0)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff1_remote6_END (7)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff2_remote6_START (8)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff2_remote6_END (15)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff3_remote6_START (16)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff3_remote6_END (23)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff4_remote6_START (24)
#define SOC_TSENSOR_DELTA_ADC_INFO_7_delta_adc_ff4_remote6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_slope_int_msk0 : 1;
        unsigned int temp_slope_int_msk1 : 1;
        unsigned int temp_slope_int_msk2 : 1;
        unsigned int temp_slope_int_msk3 : 1;
        unsigned int temp_slope_int_msk4 : 1;
        unsigned int temp_slope_int_msk5 : 1;
        unsigned int temp_slope_int_msk6 : 1;
        unsigned int temp_slope_int_msk7 : 1;
        unsigned int reserved : 8;
        unsigned int temp_slope_int_msk : 16;
    } reg;
} SOC_TSENSOR_TEMP_SLOPE_INT_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk0_START (0)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk0_END (0)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk1_START (1)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk1_END (1)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk2_START (2)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk2_END (2)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk3_START (3)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk3_END (3)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk4_START (4)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk4_END (4)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk5_START (5)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk5_END (5)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk6_START (6)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk6_END (6)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk7_START (7)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk7_END (7)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk_START (16)
#define SOC_TSENSOR_TEMP_SLOPE_INT_MSK_temp_slope_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_slope_int_clr0 : 1;
        unsigned int temp_slope_int_clr1 : 1;
        unsigned int temp_slope_int_clr2 : 1;
        unsigned int temp_slope_int_clr3 : 1;
        unsigned int temp_slope_int_clr4 : 1;
        unsigned int temp_slope_int_clr5 : 1;
        unsigned int temp_slope_int_clr6 : 1;
        unsigned int temp_slope_int_clr7 : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_TSENSOR_TEMP_SLOPE_INT_CLR_UNION;
#endif
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr0_START (0)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr0_END (0)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr1_START (1)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr1_END (1)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr2_START (2)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr2_END (2)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr3_START (3)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr3_END (3)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr4_START (4)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr4_END (4)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr5_START (5)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr5_END (5)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr6_START (6)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr6_END (6)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr7_START (7)
#define SOC_TSENSOR_TEMP_SLOPE_INT_CLR_temp_slope_int_clr7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_rawint_slope0 : 1;
        unsigned int temp_rawint_slope1 : 1;
        unsigned int temp_rawint_slope2 : 1;
        unsigned int temp_rawint_slope3 : 1;
        unsigned int temp_rawint_slope4 : 1;
        unsigned int temp_rawint_slope5 : 1;
        unsigned int temp_rawint_slope6 : 1;
        unsigned int temp_rawint_slope7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_SLOPE_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope0_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope0_END (0)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope1_START (1)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope1_END (1)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope2_START (2)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope2_END (2)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope3_START (3)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope3_END (3)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope4_START (4)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope4_END (4)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope5_START (5)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope5_END (5)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope6_START (6)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope6_END (6)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope7_START (7)
#define SOC_TSENSOR_TEMP_RAWINT_SLOPE_temp_rawint_slope7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_mskint_slope0 : 1;
        unsigned int temp_mskint_slope1 : 1;
        unsigned int temp_mskint_slope2 : 1;
        unsigned int temp_mskint_slope3 : 1;
        unsigned int temp_mskint_slope4 : 1;
        unsigned int temp_mskint_slope5 : 1;
        unsigned int temp_mskint_slope6 : 1;
        unsigned int temp_mskint_slope7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_SLOPE_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope0_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope0_END (0)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope1_START (1)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope1_END (1)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope2_START (2)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope2_END (2)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope3_START (3)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope3_END (3)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope4_START (4)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope4_END (4)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope5_START (5)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope5_END (5)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope6_START (6)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope6_END (6)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope7_START (7)
#define SOC_TSENSOR_TEMP_MSKINT_SLOPE_temp_mskint_slope7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_slope_th1 : 16;
        unsigned int temp_delta_slope_th1 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TSENSOR_TEMP_SLOPE_TH_1_UNION;
#endif
#define SOC_TSENSOR_TEMP_SLOPE_TH_1_temp_slope_th1_START (0)
#define SOC_TSENSOR_TEMP_SLOPE_TH_1_temp_slope_th1_END (15)
#define SOC_TSENSOR_TEMP_SLOPE_TH_1_temp_delta_slope_th1_START (16)
#define SOC_TSENSOR_TEMP_SLOPE_TH_1_temp_delta_slope_th1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_slope_th2 : 16;
        unsigned int temp_delta_slope_th2 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TSENSOR_TEMP_SLOPE_TH_2_UNION;
#endif
#define SOC_TSENSOR_TEMP_SLOPE_TH_2_temp_slope_th2_START (0)
#define SOC_TSENSOR_TEMP_SLOPE_TH_2_temp_slope_th2_END (15)
#define SOC_TSENSOR_TEMP_SLOPE_TH_2_temp_delta_slope_th2_START (16)
#define SOC_TSENSOR_TEMP_SLOPE_TH_2_temp_delta_slope_th2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_slope_th3 : 16;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_TSENSOR_TEMP_SLOPE_TH_3_UNION;
#endif
#define SOC_TSENSOR_TEMP_SLOPE_TH_3_temp_slope_th3_START (0)
#define SOC_TSENSOR_TEMP_SLOPE_TH_3_temp_slope_th3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_tsen_disable_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TSEN_MASK_UNION;
#endif
#define SOC_TSENSOR_TSEN_MASK_hw_tsen_disable_mask_START (0)
#define SOC_TSENSOR_TSEN_MASK_hw_tsen_disable_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_modulation_mask : 3;
        unsigned int reserved_0 : 1;
        unsigned int hotspot_src_sel : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_TSENSOR_THERMAL_CTRL_UNION;
#endif
#define SOC_TSENSOR_THERMAL_CTRL_clk_modulation_mask_START (0)
#define SOC_TSENSOR_THERMAL_CTRL_clk_modulation_mask_END (2)
#define SOC_TSENSOR_THERMAL_CTRL_hotspot_src_sel_START (4)
#define SOC_TSENSOR_THERMAL_CTRL_hotspot_src_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_cpu_hot_reg : 16;
        unsigned int temp_gpu_hot_reg : 16;
    } reg;
} SOC_TSENSOR_HOT_REG0_UNION;
#endif
#define SOC_TSENSOR_HOT_REG0_temp_cpu_hot_reg_START (0)
#define SOC_TSENSOR_HOT_REG0_temp_cpu_hot_reg_END (15)
#define SOC_TSENSOR_HOT_REG0_temp_gpu_hot_reg_START (16)
#define SOC_TSENSOR_HOT_REG0_temp_gpu_hot_reg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_npu_hot_reg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_HOT_REG1_UNION;
#endif
#define SOC_TSENSOR_HOT_REG1_temp_npu_hot_reg_START (0)
#define SOC_TSENSOR_HOT_REG1_temp_npu_hot_reg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_hotspot_th : 16;
        unsigned int temp_hotspot_lag : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_TSENSOR_TEMP_HOTSPOT_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_HOTSPOT_TH_temp_hotspot_th_START (0)
#define SOC_TSENSOR_TEMP_HOTSPOT_TH_temp_hotspot_th_END (15)
#define SOC_TSENSOR_TEMP_HOTSPOT_TH_temp_hotspot_lag_START (16)
#define SOC_TSENSOR_TEMP_HOTSPOT_TH_temp_hotspot_lag_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value0_sft : 9;
        unsigned int reserved_0 : 3;
        unsigned int temp_value0_sft_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int temp_value0_hard_sel : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_TSENSOR_TEMP_VALUE_SEL0_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE_SEL0_temp_value0_sft_START (0)
#define SOC_TSENSOR_TEMP_VALUE_SEL0_temp_value0_sft_END (8)
#define SOC_TSENSOR_TEMP_VALUE_SEL0_temp_value0_sft_en_START (12)
#define SOC_TSENSOR_TEMP_VALUE_SEL0_temp_value0_sft_en_END (12)
#define SOC_TSENSOR_TEMP_VALUE_SEL0_temp_value0_hard_sel_START (16)
#define SOC_TSENSOR_TEMP_VALUE_SEL0_temp_value0_hard_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value1_sft : 9;
        unsigned int reserved_0 : 3;
        unsigned int temp_value1_sft_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int temp_value1_hard_sel : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_TSENSOR_TEMP_VALUE_SEL1_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE_SEL1_temp_value1_sft_START (0)
#define SOC_TSENSOR_TEMP_VALUE_SEL1_temp_value1_sft_END (8)
#define SOC_TSENSOR_TEMP_VALUE_SEL1_temp_value1_sft_en_START (12)
#define SOC_TSENSOR_TEMP_VALUE_SEL1_temp_value1_sft_en_END (12)
#define SOC_TSENSOR_TEMP_VALUE_SEL1_temp_value1_hard_sel_START (16)
#define SOC_TSENSOR_TEMP_VALUE_SEL1_temp_value1_hard_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_value2_sft : 9;
        unsigned int reserved_0 : 3;
        unsigned int temp_value2_sft_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int temp_value2_hard_sel : 4;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_TSENSOR_TEMP_VALUE_SEL2_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALUE_SEL2_temp_value2_sft_START (0)
#define SOC_TSENSOR_TEMP_VALUE_SEL2_temp_value2_sft_END (8)
#define SOC_TSENSOR_TEMP_VALUE_SEL2_temp_value2_sft_en_START (12)
#define SOC_TSENSOR_TEMP_VALUE_SEL2_temp_value2_sft_en_END (12)
#define SOC_TSENSOR_TEMP_VALUE_SEL2_temp_value2_hard_sel_START (16)
#define SOC_TSENSOR_TEMP_VALUE_SEL2_temp_value2_hard_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_valid0_extend : 4;
        unsigned int temp_valid1_extend : 4;
        unsigned int temp_valid2_extend : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_TSENSOR_TEMP_VALID_EXTEND_UNION;
#endif
#define SOC_TSENSOR_TEMP_VALID_EXTEND_temp_valid0_extend_START (0)
#define SOC_TSENSOR_TEMP_VALID_EXTEND_temp_valid0_extend_END (3)
#define SOC_TSENSOR_TEMP_VALID_EXTEND_temp_valid1_extend_START (4)
#define SOC_TSENSOR_TEMP_VALID_EXTEND_temp_valid1_extend_END (7)
#define SOC_TSENSOR_TEMP_VALID_EXTEND_temp_valid2_extend_START (8)
#define SOC_TSENSOR_TEMP_VALID_EXTEND_temp_valid2_extend_END (11)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
