/*
 * asp_codec_driver.c -- codec driver
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

#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/hwspinlock.h>

#include "audio_log.h"
#include "asp_codec_utils.h"
#include "asp_codec_control.h"
#include "asp_codec_type.h"

#define LOG_TAG "asp_codec"

#define HAPTIC_BYPASS_CFG       0x40013F9F

static struct snd_soc_component *soc_codec = NULL;

static struct asp_codec_reg_page g_reg_array[] = {
	{NULL, PAGE_SOCCODEC, \
	 PAGE_SOCCODEC + SOCCODEC_END_OFFSET, false, true},
	{NULL, PAGE_ASPCFG, \
	 PAGE_ASPCFG + ASPCFG_END_OFFSET, false, true},
	{NULL, PAGE_AXI2TDM, \
	 PAGE_AXI2TDM + AXI2TDM_END, false, true},
	{NULL, PAGE_MAD, \
	 PAGE_MAD + MAD_END, false, false},
	{NULL, PAGE_SOCSMARTPA1, \
	 PAGE_SOCSMARTPA1 + SOCSMARTPA_END_OFFSET, false, true},
	{NULL, PAGE_SOCSMARTPA2, \
	 PAGE_SOCSMARTPA2 + SOCSMARTPA_END_OFFSET, false, true},
	{NULL, PAGE_SOCSMARTPA3, \
	 PAGE_SOCSMARTPA3 + SOCSMARTPA_END_OFFSET, false, true},
	{NULL, PAGE_SOCSMARTPA4, \
	 PAGE_SOCSMARTPA4 + SOCSMARTPA_END_OFFSET, false, true},
	{NULL, PAGE_HAPTIC0, \
	 PAGE_HAPTIC0 + HAPTIC_END_OFFSET, false, true},
	{NULL, PAGE_HAPTIC1, \
	 PAGE_HAPTIC1 + HAPTIC_END_OFFSET, false, true},
	{NULL, PAGE_VIRCODEC, \
	 PAGE_VIRCODEC + VIRCODEC_END_OFFSET, true, false},
};

static int micbias_en_ctl_gpio_init(int gpio)
{
	if (!gpio_is_valid(gpio)) {
		AUDIO_LOGE("gpio is not valid");
		return -EINVAL;
	}
 
	if (gpio_request(gpio, "micbias_en_ctl")) {
		AUDIO_LOGE("micbias_en_ctl failed");
		return -EINVAL;
	}
 
	if (gpio_direction_output(gpio, 0)) {
		gpio_free(gpio);
		AUDIO_LOGE("micbias en gpio set output failed");
		return -EINVAL;
	}
 
	return 0;
}
 
static int get_micbias_en_ctl_resource(struct snd_soc_component *codec)
{
	int gpio;
	int ret;
	const char *micbias_en_gpio_str = "hisilicon,micbias_en_gpio";
	struct device_node *node = NULL;
	struct codec_platform_data *priv = snd_soc_component_get_drvdata(codec);
 
	if (priv == NULL)
		return 0;
 
	node = codec->dev->of_node;
	if (node == NULL) {
		priv->micbias_en_ctl.need_gpio_ctl = false;
		return 0;
	}
 
	if (of_property_read_bool(node, micbias_en_gpio_str)) {
		priv->micbias_en_ctl.need_gpio_ctl = true;
		AUDIO_LOGI("need config micbias en ctl");
	} else {
		priv->micbias_en_ctl.need_gpio_ctl = false;
		return 0;
	}
 
	gpio = of_get_named_gpio(node, micbias_en_gpio_str, 0);
	if (gpio < 0) {
		AUDIO_LOGE("%s of_get_named_gpio failed, %d\n",
			micbias_en_gpio_str, gpio);
		ret = of_property_read_u32(node, micbias_en_gpio_str,
			(u32 *)&(gpio));
		if (ret < 0) {
			priv->micbias_en_ctl.need_gpio_ctl = false;
			AUDIO_LOGE("%s read gpio prop failed, %d\n",
				micbias_en_gpio_str, ret);
			return ret;
		}
	}
	AUDIO_LOGI("gpio:%d", gpio);
	ret = micbias_en_ctl_gpio_init(gpio);
	if (ret < 0) {
		priv->micbias_en_ctl.need_gpio_ctl = false;
		AUDIO_LOGE("gpio resource init fail, ret = %d", ret);
		return ret;
	}
	priv->micbias_en_ctl.gpio = gpio;
	return 0;
}

static void asp_codec_shutdown(struct platform_device *device)
{
	unused_parameter(device);
	struct codec_data *priv = NULL;
	AUDIO_LOGI("asp codec shutdown");

	if (soc_codec == NULL) {
		AUDIO_LOGE("parameter is null");
		return;
	}

	priv = snd_soc_component_get_drvdata(soc_codec);
	if (priv == NULL || priv->pm.asp_pd) {
		AUDIO_LOGW("asp codec is null or power down");
		return;
	}

	/* set audio down pga -120db */
	snd_soc_component_update_bits(soc_codec, AUDIO_0_DN_PGA_CTRL_REG,
		mask_on_bit(AUDIO_0_DN_PGA_GAIN_LEN, AUDIO_0_DN_PGA_GAIN_OFFSET),
		0x88 << AUDIO_0_DN_PGA_GAIN_OFFSET);
	snd_soc_component_update_bits(soc_codec, AUDIO_1_DN_PGA_CTRL_REG,
		mask_on_bit(AUDIO_1_DN_PGA_GAIN_LEN, AUDIO_1_DN_PGA_GAIN_OFFSET),
		0x88 << AUDIO_1_DN_PGA_GAIN_OFFSET);
	snd_soc_component_update_bits(soc_codec, AUDIO_2_DN_PGA_CTRL_REG,
		mask_on_bit(AUDIO_2_DN_PGA_GAIN_LEN, AUDIO_2_DN_PGA_GAIN_OFFSET),
		0x88 << AUDIO_2_DN_PGA_GAIN_OFFSET);
	snd_soc_component_update_bits(soc_codec, AUDIO_3_DN_PGA_CTRL_REG,
		mask_on_bit(AUDIO_3_DN_PGA_GAIN_LEN, AUDIO_3_DN_PGA_GAIN_OFFSET),
		0x88 << AUDIO_3_DN_PGA_GAIN_OFFSET);

	/* set codec fifo pga -120db */
	snd_soc_component_update_bits(soc_codec, CODEC_0_DN_PGA_CTRL_REG,
		mask_on_bit(CODEC_0_DN_PGA_GAIN_LEN, CODEC_0_DN_PGA_GAIN_OFFSET),
		0x88 << CODEC_0_DN_PGA_GAIN_OFFSET);
	snd_soc_component_update_bits(soc_codec, CODEC_1_DN_PGA_CTRL_REG,
		mask_on_bit(CODEC_1_DN_PGA_GAIN_LEN, CODEC_1_DN_PGA_GAIN_OFFSET),
		0x88 << CODEC_1_DN_PGA_GAIN_OFFSET);
	snd_soc_component_update_bits(soc_codec, CODEC_2_DN_PGA_CTRL_REG,
		mask_on_bit(CODEC_2_DN_PGA_GAIN_LEN, CODEC_2_DN_PGA_GAIN_OFFSET),
		0x88 << CODEC_2_DN_PGA_GAIN_OFFSET);
	snd_soc_component_update_bits(soc_codec, CODEC_3_DN_PGA_CTRL_REG,
		mask_on_bit(CODEC_3_DN_PGA_GAIN_LEN, CODEC_3_DN_PGA_GAIN_OFFSET),
		0x88 << CODEC_3_DN_PGA_GAIN_OFFSET);

	/* set spa mixer4 pga -12db */
	snd_soc_component_update_bits(soc_codec, SPA0_MIXER4_CTRL0_REG,
		BIT(SPA0_MIXER4_GAIN1_OFFSET) | BIT(SPA0_MIXER4_GAIN2_OFFSET) |
		BIT(SPA0_MIXER4_GAIN3_OFFSET) | BIT(SPA0_MIXER4_GAIN4_OFFSET), 0);
	snd_soc_component_update_bits(soc_codec, SPA1_MIXER4_CTRL0_REG,
		BIT(SPA1_MIXER4_GAIN1_OFFSET) | BIT(SPA1_MIXER4_GAIN2_OFFSET) |
		BIT(SPA1_MIXER4_GAIN3_OFFSET) | BIT(SPA1_MIXER4_GAIN4_OFFSET), 0);
	snd_soc_component_update_bits(soc_codec, SPA2_MIXER4_CTRL0_REG,
		BIT(SPA2_MIXER4_GAIN1_OFFSET) | BIT(SPA2_MIXER4_GAIN2_OFFSET) |
		BIT(SPA2_MIXER4_GAIN3_OFFSET) | BIT(SPA2_MIXER4_GAIN4_OFFSET), 0);
	snd_soc_component_update_bits(soc_codec, SPA3_MIXER4_CTRL0_REG,
		BIT(SPA3_MIXER4_GAIN1_OFFSET) | BIT(SPA3_MIXER4_GAIN2_OFFSET) |
		BIT(SPA3_MIXER4_GAIN3_OFFSET) | BIT(SPA3_MIXER4_GAIN4_OFFSET), 0);
}

