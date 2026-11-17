#ifndef __SOC_ASP_CODEC_INTERFACE_H__
#define __SOC_ASP_CODEC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_CODEC_VERSION_ADDR(base) ((base) + (0x0000UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ADDR(base) ((base) + (0x0004UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN1_ADDR(base) ((base) + (0x0008UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN2_ADDR(base) ((base) + (0x000CUL))
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ADDR(base) ((base) + (0x0010UL))
#define SOC_ASP_CODEC_CODEC_CLK_EN4_ADDR(base) ((base) + (0x0014UL))
#define SOC_ASP_CODEC_CODEC_SW_RST_N_ADDR(base) ((base) + (0x0018UL))
#define SOC_ASP_CODEC_I2S1_CTRL_ADDR(base) ((base) + (0x001CUL))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_ADDR(base) ((base) + (0x0020UL))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_ADDR(base) ((base) + (0x0024UL))
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_ADDR(base) ((base) + (0x0028UL))
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_ADDR(base) ((base) + (0x002CUL))
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_ADDR(base) ((base) + (0x0030UL))
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_ADDR(base) ((base) + (0x0034UL))
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_ADDR(base) ((base) + (0x0038UL))
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_ADDR(base) ((base) + (0x003CUL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_ADDR(base) ((base) + (0x0040UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_ADDR(base) ((base) + (0x0044UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_ADDR(base) ((base) + (0x0048UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_ADDR(base) ((base) + (0x004CUL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_ADDR(base) ((base) + (0x0050UL))
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_ADDR(base) ((base) + (0x0054UL))
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_ADDR(base) ((base) + (0x0058UL))
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_ADDR(base) ((base) + (0x005CUL))
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_ADDR(base) ((base) + (0x0060UL))
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_ADDR(base) ((base) + (0x0064UL))
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_ADDR(base) ((base) + (0x0068UL))
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_ADDR(base) ((base) + (0x006CUL))
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_ADDR(base) ((base) + (0x0070UL))
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_ADDR(base) ((base) + (0x0074UL))
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_ADDR(base) ((base) + (0x0078UL))
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_ADDR(base) ((base) + (0x007CUL))
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_ADDR(base) ((base) + (0x0080UL))
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_ADDR(base) ((base) + (0x0084UL))
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_ADDR(base) ((base) + (0x0088UL))
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_ADDR(base) ((base) + (0x008CUL))
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_ADDR(base) ((base) + (0x0090UL))
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_ADDR(base) ((base) + (0x0094UL))
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_ADDR(base) ((base) + (0x0098UL))
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_ADDR(base) ((base) + (0x009CUL))
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ADDR(base) ((base) + (0x00A0UL))
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_ADDR(base) ((base) + (0x00A4UL))
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_ADDR(base) ((base) + (0x00A8UL))
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_ADDR(base) ((base) + (0x00ACUL))
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_ADDR(base) ((base) + (0x00B0UL))
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_ADDR(base) ((base) + (0x00B4UL))
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_ADDR(base) ((base) + (0x00B8UL))
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_ADDR(base) ((base) + (0x00BCUL))
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_ADDR(base) ((base) + (0x00C0UL))
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_ADDR(base) ((base) + (0x00C4UL))
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_ADDR(base) ((base) + (0x00C8UL))
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_ADDR(base) ((base) + (0x00CCUL))
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_ADDR(base) ((base) + (0x00D0UL))
#define SOC_ASP_CODEC_SRCUP_CTRL0_ADDR(base) ((base) + (0x00D4UL))
#define SOC_ASP_CODEC_SRCUP_CTRL1_ADDR(base) ((base) + (0x00D8UL))
#define SOC_ASP_CODEC_SRCDN_CTRL0_ADDR(base) ((base) + (0x00DCUL))
#define SOC_ASP_CODEC_SRCDN_CTRL1_ADDR(base) ((base) + (0x00E0UL))
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_ADDR(base) ((base) + (0x00E4UL))
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_ADDR(base) ((base) + (0x00E8UL))
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_ADDR(base) ((base) + (0x00ECUL))
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_ADDR(base) ((base) + (0x00F0UL))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_ADDR(base) ((base) + (0x00F4UL))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_ADDR(base) ((base) + (0x00F8UL))
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_ADDR(base) ((base) + (0x00FCUL))
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ADDR(base) ((base) + (0x0104UL))
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ADDR(base) ((base) + (0x0108UL))
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_ADDR(base) ((base) + (0x010CUL))
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_ADDR(base) ((base) + (0x0110UL))
#define SOC_ASP_CODEC_DMIC_CTRL_ADDR(base) ((base) + (0x0114UL))
#define SOC_ASP_CODEC_DMIC_DIV_ADDR(base) ((base) + (0x0118UL))
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x011CUL))
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0120UL))
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0124UL))
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0128UL))
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x012CUL))
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0130UL))
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ADDR(base) ((base) + (0x0134UL))
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0138UL))
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x013CUL))
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0140UL))
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0144UL))
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0148UL))
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x014CUL))
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0150UL))
#define SOC_ASP_CODEC_SIF_CTRL_ADDR(base) ((base) + (0x0154UL))
#define SOC_ASP_CODEC_FS_CTRL0_ADDR(base) ((base) + (0x0158UL))
#define SOC_ASP_CODEC_FS_CTRL1_ADDR(base) ((base) + (0x015CUL))
#define SOC_ASP_CODEC_FS_CTRL2_ADDR(base) ((base) + (0x0160UL))
#define SOC_ASP_CODEC_FS_CTRL3_ADDR(base) ((base) + (0x0164UL))
#define SOC_ASP_CODEC_FS_CTRL4_ADDR(base) ((base) + (0x0168UL))
#define SOC_ASP_CODEC_FS_CTRL5_ADDR(base) ((base) + (0x016CUL))
#define SOC_ASP_CODEC_FS_CTRL6_ADDR(base) ((base) + (0x0170UL))
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_ADDR(base) ((base) + (0x0174UL))
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ADDR(base) ((base) + (0x0178UL))
#define SOC_ASP_CODEC_CODEC_ADC1_DC_OFFSET_ADDR(base) ((base) + (0x017CUL))
#define SOC_ASP_CODEC_CODEC_ADC2_DC_OFFSET_ADDR(base) ((base) + (0x0180UL))
#define SOC_ASP_CODEC_CODEC_ADC3_DC_OFFSET_ADDR(base) ((base) + (0x0184UL))
#define SOC_ASP_CODEC_CODEC_ADC4_DC_OFFSET_ADDR(base) ((base) + (0x0188UL))
#define SOC_ASP_CODEC_CODEC_ADC5_DC_OFFSET_ADDR(base) ((base) + (0x018CUL))
#define SOC_ASP_CODEC_CODEC_ADC6_DC_OFFSET_ADDR(base) ((base) + (0x0190UL))
#define SOC_ASP_CODEC_CODEC_ADC7_DC_OFFSET_ADDR(base) ((base) + (0x0194UL))
#define SOC_ASP_CODEC_CODEC_ADC8_DC_OFFSET_ADDR(base) ((base) + (0x0198UL))
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_ADDR(base) ((base) + (0x019CUL))
#define SOC_ASP_CODEC_MEM_CTRL_S_ADDR(base) ((base) + (0x01A0UL))
#define SOC_ASP_CODEC_MEM_CTRL_1W2R_ADDR(base) ((base) + (0x01A4UL))
#define SOC_ASP_CODEC_ADC_CTRL_HPF_ADDR(base) ((base) + (0x01A8UL))
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x01ACUL))
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_ADDR(base) ((base) + (0x01B0UL))
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_ADDR(base) ((base) + (0x01B4UL))
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_ADDR(base) ((base) + (0x01B8UL))
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_ADDR(base) ((base) + (0x01BCUL))
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_ADDR(base) ((base) + (0x01C0UL))
#define SOC_ASP_CODEC_SIF0_CTRL_ADDR(base) ((base) + (0x01C4UL))
#define SOC_ASP_CODEC_HP_L_CTRL0_ADDR(base) ((base) + (0x01C8UL))
#define SOC_ASP_CODEC_HP_L_CTRL1_ADDR(base) ((base) + (0x01CCUL))
#define SOC_ASP_CODEC_HP_R_CTRL0_ADDR(base) ((base) + (0x01D0UL))
#define SOC_ASP_CODEC_HP_R_CTRL1_ADDR(base) ((base) + (0x01D4UL))
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ADDR(base) ((base) + (0x01D8UL))
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_ADDR(base) ((base) + (0x01DCUL))
#define SOC_ASP_CODEC_FS_CTRL7_ADDR(base) ((base) + (0x01E0UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_ADDR(base) ((base) + (0x01E4UL))
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_ADDR(base) ((base) + (0x01E8UL))
#define SOC_ASP_CODEC_AUDIO_HAPTIC_CTRL0_ADDR(base) ((base) + (0x01ECUL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL1_ADDR(base) ((base) + (0x01F0UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL2_ADDR(base) ((base) + (0x01F4UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL3_ADDR(base) ((base) + (0x01F8UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL4_ADDR(base) ((base) + (0x01FCUL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL5_ADDR(base) ((base) + (0x0200UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL6_ADDR(base) ((base) + (0x0204UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_ADDR(base) ((base) + (0x0208UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL8_ADDR(base) ((base) + (0x020CUL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_ADDR(base) ((base) + (0x0210UL))
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_ADDR(base) ((base) + (0x0214UL))
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_ADDR(base) ((base) + (0x0218UL))
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_ADDR(base) ((base) + (0x021CUL))
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL0_ADDR(base) ((base) + (0x0220UL))
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL1_ADDR(base) ((base) + (0x0224UL))
#define SOC_ASP_CODEC_NOISE_METER_OFL_RECOV_CTRL_ADDR(base) ((base) + (0x0228UL))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_ADDR(base) ((base) + (0x022CUL))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA1_ADDR(base) ((base) + (0x0230UL))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_ADDR(base) ((base) + (0x0234UL))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_ADDR(base) ((base) + (0x0238UL))
#define SOC_ASP_CODEC_MEM_CTRL_SPC_ADDR(base) ((base) + (0x023CUL))
#define SOC_ASP_CODEC_CODEC_CLK_EN5_ADDR(base) ((base) + (0x0240UL))
#define SOC_ASP_CODEC_FS_CTRL8_ADDR(base) ((base) + (0x0244UL))
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0248UL))
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x024CUL))
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_ADDR(base) ((base) + (0x0250UL))
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_ADDR(base) ((base) + (0x0254UL))
#define SOC_ASP_CODEC_SRCUP_CTRL2_ADDR(base) ((base) + (0x0258UL))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_ADDR(base) ((base) + (0x025CUL))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_ADDR(base) ((base) + (0x0260UL))
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ADDR(base) ((base) + (0x0264UL))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_ADDR(base) ((base) + (0x0268UL))
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_ADDR(base) ((base) + (0x026CUL))
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_ADDR(base) ((base) + (0x0270UL))
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_ADDR(base) ((base) + (0x0274UL))
#else
#define SOC_ASP_CODEC_VERSION_ADDR(base) ((base) + (0x0000))
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ADDR(base) ((base) + (0x0004))
#define SOC_ASP_CODEC_CODEC_CLK_EN1_ADDR(base) ((base) + (0x0008))
#define SOC_ASP_CODEC_CODEC_CLK_EN2_ADDR(base) ((base) + (0x000C))
#define SOC_ASP_CODEC_CODEC_CLK_EN3_ADDR(base) ((base) + (0x0010))
#define SOC_ASP_CODEC_CODEC_CLK_EN4_ADDR(base) ((base) + (0x0014))
#define SOC_ASP_CODEC_CODEC_SW_RST_N_ADDR(base) ((base) + (0x0018))
#define SOC_ASP_CODEC_I2S1_CTRL_ADDR(base) ((base) + (0x001C))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_ADDR(base) ((base) + (0x0020))
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_ADDR(base) ((base) + (0x0024))
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_ADDR(base) ((base) + (0x0028))
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_ADDR(base) ((base) + (0x002C))
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_ADDR(base) ((base) + (0x0030))
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_ADDR(base) ((base) + (0x0034))
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_ADDR(base) ((base) + (0x0038))
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_ADDR(base) ((base) + (0x003C))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_ADDR(base) ((base) + (0x0040))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_ADDR(base) ((base) + (0x0044))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_ADDR(base) ((base) + (0x0048))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_ADDR(base) ((base) + (0x004C))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_ADDR(base) ((base) + (0x0050))
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_ADDR(base) ((base) + (0x0054))
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_ADDR(base) ((base) + (0x0058))
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_ADDR(base) ((base) + (0x005C))
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_ADDR(base) ((base) + (0x0060))
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_ADDR(base) ((base) + (0x0064))
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_ADDR(base) ((base) + (0x0068))
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_ADDR(base) ((base) + (0x006C))
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_ADDR(base) ((base) + (0x0070))
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_ADDR(base) ((base) + (0x0074))
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_ADDR(base) ((base) + (0x0078))
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_ADDR(base) ((base) + (0x007C))
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_ADDR(base) ((base) + (0x0080))
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_ADDR(base) ((base) + (0x0084))
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_ADDR(base) ((base) + (0x0088))
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_ADDR(base) ((base) + (0x008C))
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_ADDR(base) ((base) + (0x0090))
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_ADDR(base) ((base) + (0x0094))
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_ADDR(base) ((base) + (0x0098))
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_ADDR(base) ((base) + (0x009C))
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ADDR(base) ((base) + (0x00A0))
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_ADDR(base) ((base) + (0x00A4))
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_ADDR(base) ((base) + (0x00A8))
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_ADDR(base) ((base) + (0x00AC))
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_ADDR(base) ((base) + (0x00B0))
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_ADDR(base) ((base) + (0x00B4))
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_ADDR(base) ((base) + (0x00B8))
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_ADDR(base) ((base) + (0x00BC))
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_ADDR(base) ((base) + (0x00C0))
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_ADDR(base) ((base) + (0x00C4))
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_ADDR(base) ((base) + (0x00C8))
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_ADDR(base) ((base) + (0x00CC))
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_ADDR(base) ((base) + (0x00D0))
#define SOC_ASP_CODEC_SRCUP_CTRL0_ADDR(base) ((base) + (0x00D4))
#define SOC_ASP_CODEC_SRCUP_CTRL1_ADDR(base) ((base) + (0x00D8))
#define SOC_ASP_CODEC_SRCDN_CTRL0_ADDR(base) ((base) + (0x00DC))
#define SOC_ASP_CODEC_SRCDN_CTRL1_ADDR(base) ((base) + (0x00E0))
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_ADDR(base) ((base) + (0x00E4))
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_ADDR(base) ((base) + (0x00E8))
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_ADDR(base) ((base) + (0x00EC))
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_ADDR(base) ((base) + (0x00F0))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_ADDR(base) ((base) + (0x00F4))
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_ADDR(base) ((base) + (0x00F8))
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_ADDR(base) ((base) + (0x00FC))
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ADDR(base) ((base) + (0x0104))
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ADDR(base) ((base) + (0x0108))
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_ADDR(base) ((base) + (0x010C))
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_ADDR(base) ((base) + (0x0110))
#define SOC_ASP_CODEC_DMIC_CTRL_ADDR(base) ((base) + (0x0114))
#define SOC_ASP_CODEC_DMIC_DIV_ADDR(base) ((base) + (0x0118))
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x011C))
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0120))
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0124))
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0128))
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x012C))
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0130))
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ADDR(base) ((base) + (0x0134))
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0138))
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x013C))
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0140))
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0144))
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0148))
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x014C))
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x0150))
#define SOC_ASP_CODEC_SIF_CTRL_ADDR(base) ((base) + (0x0154))
#define SOC_ASP_CODEC_FS_CTRL0_ADDR(base) ((base) + (0x0158))
#define SOC_ASP_CODEC_FS_CTRL1_ADDR(base) ((base) + (0x015C))
#define SOC_ASP_CODEC_FS_CTRL2_ADDR(base) ((base) + (0x0160))
#define SOC_ASP_CODEC_FS_CTRL3_ADDR(base) ((base) + (0x0164))
#define SOC_ASP_CODEC_FS_CTRL4_ADDR(base) ((base) + (0x0168))
#define SOC_ASP_CODEC_FS_CTRL5_ADDR(base) ((base) + (0x016C))
#define SOC_ASP_CODEC_FS_CTRL6_ADDR(base) ((base) + (0x0170))
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_ADDR(base) ((base) + (0x0174))
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_ADDR(base) ((base) + (0x0178))
#define SOC_ASP_CODEC_CODEC_ADC1_DC_OFFSET_ADDR(base) ((base) + (0x017C))
#define SOC_ASP_CODEC_CODEC_ADC2_DC_OFFSET_ADDR(base) ((base) + (0x0180))
#define SOC_ASP_CODEC_CODEC_ADC3_DC_OFFSET_ADDR(base) ((base) + (0x0184))
#define SOC_ASP_CODEC_CODEC_ADC4_DC_OFFSET_ADDR(base) ((base) + (0x0188))
#define SOC_ASP_CODEC_CODEC_ADC5_DC_OFFSET_ADDR(base) ((base) + (0x018C))
#define SOC_ASP_CODEC_CODEC_ADC6_DC_OFFSET_ADDR(base) ((base) + (0x0190))
#define SOC_ASP_CODEC_CODEC_ADC7_DC_OFFSET_ADDR(base) ((base) + (0x0194))
#define SOC_ASP_CODEC_CODEC_ADC8_DC_OFFSET_ADDR(base) ((base) + (0x0198))
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_ADDR(base) ((base) + (0x019C))
#define SOC_ASP_CODEC_MEM_CTRL_S_ADDR(base) ((base) + (0x01A0))
#define SOC_ASP_CODEC_MEM_CTRL_1W2R_ADDR(base) ((base) + (0x01A4))
#define SOC_ASP_CODEC_ADC_CTRL_HPF_ADDR(base) ((base) + (0x01A8))
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x01AC))
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_ADDR(base) ((base) + (0x01B0))
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_ADDR(base) ((base) + (0x01B4))
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_ADDR(base) ((base) + (0x01B8))
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_ADDR(base) ((base) + (0x01BC))
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_ADDR(base) ((base) + (0x01C0))
#define SOC_ASP_CODEC_SIF0_CTRL_ADDR(base) ((base) + (0x01C4))
#define SOC_ASP_CODEC_HP_L_CTRL0_ADDR(base) ((base) + (0x01C8))
#define SOC_ASP_CODEC_HP_L_CTRL1_ADDR(base) ((base) + (0x01CC))
#define SOC_ASP_CODEC_HP_R_CTRL0_ADDR(base) ((base) + (0x01D0))
#define SOC_ASP_CODEC_HP_R_CTRL1_ADDR(base) ((base) + (0x01D4))
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ADDR(base) ((base) + (0x01D8))
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_ADDR(base) ((base) + (0x01DC))
#define SOC_ASP_CODEC_FS_CTRL7_ADDR(base) ((base) + (0x01E0))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_ADDR(base) ((base) + (0x01E4))
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_ADDR(base) ((base) + (0x01E8))
#define SOC_ASP_CODEC_AUDIO_HAPTIC_CTRL0_ADDR(base) ((base) + (0x01EC))
#define SOC_ASP_CODEC_NOISE_METER_CTRL1_ADDR(base) ((base) + (0x01F0))
#define SOC_ASP_CODEC_NOISE_METER_CTRL2_ADDR(base) ((base) + (0x01F4))
#define SOC_ASP_CODEC_NOISE_METER_CTRL3_ADDR(base) ((base) + (0x01F8))
#define SOC_ASP_CODEC_NOISE_METER_CTRL4_ADDR(base) ((base) + (0x01FC))
#define SOC_ASP_CODEC_NOISE_METER_CTRL5_ADDR(base) ((base) + (0x0200))
#define SOC_ASP_CODEC_NOISE_METER_CTRL6_ADDR(base) ((base) + (0x0204))
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_ADDR(base) ((base) + (0x0208))
#define SOC_ASP_CODEC_NOISE_METER_CTRL8_ADDR(base) ((base) + (0x020C))
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_ADDR(base) ((base) + (0x0210))
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_ADDR(base) ((base) + (0x0214))
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_ADDR(base) ((base) + (0x0218))
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_ADDR(base) ((base) + (0x021C))
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL0_ADDR(base) ((base) + (0x0220))
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL1_ADDR(base) ((base) + (0x0224))
#define SOC_ASP_CODEC_NOISE_METER_OFL_RECOV_CTRL_ADDR(base) ((base) + (0x0228))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_ADDR(base) ((base) + (0x022C))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA1_ADDR(base) ((base) + (0x0230))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_ADDR(base) ((base) + (0x0234))
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_ADDR(base) ((base) + (0x0238))
#define SOC_ASP_CODEC_MEM_CTRL_SPC_ADDR(base) ((base) + (0x023C))
#define SOC_ASP_CODEC_CODEC_CLK_EN5_ADDR(base) ((base) + (0x0240))
#define SOC_ASP_CODEC_FS_CTRL8_ADDR(base) ((base) + (0x0244))
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_ADDR(base) ((base) + (0x0248))
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_ADDR(base) ((base) + (0x024C))
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_ADDR(base) ((base) + (0x0250))
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_ADDR(base) ((base) + (0x0254))
#define SOC_ASP_CODEC_SRCUP_CTRL2_ADDR(base) ((base) + (0x0258))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_ADDR(base) ((base) + (0x025C))
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_ADDR(base) ((base) + (0x0260))
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ADDR(base) ((base) + (0x0264))
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_ADDR(base) ((base) + (0x0268))
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_ADDR(base) ((base) + (0x026C))
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_ADDR(base) ((base) + (0x0270))
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_ADDR(base) ((base) + (0x0274))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int version : 32;
    } reg;
} SOC_ASP_CODEC_VERSION_UNION;
#endif
#define SOC_ASP_CODEC_VERSION_version_START (0)
#define SOC_ASP_CODEC_VERSION_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spa1_up_afifo_clken : 1;
        unsigned int spa2_up_afifo_clken : 1;
        unsigned int spa3_up_afifo_clken : 1;
        unsigned int spa4_up_afifo_clken : 1;
        unsigned int spa5_up_afifo_clken : 1;
        unsigned int spa6_up_afifo_clken : 1;
        unsigned int audio_up_l_afifo_clken : 1;
        unsigned int audio_up_r_afifo_clken : 1;
        unsigned int voice_up_l_afifo_clken : 1;
        unsigned int voice_up_r_afifo_clken : 1;
        unsigned int mic3_up_afifo_clken : 1;
        unsigned int mic4_up_afifo_clken : 1;
        unsigned int mic5_up_afifo_clken : 1;
        unsigned int mic6_up_afifo_clken : 1;
        unsigned int mic7_up_afifo_clken : 1;
        unsigned int mic8_up_afifo_clken : 1;
        unsigned int ultr_up_afifo_clken : 1;
        unsigned int ultr_dn_afifo_clken : 1;
        unsigned int codec_0_dn_afifo_clken : 1;
        unsigned int codec_1_dn_afifo_clken : 1;
        unsigned int codec_2_dn_afifo_clken : 1;
        unsigned int audio_0_dn_afifo_clken : 1;
        unsigned int audio_1_dn_afifo_clken : 1;
        unsigned int audio_2_dn_afifo_clken : 1;
        unsigned int audiozoom_up_afifo_clken : 1;
        unsigned int noise_meter_up_afifo_clken : 1;
        unsigned int i2s1_pcm_clken : 1;
        unsigned int i2s1_tdm128_clken : 1;
        unsigned int i2s1_tdm256_clken : 1;
        unsigned int i2s2_pcm_clken : 1;
        unsigned int i2s2_tx_mixer2_clken : 1;
        unsigned int spa_protect_3way_clk_en : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN0_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa1_up_afifo_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa1_up_afifo_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa2_up_afifo_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa2_up_afifo_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa3_up_afifo_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa3_up_afifo_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa4_up_afifo_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa4_up_afifo_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa5_up_afifo_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa5_up_afifo_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa6_up_afifo_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa6_up_afifo_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_up_l_afifo_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_up_l_afifo_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_haptic0_dn_afifo_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_haptic0_dn_afifo_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_up_l_afifo_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_up_l_afifo_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_up_r_afifo_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_voice_up_r_afifo_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic3_up_afifo_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic3_up_afifo_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic4_up_afifo_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic4_up_afifo_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic5_up_afifo_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic5_up_afifo_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic6_up_afifo_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic6_up_afifo_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic7_up_afifo_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic7_up_afifo_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic8_up_afifo_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_mic8_up_afifo_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ultr_up_afifo_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ultr_up_afifo_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ultr_dn_afifo_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_ultr_dn_afifo_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_codec_0_dn_afifo_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_codec_0_dn_afifo_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_codec_1_dn_afifo_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_codec_1_dn_afifo_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_codec_2_dn_afifo_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_codec_2_dn_afifo_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_0_dn_afifo_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_0_dn_afifo_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_1_dn_afifo_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_1_dn_afifo_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_2_dn_afifo_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audio_2_dn_afifo_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audiozoom_up_afifo_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_audiozoom_up_afifo_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_noise_meter_up_afifo_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_noise_meter_up_afifo_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s1_pcm_clken_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s1_pcm_clken_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s1_tdm128_clken_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s1_tdm128_clken_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s1_tdm256_clken_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s1_tdm256_clken_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s2_pcm_clken_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s2_pcm_clken_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s2_tx_mixer2_clken_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_i2s2_tx_mixer2_clken_END (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa_protect_3way_clk_en_START (31)
#define SOC_ASP_CODEC_CODEC_CLK_EN0_spa_protect_3way_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_l_up_pga_clken : 1;
        unsigned int audio_r_up_pga_clken : 1;
        unsigned int voice_l_up_pga_clken : 1;
        unsigned int voice_r_up_pga_clken : 1;
        unsigned int mic3_up_pga_clken : 1;
        unsigned int mic4_up_pga_clken : 1;
        unsigned int mic5_up_pga_clken : 1;
        unsigned int mic6_up_pga_clken : 1;
        unsigned int mic7_up_pga_clken : 1;
        unsigned int mic8_up_pga_clken : 1;
        unsigned int codec_0_dn_pga_clken : 1;
        unsigned int codec_1_dn_pga_clken : 1;
        unsigned int codec_2_dn_pga_clken : 1;
        unsigned int audio_0_dn_pga_clken : 1;
        unsigned int audio_1_dn_pga_clken : 1;
        unsigned int audio_2_dn_pga_clken : 1;
        unsigned int audiozoom_up_pga_clken : 1;
        unsigned int noise_meter_up_pga_clken : 1;
        unsigned int i2s2_rx_l_pga_clken : 1;
        unsigned int i2s2_rx_r_pga_clken : 1;
        unsigned int audio_l_up_srcdn_clken : 1;
        unsigned int audio_r_up_srcdn_clken : 1;
        unsigned int voice_l_up_srcdn_clken : 1;
        unsigned int voice_r_up_srcdn_clken : 1;
        unsigned int mic3_up_srcdn_clken : 1;
        unsigned int mic4_up_srcdn_clken : 1;
        unsigned int mic5_up_srcdn_clken : 1;
        unsigned int mic6_up_srcdn_clken : 1;
        unsigned int mic7_up_srcdn_clken : 1;
        unsigned int mic8_up_srcdn_clken : 1;
        unsigned int ultr_dn_pga_clken : 1;
        unsigned int noise_meter_up_srcdn_clken : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN1_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_pga_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_pga_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_pga_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_pga_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_l_up_pga_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_l_up_pga_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_up_pga_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_up_pga_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_pga_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_pga_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic4_up_pga_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic4_up_pga_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic5_up_pga_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic5_up_pga_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic6_up_pga_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic6_up_pga_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic7_up_pga_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic7_up_pga_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic8_up_pga_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic8_up_pga_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec_0_dn_pga_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec_0_dn_pga_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec_1_dn_pga_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec_1_dn_pga_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec_2_dn_pga_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_codec_2_dn_pga_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_0_dn_pga_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_0_dn_pga_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_1_dn_pga_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_1_dn_pga_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_2_dn_pga_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_2_dn_pga_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audiozoom_up_pga_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audiozoom_up_pga_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_noise_meter_up_pga_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_noise_meter_up_pga_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s2_rx_l_pga_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s2_rx_l_pga_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s2_rx_r_pga_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_i2s2_rx_r_pga_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_srcdn_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_l_up_srcdn_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_srcdn_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_audio_r_up_srcdn_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_l_up_srcdn_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_l_up_srcdn_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_up_srcdn_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_voice_r_up_srcdn_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_srcdn_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic3_up_srcdn_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic4_up_srcdn_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic4_up_srcdn_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic5_up_srcdn_clken_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic5_up_srcdn_clken_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic6_up_srcdn_clken_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic6_up_srcdn_clken_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic7_up_srcdn_clken_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic7_up_srcdn_clken_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic8_up_srcdn_clken_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_mic8_up_srcdn_clken_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_ultr_dn_pga_clken_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_ultr_dn_pga_clken_END (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_noise_meter_up_srcdn_clken_START (31)
#define SOC_ASP_CODEC_CODEC_CLK_EN1_noise_meter_up_srcdn_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s2_tx_l_srcdn_clken : 1;
        unsigned int i2s2_tx_r_srcdn_clken : 1;
        unsigned int i2s2_rx_l_srcdn_clken : 1;
        unsigned int i2s2_rx_r_srcdn_clken : 1;
        unsigned int ultr_dn_srcup_clken : 1;
        unsigned int codec_0_dn_srcup_clken : 1;
        unsigned int codec_1_dn_srcup_clken : 1;
        unsigned int codec_2_dn_srcup_clken : 1;
        unsigned int audio_0_dn_srcup_clken : 1;
        unsigned int audio_1_dn_srcup_clken : 1;
        unsigned int audio_2_dn_srcup_clken : 1;
        unsigned int i2s2_rx_l_srcup_clken : 1;
        unsigned int i2s2_rx_r_srcup_clken : 1;
        unsigned int dacl_srcup_clken : 1;
        unsigned int dacr_srcup_clken : 1;
        unsigned int adc1_clken : 1;
        unsigned int adc2_clken : 1;
        unsigned int adc3_clken : 1;
        unsigned int adc4_clken : 1;
        unsigned int adc5_clken : 1;
        unsigned int adc6_clken : 1;
        unsigned int adc7_clken : 1;
        unsigned int adc8_clken : 1;
        unsigned int adc_ultr_clken : 1;
        unsigned int dacl_clken : 1;
        unsigned int dacr_clken : 1;
        unsigned int mixer4_spa0_clken : 1;
        unsigned int mixer4_spa1_clken : 1;
        unsigned int mixer4_spa2_clken : 1;
        unsigned int mixer2_ultr0_clken : 1;
        unsigned int mixer2_ultr1_clken : 1;
        unsigned int mixer2_ultr2_clken : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN2_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_tx_l_srcdn_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_tx_l_srcdn_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_tx_r_srcdn_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_tx_r_srcdn_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_l_srcdn_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_l_srcdn_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_r_srcdn_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_r_srcdn_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_ultr_dn_srcup_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_ultr_dn_srcup_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_codec_0_dn_srcup_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_codec_0_dn_srcup_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_codec_1_dn_srcup_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_codec_1_dn_srcup_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_codec_2_dn_srcup_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_codec_2_dn_srcup_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_audio_0_dn_srcup_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_audio_0_dn_srcup_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_audio_1_dn_srcup_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_audio_1_dn_srcup_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_audio_2_dn_srcup_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_audio_2_dn_srcup_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_l_srcup_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_l_srcup_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_r_srcup_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_i2s2_rx_r_srcup_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacl_srcup_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacl_srcup_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacr_srcup_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacr_srcup_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc1_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc1_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc2_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc3_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc4_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc4_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc5_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc5_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc6_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc6_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc7_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc7_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc8_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc8_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc_ultr_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_adc_ultr_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacl_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacl_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacr_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_dacr_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer4_spa0_clken_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer4_spa0_clken_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer4_spa1_clken_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer4_spa1_clken_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer4_spa2_clken_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer4_spa2_clken_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer2_ultr0_clken_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer2_ultr0_clken_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer2_ultr1_clken_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer2_ultr1_clken_END (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer2_ultr2_clken_START (31)
#define SOC_ASP_CODEC_CODEC_CLK_EN2_mixer2_ultr2_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc1_0p5_pga_clken : 1;
        unsigned int adc2_0p5_pga_clken : 1;
        unsigned int adc3_0p5_pga_clken : 1;
        unsigned int adc4_0p5_pga_clken : 1;
        unsigned int adc5_0p5_pga_clken : 1;
        unsigned int adc6_0p5_pga_clken : 1;
        unsigned int adc7_0p5_pga_clken : 1;
        unsigned int adc8_0p5_pga_clken : 1;
        unsigned int adc1_cicdn16_clken : 1;
        unsigned int adc2_cicdn16_clken : 1;
        unsigned int adc3_cicdn16_clken : 1;
        unsigned int adc4_cicdn16_clken : 1;
        unsigned int adc5_cicdn16_clken : 1;
        unsigned int adc6_cicdn16_clken : 1;
        unsigned int adc7_cicdn16_clken : 1;
        unsigned int adc8_cicdn16_clken : 1;
        unsigned int adc1_cicdn16_4stage_clken : 1;
        unsigned int adc2_cicdn16_4stage_clken : 1;
        unsigned int adc3_cicdn16_4stage_clken : 1;
        unsigned int adc4_cicdn16_4stage_clken : 1;
        unsigned int adc5_cicdn16_4stage_clken : 1;
        unsigned int adc6_cicdn16_4stage_clken : 1;
        unsigned int adc7_cicdn16_4stage_clken : 1;
        unsigned int adc8_cicdn16_4stage_clken : 1;
        unsigned int adc1_cic_ultr_clken : 1;
        unsigned int adc2_cic_ultr_clken : 1;
        unsigned int adc3_cic_ultr_clken : 1;
        unsigned int adc4_cic_ultr_clken : 1;
        unsigned int dmic1_clken : 1;
        unsigned int dmic2_clken : 1;
        unsigned int dmic3_clken : 1;
        unsigned int dmic4_clken : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN3_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_0p5_pga_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_0p5_pga_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_0p5_pga_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_0p5_pga_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_0p5_pga_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_0p5_pga_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_0p5_pga_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_0p5_pga_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc5_0p5_pga_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc5_0p5_pga_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc6_0p5_pga_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc6_0p5_pga_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc7_0p5_pga_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc7_0p5_pga_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc8_0p5_pga_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc8_0p5_pga_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_cicdn16_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_cicdn16_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_cicdn16_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_cicdn16_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_cicdn16_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_cicdn16_clken_END (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_cicdn16_clken_START (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_cicdn16_clken_END (11)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc5_cicdn16_clken_START (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc5_cicdn16_clken_END (12)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc6_cicdn16_clken_START (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc6_cicdn16_clken_END (13)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc7_cicdn16_clken_START (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc7_cicdn16_clken_END (14)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc8_cicdn16_clken_START (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc8_cicdn16_clken_END (15)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_cicdn16_4stage_clken_START (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_cicdn16_4stage_clken_END (16)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_cicdn16_4stage_clken_START (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_cicdn16_4stage_clken_END (17)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_cicdn16_4stage_clken_START (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_cicdn16_4stage_clken_END (18)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_cicdn16_4stage_clken_START (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_cicdn16_4stage_clken_END (19)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc5_cicdn16_4stage_clken_START (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc5_cicdn16_4stage_clken_END (20)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc6_cicdn16_4stage_clken_START (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc6_cicdn16_4stage_clken_END (21)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc7_cicdn16_4stage_clken_START (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc7_cicdn16_4stage_clken_END (22)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc8_cicdn16_4stage_clken_START (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc8_cicdn16_4stage_clken_END (23)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_cic_ultr_clken_START (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc1_cic_ultr_clken_END (24)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_cic_ultr_clken_START (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc2_cic_ultr_clken_END (25)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_cic_ultr_clken_START (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc3_cic_ultr_clken_END (26)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_cic_ultr_clken_START (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_adc4_cic_ultr_clken_END (27)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic1_clken_START (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic1_clken_END (28)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic2_clken_START (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic2_clken_END (29)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic3_clken_START (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic3_clken_END (30)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic4_clken_START (31)
#define SOC_ASP_CODEC_CODEC_CLK_EN3_dmic4_clken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ultr_hpf_clken : 1;
        unsigned int dacl_sdm_clken : 1;
        unsigned int dacr_sdm_clken : 1;
        unsigned int smartpa_feedforward_clken : 1;
        unsigned int audiozoom_clken : 1;
        unsigned int sidetone_pga_clken : 1;
        unsigned int bt_l_dn_afifo_clken : 1;
        unsigned int bt_r_dn_afifo_clken : 1;
        unsigned int sif_clken : 1;
        unsigned int noise_meter_pga_clken : 1;
        unsigned int noise_meter_srcdn_clken : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN4_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN4_ultr_hpf_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_ultr_hpf_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_dacl_sdm_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_dacl_sdm_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_dacr_sdm_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_dacr_sdm_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_audio_haptic_2ways_clk_en_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_audio_haptic_2ways_clk_en_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_audiozoom_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_audiozoom_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_sidetone_pga_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_sidetone_pga_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_bt_l_dn_afifo_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_bt_l_dn_afifo_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_bt_r_dn_afifo_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_bt_r_dn_afifo_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_sif_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_sif_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_noise_meter_pga_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_noise_meter_pga_clken_END (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_noise_meter_srcdn_clken_START (10)
#define SOC_ASP_CODEC_CODEC_CLK_EN4_noise_meter_srcdn_clken_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_sw_rst_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int rst_4mic_voice_access_irq : 1;
        unsigned int rst_4mic_audio_access_irq : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_4mic_dn_access_irq : 1;
        unsigned int rst_8mic_dn_access_irq : 1;
        unsigned int rst_8mic_up_access_irq : 1;
        unsigned int rst_8pa_dn_access_irq : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_ASP_CODEC_CODEC_SW_RST_N_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_SW_RST_N_codec_sw_rst_n_START (0)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_codec_sw_rst_n_END (0)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_4mic_voice_access_irq_START (2)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_4mic_voice_access_irq_END (2)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_4mic_audio_access_irq_START (3)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_4mic_audio_access_irq_END (3)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_4mic_dn_access_irq_START (5)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_4mic_dn_access_irq_END (5)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_8mic_dn_access_irq_START (6)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_8mic_dn_access_irq_END (6)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_8mic_up_access_irq_START (7)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_8mic_up_access_irq_END (7)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_8pa_dn_access_irq_START (8)
#define SOC_ASP_CODEC_CODEC_SW_RST_N_rst_8pa_dn_access_irq_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 13;
        unsigned int fs_i2s1 : 3;
        unsigned int i2s1_if_tx_ena : 1;
        unsigned int i2s1_if_rx_ena : 1;
        unsigned int i2s1_mst_slv : 1;
        unsigned int i2s1_direct_loop : 2;
        unsigned int i2s1_func_mode : 3;
        unsigned int i2s1_frame_mode : 1;
        unsigned int i2s1_lrclk_mode : 1;
        unsigned int i2s1_chnnl_mode : 1;
        unsigned int i2s1_codec_data_format : 1;
        unsigned int i2s1_codec_io_wordlength : 2;
        unsigned int i2s1_tx_clk_sel : 1;
        unsigned int i2s1_rx_clk_sel : 1;
    } reg;
} SOC_ASP_CODEC_I2S1_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_CTRL_fs_i2s1_START (13)
#define SOC_ASP_CODEC_I2S1_CTRL_fs_i2s1_END (15)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_tx_ena_START (16)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_tx_ena_END (16)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_rx_ena_START (17)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_if_rx_ena_END (17)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_mst_slv_START (18)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_mst_slv_END (18)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_direct_loop_START (19)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_direct_loop_END (20)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_func_mode_START (21)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_func_mode_END (23)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_frame_mode_START (24)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_frame_mode_END (24)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_lrclk_mode_START (25)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_lrclk_mode_END (25)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_chnnl_mode_START (26)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_chnnl_mode_END (26)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_data_format_START (27)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_data_format_END (27)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_io_wordlength_START (28)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_codec_io_wordlength_END (29)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_tx_clk_sel_START (30)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_tx_clk_sel_END (30)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_rx_clk_sel_START (31)
#define SOC_ASP_CODEC_I2S1_CTRL_i2s1_rx_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s1_fifo_clr : 1;
        unsigned int s1_mem_icg_bp_en : 1;
        unsigned int s1_tdm_frame_mode : 3;
        unsigned int s1_tdm_direct_loop : 2;
        unsigned int s1_tdm_if_en : 1;
        unsigned int s1_tdm_tx_ch3_sel : 2;
        unsigned int s1_tdm_tx_ch2_sel : 2;
        unsigned int s1_tdm_tx_ch1_sel : 2;
        unsigned int s1_tdm_tx_ch0_sel : 2;
        unsigned int s1_tdm_rx_slot_sel_v0 : 3;
        unsigned int s1_tdm_rx_slot_sel_i0 : 3;
        unsigned int s1_tdm_tx_clk_sel : 1;
        unsigned int s1_tdm_rx_clk_sel : 1;
        unsigned int s1_tdm_rx_slot_sel_v1 : 3;
        unsigned int s1_tdm_rx_slot_sel_i1 : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ASP_CODEC_I2S1_TDM_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_fifo_clr_START (0)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_fifo_clr_END (0)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_mem_icg_bp_en_START (1)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_mem_icg_bp_en_END (1)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_frame_mode_START (2)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_frame_mode_END (4)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_direct_loop_START (5)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_direct_loop_END (6)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_if_en_START (7)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_if_en_END (7)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch3_sel_START (8)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch3_sel_END (9)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch2_sel_START (10)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch2_sel_END (11)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch1_sel_START (12)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch1_sel_END (13)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch0_sel_START (14)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_ch0_sel_END (15)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v0_START (16)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v0_END (18)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i0_START (19)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i0_END (21)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_clk_sel_START (22)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_tx_clk_sel_END (22)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_clk_sel_START (23)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_clk_sel_END (23)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v1_START (24)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_v1_END (26)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i1_START (27)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL0_s1_tdm_rx_slot_sel_i1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s1_tdm_rx_slot_sel_v2 : 3;
        unsigned int s1_tdm_rx_slot_sel_i2 : 3;
        unsigned int s1_tdm_mode : 2;
        unsigned int s1_tdm_rx_slot_sel_v3 : 3;
        unsigned int s1_tdm_rx_slot_sel_i3 : 3;
        unsigned int reserved_0 : 2;
        unsigned int s1_tdm_mst_slv : 1;
        unsigned int reserved_1 : 1;
        unsigned int s1_tdm_err_stat : 2;
        unsigned int reserved_2 : 1;
        unsigned int s2_fifo_clr : 1;
        unsigned int reserved_3 : 10;
    } reg;
} SOC_ASP_CODEC_I2S1_TDM_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v2_START (0)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v2_END (2)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i2_START (3)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i2_END (5)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_mode_START (6)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_mode_END (7)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v3_START (8)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_v3_END (10)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i3_START (11)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_rx_slot_sel_i3_END (13)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_mst_slv_START (16)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_mst_slv_END (16)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_err_stat_START (18)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s1_tdm_err_stat_END (19)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s2_fifo_clr_START (21)
#define SOC_ASP_CODEC_I2S1_TDM_CTRL1_s2_fifo_clr_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 13;
        unsigned int fs_i2s2 : 3;
        unsigned int i2s2_if_tx_ena : 1;
        unsigned int i2s2_if_rx_ena : 1;
        unsigned int i2s2_mst_slv : 1;
        unsigned int i2s2_direct_loop : 2;
        unsigned int i2s2_func_mode : 3;
        unsigned int i2s2_frame_mode : 1;
        unsigned int i2s2_lrclk_mode : 1;
        unsigned int i2s2_chnnl_mode : 1;
        unsigned int i2s2_codec_data_format : 1;
        unsigned int i2s2_codec_io_wordlength : 2;
        unsigned int i2s2_tx_clk_sel : 1;
        unsigned int i2s2_rx_clk_sel : 1;
    } reg;
} SOC_ASP_CODEC_I2S2_PCM_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_fs_i2s2_START (13)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_fs_i2s2_END (15)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_tx_ena_START (16)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_tx_ena_END (16)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_rx_ena_START (17)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_if_rx_ena_END (17)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_mst_slv_START (18)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_mst_slv_END (18)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_direct_loop_START (19)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_direct_loop_END (20)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_func_mode_START (21)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_func_mode_END (23)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_frame_mode_START (24)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_frame_mode_END (24)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_lrclk_mode_START (25)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_lrclk_mode_END (25)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_chnnl_mode_START (26)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_chnnl_mode_END (26)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_data_format_START (27)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_data_format_END (27)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_io_wordlength_START (28)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_codec_io_wordlength_END (29)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_tx_clk_sel_START (30)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_tx_clk_sel_END (30)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_rx_clk_sel_START (31)
#define SOC_ASP_CODEC_I2S2_PCM_CTRL_i2s2_rx_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int s1_tdm_fifo_clr : 1;
        unsigned int s1_tdm_mem_icg_bp_en : 1;
        unsigned int s1_tdm_256_frame_mode : 2;
        unsigned int s1_tdm_256_direct_loop : 2;
        unsigned int reserved_1 : 8;
        unsigned int s1_tdm_rx_slot_sel_v3_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_v2_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_v1_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_v0_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_i3_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_i2_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_i1_32 : 1;
        unsigned int s1_tdm_rx_slot_sel_i0_32 : 1;
        unsigned int i2s1_tdm_slot_sel : 1;
        unsigned int s1_tdm_256_mst_slv : 1;
        unsigned int s1_tdm_256_if_en : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ASP_CODEC_I2S1_TDM256_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_fifo_clr_START (4)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_fifo_clr_END (4)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_mem_icg_bp_en_START (5)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_mem_icg_bp_en_END (5)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_frame_mode_START (6)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_frame_mode_END (7)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_direct_loop_START (8)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_direct_loop_END (9)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v3_32_START (18)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v3_32_END (18)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v2_32_START (19)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v2_32_END (19)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v1_32_START (20)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v1_32_END (20)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v0_32_START (21)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_v0_32_END (21)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i3_32_START (22)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i3_32_END (22)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i2_32_START (23)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i2_32_END (23)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i1_32_START (24)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i1_32_END (24)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i0_32_START (25)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_rx_slot_sel_i0_32_END (25)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_i2s1_tdm_slot_sel_START (26)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_i2s1_tdm_slot_sel_END (26)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_mst_slv_START (27)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_mst_slv_END (27)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_if_en_START (28)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL0_s1_tdm_256_if_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s1_tdm_rx_slot_sel_vb3_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_vb2_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_vb1_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_vb0_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_d3_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_d2_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_d1_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_d0_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_v3_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_v2_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_v1_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_v0_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_i3_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_i2_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_i1_16 : 2;
        unsigned int s1_tdm_rx_slot_sel_i0_16 : 2;
    } reg;
} SOC_ASP_CODEC_I2S1_TDM256_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb3_16_START (0)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb3_16_END (1)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb2_16_START (2)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb2_16_END (3)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb1_16_START (4)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb1_16_END (5)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb0_16_START (6)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_vb0_16_END (7)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d3_16_START (8)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d3_16_END (9)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d2_16_START (10)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d2_16_END (11)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d1_16_START (12)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d1_16_END (13)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d0_16_START (14)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_d0_16_END (15)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v3_16_START (16)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v3_16_END (17)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v2_16_START (18)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v2_16_END (19)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v1_16_START (20)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v1_16_END (21)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v0_16_START (22)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_v0_16_END (23)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i3_16_START (24)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i3_16_END (25)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i2_16_START (26)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i2_16_END (27)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i1_16_START (28)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i1_16_END (29)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i0_16_START (30)
#define SOC_ASP_CODEC_I2S1_TDM256_CTRL1_s1_tdm_rx_slot_sel_i0_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pga_mixer_thre_ctrl0 : 32;
    } reg;
} SOC_ASP_CODEC_PGA_THRE_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_pga_mixer_thre_ctrl0_START (0)
#define SOC_ASP_CODEC_PGA_THRE_CTRL0_pga_mixer_thre_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pga_mixer_thre_ctrl1 : 32;
    } reg;
} SOC_ASP_CODEC_PGA_THRE_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_pga_mixer_thre_ctrl1_START (0)
#define SOC_ASP_CODEC_PGA_THRE_CTRL1_pga_mixer_thre_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pga_mixer_thre_ctrl2 : 32;
    } reg;
} SOC_ASP_CODEC_PGA_THRE_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_pga_mixer_thre_ctrl2_START (0)
#define SOC_ASP_CODEC_PGA_THRE_CTRL2_pga_mixer_thre_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_0_dn_pga_gainoffset : 8;
        unsigned int codec_1_dn_pga_gainoffset : 8;
        unsigned int codec_2_dn_pga_gainoffset : 8;
        unsigned int audio_0_dn_pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_codec_0_dn_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_codec_0_dn_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_codec_1_dn_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_codec_1_dn_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_codec_2_dn_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_codec_2_dn_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_audio_0_dn_pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL0_audio_0_dn_pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mic3_up_pga_gainoffset : 8;
        unsigned int mic4_up_pga_gainoffset : 8;
        unsigned int audio_1_dn_pga_gainoffset : 8;
        unsigned int audio_2_dn__pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_mic3_up_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_mic3_up_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_mic4_up_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_mic4_up_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_1_dn_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_1_dn_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_2_dn__pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL1_audio_2_dn__pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_up_l_pga_gainoffset : 8;
        unsigned int audio_up_r_pga_gainoffset : 8;
        unsigned int voice_up_l_pga_gainoffset : 8;
        unsigned int voice_up_r_pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_audio_up_l_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_audio_up_l_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_audio_up_r_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_audio_up_r_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_voice_up_l_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_voice_up_l_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_voice_up_r_pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL2_voice_up_r_pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s2_rx_l_pga_gainoffset : 8;
        unsigned int i2s2_rx_r_pga_gainoffset : 8;
        unsigned int sidetone_pga_gainoffset : 8;
        unsigned int audiozoom_up_pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_i2s2_rx_l_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_i2s2_rx_l_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_i2s2_rx_r_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_i2s2_rx_r_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_sidetone_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_sidetone_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_audiozoom_up_pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL3_audiozoom_up_pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ultr_dn_pga_gainoffset : 8;
        unsigned int noise_meter_pga_gainoffset : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_ultr_dn_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_ultr_dn_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_noise_meter_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL4_noise_meter_pga_gainoffset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int codec_0_dn_pga_linear_sel : 1;
        unsigned int codec_0_dn_pga_zero_num : 5;
        unsigned int codec_0_dn_pga_thre_id : 2;
        unsigned int codec_0_dn_pga_noise_en : 1;
        unsigned int codec_0_dn_pga_bypass : 1;
        unsigned int codec_0_dn_pga_fade_out : 5;
        unsigned int codec_0_dn_pga_fade_in : 5;
        unsigned int codec_0_dn_pga_cfg : 3;
        unsigned int codec_0_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_CODEC_0_DN_PGA_CTRL_codec_0_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int codec_1_dn_pga_linear_sel : 1;
        unsigned int codec_1_dn_pga_zero_num : 5;
        unsigned int codec_1_dn_pga_thre_id : 2;
        unsigned int codec_1_dn_pga_noise_en : 1;
        unsigned int codec_1_dn_pga_bypass : 1;
        unsigned int codec_1_dn_pga_fade_out : 5;
        unsigned int codec_1_dn_pga_fade_in : 5;
        unsigned int codec_1_dn_pga_cfg : 3;
        unsigned int codec_1_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_CODEC_1_DN_PGA_CTRL_codec_1_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int codec_2_dn_pga_linear_sel : 1;
        unsigned int codec_2_dn_pga_zero_num : 5;
        unsigned int codec_2_dn_pga_thre_id : 2;
        unsigned int codec_2_dn_pga_noise_en : 1;
        unsigned int codec_2_dn_pga_bypass : 1;
        unsigned int codec_2_dn_pga_fade_out : 5;
        unsigned int codec_2_dn_pga_fade_in : 5;
        unsigned int codec_2_dn_pga_cfg : 3;
        unsigned int codec_2_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_CODEC_2_DN_PGA_CTRL_codec_2_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audio_0_dn_pga_linear_sel : 1;
        unsigned int audio_0_dn_pga_zero_num : 5;
        unsigned int audio_0_dn_pga_thre_id : 2;
        unsigned int audio_0_dn_pga_noise_en : 1;
        unsigned int audio_0_dn_pga_bypass : 1;
        unsigned int audio_0_dn_pga_fade_out : 5;
        unsigned int audio_0_dn_pga_fade_in : 5;
        unsigned int audio_0_dn_pga_cfg : 3;
        unsigned int audio_0_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_0_DN_PGA_CTRL_audio_0_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audio_1_dn_pga_linear_sel : 1;
        unsigned int audio_1_dn_pga_zero_num : 5;
        unsigned int audio_1_dn_pga_thre_id : 2;
        unsigned int audio_1_dn_pga_noise_en : 1;
        unsigned int audio_1_dn_pga_bypass : 1;
        unsigned int audio_1_dn_pga_fade_out : 5;
        unsigned int audio_1_dn_pga_fade_in : 5;
        unsigned int audio_1_dn_pga_cfg : 3;
        unsigned int audio_1_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_1_DN_PGA_CTRL_audio_1_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audio_2_dn_pga_linear_sel : 1;
        unsigned int audio_2_dn_pga_zero_num : 5;
        unsigned int audio_2_dn_pga_thre_id : 2;
        unsigned int audio_2_dn_pga_noise_en : 1;
        unsigned int audio_2_dn_pga_bypass : 1;
        unsigned int audio_2_dn_pga_fade_out : 5;
        unsigned int audio_2_dn_pga_fade_in : 5;
        unsigned int audio_2_dn_pga_cfg : 3;
        unsigned int audio_2_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_2_DN_PGA_CTRL_audio_2_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int sidetone_pga_linear_sel : 1;
        unsigned int sidetone_pga_zero_num : 5;
        unsigned int sidetone_pga_thre_id : 2;
        unsigned int sidetone_pga_noise_en : 1;
        unsigned int sidetone_pga_bypass : 1;
        unsigned int sidetone_pga_fade_out : 5;
        unsigned int sidetone_pga_fade_in : 5;
        unsigned int sidetone_pga_cfg : 3;
        unsigned int sidetone_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_SIDETONE_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_zero_num_START (2)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_zero_num_END (6)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_thre_id_START (7)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_thre_id_END (8)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_noise_en_START (9)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_noise_en_END (9)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_bypass_START (10)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_bypass_END (10)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_out_START (11)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_out_END (15)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_in_START (16)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_fade_in_END (20)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_cfg_START (21)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_cfg_END (23)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_gain_START (24)
#define SOC_ASP_CODEC_SIDETONE_PGA_CTRL_sidetone_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audio_l_up_pga_linear_sel : 1;
        unsigned int audio_l_up_pga_zero_num : 5;
        unsigned int audio_l_up_pga_thre_id : 2;
        unsigned int audio_l_up_pga_noise_en : 1;
        unsigned int audio_l_up_pga_bypass : 1;
        unsigned int audio_l_up_pga_fade_out : 5;
        unsigned int audio_l_up_pga_fade_in : 5;
        unsigned int audio_l_up_pga_cfg : 3;
        unsigned int audio_l_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_L_UP_PGA_CTRL_audio_l_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audio_r_up_pga_linear_sel : 1;
        unsigned int audio_r_up_pga_zero_num : 5;
        unsigned int audio_r_up_pga_thre_id : 2;
        unsigned int audio_r_up_pga_noise_en : 1;
        unsigned int audio_r_up_pga_bypass : 1;
        unsigned int audio_r_up_pga_fade_out : 5;
        unsigned int audio_r_up_pga_fade_in : 5;
        unsigned int audio_r_up_pga_cfg : 3;
        unsigned int audio_r_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_R_UP_PGA_CTRL_audio_r_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int voice_l_up_pga_linear_sel : 1;
        unsigned int voice_l_up_pga_zero_num : 5;
        unsigned int voice_l_up_pga_thre_id : 2;
        unsigned int voice_l_up_pga_noise_en : 1;
        unsigned int voice_l_up_pga_bypass : 1;
        unsigned int voice_l_up_pga_fade_out : 5;
        unsigned int voice_l_up_pga_fade_in : 5;
        unsigned int voice_l_up_pga_cfg : 3;
        unsigned int voice_l_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_gain_START (24)
#define SOC_ASP_CODEC_VOICE_L_UP_PGA_CTRL_voice_l_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int voice_r_up_pga_linear_sel : 1;
        unsigned int voice_r_up_pga_zero_num : 5;
        unsigned int voice_r_up_pga_thre_id : 2;
        unsigned int voice_r_up_pga_noise_en : 1;
        unsigned int voice_r_up_pga_bypass : 1;
        unsigned int voice_r_up_pga_fade_out : 5;
        unsigned int voice_r_up_pga_fade_in : 5;
        unsigned int voice_r_up_pga_cfg : 3;
        unsigned int voice_r_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_gain_START (24)
#define SOC_ASP_CODEC_VOICE_R_UP_PGA_CTRL_voice_r_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int mic3_up_pga_linear_sel : 1;
        unsigned int mic3_up_pga_zero_num : 5;
        unsigned int mic3_up_pga_thre_id : 2;
        unsigned int mic3_up_pga_noise_en : 1;
        unsigned int mic3_up_pga_bypass : 1;
        unsigned int mic3_up_pga_fade_out : 5;
        unsigned int mic3_up_pga_fade_in : 5;
        unsigned int mic3_up_pga_cfg : 3;
        unsigned int mic3_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC3_UP_PGA_CTRL_mic3_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int mic4_up_pga_linear_sel : 1;
        unsigned int mic4_up_pga_zero_num : 5;
        unsigned int mic4_up_pga_thre_id : 2;
        unsigned int mic4_up_pga_noise_en : 1;
        unsigned int mic4_up_pga_bypass : 1;
        unsigned int mic4_up_pga_fade_out : 5;
        unsigned int mic4_up_pga_fade_in : 5;
        unsigned int mic4_up_pga_cfg : 3;
        unsigned int mic4_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC4_UP_PGA_CTRL_mic4_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int mic5_up_pga_linear_sel : 1;
        unsigned int mic5_up_pga_zero_num : 5;
        unsigned int mic5_up_pga_thre_id : 2;
        unsigned int mic5_up_pga_noise_en : 1;
        unsigned int mic5_up_pga_bypass : 1;
        unsigned int mic5_up_pga_fade_out : 5;
        unsigned int mic5_up_pga_fade_in : 5;
        unsigned int mic5_up_pga_cfg : 3;
        unsigned int mic5_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC5_UP_PGA_CTRL_mic5_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int mic6_up_pga_linear_sel : 1;
        unsigned int mic6_up_pga_zero_num : 5;
        unsigned int mic6_up_pga_thre_id : 2;
        unsigned int mic6_up_pga_noise_en : 1;
        unsigned int mic6_up_pga_bypass : 1;
        unsigned int mic6_up_pga_fade_out : 5;
        unsigned int mic6_up_pga_fade_in : 5;
        unsigned int mic6_up_pga_cfg : 3;
        unsigned int mic6_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC6_UP_PGA_CTRL_mic6_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int mic7_up_pga_linear_sel : 1;
        unsigned int mic7_up_pga_zero_num : 5;
        unsigned int mic7_up_pga_thre_id : 2;
        unsigned int mic7_up_pga_noise_en : 1;
        unsigned int mic7_up_pga_bypass : 1;
        unsigned int mic7_up_pga_fade_out : 5;
        unsigned int mic7_up_pga_fade_in : 5;
        unsigned int mic7_up_pga_cfg : 3;
        unsigned int mic7_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC7_UP_PGA_CTRL_mic7_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int mic8_up_pga_linear_sel : 1;
        unsigned int mic8_up_pga_zero_num : 5;
        unsigned int mic8_up_pga_thre_id : 2;
        unsigned int mic8_up_pga_noise_en : 1;
        unsigned int mic8_up_pga_bypass : 1;
        unsigned int mic8_up_pga_fade_out : 5;
        unsigned int mic8_up_pga_fade_in : 5;
        unsigned int mic8_up_pga_cfg : 3;
        unsigned int mic8_up_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_thre_id_START (7)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_thre_id_END (8)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_noise_en_START (9)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_noise_en_END (9)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_bypass_START (10)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_bypass_END (10)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_fade_out_START (11)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_fade_out_END (15)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_fade_in_START (16)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_fade_in_END (20)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_cfg_START (21)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_cfg_END (23)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_gain_START (24)
#define SOC_ASP_CODEC_MIC8_UP_PGA_CTRL_mic8_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int i2s2_l_rx_pga_linear_sel : 1;
        unsigned int i2s2_l_rx_pga_zero_num : 5;
        unsigned int i2s2_l_rx_pga_thre_id : 2;
        unsigned int i2s2_l_rx_pga_noise_en : 1;
        unsigned int i2s2_l_rx_pga_bypass : 1;
        unsigned int i2s2_l_rx_pga_fade_out : 5;
        unsigned int i2s2_l_rx_pga_fade_in : 5;
        unsigned int i2s2_l_rx_pga_cfg : 3;
        unsigned int i2s2_l_rx_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_zero_num_START (2)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_zero_num_END (6)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_thre_id_START (7)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_thre_id_END (8)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_noise_en_START (9)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_noise_en_END (9)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_bypass_START (10)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_bypass_END (10)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_fade_out_START (11)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_fade_out_END (15)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_fade_in_START (16)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_fade_in_END (20)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_cfg_START (21)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_cfg_END (23)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_gain_START (24)
#define SOC_ASP_CODEC_I2S2_L_RX_PGA_CTRL_i2s2_l_rx_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int i2s2_r_rx_pga_linear_sel : 1;
        unsigned int i2s2_r_rx_pga_zero_num : 5;
        unsigned int i2s2_r_rx_pga_thre_id : 2;
        unsigned int i2s2_r_rx_pga_noise_en : 1;
        unsigned int i2s2_r_rx_pga_bypass : 1;
        unsigned int i2s2_r_rx_pga_fade_out : 5;
        unsigned int i2s2_r_rx_pga_fade_in : 5;
        unsigned int i2s2_r_rx_pga_cfg : 3;
        unsigned int i2s2_r_rx_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_zero_num_START (2)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_zero_num_END (6)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_thre_id_START (7)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_thre_id_END (8)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_noise_en_START (9)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_noise_en_END (9)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_bypass_START (10)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_bypass_END (10)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_fade_out_START (11)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_fade_out_END (15)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_fade_in_START (16)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_fade_in_END (20)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_cfg_START (21)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_cfg_END (23)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_gain_START (24)
#define SOC_ASP_CODEC_I2S2_R_RX_PGA_CTRL_i2s2_r_rx_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int ultr_dn_pga_linear_sel : 1;
        unsigned int ultr_dn_pga_zero_num : 5;
        unsigned int ultr_dn_pga_thre_id : 2;
        unsigned int ultr_dn_pga_noise_en : 1;
        unsigned int ultr_dn_pga_bypass : 1;
        unsigned int ultr_dn_pga_fade_out : 5;
        unsigned int ultr_dn_pga_fade_in : 5;
        unsigned int ultr_dn_pga_cfg : 3;
        unsigned int ultr_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_ULTR_DN_PGA_CTRL_ultr_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audiozoom_pga_linear_sel : 1;
        unsigned int audiozoom_pga_zero_num : 5;
        unsigned int audiozoom_pga_thre_id : 2;
        unsigned int audiozoom_pga_noise_en : 1;
        unsigned int audiozoom_pga_bypass : 1;
        unsigned int audiozoom_pga_fade_out : 5;
        unsigned int audiozoom_pga_fade_in : 5;
        unsigned int audiozoom_pga_cfg : 3;
        unsigned int audiozoom_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIOZOOM_PGA_CTRL_audiozoom_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int noise_meter_pga_linear_sel : 1;
        unsigned int noise_meter_pga_zero_num : 5;
        unsigned int noise_meter_pga_thre_id : 2;
        unsigned int noise_meter_pga_noise_en : 1;
        unsigned int noise_meter_pga_bypass : 1;
        unsigned int noise_meter_pga_fade_out : 5;
        unsigned int noise_meter_pga_fade_in : 5;
        unsigned int noise_meter_pga_cfg : 3;
        unsigned int noise_meter_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_zero_num_START (2)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_zero_num_END (6)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_thre_id_START (7)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_thre_id_END (8)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_noise_en_START (9)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_noise_en_END (9)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_bypass_START (10)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_bypass_END (10)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_fade_out_START (11)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_fade_out_END (15)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_fade_in_START (16)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_fade_in_END (20)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_cfg_START (21)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_cfg_END (23)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_gain_START (24)
#define SOC_ASP_CODEC_NOISE_METER_PGA_CTRL_noise_meter_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc1_pga_gain_offset : 8;
        unsigned int adc2_pga_gain_offset : 8;
        unsigned int adc3_pga_gain_offset : 8;
        unsigned int adc4_pga_gain_offset : 8;
    } reg;
} SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc1_pga_gain_offset_START (0)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc1_pga_gain_offset_END (7)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc2_pga_gain_offset_START (8)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc2_pga_gain_offset_END (15)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc3_pga_gain_offset_START (16)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc3_pga_gain_offset_END (23)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc4_pga_gain_offset_START (24)
#define SOC_ASP_CODEC_ADC0_PGA_GAIN_OFFSET_adc4_pga_gain_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc5_pga_gain_offset : 8;
        unsigned int adc6_pga_gain_offset : 8;
        unsigned int adc7_pga_gain_offset : 8;
        unsigned int adc8_pga_gain_offset : 8;
    } reg;
} SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc5_pga_gain_offset_START (0)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc5_pga_gain_offset_END (7)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc6_pga_gain_offset_START (8)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc6_pga_gain_offset_END (15)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc7_pga_gain_offset_START (16)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc7_pga_gain_offset_END (23)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc8_pga_gain_offset_START (24)
#define SOC_ASP_CODEC_ADC1_PGA_GAIN_OFFSET_adc8_pga_gain_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc1_up_pga_0p5_linear_sel : 1;
        unsigned int adc1_up_pga_0p5_zero_num : 5;
        unsigned int adc1_up_pga_0p5_thre_id : 2;
        unsigned int adc1_up_pga_0p5_noise_en : 1;
        unsigned int adc1_up_pga_0p5_bypass : 1;
        unsigned int adc1_up_pga_0p5_fade_out : 5;
        unsigned int adc1_up_pga_0p5_fade_in : 5;
        unsigned int adc1_up_pga_0p5_cfg : 3;
        unsigned int adc1_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC1_UP_PGA_CTRL_adc1_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc2_up_pga_linear_sel : 1;
        unsigned int adc2_up_pga_zero_num : 5;
        unsigned int adc2_up_pga_0p5_thre_id : 2;
        unsigned int adc2_up_pga_0p5_noise_en : 1;
        unsigned int adc2_up_pga_0p5_bypass : 1;
        unsigned int adc2_up_pga_0p5_fade_out : 5;
        unsigned int adc2_up_pga_0p5_fade_in : 5;
        unsigned int adc2_up_pga_0p5_cfg : 3;
        unsigned int adc2_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_zero_num_START (2)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_zero_num_END (6)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC2_UP_PGA_CTRL_adc2_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc3_up_pga_0p5_linear_sel : 1;
        unsigned int adc3_up_pga_0p5_zero_num : 5;
        unsigned int adc3_up_pga_0p5_thre_id : 2;
        unsigned int adc3_up_pga_0p5_noise_en : 1;
        unsigned int adc3_up_pga_0p5_bypass : 1;
        unsigned int adc3_up_pga_0p5_fade_out : 5;
        unsigned int adc3_up_pga_0p5_fade_in : 5;
        unsigned int adc3_up_pga_0p5_cfg : 3;
        unsigned int adc3_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC3_UP_PGA_CTRL_adc3_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc4_up_pga_0p5_linear_sel : 1;
        unsigned int adc4_up_pga_0p5_zero_num : 5;
        unsigned int adc4_up_pga_0p5_thre_id : 2;
        unsigned int adc4_up_pga_0p5_noise_en : 1;
        unsigned int adc4_up_pga_0p5_bypass : 1;
        unsigned int adc4_up_pga_0p5_fade_out : 5;
        unsigned int adc4_up_pga_0p5_fade_in : 5;
        unsigned int adc4_up_pga_0p5_cfg : 3;
        unsigned int adc4_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC4_UP_PGA_CTRL_adc4_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc5_up_pga_0p5_linear_sel : 1;
        unsigned int adc5_up_pga_0p5_zero_num : 5;
        unsigned int adc5_up_pga_0p5_thre_id : 2;
        unsigned int adc5_up_pga_0p5_noise_en : 1;
        unsigned int adc5_up_pga_0p5_bypass : 1;
        unsigned int adc5_up_pga_0p5_fade_out : 5;
        unsigned int adc5_up_pga_0p5_fade_in : 5;
        unsigned int adc5_up_pga_0p5_cfg : 3;
        unsigned int adc5_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC5_UP_PGA_CTRL_adc5_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc6_up_pga_0p5_linear_sel : 1;
        unsigned int adc6_up_pga_0p5_zero_num : 5;
        unsigned int adc6_up_pga_0p5_thre_id : 2;
        unsigned int adc6_up_pga_0p5_noise_en : 1;
        unsigned int adc6_up_pga_0p5_bypass : 1;
        unsigned int adc6_up_pga_0p5_fade_out : 5;
        unsigned int adc6_up_pga_0p5_fade_in : 5;
        unsigned int adc6_up_pga_0p5_cfg : 3;
        unsigned int adc6_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC6_UP_PGA_CTRL_adc6_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc7_up_pga_0p5_linear_sel : 1;
        unsigned int adc7_up_pga_0p5_zero_num : 5;
        unsigned int adc7_up_pga_0p5_thre_id : 2;
        unsigned int adc7_up_pga_0p5_noise_en : 1;
        unsigned int adc7_up_pga_0p5_bypass : 1;
        unsigned int adc7_up_pga_0p5_fade_out : 5;
        unsigned int adc7_up_pga_0p5_fade_in : 5;
        unsigned int adc7_up_pga_0p5_cfg : 3;
        unsigned int adc7_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC7_UP_PGA_CTRL_adc7_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int adc8_up_pga_0p5_linear_sel : 1;
        unsigned int adc8_up_pga_0p5_zero_num : 5;
        unsigned int adc8_up_pga_0p5_thre_id : 2;
        unsigned int adc8_up_pga_0p5_noise_en : 1;
        unsigned int adc8_up_pga_0p5_bypass : 1;
        unsigned int adc8_up_pga_0p5_fade_out : 5;
        unsigned int adc8_up_pga_0p5_fade_in : 5;
        unsigned int adc8_up_pga_0p5_cfg : 3;
        unsigned int adc8_up_pga_0p5_gain : 8;
    } reg;
} SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_linear_sel_START (1)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_linear_sel_END (1)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_zero_num_START (2)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_zero_num_END (6)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_thre_id_START (7)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_thre_id_END (8)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_noise_en_START (9)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_noise_en_END (9)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_bypass_START (10)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_bypass_END (10)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_fade_out_START (11)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_fade_out_END (15)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_fade_in_START (16)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_fade_in_END (20)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_cfg_START (21)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_cfg_END (23)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_gain_START (24)
#define SOC_ASP_CODEC_ADC8_UP_PGA_CTRL_adc8_up_pga_0p5_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_0_dn_srcup_src_mode : 3;
        unsigned int codec_0_dn_srcup_fifo_clr : 1;
        unsigned int codec_1_dn_srcup_src_mode : 3;
        unsigned int codec_1_dn_srcup_fifo_clr : 1;
        unsigned int codec_2_dn_srcup_src_mode : 3;
        unsigned int codec_2_dn_srcup_fifo_clr : 1;
        unsigned int audio_0_dn_srcup_src_mode : 3;
        unsigned int audio_0_dn_srcup_fifo_clr : 1;
        unsigned int audio_1_srcup_src_mode : 3;
        unsigned int audio_1_up_srcup_fifo_clr : 1;
        unsigned int audio_2_srcup_src_mode : 3;
        unsigned int audio_2_up_srcup_fifo_clr : 1;
        unsigned int dacl_mixer4_srcup_src_mode : 3;
        unsigned int dacl_mixer4_srcup_fifo_clr : 1;
        unsigned int dacr_mixer4_srcup_src_mode : 3;
        unsigned int dacr_mixer4_srcup_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SRCUP_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_0_dn_srcup_src_mode_START (0)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_0_dn_srcup_src_mode_END (2)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_0_dn_srcup_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_0_dn_srcup_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_1_dn_srcup_src_mode_START (4)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_1_dn_srcup_src_mode_END (6)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_1_dn_srcup_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_1_dn_srcup_fifo_clr_END (7)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_2_dn_srcup_src_mode_START (8)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_2_dn_srcup_src_mode_END (10)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_2_dn_srcup_fifo_clr_START (11)
#define SOC_ASP_CODEC_SRCUP_CTRL0_codec_2_dn_srcup_fifo_clr_END (11)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_0_dn_srcup_src_mode_START (12)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_0_dn_srcup_src_mode_END (14)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_0_dn_srcup_fifo_clr_START (15)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_0_dn_srcup_fifo_clr_END (15)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_1_srcup_src_mode_START (16)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_1_srcup_src_mode_END (18)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_1_up_srcup_fifo_clr_START (19)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_1_up_srcup_fifo_clr_END (19)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_2_srcup_src_mode_START (20)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_2_srcup_src_mode_END (22)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_2_up_srcup_fifo_clr_START (23)
#define SOC_ASP_CODEC_SRCUP_CTRL0_audio_2_up_srcup_fifo_clr_END (23)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacl_mixer4_srcup_src_mode_START (24)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacl_mixer4_srcup_src_mode_END (26)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacl_mixer4_srcup_fifo_clr_START (27)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacl_mixer4_srcup_fifo_clr_END (27)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacr_mixer4_srcup_src_mode_START (28)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacr_mixer4_srcup_src_mode_END (30)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacr_mixer4_srcup_fifo_clr_START (31)
#define SOC_ASP_CODEC_SRCUP_CTRL0_dacr_mixer4_srcup_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ultr_dn_srcup_src_mode : 3;
        unsigned int ultr_dn_srcup_fifo_clr : 1;
        unsigned int i2s2_rx_l_srcup_src_mode : 3;
        unsigned int i2s2_rx_l_srcup_fifo_clr : 1;
        unsigned int i2s2_rx_r_srcup_src_mode : 3;
        unsigned int i2s2_rx_r_srcup_fifo_clr : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_CODEC_SRCUP_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SRCUP_CTRL1_ultr_dn_srcup_src_mode_START (0)
#define SOC_ASP_CODEC_SRCUP_CTRL1_ultr_dn_srcup_src_mode_END (2)
#define SOC_ASP_CODEC_SRCUP_CTRL1_ultr_dn_srcup_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCUP_CTRL1_ultr_dn_srcup_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_l_srcup_src_mode_START (4)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_l_srcup_src_mode_END (6)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_l_srcup_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_l_srcup_fifo_clr_END (7)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_r_srcup_src_mode_START (8)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_r_srcup_src_mode_END (10)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_r_srcup_fifo_clr_START (11)
#define SOC_ASP_CODEC_SRCUP_CTRL1_i2s2_rx_r_srcup_fifo_clr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_l_up_srcdn_src_mode : 3;
        unsigned int audio_l_up_srcdn_fifo_clr : 1;
        unsigned int audio_r_up_srcdn_src_mode : 3;
        unsigned int audio_r_up_srcdn_fifo_clr : 1;
        unsigned int voice_l_up_srcdn_src_mode : 3;
        unsigned int voice_l_up_srcdn_fifo_clr : 1;
        unsigned int voice_r_up_srcdn_src_mode : 3;
        unsigned int voice_r_up_srcdn_fifo_clr : 1;
        unsigned int mic3_up_srcdn_src_mode : 3;
        unsigned int mic3_up_srcdn_fifo_clr : 1;
        unsigned int mic4_up_srcdn_src_mode : 3;
        unsigned int mic4_up_srcdn_fifo_clr : 1;
        unsigned int mic5_up_srcdn_src_mode : 3;
        unsigned int mic5_up_srcdn_fifo_clr : 1;
        unsigned int mic6_up_srcdn_src_mode : 3;
        unsigned int mic6_up_srcdn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SRCDN_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_l_up_srcdn_src_mode_START (0)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_l_up_srcdn_src_mode_END (2)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_l_up_srcdn_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_l_up_srcdn_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_r_up_srcdn_src_mode_START (4)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_r_up_srcdn_src_mode_END (6)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_r_up_srcdn_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCDN_CTRL0_audio_r_up_srcdn_fifo_clr_END (7)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_l_up_srcdn_src_mode_START (8)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_l_up_srcdn_src_mode_END (10)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_l_up_srcdn_fifo_clr_START (11)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_l_up_srcdn_fifo_clr_END (11)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_r_up_srcdn_src_mode_START (12)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_r_up_srcdn_src_mode_END (14)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_r_up_srcdn_fifo_clr_START (15)
#define SOC_ASP_CODEC_SRCDN_CTRL0_voice_r_up_srcdn_fifo_clr_END (15)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic3_up_srcdn_src_mode_START (16)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic3_up_srcdn_src_mode_END (18)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic3_up_srcdn_fifo_clr_START (19)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic3_up_srcdn_fifo_clr_END (19)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic4_up_srcdn_src_mode_START (20)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic4_up_srcdn_src_mode_END (22)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic4_up_srcdn_fifo_clr_START (23)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic4_up_srcdn_fifo_clr_END (23)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic5_up_srcdn_src_mode_START (24)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic5_up_srcdn_src_mode_END (26)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic5_up_srcdn_fifo_clr_START (27)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic5_up_srcdn_fifo_clr_END (27)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic6_up_srcdn_src_mode_START (28)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic6_up_srcdn_src_mode_END (30)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic6_up_srcdn_fifo_clr_START (31)
#define SOC_ASP_CODEC_SRCDN_CTRL0_mic6_up_srcdn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s2_rx_l_srcdn_src_mode : 3;
        unsigned int i2s2_rx_l_srcdn_fifo_clr : 1;
        unsigned int i2s2_rx_r_srcdn_src_mode : 3;
        unsigned int i2s2_rx_r_srcdn_fifo_clr : 1;
        unsigned int i2s2_tx_l_srcdn_src_mode : 3;
        unsigned int i2s2_tx_l_srcdn_fifo_clr : 1;
        unsigned int i2s2_tx_r_srcdn_src_mode : 3;
        unsigned int i2s2_tx_r_srcdn_fifo_clr : 1;
        unsigned int noise_meter_up_srcdn_src_mode : 3;
        unsigned int noise_meter_up_srcdn_fifo_clr : 1;
        unsigned int reserved : 4;
        unsigned int mic7_up_srcdn_src_mode : 3;
        unsigned int mic7_up_srcdn_fifo_clr : 1;
        unsigned int mic8_up_srcdn_src_mode : 3;
        unsigned int mic8_up_srcdn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SRCDN_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_l_srcdn_src_mode_START (0)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_l_srcdn_src_mode_END (2)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_l_srcdn_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_l_srcdn_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_r_srcdn_src_mode_START (4)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_r_srcdn_src_mode_END (6)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_r_srcdn_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_rx_r_srcdn_fifo_clr_END (7)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_l_srcdn_src_mode_START (8)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_l_srcdn_src_mode_END (10)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_l_srcdn_fifo_clr_START (11)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_l_srcdn_fifo_clr_END (11)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_r_srcdn_src_mode_START (12)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_r_srcdn_src_mode_END (14)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_r_srcdn_fifo_clr_START (15)
#define SOC_ASP_CODEC_SRCDN_CTRL1_i2s2_tx_r_srcdn_fifo_clr_END (15)
#define SOC_ASP_CODEC_SRCDN_CTRL1_noise_meter_up_srcdn_src_mode_START (16)
#define SOC_ASP_CODEC_SRCDN_CTRL1_noise_meter_up_srcdn_src_mode_END (18)
#define SOC_ASP_CODEC_SRCDN_CTRL1_noise_meter_up_srcdn_fifo_clr_START (19)
#define SOC_ASP_CODEC_SRCDN_CTRL1_noise_meter_up_srcdn_fifo_clr_END (19)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic7_up_srcdn_src_mode_START (24)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic7_up_srcdn_src_mode_END (26)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic7_up_srcdn_fifo_clr_START (27)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic7_up_srcdn_fifo_clr_END (27)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic8_up_srcdn_src_mode_START (28)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic8_up_srcdn_src_mode_END (30)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic8_up_srcdn_fifo_clr_START (31)
#define SOC_ASP_CODEC_SRCDN_CTRL1_mic8_up_srcdn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int spa0_mixer4_gain1 : 2;
        unsigned int spa0_mixer4_gain2 : 2;
        unsigned int spa0_mixer4_gain3 : 2;
        unsigned int spa0_mixer4_gain4 : 2;
        unsigned int spa0_mixer4_in1_mute : 1;
        unsigned int spa0_mixer4_in2_mute : 1;
        unsigned int spa0_mixer4_in3_mute : 1;
        unsigned int spa0_mixer4_in4_mute : 1;
        unsigned int spa0_mixer4_in1_id : 2;
        unsigned int spa0_mixer4_in2_id : 2;
        unsigned int spa0_mixer4_in3_id : 2;
        unsigned int spa0_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL0_spa0_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int spa0_mixer4_zero_num : 5;
        unsigned int spa0_mixer4_fade_out : 5;
        unsigned int spa0_mixer4_fade_in : 5;
        unsigned int spa0_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_SPA0_MIXER4_CTRL1_spa0_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int spa1_mixer4_gain1 : 2;
        unsigned int spa1_mixer4_gain2 : 2;
        unsigned int spa1_mixer4_gain3 : 2;
        unsigned int spa1_mixer4_gain4 : 2;
        unsigned int spa1_mixer4_in1_mute : 1;
        unsigned int spa1_mixer4_in2_mute : 1;
        unsigned int spa1_mixer4_in3_mute : 1;
        unsigned int spa1_mixer4_in4_mute : 1;
        unsigned int spa1_mixer4_in1_id : 2;
        unsigned int spa1_mixer4_in2_id : 2;
        unsigned int spa1_mixer4_in3_id : 2;
        unsigned int spa1_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL0_spa1_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int spa1_mixer4_zero_num : 5;
        unsigned int spa1_mixer4_fade_out : 5;
        unsigned int spa1_mixer4_fade_in : 5;
        unsigned int spa1_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_SPA1_MIXER4_CTRL1_spa1_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int spa2_mixer4_gain1 : 2;
        unsigned int spa2_mixer4_gain2 : 2;
        unsigned int spa2_mixer4_gain3 : 2;
        unsigned int spa2_mixer4_gain4 : 2;
        unsigned int spa2_mixer4_in1_mute : 1;
        unsigned int spa2_mixer4_in2_mute : 1;
        unsigned int spa2_mixer4_in3_mute : 1;
        unsigned int spa2_mixer4_in4_mute : 1;
        unsigned int spa2_mixer4_in1_id : 2;
        unsigned int spa2_mixer4_in2_id : 2;
        unsigned int spa2_mixer4_in3_id : 2;
        unsigned int spa2_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL0_spa2_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int spa2_mixer4_zero_num : 5;
        unsigned int spa2_mixer4_fade_out : 5;
        unsigned int spa2_mixer4_fade_in : 5;
        unsigned int spa2_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_SPA2_MIXER4_CTRL1_spa2_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int i2s2_tx_mixer2_zero_num : 5;
        unsigned int i2s2_tx_mixer2_fade_out : 5;
        unsigned int i2s2_tx_mixer2_fade_in : 5;
        unsigned int i2s2_tx_mixer2_fade_en : 1;
        unsigned int i2s2_tx_mixer2_gain1 : 2;
        unsigned int i2s2_tx_mixer2_gain2 : 2;
        unsigned int i2s2_tx_mixer2_in1_mute : 1;
        unsigned int i2s2_tx_mixer2_in2_mute : 1;
        unsigned int i2s2_tx_mixer2_in1_id : 2;
        unsigned int i2s2_tx_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_I2S2_TX_MIXER2_CTRL_i2s2_tx_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int ultr0_mixer2_zero_num : 5;
        unsigned int ultr0_mixer2_fade_out : 5;
        unsigned int ultr0_mixer2_fade_in : 5;
        unsigned int ultr0_mixer2_fade_en : 1;
        unsigned int ultr0_mixer2_gain1 : 2;
        unsigned int ultr0_mixer2_gain2 : 2;
        unsigned int ultr0_mixer2_in1_mute : 1;
        unsigned int ultr0_mixer2_in2_mute : 1;
        unsigned int ultr0_mixer2_in1_id : 2;
        unsigned int ultr0_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_ULTR0_MIXER2_CTRL_ultr0_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int ultr1_mixer2_zero_num : 5;
        unsigned int ultr1_mixer2_fade_out : 5;
        unsigned int ultr1_mixer2_fade_in : 5;
        unsigned int ultr1_mixer2_fade_en : 1;
        unsigned int ultr1_mixer2_gain1 : 2;
        unsigned int ultr1_mixer2_gain2 : 2;
        unsigned int ultr1_mixer2_in1_mute : 1;
        unsigned int ultr1_mixer2_in2_mute : 1;
        unsigned int ultr1_mixer2_in1_id : 2;
        unsigned int ultr1_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_ULTR1_MIXER2_CTRL_ultr1_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int ultr2_mixer2_zero_num : 5;
        unsigned int ultr2_mixer2_fade_out : 5;
        unsigned int ultr2_mixer2_fade_in : 5;
        unsigned int ultr2_mixer2_fade_en : 1;
        unsigned int ultr2_mixer2_gain1 : 2;
        unsigned int ultr2_mixer2_gain2 : 2;
        unsigned int ultr2_mixer2_in1_mute : 1;
        unsigned int ultr2_mixer2_in2_mute : 1;
        unsigned int ultr2_mixer2_in1_id : 2;
        unsigned int ultr2_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_ULTR2_MIXER2_CTRL_ultr2_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int adc8_cic_gain : 6;
        unsigned int adc7_cic_gain : 6;
        unsigned int reserved_1 : 4;
        unsigned int adc6_cic_gain : 6;
        unsigned int adc5_cic_gain : 6;
    } reg;
} SOC_ASP_CODEC_ADC_FILTER_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc8_cic_gain_START (4)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc8_cic_gain_END (9)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc7_cic_gain_START (10)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc7_cic_gain_END (15)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc6_cic_gain_START (20)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc6_cic_gain_END (25)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc5_cic_gain_START (26)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL0_adc5_cic_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int adc4_cic_gain : 6;
        unsigned int adc3_cic_gain : 6;
        unsigned int reserved_1 : 4;
        unsigned int adc2_cic_gain : 6;
        unsigned int adc1_cic_gain : 6;
    } reg;
} SOC_ASP_CODEC_ADC_FILTER_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc4_cic_gain_START (4)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc4_cic_gain_END (9)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc3_cic_gain_START (10)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc3_cic_gain_END (15)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc2_cic_gain_START (20)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc2_cic_gain_END (25)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc1_cic_gain_START (26)
#define SOC_ASP_CODEC_ADC_FILTER_CTRL1_adc1_cic_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmic1_sw_dmic_mode : 1;
        unsigned int dmic1_reverse : 1;
        unsigned int dmic2_sw_dmic_mode : 1;
        unsigned int dmic2_reverse : 1;
        unsigned int dmic3_sw_dmic_mode : 1;
        unsigned int dmic3_reverse : 1;
        unsigned int dmic4_sw_dmic_mode : 1;
        unsigned int dmic4_reverse : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_DMIC_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_sw_dmic_mode_START (0)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_sw_dmic_mode_END (0)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_reverse_START (1)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic1_reverse_END (1)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_sw_dmic_mode_START (2)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_sw_dmic_mode_END (2)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_reverse_START (3)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic2_reverse_END (3)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic3_sw_dmic_mode_START (4)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic3_sw_dmic_mode_END (4)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic3_reverse_START (5)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic3_reverse_END (5)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic4_sw_dmic_mode_START (6)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic4_sw_dmic_mode_END (6)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic4_reverse_START (7)
#define SOC_ASP_CODEC_DMIC_CTRL_dmic4_reverse_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_dmic1 : 4;
        unsigned int fs_dmic2 : 4;
        unsigned int fs_dmic3 : 4;
        unsigned int fs_dmic4 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CODEC_DMIC_DIV_UNION;
#endif
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic1_START (0)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic1_END (3)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic2_START (4)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic2_END (7)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic3_START (8)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic3_END (11)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic4_START (12)
#define SOC_ASP_CODEC_DMIC_DIV_fs_dmic4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int spa_1_up_fifo_aempty_th : 5;
        unsigned int spa_1_up_fifo_afull_th : 5;
        unsigned int spa_1_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int spa_2_up_fifo_aempty_th : 5;
        unsigned int spa_2_up_fifo_afull_th : 5;
        unsigned int spa_2_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_1_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_1_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_1_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_1_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_1_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_1_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_2_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_2_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_2_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_2_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_2_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_SPA12_UP_AFIFO_CTRL_spa_2_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int spa_3_up_fifo_aempty_th : 5;
        unsigned int spa_3_up_fifo_afull_th : 5;
        unsigned int spa_3_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int spa_4_up_fifo_aempty_th : 5;
        unsigned int spa_4_up_fifo_afull_th : 5;
        unsigned int spa_4_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_3_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_3_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_3_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_3_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_3_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_3_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_4_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_4_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_4_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_4_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_4_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_SPA34_UP_AFIFO_CTRL_spa_4_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int spa_5_up_fifo_aempty_th : 5;
        unsigned int spa_5_up_fifo_afull_th : 5;
        unsigned int spa_5_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int spa_6_up_fifo_aempty_th : 5;
        unsigned int spa_6_up_fifo_afull_th : 5;
        unsigned int spa_6_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_5_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_5_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_5_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_5_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_5_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_5_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_6_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_6_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_6_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_6_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_6_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_SPA56_UP_AFIFO_CTRL_spa_6_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_1_dn_fifo_aempty_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int codec_1_dn_fifo_afull_th : 7;
        unsigned int codec_1_dn_fifo_clr : 1;
        unsigned int codec_0_dn_fifo_aempty_th : 7;
        unsigned int reserved_1 : 1;
        unsigned int codec_0_dn_fifo_afull_th : 7;
        unsigned int codec_0_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_1_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_1_dn_fifo_aempty_th_END (6)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_1_dn_fifo_afull_th_START (8)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_1_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_1_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_1_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_0_dn_fifo_aempty_th_START (16)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_0_dn_fifo_aempty_th_END (22)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_0_dn_fifo_afull_th_START (24)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_0_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_0_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_CODEC_0_DN_AFIFO_CTRL_codec_0_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_2_dn_fifo_aempty_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int codec_2_dn_fifo_afull_th : 7;
        unsigned int codec_2_dn_fifo_clr : 1;
        unsigned int audio_0_dn_fifo_aempty_th : 7;
        unsigned int reserved_1 : 1;
        unsigned int audio_0_dn_fifo_afull_th : 7;
        unsigned int audio_0_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_codec_2_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_codec_2_dn_fifo_aempty_th_END (6)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_codec_2_dn_fifo_afull_th_START (8)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_codec_2_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_codec_2_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_codec_2_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_audio_0_dn_fifo_aempty_th_START (16)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_audio_0_dn_fifo_aempty_th_END (22)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_audio_0_dn_fifo_afull_th_START (24)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_audio_0_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_audio_0_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_CODEC_1_DN_AFIFO_CTRL_audio_0_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_1_dn_fifo_aempty_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int audio_1_dn_fifo_afull_th : 7;
        unsigned int audio_1_dn_fifo_clr : 1;
        unsigned int audio_2_dn_fifo_aempty_th : 7;
        unsigned int reserved_1 : 1;
        unsigned int audio_2_dn_fifo_afull_th : 7;
        unsigned int audio_2_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_1_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_1_dn_fifo_aempty_th_END (6)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_1_dn_fifo_afull_th_START (8)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_1_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_1_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_1_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_2_dn_fifo_aempty_th_START (16)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_2_dn_fifo_aempty_th_END (22)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_2_dn_fifo_afull_th_START (24)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_2_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_2_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_AUDIO_DN_AFIFO_CTRL_audio_2_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ultr_dn_fifo_aempty_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int ultr_dn_fifo_afull_th : 7;
        unsigned int ultr_dn_fifo_clr : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CODEC_ULTR_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ultr_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ultr_dn_fifo_aempty_th_END (6)
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ultr_dn_fifo_afull_th_START (8)
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ultr_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ultr_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_ULTR_AFIFO_CTRL_ultr_dn_fifo_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int audio_r_up_fifo_aempty_th : 5;
        unsigned int audio_r_up_fifo_afull_th : 5;
        unsigned int audio_r_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int audio_l_up_fifo_aempty_th : 5;
        unsigned int audio_l_up_fifo_afull_th : 5;
        unsigned int audio_l_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_r_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_AUDIO_UP_AFIFO_CTRL_audio_l_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int voice_r_up_fifo_aempty_th : 5;
        unsigned int voice_r_up_fifo_afull_th : 5;
        unsigned int voice_r_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int voice_l_up_fifo_aempty_th : 5;
        unsigned int voice_l_up_fifo_afull_th : 5;
        unsigned int voice_l_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_r_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_VOICE_UP_AFIFO_CTRL_voice_l_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int mic3_up_fifo_aempty_th : 5;
        unsigned int mic3_up_fifo_afull_th : 5;
        unsigned int mic3_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int mic4_up_fifo_aempty_th : 5;
        unsigned int mic4_up_fifo_afull_th : 5;
        unsigned int mic4_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic3_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic3_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic3_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic3_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic3_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic3_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic4_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic4_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic4_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic4_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic4_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_MIC34_UP_AFIFO_CTRL_mic4_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int mic5_up_fifo_aempty_th : 5;
        unsigned int mic5_up_fifo_afull_th : 5;
        unsigned int mic5_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int mic6_up_fifo_aempty_th : 5;
        unsigned int mic6_up_fifo_afull_th : 5;
        unsigned int mic6_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic5_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic5_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic5_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic5_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic5_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic5_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic6_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic6_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic6_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic6_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic6_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_MIC56_UP_AFIFO_CTRL_mic6_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int mic7_up_fifo_aempty_th : 5;
        unsigned int mic7_up_fifo_afull_th : 5;
        unsigned int mic7_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int mic8_up_fifo_aempty_th : 5;
        unsigned int mic8_up_fifo_afull_th : 5;
        unsigned int mic8_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic7_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic7_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic7_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic7_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic7_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic7_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic8_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic8_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic8_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic8_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic8_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_MIC78_UP_AFIFO_CTRL_mic8_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int ultr_up_fifo_aempty_th : 5;
        unsigned int ultr_up_fifo_afull_th : 5;
        unsigned int ultr_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int audiozoom_up_fifo_aempty_th : 5;
        unsigned int audiozoom_up_fifo_afull_th : 5;
        unsigned int audiozoom_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_ultr_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_audiozoom_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_audiozoom_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_audiozoom_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_audiozoom_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_audiozoom_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_ULTR_UP_AFIFO_CTRL_audiozoom_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int noise_meter_up_fifo_aempty_th : 5;
        unsigned int noise_meter_up_fifo_afull_th : 5;
        unsigned int noise_meter_up_fifo_clr : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_noise_meter_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_noise_meter_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_noise_meter_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_noise_meter_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_noise_meter_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_NOISE_METER_UP_AFIFO_CTRL_noise_meter_up_fifo_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int sif_s2p_loop : 2;
        unsigned int sif_p2s_loop : 2;
        unsigned int mic7_din_sel : 3;
        unsigned int mic8_din_sel : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_ASP_CODEC_SIF_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SIF_CTRL_sif_s2p_loop_START (2)
#define SOC_ASP_CODEC_SIF_CTRL_sif_s2p_loop_END (3)
#define SOC_ASP_CODEC_SIF_CTRL_sif_p2s_loop_START (4)
#define SOC_ASP_CODEC_SIF_CTRL_sif_p2s_loop_END (5)
#define SOC_ASP_CODEC_SIF_CTRL_mic7_din_sel_START (6)
#define SOC_ASP_CODEC_SIF_CTRL_mic7_din_sel_END (8)
#define SOC_ASP_CODEC_SIF_CTRL_mic8_din_sel_START (9)
#define SOC_ASP_CODEC_SIF_CTRL_mic8_din_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_spa1_up_afifo : 2;
        unsigned int fs_spa2_up_afifo : 2;
        unsigned int fs_spa3_up_afifo : 2;
        unsigned int fs_spa_4_up_afifo : 2;
        unsigned int fs_codec_0_dn_afifo : 3;
        unsigned int fs_codec_1_dn_afifo : 3;
        unsigned int fs_codec_2_dn_afifo : 2;
        unsigned int fs_audio_2_dn_afifo : 2;
        unsigned int fs_bt_l_dn_afifo : 2;
        unsigned int fs_bt_r_dn_afifo : 2;
        unsigned int fs_audio_l_up_afifo : 2;
        unsigned int fs_audio_r_up_afifo : 2;
        unsigned int fs_mic8_up_pga : 3;
        unsigned int reserved : 3;
    } reg;
} SOC_ASP_CODEC_FS_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa1_up_afifo_START (0)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa1_up_afifo_END (1)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa2_up_afifo_START (2)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa2_up_afifo_END (3)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa3_up_afifo_START (4)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa3_up_afifo_END (5)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa_4_up_afifo_START (6)
#define SOC_ASP_CODEC_FS_CTRL0_fs_spa_4_up_afifo_END (7)
#define SOC_ASP_CODEC_FS_CTRL0_fs_codec_0_dn_afifo_START (8)
#define SOC_ASP_CODEC_FS_CTRL0_fs_codec_0_dn_afifo_END (10)
#define SOC_ASP_CODEC_FS_CTRL0_fs_codec_1_dn_afifo_START (11)
#define SOC_ASP_CODEC_FS_CTRL0_fs_codec_1_dn_afifo_END (13)
#define SOC_ASP_CODEC_FS_CTRL0_fs_codec_2_dn_afifo_START (14)
#define SOC_ASP_CODEC_FS_CTRL0_fs_codec_2_dn_afifo_END (15)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_2_dn_afifo_START (16)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_2_dn_afifo_END (17)
#define SOC_ASP_CODEC_FS_CTRL0_fs_bt_l_dn_afifo_START (18)
#define SOC_ASP_CODEC_FS_CTRL0_fs_bt_l_dn_afifo_END (19)
#define SOC_ASP_CODEC_FS_CTRL0_fs_bt_r_dn_afifo_START (20)
#define SOC_ASP_CODEC_FS_CTRL0_fs_bt_r_dn_afifo_END (21)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_l_up_afifo_START (22)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_l_up_afifo_END (23)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_r_up_afifo_START (24)
#define SOC_ASP_CODEC_FS_CTRL0_fs_audio_r_up_afifo_END (25)
#define SOC_ASP_CODEC_FS_CTRL0_fs_mic8_up_pga_START (26)
#define SOC_ASP_CODEC_FS_CTRL0_fs_mic8_up_pga_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_voice_l_up_afifo : 3;
        unsigned int fs_voice_r_up_afifo : 3;
        unsigned int fs_mic3_up_afifo : 3;
        unsigned int fs_mic4_up_afifo : 3;
        unsigned int fs_mic5_up_afifo : 3;
        unsigned int fs_mic6_up_afifo : 3;
        unsigned int fs_mic7_up_afifo : 3;
        unsigned int fs_mic8_up_afifo : 3;
        unsigned int fs_ultr_up_afifo : 2;
        unsigned int reserved_0 : 2;
        unsigned int fs_mic7_up_pga : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_ASP_CODEC_FS_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_l_up_afifo_START (0)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_l_up_afifo_END (2)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_r_up_afifo_START (3)
