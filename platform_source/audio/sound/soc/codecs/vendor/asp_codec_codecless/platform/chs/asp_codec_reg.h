/*
 * asp_codec_reg.h -- codec driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ASP_CODEC_REG_H__
#define __ASP_CODEC_REG_H__

/*
 * Due to the limitation of ALSA that the register address is of type int,
 * while the actual base address of the codec registers is of type unsigned int,
 * it is necessary to clear the sign bit of the base address.
 */
#define clear_31_bit(x)     ((x) & (0x7FFFFFFF))

#define PAGE_SOCCODEC         clear_31_bit(0xFD090000)
#define PAGE_ASPCFG           clear_31_bit(0xFD0BE000)
#define PAGE_AXI2TDM          clear_31_bit(0xFD0BD000)
#define PAGE_MAD              clear_31_bit(0xFDA80000)
#define PAGE_VIRCODEC         0x8000

#define PAGE_HAPTIC0        (PAGE_SOCCODEC + 0x6000)
#define HAP0_LRA_BYPASS_CFG         (PAGE_HAPTIC0 + 0x0)
#define HAP0_LRA_CLK_RST_CFG        (PAGE_HAPTIC0 + 0x4)
#define HAP0_LRA_LP_CFG0        (PAGE_HAPTIC0 + 0x14)
#define CFG_AUDIO_HAPTIC_LP_I2S_OFFSET           0
#define CFG_AUDIO_HAPTIC_LP_I2S_OFFSET_LEN       1
#define CFG_AUDIO_HAPTIC_LP_PA_OFFSET            1
#define CFG_AUDIO_HAPTIC_LP_PA_OFFSET_LEN        1
#define HAP0_LRA_CFG0        (PAGE_HAPTIC0 + 0xa0)
#define CFG_LRA_MIXER_F0_DRV_0_OFFSET            26
#define CFG_LRA_MIXER_F0_DRV_0_OFFSET_LEN        1
#define CFG_LRA_MIXER_F0_DRV_1_OFFSET            27
#define CFG_LRA_MIXER_F0_DRV_1_OFFSET_LEN        1

#define PAGE_HAPTIC1      (PAGE_SOCCODEC + 0x7000)
#define HAP1_LRA_BYPASS_CFG         (PAGE_HAPTIC1 + 0x0)
#define HAP1_LRA_CLK_RST_CFG        (PAGE_HAPTIC1 + 0x4)
#define HAP1_LRA_LP_CFG0        (PAGE_HAPTIC1 + 0x14)
#define HAP1_LRA_CFG0        (PAGE_HAPTIC1 + 0xa0)

#define PAGE_SOCSMARTPA1      (PAGE_SOCCODEC + 0x2000)
#define IV_DATA_SEL1        (PAGE_SOCSMARTPA1 + 0x0)
#define SPA1_FIR_BYPASS_EN_OFFSET                30
#define SPA1_FIR_BYPASS_EN_LEN                   1
#define SPA1_SPA_I_DATA_SEL_OFFSET               22
#define SPA1_SPA_I_DATA_SEL_OFFSET_LEN           4
#define SPA1_SPA_V_DATA_SEL_OFFSET               18
#define SPA1_SPA_V_DATA_SEL_OFFSET_LEN           4
#define SPA1_BYPASS_EN_OFFSET                    0
#define SPA1_BYPASS_EN_LEN                       18
#define CLK_RST_CFG1          (PAGE_SOCSMARTPA1 + 0x4)
#define SPA1_SMARTPA_PROTECT_CLK_RST_EN_OFFSET   15
#define SPA1_CLK_RST_CFG_CLK_RST_EN_LEN          17
#define SPA1_PARAMS_PASSTHROUGH_EN_OFFSET        12
#define SPA1_PARAMS_PASSTHROUGH_EN_LEN           1
#define SPA1_BCN_LTM_FIR_CLK_RST_EN_OFFSET       1
#define SPA1_BCN_LTM_FIR_CLK_RST_EN_LEN          3
#define SPA1_PRE_CFG0         (PAGE_SOCSMARTPA1 + 0x8)
#define SPA1_CFG_PRE_PGA_BYPASS_OFFSET           4
#define SPA1_CFG_PRE_PGA_BYPASS_LEN              1
#define SPA1_CFG_PRE_HPS_BYPASS_OFFSET           3
#define SPA1_CFG_PRE_HPS_BYPASS_LEN              1
#define SPA1_CFG_PRE_LPS_BYPASS_OFFSET           2
#define SPA1_CFG_PRE_LPS_BYPASS_LEN              1
#define SPA1_CFG_PRE_PILOTTONE_CLKEN_OFFSET      0
#define SPA1_CFG_PRE_PILOTTONE_CLKEN_LEN         1
#define SPA1_CG_EN_CFG       (PAGE_SOCSMARTPA1 + 0x40)
#define SPA1_PRE_PROCESS_CG_EN_OFFSET            0
#define SPA1_CFG_EN_LEN                          18

#define PAGE_SOCSMARTPA2      (PAGE_SOCCODEC + 0x3000)
#define IV_DATA_SEL2        (PAGE_SOCSMARTPA2 + 0x0)
#define SPA2_FIR_BYPASS_EN_OFFSET                30
#define SPA2_FIR_BYPASS_EN_LEN                   1
#define SPA2_SPA_I_DATA_SEL_OFFSET               22
#define SPA2_SPA_I_DATA_SEL_OFFSET_LEN           4
#define SPA2_SPA_V_DATA_SEL_OFFSET               18
#define SPA2_SPA_V_DATA_SEL_OFFSET_LEN           4
#define SPA2_BYPASS_EN_OFFSET                    0
#define SPA2_BYPASS_EN_LEN                       18
#define CLK_RST_CFG2          (PAGE_SOCSMARTPA2 + 0x4)
#define SPA2_SMARTPA_PROTECT_CLK_RST_EN_OFFSET   15
#define SPA2_CLK_RST_CFG_CLK_RST_EN_LEN          17
#define SPA2_PARAMS_PASSTHROUGH_EN_OFFSET        12
#define SPA2_PARAMS_PASSTHROUGH_EN_LEN           1
#define SPA2_BCN_LTM_FIR_CLK_RST_EN_OFFSET       1
#define SPA2_BCN_LTM_FIR_CLK_RST_EN_LEN          3
#define SPA2_PRE_CFG0         (PAGE_SOCSMARTPA2 + 0x8)
#define SPA2_CFG_PRE_PGA_BYPASS_OFFSET           4
#define SPA2_CFG_PRE_PGA_BYPASS_LEN              1
#define SPA2_CFG_PRE_HPS_BYPASS_OFFSET           3
#define SPA2_CFG_PRE_HPS_BYPASS_LEN              1
#define SPA2_CFG_PRE_LPS_BYPASS_OFFSET           2
#define SPA2_CFG_PRE_LPS_BYPASS_LEN              1
#define SPA2_CFG_PRE_PILOTTONE_CLKEN_OFFSET      0
#define SPA2_CFG_PRE_PILOTTONE_CLKEN_LEN         1
#define SPA2_CG_EN_CFG       (PAGE_SOCSMARTPA2 + 0x40)
#define SPA2_PRE_PROCESS_CG_EN_OFFSET            0
#define SPA2_CFG_EN_LEN                          18

#define PAGE_SOCSMARTPA3      (PAGE_SOCCODEC + 0x4000)
#define IV_DATA_SEL3        (PAGE_SOCSMARTPA3 + 0x0)
#define SPA3_FIR_BYPASS_EN_OFFSET                30
#define SPA3_FIR_BYPASS_EN_LEN                   1
#define SPA3_SPA_I_DATA_SEL_OFFSET               22
#define SPA3_SPA_I_DATA_SEL_OFFSET_LEN           4
#define SPA3_SPA_V_DATA_SEL_OFFSET               18
#define SPA3_SPA_V_DATA_SEL_OFFSET_LEN           4
#define SPA3_BYPASS_EN_OFFSET                    0
#define SPA3_BYPASS_EN_LEN                       18
#define CLK_RST_CFG3          (PAGE_SOCSMARTPA3 + 0x4)
#define SPA3_SMARTPA_PROTECT_CLK_RST_EN_OFFSET   15
#define SPA3_CLK_RST_CFG_CLK_RST_EN_LEN          17
#define SPA3_PARAMS_PASSTHROUGH_EN_OFFSET        12
#define SPA3_PARAMS_PASSTHROUGH_EN_LEN           1
#define SPA3_BCN_LTM_FIR_CLK_RST_EN_OFFSET       1
#define SPA3_BCN_LTM_FIR_CLK_RST_EN_LEN          3
#define SPA3_PRE_CFG0         (PAGE_SOCSMARTPA3 + 0x8)
#define SPA3_CFG_PRE_PGA_BYPASS_OFFSET           4
#define SPA3_CFG_PRE_PGA_BYPASS_LEN              1
#define SPA3_CFG_PRE_HPS_BYPASS_OFFSET           3
#define SPA3_CFG_PRE_HPS_BYPASS_LEN              1
#define SPA3_CFG_PRE_LPS_BYPASS_OFFSET           2
#define SPA3_CFG_PRE_LPS_BYPASS_LEN              1
#define SPA3_CFG_PRE_PILOTTONE_CLKEN_OFFSET      0
#define SPA3_CFG_PRE_PILOTTONE_CLKEN_LEN         1
#define SPA3_CG_EN_CFG       (PAGE_SOCSMARTPA3 + 0x40)
#define SPA3_PRE_PROCESS_CG_EN_OFFSET            0
#define SPA3_CFG_EN_LEN                          18

#define PAGE_SOCSMARTPA4      (PAGE_SOCCODEC + 0x5000)
#define IV_DATA_SEL4        (PAGE_SOCSMARTPA4 + 0x0)
#define SPA4_FIR_BYPASS_EN_OFFSET                30
#define SPA4_FIR_BYPASS_EN_LEN                   1
#define SPA4_SPA_I_DATA_SEL_OFFSET               22
#define SPA4_SPA_I_DATA_SEL_OFFSET_LEN           4
#define SPA4_SPA_V_DATA_SEL_OFFSET               18
#define SPA4_SPA_V_DATA_SEL_OFFSET_LEN           4
#define SPA4_BYPASS_EN_OFFSET                    0
#define SPA4_BYPASS_EN_LEN                       18
#define CLK_RST_CFG4          (PAGE_SOCSMARTPA4 + 0x4)
#define SPA4_SMARTPA_PROTECT_CLK_RST_EN_OFFSET   15
#define SPA4_CLK_RST_CFG_CLK_RST_EN_LEN          17
#define SPA4_PARAMS_PASSTHROUGH_EN_OFFSET        12
#define SPA4_PARAMS_PASSTHROUGH_EN_LEN           1
#define SPA4_BCN_LTM_FIR_CLK_RST_EN_OFFSET       1
#define SPA4_BCN_LTM_FIR_CLK_RST_EN_LEN          3
#define SPA4_PRE_CFG0         (PAGE_SOCSMARTPA4 + 0x8)
#define SPA4_CFG_PRE_PGA_BYPASS_OFFSET           4
#define SPA4_CFG_PRE_PGA_BYPASS_LEN              1
#define SPA4_CFG_PRE_HPS_BYPASS_OFFSET           3
#define SPA4_CFG_PRE_HPS_BYPASS_LEN              1
#define SPA4_CFG_PRE_LPS_BYPASS_OFFSET           2
#define SPA4_CFG_PRE_LPS_BYPASS_LEN              1
#define SPA4_CFG_PRE_PILOTTONE_CLKEN_OFFSET      0
#define SPA4_CFG_PRE_PILOTTONE_CLKEN_LEN         1
#define SPA4_CG_EN_CFG       (PAGE_SOCSMARTPA4 + 0x40)
#define SPA4_PRE_PROCESS_CG_EN_OFFSET            0
#define SPA4_CFG_EN_LEN                          18

#define SOCCODEC_END_OFFSET   0x27C
#define VIRCODEC_END_OFFSET   (VIR_REG_CNT - 1)
#define ASPCFG_END_OFFSET     0xFFF
#define AXI2TDM_END           0x94
#define MAD_END               0xFFF
#define SOCSMARTPA_END_OFFSET 0x40
#define MAD_CFG_BASE          (0xFDA80000)
#define HAPTIC_END_OFFSET     0xA4

#include "asp_codec_axi2tdm_reg.h"
#include "asp_codec_mad_regs.h"

#define VERSION_REG              (PAGE_SOCCODEC + 0x0)
#define VERSION_OFFSET                            0
#define VERSION_LEN                               32

#define CODEC_CLK_EN0_REG        (PAGE_SOCCODEC + 0x4)
#define HAPTIC0_DN_AFIFO_CLKEN_OFFSET             7
#define HAPTIC0_DN_AFIFO_CLKEN_LEN                1
#define HAPTIC1_DN_AFIFO_CLKEN_OFFSET             8
#define HAPTIC1_DN_AFIFO_CLKEN_LEN                1
#define HAPTIC0_UP_AFIFO_CLKEN_OFFSET             9
#define HAPTIC0_UP_AFIFO_CLKEN_LEN                1
#define HAPTIC1_UP_AFIFO_CLKEN_OFFSET             10
#define HAPTIC1_UP_AFIFO_CLKEN_LEN                1
#define HAPTIC2_UP_AFIFO_CLKEN_OFFSET             11
#define HAPTIC2_UP_AFIFO_CLKEN_LEN                1
#define HAPTIC3_UP_AFIFO_CLKEN_OFFSET             12
#define HAPTIC3_UP_AFIFO_CLKEN_LEN                1
#define SPA4567_UP_AFIFO_CLKEN_OFFSET             13
#define SPA4567_UP_AFIFO_CLKEN_LEN                1
#define SPA0123_UP_AFIFO_CLKEN_OFFSET             14
#define SPA0123_UP_AFIFO_CLKEN_LEN                1
#define AUDIO_LR_UP_AFIFO_CLKEN_OFFSET            15
#define AUDIO_LR_UP_AFIFO_CLKEN_LEN               1
#define ULTR_UP_AFIFO_CLKEN_OFFSET                16
#define ULTR_UP_AFIFO_CLKEN_LEN                   1
#define ULTR_DN_AFIFO_CLKEN_OFFSET                17
#define ULTR_DN_AFIFO_CLKEN_LEN                   1
#define VOICE_LR_UP_AFIFO_CLKEN_OFFSET            18
#define VOICE_LR_UP_AFIFO_CLKEN_LEN               1
#define MIC23_UP_AFIFO_CLKEN_OFFSET               19
#define MIC23_UP_AFIFO_CLKEN_LEN                  1
#define MIC45_UP_AFIFO_CLKEN_OFFSET               20
#define MIC45_UP_AFIFO_CLKEN_LEN                  1
#define MIC67_UP_AFIFO_CLKEN_OFFSET               21
#define MIC67_UP_AFIFO_CLKEN_LEN                  1
#define CODEC_0123_DN_AFIFO_CLKEN_OFFSET          22
#define CODEC_0123_DN_AFIFO_CLKEN_LEN             1
#define AUDIO_0123_DN_AFIFO_CLKEN_OFFSET          23
#define AUDIO_0123_DN_AFIFO_CLKEN_LEN             1
#define BT_LR_DN_AFIFO_CLKEN_OFFSET               24
#define BT_LR_DN_AFIFO_CLKEN_LEN                  1
#define SPA_TEST_AFIFO_CLKEN_OFFSET               25
#define SPA_TEST_AFIFO_CLKEN_LEN                  1
#define I2S1_PCM_CLKEN_OFFSET                     26    /* store:I2S1_PCM_CLKEN, CHS:I2S0_PCM_CLKEN */
#define I2S1_PCM_CLKEN_LEN                        1
#define I2S0_TDM128_CLKEN_OFFSET                  27
#define I2S0_TDM128_CLKEN_LEN                     1
#define I2S0_TDM256_CLKEN_OFFSET                  28
#define I2S0_TDM256_CLKEN_LEN                     1
#define I2S2_PCM_CLKEN_OFFSET                     29    /* store:I2S2_PCM_CLKEN, CHS:I2S1_PCM_CLKEN */
#define I2S2_PCM_CLKEN_LEN                        1
#define I2S1_TX_MIXER2_CLKEN_OFFSET               30
#define I2S1_TX_MIXER2_CLKEN_LEN                  1
#define SPA_PROTECT_4WAY_CLK_EN_OFFSET            31
#define SPA_PROTECT_4WAY_CLK_EN_LEN               1

#define CODEC_CLK_EN1_REG        (PAGE_SOCCODEC + 0x8)
#define AUDIO_L_UP_PGA_CLKEN_OFFSET               0
#define AUDIO_L_UP_PGA_CLKEN_LEN                  1
#define AUDIO_R_UP_PGA_CLKEN_OFFSET               1
#define AUDIO_R_UP_PGA_CLKEN_LEN                  1
#define VOICE_L_UP_PGA_CLKEN_OFFSET               2
#define VOICE_L_UP_PGA_CLKEN_LEN                  1
#define VOICE_R_UP_PGA_CLKEN_OFFSET               3
#define VOICE_R_UP_PGA_CLKEN_LEN                  1
#define MIC3_UP_PGA_CLKEN_OFFSET                  4    /* store:MIC3_UP_PGA, CHS:MIC2_UP_PGA */
#define MIC3_UP_PGA_CLKEN_LEN                     1
#define MIC4_UP_PGA_CLKEN_OFFSET                  5    /* store:MIC4_UP_PGA, CHS:MIC3_UP_PGA */
#define MIC4_UP_PGA_CLKEN_LEN                     1
#define MIC5_UP_PGA_CLKEN_OFFSET                  6    /* store:MIC5_UP_PGA, CHS:MIC4_UP_PGA */
#define MIC5_UP_PGA_CLKEN_LEN                     1
#define MIC6_UP_PGA_CLKEN_OFFSET                  7    /* store:MIC6_UP_PGA, CHS:MIC5_UP_PGA */
#define MIC6_UP_PGA_CLKEN_LEN                     1
#define MIC7_UP_PGA_CLKEN_OFFSET                  8    /* store:MIC7_UP_PGA, CHS:MIC6_UP_PGA */
#define MIC7_UP_PGA_CLKEN_LEN                     1
#define MIC8_UP_PGA_CLKEN_OFFSET                  9    /* store:MIC8_UP_PGA, CHS:MIC7_UP_PGA */
#define MIC8_UP_PGA_CLKEN_LEN                     1
#define CODEC_0_DN_PGA_CLKEN_OFFSET               10
#define CODEC_0_DN_PGA_CLKEN_LEN                  1
#define CODEC_1_DN_PGA_CLKEN_OFFSET               11
#define CODEC_1_DN_PGA_CLKEN_LEN                  1
#define CODEC_2_DN_PGA_CLKEN_OFFSET               12
#define CODEC_2_DN_PGA_CLKEN_LEN                  1
#define AUDIO_0_DN_PGA_CLKEN_OFFSET               13
#define AUDIO_0_DN_PGA_CLKEN_LEN                  1
#define AUDIO_1_DN_PGA_CLKEN_OFFSET               14
#define AUDIO_1_DN_PGA_CLKEN_LEN                  1
#define AUDIO_2_DN_PGA_CLKEN_OFFSET               15
#define AUDIO_2_DN_PGA_CLKEN_LEN                  1
#define I2S1_RX_L_PGA_CLKEN_OFFSET                18
#define I2S1_RX_L_PGA_CLKEN_LEN                   1
#define I2S1_RX_R_PGA_CLKEN_OFFSET                19
#define I2S1_RX_R_PGA_CLKEN_LEN                   1
#define AUDIO_L_UP_SRCDN_CLKEN_OFFSET             20
#define AUDIO_L_UP_SRCDN_CLKEN_LEN                1
#define AUDIO_R_UP_SRCDN_CLKEN_OFFSET             21
#define AUDIO_R_UP_SRCDN_CLKEN_LEN                1
#define VOICE_L_UP_SRCDN_CLKEN_OFFSET             22
#define VOICE_L_UP_SRCDN_CLKEN_LEN                1
#define VOICE_R_UP_SRCDN_CLKEN_OFFSET             23
#define VOICE_R_UP_SRCDN_CLKEN_LEN                1
#define MIC3_UP_SRCDN_CLKEN_OFFSET                24    /* store:MIC3_UP_SRCDN, CHS:MIC2_UP_SRCDN */
#define MIC3_UP_SRCDN_CLKEN_LEN                   1
#define MIC4_UP_SRCDN_CLKEN_OFFSET                25    /* store:MIC4_UP_SRCDN, CHS:MIC3_UP_SRCDN */
#define MIC4_UP_SRCDN_CLKEN_LEN                   1
#define MIC5_UP_SRCDN_CLKEN_OFFSET                26    /* store:MIC5_UP_SRCDN, CHS:MIC4_UP_SRCDN */
#define MIC5_UP_SRCDN_CLKEN_LEN                   1
#define MIC6_UP_SRCDN_CLKEN_OFFSET                27    /* store:MIC6_UP_SRCDN, CHS:MIC5_UP_SRCDN */
#define MIC6_UP_SRCDN_CLKEN_LEN                   1
#define MIC7_UP_SRCDN_CLKEN_OFFSET                28    /* store:MIC7_UP_SRCDN, CHS:MIC6_UP_SRCDN */
#define MIC7_UP_SRCDN_CLKEN_LEN                   1
#define MIC8_UP_SRCDN_CLKEN_OFFSET                29    /* store:MIC8_UP_SRCDN, CHS:MIC7_UP_SRCDN */
#define MIC8_UP_SRCDN_CLKEN_LEN                   1
#define ULTR_DN_PGA_CLKEN_OFFSET                  30
#define ULTR_DN_PGA_CLKEN_LEN                     1