static void asp_codec_priv_data_init(struct snd_soc_component *codec)
{
	if (codec == NULL) {
        AUDIO_LOGE("codec is nullptr");
		return;
	}
	int ret;
	soc_codec = codec;
	ret = get_micbias_en_ctl_resource(codec);
	if (ret < 0)
		AUDIO_LOGE("get micbias en ctl failed");
}

static void asp_codec_priv_data_deinit(struct snd_soc_component *codec)
{
	soc_codec = NULL;
}

static void asp_codec_reg_init(struct snd_soc_component *codec)
{
	/* adc pga bypass */
	asp_codec_update_bits_without_pm(codec, ADC1_UP_PGA_CTRL_REG, BIT(ADC0_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC0_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC2_UP_PGA_CTRL_REG, BIT(ADC1_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC1_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC3_UP_PGA_CTRL_REG, BIT(ADC2_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC2_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC4_UP_PGA_CTRL_REG, BIT(ADC3_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC3_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC5_UP_PGA_CTRL_REG, BIT(ADC4_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC4_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC6_UP_PGA_CTRL_REG, BIT(ADC5_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC5_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC7_UP_PGA_CTRL_REG, BIT(ADC6_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC6_UP_PGA_0P5_BYPASS_OFFSET));
	asp_codec_update_bits_without_pm(codec, ADC8_UP_PGA_CTRL_REG, BIT(ADC7_UP_PGA_0P5_BYPASS_OFFSET),
		BIT(ADC7_UP_PGA_0P5_BYPASS_OFFSET));
	/* set i2s2 frq 8k */
	asp_codec_update_bits_without_pm(codec, I2S2_PCM_CTRL_REG, mask_on_bit(FS_I2S2_LEN, FS_I2S2_OFFSET), 0);
	asp_codec_update_bits_without_pm(codec, I2S1_CTRL_REG,
		mask_on_bit(I2S1_TX_CLK_SEL_LEN, I2S1_TX_CLK_SEL_OFFSET),
		BIT(I2S1_TX_CLK_SEL_OFFSET));

	/* dmic 1/2 768k */
	asp_codec_update_bits_without_pm(codec, DMIC_DIV_REG,
		mask_on_bit(FS_DMIC1_LEN, FS_DMIC1_OFFSET) | mask_on_bit(FS_DMIC2_LEN, FS_DMIC2_OFFSET),
		0x7 << FS_DMIC1_OFFSET | 0x7 << FS_DMIC2_OFFSET);

	/* haptic low power */
	asp_codec_update_bits_without_pm(codec, I2S3_PCM_CTRL_REG, BIT(I2S3_LP_EN_OFFSET), BIT(I2S3_LP_EN_OFFSET));
	asp_codec_update_bits_without_pm(codec, I2S3_PCM_CTRL_REG, mask_on_bit(I2S3_HARDWARE_LP_CTRL_SEL_LEN, I2S3_HARDWARE_LP_CTRL_SEL_OFFSET),
		mask_on_bit(I2S3_HARDWARE_LP_CTRL_SEL_LEN, I2S3_HARDWARE_LP_CTRL_SEL_OFFSET));
	
	/* ultr_mixer2 spa_out unmute */
	asp_codec_update_bits_without_pm(codec, ULTR0_MIXER2_CTRL_REG, BIT(ULTR0_MIXER2_IN1_MUTE_OFFSET), 0);
	asp_codec_update_bits_without_pm(codec, ULTR1_MIXER2_CTRL_REG, BIT(ULTR1_MIXER2_IN1_MUTE_OFFSET), 0);
	asp_codec_update_bits_without_pm(codec, ULTR2_MIXER2_CTRL_REG, BIT(ULTR2_MIXER2_IN1_MUTE_OFFSET), 0);
	asp_codec_update_bits_without_pm(codec, ULTR3_MIXER2_CTRL_REG, BIT(ULTR3_MIXER2_IN1_MUTE_OFFSET), 0);
}

static void asp_codec_reset(struct snd_soc_component *codec)
{
#ifdef CONFIG_SND_SOC_ASP_CODEC_SUPPORT_HWSPIN_LOCK
	struct codec_data *priv = snd_soc_component_get_drvdata(codec);
	int hwlock_ret;
	hwlock_ret = hwspin_lock_timeout_in_atomic(priv->hwlock, GET_HWLOCK_TIMEOUT_MS);
	if (hwlock_ret != 0)
		AUDIO_LOGE("asp codec hwlock get timeout, ret:%d", hwlock_ret);
#endif
	asp_codec_reg_write_without_pm(codec, R_RST_CTRLEN, BIT(RST_EN_CODEC_N));
	asp_codec_reg_write_without_pm(codec, R_RST_CTRLDIS, BIT(RST_DISEN_CODEC_N));
#ifdef CONFIG_SND_SOC_ASP_CODEC_SUPPORT_HWSPIN_LOCK
	if (hwlock_ret == 0)
		hwspin_unlock_in_atomic(priv->hwlock);
#endif
	asp_codec_reg_write_without_pm(codec, R_GATE_EN, BIT(GT_CODEC_CLK));
	/* init AX2TDM */
	asp_codec_reg_write_without_pm(codec, R_RST_CTRLEN, BIT(RST_EN_AXI2TDM_N));
	asp_codec_reg_write_without_pm(codec, R_RST_CTRLDIS, BIT(RST_DISEN_AXI2TDM_N));
	asp_codec_reg_write_without_pm(codec, R_GATE_EN, BIT(GT_AXI2TDM_CLK));
}

static void asp_codec_fpga_pinctrl_init(struct snd_soc_component *codec)
{
	AUDIO_LOGI("set asp gpio pinctrl");
}

struct codec_platform_data g_codec_platform_data = {
	.base.ops = {
		asp_codec_priv_data_init,
		asp_codec_priv_data_deinit,
		asp_codec_reg_init,
		asp_codec_reset,
		asp_codec_shutdown,
		asp_codec_fpga_pinctrl_init,
	},
	.base.v_codec_num = VIR_REG_CNT,
	.base.platform_reg_array = &g_reg_array[0],
	.base.platform_reg_size = ARRAY_SIZE(g_reg_array),
};

static_t int __init asp_codec_data_init(void)
{
	asp_codec_driver_init(&(g_codec_platform_data.base));
	return 0;
}

arch_initcall(asp_codec_data_init);