#define SOC_ASP_CODEC_FS_CTRL1_fs_voice_r_up_afifo_END (5)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic3_up_afifo_START (6)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic3_up_afifo_END (8)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic4_up_afifo_START (9)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic4_up_afifo_END (11)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic5_up_afifo_START (12)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic5_up_afifo_END (14)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic6_up_afifo_START (15)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic6_up_afifo_END (17)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic7_up_afifo_START (18)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic7_up_afifo_END (20)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic8_up_afifo_START (21)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic8_up_afifo_END (23)
#define SOC_ASP_CODEC_FS_CTRL1_fs_ultr_up_afifo_START (24)
#define SOC_ASP_CODEC_FS_CTRL1_fs_ultr_up_afifo_END (25)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic7_up_pga_START (28)
#define SOC_ASP_CODEC_FS_CTRL1_fs_mic7_up_pga_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_codec_0_dn_pga : 2;
        unsigned int fs_codec_1_dn_pga : 2;
        unsigned int fs_codec_2_dn_pga : 2;
        unsigned int fs_audio_0_dn_pga : 2;
        unsigned int fs_audio_1_dn_pga : 2;
        unsigned int fs_audio_2_dn_pga : 2;
        unsigned int fs_audio_l_up_pga : 2;
        unsigned int fs_audio_r_up_pga : 2;
        unsigned int fs_mic3_up_pga : 3;
        unsigned int fs_mic4_up_pga : 3;
        unsigned int fs_mic5_up_pga : 3;
        unsigned int fs_mic6_up_pga : 3;
        unsigned int reserved : 4;
    } reg;
} SOC_ASP_CODEC_FS_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec_0_dn_pga_START (0)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec_0_dn_pga_END (1)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec_1_dn_pga_START (2)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec_1_dn_pga_END (3)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec_2_dn_pga_START (4)
#define SOC_ASP_CODEC_FS_CTRL2_fs_codec_2_dn_pga_END (5)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_0_dn_pga_START (6)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_0_dn_pga_END (7)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_1_dn_pga_START (8)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_1_dn_pga_END (9)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_2_dn_pga_START (10)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_2_dn_pga_END (11)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_l_up_pga_START (12)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_l_up_pga_END (13)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_r_up_pga_START (14)
#define SOC_ASP_CODEC_FS_CTRL2_fs_audio_r_up_pga_END (15)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic3_up_pga_START (16)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic3_up_pga_END (18)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic4_up_pga_START (19)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic4_up_pga_END (21)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic5_up_pga_START (22)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic5_up_pga_END (24)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic6_up_pga_START (25)
#define SOC_ASP_CODEC_FS_CTRL2_fs_mic6_up_pga_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_i2s2_rx_l_pga : 3;
        unsigned int fs_i2s2_rx_r_pga : 3;
        unsigned int fs_codec_0_dn_srcup_din : 2;
        unsigned int fs_codec_0_dn_srcup_dout : 3;
        unsigned int fs_codec_1_dn_srcup_din : 2;
        unsigned int fs_codec_1_dn_srcup_dout : 3;
        unsigned int fs_codec_2_dn_srcup_din : 2;
        unsigned int fs_codec_2_dn_srcup_dout : 3;
        unsigned int fs_audio_0_dn_srcup_din : 2;
        unsigned int fs_audio_0_dn_srcup_dout : 3;
        unsigned int fs_audio_1_dn_srcup_din : 2;
        unsigned int fs_audio_1_dn_srcup_dout : 3;
        unsigned int reserved : 1;
    } reg;
} SOC_ASP_CODEC_FS_CTRL3_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_rx_l_pga_START (0)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_rx_l_pga_END (2)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_rx_r_pga_START (3)
#define SOC_ASP_CODEC_FS_CTRL3_fs_i2s2_rx_r_pga_END (5)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_0_dn_srcup_din_START (6)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_0_dn_srcup_din_END (7)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_0_dn_srcup_dout_START (8)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_0_dn_srcup_dout_END (10)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_1_dn_srcup_din_START (11)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_1_dn_srcup_din_END (12)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_1_dn_srcup_dout_START (13)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_1_dn_srcup_dout_END (15)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_2_dn_srcup_din_START (16)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_2_dn_srcup_din_END (17)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_2_dn_srcup_dout_START (18)
#define SOC_ASP_CODEC_FS_CTRL3_fs_codec_2_dn_srcup_dout_END (20)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_0_dn_srcup_din_START (21)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_0_dn_srcup_din_END (22)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_0_dn_srcup_dout_START (23)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_0_dn_srcup_dout_END (25)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_1_dn_srcup_din_START (26)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_1_dn_srcup_din_END (27)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_1_dn_srcup_dout_START (28)
#define SOC_ASP_CODEC_FS_CTRL3_fs_audio_1_dn_srcup_dout_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 14;
        unsigned int fs_audio_up_l_srcdn_din : 2;
        unsigned int fs_audio_up_l_srcdn_dout : 2;
        unsigned int fs_audio_up_r_srcdn_din : 2;
        unsigned int fs_audio_up_r_srcdn_dout : 2;
        unsigned int fs_voice_up_l_srcdn_din : 2;
        unsigned int fs_voice_up_l_srcdn_dout : 3;
        unsigned int fs_voice_up_r_srcdn_din : 2;
        unsigned int fs_voice_up_r_srcdn_dout : 3;
    } reg;
} SOC_ASP_CODEC_FS_CTRL4_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_l_srcdn_din_START (14)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_l_srcdn_din_END (15)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_l_srcdn_dout_START (16)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_l_srcdn_dout_END (17)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_r_srcdn_din_START (18)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_r_srcdn_din_END (19)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_r_srcdn_dout_START (20)
#define SOC_ASP_CODEC_FS_CTRL4_fs_audio_up_r_srcdn_dout_END (21)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_l_srcdn_din_START (22)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_l_srcdn_din_END (23)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_l_srcdn_dout_START (24)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_l_srcdn_dout_END (26)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_r_srcdn_din_START (27)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_r_srcdn_din_END (28)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_r_srcdn_dout_START (29)
#define SOC_ASP_CODEC_FS_CTRL4_fs_voice_up_r_srcdn_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_mic3_srcdn_dout : 3;
        unsigned int fs_mic4_srcdn_dout : 3;
        unsigned int fs_mic5_srcdn_dout : 3;
        unsigned int fs_mic6_srcdn_dout : 3;
        unsigned int fs_mic7_srcdn_dout : 3;
        unsigned int fs_mic8_srcdn_dout : 3;
        unsigned int fs_i2s2_rx_l_srcdn_din : 3;
        unsigned int fs_i2s2_rx_l_srcdn_dout : 3;
        unsigned int fs_voice_l_up_pga : 3;
        unsigned int fs_voice_r_up_pga : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ASP_CODEC_FS_CTRL5_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic3_srcdn_dout_START (0)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic3_srcdn_dout_END (2)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic4_srcdn_dout_START (3)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic4_srcdn_dout_END (5)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic5_srcdn_dout_START (6)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic5_srcdn_dout_END (8)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic6_srcdn_dout_START (9)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic6_srcdn_dout_END (11)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic7_srcdn_dout_START (12)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic7_srcdn_dout_END (14)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic8_srcdn_dout_START (15)