#define CODEC_CLK_EN2_REG        (PAGE_SOCCODEC + 0xC)
#define I2S1_TX_L_SRCDN_CLKEN_OFFSET              0
#define I2S1_TX_L_SRCDN_CLKEN_LEN                 1
#define I2S1_TX_R_SRCDN_CLKEN_OFFSET              1
#define I2S1_TX_R_SRCDN_CLKEN_LEN                 1
#define I2S1_RX_L_SRCDN_CLKEN_OFFSET              2
#define I2S1_RX_L_SRCDN_CLKEN_LEN                 1
#define I2S1_RX_R_SRCDN_CLKEN_OFFSET              3
#define I2S1_RX_R_SRCDN_CLKEN_LEN                 1
#define ULTR_DN_SRCUP_CLKEN_OFFSET                4
#define ULTR_DN_SRCUP_CLKEN_LEN                   1
#define CODEC_0_DN_SRCUP_CLKEN_OFFSET             5
#define CODEC_0_DN_SRCUP_CLKEN_LEN                1
#define CODEC_1_DN_SRCUP_CLKEN_OFFSET             6
#define CODEC_1_DN_SRCUP_CLKEN_LEN                1
#define CODEC_2_DN_SRCUP_CLKEN_OFFSET             7
#define CODEC_2_DN_SRCUP_CLKEN_LEN                1
#define AUDIO_0_DN_SRCUP_CLKEN_OFFSET             8
#define AUDIO_0_DN_SRCUP_CLKEN_LEN                1
#define AUDIO_1_DN_SRCUP_CLKEN_OFFSET             9
#define AUDIO_1_DN_SRCUP_CLKEN_LEN                1
#define AUDIO_2_DN_SRCUP_CLKEN_OFFSET             10
#define AUDIO_2_DN_SRCUP_CLKEN_LEN                1
#define I2S1_RX_L_SRCUP_CLKEN_OFFSET              11
#define I2S1_RX_L_SRCUP_CLKEN_LEN                 1
#define I2S1_RX_R_SRCUP_CLKEN_OFFSET              12
#define I2S1_RX_R_SRCUP_CLKEN_LEN                 1
#define DACL_SRCUP_CLKEN_OFFSET                   13
#define DACL_SRCUP_CLKEN_LEN                      1
#define DACR_SRCUP_CLKEN_OFFSET                   14
#define DACR_SRCUP_CLKEN_LEN                      1
#define ADC1_CLKEN_OFFSET                         15    /* store:ADC1, CHS:ADC0 */
#define ADC1_CLKEN_LEN                            1
#define ADC2_CLKEN_OFFSET                         16    /* store:ADC2, CHS:ADC1 */
#define ADC2_CLKEN_LEN                            1
#define ADC3_CLKEN_OFFSET                         17    /* store:ADC3, CHS:ADC2 */
#define ADC3_CLKEN_LEN                            1
#define ADC4_CLKEN_OFFSET                         18    /* store:ADC4, CHS:ADC3 */
#define ADC4_CLKEN_LEN                            1
#define ADC5_CLKEN_OFFSET                         19    /* store:ADC5, CHS:ADC4 */
#define ADC5_CLKEN_LEN                            1
#define ADC6_CLKEN_OFFSET                         20    /* store:ADC6, CHS:ADC5 */
#define ADC6_CLKEN_LEN                            1
#define ADC7_CLKEN_OFFSET                         21    /* store:ADC7, CHS:ADC6 */
#define ADC7_CLKEN_LEN                            1
#define ADC8_CLKEN_OFFSET                         22    /* store:ADC8, CHS:ADC7 */
#define ADC8_CLKEN_LEN                            1
#define ADC_ULTR_CLKEN_OFFSET                     23
#define ADC_ULTR_CLKEN_LEN                        1
#define DACL_CLKEN_OFFSET                         24
#define DACL_CLKEN_LEN                            1
#define DACR_CLKEN_OFFSET                         25
#define DACR_CLKEN_LEN                            1
#define MIXER4_SPA0_CLKEN_OFFSET                  26
#define MIXER4_SPA0_CLKEN_LEN                     1
#define MIXER4_SPA1_CLKEN_OFFSET                  27
#define MIXER4_SPA1_CLKEN_LEN                     1
#define MIXER4_SPA2_CLKEN_OFFSET                  28
#define MIXER4_SPA2_CLKEN_LEN                     1
#define MIXER2_ULTR0_CLKEN_OFFSET                 29
#define MIXER2_ULTR0_CLKEN_LEN                    1
#define MIXER2_ULTR1_CLKEN_OFFSET                 30
#define MIXER2_ULTR1_CLKEN_LEN                    1
#define MIXER2_ULTR2_CLKEN_OFFSET                 31
#define MIXER2_ULTR2_CLKEN_LEN                    1

#define CODEC_CLK_EN3_REG        (PAGE_SOCCODEC + 0x10)
#define ADC1_0P5_PGA_CLKEN_OFFSET                 0    /* store:ADC1, CHS:ADC0 */
#define ADC1_0P5_PGA_CLKEN_LEN                    1
#define ADC2_0P5_PGA_CLKEN_OFFSET                 1    /* store:ADC2, CHS:ADC1 */
#define ADC2_0P5_PGA_CLKEN_LEN                    1
#define ADC3_0P5_PGA_CLKEN_OFFSET                 2    /* store:ADC3, CHS:ADC2 */
#define ADC3_0P5_PGA_CLKEN_LEN                    1
#define ADC4_0P5_PGA_CLKEN_OFFSET                 3    /* store:ADC4, CHS:ADC3 */
#define ADC4_0P5_PGA_CLKEN_LEN                    1
#define ADC5_0P5_PGA_CLKEN_OFFSET                 4    /* store:ADC5, CHS:ADC4 */
#define ADC5_0P5_PGA_CLKEN_LEN                    1
#define ADC6_0P5_PGA_CLKEN_OFFSET                 5    /* store:ADC6, CHS:ADC5 */
#define ADC6_0P5_PGA_CLKEN_LEN                    1
#define ADC7_0P5_PGA_CLKEN_OFFSET                 6    /* store:ADC7, CHS:ADC6 */
#define ADC7_0P5_PGA_CLKEN_LEN                    1
#define ADC8_0P5_PGA_CLKEN_OFFSET                 7    /* store:ADC8, CHS:ADC7 */
#define ADC8_0P5_PGA_CLKEN_LEN                    1
#define ADC0_CICDN16_CLKEN_OFFSET                 8
#define ADC0_CICDN16_CLKEN_LEN                    1
#define ADC1_CICDN16_CLKEN_OFFSET                 9
#define ADC1_CICDN16_CLKEN_LEN                    1
#define ADC2_CICDN16_CLKEN_OFFSET                 10
#define ADC2_CICDN16_CLKEN_LEN                    1
#define ADC3_CICDN16_CLKEN_OFFSET                 11
#define ADC3_CICDN16_CLKEN_LEN                    1
#define ADC4_CICDN16_CLKEN_OFFSET                 12
#define ADC4_CICDN16_CLKEN_LEN                    1
#define ADC5_CICDN16_CLKEN_OFFSET                 13
#define ADC5_CICDN16_CLKEN_LEN                    1
#define ADC6_CICDN16_CLKEN_OFFSET                 14
#define ADC6_CICDN16_CLKEN_LEN                    1
#define ADC7_CICDN16_CLKEN_OFFSET                 15
#define ADC7_CICDN16_CLKEN_LEN                    1
#define ADC0_CICDN16_4STAGE_CLKEN_OFFSET          16
#define ADC0_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC1_CICDN16_4STAGE_CLKEN_OFFSET          17
#define ADC1_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC2_CICDN16_4STAGE_CLKEN_OFFSET          18
#define ADC2_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC3_CICDN16_4STAGE_CLKEN_OFFSET          19
#define ADC3_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC4_CICDN16_4STAGE_CLKEN_OFFSET          20
#define ADC4_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC5_CICDN16_4STAGE_CLKEN_OFFSET          21
#define ADC5_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC6_CICDN16_4STAGE_CLKEN_OFFSET          22
#define ADC6_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC7_CICDN16_4STAGE_CLKEN_OFFSET          23
#define ADC7_CICDN16_4STAGE_CLKEN_LEN             1
#define ADC0_CIC_ULTR_CLKEN_OFFSET                24
#define ADC0_CIC_ULTR_CLKEN_LEN                   1
#define ADC1_CIC_ULTR_CLKEN_OFFSET                25
#define ADC1_CIC_ULTR_CLKEN_LEN                   1
#define ADC2_CIC_ULTR_CLKEN_OFFSET                26
#define ADC2_CIC_ULTR_CLKEN_LEN                   1
#define ADC3_CIC_ULTR_CLKEN_OFFSET                27
#define ADC3_CIC_ULTR_CLKEN_LEN                   1
#define DMIC1_CLKEN_OFFSET                        28    /* store:DMIC1, CHS:DMIC0 */
#define DMIC1_CLKEN_LEN                           1
#define DMIC2_CLKEN_OFFSET                        29    /* store:DMIC2, CHS:DMIC1 */
#define DMIC2_CLKEN_LEN                           1
#define DMIC3_CLKEN_OFFSET                        30    /* store:DMIC3, CHS:DMIC2 */
#define DMIC3_CLKEN_LEN                           1
#define DMIC4_CLKEN_OFFSET                        31    /* store:DMIC4, CHS:DMIC3 */
#define DMIC4_CLKEN_LEN                           1

#define CODEC_CLK_EN4_REG        (PAGE_SOCCODEC + 0x14)
#define ULTR_HPF_CLKEN_OFFSET                     0
#define ULTR_HPF_CLKEN_LEN                        1
#define DACL_SDM_CLKEN_OFFSET                     1
#define DACL_SDM_CLKEN_LEN                        1
#define DACR_SDM_CLKEN_OFFSET                     2
#define DACR_SDM_CLKEN_LEN                        1
#define AUDIO_HAPTIC_2WAYS_CLK_EN_OFFSET          3
#define AUDIO_HAPTIC_2WAYS_CLK_EN_LEN             1
#define SIDETONE_PGA_CLKEN_OFFSET                 5
#define SIDETONE_PGA_CLKEN_LEN                    1
#define DACL_UP16_CLKEN_OFFSET                    11
#define DACL_UP16_CLKEN_LEN                       1
#define DACL_SRCUP_ULTR_CLKEN_OFFSET              12
#define DACL_SRCUP_ULTR_CLKEN_LEN                 1
#define SPA0_ONE_KEY_CLK_RST_EN_OFFSET            13
#define SPA0_ONE_KEY_CLK_RST_EN_LEN               1
#define SPA1_ONE_KEY_CLK_RST_EN_OFFSET            14
#define SPA1_ONE_KEY_CLK_RST_EN_LEN               1
#define SPA2_ONE_KEY_CLK_RST_EN_OFFSET            15
#define SPA2_ONE_KEY_CLK_RST_EN_LEN               1
#define SPA3_ONE_KEY_CLK_RST_EN_OFFSET            16
#define SPA3_ONE_KEY_CLK_RST_EN_LEN               1

#define CODEC_SW_RST_N_REG       (PAGE_SOCCODEC + 0x18)
#define CODEC_SW_RST_N_OFFSET                     0
#define CODEC_SW_RST_N_LEN                        1
#define RST_4MIC_VOICE_ACCESS_IRQ_OFFSET          2
#define RST_4MIC_VOICE_ACCESS_IRQ_LEN             1
#define RST_4MIC_AUDIO_ACCESS_IRQ_OFFSET          3
#define RST_4MIC_AUDIO_ACCESS_IRQ_LEN             1
#define RST_4MIC_DN_ACCESS_IRQ_OFFSET             5
#define RST_4MIC_DN_ACCESS_IRQ_LEN                1
#define RST_8MIC_DN_ACCESS_IRQ_OFFSET             6
#define RST_8MIC_DN_ACCESS_IRQ_LEN                1
#define RST_8MIC_UP_ACCESS_IRQ_OFFSET             7
#define RST_8MIC_UP_ACCESS_IRQ_LEN                1
#define RST_8PA_DN_ACCESS_IRQ_OFFSET              8
#define RST_8PA_DN_ACCESS_IRQ_LEN                 1

#define I2S0_CTRL_REG            (PAGE_SOCCODEC + 0x1C)
#define FS_I2S1_OFFSET                            13    /* store:FS_I2S1, CHS:FS_I2S0 */
#define FS_I2S1_LEN                               3
#define I2S1_IF_TX_ENA_OFFSET                     16    /* store:I2S1_IF_TX_ENA, CHS:I2S0_IF_TX_ENA */
#define I2S1_IF_TX_ENA_LEN                        1
#define I2S1_IF_RX_ENA_OFFSET                     17    /* store:I2S1_IF_RX_ENA, CHS:I2S0_IF_RX_ENA */
#define I2S1_IF_RX_ENA_LEN                        1
#define I2S0_MST_SLV_OFFSET                       18
#define I2S0_MST_SLV_LEN                          1
#define I2S1_DIRECT_LOOP_OFFSET                   19    /* store:I2S1_DIRECT_LOOP, CHS:I2S0_DIRECT_LOOP */
#define I2S1_DIRECT_LOOP_LEN                      2
#define I2S1_FUNC_MODE_OFFSET                     21    /* store:I2S1_FUNC_MODE, CHS:I2S0_FUNC_MODE */
#define I2S1_FUNC_MODE_LEN                        3
#define I2S1_FRAME_MODE_OFFSET                    24    /* store:I2S1_FRAME_MODE, CHS:I2S0_FRAME_MODE */
#define I2S1_FRAME_MODE_LEN                       1
#define I2S0_LRCLK_MODE_OFFSET                    25
#define I2S0_LRCLK_MODE_LEN                       1
#define I2S0_CHNNL_MODE_OFFSET                    26
#define I2S0_CHNNL_MODE_LEN                       1
#define I2S0_CODEC_DATA_FORMAT_OFFSET             27
#define I2S0_CODEC_DATA_FORMAT_LEN                1
#define I2S0_CODEC_IO_WORDLENGTH_OFFSET           28
#define I2S0_CODEC_IO_WORDLENGTH_LEN              2
#define I2S1_TX_CLK_SEL_OFFSET                    30    /* store:I2S1_TX_CLK_SEL, CHS:I2S0_TX_CLK_SEL */
#define I2S1_TX_CLK_SEL_LEN                       1
#define I2S1_RX_CLK_SEL_OFFSET                    31    /* store:I2S1_RX_CLK_SEL, CHS:I2S0_RX_CLK_SEL */
#define I2S1_RX_CLK_SEL_LEN                       1

#define I2S0_TDM_CTRL0_REG       (PAGE_SOCCODEC + 0x20)
#define S0_FIFO_CLR_OFFSET                        0
#define S0_FIFO_CLR_LEN                           1
#define S0_MEM_ICG_BP_EN_OFFSET                   1
#define S0_MEM_ICG_BP_EN_LEN                      1
#define S0_TDM_FRAME_MODE_OFFSET                  2
#define S0_TDM_FRAME_MODE_LEN                     3
#define S0_TDM_DIRECT_LOOP_OFFSET                 5
#define S0_TDM_DIRECT_LOOP_LEN                    2
#define S0_TDM_IF_EN_OFFSET                       7
#define S0_TDM_IF_EN_LEN                          1
#define S0_TDM_TX_CH3_SEL_OFFSET                  8
#define S0_TDM_TX_CH3_SEL_LEN                     2
#define S0_TDM_TX_CH2_SEL_OFFSET                  10
#define S0_TDM_TX_CH2_SEL_LEN                     2
#define S0_TDM_TX_CH1_SEL_OFFSET                  12
#define S0_TDM_TX_CH1_SEL_LEN                     2
#define S0_TDM_TX_CH0_SEL_OFFSET                  14
#define S0_TDM_TX_CH0_SEL_LEN                     2
#define S0_TDM_RX_SLOT_SEL_V0_OFFSET              16
#define S0_TDM_RX_SLOT_SEL_V0_LEN                 3
#define S0_TDM_RX_SLOT_SEL_I0_OFFSET              19
#define S0_TDM_RX_SLOT_SEL_I0_LEN                 3
#define S0_TDM_TX_CLK_SEL_OFFSET                  22
#define S0_TDM_TX_CLK_SEL_LEN                     1
#define S0_TDM_RX_CLK_SEL_OFFSET                  23
#define S0_TDM_RX_CLK_SEL_LEN                     1
#define S0_TDM_RX_SLOT_SEL_V1_OFFSET              24
#define S0_TDM_RX_SLOT_SEL_V1_LEN                 3
#define S0_TDM_RX_SLOT_SEL_I1_OFFSET              27
#define S0_TDM_RX_SLOT_SEL_I1_LEN                 3

#define I2S0_TDM_CTRL1_REG       (PAGE_SOCCODEC + 0x24)
#define S0_TDM_RX_SLOT_SEL_V2_OFFSET              0
#define S0_TDM_RX_SLOT_SEL_V2_LEN                 3
#define S0_TDM_RX_SLOT_SEL_I2_OFFSET              3
#define S0_TDM_RX_SLOT_SEL_I2_LEN                 3
#define S0_TDM_MODE_OFFSET                        6
#define S0_TDM_MODE_LEN                           2
#define S0_TDM_RX_SLOT_SEL_V3_OFFSET              8
#define S0_TDM_RX_SLOT_SEL_V3_LEN                 3
#define S0_TDM_RX_SLOT_SEL_I3_OFFSET              11
#define S0_TDM_RX_SLOT_SEL_I3_LEN                 3
#define S0_TDM_MST_SLV_OFFSET                     16
#define S0_TDM_MST_SLV_LEN                        1
#define S0_TDM_ERR_STAT_OFFSET                    18
#define S0_TDM_ERR_STAT_LEN                       2
#define S1_FIFO_CLR_OFFSET                        21
#define S1_FIFO_CLR_LEN                           1

#define I2S1_PCM_CTRL_REG        (PAGE_SOCCODEC + 0x28)
#define FS_I2S2_OFFSET                            13    /* store:FS_I2S2, CHS:FS_I2S1 */
#define FS_I2S2_LEN                               3
#define I2S2_IF_TX_ENA_OFFSET                     16    /* store:I2S2_IF_TX_ENA, CHS:I2S1_IF_TX_ENA */
#define I2S2_IF_TX_ENA_LEN                        1
#define I2S2_IF_RX_ENA_OFFSET                     17    /* store:I2S2_IF_RX_ENA, CHS:I2S1_IF_RX_ENA */
#define I2S2_IF_RX_ENA_LEN                        1
#define I2S1_MST_SLV_OFFSET                       18
#define I2S1_MST_SLV_LEN                          1
#define I2S2_DIRECT_LOOP_OFFSET                   19    /* store:I2S2_DIRECT_LOOP, CHS:I2S1_DIRECT_LOOP */
#define I2S2_DIRECT_LOOP_LEN                      2
#define I2S2_FUNC_MODE_OFFSET                     21    /* store:I2S2_FUNC_MODE, CHS:I2S1_FUNC_MODE */
#define I2S2_FUNC_MODE_LEN                        3
#define I2S2_FRAME_MODE_OFFSET                    24    /* store:I2S2_FRAME_MODE, CHS:I2S1_FRAME_MODE */
#define I2S2_FRAME_MODE_LEN                       1
#define I2S1_LRCLK_MODE_OFFSET                    25
#define I2S1_LRCLK_MODE_LEN                       1
#define I2S1_CHNNL_MODE_OFFSET                    26
#define I2S1_CHNNL_MODE_LEN                       1
#define I2S1_CODEC_DATA_FORMAT_OFFSET             27
#define I2S1_CODEC_DATA_FORMAT_LEN                1
#define I2S1_CODEC_IO_WORDLENGTH_OFFSET           28
#define I2S1_CODEC_IO_WORDLENGTH_LEN              2
#define I2S2_TX_CLK_SEL_OFFSET                    30    /* store:I2S2_TX_CLK_SEL, CHS:I2S1_TX_CLK_SEL */
#define I2S2_TX_CLK_SEL_LEN                       1
#define I2S2_RX_CLK_SEL_OFFSET                    31    /* store:I2S2_RX_CLK_SEL, CHS:I2S1_RX_CLK_SEL */
#define I2S2_RX_CLK_SEL_LEN                       1

#define I2S0_TDM256_CTRL0_REG    (PAGE_SOCCODEC + 0x2C)
#define S0_TDM_FIFO_CLR_OFFSET                    4
#define S0_TDM_FIFO_CLR_LEN                       1
#define S0_TDM_MEM_ICG_BP_EN_OFFSET               5
#define S0_TDM_MEM_ICG_BP_EN_LEN                  1
#define S0_TDM_256_FRAME_MODE_OFFSET              6
#define S0_TDM_256_FRAME_MODE_LEN                 2
#define S0_TDM_256_DIRECT_LOOP_OFFSET             8
#define S0_TDM_256_DIRECT_LOOP_LEN                2
#define S0_TDM_RX_SLOT_SEL_V3_32_OFFSET           18
#define S0_TDM_RX_SLOT_SEL_V3_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_V2_32_OFFSET           19
#define S0_TDM_RX_SLOT_SEL_V2_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_V1_32_OFFSET           20
#define S0_TDM_RX_SLOT_SEL_V1_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_V0_32_OFFSET           21
#define S0_TDM_RX_SLOT_SEL_V0_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_I3_32_OFFSET           22
#define S0_TDM_RX_SLOT_SEL_I3_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_I2_32_OFFSET           23
#define S0_TDM_RX_SLOT_SEL_I2_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_I1_32_OFFSET           24
#define S0_TDM_RX_SLOT_SEL_I1_32_LEN              1
#define S0_TDM_RX_SLOT_SEL_I0_32_OFFSET           25
#define S0_TDM_RX_SLOT_SEL_I0_32_LEN              1
#define I2S0_TDM_SLOT_SEL_OFFSET                  26
#define I2S0_TDM_SLOT_SEL_LEN                     1
#define S0_TDM_256_MST_SLV_OFFSET                 27
#define S0_TDM_256_MST_SLV_LEN                    1
#define S0_TDM_256_IF_EN_OFFSET                   28
#define S0_TDM_256_IF_EN_LEN                      1

