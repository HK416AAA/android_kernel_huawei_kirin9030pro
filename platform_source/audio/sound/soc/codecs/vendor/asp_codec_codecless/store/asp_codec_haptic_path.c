/*
 * asp_codec_haptic_path.c -- codec driver.
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

#include <sound/soc.h>
#include "audio_log.h"
#include "audio_pinctrl.h"
#include "asp_codec_store.h"
#include "asp_codec_type.h"

#define LOG_TAG "asp_codec_haptic_path"

#define I2S3_CFG_KCONTROLS \
	SOC_SINGLE("FS_S3_IF_I2S", \
		I2S3_PCM_CTRL_REG, FS_I2S3_OFFSET, \
		max_val_on_bit(FS_I2S3_LEN), 0), \
	SOC_SINGLE("I2S3_FUNC_MODE", \
		I2S3_PCM_CTRL_REG, I2S3_FUNC_MODE_OFFSET, \
		max_val_on_bit(I2S3_FUNC_MODE_LEN), 0), \
	SOC_SINGLE("I2S3_I2S_DIRECT_MODE", \
		I2S3_PCM_CTRL_REG, I2S3_DIRECT_LOOP_OFFSET, \
		max_val_on_bit(I2S3_DIRECT_LOOP_LEN), 0), \
	SOC_SINGLE("I2S3_FRAME_MODE", \
		I2S3_PCM_CTRL_REG, I2S3_FRAME_MODE_OFFSET, \
		max_val_on_bit(I2S3_FRAME_MODE_LEN), 0), \
	SOC_SINGLE("I2S3_RX_CLK_SEL", \
		I2S3_PCM_CTRL_REG, I2S3_RX_CLK_SEL_OFFSET, \
		max_val_on_bit(I2S3_RX_CLK_SEL_LEN), 0), \
	SOC_SINGLE("I2S3_TX_CLK_SEL", \
		I2S3_PCM_CTRL_REG, I2S3_TX_CLK_SEL_OFFSET, \
		max_val_on_bit(I2S3_TX_CLK_SEL_LEN), 0), \
    SOC_SINGLE("I2S3_CODEC_IO_WORDLENGTH", \
		I2S3_PCM_CTRL_REG, I2S3_CODEC_IO_WORDLENGTH_OFFSET, \
		max_val_on_bit(I2S3_CODEC_IO_WORDLENGTH_LEN), 0), \
	SOC_SINGLE("I2S3_LRCLK_MODE", \
		I2S3_PCM_CTRL_REG, I2S3_LRCLK_MODE_OFFSET, \
		max_val_on_bit(I2S3_LRCLK_MODE_LEN), 0), \
	SOC_SINGLE("I2S3_LP_EN", \
		I2S3_PCM_CTRL_REG, I2S3_LP_EN_OFFSET, \
		max_val_on_bit(I2S3_LP_EN_LEN), 0), \
	SOC_SINGLE("I2S3_HARDWARE_LP_CTRL_SEL", \
		I2S3_PCM_CTRL_REG, I2S3_HARDWARE_LP_CTRL_SEL_OFFSET, \
		max_val_on_bit(I2S3_HARDWARE_LP_CTRL_SEL_LEN), 0), \
	SOC_SINGLE("I2S3_LP_CTRL_CLK_EN", \
		I2S3_PCM_CTRL_REG, I2S3_LP_CTRL_CLK_EN_OFFSET, \
		max_val_on_bit(I2S3_LP_CTRL_CLK_EN_LEN), 0) \
		
#define HAPTIC_DATA_SEL_KCONTROLS \
	SOC_SINGLE("HAPTIC0_I_DATA_SEL", \
		AUDIO_HAPTIC_CTRL0_REG, HAPTIC0_I_DATA_SEL_OFFSET, \
		max_val_on_bit(HAPTIC0_I_DATA_SEL_LEN), 0), \
    SOC_SINGLE("HAPTIC0_V_DATA_SEL", \
		AUDIO_HAPTIC_CTRL0_REG, HAPTIC0_V_DATA_SEL_OFFSET, \
		max_val_on_bit(HAPTIC0_V_DATA_SEL_LEN), 0), \
    SOC_SINGLE("HAPTIC1_I_DATA_SEL", \
		AUDIO_HAPTIC_CTRL0_REG, HAPTIC1_I_DATA_SEL_OFFSET, \
		max_val_on_bit(HAPTIC1_I_DATA_SEL_LEN), 0), \
    SOC_SINGLE("HAPTIC1_V_DATA_SEL", \
		AUDIO_HAPTIC_CTRL0_REG, HAPTIC1_V_DATA_SEL_OFFSET, \
		max_val_on_bit(HAPTIC1_V_DATA_SEL_LEN), 0) \

#define FS_HAPTIC_FIFO_KCONTROLS \
	SOC_SINGLE("FS_HAPTIC0_UP_AFIFO", \
		FS_CTRL1_REG, FS_HAPTIC0_UP_AFIFO_OFFSET, \
		max_val_on_bit(FS_HAPTIC0_UP_AFIFO_LEN), 0), \
	SOC_SINGLE("FS_HAPTIC1_UP_AFIFO", \
		FS_CTRL1_REG, FS_HAPTIC1_UP_AFIFO_OFFSET, \
		max_val_on_bit(FS_HAPTIC1_UP_AFIFO_LEN), 0), \
	SOC_SINGLE("FS_HAPTIC2_UP_AFIFO", \
		FS_CTRL1_REG, FS_HAPTIC2_UP_AFIFO_OFFSET, \
		max_val_on_bit(FS_HAPTIC2_UP_AFIFO_LEN), 0), \
	SOC_SINGLE("FS_HAPTIC3_UP_AFIFO", \
		FS_CTRL1_REG, FS_HAPTIC3_UP_AFIFO_OFFSET, \
		max_val_on_bit(FS_HAPTIC3_UP_AFIFO_LEN), 0), \
	SOC_SINGLE("FS_HAPTIC0_DN_AFIFO", \
		FS_CTRL1_REG, FS_HAPTIC0_DN_AFIFO_OFFSET, \
		max_val_on_bit(FS_HAPTIC0_DN_AFIFO_LEN), 0), \
	SOC_SINGLE("FS_HAPTIC1_DN_AFIFO", \
		FS_CTRL1_REG, FS_HAPTIC1_DN_AFIFO_OFFSET, \
		max_val_on_bit(FS_HAPTIC1_DN_AFIFO_LEN), 0) \

#define AUDIO_HAPTIC_BYPASS_KCONTROLS \
	SOC_SINGLE("AUDIO_HAPTIC_0_DN_BYPASS", \
		AUDIO_HAPTIC_CTRL0_REG, AUDIO_HAPTIC_0_DN_BYPASS_OFFSET, \
		max_val_on_bit(AUDIO_HAPTIC_0_DN_BYPASS_LEN), 0), \
	SOC_SINGLE("AUDIO_HAPTIC_1_DN_BYPASS", \
		AUDIO_HAPTIC_CTRL0_REG, AUDIO_HAPTIC_1_DN_BYPASS_OFFSET, \
		max_val_on_bit(AUDIO_HAPTIC_1_DN_BYPASS_LEN), 0), \
	SOC_SINGLE("AUDIO_HAPTIC_0_UP_BYPASS", \
		AUDIO_HAPTIC_CTRL0_REG, AUDIO_HAPTIC_0_UP_BYPASS_OFFSET, \
		max_val_on_bit(AUDIO_HAPTIC_0_UP_BYPASS_LEN), 0), \
	SOC_SINGLE("AUDIO_HAPTIC_1_UP_BYPASS", \
		AUDIO_HAPTIC_CTRL0_REG, AUDIO_HAPTIC_1_UP_BYPASS_OFFSET, \
		max_val_on_bit(AUDIO_HAPTIC_1_UP_BYPASS_LEN), 0) \

static const struct snd_kcontrol_new haptic_snd_kcontrols[] = {
	I2S3_CFG_KCONTROLS,
	HAPTIC_DATA_SEL_KCONTROLS,
	FS_HAPTIC_FIFO_KCONTROLS,
	AUDIO_HAPTIC_BYPASS_KCONTROLS,
};

#define HAPTIC_INPUT_OUTPUT_WIDGET \
	SND_SOC_DAPM_INPUT("I2S3_RX_INPUT"), \
	SND_SOC_DAPM_OUTPUT("I2S3_TX_OUTPUT"), \
	SND_SOC_DAPM_INPUT("HAPTIC0_DN_FIFO_INPUT"), \
	SND_SOC_DAPM_OUTPUT("HAPTIC0_UP_FIFO_OUTPUT"), \
    SND_SOC_DAPM_INPUT("HAPTIC1_DN_FIFO_INPUT"), \
    SND_SOC_DAPM_OUTPUT("HAPTIC1_UP_FIFO_OUTPUT"), \
    SND_SOC_DAPM_OUTPUT("HAPTIC2_UP_FIFO_OUTPUT"), \
    SND_SOC_DAPM_OUTPUT("HAPTIC3_UP_FIFO_OUTPUT") \

static const struct snd_kcontrol_new dapm_haptic0_up_switch_controls =
	SOC_DAPM_SINGLE("ENABLE", CODEC_VIR2_REG_ADDR, HAPTIC0_UP_BIT, 1, 0);

static int haptic0_up_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	unused_parameter(kcontrol);
    struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

    AUDIO_LOGI("haptic0_up power event %d", event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC0_UP_AFIFO_CLKEN_OFFSET), 0);
            udelay(CLEAR_FIFO_DELAY_LEN_US);
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC0_UP_AFIFO_CLKEN_OFFSET), BIT(HAPTIC0_UP_AFIFO_CLKEN_OFFSET));
            break;
        case SND_SOC_DAPM_POST_PMD:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC0_UP_AFIFO_CLKEN_OFFSET), 0);
            break;
        default:
            AUDIO_LOGW("power event err:%d", event);
            break;
    }

	return 0;
}

static const struct snd_kcontrol_new dapm_haptic1_up_switch_controls =
	SOC_DAPM_SINGLE("ENABLE", CODEC_VIR2_REG_ADDR, HAPTIC1_UP_BIT, 1, 0);

static int haptic1_up_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	unused_parameter(kcontrol);
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("haptic1_up power event %d", event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC1_UP_AFIFO_CLKEN_OFFSET), 0);
            udelay(CLEAR_FIFO_DELAY_LEN_US);
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC1_UP_AFIFO_CLKEN_OFFSET), BIT(HAPTIC1_UP_AFIFO_CLKEN_OFFSET));
            break;
        case SND_SOC_DAPM_POST_PMD:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC1_UP_AFIFO_CLKEN_OFFSET), 0);
            break;
        default:
            AUDIO_LOGW("power event err:%d", event);
            break;
    }

	return 0;
}

static const struct snd_kcontrol_new dapm_haptic2_up_switch_controls =
	SOC_DAPM_SINGLE("ENABLE", CODEC_VIR2_REG_ADDR, HAPTIC2_UP_BIT, 1, 0);

static int haptic2_up_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	unused_parameter(kcontrol);
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("haptic2_up power event %d", event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC2_UP_AFIFO_CLKEN_OFFSET), 0);
            udelay(CLEAR_FIFO_DELAY_LEN_US);
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC2_UP_AFIFO_CLKEN_OFFSET), BIT(HAPTIC2_UP_AFIFO_CLKEN_OFFSET));
            break;
        case SND_SOC_DAPM_POST_PMD:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
            BIT(HAPTIC2_UP_AFIFO_CLKEN_OFFSET), 0);
            break;
        default:
            AUDIO_LOGW("power event err:%d", event);
            break;
	}

	return 0;
}

static const struct snd_kcontrol_new dapm_haptic3_up_switch_controls =
	SOC_DAPM_SINGLE("ENABLE", CODEC_VIR2_REG_ADDR, HAPTIC3_UP_BIT, 1, 0);

static int haptic3_up_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	unused_parameter(kcontrol);
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("haptic3_up power event %d", event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC3_UP_AFIFO_CLKEN_OFFSET), 0);
            udelay(CLEAR_FIFO_DELAY_LEN_US);
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC3_UP_AFIFO_CLKEN_OFFSET), BIT(HAPTIC3_UP_AFIFO_CLKEN_OFFSET));
            break;
        case SND_SOC_DAPM_POST_PMD:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC3_UP_AFIFO_CLKEN_OFFSET), 0);
            break;
        default:
            AUDIO_LOGW("power event err:%d", event);
            break;
    }

	return 0;
}

static const struct snd_kcontrol_new dapm_haptic0_dn_switch_controls =
	SOC_DAPM_SINGLE("ENABLE", CODEC_VIR2_REG_ADDR, HAPTIC0_DN_BIT, 1, 0);

static int haptic0_dn_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	unused_parameter(kcontrol);
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("haptic0_dn power event %d", event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC0_DN_AFIFO_CLKEN_OFFSET), 0);
            udelay(CLEAR_FIFO_DELAY_LEN_US);
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC0_DN_AFIFO_CLKEN_OFFSET), BIT(HAPTIC0_DN_AFIFO_CLKEN_OFFSET));
            break;
        case SND_SOC_DAPM_POST_PMD:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC0_DN_AFIFO_CLKEN_OFFSET), 0);
            break;
        default:
            AUDIO_LOGW("power event err:%d", event);
            break;
	}

	return 0;
}

static const struct snd_kcontrol_new dapm_haptic1_dn_switch_controls =
	SOC_DAPM_SINGLE("ENABLE", CODEC_VIR2_REG_ADDR, HAPTIC1_DN_BIT, 1, 0);

static int haptic1_dn_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);
	unused_parameter(kcontrol);

	AUDIO_LOGI("haptic1_dn power event %d", event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC1_DN_AFIFO_CLKEN_OFFSET), 0);
            udelay(CLEAR_FIFO_DELAY_LEN_US);
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC1_DN_AFIFO_CLKEN_OFFSET), BIT(HAPTIC1_DN_AFIFO_CLKEN_OFFSET));
            break;
        case SND_SOC_DAPM_POST_PMD:
            snd_soc_component_update_bits_with_lock(codec, CODEC_CLK_EN0_REG,
                BIT(HAPTIC1_DN_AFIFO_CLKEN_OFFSET), 0);
            break;
        default:
            AUDIO_LOGW("power event err:%d", event);
            break;
    }

	return 0;
}

static int i2s3_supply_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	unused_parameter(w);
	unused_parameter(kcontrol);
	AUDIO_LOGI("power event: %d", event);

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		audio_pinctrl_set_pinctrl_mode(AUDIO_PINCTRL_I2S3, AUDIO_PINCTRL_DEFAULT);
		break;
	case SND_SOC_DAPM_POST_PMD:
		audio_pinctrl_set_pinctrl_mode(AUDIO_PINCTRL_I2S3, AUDIO_PINCTRL_IDLE);
		break;
	default:
		AUDIO_LOGW("power event err: %d", event);
		break;
	}

	return 0;
}

#define HAPTIC_SWITCH_WIDGET \
	SND_SOC_DAPM_SWITCH_E("HAPTIC0_UP_SWITCH", SND_SOC_NOPM, 0, 0, \
		&dapm_haptic0_up_switch_controls, haptic0_up_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)), \
	SND_SOC_DAPM_SWITCH_E("HAPTIC1_UP_SWITCH", SND_SOC_NOPM, 0, 0, \
		&dapm_haptic1_up_switch_controls, haptic1_up_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)), \
	SND_SOC_DAPM_SWITCH_E("HAPTIC2_UP_SWITCH", SND_SOC_NOPM, 0, 0, \
		&dapm_haptic2_up_switch_controls, haptic2_up_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)), \
	SND_SOC_DAPM_SWITCH_E("HAPTIC3_UP_SWITCH", SND_SOC_NOPM, 0, 0, \
		&dapm_haptic3_up_switch_controls, haptic3_up_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)), \
	SND_SOC_DAPM_SWITCH_E("HAPTIC0_DN_SWITCH", SND_SOC_NOPM, 0, 0, \
		&dapm_haptic0_dn_switch_controls, haptic0_dn_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)), \
	SND_SOC_DAPM_SWITCH_E("HAPTIC1_DN_SWITCH", SND_SOC_NOPM, 0, 0, \
		&dapm_haptic1_dn_switch_controls, haptic1_dn_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)) \
		
#define HAPTIC_DRV_WIDGET \
	SND_SOC_DAPM_OUT_DRV("I2S3_TX_DRV", \
		I2S3_PCM_CTRL_REG, I2S3_IF_TX_ENA_OFFSET, 0, NULL, 0) \

#define HAPTIC_SUPPLY_WIDGET \
	SND_SOC_DAPM_SUPPLY_S("I2S3_SUPPLY", \
		0, I2S3_PCM_CTRL_REG, I2S3_PCM_CLKEN_OFFSET, 0, \
		i2s3_supply_power_event, \
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)), \
	SND_SOC_DAPM_SUPPLY_S("I2S3_RX_SUPPLY", \
		0, I2S3_PCM_CTRL_REG, I2S3_IF_RX_ENA_OFFSET, 0, NULL, 0) \

static const struct snd_soc_dapm_widget haptic_dapm_widgets[] = {
	HAPTIC_INPUT_OUTPUT_WIDGET,
	HAPTIC_SWITCH_WIDGET,
	HAPTIC_DRV_WIDGET,
	HAPTIC_SUPPLY_WIDGET,
};

static const struct snd_codec_resource haptic_resource = {
	"ASP_CODEC_HAPTIC",
	haptic_snd_kcontrols,
	ARRAY_SIZE(haptic_snd_kcontrols),
	haptic_dapm_widgets,
	ARRAY_SIZE(haptic_dapm_widgets),
};

int __init add_haptic_path_in_list(void)
{
	return add_codec_base_dapm_list(&haptic_resource);
}
device_initcall(add_haptic_path_in_list);