#define SOC_ASP_CODEC_FS_CTRL5_fs_mic8_srcdn_dout_END (17)
#define SOC_ASP_CODEC_FS_CTRL5_fs_i2s2_rx_l_srcdn_din_START (18)
#define SOC_ASP_CODEC_FS_CTRL5_fs_i2s2_rx_l_srcdn_din_END (20)
#define SOC_ASP_CODEC_FS_CTRL5_fs_i2s2_rx_l_srcdn_dout_START (21)
#define SOC_ASP_CODEC_FS_CTRL5_fs_i2s2_rx_l_srcdn_dout_END (23)
#define SOC_ASP_CODEC_FS_CTRL5_fs_voice_l_up_pga_START (24)
#define SOC_ASP_CODEC_FS_CTRL5_fs_voice_l_up_pga_END (26)
#define SOC_ASP_CODEC_FS_CTRL5_fs_voice_r_up_pga_START (27)
#define SOC_ASP_CODEC_FS_CTRL5_fs_voice_r_up_pga_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_i2s2_rx_r_srcdn_din : 3;
        unsigned int fs_i2s2_rx_r_srcdn_dout : 3;
        unsigned int fs_i2s2_tx_l_srcdn_din : 2;
        unsigned int fs_i2s2_tx_l_srcdn_dout : 3;
        unsigned int fs_i2s2_tx_r_srcdn_din : 2;
        unsigned int fs_i2s2_tx_r_srcdn_dout : 3;
        unsigned int fs_i2s2_tx_mixer2 : 3;
        unsigned int fs_s1_tdm : 2;
        unsigned int fs_spa2_mixer4 : 1;
        unsigned int fs_spa1_mixer4 : 1;
        unsigned int fs_spa0_mixer4 : 1;
        unsigned int fs_audio_0_dn_afifo : 3;
        unsigned int fs_audio_1_dn_afifo : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_ASP_CODEC_FS_CTRL6_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_rx_r_srcdn_din_START (0)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_rx_r_srcdn_din_END (2)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_rx_r_srcdn_dout_START (3)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_rx_r_srcdn_dout_END (5)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_l_srcdn_din_START (6)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_l_srcdn_din_END (7)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_l_srcdn_dout_START (8)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_l_srcdn_dout_END (10)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_r_srcdn_din_START (11)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_r_srcdn_din_END (12)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_r_srcdn_dout_START (13)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_r_srcdn_dout_END (15)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_mixer2_START (16)