#define I2S0_TDM256_CTRL1_REG    (PAGE_SOCCODEC + 0x30)
#define S0_TDM_RX_SLOT_SEL_VB3_16_OFFSET          0
#define S0_TDM_RX_SLOT_SEL_VB3_16_LEN             2
#define S0_TDM_RX_SLOT_SEL_VB2_16_OFFSET          2
#define S0_TDM_RX_SLOT_SEL_VB2_16_LEN             2
#define S0_TDM_RX_SLOT_SEL_VB1_16_OFFSET          4
#define S0_TDM_RX_SLOT_SEL_VB1_16_LEN             2
#define S0_TDM_RX_SLOT_SEL_VB0_16_OFFSET          6
#define S0_TDM_RX_SLOT_SEL_VB0_16_LEN             2
#define S0_TDM_RX_SLOT_SEL_D3_16_OFFSET           8
#define S0_TDM_RX_SLOT_SEL_D3_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_D2_16_OFFSET           10
#define S0_TDM_RX_SLOT_SEL_D2_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_D1_16_OFFSET           12
#define S0_TDM_RX_SLOT_SEL_D1_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_D0_16_OFFSET           14
#define S0_TDM_RX_SLOT_SEL_D0_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_V3_16_OFFSET           16
#define S0_TDM_RX_SLOT_SEL_V3_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_V2_16_OFFSET           18
#define S0_TDM_RX_SLOT_SEL_V2_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_V1_16_OFFSET           20
#define S0_TDM_RX_SLOT_SEL_V1_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_V0_16_OFFSET           22
#define S0_TDM_RX_SLOT_SEL_V0_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_I3_16_OFFSET           24
#define S0_TDM_RX_SLOT_SEL_I3_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_I2_16_OFFSET           26
#define S0_TDM_RX_SLOT_SEL_I2_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_I1_16_OFFSET           28
#define S0_TDM_RX_SLOT_SEL_I1_16_LEN              2
#define S0_TDM_RX_SLOT_SEL_I0_16_OFFSET           30
#define S0_TDM_RX_SLOT_SEL_I0_16_LEN              2

#define PGA_THRE_CTRL0_REG       (PAGE_SOCCODEC + 0x34)
#define PGA_MIXER_THRE_CTRL0_OFFSET               0
#define PGA_MIXER_THRE_CTRL0_LEN                  32

#define PGA_THRE_CTRL1_REG       (PAGE_SOCCODEC + 0x38)
#define PGA_MIXER_THRE_CTRL1_OFFSET               0
#define PGA_MIXER_THRE_CTRL1_LEN                  32

#define PGA_THRE_CTRL2_REG       (PAGE_SOCCODEC + 0x3C)
#define PGA_MIXER_THRE_CTRL2_OFFSET               0
#define PGA_MIXER_THRE_CTRL2_LEN                  32

#define PGA_GAINOFFSET_CTRL0_REG (PAGE_SOCCODEC + 0x40)
#define CODEC_0_DN_PGA_GAINOFFSET_OFFSET          0
#define CODEC_0_DN_PGA_GAINOFFSET_LEN             8
#define CODEC_1_DN_PGA_GAINOFFSET_OFFSET          8
#define CODEC_1_DN_PGA_GAINOFFSET_LEN             8
#define CODEC_2_DN_PGA_GAINOFFSET_OFFSET          16
#define CODEC_2_DN_PGA_GAINOFFSET_LEN             8
#define AUDIO_0_DN_PGA_GAINOFFSET_OFFSET          24
#define AUDIO_0_DN_PGA_GAINOFFSET_LEN             8

#define PGA_GAINOFFSET_CTRL1_REG (PAGE_SOCCODEC + 0x44)
#define MIC2_UP_PGA_GAINOFFSET_OFFSET             0
#define MIC2_UP_PGA_GAINOFFSET_LEN                8
#define MIC3_UP_PGA_GAINOFFSET_OFFSET             8
#define MIC3_UP_PGA_GAINOFFSET_LEN                8
#define AUDIO_1_DN_PGA_GAINOFFSET_OFFSET          16
#define AUDIO_1_DN_PGA_GAINOFFSET_LEN             8
#define AUDIO_2_DN_PGA_GAINOFFSET_OFFSET          24
#define AUDIO_2_DN_PGA_GAINOFFSET_LEN             8

#define PGA_GAINOFFSET_CTRL2_REG (PAGE_SOCCODEC + 0x48)
#define AUDIO_UP_L_PGA_GAINOFFSET_OFFSET          0
#define AUDIO_UP_L_PGA_GAINOFFSET_LEN             8
#define AUDIO_UP_R_PGA_GAINOFFSET_OFFSET          8
#define AUDIO_UP_R_PGA_GAINOFFSET_LEN             8
#define VOICE_UP_L_PGA_GAINOFFSET_OFFSET          16
#define VOICE_UP_L_PGA_GAINOFFSET_LEN             8
#define VOICE_UP_R_PGA_GAINOFFSET_OFFSET          24
#define VOICE_UP_R_PGA_GAINOFFSET_LEN             8

#define PGA_GAINOFFSET_CTRL3_REG (PAGE_SOCCODEC + 0x4C)
#define I2S1_RX_L_PGA_GAINOFFSET_OFFSET           0
#define I2S1_RX_L_PGA_GAINOFFSET_LEN              8
#define I2S1_RX_R_PGA_GAINOFFSET_OFFSET           8
#define I2S1_RX_R_PGA_GAINOFFSET_LEN              8
#define SIDETONE_PGA_GAINOFFSET_OFFSET            16
#define SIDETONE_PGA_GAINOFFSET_LEN               8

#define PGA_GAINOFFSET_CTRL4_REG (PAGE_SOCCODEC + 0x50)
#define ULTR_DN_PGA_GAINOFFSET_OFFSET             0
#define ULTR_DN_PGA_GAINOFFSET_LEN                8

#define CODEC_0_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x54)
#define CODEC_0_DN_PGA_LINEAR_SEL_OFFSET          1
#define CODEC_0_DN_PGA_LINEAR_SEL_LEN             1
#define CODEC_0_DN_PGA_ZERO_NUM_OFFSET            2
#define CODEC_0_DN_PGA_ZERO_NUM_LEN               5
#define CODEC_0_DN_PGA_THRE_ID_OFFSET             7
#define CODEC_0_DN_PGA_THRE_ID_LEN                2
#define CODEC_0_DN_PGA_NOISE_EN_OFFSET            9
#define CODEC_0_DN_PGA_NOISE_EN_LEN               1
#define CODEC_0_DN_PGA_BYPASS_OFFSET              10
#define CODEC_0_DN_PGA_BYPASS_LEN                 1
#define CODEC_0_DN_PGA_FADE_OUT_OFFSET            11
#define CODEC_0_DN_PGA_FADE_OUT_LEN               5
#define CODEC_0_DN_PGA_FADE_IN_OFFSET             16
#define CODEC_0_DN_PGA_FADE_IN_LEN                5
#define CODEC_0_DN_PGA_CFG_OFFSET                 21
#define CODEC_0_DN_PGA_CFG_LEN                    3
#define CODEC_0_DN_PGA_GAIN_OFFSET                24
#define CODEC_0_DN_PGA_GAIN_LEN                   8

#define CODEC_1_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x58)
#define CODEC_1_DN_PGA_LINEAR_SEL_OFFSET          1
#define CODEC_1_DN_PGA_LINEAR_SEL_LEN             1
#define CODEC_1_DN_PGA_ZERO_NUM_OFFSET            2
#define CODEC_1_DN_PGA_ZERO_NUM_LEN               5
#define CODEC_1_DN_PGA_THRE_ID_OFFSET             7
#define CODEC_1_DN_PGA_THRE_ID_LEN                2
#define CODEC_1_DN_PGA_NOISE_EN_OFFSET            9
#define CODEC_1_DN_PGA_NOISE_EN_LEN               1
#define CODEC_1_DN_PGA_BYPASS_OFFSET              10
#define CODEC_1_DN_PGA_BYPASS_LEN                 1
#define CODEC_1_DN_PGA_FADE_OUT_OFFSET            11
#define CODEC_1_DN_PGA_FADE_OUT_LEN               5
#define CODEC_1_DN_PGA_FADE_IN_OFFSET             16
#define CODEC_1_DN_PGA_FADE_IN_LEN                5
#define CODEC_1_DN_PGA_CFG_OFFSET                 21
#define CODEC_1_DN_PGA_CFG_LEN                    3
#define CODEC_1_DN_PGA_GAIN_OFFSET                24
#define CODEC_1_DN_PGA_GAIN_LEN                   8

#define CODEC_2_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x5C)
#define CODEC_2_DN_PGA_LINEAR_SEL_OFFSET          1
#define CODEC_2_DN_PGA_LINEAR_SEL_LEN             1
#define CODEC_2_DN_PGA_ZERO_NUM_OFFSET            2
#define CODEC_2_DN_PGA_ZERO_NUM_LEN               5
#define CODEC_2_DN_PGA_THRE_ID_OFFSET             7
#define CODEC_2_DN_PGA_THRE_ID_LEN                2
#define CODEC_2_DN_PGA_NOISE_EN_OFFSET            9
#define CODEC_2_DN_PGA_NOISE_EN_LEN               1
#define CODEC_2_DN_PGA_BYPASS_OFFSET              10
#define CODEC_2_DN_PGA_BYPASS_LEN                 1
#define CODEC_2_DN_PGA_FADE_OUT_OFFSET            11
#define CODEC_2_DN_PGA_FADE_OUT_LEN               5
#define CODEC_2_DN_PGA_FADE_IN_OFFSET             16
#define CODEC_2_DN_PGA_FADE_IN_LEN                5
#define CODEC_2_DN_PGA_CFG_OFFSET                 21
#define CODEC_2_DN_PGA_CFG_LEN                    3
#define CODEC_2_DN_PGA_GAIN_OFFSET                24
#define CODEC_2_DN_PGA_GAIN_LEN                   8

#define AUDIO_0_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x60)
#define AUDIO_0_DN_PGA_LINEAR_SEL_OFFSET          1
#define AUDIO_0_DN_PGA_LINEAR_SEL_LEN             1
#define AUDIO_0_DN_PGA_ZERO_NUM_OFFSET            2
#define AUDIO_0_DN_PGA_ZERO_NUM_LEN               5
#define AUDIO_0_DN_PGA_THRE_ID_OFFSET             7
#define AUDIO_0_DN_PGA_THRE_ID_LEN                2
#define AUDIO_0_DN_PGA_NOISE_EN_OFFSET            9
#define AUDIO_0_DN_PGA_NOISE_EN_LEN               1
#define AUDIO_0_DN_PGA_BYPASS_OFFSET              10
#define AUDIO_0_DN_PGA_BYPASS_LEN                 1
#define AUDIO_0_DN_PGA_FADE_OUT_OFFSET            11
#define AUDIO_0_DN_PGA_FADE_OUT_LEN               5
#define AUDIO_0_DN_PGA_FADE_IN_OFFSET             16
#define AUDIO_0_DN_PGA_FADE_IN_LEN                5
#define AUDIO_0_DN_PGA_CFG_OFFSET                 21
#define AUDIO_0_DN_PGA_CFG_LEN                    3
#define AUDIO_0_DN_PGA_GAIN_OFFSET                24
#define AUDIO_0_DN_PGA_GAIN_LEN                   8

#define AUDIO_1_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x64)
#define AUDIO_1_DN_PGA_LINEAR_SEL_OFFSET          1
#define AUDIO_1_DN_PGA_LINEAR_SEL_LEN             1
#define AUDIO_1_DN_PGA_ZERO_NUM_OFFSET            2
#define AUDIO_1_DN_PGA_ZERO_NUM_LEN               5
#define AUDIO_1_DN_PGA_THRE_ID_OFFSET             7
#define AUDIO_1_DN_PGA_THRE_ID_LEN                2
#define AUDIO_1_DN_PGA_NOISE_EN_OFFSET            9
#define AUDIO_1_DN_PGA_NOISE_EN_LEN               1
#define AUDIO_1_DN_PGA_BYPASS_OFFSET              10
#define AUDIO_1_DN_PGA_BYPASS_LEN                 1
#define AUDIO_1_DN_PGA_FADE_OUT_OFFSET            11
#define AUDIO_1_DN_PGA_FADE_OUT_LEN               5
#define AUDIO_1_DN_PGA_FADE_IN_OFFSET             16
#define AUDIO_1_DN_PGA_FADE_IN_LEN                5
#define AUDIO_1_DN_PGA_CFG_OFFSET                 21
#define AUDIO_1_DN_PGA_CFG_LEN                    3
#define AUDIO_1_DN_PGA_GAIN_OFFSET                24
#define AUDIO_1_DN_PGA_GAIN_LEN                   8

#define AUDIO_2_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x68)
#define AUDIO_2_DN_PGA_LINEAR_SEL_OFFSET          1
#define AUDIO_2_DN_PGA_LINEAR_SEL_LEN             1
#define AUDIO_2_DN_PGA_ZERO_NUM_OFFSET            2
#define AUDIO_2_DN_PGA_ZERO_NUM_LEN               5
#define AUDIO_2_DN_PGA_THRE_ID_OFFSET             7
#define AUDIO_2_DN_PGA_THRE_ID_LEN                2
#define AUDIO_2_DN_PGA_NOISE_EN_OFFSET            9
#define AUDIO_2_DN_PGA_NOISE_EN_LEN               1
#define AUDIO_2_DN_PGA_BYPASS_OFFSET              10
#define AUDIO_2_DN_PGA_BYPASS_LEN                 1
#define AUDIO_2_DN_PGA_FADE_OUT_OFFSET            11
#define AUDIO_2_DN_PGA_FADE_OUT_LEN               5
#define AUDIO_2_DN_PGA_FADE_IN_OFFSET             16
#define AUDIO_2_DN_PGA_FADE_IN_LEN                5
#define AUDIO_2_DN_PGA_CFG_OFFSET                 21
#define AUDIO_2_DN_PGA_CFG_LEN                    3
#define AUDIO_2_DN_PGA_GAIN_OFFSET                24
#define AUDIO_2_DN_PGA_GAIN_LEN                   8

#define SIDETONE_PGA_CTRL_REG    (PAGE_SOCCODEC + 0x6C)
#define SIDETONE_PGA_LINEAR_SEL_OFFSET            1
#define SIDETONE_PGA_LINEAR_SEL_LEN               1
#define SIDETONE_PGA_ZERO_NUM_OFFSET              2
#define SIDETONE_PGA_ZERO_NUM_LEN                 5
#define SIDETONE_PGA_THRE_ID_OFFSET               7
#define SIDETONE_PGA_THRE_ID_LEN                  2
#define SIDETONE_PGA_NOISE_EN_OFFSET              9
#define SIDETONE_PGA_NOISE_EN_LEN                 1
#define SIDETONE_PGA_BYPASS_OFFSET                10
#define SIDETONE_PGA_BYPASS_LEN                   1
#define SIDETONE_PGA_FADE_OUT_OFFSET              11
#define SIDETONE_PGA_FADE_OUT_LEN                 5
#define SIDETONE_PGA_FADE_IN_OFFSET               16
#define SIDETONE_PGA_FADE_IN_LEN                  5
#define SIDETONE_PGA_CFG_OFFSET                   21
#define SIDETONE_PGA_CFG_LEN                      3
#define SIDETONE_PGA_GAIN_OFFSET                  24
#define SIDETONE_PGA_GAIN_LEN                     8

#define AUDIO_L_UP_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x70)
#define AUDIO_L_UP_PGA_LINEAR_SEL_OFFSET          1
#define AUDIO_L_UP_PGA_LINEAR_SEL_LEN             1
#define AUDIO_L_UP_PGA_ZERO_NUM_OFFSET            2
#define AUDIO_L_UP_PGA_ZERO_NUM_LEN               5
#define AUDIO_L_UP_PGA_THRE_ID_OFFSET             7
#define AUDIO_L_UP_PGA_THRE_ID_LEN                2
#define AUDIO_L_UP_PGA_NOISE_EN_OFFSET            9
#define AUDIO_L_UP_PGA_NOISE_EN_LEN               1
#define AUDIO_L_UP_PGA_BYPASS_OFFSET              10
#define AUDIO_L_UP_PGA_BYPASS_LEN                 1
#define AUDIO_L_UP_PGA_FADE_OUT_OFFSET            11
#define AUDIO_L_UP_PGA_FADE_OUT_LEN               5
#define AUDIO_L_UP_PGA_FADE_IN_OFFSET             16
#define AUDIO_L_UP_PGA_FADE_IN_LEN                5
#define AUDIO_L_UP_PGA_CFG_OFFSET                 21
#define AUDIO_L_UP_PGA_CFG_LEN                    3
#define AUDIO_L_UP_PGA_GAIN_OFFSET                24
#define AUDIO_L_UP_PGA_GAIN_LEN                   8

#define AUDIO_R_UP_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x74)
#define AUDIO_R_UP_PGA_LINEAR_SEL_OFFSET          1
#define AUDIO_R_UP_PGA_LINEAR_SEL_LEN             1
#define AUDIO_R_UP_PGA_ZERO_NUM_OFFSET            2
#define AUDIO_R_UP_PGA_ZERO_NUM_LEN               5
#define AUDIO_R_UP_PGA_THRE_ID_OFFSET             7
#define AUDIO_R_UP_PGA_THRE_ID_LEN                2
#define AUDIO_R_UP_PGA_NOISE_EN_OFFSET            9
#define AUDIO_R_UP_PGA_NOISE_EN_LEN               1
#define AUDIO_R_UP_PGA_BYPASS_OFFSET              10
#define AUDIO_R_UP_PGA_BYPASS_LEN                 1
#define AUDIO_R_UP_PGA_FADE_OUT_OFFSET            11
#define AUDIO_R_UP_PGA_FADE_OUT_LEN               5
#define AUDIO_R_UP_PGA_FADE_IN_OFFSET             16
#define AUDIO_R_UP_PGA_FADE_IN_LEN                5
#define AUDIO_R_UP_PGA_CFG_OFFSET                 21
#define AUDIO_R_UP_PGA_CFG_LEN                    3
#define AUDIO_R_UP_PGA_GAIN_OFFSET                24
#define AUDIO_R_UP_PGA_GAIN_LEN                   8

#define VOICE_L_UP_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x78)
#define VOICE_L_UP_PGA_LINEAR_SEL_OFFSET          1
#define VOICE_L_UP_PGA_LINEAR_SEL_LEN             1
#define VOICE_L_UP_PGA_ZERO_NUM_OFFSET            2
#define VOICE_L_UP_PGA_ZERO_NUM_LEN               5
#define VOICE_L_UP_PGA_THRE_ID_OFFSET             7
#define VOICE_L_UP_PGA_THRE_ID_LEN                2
#define VOICE_L_UP_PGA_NOISE_EN_OFFSET            9
#define VOICE_L_UP_PGA_NOISE_EN_LEN               1
#define VOICE_L_UP_PGA_BYPASS_OFFSET              10
#define VOICE_L_UP_PGA_BYPASS_LEN                 1
#define VOICE_L_UP_PGA_FADE_OUT_OFFSET            11
#define VOICE_L_UP_PGA_FADE_OUT_LEN               5
#define VOICE_L_UP_PGA_FADE_IN_OFFSET             16
#define VOICE_L_UP_PGA_FADE_IN_LEN                5
#define VOICE_L_UP_PGA_CFG_OFFSET                 21
#define VOICE_L_UP_PGA_CFG_LEN                    3
#define VOICE_L_UP_PGA_GAIN_OFFSET                24
#define VOICE_L_UP_PGA_GAIN_LEN                   8

#define VOICE_R_UP_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x7C)
#define VOICE_R_UP_PGA_LINEAR_SEL_OFFSET          1
#define VOICE_R_UP_PGA_LINEAR_SEL_LEN             1
#define VOICE_R_UP_PGA_ZERO_NUM_OFFSET            2
#define VOICE_R_UP_PGA_ZERO_NUM_LEN               5
#define VOICE_R_UP_PGA_THRE_ID_OFFSET             7
#define VOICE_R_UP_PGA_THRE_ID_LEN                2
#define VOICE_R_UP_PGA_NOISE_EN_OFFSET            9
#define VOICE_R_UP_PGA_NOISE_EN_LEN               1
#define VOICE_R_UP_PGA_BYPASS_OFFSET              10
#define VOICE_R_UP_PGA_BYPASS_LEN                 1
#define VOICE_R_UP_PGA_FADE_OUT_OFFSET            11
#define VOICE_R_UP_PGA_FADE_OUT_LEN               5
#define VOICE_R_UP_PGA_FADE_IN_OFFSET             16
#define VOICE_R_UP_PGA_FADE_IN_LEN                5
#define VOICE_R_UP_PGA_CFG_OFFSET                 21
#define VOICE_R_UP_PGA_CFG_LEN                    3
#define VOICE_R_UP_PGA_GAIN_OFFSET                24
#define VOICE_R_UP_PGA_GAIN_LEN                   8

#define MIC3_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0x80)    /* store:MIC3, CHS:MIC2 */
#define MIC2_UP_PGA_LINEAR_SEL_OFFSET             1
#define MIC2_UP_PGA_LINEAR_SEL_LEN                1
#define MIC2_UP_PGA_ZERO_NUM_OFFSET               2
#define MIC2_UP_PGA_ZERO_NUM_LEN                  5
#define MIC2_UP_PGA_THRE_ID_OFFSET                7
#define MIC2_UP_PGA_THRE_ID_LEN                   2
#define MIC2_UP_PGA_NOISE_EN_OFFSET               9
#define MIC2_UP_PGA_NOISE_EN_LEN                  1
#define MIC3_UP_PGA_BYPASS_OFFSET                 10    /* store:MIC3_UP_PGA, CHS:MIC2_UP_PGA */
#define MIC3_UP_PGA_BYPASS_LEN                    1
#define MIC2_UP_PGA_FADE_OUT_OFFSET               11
#define MIC2_UP_PGA_FADE_OUT_LEN                  5
#define MIC2_UP_PGA_FADE_IN_OFFSET                16
#define MIC2_UP_PGA_FADE_IN_LEN                   5
#define MIC2_UP_PGA_CFG_OFFSET                    21
#define MIC2_UP_PGA_CFG_LEN                       3
#define MIC3_UP_PGA_GAIN_OFFSET                   24    /* store:MIC3_UP_PGA, CHS:MIC2_UP_PGA */
#define MIC3_UP_PGA_GAIN_LEN                      8