#define SOC_ASP_CODEC_FS_CTRL6_fs_i2s2_tx_mixer2_END (18)
#define SOC_ASP_CODEC_FS_CTRL6_fs_s1_tdm_START (19)
#define SOC_ASP_CODEC_FS_CTRL6_fs_s1_tdm_END (20)
#define SOC_ASP_CODEC_FS_CTRL6_fs_spa2_mixer4_START (21)
#define SOC_ASP_CODEC_FS_CTRL6_fs_spa2_mixer4_END (21)
#define SOC_ASP_CODEC_FS_CTRL6_fs_spa1_mixer4_START (22)
#define SOC_ASP_CODEC_FS_CTRL6_fs_spa1_mixer4_END (22)
#define SOC_ASP_CODEC_FS_CTRL6_fs_spa0_mixer4_START (23)
#define SOC_ASP_CODEC_FS_CTRL6_fs_spa0_mixer4_END (23)
#define SOC_ASP_CODEC_FS_CTRL6_fs_audio_0_dn_afifo_START (24)
#define SOC_ASP_CODEC_FS_CTRL6_fs_audio_0_dn_afifo_END (26)
#define SOC_ASP_CODEC_FS_CTRL6_fs_audio_1_dn_afifo_START (27)
#define SOC_ASP_CODEC_FS_CTRL6_fs_audio_1_dn_afifo_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s1_tx_l_sel : 2;
        unsigned int i2s1_tx_r_sel : 2;
        unsigned int i2s2_tx_r_sel : 1;
        unsigned int sidetone_pga_din_sel : 3;
        unsigned int adc1_din_sel : 1;
        unsigned int adc2_din_sel : 1;
        unsigned int adc3_din_sel : 1;
        unsigned int adc4_din_sel : 1;
        unsigned int au_up_l_din_sel : 3;
        unsigned int au_up_r_din_sel : 3;
        unsigned int vo_up_l_din_sel : 3;
        unsigned int vo_up_r_din_sel : 3;
        unsigned int mic3_din_sel : 3;
        unsigned int mic4_din_sel : 3;
        unsigned int i2s2_tx_sel : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_DIN_MUX0_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s1_tx_l_sel_START (0)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s1_tx_l_sel_END (1)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s1_tx_r_sel_START (2)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s1_tx_r_sel_END (3)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s2_tx_r_sel_START (4)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s2_tx_r_sel_END (4)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_sidetone_pga_din_sel_START (5)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_sidetone_pga_din_sel_END (7)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc1_din_sel_START (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc1_din_sel_END (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc2_din_sel_START (9)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc2_din_sel_END (9)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc3_din_sel_START (10)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc3_din_sel_END (10)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc4_din_sel_START (11)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_adc4_din_sel_END (11)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_au_up_l_din_sel_START (12)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_au_up_l_din_sel_END (14)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_au_up_r_din_sel_START (15)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_au_up_r_din_sel_END (17)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_vo_up_l_din_sel_START (18)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_vo_up_l_din_sel_END (20)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_vo_up_r_din_sel_START (21)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_vo_up_r_din_sel_END (23)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_mic3_din_sel_START (24)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_mic3_din_sel_END (26)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_mic4_din_sel_START (27)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_mic4_din_sel_END (29)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s2_tx_sel_START (30)
#define SOC_ASP_CODEC_CODEC_DIN_MUX0_i2s2_tx_sel_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mic5_din_sel : 4;
        unsigned int mic6_din_sel : 4;
        unsigned int bm_i2s1_tdm_tx_l_din_sel : 1;
        unsigned int bm_i2s1_tdm_tx_r_din_sel : 1;
        unsigned int noise_meter_pga_din : 4;
        unsigned int bt_tx_srcdn_din_sel : 1;
        unsigned int dacl_srcup_din_sel : 1;
        unsigned int dacr_srcup_din_sel : 1;
        unsigned int adc1_cic_dout_sel : 2;
        unsigned int adc2_cic_dout_sel : 2;
        unsigned int adc3_cic_dout_sel : 2;
        unsigned int adc4_cic_dout_sel : 2;
        unsigned int adc5_cic_dout_sel : 1;
        unsigned int adc6_cic_dout_sel : 1;
        unsigned int adc7_cic_dout_sel : 1;
        unsigned int adc8_cic_dout_sel : 1;
        unsigned int adc_ultr_cic_din_sel : 3;
    } reg;
} SOC_ASP_CODEC_CODEC_DIN_MUX1_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_mic5_din_sel_START (0)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_mic5_din_sel_END (3)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_mic6_din_sel_START (4)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_mic6_din_sel_END (7)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_bm_i2s1_tdm_tx_l_din_sel_START (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_bm_i2s1_tdm_tx_l_din_sel_END (8)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_bm_i2s1_tdm_tx_r_din_sel_START (9)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_bm_i2s1_tdm_tx_r_din_sel_END (9)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_noise_meter_pga_din_START (10)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_noise_meter_pga_din_END (13)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_bt_tx_srcdn_din_sel_START (14)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_bt_tx_srcdn_din_sel_END (14)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_dacl_srcup_din_sel_START (15)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_dacl_srcup_din_sel_END (15)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_dacr_srcup_din_sel_START (16)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_dacr_srcup_din_sel_END (16)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc1_cic_dout_sel_START (17)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc1_cic_dout_sel_END (18)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc2_cic_dout_sel_START (19)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc2_cic_dout_sel_END (20)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc3_cic_dout_sel_START (21)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc3_cic_dout_sel_END (22)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc4_cic_dout_sel_START (23)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc4_cic_dout_sel_END (24)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc5_cic_dout_sel_START (25)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc5_cic_dout_sel_END (25)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc6_cic_dout_sel_START (26)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc6_cic_dout_sel_END (26)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc7_cic_dout_sel_START (27)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc7_cic_dout_sel_END (27)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc8_cic_dout_sel_START (28)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc8_cic_dout_sel_END (28)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc_ultr_cic_din_sel_START (29)
#define SOC_ASP_CODEC_CODEC_DIN_MUX1_adc_ultr_cic_din_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc1_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC1_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC1_DC_OFFSET_adc1_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC1_DC_OFFSET_adc1_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc2_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC2_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC2_DC_OFFSET_adc2_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC2_DC_OFFSET_adc2_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc3_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC3_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC3_DC_OFFSET_adc3_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC3_DC_OFFSET_adc3_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc4_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC4_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC4_DC_OFFSET_adc4_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC4_DC_OFFSET_adc4_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc5_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC5_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC5_DC_OFFSET_adc5_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC5_DC_OFFSET_adc5_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc6_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC6_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC6_DC_OFFSET_adc6_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC6_DC_OFFSET_adc6_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc7_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC7_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC7_DC_OFFSET_adc7_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC7_DC_OFFSET_adc7_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc8_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC8_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC8_DC_OFFSET_adc8_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC8_DC_OFFSET_adc8_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc_ultr_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_adc_ultr_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_ADC_ULTR_DC_OFFSET_adc_ultr_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ASP_CODEC_MEM_CTRL_S_UNION;
#endif
#define SOC_ASP_CODEC_MEM_CTRL_S_mem_ctrl_s_START (0)
#define SOC_ASP_CODEC_MEM_CTRL_S_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CODEC_MEM_CTRL_1W2R_UNION;
#endif
#define SOC_ASP_CODEC_MEM_CTRL_1W2R_mem_ctrl_d1w2r_START (0)
#define SOC_ASP_CODEC_MEM_CTRL_1W2R_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc1_hpf_bypass_en : 1;
        unsigned int adc2_hpf_bypass_en : 1;
        unsigned int adc3_hpf_bypass_en : 1;
        unsigned int adc4_hpf_bypass_en : 1;
        unsigned int adc5_hpf_bypass_en : 1;
        unsigned int adc6_hpf_bypass_en : 1;
        unsigned int adc7_hpf_bypass_en : 1;
        unsigned int adc8_hpf_bypass_en : 1;
        unsigned int dacr_up16_hbf3_bypass_en : 1;
        unsigned int dacr_up16_hbf2_bypass_en : 1;
        unsigned int dacr_up16_hbf1_bypass_en : 1;
        unsigned int dacr_up16_hbf0_bypass_en : 1;
        unsigned int dacl_up16_hbf3_bypass_en : 1;
        unsigned int dacl_up16_hbf2_bypass_en : 1;
        unsigned int dacl_up16_hbf1_bypass_en : 1;
        unsigned int dacl_up16_hbf0_bypass_en : 1;
        unsigned int adc_ultr_hpf_bypass_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_ASP_CODEC_ADC_CTRL_HPF_UNION;
#endif
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc1_hpf_bypass_en_START (0)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc1_hpf_bypass_en_END (0)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc2_hpf_bypass_en_START (1)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc2_hpf_bypass_en_END (1)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc3_hpf_bypass_en_START (2)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc3_hpf_bypass_en_END (2)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc4_hpf_bypass_en_START (3)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc4_hpf_bypass_en_END (3)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc5_hpf_bypass_en_START (4)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc5_hpf_bypass_en_END (4)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc6_hpf_bypass_en_START (5)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc6_hpf_bypass_en_END (5)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc7_hpf_bypass_en_START (6)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc7_hpf_bypass_en_END (6)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc8_hpf_bypass_en_START (7)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc8_hpf_bypass_en_END (7)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf3_bypass_en_START (8)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf3_bypass_en_END (8)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf2_bypass_en_START (9)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf2_bypass_en_END (9)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf1_bypass_en_START (10)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf1_bypass_en_END (10)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf0_bypass_en_START (11)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacr_up16_hbf0_bypass_en_END (11)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf3_bypass_en_START (12)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf3_bypass_en_END (12)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf2_bypass_en_START (13)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf2_bypass_en_END (13)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf1_bypass_en_START (14)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf1_bypass_en_END (14)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf0_bypass_en_START (15)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_dacl_up16_hbf0_bypass_en_END (15)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc_ultr_hpf_bypass_en_START (16)
#define SOC_ASP_CODEC_ADC_CTRL_HPF_adc_ultr_hpf_bypass_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bt_l_dn_fifo_aempty_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int bt_l_dn_fifo_afull_th : 7;
        unsigned int bt_l_dn_fifo_clr : 1;
        unsigned int bt_r_dn_fifo_aempty_th : 7;
        unsigned int reserved_1 : 1;
        unsigned int bt_r_dn_fifo_afull_th : 7;
        unsigned int bt_r_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_l_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_l_dn_fifo_aempty_th_END (6)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_l_dn_fifo_afull_th_START (8)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_l_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_l_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_l_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_r_dn_fifo_aempty_th_START (16)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_r_dn_fifo_aempty_th_END (22)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_r_dn_fifo_afull_th_START (24)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_r_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_r_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_BT_DN_AFIFO_CTRL_bt_r_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dacl_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_dacl_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_DACL_DC_OFFSET_dacl_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dacr_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_dacr_dc_offset_START (0)
#define SOC_ASP_CODEC_CODEC_DACR_DC_OFFSET_dacr_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdm_r_calt_vld : 1;
        unsigned int sdm_r_dither : 1;
        unsigned int dacr_fir2d_bypass_en : 1;
        unsigned int dacr_fir2c_bypass_en : 1;
        unsigned int sdm_l_calt_vld : 1;
        unsigned int sdm_l_dither : 1;
        unsigned int dacl_fir2d_bypass_en : 1;
        unsigned int dacl_fir2c_bypass_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_DAC_FILTER_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_calt_vld_START (0)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_calt_vld_END (0)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_dither_START (1)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_r_dither_END (1)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2d_bypass_en_START (2)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2d_bypass_en_END (2)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2c_bypass_en_START (3)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacr_fir2c_bypass_en_END (3)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_calt_vld_START (4)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_calt_vld_END (4)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_dither_START (5)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_sdm_l_dither_END (5)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2d_bypass_en_START (6)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2d_bypass_en_END (6)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2c_bypass_en_START (7)
#define SOC_ASP_CODEC_DAC_FILTER_CTRL_dacl_fir2c_bypass_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc1_cic_dn4_ultra_gain : 8;
        unsigned int adc1_cic_dn8_ultra_gain : 4;
        unsigned int reserved_0 : 4;
        unsigned int adc2_cic_dn4_ultra_gain : 8;
        unsigned int adc2_cic_dn8_ultra_gain : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ASP_CODEC_CIC_ULTRA_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc1_cic_dn4_ultra_gain_START (0)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc1_cic_dn4_ultra_gain_END (7)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc1_cic_dn8_ultra_gain_START (8)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc1_cic_dn8_ultra_gain_END (11)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc2_cic_dn4_ultra_gain_START (16)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc2_cic_dn4_ultra_gain_END (23)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc2_cic_dn8_ultra_gain_START (24)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL0_adc2_cic_dn8_ultra_gain_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc3_cic_dn4_ultra_gain : 8;
        unsigned int adc3_cic_dn8_ultra_gain : 4;
        unsigned int reserved_0 : 4;
        unsigned int adc4_cic_dn4_ultra_gain : 8;
        unsigned int adc4_cic_dn8_ultra_gain : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ASP_CODEC_CIC_ULTRA_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc3_cic_dn4_ultra_gain_START (0)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc3_cic_dn4_ultra_gain_END (7)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc3_cic_dn8_ultra_gain_START (8)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc3_cic_dn8_ultra_gain_END (11)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc4_cic_dn4_ultra_gain_START (16)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc4_cic_dn4_ultra_gain_END (23)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc4_cic_dn8_ultra_gain_START (24)
#define SOC_ASP_CODEC_CIC_ULTRA_CTRL1_adc4_cic_dn8_ultra_gain_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sif0_dacl_en : 1;
        unsigned int sif0_dacr_en : 1;
        unsigned int sif0_adcl_en : 1;
        unsigned int sif0_adcr_en : 1;
        unsigned int sif0_adc_mic3_en : 1;
        unsigned int sif0_dac_ultr_en : 1;
        unsigned int sif0_spa_dac_en : 1;
        unsigned int sif0_spa_adc_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_SIF0_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_dacl_en_START (0)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_dacl_en_END (0)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_dacr_en_START (1)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_dacr_en_END (1)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_adcl_en_START (2)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_adcl_en_END (2)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_adcr_en_START (3)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_adcr_en_END (3)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_adc_mic3_en_START (4)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_adc_mic3_en_END (4)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_dac_ultr_en_START (5)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_dac_ultr_en_END (5)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_spa_dac_en_START (6)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_spa_dac_en_END (6)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_spa_adc_en_START (7)
#define SOC_ASP_CODEC_SIF0_CTRL_sif0_spa_adc_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hp_l_srcup_din_sel : 1;
        unsigned int hp_l_fir2c_bypass_en : 1;
        unsigned int hp_l_fir2d_bypass_en : 1;
        unsigned int hp_l_hbf0_bypass_en : 1;
        unsigned int hp_l_hbf1_bypass_en : 1;
        unsigned int hp_l_hbf2_bypass_en : 1;
        unsigned int hp_l_hbf3_bypass_en : 1;
        unsigned int hp_l_sdm_calt_vld : 1;
        unsigned int hp_l_sdm_dither : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CODEC_HP_L_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_srcup_din_sel_START (0)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_srcup_din_sel_END (0)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_fir2c_bypass_en_START (1)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_fir2c_bypass_en_END (1)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_fir2d_bypass_en_START (2)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_fir2d_bypass_en_END (2)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf0_bypass_en_START (3)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf0_bypass_en_END (3)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf1_bypass_en_START (4)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf1_bypass_en_END (4)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf2_bypass_en_START (5)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf2_bypass_en_END (5)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf3_bypass_en_START (6)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_hbf3_bypass_en_END (6)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_sdm_calt_vld_START (7)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_sdm_calt_vld_END (7)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_sdm_dither_START (8)
#define SOC_ASP_CODEC_HP_L_CTRL0_hp_l_sdm_dither_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hp_l_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_HP_L_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_HP_L_CTRL1_hp_l_dc_offset_START (0)
#define SOC_ASP_CODEC_HP_L_CTRL1_hp_l_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hp_r_srcup_din_sel : 1;
        unsigned int hp_r_fir2c_bypass_en : 1;
        unsigned int hp_r_fir2d_bypass_en : 1;
        unsigned int hp_r_hbf0_bypass_en : 1;
        unsigned int hp_r_hbf1_bypass_en : 1;
        unsigned int hp_r_hbf2_bypass_en : 1;
        unsigned int hp_r_hbf3_bypass_en : 1;
        unsigned int hp_r_sdm_calt_vld : 1;
        unsigned int hp_r_sdm_dither : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CODEC_HP_R_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_srcup_din_sel_START (0)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_srcup_din_sel_END (0)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_fir2c_bypass_en_START (1)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_fir2c_bypass_en_END (1)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_fir2d_bypass_en_START (2)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_fir2d_bypass_en_END (2)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf0_bypass_en_START (3)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf0_bypass_en_END (3)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf1_bypass_en_START (4)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf1_bypass_en_END (4)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf2_bypass_en_START (5)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf2_bypass_en_END (5)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf3_bypass_en_START (6)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_hbf3_bypass_en_END (6)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_sdm_calt_vld_START (7)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_sdm_calt_vld_END (7)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_sdm_dither_START (8)
#define SOC_ASP_CODEC_HP_R_CTRL0_hp_r_sdm_dither_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hp_r_dc_offset : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_HP_R_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_HP_R_CTRL1_hp_r_dc_offset_START (0)
#define SOC_ASP_CODEC_HP_R_CTRL1_hp_r_dc_offset_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ultr_adc_cic_gain : 6;
        unsigned int reserved_0 : 2;
        unsigned int ultr_adc_compd_bypass_en : 1;
        unsigned int ultr_adc_hbf2d_bypass_en : 1;
        unsigned int ultr_adc_hbfvd_bypass_en : 1;
        unsigned int ultr_adc_hpf_bypass_en : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_ASP_CODEC_ULTR_ADC_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_cic_gain_START (0)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_cic_gain_END (5)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_compd_bypass_en_START (8)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_compd_bypass_en_END (8)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_hbf2d_bypass_en_START (9)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_hbf2d_bypass_en_END (9)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_hbfvd_bypass_en_START (10)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_hbfvd_bypass_en_END (10)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_hpf_bypass_en_START (11)
#define SOC_ASP_CODEC_ULTR_ADC_CTRL0_ultr_adc_hpf_bypass_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adc1_cic_ultra_sel : 1;
        unsigned int adc2_cic_ultra_sel : 1;
        unsigned int adc3_cic_ultra_sel : 1;
        unsigned int adc4_cic_ultra_sel : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc1_cic_ultra_sel_START (0)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc1_cic_ultra_sel_END (0)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc2_cic_ultra_sel_START (1)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc2_cic_ultra_sel_END (1)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc3_cic_ultra_sel_START (2)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc3_cic_ultra_sel_END (2)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc4_cic_ultra_sel_START (3)
#define SOC_ASP_CODEC_ADC_ULTRA_CIC_CTRL_adc4_cic_ultra_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_audio_2_dn_srcup_din : 2;
        unsigned int fs_audio_2_dn_srcup_dout : 3;
        unsigned int fs_i2s2_rx_l_srcup_din : 3;
        unsigned int fs_i2s2_rx_l_srcup_dout : 3;
        unsigned int fs_i2s2_rx_r_srcup_din : 3;
        unsigned int fs_i2s2_rx_r_srcup_dout : 3;
        unsigned int fs_dacl_mixer4_srcup_din : 2;
        unsigned int fs_dacl_mixer4_srcup_dout : 2;
        unsigned int fs_dacr_mixer4_srcup_din : 2;
        unsigned int fs_dacr_mixer4_srcup_dout : 2;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_CODEC_FS_CTRL7_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL7_fs_audio_2_dn_srcup_din_START (0)
#define SOC_ASP_CODEC_FS_CTRL7_fs_audio_2_dn_srcup_din_END (1)
#define SOC_ASP_CODEC_FS_CTRL7_fs_audio_2_dn_srcup_dout_START (2)
#define SOC_ASP_CODEC_FS_CTRL7_fs_audio_2_dn_srcup_dout_END (4)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_l_srcup_din_START (5)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_l_srcup_din_END (7)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_l_srcup_dout_START (8)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_l_srcup_dout_END (10)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_r_srcup_din_START (11)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_r_srcup_din_END (13)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_r_srcup_dout_START (14)
#define SOC_ASP_CODEC_FS_CTRL7_fs_i2s2_rx_r_srcup_dout_END (16)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacl_mixer4_srcup_din_START (17)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacl_mixer4_srcup_din_END (18)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacl_mixer4_srcup_dout_START (19)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacl_mixer4_srcup_dout_END (20)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacr_mixer4_srcup_din_START (21)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacr_mixer4_srcup_din_END (22)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacr_mixer4_srcup_dout_START (23)
#define SOC_ASP_CODEC_FS_CTRL7_fs_dacr_mixer4_srcup_dout_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mic5_up_pga_gainoffset : 8;
        unsigned int mic6_up_pga_gainoffset : 8;
        unsigned int mic7_up_pga_gainoffset : 8;
        unsigned int mic8_up__pga_gainoffset : 8;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic5_up_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic5_up_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic6_up_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic6_up_pga_gainoffset_END (15)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic7_up_pga_gainoffset_START (16)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic7_up_pga_gainoffset_END (23)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic8_up__pga_gainoffset_START (24)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL5_mic8_up__pga_gainoffset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audiozoom_data0_din_sel : 3;
        unsigned int audiozoom_data1_din_sel : 3;
        unsigned int audiozoom_data2_din_sel : 3;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CODEC_CODEC_DIN_MUX2_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_audiozoom_data0_din_sel_START (0)
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_audiozoom_data0_din_sel_END (2)
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_audiozoom_data1_din_sel_START (3)
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_audiozoom_data1_din_sel_END (5)
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_audiozoom_data2_din_sel_START (6)
#define SOC_ASP_CODEC_CODEC_DIN_MUX2_audiozoom_data2_din_sel_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int f_alpha : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL0_f_alpha_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL0_f_alpha_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s_alpha : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL1_s_alpha_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL1_s_alpha_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mic_sens_offset : 16;
        unsigned int la_offset : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL2_mic_sens_offset_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL2_mic_sens_offset_END (15)
#define SOC_ASP_CODEC_NOISE_METER_CTRL2_la_offset_START (16)
#define SOC_ASP_CODEC_NOISE_METER_CTRL2_la_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lc_offset : 16;
        unsigned int lz_offset : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL3_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL3_lc_offset_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL3_lc_offset_END (15)
#define SOC_ASP_CODEC_NOISE_METER_CTRL3_lz_offset_START (16)
#define SOC_ASP_CODEC_NOISE_METER_CTRL3_lz_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int laf_offset : 16;
        unsigned int las_offset : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL4_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL4_laf_offset_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL4_laf_offset_END (15)
#define SOC_ASP_CODEC_NOISE_METER_CTRL4_las_offset_START (16)
#define SOC_ASP_CODEC_NOISE_METER_CTRL4_las_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int laf_max_offset : 16;
        unsigned int las_max_offset : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL5_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL5_laf_max_offset_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL5_laf_max_offset_END (15)
#define SOC_ASP_CODEC_NOISE_METER_CTRL5_las_max_offset_START (16)
#define SOC_ASP_CODEC_NOISE_METER_CTRL5_las_max_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int a_wt_gain : 10;
        unsigned int reserved_0: 2;
        unsigned int c_wt_gain : 10;
        unsigned int reserved_1: 10;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL6_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL6_a_wt_gain_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL6_a_wt_gain_END (9)
#define SOC_ASP_CODEC_NOISE_METER_CTRL6_c_wt_gain_START (12)
#define SOC_ASP_CODEC_NOISE_METER_CTRL6_c_wt_gain_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int z_wt_gain : 10;
        unsigned int reserved_0: 2;
        unsigned int ofl_incr : 6;
        unsigned int reserved_1: 2;
        unsigned int ofl_decr : 6;
        unsigned int reserved_2: 6;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL7_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_z_wt_gain_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_z_wt_gain_END (9)
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_ofl_incr_START (12)
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_ofl_incr_END (17)
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_ofl_decr_START (20)
#define SOC_ASP_CODEC_NOISE_METER_CTRL7_ofl_decr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_lvl_thr : 16;
        unsigned int ns_dur_thr : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL8_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL8_ns_lvl_thr_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL8_ns_lvl_thr_END (15)
#define SOC_ASP_CODEC_NOISE_METER_CTRL8_ns_dur_thr_START (16)
#define SOC_ASP_CODEC_NOISE_METER_CTRL8_ns_dur_thr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ofl_alpha : 20;
        unsigned int ofl_dur : 3;
        unsigned int reserved_0 : 1;
        unsigned int nsm_ofl_en : 1;
        unsigned int nsm_onl_en : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL9_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_ofl_alpha_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_ofl_alpha_END (19)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_ofl_dur_START (20)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_ofl_dur_END (22)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_nsm_ofl_en_START (24)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_nsm_ofl_en_END (24)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_nsm_onl_en_START (25)
#define SOC_ASP_CODEC_NOISE_METER_CTRL9_nsm_onl_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nsm_onl_intr_clr : 1;
        unsigned int nsm_ofl_intr_clr : 1;
        unsigned int reserved : 14;
        unsigned int ofl_laf_offset : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_CTRL10_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_nsm_onl_intr_clr_START (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_nsm_onl_intr_clr_END (0)
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_nsm_ofl_intr_clr_START (1)
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_nsm_ofl_intr_clr_END (1)
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_ofl_laf_offset_START (16)
#define SOC_ASP_CODEC_NOISE_METER_CTRL10_ofl_laf_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nm_ofl_sto_wr_addr : 11;
        unsigned int reserved_0 : 1;
        unsigned int nm_ofl_sto_rd_addr : 11;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_nm_ofl_sto_wr_addr_START (0)
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_nm_ofl_sto_wr_addr_END (10)
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_nm_ofl_sto_rd_addr_START (12)
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL0_nm_ofl_sto_rd_addr_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nm_ofl_wr_addr_init : 11;
        unsigned int reserved_0 : 1;
        unsigned int nm_ofl_rd_addr_init : 11;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_nm_ofl_wr_addr_init_START (0)
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_nm_ofl_wr_addr_init_END (10)
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_nm_ofl_rd_addr_init_START (12)
#define SOC_ASP_CODEC_NOISE_METER_OFL_ADDR_CTRL1_nm_ofl_rd_addr_init_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nm_ofl_sto_nos_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL0_nm_ofl_sto_nos_cnt_START (0)
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL0_nm_ofl_sto_nos_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nm_ofl_nos_cnt_init : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL1_nm_ofl_nos_cnt_init_START (0)
#define SOC_ASP_CODEC_NOISE_METER_OFL_NOS_CNT_CTRL1_nm_ofl_nos_cnt_init_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int nm_ofl_recov_pulse : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_OFL_RECOV_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_OFL_RECOV_CTRL_nm_ofl_recov_pulse_START (0)
#define SOC_ASP_CODEC_NOISE_METER_OFL_RECOV_CTRL_nm_ofl_recov_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int noise_meter_online_la_data : 16;
        unsigned int noise_meter_online_lc_data : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_noise_meter_online_la_data_START (0)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_noise_meter_online_la_data_END (15)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_noise_meter_online_lc_data_START (16)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA0_noise_meter_online_lc_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int noise_meter_online_lz_data : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA1_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA1_noise_meter_online_lz_data_START (0)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA1_noise_meter_online_lz_data_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int noise_meter_online_las_data : 16;
        unsigned int noise_meter_online_laf_data : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_noise_meter_online_las_data_START (0)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_noise_meter_online_las_data_END (15)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_noise_meter_online_laf_data_START (16)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA2_noise_meter_online_laf_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int noise_meter_online_lasmax_data : 16;
        unsigned int noise_meter_online_lafmax_data : 16;
    } reg;
} SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_UNION;
#endif
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_noise_meter_online_lasmax_data_START (0)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_noise_meter_online_lasmax_data_END (15)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_noise_meter_online_lafmax_data_START (16)
#define SOC_ASP_CODEC_NOISE_METER_ONLINE_DATA3_noise_meter_online_lafmax_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_spc : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ASP_CODEC_MEM_CTRL_SPC_UNION;
#endif
#define SOC_ASP_CODEC_MEM_CTRL_SPC_mem_ctrl_spc_START (0)
#define SOC_ASP_CODEC_MEM_CTRL_SPC_mem_ctrl_spc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_3_dn_srcup_clken : 1;
        unsigned int audio_3_dn_srcup_clken : 1;
        unsigned int codec_3_dn_pga_clken : 1;
        unsigned int audio_3_dn_pga_clken : 1;
        unsigned int codec_3_dn_afifo_clken : 1;
        unsigned int audio_3_dn_afifo_clken : 1;
        unsigned int spa7_up_afifo_clken : 1;
        unsigned int spa8_up_afifo_clken : 1;
        unsigned int mixer4_spa3_clken : 1;
        unsigned int mixer2_ultr3_clken : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_CODEC_CODEC_CLK_EN5_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_CLK_EN5_codec_3_dn_srcup_clken_START (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_codec_3_dn_srcup_clken_END (0)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_audio_3_dn_srcup_clken_START (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_audio_3_dn_srcup_clken_END (1)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_codec_3_dn_pga_clken_START (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_codec_3_dn_pga_clken_END (2)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_audio_3_dn_pga_clken_START (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_audio_3_dn_pga_clken_END (3)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_codec_3_dn_afifo_clken_START (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_codec_3_dn_afifo_clken_END (4)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_audio_3_dn_afifo_clken_START (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_audio_3_dn_afifo_clken_END (5)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_spa7_up_afifo_clken_START (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_spa7_up_afifo_clken_END (6)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_spa8_up_afifo_clken_START (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_spa8_up_afifo_clken_END (7)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_mixer4_spa3_clken_START (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_mixer4_spa3_clken_END (8)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_mixer2_ultr3_clken_START (9)
#define SOC_ASP_CODEC_CODEC_CLK_EN5_mixer2_ultr3_clken_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_codec_3_dn_srcup_din : 2;
        unsigned int fs_codec_3_dn_srcup_dout : 3;
        unsigned int fs_audio_3_dn_srcup_din : 2;
        unsigned int fs_audio_3_dn_srcup_dout : 3;
        unsigned int fs_codec_3_dn_pga : 2;
        unsigned int fs_audio_3_dn_pga : 2;
        unsigned int fs_codec_3_dn_afifo : 2;
        unsigned int fs_audio_3_dn_afifo : 2;
        unsigned int fs_spa3_mixer4 : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_ASP_CODEC_FS_CTRL8_UNION;
#endif
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_srcup_din_START (0)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_srcup_din_END (1)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_srcup_dout_START (2)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_srcup_dout_END (4)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_srcup_din_START (5)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_srcup_din_END (6)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_srcup_dout_START (7)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_srcup_dout_END (9)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_pga_START (10)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_pga_END (11)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_pga_START (12)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_pga_END (13)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_afifo_START (14)
#define SOC_ASP_CODEC_FS_CTRL8_fs_codec_3_dn_afifo_END (15)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_afifo_START (16)
#define SOC_ASP_CODEC_FS_CTRL8_fs_audio_3_dn_afifo_END (17)
#define SOC_ASP_CODEC_FS_CTRL8_fs_spa3_mixer4_START (18)
#define SOC_ASP_CODEC_FS_CTRL8_fs_spa3_mixer4_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int audio_3_dn_fifo_aempty_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int audio_3_dn_fifo_afull_th : 7;
        unsigned int audio_3_dn_fifo_clr : 1;
        unsigned int codec_3_dn_fifo_aempty_th : 7;
        unsigned int reserved_1 : 1;
        unsigned int codec_3_dn_fifo_afull_th : 7;
        unsigned int codec_3_dn_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_audio_3_dn_fifo_aempty_th_START (0)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_audio_3_dn_fifo_aempty_th_END (6)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_audio_3_dn_fifo_afull_th_START (8)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_audio_3_dn_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_audio_3_dn_fifo_clr_START (15)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_audio_3_dn_fifo_clr_END (15)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_codec_3_dn_fifo_aempty_th_START (16)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_codec_3_dn_fifo_aempty_th_END (22)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_codec_3_dn_fifo_afull_th_START (24)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_codec_3_dn_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_codec_3_dn_fifo_clr_START (31)
#define SOC_ASP_CODEC_CODEC_3_DN_AFIFO_CTRL_codec_3_dn_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int spa_7_up_fifo_aempty_th : 5;
        unsigned int spa_7_up_fifo_afull_th : 5;
        unsigned int spa_7_up_fifo_clr : 1;
        unsigned int reserved_1 : 5;
        unsigned int spa_8_up_fifo_aempty_th : 5;
        unsigned int spa_8_up_fifo_afull_th : 5;
        unsigned int spa_8_up_fifo_clr : 1;
    } reg;
} SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_7_up_fifo_aempty_th_START (5)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_7_up_fifo_aempty_th_END (9)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_7_up_fifo_afull_th_START (10)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_7_up_fifo_afull_th_END (14)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_7_up_fifo_clr_START (15)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_7_up_fifo_clr_END (15)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_8_up_fifo_aempty_th_START (21)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_8_up_fifo_aempty_th_END (25)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_8_up_fifo_afull_th_START (26)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_8_up_fifo_afull_th_END (30)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_8_up_fifo_clr_START (31)
#define SOC_ASP_CODEC_SPA78_UP_AFIFO_CTRL_spa_8_up_fifo_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int codec_3_dn_pga_linear_sel : 1;
        unsigned int codec_3_dn_pga_zero_num : 5;
        unsigned int codec_3_dn_pga_thre_id : 2;
        unsigned int codec_3_dn_pga_noise_en : 1;
        unsigned int codec_3_dn_pga_bypass : 1;
        unsigned int codec_3_dn_pga_fade_out : 5;
        unsigned int codec_3_dn_pga_fade_in : 5;
        unsigned int codec_3_dn_pga_cfg : 3;
        unsigned int codec_3_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_CODEC_3_DN_PGA_CTRL_codec_3_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int audio_3_dn_pga_linear_sel : 1;
        unsigned int audio_3_dn_pga_zero_num : 5;
        unsigned int audio_3_dn_pga_thre_id : 2;
        unsigned int audio_3_dn_pga_noise_en : 1;
        unsigned int audio_3_dn_pga_bypass : 1;
        unsigned int audio_3_dn_pga_fade_out : 5;
        unsigned int audio_3_dn_pga_fade_in : 5;
        unsigned int audio_3_dn_pga_cfg : 3;
        unsigned int audio_3_dn_pga_gain : 8;
    } reg;
} SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_linear_sel_START (1)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_linear_sel_END (1)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_zero_num_START (2)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_zero_num_END (6)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_thre_id_START (7)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_thre_id_END (8)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_noise_en_START (9)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_noise_en_END (9)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_bypass_START (10)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_bypass_END (10)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_fade_out_START (11)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_fade_out_END (15)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_fade_in_START (16)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_fade_in_END (20)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_cfg_START (21)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_cfg_END (23)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_gain_START (24)
#define SOC_ASP_CODEC_AUDIO_3_DN_PGA_CTRL_audio_3_dn_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_3_dn_srcup_src_mode : 3;
        unsigned int codec_3_dn_srcup_fifo_clr : 1;
        unsigned int audio_3_srcup_src_mode : 3;
        unsigned int audio_3_dn_srcup_fifo_clr : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_SRCUP_CTRL2_UNION;
#endif
#define SOC_ASP_CODEC_SRCUP_CTRL2_codec_3_dn_srcup_src_mode_START (0)
#define SOC_ASP_CODEC_SRCUP_CTRL2_codec_3_dn_srcup_src_mode_END (2)
#define SOC_ASP_CODEC_SRCUP_CTRL2_codec_3_dn_srcup_fifo_clr_START (3)
#define SOC_ASP_CODEC_SRCUP_CTRL2_codec_3_dn_srcup_fifo_clr_END (3)
#define SOC_ASP_CODEC_SRCUP_CTRL2_audio_3_srcup_src_mode_START (4)
#define SOC_ASP_CODEC_SRCUP_CTRL2_audio_3_srcup_src_mode_END (6)
#define SOC_ASP_CODEC_SRCUP_CTRL2_audio_3_dn_srcup_fifo_clr_START (7)
#define SOC_ASP_CODEC_SRCUP_CTRL2_audio_3_dn_srcup_fifo_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int spa3_mixer4_gain1 : 2;
        unsigned int spa3_mixer4_gain2 : 2;
        unsigned int spa3_mixer4_gain3 : 2;
        unsigned int spa3_mixer4_gain4 : 2;
        unsigned int spa3_mixer4_in1_mute : 1;
        unsigned int spa3_mixer4_in2_mute : 1;
        unsigned int spa3_mixer4_in3_mute : 1;
        unsigned int spa3_mixer4_in4_mute : 1;
        unsigned int spa3_mixer4_in1_id : 2;
        unsigned int spa3_mixer4_in2_id : 2;
        unsigned int spa3_mixer4_in3_id : 2;
        unsigned int spa3_mixer4_in4_id : 2;
    } reg;
} SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_UNION;
#endif
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain1_START (12)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain1_END (13)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain2_START (14)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain2_END (15)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain3_START (16)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain3_END (17)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain4_START (18)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_gain4_END (19)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_mute_START (20)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_mute_END (20)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_mute_START (21)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_mute_END (21)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_mute_START (22)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_mute_END (22)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_mute_START (23)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_mute_END (23)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_id_START (24)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in1_id_END (25)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_id_START (26)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in2_id_END (27)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_id_START (28)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in3_id_END (29)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_id_START (30)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL0_spa3_mixer4_in4_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 16;
        unsigned int spa3_mixer4_zero_num : 5;
        unsigned int spa3_mixer4_fade_out : 5;
        unsigned int spa3_mixer4_fade_in : 5;
        unsigned int spa3_mixer4_fade_en : 1;
    } reg;
} SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_UNION;
#endif
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_zero_num_START (16)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_zero_num_END (20)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_out_START (21)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_out_END (25)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_in_START (26)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_in_END (30)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_en_START (31)
#define SOC_ASP_CODEC_SPA3_MIXER4_CTRL1_spa3_mixer4_fade_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 6;
        unsigned int ultr3_mixer2_zero_num : 5;
        unsigned int ultr3_mixer2_fade_out : 5;
        unsigned int ultr3_mixer2_fade_in : 5;
        unsigned int ultr3_mixer2_fade_en : 1;
        unsigned int ultr3_mixer2_gain1 : 2;
        unsigned int ultr3_mixer2_gain2 : 2;
        unsigned int ultr3_mixer2_in1_mute : 1;
        unsigned int ultr3_mixer2_in2_mute : 1;
        unsigned int ultr3_mixer2_in1_id : 2;
        unsigned int ultr3_mixer2_in2_id : 2;
    } reg;
} SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_zero_num_START (6)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_zero_num_END (10)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_fade_out_START (11)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_fade_out_END (15)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_fade_in_START (16)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_fade_in_END (20)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_fade_en_START (21)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_fade_en_END (21)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_gain1_START (22)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_gain1_END (23)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_gain2_START (24)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_gain2_END (25)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in1_mute_START (26)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in1_mute_END (26)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in2_mute_START (27)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in2_mute_END (27)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in1_id_START (28)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in1_id_END (29)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in2_id_START (30)
#define SOC_ASP_CODEC_ULTR3_MIXER2_CTRL_ultr3_mixer2_in2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int codec_3_dn_pga_gainoffset : 8;
        unsigned int audio_3_dn_pga_gainoffset : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_UNION;
#endif
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_codec_3_dn_pga_gainoffset_START (0)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_codec_3_dn_pga_gainoffset_END (7)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_audio_3_dn_pga_gainoffset_START (8)
#define SOC_ASP_CODEC_PGA_GAINOFFSET_CTRL6_audio_3_dn_pga_gainoffset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spa1_din_sel : 1;
        unsigned int spa2_din_sel : 1;
        unsigned int spa3_din_sel : 1;
        unsigned int spa4_din_sel : 1;
        unsigned int bm_i2s1_tdm128_slot1_din_sel : 1;
        unsigned int bm_i2s1_tdm128_slot0_din_sel : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_UNION;
#endif
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa1_din_sel_START (0)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa1_din_sel_END (0)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa2_din_sel_START (1)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa2_din_sel_END (1)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa3_din_sel_START (2)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa3_din_sel_END (2)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa4_din_sel_START (3)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_spa4_din_sel_END (3)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_bm_i2s1_tdm128_slot1_din_sel_START (4)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_bm_i2s1_tdm128_slot1_din_sel_END (4)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_bm_i2s1_tdm128_slot0_din_sel_START (5)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL6_bm_i2s1_tdm128_slot0_din_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s1_tdm256_3iv_din_sel : 3;
        unsigned int i2s1_tdm256_2iv_din_sel : 3;
        unsigned int i2s1_tdm256_1iv_din_sel : 3;
        unsigned int i2s1_tdm256_0iv_din_sel : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_UNION;