#define MIC4_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0x84)    /* store:MIC4, CHS:MIC3 */
#define MIC3_UP_PGA_LINEAR_SEL_OFFSET             1
#define MIC3_UP_PGA_LINEAR_SEL_LEN                1
#define MIC3_UP_PGA_ZERO_NUM_OFFSET               2
#define MIC3_UP_PGA_ZERO_NUM_LEN                  5
#define MIC3_UP_PGA_THRE_ID_OFFSET                7
#define MIC3_UP_PGA_THRE_ID_LEN                   2
#define MIC3_UP_PGA_NOISE_EN_OFFSET               9
#define MIC3_UP_PGA_NOISE_EN_LEN                  1
#define MIC4_UP_PGA_BYPASS_OFFSET                 10    /* store:MIC4_UP_PGA, CHS:MIC3_UP_PGA */
#define MIC4_UP_PGA_BYPASS_LEN                    1
#define MIC3_UP_PGA_FADE_OUT_OFFSET               11
#define MIC3_UP_PGA_FADE_OUT_LEN                  5
#define MIC3_UP_PGA_FADE_IN_OFFSET                16
#define MIC3_UP_PGA_FADE_IN_LEN                   5
#define MIC3_UP_PGA_CFG_OFFSET                    21
#define MIC3_UP_PGA_CFG_LEN                       3
#define MIC4_UP_PGA_GAIN_OFFSET                   24    /* store:MIC4_UP_PGA, CHS:MIC3_UP_PGA */
#define MIC4_UP_PGA_GAIN_LEN                      8

#define MIC5_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0x88)    /* store:MIC5, CHS:MIC4 */
#define MIC4_UP_PGA_LINEAR_SEL_OFFSET             1
#define MIC4_UP_PGA_LINEAR_SEL_LEN                1
#define MIC4_UP_PGA_ZERO_NUM_OFFSET               2
#define MIC4_UP_PGA_ZERO_NUM_LEN                  5
#define MIC4_UP_PGA_THRE_ID_OFFSET                7
#define MIC4_UP_PGA_THRE_ID_LEN                   2
#define MIC4_UP_PGA_NOISE_EN_OFFSET               9
#define MIC4_UP_PGA_NOISE_EN_LEN                  1
#define MIC5_UP_PGA_BYPASS_OFFSET                 10    /* store:MIC5_UP_PGA, CHS:MIC4_UP_PGA */
#define MIC5_UP_PGA_BYPASS_LEN                    1
#define MIC4_UP_PGA_FADE_OUT_OFFSET               11
#define MIC4_UP_PGA_FADE_OUT_LEN                  5
#define MIC4_UP_PGA_FADE_IN_OFFSET                16
#define MIC4_UP_PGA_FADE_IN_LEN                   5
#define MIC4_UP_PGA_CFG_OFFSET                    21
#define MIC4_UP_PGA_CFG_LEN                       3
#define MIC5_UP_PGA_GAIN_OFFSET                   24    /* store:MIC5_UP_PGA, CHS:MIC4_UP_PGA */
#define MIC5_UP_PGA_GAIN_LEN                      8

#define MIC6_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0x8C)    /* store:MIC6, CHS:MIC5 */
#define MIC5_UP_PGA_LINEAR_SEL_OFFSET             1
#define MIC5_UP_PGA_LINEAR_SEL_LEN                1
#define MIC5_UP_PGA_ZERO_NUM_OFFSET               2
#define MIC5_UP_PGA_ZERO_NUM_LEN                  5
#define MIC5_UP_PGA_THRE_ID_OFFSET                7
#define MIC5_UP_PGA_THRE_ID_LEN                   2
#define MIC5_UP_PGA_NOISE_EN_OFFSET               9
#define MIC5_UP_PGA_NOISE_EN_LEN                  1
#define MIC6_UP_PGA_BYPASS_OFFSET                 10    /* store:MIC6_UP_PGA, CHS:MIC5_UP_PGA */
#define MIC6_UP_PGA_BYPASS_LEN                    1
#define MIC5_UP_PGA_FADE_OUT_OFFSET               11
#define MIC5_UP_PGA_FADE_OUT_LEN                  5
#define MIC5_UP_PGA_FADE_IN_OFFSET                16
#define MIC5_UP_PGA_FADE_IN_LEN                   5
#define MIC5_UP_PGA_CFG_OFFSET                    21
#define MIC5_UP_PGA_CFG_LEN                       3
#define MIC6_UP_PGA_GAIN_OFFSET                   24    /* store:MIC6_UP_PGA, CHS:MIC5_UP_PGA */
#define MIC6_UP_PGA_GAIN_LEN                      8

#define MIC7_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0x90)    /* NSV:MIC7, CHS:MIC6 */
#define MIC6_UP_PGA_LINEAR_SEL_OFFSET             1
#define MIC6_UP_PGA_LINEAR_SEL_LEN                1
#define MIC6_UP_PGA_ZERO_NUM_OFFSET               2
#define MIC6_UP_PGA_ZERO_NUM_LEN                  5
#define MIC6_UP_PGA_THRE_ID_OFFSET                7
#define MIC6_UP_PGA_THRE_ID_LEN                   2
#define MIC6_UP_PGA_NOISE_EN_OFFSET               9
#define MIC6_UP_PGA_NOISE_EN_LEN                  1
#define MIC7_UP_PGA_BYPASS_OFFSET                 10    /* store:MIC7_UP_PGA, CHS:MIC6_UP_PGA */
#define MIC7_UP_PGA_BYPASS_LEN                    1
#define MIC6_UP_PGA_FADE_OUT_OFFSET               11
#define MIC6_UP_PGA_FADE_OUT_LEN                  5
#define MIC6_UP_PGA_FADE_IN_OFFSET                16
#define MIC6_UP_PGA_FADE_IN_LEN                   5
#define MIC6_UP_PGA_CFG_OFFSET                    21
#define MIC6_UP_PGA_CFG_LEN                       3
#define MIC7_UP_PGA_GAIN_OFFSET                   24    /* store:MIC7_UP_PGA, CHS:MIC6_UP_PGA */
#define MIC7_UP_PGA_GAIN_LEN                      8

#define MIC8_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0x94)    /* NSV:MIC8, CHS:MIC7 */
#define MIC7_UP_PGA_LINEAR_SEL_OFFSET             1
#define MIC7_UP_PGA_LINEAR_SEL_LEN                1
#define MIC7_UP_PGA_ZERO_NUM_OFFSET               2
#define MIC7_UP_PGA_ZERO_NUM_LEN                  5
#define MIC7_UP_PGA_THRE_ID_OFFSET                7
#define MIC7_UP_PGA_THRE_ID_LEN                   2
#define MIC7_UP_PGA_NOISE_EN_OFFSET               9
#define MIC7_UP_PGA_NOISE_EN_LEN                  1
#define MIC8_UP_PGA_BYPASS_OFFSET                 10    /* store:MIC8_UP_PGA, CHS:MIC7_UP_PGA */
#define MIC8_UP_PGA_BYPASS_LEN                    1
#define MIC7_UP_PGA_FADE_OUT_OFFSET               11
#define MIC7_UP_PGA_FADE_OUT_LEN                  5
#define MIC7_UP_PGA_FADE_IN_OFFSET                16
#define MIC7_UP_PGA_FADE_IN_LEN                   5
#define MIC7_UP_PGA_CFG_OFFSET                    21
#define MIC7_UP_PGA_CFG_LEN                       3
#define MIC8_UP_PGA_GAIN_OFFSET                   24    /* store:MIC8_UP_PGA, CHS:MIC7_UP_PGA */
#define MIC8_UP_PGA_GAIN_LEN                      8

#define I2S1_L_RX_PGA_CTRL_REG   (PAGE_SOCCODEC + 0x98)
#define I2S1_L_RX_PGA_LINEAR_SEL_OFFSET           1
#define I2S1_L_RX_PGA_LINEAR_SEL_LEN              1
#define I2S1_L_RX_PGA_ZERO_NUM_OFFSET             2
#define I2S1_L_RX_PGA_ZERO_NUM_LEN                5
#define I2S1_L_RX_PGA_THRE_ID_OFFSET              7
#define I2S1_L_RX_PGA_THRE_ID_LEN                 2
#define I2S1_L_RX_PGA_NOISE_EN_OFFSET             9
#define I2S1_L_RX_PGA_NOISE_EN_LEN                1
#define I2S1_L_RX_PGA_BYPASS_OFFSET               10
#define I2S1_L_RX_PGA_BYPASS_LEN                  1
#define I2S1_L_RX_PGA_FADE_OUT_OFFSET             11
#define I2S1_L_RX_PGA_FADE_OUT_LEN                5
#define I2S1_L_RX_PGA_FADE_IN_OFFSET              16
#define I2S1_L_RX_PGA_FADE_IN_LEN                 5
#define I2S1_L_RX_PGA_CFG_OFFSET                  21
#define I2S1_L_RX_PGA_CFG_LEN                     3
#define I2S1_L_RX_PGA_GAIN_OFFSET                 24
#define I2S1_L_RX_PGA_GAIN_LEN                    8

#define I2S1_R_RX_PGA_CTRL_REG   (PAGE_SOCCODEC + 0x9C)
#define I2S1_R_RX_PGA_LINEAR_SEL_OFFSET           1
#define I2S1_R_RX_PGA_LINEAR_SEL_LEN              1
#define I2S1_R_RX_PGA_ZERO_NUM_OFFSET             2
#define I2S1_R_RX_PGA_ZERO_NUM_LEN                5
#define I2S1_R_RX_PGA_THRE_ID_OFFSET              7
#define I2S1_R_RX_PGA_THRE_ID_LEN                 2
#define I2S1_R_RX_PGA_NOISE_EN_OFFSET             9
#define I2S1_R_RX_PGA_NOISE_EN_LEN                1
#define I2S1_R_RX_PGA_BYPASS_OFFSET               10
#define I2S1_R_RX_PGA_BYPASS_LEN                  1
#define I2S1_R_RX_PGA_FADE_OUT_OFFSET             11
#define I2S1_R_RX_PGA_FADE_OUT_LEN                5
#define I2S1_R_RX_PGA_FADE_IN_OFFSET              16
#define I2S1_R_RX_PGA_FADE_IN_LEN                 5
#define I2S1_R_RX_PGA_CFG_OFFSET                  21
#define I2S1_R_RX_PGA_CFG_LEN                     3
#define I2S1_R_RX_PGA_GAIN_OFFSET                 24
#define I2S1_R_RX_PGA_GAIN_LEN                    8

#define ULTR_DN_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xA0)
#define ULTR_DN_PGA_LINEAR_SEL_OFFSET             1
#define ULTR_DN_PGA_LINEAR_SEL_LEN                1
#define ULTR_DN_PGA_ZERO_NUM_OFFSET               2
#define ULTR_DN_PGA_ZERO_NUM_LEN                  5
#define ULTR_DN_PGA_THRE_ID_OFFSET                7
#define ULTR_DN_PGA_THRE_ID_LEN                   2
#define ULTR_DN_PGA_NOISE_EN_OFFSET               9
#define ULTR_DN_PGA_NOISE_EN_LEN                  1
#define ULTR_DN_PGA_BYPASS_OFFSET                 10
#define ULTR_DN_PGA_BYPASS_LEN                    1
#define ULTR_DN_PGA_FADE_OUT_OFFSET               11
#define ULTR_DN_PGA_FADE_OUT_LEN                  5
#define ULTR_DN_PGA_FADE_IN_OFFSET                16
#define ULTR_DN_PGA_FADE_IN_LEN                   5
#define ULTR_DN_PGA_CFG_OFFSET                    21
#define ULTR_DN_PGA_CFG_LEN                       3
#define ULTR_DN_PGA_GAIN_OFFSET                   24
#define ULTR_DN_PGA_GAIN_LEN                      8

#define AUDIOZOOM_PGA_CTRL_REG   (PAGE_SOCCODEC + 0xA4)

#define NOISE_METER_PGA_CTRL_REG (PAGE_SOCCODEC + 0xA8)

#define ADC0_PGA_GAIN_OFFSET_REG (PAGE_SOCCODEC + 0xAC)
#define ADC0_PGA_GAIN_OFFSET_OFFSET               0
#define ADC0_PGA_GAIN_OFFSET_LEN                  8
#define ADC1_PGA_GAIN_OFFSET_OFFSET               8
#define ADC1_PGA_GAIN_OFFSET_LEN                  8
#define ADC2_PGA_GAIN_OFFSET_OFFSET               16
#define ADC2_PGA_GAIN_OFFSET_LEN                  8
#define ADC3_PGA_GAIN_OFFSET_OFFSET               24
#define ADC3_PGA_GAIN_OFFSET_LEN                  8

#define ADC1_PGA_GAIN_OFFSET_REG (PAGE_SOCCODEC + 0xB0)
#define ADC4_PGA_GAIN_OFFSET_OFFSET               0
#define ADC4_PGA_GAIN_OFFSET_LEN                  8
#define ADC5_PGA_GAIN_OFFSET_OFFSET               8
#define ADC5_PGA_GAIN_OFFSET_LEN                  8
#define ADC6_PGA_GAIN_OFFSET_OFFSET               16
#define ADC6_PGA_GAIN_OFFSET_LEN                  8
#define ADC7_PGA_GAIN_OFFSET_OFFSET               24
#define ADC7_PGA_GAIN_OFFSET_LEN                  8

#define ADC1_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xB4)    /* store:AD1, CHS:ADC0 */
#define ADC0_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC0_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC0_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC0_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC0_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC0_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC0_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC0_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC0_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC0_UP_PGA_0P5_BYPASS_LEN                1
#define ADC0_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC0_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC0_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC0_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC0_UP_PGA_0P5_CFG_OFFSET                21
#define ADC0_UP_PGA_0P5_CFG_LEN                   3
#define ADC0_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC0_UP_PGA_0P5_GAIN_LEN                  8

#define ADC2_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xB8)    /* store:AD2, CHS:ADC1 */
#define ADC1_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC1_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC1_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC1_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC1_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC1_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC1_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC1_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC1_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC1_UP_PGA_0P5_BYPASS_LEN                1
#define ADC1_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC1_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC1_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC1_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC1_UP_PGA_0P5_CFG_OFFSET                21
#define ADC1_UP_PGA_0P5_CFG_LEN                   3
#define ADC1_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC1_UP_PGA_0P5_GAIN_LEN                  8

#define ADC3_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xBC)    /* store:AD3, CHS:ADC2 */
#define ADC2_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC2_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC2_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC2_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC2_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC2_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC2_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC2_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC2_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC2_UP_PGA_0P5_BYPASS_LEN                1
#define ADC2_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC2_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC2_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC2_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC2_UP_PGA_0P5_CFG_OFFSET                21
#define ADC2_UP_PGA_0P5_CFG_LEN                   3
#define ADC2_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC2_UP_PGA_0P5_GAIN_LEN                  8

#define ADC4_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xC0)    /* store:AD4, CHS:ADC3 */
#define ADC3_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC3_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC3_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC3_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC3_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC3_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC3_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC3_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC3_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC3_UP_PGA_0P5_BYPASS_LEN                1
#define ADC3_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC3_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC3_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC3_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC3_UP_PGA_0P5_CFG_OFFSET                21
#define ADC3_UP_PGA_0P5_CFG_LEN                   3
#define ADC3_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC3_UP_PGA_0P5_GAIN_LEN                  8

#define ADC5_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xC4)    /* store:AD5, CHS:ADC4 */
#define ADC4_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC4_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC4_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC4_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC4_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC4_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC4_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC4_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC4_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC4_UP_PGA_0P5_BYPASS_LEN                1
#define ADC4_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC4_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC4_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC4_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC4_UP_PGA_0P5_CFG_OFFSET                21
#define ADC4_UP_PGA_0P5_CFG_LEN                   3
#define ADC4_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC4_UP_PGA_0P5_GAIN_LEN                  8

#define ADC6_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xC8)    /* store:AD6, CHS:ADC5 */
#define ADC5_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC5_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC5_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC5_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC5_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC5_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC5_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC5_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC5_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC5_UP_PGA_0P5_BYPASS_LEN                1
#define ADC5_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC5_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC5_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC5_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC5_UP_PGA_0P5_CFG_OFFSET                21
#define ADC5_UP_PGA_0P5_CFG_LEN                   3
#define ADC5_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC5_UP_PGA_0P5_GAIN_LEN                  8

#define ADC7_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xCC)    /* store:AD7, CHS:ADC6 */
#define ADC6_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC6_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC6_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC6_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC6_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC6_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC6_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC6_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC6_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC6_UP_PGA_0P5_BYPASS_LEN                1
#define ADC6_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC6_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC6_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC6_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC6_UP_PGA_0P5_CFG_OFFSET                21
#define ADC6_UP_PGA_0P5_CFG_LEN                   3
#define ADC6_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC6_UP_PGA_0P5_GAIN_LEN                  8

#define ADC8_UP_PGA_CTRL_REG     (PAGE_SOCCODEC + 0xD0)    /* store:AD8, CHS:ADC7 */
#define ADC7_UP_PGA_0P5_LINEAR_SEL_OFFSET         1
#define ADC7_UP_PGA_0P5_LINEAR_SEL_LEN            1
#define ADC7_UP_PGA_0P5_ZERO_NUM_OFFSET           2
#define ADC7_UP_PGA_0P5_ZERO_NUM_LEN              5
#define ADC7_UP_PGA_0P5_THRE_ID_OFFSET            7
#define ADC7_UP_PGA_0P5_THRE_ID_LEN               2
#define ADC7_UP_PGA_0P5_NOISE_EN_OFFSET           9
#define ADC7_UP_PGA_0P5_NOISE_EN_LEN              1
#define ADC7_UP_PGA_0P5_BYPASS_OFFSET             10
#define ADC7_UP_PGA_0P5_BYPASS_LEN                1
#define ADC7_UP_PGA_0P5_FADE_OUT_OFFSET           11
#define ADC7_UP_PGA_0P5_FADE_OUT_LEN              5
#define ADC7_UP_PGA_0P5_FADE_IN_OFFSET            16
#define ADC7_UP_PGA_0P5_FADE_IN_LEN               5
#define ADC7_UP_PGA_0P5_CFG_OFFSET                21
#define ADC7_UP_PGA_0P5_CFG_LEN                   3
#define ADC7_UP_PGA_0P5_GAIN_OFFSET               24
#define ADC7_UP_PGA_0P5_GAIN_LEN                  8

#define SRCUP_CTRL0_REG          (PAGE_SOCCODEC + 0xD4)
#define CODEC_0_DN_SRCUP_SRC_MODE_OFFSET          0
#define CODEC_0_DN_SRCUP_SRC_MODE_LEN             3
#define CODEC_0_DN_SRCUP_FIFO_CLR_OFFSET          3
#define CODEC_0_DN_SRCUP_FIFO_CLR_LEN             1
#define CODEC_1_DN_SRCUP_SRC_MODE_OFFSET          4
#define CODEC_1_DN_SRCUP_SRC_MODE_LEN             3
#define CODEC_1_DN_SRCUP_FIFO_CLR_OFFSET          7
#define CODEC_1_DN_SRCUP_FIFO_CLR_LEN             1
#define CODEC_2_DN_SRCUP_SRC_MODE_OFFSET          8
#define CODEC_2_DN_SRCUP_SRC_MODE_LEN             3
#define CODEC_2_DN_SRCUP_FIFO_CLR_OFFSET          11
#define CODEC_2_DN_SRCUP_FIFO_CLR_LEN             1
#define AUDIO_0_DN_SRCUP_SRC_MODE_OFFSET          12
#define AUDIO_0_DN_SRCUP_SRC_MODE_LEN             3
#define AUDIO_0_DN_SRCUP_FIFO_CLR_OFFSET          15
#define AUDIO_0_DN_SRCUP_FIFO_CLR_LEN             1
#define AUDIO_1_SRCUP_SRC_MODE_OFFSET             16
#define AUDIO_1_SRCUP_SRC_MODE_LEN                3
#define AUDIO_1_UP_SRCUP_FIFO_CLR_OFFSET          19
#define AUDIO_1_UP_SRCUP_FIFO_CLR_LEN             1
#define AUDIO_2_SRCUP_SRC_MODE_OFFSET             20
#define AUDIO_2_SRCUP_SRC_MODE_LEN                3
#define AUDIO_2_UP_SRCUP_FIFO_CLR_OFFSET          23
#define AUDIO_2_UP_SRCUP_FIFO_CLR_LEN             1
#define DACL_MIXER4_SRCUP_SRC_MODE_OFFSET         24
#define DACL_MIXER4_SRCUP_SRC_MODE_LEN            3
#define DACL_MIXER4_SRCUP_FIFO_CLR_OFFSET         27
#define DACL_MIXER4_SRCUP_FIFO_CLR_LEN            1
#define DACR_MIXER4_SRCUP_SRC_MODE_OFFSET         28
#define DACR_MIXER4_SRCUP_SRC_MODE_LEN            3
#define DACR_MIXER4_SRCUP_FIFO_CLR_OFFSET         31
#define DACR_MIXER4_SRCUP_FIFO_CLR_LEN            1

#define SRCUP_CTRL1_REG          (PAGE_SOCCODEC + 0xD8)
#define ULTR_DN_SRCUP_SRC_MODE_OFFSET             0
#define ULTR_DN_SRCUP_SRC_MODE_LEN                3
#define ULTR_DN_SRCUP_FIFO_CLR_OFFSET             3
#define ULTR_DN_SRCUP_FIFO_CLR_LEN                1
#define I2S1_RX_L_SRCUP_SRC_MODE_OFFSET           4
#define I2S1_RX_L_SRCUP_SRC_MODE_LEN              3
#define I2S1_RX_L_SRCUP_FIFO_CLR_OFFSET           7
#define I2S1_RX_L_SRCUP_FIFO_CLR_LEN              1
#define I2S1_RX_R_SRCUP_SRC_MODE_OFFSET           8
#define I2S1_RX_R_SRCUP_SRC_MODE_LEN              3
#define I2S1_RX_R_SRCUP_FIFO_CLR_OFFSET           11
#define I2S1_RX_R_SRCUP_FIFO_CLR_LEN              1