#endif
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_3iv_din_sel_START (0)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_3iv_din_sel_END (2)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_2iv_din_sel_START (3)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_2iv_din_sel_END (5)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_1iv_din_sel_START (6)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_1iv_din_sel_END (8)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_0iv_din_sel_START (9)
#define SOC_ASP_CODEC_SPA_AFIFO_UP_DIN_CTRL7_i2s1_tdm256_0iv_din_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2s3_rx_clk_sel : 31;
        unsigned int i2s3_tx_clk_sel : 30;
        unsigned int i2s3_codec_io_wordlength : 28;
        unsigned int i2s3_codec_data_format : 27;
        unsigned int i2s3_chnnl_mode : 26;
        unsigned int i2s3_lrclk_mode : 25;
        unsigned int i2s3_frame_mode : 24;
        unsigned int i2s3_func_mode : 21;
        unsigned int i2s3_direct_loop : 19;
        unsigned int i2s3_mst_slv : 18;
        unsigned int i2s3_if_rx_ena : 17;
        unsigned int i2s3_if_tx_ena : 16;
        unsigned int fs_i2s3 : 13;
        unsigned int s3_fifo_clr : 12;
        unsigned int i2s3_pcm_clken : 11;
        unsigned int i2s3_lp_en : 10;
        unsigned int i2s3_hardware_lp_ctrl_sel : 8;
        unsigned int i2s3_lp_ctrl_clk_en : 7;
        unsigned int reserved;
    } reg;
} SOC_ASP_CODEC_I2S3_PCM_CTRL_UNION;
#endif
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lp_ctrl_clk_en_START (7)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lp_ctrl_clk_en_END (7)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_hardware_lp_ctrl_sel_START (8)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_hardware_lp_ctrl_sel_END (9)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lp_en_START (10)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lp_en_END (10)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_pcm_clken_START (11)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_pcm_clken_END (11)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_s3_fifo_clr_START (12)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_s3_fifo_clr_END (12)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_fs_i2s3_START (13)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_fs_i2s3_END (15)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_tx_ena_START (16)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_tx_ena_END (16)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_rx_ena_START (17)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_if_rx_ena_END (17)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_mst_slv_START (18)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_mst_slv_END (18)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_direct_loop_START (19)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_direct_loop_END (20)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_func_mode_START (21)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_func_mode_END (23)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_frame_mode_START (24)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_frame_mode_END (24)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lrclk_mode_START (25)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_lrclk_mode_END (25)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_chnnl_mode_START (26)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_chnnl_mode_END (26)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_data_format_START (27)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_data_format_END (27)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_io_wordlength_START (28)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_codec_io_wordlength_END (29)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_tx_clk_sel_START (30)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_tx_clk_sel_END (30)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_rx_clk_sel_START (31)
#define SOC_ASP_CODEC_I2S3_PCM_CTRL_i2s3_rx_clk_sel_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