#define SRCDN_CTRL0_REG          (PAGE_SOCCODEC + 0xDC)
#define AUDIO_L_UP_SRCDN_SRC_MODE_OFFSET          0
#define AUDIO_L_UP_SRCDN_SRC_MODE_LEN             3
#define AUDIO_L_UP_SRCDN_FIFO_CLR_OFFSET          3
#define AUDIO_L_UP_SRCDN_FIFO_CLR_LEN             1
#define AUDIO_R_UP_SRCDN_SRC_MODE_OFFSET          4
#define AUDIO_R_UP_SRCDN_SRC_MODE_LEN             3
#define AUDIO_R_UP_SRCDN_FIFO_CLR_OFFSET          7
#define AUDIO_R_UP_SRCDN_FIFO_CLR_LEN             1
#define VOICE_L_UP_SRCDN_SRC_MODE_OFFSET          8
#define VOICE_L_UP_SRCDN_SRC_MODE_LEN             3
#define VOICE_L_UP_SRCDN_FIFO_CLR_OFFSET          11
#define VOICE_L_UP_SRCDN_FIFO_CLR_LEN             1
#define VOICE_R_UP_SRCDN_SRC_MODE_OFFSET          12
#define VOICE_R_UP_SRCDN_SRC_MODE_LEN             3
#define VOICE_R_UP_SRCDN_FIFO_CLR_OFFSET          15
#define VOICE_R_UP_SRCDN_FIFO_CLR_LEN             1
#define MIC3_UP_SRCDN_SRC_MODE_OFFSET             16    /* store:MIC3_UP, CHS:MIC3_UP */
#define MIC3_UP_SRCDN_SRC_MODE_LEN                3
#define MIC2_UP_SRCDN_FIFO_CLR_OFFSET             19
#define MIC2_UP_SRCDN_FIFO_CLR_LEN                1
#define MIC4_UP_SRCDN_SRC_MODE_OFFSET             20    /* store:MIC4_UP, CHS:MIC3_UP */
#define MIC4_UP_SRCDN_SRC_MODE_LEN                3
#define MIC3_UP_SRCDN_FIFO_CLR_OFFSET             23
#define MIC3_UP_SRCDN_FIFO_CLR_LEN                1
#define MIC5_UP_SRCDN_SRC_MODE_OFFSET             24    /* store:MIC5_UP, CHS:MIC4_UP */
#define MIC5_UP_SRCDN_SRC_MODE_LEN                3
#define MIC4_UP_SRCDN_FIFO_CLR_OFFSET             27
#define MIC4_UP_SRCDN_FIFO_CLR_LEN                1
#define MIC6_UP_SRCDN_SRC_MODE_OFFSET             28    /* store:MIC6_UP, CHS:MIC5_UP */
#define MIC6_UP_SRCDN_SRC_MODE_LEN                3
#define MIC5_UP_SRCDN_FIFO_CLR_OFFSET             31
#define MIC5_UP_SRCDN_FIFO_CLR_LEN                1

#define SRCDN_CTRL1_REG          (PAGE_SOCCODEC + 0xE0)
#define I2S1_RX_L_SRCDN_SRC_MODE_OFFSET           0
#define I2S1_RX_L_SRCDN_SRC_MODE_LEN              3
#define I2S1_RX_L_SRCDN_FIFO_CLR_OFFSET           3
#define I2S1_RX_L_SRCDN_FIFO_CLR_LEN              1
#define I2S1_RX_R_SRCDN_SRC_MODE_OFFSET           4
#define I2S1_RX_R_SRCDN_SRC_MODE_LEN              3
#define I2S1_RX_R_SRCDN_FIFO_CLR_OFFSET           7
#define I2S1_RX_R_SRCDN_FIFO_CLR_LEN              1
#define I2S1_TX_L_SRCDN_SRC_MODE_OFFSET           8
#define I2S1_TX_L_SRCDN_SRC_MODE_LEN              3
#define I2S1_TX_L_SRCDN_FIFO_CLR_OFFSET           11
#define I2S1_TX_L_SRCDN_FIFO_CLR_LEN              1
#define I2S1_TX_R_SRCDN_SRC_MODE_OFFSET           12
#define I2S1_TX_R_SRCDN_SRC_MODE_LEN              3
#define I2S1_TX_R_SRCDN_FIFO_CLR_OFFSET           15
#define I2S1_TX_R_SRCDN_FIFO_CLR_LEN              1
#define MIC7_UP_SRCDN_SRC_MODE_OFFSET             24    /* store:MIC7_UP, CHS:MIC6_UP */
#define MIC7_UP_SRCDN_SRC_MODE_LEN                3
#define MIC6_UP_SRCDN_FIFO_CLR_OFFSET             27
#define MIC6_UP_SRCDN_FIFO_CLR_LEN                1
#define MIC8_UP_SRCDN_SRC_MODE_OFFSET             28    /* store:MIC8_UP, CHS:MIC7_UP */
#define MIC8_UP_SRCDN_SRC_MODE_LEN                3
#define MIC7_UP_SRCDN_FIFO_CLR_OFFSET             31
#define MIC7_UP_SRCDN_FIFO_CLR_LEN                1

#define SPA0_MIXER4_CTRL0_REG    (PAGE_SOCCODEC + 0xE4)
#define SPA0_MIXER4_GAIN1_OFFSET                  12
#define SPA0_MIXER4_GAIN1_LEN                     2
#define SPA0_MIXER4_GAIN2_OFFSET                  14
#define SPA0_MIXER4_GAIN2_LEN                     2
#define SPA0_MIXER4_GAIN3_OFFSET                  16
#define SPA0_MIXER4_GAIN3_LEN                     2
#define SPA0_MIXER4_GAIN4_OFFSET                  18
#define SPA0_MIXER4_GAIN4_LEN                     2
#define SPA0_MIXER4_IN1_MUTE_OFFSET               20
#define SPA0_MIXER4_IN1_MUTE_LEN                  1
#define SPA0_MIXER4_IN2_MUTE_OFFSET               21
#define SPA0_MIXER4_IN2_MUTE_LEN                  1
#define SPA0_MIXER4_IN3_MUTE_OFFSET               22
#define SPA0_MIXER4_IN3_MUTE_LEN                  1
#define SPA0_MIXER4_IN4_MUTE_OFFSET               23
#define SPA0_MIXER4_IN4_MUTE_LEN                  1
#define SPA0_MIXER4_IN1_ID_OFFSET                 24
#define SPA0_MIXER4_IN1_ID_LEN                    2
#define SPA0_MIXER4_IN2_ID_OFFSET                 26
#define SPA0_MIXER4_IN2_ID_LEN                    2
#define SPA0_MIXER4_IN3_ID_OFFSET                 28
#define SPA0_MIXER4_IN3_ID_LEN                    2
#define SPA0_MIXER4_IN4_ID_OFFSET                 30
#define SPA0_MIXER4_IN4_ID_LEN                    2

#define SPA0_MIXER4_CTRL1_REG    (PAGE_SOCCODEC + 0xE8)
#define SPA0_MIXER4_ZERO_NUM_OFFSET               16
#define SPA0_MIXER4_ZERO_NUM_LEN                  5
#define SPA0_MIXER4_FADE_OUT_OFFSET               21
#define SPA0_MIXER4_FADE_OUT_LEN                  5
#define SPA0_MIXER4_FADE_IN_OFFSET                26
#define SPA0_MIXER4_FADE_IN_LEN                   5
#define SPA0_MIXER4_FADE_EN_OFFSET                31
#define SPA0_MIXER4_FADE_EN_LEN                   1

#define SPA1_MIXER4_CTRL0_REG    (PAGE_SOCCODEC + 0xEC)
#define SPA1_MIXER4_GAIN1_OFFSET                  12
#define SPA1_MIXER4_GAIN1_LEN                     2
#define SPA1_MIXER4_GAIN2_OFFSET                  14
#define SPA1_MIXER4_GAIN2_LEN                     2
#define SPA1_MIXER4_GAIN3_OFFSET                  16
#define SPA1_MIXER4_GAIN3_LEN                     2
#define SPA1_MIXER4_GAIN4_OFFSET                  18
#define SPA1_MIXER4_GAIN4_LEN                     2
#define SPA1_MIXER4_IN1_MUTE_OFFSET               20
#define SPA1_MIXER4_IN1_MUTE_LEN                  1
#define SPA1_MIXER4_IN2_MUTE_OFFSET               21
#define SPA1_MIXER4_IN2_MUTE_LEN                  1
#define SPA1_MIXER4_IN3_MUTE_OFFSET               22
#define SPA1_MIXER4_IN3_MUTE_LEN                  1
#define SPA1_MIXER4_IN4_MUTE_OFFSET               23
#define SPA1_MIXER4_IN4_MUTE_LEN                  1
#define SPA1_MIXER4_IN1_ID_OFFSET                 24
#define SPA1_MIXER4_IN1_ID_LEN                    2
#define SPA1_MIXER4_IN2_ID_OFFSET                 26
#define SPA1_MIXER4_IN2_ID_LEN                    2
#define SPA1_MIXER4_IN3_ID_OFFSET                 28
#define SPA1_MIXER4_IN3_ID_LEN                    2
#define SPA1_MIXER4_IN4_ID_OFFSET                 30
#define SPA1_MIXER4_IN4_ID_LEN                    2

#define SPA1_MIXER4_CTRL1_REG    (PAGE_SOCCODEC + 0xF0)
#define SPA1_MIXER4_ZERO_NUM_OFFSET               16
#define SPA1_MIXER4_ZERO_NUM_LEN                  5
#define SPA1_MIXER4_FADE_OUT_OFFSET               21
#define SPA1_MIXER4_FADE_OUT_LEN                  5
#define SPA1_MIXER4_FADE_IN_OFFSET                26
#define SPA1_MIXER4_FADE_IN_LEN                   5
#define SPA1_MIXER4_FADE_EN_OFFSET                31
#define SPA1_MIXER4_FADE_EN_LEN                   1

#define SPA2_MIXER4_CTRL0_REG    (PAGE_SOCCODEC + 0xF4)
#define SPA2_MIXER4_GAIN1_OFFSET                  12
#define SPA2_MIXER4_GAIN1_LEN                     2
#define SPA2_MIXER4_GAIN2_OFFSET                  14
#define SPA2_MIXER4_GAIN2_LEN                     2
#define SPA2_MIXER4_GAIN3_OFFSET                  16
#define SPA2_MIXER4_GAIN3_LEN                     2
#define SPA2_MIXER4_GAIN4_OFFSET                  18
#define SPA2_MIXER4_GAIN4_LEN                     2
#define SPA2_MIXER4_IN1_MUTE_OFFSET               20
#define SPA2_MIXER4_IN1_MUTE_LEN                  1
#define SPA2_MIXER4_IN2_MUTE_OFFSET               21
#define SPA2_MIXER4_IN2_MUTE_LEN                  1
#define SPA2_MIXER4_IN3_MUTE_OFFSET               22
#define SPA2_MIXER4_IN3_MUTE_LEN                  1
#define SPA2_MIXER4_IN4_MUTE_OFFSET               23
#define SPA2_MIXER4_IN4_MUTE_LEN                  1
#define SPA2_MIXER4_IN1_ID_OFFSET                 24
#define SPA2_MIXER4_IN1_ID_LEN                    2
#define SPA2_MIXER4_IN2_ID_OFFSET                 26
#define SPA2_MIXER4_IN2_ID_LEN                    2
#define SPA2_MIXER4_IN3_ID_OFFSET                 28
#define SPA2_MIXER4_IN3_ID_LEN                    2
#define SPA2_MIXER4_IN4_ID_OFFSET                 30
#define SPA2_MIXER4_IN4_ID_LEN                    2

#define SPA2_MIXER4_CTRL1_REG    (PAGE_SOCCODEC + 0xF8)
#define SPA2_MIXER4_ZERO_NUM_OFFSET               16
#define SPA2_MIXER4_ZERO_NUM_LEN                  5
#define SPA2_MIXER4_FADE_OUT_OFFSET               21
#define SPA2_MIXER4_FADE_OUT_LEN                  5
#define SPA2_MIXER4_FADE_IN_OFFSET                26
#define SPA2_MIXER4_FADE_IN_LEN                   5
#define SPA2_MIXER4_FADE_EN_OFFSET                31
#define SPA2_MIXER4_FADE_EN_LEN                   1

#define I2S1_TX_MIXER2_CTRL_REG  (PAGE_SOCCODEC + 0xFC)
#define I2S1_TX_MIXER2_ZERO_NUM_OFFSET            6
#define I2S1_TX_MIXER2_ZERO_NUM_LEN               5
#define I2S1_TX_MIXER2_FADE_OUT_OFFSET            11
#define I2S1_TX_MIXER2_FADE_OUT_LEN               5
#define I2S1_TX_MIXER2_FADE_IN_OFFSET             16
#define I2S1_TX_MIXER2_FADE_IN_LEN                5
#define I2S1_TX_MIXER2_FADE_EN_OFFSET             21
#define I2S1_TX_MIXER2_FADE_EN_LEN                1
#define I2S1_TX_MIXER2_GAIN1_OFFSET               22
#define I2S1_TX_MIXER2_GAIN1_LEN                  2
#define I2S1_TX_MIXER2_GAIN2_OFFSET               24
#define I2S1_TX_MIXER2_GAIN2_LEN                  2
#define I2S1_TX_MIXER2_IN1_MUTE_OFFSET            26
#define I2S1_TX_MIXER2_IN1_MUTE_LEN               1
#define I2S1_TX_MIXER2_IN2_MUTE_OFFSET            27
#define I2S1_TX_MIXER2_IN2_MUTE_LEN               1
#define I2S1_TX_MIXER2_IN1_ID_OFFSET              28
#define I2S1_TX_MIXER2_IN1_ID_LEN                 2
#define I2S1_TX_MIXER2_IN2_ID_OFFSET              30
#define I2S1_TX_MIXER2_IN2_ID_LEN                 2

#define ULTR0_MIXER2_CTRL_REG    (PAGE_SOCCODEC + 0x100)
#define ULTR0_MIXER2_VLD_SEL_OFFSET               4
#define ULTR0_MIXER2_VLD_SEL_LEN                  1
#define ULTR0_MIXER2_FADE_EN2_OFFSET              5
#define ULTR0_MIXER2_FADE_EN2_LEN                 1
#define ULTR0_MIXER2_ZERO_NUM_OFFSET              6
#define ULTR0_MIXER2_ZERO_NUM_LEN                 5
#define ULTR0_MIXER2_FADE_OUT_OFFSET              11
#define ULTR0_MIXER2_FADE_OUT_LEN                 5
#define ULTR0_MIXER2_FADE_IN_OFFSET               16
#define ULTR0_MIXER2_FADE_IN_LEN                  5
#define ULTR0_MIXER2_FADE_EN1_OFFSET              21
#define ULTR0_MIXER2_FADE_EN1_LEN                 1
#define ULTR0_MIXER2_GAIN1_OFFSET                 22
#define ULTR0_MIXER2_GAIN1_LEN                    2
#define ULTR0_MIXER2_GAIN2_OFFSET                 24
#define ULTR0_MIXER2_GAIN2_LEN                    2
#define ULTR0_MIXER2_IN1_MUTE_OFFSET              26
#define ULTR0_MIXER2_IN1_MUTE_LEN                 1
#define ULTR0_MIXER2_IN2_MUTE_OFFSET              27
#define ULTR0_MIXER2_IN2_MUTE_LEN                 1
#define ULTR0_MIXER2_IN1_ID_OFFSET                28
#define ULTR0_MIXER2_IN1_ID_LEN                   2
#define ULTR0_MIXER2_IN2_ID_OFFSET                30
#define ULTR0_MIXER2_IN2_ID_LEN                   2

#define ULTR1_MIXER2_CTRL_REG    (PAGE_SOCCODEC + 0x104)
#define ULTR1_MIXER2_VLD_SEL_OFFSET               4
#define ULTR1_MIXER2_VLD_SEL_LEN                  1
#define ULTR1_MIXER2_FADE_EN2_OFFSET              5
#define ULTR1_MIXER2_FADE_EN2_LEN                 1
#define ULTR1_MIXER2_ZERO_NUM_OFFSET              6
#define ULTR1_MIXER2_ZERO_NUM_LEN                 5
#define ULTR1_MIXER2_FADE_OUT_OFFSET              11
#define ULTR1_MIXER2_FADE_OUT_LEN                 5
#define ULTR1_MIXER2_FADE_IN_OFFSET               16
#define ULTR1_MIXER2_FADE_IN_LEN                  5
#define ULTR1_MIXER2_FADE_EN1_OFFSET              21
#define ULTR1_MIXER2_FADE_EN1_LEN                 1
#define ULTR1_MIXER2_GAIN1_OFFSET                 22
#define ULTR1_MIXER2_GAIN1_LEN                    2
#define ULTR1_MIXER2_GAIN2_OFFSET                 24
#define ULTR1_MIXER2_GAIN2_LEN                    2
#define ULTR1_MIXER2_IN1_MUTE_OFFSET              26
#define ULTR1_MIXER2_IN1_MUTE_LEN                 1
#define ULTR1_MIXER2_IN2_MUTE_OFFSET              27
#define ULTR1_MIXER2_IN2_MUTE_LEN                 1
#define ULTR1_MIXER2_IN1_ID_OFFSET                28
#define ULTR1_MIXER2_IN1_ID_LEN                   2
#define ULTR1_MIXER2_IN2_ID_OFFSET                30
#define ULTR1_MIXER2_IN2_ID_LEN                   2

#define ULTR2_MIXER2_CTRL_REG    (PAGE_SOCCODEC + 0x108)
#define ULTR2_MIXER2_VLD_SEL_OFFSET               4
#define ULTR2_MIXER2_VLD_SEL_LEN                  1
#define ULTR2_MIXER2_FADE_EN2_OFFSET              5
#define ULTR2_MIXER2_FADE_EN2_LEN                 1
#define ULTR2_MIXER2_ZERO_NUM_OFFSET              6
#define ULTR2_MIXER2_ZERO_NUM_LEN                 5
#define ULTR2_MIXER2_FADE_OUT_OFFSET              11
#define ULTR2_MIXER2_FADE_OUT_LEN                 5
#define ULTR2_MIXER2_FADE_IN_OFFSET               16
#define ULTR2_MIXER2_FADE_IN_LEN                  5
#define ULTR2_MIXER2_FADE_EN1_OFFSET              21
#define ULTR2_MIXER2_FADE_EN1_LEN                 1
#define ULTR2_MIXER2_GAIN1_OFFSET                 22
#define ULTR2_MIXER2_GAIN1_LEN                    2
#define ULTR2_MIXER2_GAIN2_OFFSET                 24
#define ULTR2_MIXER2_GAIN2_LEN                    2
#define ULTR2_MIXER2_IN1_MUTE_OFFSET              26
#define ULTR2_MIXER2_IN1_MUTE_LEN                 1
#define ULTR2_MIXER2_IN2_MUTE_OFFSET              27
#define ULTR2_MIXER2_IN2_MUTE_LEN                 1
#define ULTR2_MIXER2_IN1_ID_OFFSET                28
#define ULTR2_MIXER2_IN1_ID_LEN                   2
#define ULTR2_MIXER2_IN2_ID_OFFSET                30
#define ULTR2_MIXER2_IN2_ID_LEN                   2

#define ADC_FILTER_CTRL0_REG     (PAGE_SOCCODEC + 0x10C)
#define ADC7_CIC_GAIN_OFFSET                      4
#define ADC7_CIC_GAIN_LEN                         6
#define ADC6_CIC_GAIN_OFFSET                      10
#define ADC6_CIC_GAIN_LEN                         6
#define ADC5_CIC_GAIN_OFFSET                      20
#define ADC5_CIC_GAIN_LEN                         6
#define ADC4_CIC_GAIN_OFFSET                      26
#define ADC4_CIC_GAIN_LEN                         6

#define ADC_FILTER_CTRL1_REG     (PAGE_SOCCODEC + 0x110)
#define ADC3_CIC_GAIN_OFFSET                      4
#define ADC3_CIC_GAIN_LEN                         6
#define ADC2_CIC_GAIN_OFFSET                      10
#define ADC2_CIC_GAIN_LEN                         6
#define ADC1_CIC_GAIN_OFFSET                      20
#define ADC1_CIC_GAIN_LEN                         6
#define ADC0_CIC_GAIN_OFFSET                      26
#define ADC0_CIC_GAIN_LEN                         6

#define DMIC_CTRL_REG            (PAGE_SOCCODEC + 0x114)
#define DMIC0_SW_DMIC_MODE_OFFSET                 0
#define DMIC0_SW_DMIC_MODE_LEN                    1
#define DMIC0_REVERSE_OFFSET                      1
#define DMIC0_REVERSE_LEN                         1
#define DMIC1_SW_DMIC_MODE_OFFSET                 2
#define DMIC1_SW_DMIC_MODE_LEN                    1
#define DMIC1_REVERSE_OFFSET                      3
#define DMIC1_REVERSE_LEN                         1
#define DMIC2_SW_DMIC_MODE_OFFSET                 4
#define DMIC2_SW_DMIC_MODE_LEN                    1
#define DMIC2_REVERSE_OFFSET                      5
#define DMIC2_REVERSE_LEN                         1
#define DMIC3_SW_DMIC_MODE_OFFSET                 6
#define DMIC3_SW_DMIC_MODE_LEN                    1
#define DMIC3_REVERSE_OFFSET                      7
#define DMIC3_REVERSE_LEN                         1

#define DMIC_DIV_REG             (PAGE_SOCCODEC + 0x118)
#define FS_DMIC1_OFFSET                           0    /* store:FS_DMIC1, CHS:FS_DMIC0 */
#define FS_DMIC1_LEN                              4
#define FS_DMIC2_OFFSET                           4    /* store:FS_DMIC2, CHS:FS_DMIC1 */
#define FS_DMIC2_LEN                              4
#define FS_DMIC3_OFFSET                           8    /* store:FS_DMIC3, CHS:FS_DMIC2 */
#define FS_DMIC3_LEN                              4
#define FS_DMIC4_OFFSET                           12   /* store:FS_DMIC4, CHS:FS_DMIC3 */
#define FS_DMIC4_LEN                              4

#define SPA_UP_AFIFO_CTRL_REG    (PAGE_SOCCODEC + 0x11C)
#define SPA0123_UP_FIFO_AEMPTY_TH_OFFSET          5
#define SPA0123_UP_FIFO_AEMPTY_TH_LEN             5
#define SPA0123_UP_FIFO_AFULL_TH_OFFSET           10
#define SPA0123_UP_FIFO_AFULL_TH_LEN              5
#define SPA0123_UP_FIFO_CLR_OFFSET                15
#define SPA0123_UP_FIFO_CLR_LEN                   1
#define SPA4567_UP_FIFO_AEMPTY_TH_OFFSET          21
#define SPA4567_UP_FIFO_AEMPTY_TH_LEN             5
#define SPA4567_UP_FIFO_AFULL_TH_OFFSET           26
#define SPA4567_UP_FIFO_AFULL_TH_LEN              5
#define SPA4567_UP_FIFO_CLR_OFFSET                31
#define SPA4567_UP_FIFO_CLR_LEN                   1

#define HAPTIC_UP_AFIFO_CTRL1_REG (PAGE_SOCCODEC + 0x120)
#define HAPTIC1_UP_FIFO_AEMPTY_TH_OFFSET          5
#define HAPTIC1_UP_FIFO_AEMPTY_TH_LEN             5
#define HAPTIC1_UP_FIFO_AFULL_TH_OFFSET           10
#define HAPTIC1_UP_FIFO_AFULL_TH_LEN              5
#define HAPTIC1_UP_FIFO_CLR_OFFSET                15
#define HAPTIC1_UP_FIFO_CLR_LEN                   1
#define HAPTIC0_UP_FIFO_AEMPTY_TH_OFFSET          21
#define HAPTIC0_UP_FIFO_AEMPTY_TH_LEN             5
#define HAPTIC0_UP_FIFO_AFULL_TH_OFFSET           26
#define HAPTIC0_UP_FIFO_AFULL_TH_LEN              5
#define HAPTIC0_UP_FIFO_CLR_OFFSET                31
#define HAPTIC0_UP_FIFO_CLR_LEN                   1

#define HAPTIC_UP_AFIFO_CTRL2_REG (PAGE_SOCCODEC + 0x124)
#define HAPTIC3_UP_FIFO_AEMPTY_TH_OFFSET          5
#define HAPTIC3_UP_FIFO_AEMPTY_TH_LEN             5
#define HAPTIC3_UP_FIFO_AFULL_TH_OFFSET           10
#define HAPTIC3_UP_FIFO_AFULL_TH_LEN              5
#define HAPTIC3_UP_FIFO_CLR_OFFSET                15
#define HAPTIC3_UP_FIFO_CLR_LEN                   1
#define HAPTIC2_UP_FIFO_AEMPTY_TH_OFFSET          21
#define HAPTIC2_UP_FIFO_AEMPTY_TH_LEN             5
#define HAPTIC2_UP_FIFO_AFULL_TH_OFFSET           26
#define HAPTIC2_UP_FIFO_AFULL_TH_LEN              5
#define HAPTIC2_UP_FIFO_CLR_OFFSET                31
#define HAPTIC2_UP_FIFO_CLR_LEN                   1

#define CODEC_0123_DN_AFIFO_CTRL_REG (PAGE_SOCCODEC + 0x128)
#define CODEC_0123_DN_FIFO_AEMPTY_TH_OFFSET       17
#define CODEC_0123_DN_FIFO_AEMPTY_TH_LEN          7
#define CODEC_0123_DN_FIFO_AFULL_TH_OFFSET        24
#define CODEC_0123_DN_FIFO_AFULL_TH_LEN           7
#define CODEC_0123_DN_FIFO_CLR_OFFSET             31
#define CODEC_0123_DN_FIFO_CLR_LEN                1

#define AUDIO_0123_DN_AFIFO_CTRL_REG (PAGE_SOCCODEC + 0x12C)
#define AUDIO_0123_DN_FIFO_AEMPTY_TH_OFFSET       17
#define AUDIO_0123_DN_FIFO_AEMPTY_TH_LEN          7
#define AUDIO_0123_DN_FIFO_AFULL_TH_OFFSET        24
#define AUDIO_0123_DN_FIFO_AFULL_TH_LEN           7
#define AUDIO_0123_DN_FIFO_CLR_OFFSET             31
#define AUDIO_0123_DN_FIFO_CLR_LEN                1

#define HAPTIC01_DN_AFIFO_CTRL_REG (PAGE_SOCCODEC + 0x130)
#define HAPTIC1_DN_FIFO_AEMPTY_TH_OFFSET          2
#define HAPTIC1_DN_FIFO_AEMPTY_TH_LEN             7
#define HAPTIC1_DN_FIFO_AFULL_TH_OFFSET           9
#define HAPTIC1_DN_FIFO_AFULL_TH_LEN              7
#define HAPTIC1_DN_FIFO_CLR_OFFSET                16
#define HAPTIC1_DN_FIFO_CLR_LEN                   1
#define HAPTIC0_DN_FIFO_AEMPTY_TH_OFFSET          17
#define HAPTIC0_DN_FIFO_AEMPTY_TH_LEN             7
#define HAPTIC0_DN_FIFO_AFULL_TH_OFFSET           24
#define HAPTIC0_DN_FIFO_AFULL_TH_LEN              7
#define HAPTIC0_DN_FIFO_CLR_OFFSET                31
#define HAPTIC0_DN_FIFO_CLR_LEN                   1

#define ULTR_DN_AFIFO_CTRL_REG   (PAGE_SOCCODEC + 0x134)
#define ULTR_DN_FIFO_AEMPTY_TH_OFFSET             0
#define ULTR_DN_FIFO_AEMPTY_TH_LEN                7
#define ULTR_DN_FIFO_AFULL_TH_OFFSET              8
#define ULTR_DN_FIFO_AFULL_TH_LEN                 7
#define ULTR_DN_FIFO_CLR_OFFSET                   15
#define ULTR_DN_FIFO_CLR_LEN                      1

#define AUDIO_UP_AFIFO_CTRL_REG  (PAGE_SOCCODEC + 0x138)
#define AUDIO_LR_UP_FIFO_AEMPTY_TH_OFFSET         21
#define AUDIO_LR_UP_FIFO_AEMPTY_TH_LEN            5
#define AUDIO_LR_UP_FIFO_AFULL_TH_OFFSET          26
#define AUDIO_LR_UP_FIFO_AFULL_TH_LEN             5
#define AUDIO_LR_UP_FIFO_CLR_OFFSET               31
#define AUDIO_LR_UP_FIFO_CLR_LEN                  1

#define VOICE_UP_AFIFO_CTRL_REG  (PAGE_SOCCODEC + 0x13C)
#define VOICE_LR_UP_FIFO_AEMPTY_TH_OFFSET         21
#define VOICE_LR_UP_FIFO_AEMPTY_TH_LEN            5
#define VOICE_LR_UP_FIFO_AFULL_TH_OFFSET          26
#define VOICE_LR_UP_FIFO_AFULL_TH_LEN             5
#define VOICE_LR_UP_FIFO_CLR_OFFSET               31
#define VOICE_LR_UP_FIFO_CLR_LEN                  1

#define MIC23_UP_AFIFO_CTRL_REG  (PAGE_SOCCODEC + 0x140)
#define MIC23_UP_FIFO_AEMPTY_TH_OFFSET            21
#define MIC23_UP_FIFO_AEMPTY_TH_LEN               5
#define MIC23_UP_FIFO_AFULL_TH_OFFSET             26
#define MIC23_UP_FIFO_AFULL_TH_LEN                5
#define MIC23_UP_FIFO_CLR_OFFSET                  31
#define MIC23_UP_FIFO_CLR_LEN                     1

#define MIC45_UP_AFIFO_CTRL_REG  (PAGE_SOCCODEC + 0x144)
#define MIC45_UP_FIFO_AEMPTY_TH_OFFSET            21
#define MIC45_UP_FIFO_AEMPTY_TH_LEN               5
#define MIC45_UP_FIFO_AFULL_TH_OFFSET             26
#define MIC45_UP_FIFO_AFULL_TH_LEN                5
#define MIC45_UP_FIFO_CLR_OFFSET                  31
#define MIC45_UP_FIFO_CLR_LEN                     1

#define MIC67_UP_AFIFO_CTRL_REG  (PAGE_SOCCODEC + 0x148)
#define MIC67_UP_FIFO_AEMPTY_TH_OFFSET            21
#define MIC67_UP_FIFO_AEMPTY_TH_LEN               5
#define MIC67_UP_FIFO_AFULL_TH_OFFSET             26
#define MIC67_UP_FIFO_AFULL_TH_LEN                5
#define MIC67_UP_FIFO_CLR_OFFSET                  31
#define MIC67_UP_FIFO_CLR_LEN                     1

#define ULTR_UP_AFIFO_CTRL_REG   (PAGE_SOCCODEC + 0x14C)
#define ULTR_UP_FIFO_AEMPTY_TH_OFFSET             5
#define ULTR_UP_FIFO_AEMPTY_TH_LEN                5
#define ULTR_UP_FIFO_AFULL_TH_OFFSET              10
#define ULTR_UP_FIFO_AFULL_TH_LEN                 5
#define ULTR_UP_FIFO_CLR_OFFSET                   15
#define ULTR_UP_FIFO_CLR_LEN                      1

#define NOISE_METER_UP_AFIFO_CTRL_REG (PAGE_SOCCODEC + 0x150)

#define SIF_CTRL_REG             (PAGE_SOCCODEC + 0x154)
#define SIF_S2P_LOOP_OFFSET                       2
#define SIF_S2P_LOOP_LEN                          2
#define SIF_P2S_LOOP_OFFSET                       4
#define SIF_P2S_LOOP_LEN                          2
#define MIC7_DIN_SEL_OFFSET                       6    /* store:MIC7_DIN_SEL, CHS:MIC6_DIN_SEL */
#define MIC7_DIN_SEL_LEN                          3
#define MIC8_DIN_SEL_OFFSET                       9    /* store:MIC8_DIN_SEL, CHS:MIC7_DIN_SEL */
#define MIC8_DIN_SEL_LEN                          3

#define FS_CTRL0_REG             (PAGE_SOCCODEC + 0x158)
#define FS_CODEC_0123_DN_AFIFO_OFFSET             2
#define FS_CODEC_0123_DN_AFIFO_LEN                3
#define FS_AUDIO_0123_DN_AFIFO_OFFSET             5
#define FS_AUDIO_0123_DN_AFIFO_LEN                3
#define FS_BT_LR_DN_AFIFO_OFFSET                  8
#define FS_BT_LR_DN_AFIFO_LEN                     2
#define FS_ULTR_UP_AFIFO_OFFSET                   14
#define FS_ULTR_UP_AFIFO_LEN                      2
#define FS_MIC67_UP_AFIFO_OFFSET                  16
#define FS_MIC67_UP_AFIFO_LEN                     3
#define FS_MIC45_UP_AFIFO_OFFSET                  19
#define FS_MIC45_UP_AFIFO_LEN                     3
#define FS_MIC23_UP_AFIFO_OFFSET                  22
#define FS_MIC23_UP_AFIFO_LEN                     3
#define FS_VOICE_LR_UP_AFIFO_OFFSET               25
#define FS_VOICE_LR_UP_AFIFO_LEN                  3
#define FS_AUDIO_LR_UP_AFIFO_OFFSET               28
#define FS_AUDIO_LR_UP_AFIFO_LEN                  2
#define FS_SPA_0123_UP_AFIFO_OFFSET               30
#define FS_SPA_0123_UP_AFIFO_LEN                  2

#define FS_CTRL1_REG             (PAGE_SOCCODEC + 0x15C)
#define FS_MIC7_UP_PGA_OFFSET                     14    /* NSV:FS_MIC7, CHS:FS_MIC6 */
#define FS_MIC7_UP_PGA_LEN                        3     /* NSV:FS_MIC7, CHS:FS_MIC6 */
#define FS_MIC8_UP_PGA_OFFSET                     17    /* NSV:FS_MIC8, CHS:FS_MIC7 */
#define FS_MIC8_UP_PGA_LEN                        3     /* NSV:FS_MIC8, CHS:FS_MIC7 */
#define FS_HAPTIC3_UP_AFIFO_OFFSET                20
#define FS_HAPTIC3_UP_AFIFO_LEN                   2
#define FS_HAPTIC2_UP_AFIFO_OFFSET                22
#define FS_HAPTIC2_UP_AFIFO_LEN                   2
#define FS_HAPTIC1_UP_AFIFO_OFFSET                24
#define FS_HAPTIC1_UP_AFIFO_LEN                   2
#define FS_HAPTIC0_UP_AFIFO_OFFSET                26
#define FS_HAPTIC0_UP_AFIFO_LEN                   2
#define FS_HAPTIC1_DN_AFIFO_OFFSET                28
#define FS_HAPTIC1_DN_AFIFO_LEN                   2
#define FS_HAPTIC0_DN_AFIFO_OFFSET                30
#define FS_HAPTIC0_DN_AFIFO_LEN                   2

#define FS_CTRL2_REG             (PAGE_SOCCODEC + 0x160)
#define FS_CODEC_0_DN_PGA_OFFSET                  0
#define FS_CODEC_0_DN_PGA_LEN                     2
#define FS_CODEC_1_DN_PGA_OFFSET                  2
#define FS_CODEC_1_DN_PGA_LEN                     2
#define FS_CODEC_2_DN_PGA_OFFSET                  4
#define FS_CODEC_2_DN_PGA_LEN                     2
#define FS_AUDIO_0_DN_PGA_OFFSET                  6
#define FS_AUDIO_0_DN_PGA_LEN                     2
#define FS_AUDIO_1_DN_PGA_OFFSET                  8
#define FS_AUDIO_1_DN_PGA_LEN                     2
#define FS_AUDIO_2_DN_PGA_OFFSET                  10
#define FS_AUDIO_2_DN_PGA_LEN                     2
#define FS_AUDIO_L_UP_PGA_OFFSET                  12
#define FS_AUDIO_L_UP_PGA_LEN                     2
#define FS_AUDIO_R_UP_PGA_OFFSET                  14
#define FS_AUDIO_R_UP_PGA_LEN                     2
#define FS_MIC3_UP_PGA_OFFSET                     16    /* store:FS_MIC3, CHS:FS_MIC2 */
#define FS_MIC3_UP_PGA_LEN                        3
#define FS_MIC4_UP_PGA_OFFSET                     19    /* store:FS_MIC4, CHS:FS_MIC3 */
#define FS_MIC4_UP_PGA_LEN                        3
#define FS_MIC5_UP_PGA_OFFSET                     22    /* store:FS_MIC5, CHS:FS_MIC4 */
#define FS_MIC5_UP_PGA_LEN                        3
#define FS_MIC6_UP_PGA_OFFSET                     25    /* store:FS_MIC6, CHS:FS_MIC5 */
#define FS_MIC6_UP_PGA_LEN                        3

#define FS_CTRL3_REG             (PAGE_SOCCODEC + 0x164)
#define FS_I2S1_RX_L_PGA_OFFSET                   0
#define FS_I2S1_RX_L_PGA_LEN                      3
#define FS_I2S1_RX_R_PGA_OFFSET                   3
#define FS_I2S1_RX_R_PGA_LEN                      3
#define FS_CODEC_0_DN_SRCUP_DIN_OFFSET            6
#define FS_CODEC_0_DN_SRCUP_DIN_LEN               2
#define FS_CODEC_0_DN_SRCUP_DOUT_OFFSET           8
#define FS_CODEC_0_DN_SRCUP_DOUT_LEN              3
#define FS_CODEC_1_DN_SRCUP_DIN_OFFSET            11
#define FS_CODEC_1_DN_SRCUP_DIN_LEN               2
#define FS_CODEC_1_DN_SRCUP_DOUT_OFFSET           13
#define FS_CODEC_1_DN_SRCUP_DOUT_LEN              3
#define FS_CODEC_2_DN_SRCUP_DIN_OFFSET            16
#define FS_CODEC_2_DN_SRCUP_DIN_LEN               2
#define FS_CODEC_2_DN_SRCUP_DOUT_OFFSET           18
#define FS_CODEC_2_DN_SRCUP_DOUT_LEN              3
#define FS_AUDIO_0_DN_SRCUP_DIN_OFFSET            21
#define FS_AUDIO_0_DN_SRCUP_DIN_LEN               2
#define FS_AUDIO_0_DN_SRCUP_DOUT_OFFSET           23
#define FS_AUDIO_0_DN_SRCUP_DOUT_LEN              3
#define FS_AUDIO_1_DN_SRCUP_DIN_OFFSET            26
#define FS_AUDIO_1_DN_SRCUP_DIN_LEN               2
#define FS_AUDIO_1_DN_SRCUP_DOUT_OFFSET           28
#define FS_AUDIO_1_DN_SRCUP_DOUT_LEN              3

#define FS_CTRL4_REG             (PAGE_SOCCODEC + 0x168)
#define FS_AUDIO_UP_L_SRCDN_DIN_OFFSET            14
#define FS_AUDIO_UP_L_SRCDN_DIN_LEN               2
#define FS_AUDIO_UP_L_SRCDN_DOUT_OFFSET           16
#define FS_AUDIO_UP_L_SRCDN_DOUT_LEN              2
#define FS_AUDIO_UP_R_SRCDN_DIN_OFFSET            18
#define FS_AUDIO_UP_R_SRCDN_DIN_LEN               2
#define FS_AUDIO_UP_R_SRCDN_DOUT_OFFSET           20
#define FS_AUDIO_UP_R_SRCDN_DOUT_LEN              2
#define FS_VOICE_UP_L_SRCDN_DIN_OFFSET            22
#define FS_VOICE_UP_L_SRCDN_DIN_LEN               2
#define FS_VOICE_UP_L_SRCDN_DOUT_OFFSET           24
#define FS_VOICE_UP_L_SRCDN_DOUT_LEN              3
#define FS_VOICE_UP_R_SRCDN_DIN_OFFSET            27
#define FS_VOICE_UP_R_SRCDN_DIN_LEN               2
#define FS_VOICE_UP_R_SRCDN_DOUT_OFFSET           29
#define FS_VOICE_UP_R_SRCDN_DOUT_LEN              3

#define FS_CTRL5_REG             (PAGE_SOCCODEC + 0x16C)
#define FS_MIC3_SRCDN_DOUT_OFFSET                 0     /* store:FS_CTRL3, CHS:FS_CTRL2 */
#define FS_MIC3_SRCDN_DOUT_LEN                    3
#define FS_MIC4_SRCDN_DOUT_OFFSET                 3     /* store:FS_CTRL4, CHS:FS_CTRL3 */
#define FS_MIC4_SRCDN_DOUT_LEN                    3
#define FS_MIC5_SRCDN_DOUT_OFFSET                 6     /* store:FS_CTRL5, CHS:FS_CTRL4 */
#define FS_MIC5_SRCDN_DOUT_LEN                    3
#define FS_MIC6_SRCDN_DOUT_OFFSET                 9     /* store:FS_CTRL6, CHS:FS_CTRL5 */
#define FS_MIC6_SRCDN_DOUT_LEN                    3
#define FS_MIC7_SRCDN_DOUT_OFFSET                 12    /* NSV:FS_CTRL7, CHS:FS_CTRL6 */
#define FS_MIC7_SRCDN_DOUT_LEN                    3
#define FS_MIC8_SRCDN_DOUT_OFFSET                 15    /* NSV:FS_CTRL8, CHS:FS_CTRL7 */
#define FS_MIC8_SRCDN_DOUT_LEN                    3
#define FS_I2S1_RX_L_SRCDN_DIN_OFFSET             18
#define FS_I2S1_RX_L_SRCDN_DIN_LEN                3
#define FS_I2S1_RX_L_SRCDN_DOUT_OFFSET            21
#define FS_I2S1_RX_L_SRCDN_DOUT_LEN               3
#define FS_VOICE_L_UP_PGA_OFFSET                  24
#define FS_VOICE_L_UP_PGA_LEN                     3
#define FS_VOICE_R_UP_PGA_OFFSET                  27
#define FS_VOICE_R_UP_PGA_LEN                     3

#define FS_CTRL6_REG             (PAGE_SOCCODEC + 0x170)
#define FS_I2S1_RX_R_SRCDN_DIN_OFFSET             0
#define FS_I2S1_RX_R_SRCDN_DIN_LEN                3
#define FS_I2S1_RX_R_SRCDN_DOUT_OFFSET            3
#define FS_I2S1_RX_R_SRCDN_DOUT_LEN               3
#define FS_I2S1_TX_L_SRCDN_DIN_OFFSET             6
#define FS_I2S1_TX_L_SRCDN_DIN_LEN                2
#define FS_I2S1_TX_L_SRCDN_DOUT_OFFSET            8
#define FS_I2S1_TX_L_SRCDN_DOUT_LEN               3
#define FS_I2S1_TX_R_SRCDN_DIN_OFFSET             11
#define FS_I2S1_TX_R_SRCDN_DIN_LEN                2
#define FS_I2S1_TX_R_SRCDN_DOUT_OFFSET            13
#define FS_I2S1_TX_R_SRCDN_DOUT_LEN               3
#define FS_I2S1_TX_MIXER2_OFFSET                  16
#define FS_I2S1_TX_MIXER2_LEN                     3
#define FS_S0_TDM_OFFSET                          19
#define FS_S0_TDM_LEN                             2
#define FS_SPA2_MIXER4_OFFSET                     21
#define FS_SPA2_MIXER4_LEN                        1
#define FS_SPA1_MIXER4_OFFSET                     22
#define FS_SPA1_MIXER4_LEN                        1
#define FS_SPA0_MIXER4_OFFSET                     23
#define FS_SPA0_MIXER4_LEN                        1

#define CODEC_DIN_MUX0_REG       (PAGE_SOCCODEC + 0x174)
#define I2S1_TX_L_SEL_OFFSET                      0    /* store:I2S1_TX_L_SEL, CHS:I2S0_TX_L_SEL */
#define I2S1_TX_L_SEL_LEN                         2
#define I2S1_TX_R_SEL_OFFSET                      2    /* store:I2S1_TX_R_SEL, CHS:I2S0_TX_R_SEL */
#define I2S1_TX_R_SEL_LEN                         2
#define I2S2_TX_R_SEL_OFFSET                      4    /* store:I2S2_TX_R_SEL, CHS:I2S1_TX_R_SEL */
#define I2S2_TX_R_SEL_LEN                         1
#define SIDETONE_PGA_DIN_SEL_OFFSET               5
#define SIDETONE_PGA_DIN_SEL_LEN                  3
#define ADC1_DIN_SEL_OFFSET                       8    /* store:ADC1_DIN_SEL, CHS:ADC0_DIN_SEL */
#define ADC1_DIN_SEL_LEN                          1
#define ADC2_DIN_SEL_OFFSET                       9    /* store:ADC2_DIN_SEL, CHS:ADC1_DIN_SEL */
#define ADC2_DIN_SEL_LEN                          1
#define ADC3_DIN_SEL_OFFSET                       10   /* store:ADC3_DIN_SEL, CHS:ADC2_DIN_SEL */
#define ADC3_DIN_SEL_LEN                          1
#define ADC4_DIN_SEL_OFFSET                       11   /* store:ADC4_DIN_SEL, CHS:ADC3_DIN_SEL */
#define ADC4_DIN_SEL_LEN                          1
#define AU_UP_L_DIN_SEL_OFFSET                    12
#define AU_UP_L_DIN_SEL_LEN                       3
#define AU_UP_R_DIN_SEL_OFFSET                    15
#define AU_UP_R_DIN_SEL_LEN                       3
#define VO_UP_L_DIN_SEL_OFFSET                    18
#define VO_UP_L_DIN_SEL_LEN                       3
#define VO_UP_R_DIN_SEL_OFFSET                    21
#define VO_UP_R_DIN_SEL_LEN                       3
#define MIC3_DIN_SEL_OFFSET                       24    /* store:MIC3_DIN_SEL, CHS:MIC2_DIN_SEL */
#define MIC3_DIN_SEL_LEN                          3
#define MIC4_DIN_SEL_OFFSET                       27    /* store:MIC4_DIN_SEL, CHS:MIC3_DIN_SEL */
#define MIC4_DIN_SEL_LEN                          3
#define I2S1_TX_SEL_OFFSET                        30
#define I2S1_TX_SEL_LEN                           1

#define CODEC_DIN_MUX1_REG       (PAGE_SOCCODEC + 0x178)
#define MIC5_DIN_SEL_OFFSET                       0    /* store:MIC5_DIN_SEL, CHS:MIC4_DIN_SEL */
#define MIC5_DIN_SEL_LEN                          4
#define MIC6_DIN_SEL_OFFSET                       4    /* store:MIC6_DIN_SEL, CHS:MIC5_DIN_SEL */
#define MIC6_DIN_SEL_LEN                          4
#define BM_I2S0_TDM128_SLOT2_DIN_SEL_OFFSET       8
#define BM_I2S0_TDM128_SLOT2_DIN_SEL_LEN          1
#define BM_I2S0_TDM128_SLOT3_DIN_SEL_OFFSET       9
#define BM_I2S0_TDM128_SLOT3_DIN_SEL_LEN          1
#define BT_TX_SRCDN_DIN_SEL_OFFSET                14
#define BT_TX_SRCDN_DIN_SEL_LEN                   1
#define DACL_SRCUP_DIN_SEL_OFFSET                 15
#define DACL_SRCUP_DIN_SEL_LEN                    1
#define DACR_SRCUP_DIN_SEL_OFFSET                 16
#define DACR_SRCUP_DIN_SEL_LEN                    1
#define ADC0_CIC_DOUT_SEL_OFFSET                  17
#define ADC0_CIC_DOUT_SEL_LEN                     2
#define ADC1_CIC_DOUT_SEL_OFFSET                  19
#define ADC1_CIC_DOUT_SEL_LEN                     2
#define ADC2_CIC_DOUT_SEL_OFFSET                  21
#define ADC2_CIC_DOUT_SEL_LEN                     2
#define ADC3_CIC_DOUT_SEL_OFFSET                  23
#define ADC3_CIC_DOUT_SEL_LEN                     2
#define ADC4_CIC_DOUT_SEL_OFFSET                  25
#define ADC4_CIC_DOUT_SEL_LEN                     1
#define ADC5_CIC_DOUT_SEL_OFFSET                  26
#define ADC5_CIC_DOUT_SEL_LEN                     1
#define ADC6_CIC_DOUT_SEL_OFFSET                  27
#define ADC6_CIC_DOUT_SEL_LEN                     1
#define ADC7_CIC_DOUT_SEL_OFFSET                  28
#define ADC7_CIC_DOUT_SEL_LEN                     1
#define ADC_ULTR_CIC_DIN_SEL_OFFSET               29
#define ADC_ULTR_CIC_DIN_SEL_LEN                  3

#define CODEC_ADC0_DC_OFFSET_REG (PAGE_SOCCODEC + 0x17C)
#define ADC0_DC_OFFSET_OFFSET                     0
#define ADC0_DC_OFFSET_LEN                        24

#define CODEC_ADC1_DC_OFFSET_REG (PAGE_SOCCODEC + 0x180)
#define ADC1_DC_OFFSET_OFFSET                     0
#define ADC1_DC_OFFSET_LEN                        24

#define CODEC_ADC2_DC_OFFSET_REG (PAGE_SOCCODEC + 0x184)
#define ADC2_DC_OFFSET_OFFSET                     0
#define ADC2_DC_OFFSET_LEN                        24

#define CODEC_ADC3_DC_OFFSET_REG (PAGE_SOCCODEC + 0x188)
#define ADC3_DC_OFFSET_OFFSET                     0
#define ADC3_DC_OFFSET_LEN                        24

#define CODEC_ADC4_DC_OFFSET_REG (PAGE_SOCCODEC + 0x18C)
#define ADC4_DC_OFFSET_OFFSET                     0
#define ADC4_DC_OFFSET_LEN                        24

#define CODEC_ADC5_DC_OFFSET_REG (PAGE_SOCCODEC + 0x190)
#define ADC5_DC_OFFSET_OFFSET                     0
#define ADC5_DC_OFFSET_LEN                        24

#define CODEC_ADC6_DC_OFFSET_REG (PAGE_SOCCODEC + 0x194)
#define ADC6_DC_OFFSET_OFFSET                     0
#define ADC6_DC_OFFSET_LEN                        24

#define CODEC_ADC7_DC_OFFSET_REG (PAGE_SOCCODEC + 0x198)
#define ADC7_DC_OFFSET_OFFSET                     0
#define ADC7_DC_OFFSET_LEN                        24

#define CODEC_ADC_ULTR_DC_OFFSET_REG (PAGE_SOCCODEC + 0x19C)
#define ADC_ULTR_DC_OFFSET_OFFSET                 0
#define ADC_ULTR_DC_OFFSET_LEN                    24

#define MEM_CTRL_S_REG           (PAGE_SOCCODEC + 0x1A0)
#define MEM_CTRL_S_OFFSET                         0
#define MEM_CTRL_S_LEN                            26

#define MEM_CTRL_D1W2R_REG       (PAGE_SOCCODEC + 0x1A4)
#define MEM_CTRL_D1W2R_OFFSET                     0
#define MEM_CTRL_D1W2R_LEN                        16

#define ADC_CTRL_HPF_REG         (PAGE_SOCCODEC + 0x1A8)
#define ADC0_HPF_BYPASS_EN_OFFSET                 0
#define ADC0_HPF_BYPASS_EN_LEN                    1
#define ADC1_HPF_BYPASS_EN_OFFSET                 1
#define ADC1_HPF_BYPASS_EN_LEN                    1
#define ADC2_HPF_BYPASS_EN_OFFSET                 2
#define ADC2_HPF_BYPASS_EN_LEN                    1
#define ADC3_HPF_BYPASS_EN_OFFSET                 3
#define ADC3_HPF_BYPASS_EN_LEN                    1
#define ADC4_HPF_BYPASS_EN_OFFSET                 4
#define ADC4_HPF_BYPASS_EN_LEN                    1
#define ADC5_HPF_BYPASS_EN_OFFSET                 5
#define ADC5_HPF_BYPASS_EN_LEN                    1
#define ADC6_HPF_BYPASS_EN_OFFSET                 6
#define ADC6_HPF_BYPASS_EN_LEN                    1
#define ADC7_HPF_BYPASS_EN_OFFSET                 7
#define ADC7_HPF_BYPASS_EN_LEN                    1
#define DACR_UP16_HBF3_BYPASS_EN_OFFSET           8
#define DACR_UP16_HBF3_BYPASS_EN_LEN              1
#define DACR_UP16_HBF2_BYPASS_EN_OFFSET           9
#define DACR_UP16_HBF2_BYPASS_EN_LEN              1
#define DACR_UP16_HBF1_BYPASS_EN_OFFSET           10
#define DACR_UP16_HBF1_BYPASS_EN_LEN              1
#define DACR_UP16_HBF0_BYPASS_EN_OFFSET           11
#define DACR_UP16_HBF0_BYPASS_EN_LEN              1
#define DACL_UP16_HBF3_BYPASS_EN_OFFSET           12
#define DACL_UP16_HBF3_BYPASS_EN_LEN              1
#define DACL_UP16_HBF2_BYPASS_EN_OFFSET           13
#define DACL_UP16_HBF2_BYPASS_EN_LEN              1
#define DACL_UP16_HBF1_BYPASS_EN_OFFSET           14
#define DACL_UP16_HBF1_BYPASS_EN_LEN              1
#define DACL_UP16_HBF0_BYPASS_EN_OFFSET           15
#define DACL_UP16_HBF0_BYPASS_EN_LEN              1
#define ADC_ULTR_HPF_BYPASS_EN_OFFSET             16
#define ADC_ULTR_HPF_BYPASS_EN_LEN                1

#define BT_LR_DN_AFIFO_CTRL_REG  (PAGE_SOCCODEC + 0x1AC)
#define BT_LR_DN_FIFO_AEMPTY_TH_OFFSET            17
#define BT_LR_DN_FIFO_AEMPTY_TH_LEN               7
#define BT_LR_DN_FIFO_AFULL_TH_OFFSET             24
#define BT_LR_DN_FIFO_AFULL_TH_LEN                7
#define BT_LR_DN_FIFO_CLR_OFFSET                  31
#define BT_LR_DN_FIFO_CLR_LEN                     1

#define CODEC_DACL_DC_OFFSET_REG (PAGE_SOCCODEC + 0x1B0)
#define DACL_DC_OFFSET_OFFSET                     0
#define DACL_DC_OFFSET_LEN                        24

#define CODEC_DACR_DC_OFFSET_REG (PAGE_SOCCODEC + 0x1B4)
#define DACR_DC_OFFSET_OFFSET                     0
#define DACR_DC_OFFSET_LEN                        24

#define DAC_FILTER_CTRL_REG      (PAGE_SOCCODEC + 0x1B8)
#define SDM_R_CALT_VLD_OFFSET                     0
#define SDM_R_CALT_VLD_LEN                        1
#define SDM_R_DITHER_OFFSET                       1
#define SDM_R_DITHER_LEN                          1
#define DACR_FIR2D_BYPASS_EN_OFFSET               2
#define DACR_FIR2D_BYPASS_EN_LEN                  1
#define DACR_FIR2C_BYPASS_EN_OFFSET               3
#define DACR_FIR2C_BYPASS_EN_LEN                  1
#define SDM_L_CALT_VLD_OFFSET                     4
#define SDM_L_CALT_VLD_LEN                        1
#define SDM_L_DITHER_OFFSET                       5
#define SDM_L_DITHER_LEN                          1
#define DACL_FIR2D_BYPASS_EN_OFFSET               6
#define DACL_FIR2D_BYPASS_EN_LEN                  1
#define DACL_FIR2C_BYPASS_EN_OFFSET               7
#define DACL_FIR2C_BYPASS_EN_LEN                  1

#define CIC_ULTRA_CTRL0_REG      (PAGE_SOCCODEC + 0x1BC)
#define ADC0_CIC_DN4_ULTRA_GAIN_OFFSET            0
#define ADC0_CIC_DN4_ULTRA_GAIN_LEN               8
#define ADC0_CIC_DN8_ULTRA_GAIN_OFFSET            8
#define ADC0_CIC_DN8_ULTRA_GAIN_LEN               4
#define ADC1_CIC_DN4_ULTRA_GAIN_OFFSET            16
#define ADC1_CIC_DN4_ULTRA_GAIN_LEN               8
#define ADC1_CIC_DN8_ULTRA_GAIN_OFFSET            24
#define ADC1_CIC_DN8_ULTRA_GAIN_LEN               4

#define CIC_ULTRA_CTRL1_REG      (PAGE_SOCCODEC + 0x1C0)
#define ADC2_CIC_DN4_ULTRA_GAIN_OFFSET            0
#define ADC2_CIC_DN4_ULTRA_GAIN_LEN               8
#define ADC2_CIC_DN8_ULTRA_GAIN_OFFSET            8
#define ADC2_CIC_DN8_ULTRA_GAIN_LEN               4
#define ADC3_CIC_DN4_ULTRA_GAIN_OFFSET            16
#define ADC3_CIC_DN4_ULTRA_GAIN_LEN               8
#define ADC3_CIC_DN8_ULTRA_GAIN_OFFSET            24
#define ADC3_CIC_DN8_ULTRA_GAIN_LEN               4

#define SIF0_CTRL_REG            (PAGE_SOCCODEC + 0x1C4)
#define SIF0_DACL_EN_OFFSET                       0
#define SIF0_DACL_EN_LEN                          1
#define SIF0_DACR_EN_OFFSET                       1
#define SIF0_DACR_EN_LEN                          1
#define SIF0_ADCL_EN_OFFSET                       2
#define SIF0_ADCL_EN_LEN                          1
#define SIF0_ADCR_EN_OFFSET                       3
#define SIF0_ADCR_EN_LEN                          1
#define SIF0_ADC_MIC3_EN_OFFSET                   4
#define SIF0_ADC_MIC3_EN_LEN                      1
#define SIF0_DAC_ULTR_EN_OFFSET                   5
#define SIF0_DAC_ULTR_EN_LEN                      1
#define SIF0_SPA_DAC_EN_OFFSET                    6
#define SIF0_SPA_DAC_EN_LEN                       1
#define SIF0_SPA_ADC_EN_OFFSET                    7
#define SIF0_SPA_ADC_EN_LEN                       1

#define HP_L_CTRL0_REG           (PAGE_SOCCODEC + 0x1C8)
#define HP_L_SRCUP_DIN_SEL_OFFSET                 0
#define HP_L_SRCUP_DIN_SEL_LEN                    1
#define HP_L_FIR2C_BYPASS_EN_OFFSET               1
#define HP_L_FIR2C_BYPASS_EN_LEN                  1
#define HP_L_FIR2D_BYPASS_EN_OFFSET               2
#define HP_L_FIR2D_BYPASS_EN_LEN                  1
#define HP_L_HBF0_BYPASS_EN_OFFSET                3
#define HP_L_HBF0_BYPASS_EN_LEN                   1
#define HP_L_HBF1_BYPASS_EN_OFFSET                4
#define HP_L_HBF1_BYPASS_EN_LEN                   1
#define HP_L_HBF2_BYPASS_EN_OFFSET                5
#define HP_L_HBF2_BYPASS_EN_LEN                   1
#define HP_L_HBF3_BYPASS_EN_OFFSET                6
#define HP_L_HBF3_BYPASS_EN_LEN                   1
#define HP_L_SDM_CALT_VLD_OFFSET                  7
#define HP_L_SDM_CALT_VLD_LEN                     1
#define HP_L_SDM_DITHER_OFFSET                    8
#define HP_L_SDM_DITHER_LEN                       1

#define HP_L_CTRL1_REG           (PAGE_SOCCODEC + 0x1CC)
#define HP_L_DC_OFFSET_OFFSET                     0
#define HP_L_DC_OFFSET_LEN                        24

#define HP_R_CTRL0_REG           (PAGE_SOCCODEC + 0x1D0)
#define HP_R_SRCUP_DIN_SEL_OFFSET                 0
#define HP_R_SRCUP_DIN_SEL_LEN                    1
#define HP_R_FIR2C_BYPASS_EN_OFFSET               1
#define HP_R_FIR2C_BYPASS_EN_LEN                  1
#define HP_R_FIR2D_BYPASS_EN_OFFSET               2
#define HP_R_FIR2D_BYPASS_EN_LEN                  1
#define HP_R_HBF0_BYPASS_EN_OFFSET                3
#define HP_R_HBF0_BYPASS_EN_LEN                   1
#define HP_R_HBF1_BYPASS_EN_OFFSET                4
#define HP_R_HBF1_BYPASS_EN_LEN                   1
#define HP_R_HBF2_BYPASS_EN_OFFSET                5
#define HP_R_HBF2_BYPASS_EN_LEN                   1
#define HP_R_HBF3_BYPASS_EN_OFFSET                6
#define HP_R_HBF3_BYPASS_EN_LEN                   1
#define HP_R_SDM_CALT_VLD_OFFSET                  7
#define HP_R_SDM_CALT_VLD_LEN                     1
#define HP_R_SDM_DITHER_OFFSET                    8
#define HP_R_SDM_DITHER_LEN                       1

#define HP_R_CTRL1_REG           (PAGE_SOCCODEC + 0x1D4)
#define HP_R_DC_OFFSET_OFFSET                     0
#define HP_R_DC_OFFSET_LEN                        24

#define ULTR_ADC_CTRL0_REG       (PAGE_SOCCODEC + 0x1D8)
#define ULTR_ADC_CIC_GAIN_OFFSET                  0
#define ULTR_ADC_CIC_GAIN_LEN                     6
#define ULTR_ADC_COMPD_BYPASS_EN_OFFSET           8
#define ULTR_ADC_COMPD_BYPASS_EN_LEN              1
#define ULTR_ADC_HBF2D_BYPASS_EN_OFFSET           9
#define ULTR_ADC_HBF2D_BYPASS_EN_LEN              1
#define ULTR_ADC_HBFVD_BYPASS_EN_OFFSET           10
#define ULTR_ADC_HBFVD_BYPASS_EN_LEN              1
#define ULTR_ADC_HPF_BYPASS_EN_OFFSET             11
#define ULTR_ADC_HPF_BYPASS_EN_LEN                1

#define ADC_ULTRA_CIC_CTRL_REG   (PAGE_SOCCODEC + 0x1DC)
#define ADC0_CIC_ULTRA_SEL_OFFSET                 0
#define ADC0_CIC_ULTRA_SEL_LEN                    1
#define ADC1_CIC_ULTRA_SEL_OFFSET                 1
#define ADC1_CIC_ULTRA_SEL_LEN                    1
#define ADC2_CIC_ULTRA_SEL_OFFSET                 2
#define ADC2_CIC_ULTRA_SEL_LEN                    1
#define ADC3_CIC_ULTRA_SEL_OFFSET                 3
#define ADC3_CIC_ULTRA_SEL_LEN                    1

#define FS_CTRL7_REG             (PAGE_SOCCODEC + 0x1E0)
#define FS_AUDIO_2_DN_SRCUP_DIN_OFFSET            0
#define FS_AUDIO_2_DN_SRCUP_DIN_LEN               2
#define FS_AUDIO_2_DN_SRCUP_DOUT_OFFSET           2
#define FS_AUDIO_2_DN_SRCUP_DOUT_LEN              3
#define FS_I2S1_RX_L_SRCUP_DIN_OFFSET             5
#define FS_I2S1_RX_L_SRCUP_DIN_LEN                3
#define FS_I2S1_RX_L_SRCUP_DOUT_OFFSET            8
#define FS_I2S1_RX_L_SRCUP_DOUT_LEN               3
#define FS_I2S1_RX_R_SRCUP_DIN_OFFSET             11
#define FS_I2S1_RX_R_SRCUP_DIN_LEN                3
#define FS_I2S1_RX_R_SRCUP_DOUT_OFFSET            14
#define FS_I2S1_RX_R_SRCUP_DOUT_LEN               3
#define FS_DACL_MIXER4_SRCUP_DIN_OFFSET           17
#define FS_DACL_MIXER4_SRCUP_DIN_LEN              2
#define FS_DACL_MIXER4_SRCUP_DOUT_OFFSET          19
#define FS_DACL_MIXER4_SRCUP_DOUT_LEN             2
#define FS_DACR_MIXER4_SRCUP_DIN_OFFSET           21
#define FS_DACR_MIXER4_SRCUP_DIN_LEN              2
#define FS_DACR_MIXER4_SRCUP_DOUT_OFFSET          23
#define FS_DACR_MIXER4_SRCUP_DOUT_LEN             2

#define PGA_GAINOFFSET_CTRL5_REG (PAGE_SOCCODEC + 0x1E4)
#define MIC4_UP_PGA_GAINOFFSET_OFFSET             0
#define MIC4_UP_PGA_GAINOFFSET_LEN                8
#define MIC5_UP_PGA_GAINOFFSET_OFFSET             8
#define MIC5_UP_PGA_GAINOFFSET_LEN                8
#define MIC6_UP_PGA_GAINOFFSET_OFFSET             16
#define MIC6_UP_PGA_GAINOFFSET_LEN                8
#define MIC7_UP_PGA_GAINOFFSET_OFFSET             24
#define MIC7_UP_PGA_GAINOFFSET_LEN                8

#define DLOCK_BP_REG             (PAGE_SOCCODEC + 0x1E8)
#define DLOCK_BP_SMARTPA_OFFSET                   0
#define DLOCK_BP_SMARTPA_LEN                      1
#define DLOCK_BP_AUDIO_HAPTIC_OFFSET              1
#define DLOCK_BP_AUDIO_HAPTIC_LEN                 1

#define AUDIO_HAPTIC_CTRL0_REG   (PAGE_SOCCODEC + 0x1EC)
#define HAPTIC0_I_DATA_SEL_OFFSET                 0
#define HAPTIC0_I_DATA_SEL_LEN                    1
#define HAPTIC0_V_DATA_SEL_OFFSET                 1
#define HAPTIC0_V_DATA_SEL_LEN                    1
#define HAPTIC1_I_DATA_SEL_OFFSET                 2
#define HAPTIC1_I_DATA_SEL_LEN                    1
#define HAPTIC1_V_DATA_SEL_OFFSET                 3
#define HAPTIC1_V_DATA_SEL_LEN                    1
#define AUDIO_HAPTIC_0_DN_BYPASS_OFFSET           4
#define AUDIO_HAPTIC_0_DN_BYPASS_LEN              1
#define AUDIO_HAPTIC_0_UP_BYPASS_OFFSET           5
#define AUDIO_HAPTIC_0_UP_BYPASS_LEN              1
#define AUDIO_HAPTIC_1_DN_BYPASS_OFFSET           6
#define AUDIO_HAPTIC_1_DN_BYPASS_LEN              1
#define AUDIO_HAPTIC_1_UP_BYPASS_OFFSET           7
#define AUDIO_HAPTIC_1_UP_BYPASS_LEN              1
#define HAPTIC3_UP_AFIFO_DIN_SEL_OFFSET           8
#define HAPTIC3_UP_AFIFO_DIN_SEL_LEN              1
#define HAPTIC2_UP_AFIFO_DIN_SEL_OFFSET           9
#define HAPTIC2_UP_AFIFO_DIN_SEL_LEN              1

#define NOISE_METER_CTRL1_REG    (PAGE_SOCCODEC + 0x1F0)

#define NOISE_METER_CTRL2_REG    (PAGE_SOCCODEC + 0x1F4)

#define NOISE_METER_CTRL3_REG    (PAGE_SOCCODEC + 0x1F8)

#define NOISE_METER_CTRL4_REG    (PAGE_SOCCODEC + 0x1FC)

#define NOISE_METER_CTRL5_REG    (PAGE_SOCCODEC + 0x200)

#define NOISE_METER_CTRL6_REG    (PAGE_SOCCODEC + 0x204)

#define NOISE_METER_CTRL7_REG    (PAGE_SOCCODEC + 0x208)

#define NOISE_METER_CTRL8_REG    (PAGE_SOCCODEC + 0x20C)

#define NOISE_METER_CTRL9_REG    (PAGE_SOCCODEC + 0x210)

#define NOISE_METER_CTRL10_REG   (PAGE_SOCCODEC + 0x214)

#define NOISE_METER_OFL_REG_CTRL0_REG (PAGE_SOCCODEC + 0x218)

#define NOISE_METER_OFL_REG_CTRL1_REG (PAGE_SOCCODEC + 0x21C)

#define NOISE_METER_OFL_NOS_CNT_CTRL0_REG (PAGE_SOCCODEC + 0x220)

#define NOISE_METER_OFL_NOS_CNT_CTRL1_REG (PAGE_SOCCODEC + 0x224)

#define NOISE_METER_OFL_RECOV_CTRL_REG (PAGE_SOCCODEC + 0x228)

#define NOISE_METER_ONLINE_DATA0_REG (PAGE_SOCCODEC + 0x22C)

#define NOISE_METER_ONLINE_DATA1_REG (PAGE_SOCCODEC + 0x230)

#define NOISE_METER_ONLINE_DATA2_REG (PAGE_SOCCODEC + 0x234)

#define NOISE_METER_ONLINE_DATA3_REG (PAGE_SOCCODEC + 0x238)

#define MEM_CTRL_SPC_REG         (PAGE_SOCCODEC + 0x23C)
#define MEM_CTRL_SPC_OFFSET                       0
#define MEM_CTRL_SPC_LEN                          26

#define CODEC_CLK_EN5_REG        (PAGE_SOCCODEC + 0x240)
#define CODEC_3_DN_SRCUP_CLKEN_OFFSET             0
#define CODEC_3_DN_SRCUP_CLKEN_LEN                1
#define AUDIO_3_DN_SRCUP_CLKEN_OFFSET             1
#define AUDIO_3_DN_SRCUP_CLKEN_LEN                1
#define CODEC_3_DN_PGA_CLKEN_OFFSET               2
#define CODEC_3_DN_PGA_CLKEN_LEN                  1
#define AUDIO_3_DN_PGA_CLKEN_OFFSET               3
#define AUDIO_3_DN_PGA_CLKEN_LEN                  1
#define MIXER4_SPA3_CLKEN_OFFSET                  8
#define MIXER4_SPA3_CLKEN_LEN                     1
#define MIXER2_ULTR3_CLKEN_OFFSET                 9
#define MIXER2_ULTR3_CLKEN_LEN                    1

#define FS_CTRL8_REG             (PAGE_SOCCODEC + 0x244)
#define FS_CODEC_3_DN_SRCUP_DIN_OFFSET            0
#define FS_CODEC_3_DN_SRCUP_DIN_LEN               2
#define FS_CODEC_3_DN_SRCUP_DOUT_OFFSET           2
#define FS_CODEC_3_DN_SRCUP_DOUT_LEN              3
#define FS_AUDIO_3_DN_SRCUP_DIN_OFFSET            5
#define FS_AUDIO_3_DN_SRCUP_DIN_LEN               2
#define FS_AUDIO_3_DN_SRCUP_DOUT_OFFSET           7
#define FS_AUDIO_3_DN_SRCUP_DOUT_LEN              3
#define FS_CODEC_3_DN_PGA_OFFSET                  10
#define FS_CODEC_3_DN_PGA_LEN                     2
#define FS_AUDIO_3_DN_PGA_OFFSET                  12
#define FS_AUDIO_3_DN_PGA_LEN                     2
#define FS_SPA3_MIXER4_OFFSET                     18
#define FS_SPA3_MIXER4_LEN                        1

#define AFIFO_CHANNAL_CTRL_REG   (PAGE_SOCCODEC + 0x248)
#define AUDIO_0123_DN_AFIFO_CHANNAL_OFFSET        1
#define AUDIO_0123_DN_AFIFO_CHANNAL_LEN           2
#define CODEC_0123_DN_AFIFO_CHANNAL_OFFSET        3
#define CODEC_0123_DN_AFIFO_CHANNAL_LEN           2
#define BT_LR_DN_AFIFO_CHANNAL_OFFSET             5
#define BT_LR_DN_AFIFO_CHANNAL_LEN                1
#define MIC67_UP_AFIFO_CHANNAL_OFFSET             8
#define MIC67_UP_AFIFO_CHANNAL_LEN                1
#define MIC45_UP_AFIFO_CHANNAL_OFFSET             9
#define MIC45_UP_AFIFO_CHANNAL_LEN                1
#define MIC23_UP_AFIFO_CHANNAL_OFFSET             10
#define MIC23_UP_AFIFO_CHANNAL_LEN                1
#define VOICE_LR_UP_AFIFO_CHANNAL_OFFSET          11
#define VOICE_LR_UP_AFIFO_CHANNAL_LEN             1
#define AUDIO_LR_UP_AFIFO_CHANNAL_OFFSET          12
#define AUDIO_LR_UP_AFIFO_CHANNAL_LEN             1
#define SPA0123_UP_AFIFO_CHANNAL_OFFSET           13
#define SPA0123_UP_AFIFO_CHANNAL_LEN              2
#define SPA4567_UP_AFIFO_CHANNAL_OFFSET           15
#define SPA4567_UP_AFIFO_CHANNAL_LEN              2

#define AFIFO_CTRL_REG           (PAGE_SOCCODEC + 0x24C)

#define CODEC_3_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x250)
#define CODEC_3_DN_PGA_LINEAR_SEL_OFFSET          1
#define CODEC_3_DN_PGA_LINEAR_SEL_LEN             1
#define CODEC_3_DN_PGA_ZERO_NUM_OFFSET            2
#define CODEC_3_DN_PGA_ZERO_NUM_LEN               5
#define CODEC_3_DN_PGA_THRE_ID_OFFSET             7
#define CODEC_3_DN_PGA_THRE_ID_LEN                2
#define CODEC_3_DN_PGA_NOISE_EN_OFFSET            9
#define CODEC_3_DN_PGA_NOISE_EN_LEN               1
#define CODEC_3_DN_PGA_BYPASS_OFFSET              10
#define CODEC_3_DN_PGA_BYPASS_LEN                 1
#define CODEC_3_DN_PGA_FADE_OUT_OFFSET            11
#define CODEC_3_DN_PGA_FADE_OUT_LEN               5
#define CODEC_3_DN_PGA_FADE_IN_OFFSET             16
#define CODEC_3_DN_PGA_FADE_IN_LEN                5
#define CODEC_3_DN_PGA_CFG_OFFSET                 21
#define CODEC_3_DN_PGA_CFG_LEN                    3
#define CODEC_3_DN_PGA_GAIN_OFFSET                24
#define CODEC_3_DN_PGA_GAIN_LEN                   8

#define AUDIO_3_DN_PGA_CTRL_REG  (PAGE_SOCCODEC + 0x254)
#define AUDIO_3_DN_PGA_LINEAR_SEL_OFFSET          1
#define AUDIO_3_DN_PGA_LINEAR_SEL_LEN             1
#define AUDIO_3_DN_PGA_ZERO_NUM_OFFSET            2
#define AUDIO_3_DN_PGA_ZERO_NUM_LEN               5
#define AUDIO_3_DN_PGA_THRE_ID_OFFSET             7
#define AUDIO_3_DN_PGA_THRE_ID_LEN                2
#define AUDIO_3_DN_PGA_NOISE_EN_OFFSET            9
#define AUDIO_3_DN_PGA_NOISE_EN_LEN               1
#define AUDIO_3_DN_PGA_BYPASS_OFFSET              10
#define AUDIO_3_DN_PGA_BYPASS_LEN                 1
#define AUDIO_3_DN_PGA_FADE_OUT_OFFSET            11
#define AUDIO_3_DN_PGA_FADE_OUT_LEN               5
#define AUDIO_3_DN_PGA_FADE_IN_OFFSET             16
#define AUDIO_3_DN_PGA_FADE_IN_LEN                5
#define AUDIO_3_DN_PGA_CFG_OFFSET                 21
#define AUDIO_3_DN_PGA_CFG_LEN                    3
#define AUDIO_3_DN_PGA_GAIN_OFFSET                24
#define AUDIO_3_DN_PGA_GAIN_LEN                   8

#define SRCUP_CTRL2_REG          (PAGE_SOCCODEC + 0x258)
#define CODEC_3_DN_SRCUP_SRC_MODE_OFFSET          0
#define CODEC_3_DN_SRCUP_SRC_MODE_LEN             3
#define CODEC_3_DN_SRCUP_FIFO_CLR_OFFSET          3
#define CODEC_3_DN_SRCUP_FIFO_CLR_LEN             1
#define AUDIO_3_SRCUP_SRC_MODE_OFFSET             4
#define AUDIO_3_SRCUP_SRC_MODE_LEN                3
#define AUDIO_3_DN_SRCUP_FIFO_CLR_OFFSET          7
#define AUDIO_3_DN_SRCUP_FIFO_CLR_LEN             1

#define SPA3_MIXER4_CTRL0_REG    (PAGE_SOCCODEC + 0x25C)
#define SPA3_MIXER4_GAIN1_OFFSET                  12
#define SPA3_MIXER4_GAIN1_LEN                     2
#define SPA3_MIXER4_GAIN2_OFFSET                  14
#define SPA3_MIXER4_GAIN2_LEN                     2
#define SPA3_MIXER4_GAIN3_OFFSET                  16
#define SPA3_MIXER4_GAIN3_LEN                     2
#define SPA3_MIXER4_GAIN4_OFFSET                  18
#define SPA3_MIXER4_GAIN4_LEN                     2
#define SPA3_MIXER4_IN1_MUTE_OFFSET               20
#define SPA3_MIXER4_IN1_MUTE_LEN                  1
#define SPA3_MIXER4_IN2_MUTE_OFFSET               21
#define SPA3_MIXER4_IN2_MUTE_LEN                  1
#define SPA3_MIXER4_IN3_MUTE_OFFSET               22
#define SPA3_MIXER4_IN3_MUTE_LEN                  1
#define SPA3_MIXER4_IN4_MUTE_OFFSET               23
#define SPA3_MIXER4_IN4_MUTE_LEN                  1
#define SPA3_MIXER4_IN1_ID_OFFSET                 24
#define SPA3_MIXER4_IN1_ID_LEN                    2
#define SPA3_MIXER4_IN2_ID_OFFSET                 26
#define SPA3_MIXER4_IN2_ID_LEN                    2
#define SPA3_MIXER4_IN3_ID_OFFSET                 28
#define SPA3_MIXER4_IN3_ID_LEN                    2
#define SPA3_MIXER4_IN4_ID_OFFSET                 30
#define SPA3_MIXER4_IN4_ID_LEN                    2

#define SPA3_MIXER4_CTRL1_REG    (PAGE_SOCCODEC + 0x260)
#define SPA3_MIXER4_ZERO_NUM_OFFSET               16
#define SPA3_MIXER4_ZERO_NUM_LEN                  5
#define SPA3_MIXER4_FADE_OUT_OFFSET               21
#define SPA3_MIXER4_FADE_OUT_LEN                  5
#define SPA3_MIXER4_FADE_IN_OFFSET                26
#define SPA3_MIXER4_FADE_IN_LEN                   5
#define SPA3_MIXER4_FADE_EN_OFFSET                31
#define SPA3_MIXER4_FADE_EN_LEN                   1

#define ULTR3_MIXER2_CTRL_REG    (PAGE_SOCCODEC + 0x264)
#define ULTR3_MIXER2_VLD_SEL_OFFSET               4
#define ULTR3_MIXER2_VLD_SEL_LEN                  1
#define ULTR3_MIXER2_FADE_EN2_OFFSET              5
#define ULTR3_MIXER2_FADE_EN2_LEN                 1
#define ULTR3_MIXER2_ZERO_NUM_OFFSET              6
#define ULTR3_MIXER2_ZERO_NUM_LEN                 5
#define ULTR3_MIXER2_FADE_OUT_OFFSET              11
#define ULTR3_MIXER2_FADE_OUT_LEN                 5
#define ULTR3_MIXER2_FADE_IN_OFFSET               16
#define ULTR3_MIXER2_FADE_IN_LEN                  5
#define ULTR3_MIXER2_FADE_EN1_OFFSET              21
#define ULTR3_MIXER2_FADE_EN1_LEN                 1
#define ULTR3_MIXER2_GAIN1_OFFSET                 22
#define ULTR3_MIXER2_GAIN1_LEN                    2
#define ULTR3_MIXER2_GAIN2_OFFSET                 24
#define ULTR3_MIXER2_GAIN2_LEN                    2
#define ULTR3_MIXER2_IN1_MUTE_OFFSET              26
#define ULTR3_MIXER2_IN1_MUTE_LEN                 1
#define ULTR3_MIXER2_IN2_MUTE_OFFSET              27
#define ULTR3_MIXER2_IN2_MUTE_LEN                 1
#define ULTR3_MIXER2_IN1_ID_OFFSET                28
#define ULTR3_MIXER2_IN1_ID_LEN                   2
#define ULTR3_MIXER2_IN2_ID_OFFSET                30
#define ULTR3_MIXER2_IN2_ID_LEN                   2

#define PGA_GAINOFFSET_CTRL6_REG (PAGE_SOCCODEC + 0x268)
#define CODEC_3_DN_PGA_GAINOFFSET_OFFSET          0
#define CODEC_3_DN_PGA_GAINOFFSET_LEN             8
#define AUDIO_3_DN_PGA_GAINOFFSET_OFFSET          8
#define AUDIO_3_DN_PGA_GAINOFFSET_LEN             8

#define SPA_AFIFO_UP_DIN_CTRL6_REG (PAGE_SOCCODEC + 0x26C)
#define SPA1_DIN_SEL_OFFSET                       0    /* store:SPA1_DIN, CHS:SPA0_DIN */
#define SPA1_DIN_SEL_LEN                          1
#define SPA2_DIN_SEL_OFFSET                       1    /* store:SPA2_DIN, CHS:SPA1_DIN */
#define SPA2_DIN_SEL_LEN                          1
#define SPA3_DIN_SEL_OFFSET                       2    /* store:SPA3_DIN, CHS:SPA2_DIN */
#define SPA3_DIN_SEL_LEN                          1
#define SPA4_DIN_SEL_OFFSET                       3    /* store:SPA4_DIN, CHS:SPA3_DIN */
#define SPA4_DIN_SEL_LEN                          1
#define BM_I2S0_TDM128_SLOT1_DIN_SEL_OFFSET       4
#define BM_I2S0_TDM128_SLOT1_DIN_SEL_LEN          1
#define BM_I2S0_TDM128_SLOT0_DIN_SEL_OFFSET       5
#define BM_I2S0_TDM128_SLOT0_DIN_SEL_LEN          1
#define SPA_TEST_FIFO_DIN_SEL_OFFSET              6
#define SPA_TEST_FIFO_DIN_SEL_LEN                 2
#define SPA_TEST_FIFO_CLR_OFFSET                  8
#define SPA_TEST_FIFO_CLR_LEN                     1
#define FS_SPA_TEST_UP_AFIFO_OFFSET               9
#define FS_SPA_TEST_UP_AFIFO_LEN                  3
#define SPA_TEST_FIFO_AFULL_TH_OFFSET             12
#define SPA_TEST_FIFO_AFULL_TH_LEN                5
#define SPA_TEST_FIFO_AEMPTY_TH_OFFSET            17
#define SPA_TEST_FIFO_AEMPTY_TH_LEN               5

#define SPA_AFIFO_UP_DIN_CTRL7_REG (PAGE_SOCCODEC + 0x270)
#define I2S0_TDM256_3IV_DIN_SEL_OFFSET            0
#define I2S0_TDM256_3IV_DIN_SEL_LEN               3
#define I2S0_TDM256_2IV_DIN_SEL_OFFSET            3
#define I2S0_TDM256_2IV_DIN_SEL_LEN               3
#define I2S0_TDM256_1IV_DIN_SEL_OFFSET            6
#define I2S0_TDM256_1IV_DIN_SEL_LEN               3
#define I2S0_TDM256_0IV_DIN_SEL_OFFSET            9
#define I2S0_TDM256_0IV_DIN_SEL_LEN               3

#define I2S3_PCM_CTRL_REG        (PAGE_SOCCODEC + 0x274)
#define I2S3_LP_CTRL_CLK_EN_OFFSET                7
#define I2S3_LP_CTRL_CLK_EN_LEN                   1
#define I2S3_HARDWARE_LP_CTRL_SEL_OFFSET          8
#define I2S3_HARDWARE_LP_CTRL_SEL_LEN             2
#define I2S3_LP_EN_OFFSET                         10
#define I2S3_LP_EN_LEN                            1
#define I2S3_PCM_CLKEN_OFFSET                     11
#define I2S3_PCM_CLKEN_LEN                        1
#define S3_FIFO_CLR_OFFSET                        12
#define S3_FIFO_CLR_LEN                           1
#define FS_I2S3_OFFSET                            13
#define FS_I2S3_LEN                               3
#define I2S3_IF_TX_ENA_OFFSET                     16
#define I2S3_IF_TX_ENA_LEN                        1
#define I2S3_IF_RX_ENA_OFFSET                     17
#define I2S3_IF_RX_ENA_LEN                        1
#define I2S3_MST_SLV_OFFSET                       18
#define I2S3_MST_SLV_LEN                          1
#define I2S3_DIRECT_LOOP_OFFSET                   19
#define I2S3_DIRECT_LOOP_LEN                      2
#define I2S3_FUNC_MODE_OFFSET                     21
#define I2S3_FUNC_MODE_LEN                        3
#define I2S3_FRAME_MODE_OFFSET                    24
#define I2S3_FRAME_MODE_LEN                       1
#define I2S3_LRCLK_MODE_OFFSET                    25
#define I2S3_LRCLK_MODE_LEN                       1
#define I2S3_CHNNL_MODE_OFFSET                    26
#define I2S3_CHNNL_MODE_LEN                       1
#define I2S3_CODEC_DATA_FORMAT_OFFSET             27
#define I2S3_CODEC_DATA_FORMAT_LEN                1
#define I2S3_CODEC_IO_WORDLENGTH_OFFSET           28
#define I2S3_CODEC_IO_WORDLENGTH_LEN              2
#define I2S3_TX_CLK_SEL_OFFSET                    30
#define I2S3_TX_CLK_SEL_LEN                       1
#define I2S3_RX_CLK_SEL_OFFSET                    31
#define I2S3_RX_CLK_SEL_LEN                       1

#define SPA_BYPASS_CTRL_REG      (PAGE_SOCCODEC + 0x278)
#define SPA0_BYPASS_OFFSET                        0
#define SPA0_BYPASS_LEN                           1
#define SPA1_BYPASS_OFFSET                        1
#define SPA1_BYPASS_LEN                           1
#define SPA2_BYPASS_OFFSET                        2
#define SPA2_BYPASS_LEN                           1
#define SPA3_BYPASS_OFFSET                        3
#define SPA3_BYPASS_LEN                           1

#define R_RST_CTRLEN                  (PAGE_ASPCFG + 0x0)
#define RST_EN_CODEC_N 9
#define RST_EN_AXI2TDM_N 25

#define R_RST_CTRLDIS                 (PAGE_ASPCFG + 0x4)
#define RST_DISEN_CODEC_N 9
#define RST_DISEN_AXI2TDM_N 25

#define R_RST_CTRLSTAT                (PAGE_ASPCFG + 0x8)
#define RST_DSP_N 4

#define R_GATE_EN                     (PAGE_ASPCFG + 0xC)
#define GT_CODEC_CLK 3
#define GT_AXI2TDM_CLK 30
#define IODIE_CODEC_CLK 6

#define R_GATE_CLKEN                  (PAGE_ASPCFG + 0x14)
#define GT_HIFIDSPCLK 0

#define R_DMA_SEL                     (PAGE_ASPCFG + 0x54)
#define PA_CLK_OUT_SEL_OFFSET 11

#define R_CODEC_DMA_SEL               (PAGE_ASPCFG + 0x218)
#define CODEC_DMA_SEL 0               /* NSV bit17, CHS bit0 */

#define RESERVED_LOCK_ADDR            (PAGE_ASPCFG + 0x90)

#define PA_CLK_ENABLE                 (PAGE_ASPCFG + 0x2C)

#define PA_DIV_ENABLE_VALUE            0x1F001
#define PA_CLK_ENABLE_VALUE            0x8000000
#define PA_CLK_DISABLE_VALUE           0x8000800

#endif
