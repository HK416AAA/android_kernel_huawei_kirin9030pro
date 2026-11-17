/*
 * hwcxext_codec_v1.c
 *
 * hwcxext codec v1 driver
 *
 * Copyright (c) 2022 Huawei Technologies Co., Ltd.
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

#ifdef CONFIG_HUAWEI_DSM_AUDIO
#include <dsm_audio/dsm_audio.h>
#endif

#include "hwcxext_codec_v1.h"
#ifdef AUDIO_AT_DEF
#include "hwcxext_codec_ctl.h"
#endif
/*
 * DAC/ADC Volume
 *
 * max : 74 : 0 dB
 * ( in 1 dB  step )
 * min : 0 : -74 dB
 */
static const DECLARE_TLV_DB_SCALE(adc_tlv, -7400, 100, 0);
static const DECLARE_TLV_DB_SCALE(dac_tlv, -7400, 100, 0);
static const DECLARE_TLV_DB_SCALE(boost_tlv, 0, 1200, 0);

static struct hwcxext_codec_regmap_cfg *g_cx_regmap_cfg = NULL;
static struct hwcxext_reg_ctl_sequence *g_init_regs_seq = NULL;
static struct hwcxext_codec_v1_priv *g_hwcxext_codec = NULL;


static void hwcxext_codec_v1_snd_soc_update_bits(
	struct snd_soc_component *component, unsigned int reg, unsigned int mask, unsigned int value)
{
	int ret;
	ret = snd_soc_component_update_bits(component, reg, mask, value);
	if (ret < 0)
		hwlog_err("%s: update_bits failed = %d\n", __func__, ret);
}

static void hwcxext_codec_v1_snd_soc_write(
	struct snd_soc_component *component, unsigned int reg, unsigned int value)
{
	int ret;
	ret = snd_soc_component_write(component, reg, value);
	if (ret < 0)
		hwlog_err("%s: write failed = %d\n", __func__, ret);
}

static void hwcxext_codec_v1_set_porta(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: porta set in enable=%d\n", __func__, enable);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_CONNECTION_SELECT, 0x00);
	if (enable) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0xC0);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 0x46);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT, 0x46);
		return;
	}
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x03);
	return;
}

static void hwcxext_codec_v1_set_portb(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portb set in enable=%d\n", __func__, enable);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0x00);
	if (enable) { // open portB
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 0x21);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_RIGHT, 0x2);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_LEFT, 0x2);
		return;
	}
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002000);
}

static void hwcxext_codec_v1_set_portc(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portc set in enable=%d\n", __func__, enable);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0x02);
	if (enable) { // open portC
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 0x20);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_RIGHT, 0x0);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_LEFT, 0x0);
		return;
	}
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002000);
}

static void hwcxext_codec_v1_set_portd(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portD set in enable=%d\n", __func__, enable);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0x01);
	if (enable) { // open portD
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x24);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_RIGHT, 0x2);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_LEFT, 0x2);
        hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_1, 0x48);
        hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_1, 0x48);
        return;
	}
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002000);
}

static void hwcxext_codec_v1_set_portg(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portg set in enable=%d\n", __func__, enable);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_CONNECTION_SELECT, 0x01);
	if (enable) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_PIN_CTRL, 0x40);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x8880000c);

        #ifdef CONFIG_HWCXEXT_CODEC_MODULE_HMPC
		    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0x48);
		    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 0x48);
		    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ANALOG_TEST1, 0x7b);
		#else
		    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ANALOG_TEST1, 0x59);
		#endif

		return;
	}

	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0x03);
}

static void hwcxext_codec_v1_set_invert_headset(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: invert headset set in enable=%d\n", __func__, enable);
	if (enable) {
		hwlog_info("%s: set headset as 4 pole\n", __func__);
		/* disable manual mode, clear setting bit */
		hwcxext_codec_v1_snd_soc_update_bits(component,
			HWCXEXT_CODEC_V1_CODEC_TEST39, 0x83f, 0x000);
		/* enable manual mode, set micbias pin as US rule */
		hwcxext_codec_v1_snd_soc_update_bits(component,
			HWCXEXT_CODEC_V1_CODEC_TEST39, 0x81f, 0x81f);
		return;
	}
	hwlog_info("%s: set headset as invert 4 pole\n", __func__);
	/* disable manual mode, clear setting bit */
	hwcxext_codec_v1_snd_soc_update_bits(component,
		HWCXEXT_CODEC_V1_CODEC_TEST39, 0x83f, 0x000);
	/* enable manual mode, set micbias pin as EU rule */
	hwcxext_codec_v1_snd_soc_update_bits(component,
		HWCXEXT_CODEC_V1_CODEC_TEST39, 0x82f, 0x82f);
}

static int hwcxext_codec_v1_i2c_dump_regs(struct hwcxext_codec_regmap_cfg *cfg)
{
    unsigned int *regs = NULL;
    unsigned int value = 0;

    if (IS_ERR_OR_NULL(cfg))
        return -EINVAL;

    if (IS_ERR_OR_NULL(cfg->regmap))
        return -EINVAL;

    regs = cfg->reg_readable;
    if (regs == NULL || cfg->num_readable <= 0) {
        hwlog_info("%s: reg_readable is not set\n", __func__);
        return -EINVAL;
    }

    int i;
    for (i = 0; i < cfg->num_readable; i++) {
        regmap_read(cfg->regmap, regs[i], &value);
        hwlog_info("%s: read reg 0x%08x=0x%08x\n", __func__, regs[i], value);
    }
    return 0;
}

static int hwcxext_codec_v1_i2c_init_regs(struct hwcxext_codec_regmap_cfg *cfg)
{
	hwlog_info("%s: hwcxext_codec_v1_i2c_init_regs in\n", __func__);
	if (IS_ERR_OR_NULL(cfg)) {
		hwlog_err("%s: (cfg) regs failed\n", __func__);
		return -EINVAL;
	}

	if (IS_ERR_OR_NULL(cfg->regmap)) {
		hwlog_err("%s: (cfg regmap) regs failed\n", __func__);
		return -EINVAL;
	}

	if (IS_ERR_OR_NULL(g_init_regs_seq)) {
		hwlog_err("%s: (g_init_regs_seq) regs failed\n", __func__);
		return -EINVAL;
	}

	int ret = hwcxext_i2c_ops_regs_seq(cfg, g_init_regs_seq);
	if (ret) {
		hwlog_err("%s: init regs failed\n", __func__);
		return -ENXIO;
	}
	hwlog_info("%s: hwcxext_codec_v1_i2c_init_regs ok\n", __func__);
	return 0;
}

static void hwcxext_codec_v1_dump_regs(struct hwcxext_mbhc_priv *mbhc)
{
	struct hwcxext_codec_v1_priv *hwcxext_codec = NULL;

	if (mbhc == NULL) {
		hwlog_err("%s: params is inavild\n", __func__);
		return;
	}

	hwcxext_codec = snd_soc_component_get_drvdata(mbhc->component);
	if (hwcxext_codec == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		return;
	}

	hwcxext_codec_v1_i2c_dump_regs(hwcxext_codec->regmap_cfg);
}

static int get_4_pole_headset_type(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	if (kcontrol == NULL || ucontrol == NULL) {
		hwlog_info("%s: input pointer is null", __func__);
		return -EINVAL;
	}
	hwlog_info("%s: user input is %d", __func__, ucontrol->value.integer.value[0]);
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	unsigned int hs_type = snd_soc_component_read(component,
		HWCXEXT_CODEC_V1_DIGITAL_TEST11);
	hwlog_info("%s: hs_type 0x%x\n", __func__, hs_type);
	hs_type = hs_type >> 8;
	if (hs_type & 0x8) {
		ucontrol->value.integer.value[0] = 1;
		hwlog_info("%s: headphone is 4 pole\n", __func__);
	} else if (hs_type & 0x4) {
		ucontrol->value.integer.value[0] = 0;
		hwlog_info("%s: headphone is invert 4 pole\n", __func__);
	}
	return 0;
}

static int set_4_pole_headset_type(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	if (kcontrol == NULL || ucontrol == NULL) {
		hwlog_info("%s: input pointer is null", __func__);
		return -EINVAL;
	}

	if ((g_cx_regmap_cfg != NULL) && (g_cx_regmap_cfg->init_flag <= 1)) {
		hwlog_info("%s: is going init proccess, no need set invert headset type\n", __func__);
		g_cx_regmap_cfg->init_flag++;
		return 0;
	}
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	unsigned int hs_type = snd_soc_component_read(component,
		HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
	if (hs_type & HWCXEXT_CODEC_V1_BIT_31) {
		unsigned int headset_invert_type = ucontrol->value.integer.value[0];
		if (headset_invert_type) {
			hwcxext_codec_v1_set_invert_headset(component, true);
			hwlog_info("%s: set headset_invert_type=%d\n", __func__, headset_invert_type);
			return 1;
		} else {
			hwcxext_codec_v1_set_invert_headset(component, false);
			hwlog_info("%s: set headset_invert_type=%d\n", __func__, headset_invert_type);
			return 1;
		}
	} else {
		hwlog_info("%s: hs_type=%d, no 4 pole headset insert\n", __func__, hs_type);
		return 0;
	}

	return 0;
}

static const struct snd_kcontrol_new hwcxext_codec_v1_snd_controls[] = {
	SOC_DOUBLE_R_TLV("PortD Boost Volume", HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_RIGHT, 0, 3, 0, boost_tlv),
	SOC_DOUBLE_R_TLV("PortC Boost Volume", HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_RIGHT, 0, 3, 0, boost_tlv),
	SOC_DOUBLE_R_TLV("PortB Boost Volume", HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_RIGHT, 0, 3, 0, boost_tlv),
	SOC_DOUBLE_R_TLV("PortB ADC1 Volume", HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_0,
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_0, 0, 0x4a, 0, adc_tlv),
	SOC_DOUBLE_R_TLV("PortD ADC1 Volume", HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_1,
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_1, 0, 0x48, 0, adc_tlv),
	SOC_DOUBLE_R_TLV("PortC ADC1 Volume", HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_2,
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_2, 0, 0x4a, 0, adc_tlv),
	SOC_DOUBLE_R_TLV("DAC1 Volume", HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 0, 0x48, 0, dac_tlv),
	SOC_DOUBLE_R("DAC1 Switch", HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 7,  1, 0),
	SOC_DOUBLE_R_TLV("DAC2 Volume", HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0, 0x4a, 0, dac_tlv),
	SOC_DOUBLE_R("DAC2 Switch", HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 7,  1, 0),
	SOC_SINGLE("PortA HP Amp Switch", HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 7, 1, 0),
	SOC_SINGLE("Headset MIC Loop Switch", HWCXEXT_CODEC_V1_CODEC_TEST11, 8, 3, 0),
	SOC_SINGLE_EXT("INVERT_HEADSET_SWITCH", HWCXEXT_CODEC_V1_DIGITAL_TEST22,
		7, 1, 0, get_4_pole_headset_type, set_4_pole_headset_type),
};

static const struct snd_kcontrol_new dapm_mic_capture_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 0, 1, 0);
static const struct snd_kcontrol_new dapm_speaker_playback_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 1, 1, 0);
static const struct snd_kcontrol_new dapm_left_speaker_playback_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 7, 1, 0);
static const struct snd_kcontrol_new dapm_right_speaker_playback_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 7, 1, 0);

/* VIRTUAL pc kcontrol define */
static const struct snd_kcontrol_new dapm_headset_playback_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 2, 1, 0);
static const struct snd_kcontrol_new dapm_headset_mic_capture_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 3, 1, 0);
static const struct snd_kcontrol_new dapm_rear_linein_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 4, 1, 0);
static const struct snd_kcontrol_new dapm_rear_head_mic_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 5, 1, 0);
static const struct snd_kcontrol_new dapm_rear_headphone_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, 6, 1, 0);

/* dapm kcontrol define */
static const struct snd_kcontrol_new portaouten_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 6, 1, 0);

static const struct snd_kcontrol_new portgouten_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_PORTG_PIN_CTRL, 6, 1, 0);

static const struct snd_kcontrol_new portbinen_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 5, 1, 0);

static const struct snd_kcontrol_new portcinen_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 5, 1, 0);

static const struct snd_kcontrol_new portdinen_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 5, 1, 0);

static const struct snd_kcontrol_new i2sadc1l_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0, 1, 0);

static const struct snd_kcontrol_new i2sadc1r_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 1, 1, 0);

static const struct snd_kcontrol_new i2sadc2l_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 2, 1, 0);

static const struct snd_kcontrol_new i2sadc2r_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 3, 1, 0);

static const struct snd_kcontrol_new i2sdac1l_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0, 1, 0);

static const struct snd_kcontrol_new i2sdac1r_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 1, 1, 0);

static const struct snd_kcontrol_new i2sdac2l_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 2, 1, 0);

static const struct snd_kcontrol_new i2sdac2r_ctl =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 3, 1, 0);

static const char * const dac_enum_text[] = {
	"DAC1 Switch", "DAC2 Switch",
};

static const struct soc_enum porta_dac_enum =
    SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_PORTA_CONNECTION_SELECT, 0, 2, dac_enum_text);

static const struct snd_kcontrol_new porta_mux =
	SOC_DAPM_ENUM("PortA Mux", porta_dac_enum);

static const struct soc_enum portg_dac_enum =
    SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_PORTG_CONNECTION_SELECT, 0, 2, dac_enum_text);

static const struct snd_kcontrol_new portg_mux =
	SOC_DAPM_ENUM("PortG Mux", portg_dac_enum);

static const char *const adc1in_sel_text[] = {
    "PortB Switch", "PortD Switch", "PortC Switch", "Widget15 Switch",
};

static const struct soc_enum adc1in_sel_enum =
	SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0, 4, adc1in_sel_text);

static const struct snd_kcontrol_new adc1_mux =
	SOC_DAPM_ENUM("ADC1 Mux", adc1in_sel_enum);

static const char * const adc2in_sel_text[] = {
	"PortC Switch", "Widget15 Switch",
};

static const struct soc_enum adc2in_sel_enum =
	SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_ADC2_CONNECTION_SELECT, 0, 2, adc2in_sel_text);

static const struct snd_kcontrol_new adc2_mux = SOC_DAPM_ENUM("ADC2 Mux", adc2in_sel_enum);

static const struct snd_kcontrol_new wid15_mix[] = {
	SOC_DAPM_SINGLE("DAC1L Switch", HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_LEFT_0, 7, 1, 1),
	SOC_DAPM_SINGLE("DAC1R Switch", HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_RIGHT_0, 7, 1, 1),
	SOC_DAPM_SINGLE("DAC2L Switch", HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_LEFT_1, 7, 1, 1),
	SOC_DAPM_SINGLE("DAC2R Switch", HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_RIGHT_1, 7, 1, 1),
};

static int hwcxext_codec_v1_afg_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x00);
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x10);
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err: %d\n", __func__, event);
		break;
	}
	return 0;
}

static int hwcxext_codec_v1_portb_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_portc_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_portd_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_widget15_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_MIXER_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_MIXER_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err : %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_adc1_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_adc2_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ADC2_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ADC2_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

int hwcxext_codec_v1_headset_micbias_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		/* PortD Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x04, 0x04);
		/* Headset Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ANALOG_TEST11, 0x02, 0x02);
		break;
	case SND_SOC_DAPM_POST_PMD:
		/* Headset Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ANALOG_TEST11, 0x02, 0x00);
		/* PortD Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x04, 0x00);
		break;
	default:
		hwlog_warn("event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

int hwcxext_codec_v1_portb_micbias_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		/* PortB Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 0x04, 0x04);
		break;
	case SND_SOC_DAPM_POST_PMD:
		/* PortB Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 0x04, 0x00);
		break;
	default:
		hwlog_warn("event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

int hwcxext_codec_v1_portc_micbias_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		/* PortC Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 0x04, 0x04);
		break;
	case SND_SOC_DAPM_POST_PMD:
		/* PortC Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 0x04, 0x00);
		break;
	default:
		hwlog_warn("event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

int hwcxext_codec_v1_portd_micbias_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		/* PortC Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x04, 0x04);
		break;
	case SND_SOC_DAPM_POST_PMD:
		/* PortC Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x04, 0x00);
		break;
	default:
		hwlog_warn("event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_porta_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err : %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_portg_power_event(
	struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err : %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_dac1_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_dac2_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static void hwcxext_codec_v1_unmute_mic(struct work_struct *work)
{
    IN_FUNCTION;
    struct hwcxext_codec_v1_priv *hwcxext_codec =
        container_of(to_delayed_work(work), struct hwcxext_codec_v1_priv, headset_unmute_work);
    if (hwcxext_codec == NULL) {
        hwlog_err("hwcxext_codec is null\n");
        return;
    }
    struct snd_soc_component *component = hwcxext_codec->component;
    if (component == NULL) {
        hwlog_err("hwcxext's component is null\n");
        return;
    }
    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_1, 0x48);
    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_1, 0x48);
}

static void hwcxext_codec_v1_mute_mic(struct snd_soc_component *component, struct hwcxext_codec_v1_priv *hwcxext_codec)
{
    IN_FUNCTION;
    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_1, 0x48 | 0x80);
    hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_1, 0x48 | 0x80);
}

static int hwcxext_codec_v1_headset_mic_capture_event(
    struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
    struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
    struct hwcxext_codec_v1_priv *hwcxext_codec = snd_soc_component_get_drvdata(component);
    if (!hwcxext_codec) {
        hwlog_err("%s: Failed to allocate work data\n", __func__);
        return -ENOMEM;
    }
    cancel_delayed_work_sync(&hwcxext_codec->headset_unmute_work);
    hwlog_info("%s: event:0x%x\n", __func__, event);
    switch (event) {
    case SND_SOC_DAPM_PRE_PMU:
        hwcxext_codec_v1_set_portd(component, true);
        hwcxext_codec_v1_mute_mic(component, hwcxext_codec);
        schedule_delayed_work(&hwcxext_codec->headset_unmute_work, msecs_to_jiffies(MUTE_MIC_TIME_MS));
        break;
    case SND_SOC_DAPM_POST_PMD:
        hwcxext_codec_v1_set_portd(component, false);
        break;
    default:
        hwlog_err("%s: event err: %d\n", __func__, event);
        break;
    }
    return 0;
}

static int hwcxext_codec_v1_headset_playback_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_porta(component, true);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_porta(component, false);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_speaker_playback_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portg(component, true);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portg(component, false);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_mic_capture_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	return 0;
}

static int hwcxext_codec_v1_left_speaker_playback_event(
    struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
    struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
    hwlog_info("%s: event:0x%x\n", __func__, event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 0x80, 0);
            break;
        case SND_SOC_DAPM_POST_PMD:
            hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 0x80, 0x80);
            hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
            break;
        default:
            hwlog_err("%s: event err: %d\n", __func__, event);
            break;
    }

    return 0;
}

static int hwcxext_codec_v1_right_speaker_playback_event(
    struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
    struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
    hwlog_info("%s: event:0x%x\n", __func__, event);
    switch (event) {
        case SND_SOC_DAPM_PRE_PMU:
            hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0x80, 0);
            break;
        case SND_SOC_DAPM_POST_PMD:
            hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0x80, 0x80);
            break;
        default:
            hwlog_err("%s: event err: %d\n", __func__, event);
            break;
    }

    return 0;
}

static int hwcxext_codec_v1_linein_capture_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portc(component, true);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portc(component, false);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_rear_mic_capture_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portb(component, true);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portb(component, false);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

static int hwcxext_codec_v1_rear_headphone_playback_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	if (w == NULL || w->dapm == NULL) {
		hwlog_err("%s: snd_soc_dapm_widget is NULL\n", __func__);
		return -EINVAL;
	}
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_porta(component, true);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_porta(component, false);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}

	return 0;
}

/* dapm widgets */
static const struct snd_soc_dapm_widget hwcxext_codec_v1_dapm_widgets[] = {
	/* Playback */
	SND_SOC_DAPM_INPUT("In AIF"),

	SND_SOC_DAPM_SWITCH("I2S DAC1L", SND_SOC_NOPM, 0, 0, &i2sdac1l_ctl),
	SND_SOC_DAPM_SWITCH("I2S DAC1R", SND_SOC_NOPM, 0, 0, &i2sdac1r_ctl),
	SND_SOC_DAPM_SWITCH("I2S DAC2L", SND_SOC_NOPM, 0, 0, &i2sdac2l_ctl),
	SND_SOC_DAPM_SWITCH("I2S DAC2R", SND_SOC_NOPM, 0, 0, &i2sdac2r_ctl),

	SND_SOC_DAPM_DAC_E("DAC1", NULL, SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_dac1_event, (SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_DAC_E("DAC2", NULL, SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_dac2_event, (SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_MUX("PortA Mux", SND_SOC_NOPM, 0, 0, &porta_mux),
	SND_SOC_DAPM_MUX("PortG Mux", SND_SOC_NOPM, 0, 0, &portg_mux),

	/* SUPPLY */
	SND_SOC_DAPM_SUPPLY("PortA Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_porta_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SUPPLY("PortG Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_portg_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_SWITCH("PortA Out En", SND_SOC_NOPM, 0, 0, &portaouten_ctl),
	SND_SOC_DAPM_SWITCH("PortG Out En", SND_SOC_NOPM, 0, 0, &portgouten_ctl),

	SND_SOC_DAPM_OUTPUT("PORTA"),
	SND_SOC_DAPM_OUTPUT("PORTG"),

	/* Capture */
	SND_SOC_DAPM_OUTPUT("Out AIF"),

	SND_SOC_DAPM_SWITCH("I2S ADC1L", SND_SOC_NOPM, 0, 0, &i2sadc1l_ctl),
	SND_SOC_DAPM_SWITCH("I2S ADC1R", SND_SOC_NOPM, 0, 0, &i2sadc1r_ctl),
	SND_SOC_DAPM_SWITCH("I2S ADC2L", SND_SOC_NOPM, 0, 0, &i2sadc2l_ctl),
	SND_SOC_DAPM_SWITCH("I2S ADC2R", SND_SOC_NOPM, 0, 0, &i2sadc2r_ctl),

	/* ADC */
	SND_SOC_DAPM_ADC_E("ADC1", NULL, SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_adc1_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_ADC_E("ADC2", NULL, SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_adc2_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_MUX("ADC1 Mux", SND_SOC_NOPM, 0, 0, &adc1_mux),
	SND_SOC_DAPM_MUX("ADC2 Mux", SND_SOC_NOPM, 0, 0, &adc2_mux),

	/* SUPPLY */
	SND_SOC_DAPM_SUPPLY("AFG Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_afg_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_SUPPLY("PortB Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_portb_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_SUPPLY("PortC Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_portc_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_SUPPLY("PortD Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_portd_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_SUPPLY("Widget15 Power", SND_SOC_NOPM, 0, 0,
		hwcxext_codec_v1_widget15_power_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_MIXER("Widget15 Mixer", SND_SOC_NOPM, 0, 0,
		wid15_mix, ARRAY_SIZE(wid15_mix)),
	SND_SOC_DAPM_SWITCH("PortB In En", SND_SOC_NOPM, 0, 0, &portbinen_ctl),
	SND_SOC_DAPM_SWITCH("PortC In En", SND_SOC_NOPM, 0, 0, &portcinen_ctl),
	SND_SOC_DAPM_SWITCH("PortD In En", SND_SOC_NOPM, 0, 0, &portdinen_ctl),

	/* MICBIAS */
	SND_SOC_DAPM_MIC("Headset Bias", hwcxext_codec_v1_headset_micbias_event),
	SND_SOC_DAPM_MIC("PortB Mic Bias", hwcxext_codec_v1_portb_micbias_event),
	SND_SOC_DAPM_MIC("PortC Mic Bias", hwcxext_codec_v1_portc_micbias_event),
	SND_SOC_DAPM_MIC("PortD Mic Bias", hwcxext_codec_v1_portd_micbias_event),

	SND_SOC_DAPM_INPUT("PORTB"),
	SND_SOC_DAPM_INPUT("PORTC"),
	SND_SOC_DAPM_INPUT("PORTD"),

	SND_SOC_DAPM_SWITCH_E("Headset_Playback",
		SND_SOC_NOPM, 0, 0, &dapm_headset_playback_switch_controls,
		hwcxext_codec_v1_headset_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Headset_Mic_Capture",
		SND_SOC_NOPM, 0, 0, &dapm_headset_mic_capture_switch_controls,
		hwcxext_codec_v1_headset_mic_capture_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("LineIn Capture",
		SND_SOC_NOPM, 0, 0, &dapm_rear_linein_switch_controls,
		hwcxext_codec_v1_linein_capture_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Rear Mic Capture",
		SND_SOC_NOPM, 0, 0, &dapm_rear_head_mic_switch_controls,
		hwcxext_codec_v1_rear_mic_capture_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Rear Headphone Playback",
		SND_SOC_NOPM, 0, 0, &dapm_rear_headphone_switch_controls,
		hwcxext_codec_v1_rear_headphone_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Speaker_Playback",
		SND_SOC_NOPM, 0, 0, &dapm_speaker_playback_switch_controls,
		hwcxext_codec_v1_speaker_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Mic Capture",
		SND_SOC_NOPM, 0, 0, &dapm_mic_capture_switch_controls,
		hwcxext_codec_v1_mic_capture_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Left_Speaker_Playback",
		SND_SOC_NOPM, 0, 0, &dapm_left_speaker_playback_switch_controls,
		hwcxext_codec_v1_left_speaker_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Right_Speaker_Playback",
		SND_SOC_NOPM, 0, 0, &dapm_right_speaker_playback_switch_controls,
		hwcxext_codec_v1_right_speaker_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_INPUT("Virtual_INPUT"),
	SND_SOC_DAPM_OUTPUT("Virtual_OUTPUT"),
	SND_SOC_DAPM_INPUT("PLAYBACK_INPUT"),
	SND_SOC_DAPM_OUTPUT("PLAYBACK_OUTPUT"),
	SND_SOC_DAPM_INPUT("CAPTURE_INPUT"),
	SND_SOC_DAPM_OUTPUT("CAPTURE_OUTPUT"),

	SND_SOC_DAPM_HP("Headphone Jack", NULL),
	SND_SOC_DAPM_HP("Rear HeadPhone Jack", NULL),
	SND_SOC_DAPM_MIC("Headset Mic Jack", NULL),
	SND_SOC_DAPM_MIC("Rear Mic Jack", NULL),
	SND_SOC_DAPM_MIC("Mic Jack", NULL),
	SND_SOC_DAPM_LINE("LineIn Jack", NULL),
	SND_SOC_DAPM_SPK("Speaker Jack", NULL),
};

static const struct snd_soc_dapm_route hwcxext_codec_v1_dapm_routes[] = {
	/* Playback */
	{"In AIF", NULL, "AFG Power"},
	{"I2S DAC1L", "Switch", "In AIF"},
	{"I2S DAC1R", "Switch", "In AIF"},
	{"I2S DAC2L", "Switch", "In AIF"},
	{"I2S DAC2R", "Switch", "In AIF"},

	{"DAC1", NULL, "I2S DAC1L"},
	{"DAC1", NULL, "I2S DAC1R"},
	{"DAC2", NULL, "I2S DAC2L"},
	{"DAC2", NULL, "I2S DAC2R"},

	{"PortA Mux", "DAC1 Switch", "DAC1"},
	{"PortA Mux", "DAC2 Switch", "DAC2"},
	{"PortG Mux", "DAC1 Switch", "DAC1"},
	{"PortG Mux", "DAC2 Switch", "DAC2"},
	{"Widget15 Mixer", "DAC1L Switch", "DAC1"},
	{"Widget15 Mixer", "DAC1R Switch", "DAC2"},
	{"Widget15 Mixer", "DAC2L Switch", "DAC1"},
	{"Widget15 Mixer", "DAC2R Switch", "DAC2"},

	{"Widget15 Mixer", NULL, "Widget15 Power"},
	{"PortA Out En", "Switch", "PortA Mux"},
	{"PortG Out En", "Switch", "PortG Mux"},
	{"PortA Mux", NULL, "PortA Power"},
	{"PortG Mux", NULL, "PortG Power"},
	{"PortA Out En", NULL, "PortA Power"},
	{"PortG Out En", NULL, "PortG Power"},

	{"PORTA", NULL, "PortA Out En"},
	{"PORTG", NULL, "PortG Out En"},

	/* Capture */
	{"PORTD", NULL, "Headset Bias"},
	{"PortB In En", "Switch", "PORTB"},
	{"PortC In En", "Switch", "PORTC"},
	{"PortD In En", "Switch", "PORTD"},

	{"ADC1 Mux", "PortB Switch", "PortB In En"},
	{"ADC1 Mux", "PortC Switch", "PortC In En"},
	{"ADC1 Mux", "PortD Switch", "PortD In En"},
	{"ADC1 Mux", "Widget15 Switch", "Widget15 Mixer"},
	{"ADC2 Mux", "PortC Switch", "PortC In En"},
	{"ADC2 Mux", "Widget15 Switch", "Widget15 Mixer"},
	{"ADC1", NULL, "ADC1 Mux"},
	{"ADC2", NULL, "ADC2 Mux"},

	{"I2S ADC1L", "Switch", "ADC1"},
	{"I2S ADC1R", "Switch", "ADC1"},
	{"I2S ADC2L", "Switch", "ADC2"},
	{"I2S ADC2R", "Switch", "ADC2"},

	{"Out AIF", NULL, "I2S ADC1L"},
	{"Out AIF", NULL, "I2S ADC1R"},
	{"Out AIF", NULL, "I2S ADC2L"},
	{"Out AIF", NULL, "I2S ADC2R"},

	{"Out AIF", NULL, "AFG Power"},
	{"PortB In En", NULL, "PortB Power"},
	{"PortC In En", NULL, "PortC Power"},
	{"PortD In En", NULL, "PortD Power"},

	{"Headset_Playback", "Switch", "PLAYBACK_INPUT"},
	{"PLAYBACK_OUTPUT", NULL, "Headset_Playback"},
	{"Rear Headphone Playback", "Switch", "PLAYBACK_INPUT"},
	{"PLAYBACK_OUTPUT", NULL, "Rear Headphone Playback"},
	{"Headset_Mic_Capture", "Switch", "CAPTURE_INPUT"},
	{"CAPTURE_OUTPUT", NULL, "Headset_Mic_Capture"},
	{"LineIn Capture", "Switch", "CAPTURE_INPUT"},
	{"CAPTURE_OUTPUT", NULL, "LineIn Capture"},
	{"Rear Mic Capture", "Switch", "CAPTURE_INPUT"},
	{"CAPTURE_OUTPUT", NULL, "Rear Mic Capture"},
	{"Speaker_Playback", "Switch", "Virtual_INPUT"},
	{"Virtual_OUTPUT", NULL, "Speaker_Playback"},
	{"Mic Capture", "Switch", "Virtual_INPUT"},
	{"Virtual_OUTPUT", NULL, "Mic Capture"},
	{"Right_Speaker_Playback", "Switch", "Virtual_INPUT"},
	{"Virtual_OUTPUT", NULL, "Right_Speaker_Playback"},
	{"Left_Speaker_Playback", "Switch", "Virtual_INPUT"},
	{"Virtual_OUTPUT", NULL, "Left_Speaker_Playback"},
};

static int hwcxext_codec_v1_set_dai_sysclk(
	struct snd_soc_dai *codec_dai,
	int clk_id, unsigned int freq, int dir)
{
	return 0;
}

static int hwcxext_codec_v1_set_dai_fmt(struct snd_soc_dai *codec_dai,
	unsigned int fmt)
{
	return 0;
}

static int hwcxext_codec_v1_pcm_hw_params(
	struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	return 0;
}

static int hwcxext_codec_v1_set_dai_bclk_ratio(
	struct snd_soc_dai *dai,
	unsigned int ratio)
{
	return 0;
}

static const struct snd_soc_dai_ops hwevext_codec_v1_ops = {
	.hw_params = hwcxext_codec_v1_pcm_hw_params,
	.set_fmt = hwcxext_codec_v1_set_dai_fmt,
	.set_sysclk = hwcxext_codec_v1_set_dai_sysclk,
	.set_bclk_ratio = hwcxext_codec_v1_set_dai_bclk_ratio,
};

static struct snd_soc_dai_driver hwcxext_codec_v1_dai = {
	.name = "HWCXEXT HiFi",
	.playback = {
		.stream_name = "Playback",
		.channels_min = 1,
		.channels_max = 2,
		.rates = HWCXEXT_CODEC_V1_RATES,
		.formats = HWCXEXT_CODEC_V1_FORMATS,
	},
	.capture = {
		.stream_name = "Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rates = HWCXEXT_CODEC_V1_RATES,
		.formats = HWCXEXT_CODEC_V1_FORMATS,
	},
	.ops = &hwevext_codec_v1_ops,
	.symmetric_rates = 1,
};

static int check_front_headphone_in(
	struct hwcxext_mbhc_priv *mbhc, unsigned int flag, unsigned int flag_pa, int tim)
{
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}

	if (mbhc->item_type) {
		hwlog_info("%s:item_type = %d, is notebook pc item\n", __func__, mbhc->item_type);
		if (flag_pa & HWCXEXT_CODEC_V1_BIT_31) {
			return AUDIO_JACK_HEADSET;
		} else {
			return AUDIO_JACK_PLUG_OUT;
		}
	}
	hwlog_info("%s:item_type = %d, is desk pc item\n", __func__, mbhc->item_type);
	if (((flag & HWCXEXT_CODEC_V1_BIT_02) == 0) &&
		(mbhc->hs_port_status & HWCXEXT_CODEC_V1_AFG_BIT3)) {
		/* front jack plug in, first irq is gpio afg irq, when lineout jack unplug, need to lose it */
		if ((mbhc->front_jack_first_irq) && ((mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTA_BIT1) == 0)) {
			mbhc->front_jack_first_irq = 0;
			return AUDIO_JACK_HEADSET_NOUSE;
		}
		mbhc->front_jack_first_irq = 1;
		/* gpio1(afg) status set 0, means front jack is plug in now */
		mbhc->hs_port_status &= ~(HWCXEXT_CODEC_V1_AFG_BIT3);
		return AUDIO_JACK_HEADSET;
	} else if ((flag & HWCXEXT_CODEC_V1_BIT_02) &&
		((mbhc->hs_port_status & HWCXEXT_CODEC_V1_AFG_BIT3) == 0)) {
		/* front jack plug out, if lineout jack unplug, first irq is gpio afg irq, need to lose it */
		if ((mbhc->front_jack_first_irq) && ((mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTA_BIT1) == 0)) {
			mbhc->front_jack_first_irq = 0;
			return AUDIO_JACK_HEADSET_NOUSE;
		}
		if (flag_pa & HWCXEXT_CODEC_V1_BIT_31) {
			/* When front jack plug out, need to check and set lineout(porta) status */
			mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTA_BIT1;
		} else if ((flag_pa & HWCXEXT_CODEC_V1_BIT_31) == 0) {
			mbhc->hs_port_status &= ~(HWCXEXT_CODEC_V1_PORTA_BIT1);
		}
		mbhc->front_jack_first_irq = 1;
		/* gpio1(afg) status set 1, means front jack is plug out now */
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_AFG_BIT3;
		mbhc->hs_port_status &= ~(HWCXEXT_CODEC_V1_PORTD_BIT5);
		return AUDIO_JACK_PLUG_OUT;
	}
	return AUDIO_JACK_NONE;
}

static void check_porta_status(struct hwcxext_mbhc_priv *mbhc, unsigned int flag, unsigned int flag_pa, int *type_ptr)
{
	if ((flag & HWCXEXT_CODEC_V1_BIT_02) && (flag_pa & HWCXEXT_CODEC_V1_BIT_31) &&
		((mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTA_BIT1) == 0)) {
		hwlog_info("%s:pre type=%d, new type = AUDIO_JACK_LINEOUT, hs_port_status = %d\n",
			__func__, mbhc->hs_status, mbhc->hs_port_status);
		/* lineout jack plug in, porta status set 1 */
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTA_BIT1;
		*type_ptr = AUDIO_JACK_LINEOUT;
	} else if ((flag & HWCXEXT_CODEC_V1_BIT_02) && ((flag_pa & HWCXEXT_CODEC_V1_BIT_31) == 0) &&
		(mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTA_BIT1)) {
		hwlog_info("%s:pre type = %d, new type = AUDIO_JACK_REAR_PLUG_OUT, hs_port_status = %d\n",
			__func__, mbhc->hs_status, mbhc->hs_port_status);
		/* lineout jack plug out, porta status set 0 */
		mbhc->hs_port_status &= ~(HWCXEXT_CODEC_V1_PORTA_BIT1);
		*type_ptr = AUDIO_JACK_REAR_PLUG_OUT;
	}
	return;
}

static void check_portb_status(struct hwcxext_mbhc_priv *mbhc, unsigned int flag, int *type_ptr)
{
	if ((flag & HWCXEXT_CODEC_V1_BIT_31) && ((mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTB_BIT0) == 0)) {
		hwlog_info("%s:pre type = %d, new type = AUDIO_JACK_MIC, hs_port_status = %d\n",
			__func__, mbhc->hs_status, mbhc->hs_port_status);
		/* micin jack plug in, portb status set 1 */
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTB_BIT0;
		*type_ptr = AUDIO_JACK_MIC;
	} else if (((flag & HWCXEXT_CODEC_V1_BIT_31) == 0) && (mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTB_BIT0)) {
		hwlog_info("%s:pre type = %d, new type = AUDIO_JACK_REAR_PLUG_OUT, hs_port_status = %d\n",
			__func__, mbhc->hs_status, mbhc->hs_port_status);
		/* micin jack plug in, portb status set 0 */
		mbhc->hs_port_status &= ~(HWCXEXT_CODEC_V1_PORTB_BIT0);
		*type_ptr = AUDIO_JACK_REAR_PLUG_OUT;
	}
	return;
}

static void check_portc_status(struct hwcxext_mbhc_priv *mbhc, unsigned int flag, int *type_ptr)
{
	if ((flag & HWCXEXT_CODEC_V1_BIT_31) && ((mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTC_BIT2) == 0)) {
		hwlog_info("%s:pre type=%d, new type = AUDIO_JACK_LINEIN, hs_port_status = %d\n",
			__func__, mbhc->hs_status, mbhc->hs_port_status);
		/* linein jack plug in, portc status set 1 */
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTC_BIT2;
		*type_ptr = AUDIO_JACK_LINEIN;
	} else if (((flag & HWCXEXT_CODEC_V1_BIT_31) == 0) && (mbhc->hs_port_status & HWCXEXT_CODEC_V1_PORTC_BIT2)) {
		hwlog_info("%s:pre type = %d, new type = AUDIO_JACK_REAR_PLUG_OUT, hs_port_status = %d\n",
			__func__, mbhc->hs_status, mbhc->hs_port_status);
		/* linein jack plug in, portc status set 0 */
		mbhc->hs_port_status &= ~(HWCXEXT_CODEC_V1_PORTC_BIT2);
		*type_ptr = AUDIO_JACK_REAR_PLUG_OUT;
	}
}

static int check_rear_headphone_in(
	struct hwcxext_mbhc_priv *mbhc, unsigned int flag, unsigned int flag_pa, int tim)
{
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}
	int type = AUDIO_JACK_NONE;
	int *type_ptr = &type;
	/* through judge porta reg and porta status to ensure lineout jack is plug in or out */
	check_porta_status(mbhc, flag, flag_pa, type_ptr);
	/* through judge portb reg and portb status to ensure micin jack is plug in or out */
	flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTB_PIN_SENSE);
	hwlog_info("%s:portb(tim = %d) = : %#04x\n", __func__, tim, flag);
    check_portb_status(mbhc, flag, type_ptr);
	/* through judge portc reg and portc status to ensure linein jack is plug in or out */
	flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTC_PIN_SENSE);
	hwlog_info("%s:portc(tim = %d) = : %#04x\n", __func__, tim, flag);
    check_portc_status(mbhc, flag, type_ptr);
	return type;
}

static int init_check_headset_in(struct hwcxext_mbhc_priv *mbhc)
{
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}
	IN_FUNCTION;
	int type = AUDIO_JACK_NONE;
	unsigned int afg_flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_AFG_GPIO_DATA);
	unsigned int port_flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
	hwlog_info("%s:afg = %#04x, porta = %#04x\n", __func__, afg_flag, port_flag);

	if (mbhc->item_type) {
		hwlog_info("%s:item_type = %d, is notebook pc item\n", __func__, mbhc->item_type);
		if (port_flag & HWCXEXT_CODEC_V1_BIT_31) {
			return AUDIO_JACK_HEADSET;
		} else {
			return AUDIO_JACK_PLUG_OUT;
		}
	}

	if ((afg_flag & HWCXEXT_CODEC_V1_BIT_02) == 0) {
		type = AUDIO_JACK_HEADSET;
		mbhc->hs_port_status = 0;
		hwlog_info("%s:front jack plug in, hs_port_status = %d\n", __func__, mbhc->hs_port_status);
	} else {
		type = AUDIO_JACK_PLUG_OUT;
		mbhc->hs_port_status = 8;
		if (port_flag & HWCXEXT_CODEC_V1_BIT_31) {
			mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTA_BIT1;
			hwlog_info("%s:lineout jack plug in\n", __func__);
		}
		hwlog_info("%s:no front jack plug in, hs_port_status = %d\n", __func__, mbhc->hs_port_status);
	}
	port_flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTB_PIN_SENSE);
	hwlog_info("%s:portb = %#04x\n", __func__, port_flag);
	if (port_flag & HWCXEXT_CODEC_V1_BIT_31) {
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTB_BIT0;
		hwlog_info("%s:micin jack plug in, hs_port_status = %d\n", __func__, mbhc->hs_port_status);
	}
	port_flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTC_PIN_SENSE);
	hwlog_info("%s:portc = %#04x\n", __func__, port_flag);
	if (port_flag & HWCXEXT_CODEC_V1_BIT_31) {
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTC_BIT2;
		hwlog_info("%s:linein jack plug in, hs_port_status = %d\n", __func__, mbhc->hs_port_status);
	}
	return type;
}

static int hwcxext_codec_v1_mbhc_check_headset_in(
	struct hwcxext_mbhc_priv *mbhc, int timeouts)
{
	int type = AUDIO_JACK_NONE;
	int tim = 0;

	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}
	if (timeouts == 0) {
		type = init_check_headset_in(mbhc);
		hwlog_info("%s:timeouts = %d, is not irq, is init headset jack status, type = %d\n",
			__func__, timeouts, type);
		return type;
	}

	do {
		unsigned int flag = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_AFG_GPIO_DATA);
		hwlog_info("%s:flag_afg(tim = %d) = : %#04x\n", __func__, tim, flag);
		unsigned int flag_pa = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
		hwlog_info("%s:porta(tim = %d) = : %#04x\n", __func__, tim, flag_pa);
		int front_headphone_type = check_front_headphone_in(mbhc, flag, flag_pa, tim);
		if (front_headphone_type != AUDIO_JACK_NONE) {
			hwlog_info("%s:front headphone, pre type = %d, new type = %d, hs_port_status = %d\n",
				__func__, mbhc->hs_status, front_headphone_type, mbhc->hs_port_status);
			return front_headphone_type;
		}
		int rear_headphone_type = check_rear_headphone_in(mbhc, flag, flag_pa, tim);
		if (rear_headphone_type != AUDIO_JACK_NONE) {
			hwlog_info("%s:rear headphone, pre type = %d, new type = %d, hs_port_status = %d\n",
				__func__, mbhc->hs_status, rear_headphone_type, mbhc->hs_port_status);
			return rear_headphone_type;
		}
		unsigned int flag_btn = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_CODEC_TEST37);
		if (((mbhc->hs_port_status & HWCXEXT_CODEC_V1_AFG_BIT3) == 0) &&
			(flag_btn & HWCXEXT_CODEC_V1_BTN_PRESS_BIT)) {
			hwlog_info("%s:flag_btn = %#04x, is btn\n", __func__, flag_btn);
			mbhc->hs_status = AUDIO_JACK_HEADSET;
		}
		type = mbhc->hs_status;
		if (tim < timeouts)
			msleep(CODEC_HS_CHECK_DELAY_TIME_MS); /* delay 100 ms */
		tim += CODEC_HS_CHECK_DELAY_TIME_MS;
	} while (tim <= timeouts);
	hwlog_info("%s:pre type = %d, new type = %d, hs_port_status = %d\n",
		__func__, mbhc->hs_status, type, mbhc->hs_port_status);
	return type;
}

static void hwcxext_codec_v1_enable_micbias_for_hs_detect(
	struct hwcxext_mbhc_priv *mbhc)
{
	IN_FUNCTION;
	UNUSED_PARAMETER(mbhc);
}

static void hwcxext_codec_v1_disable_micbias_for_hs_detect(
	struct hwcxext_mbhc_priv *mbhc)
{
	IN_FUNCTION;
	/* disable manual mode, disable micbias in mic */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST39,
		0x83f, 0x000);
	hwcxext_codec_v1_snd_soc_write(mbhc->component, HWCXEXT_CODEC_V1_ANALOG_TEST2, 0x00);
	int mic_cur_threshold = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_ANALOG_TEST2);
	hwlog_info("%s: 4 pole hs plug out, set mic_cur_threshold = %#04x\n", __func__, mic_cur_threshold);
	struct snd_soc_dapm_context *dapm = NULL;
	dapm = snd_soc_component_get_dapm(mbhc->component);
	if (IS_ERR_OR_NULL(dapm)) {
		hwlog_err("%s: dapm is NULL\n", __func__);
		return;
	}
	snd_soc_dapm_disable_pin_unlocked(dapm, "Headset_Mic_Capture");
	snd_soc_dapm_disable_pin_unlocked(dapm, "Headset_Playback");
	snd_soc_dapm_sync(dapm);
}

static void hwcxext_codec_v1_clear_irq(struct hwcxext_mbhc_priv *mbhc)
{
	struct snd_soc_dapm_context *dapm = NULL;

	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return;
	}

	IN_FUNCTION;
	dapm = snd_soc_component_get_dapm(mbhc->component);

	/* Use GPOI0 as interrupt pin */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_UM_INTERRUPT_CRTL,
		0x10, 0x10);
}

static void hwcxext_codec_v1_enable_jack_detect(struct hwcxext_mbhc_priv *mbhc)
{
	struct snd_soc_dapm_context *dapm = NULL;

	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return;
	}

	IN_FUNCTION;
	dapm = snd_soc_component_get_dapm(mbhc->component);

	/* Enables unsolitited message on PortA - PortC */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_PORTA_UNSOLICITED_RESPONSE, 0xff, 0x80);
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_PORTB_UNSOLICITED_RESPONSE, 0xff, 0x80);
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_PORTC_UNSOLICITED_RESPONSE, 0xff, 0x80);

	/* support both nokia and apple headset set. Monitor time = 275 ms */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_DIGITAL_TEST15, 0xff, 0x87);

	/* Disable TIP detection */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_ANALOG_TEST12, 0xfff, 0x300);

	/* Switch MusicD3Live pin to GPIO */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_DIGITAL_TEST1, 0xff, 0);
}

static unsigned int hwcxext_codec_v1_get_hs_type(struct hwcxext_mbhc_priv *mbhc)
{
	unsigned int hs_type;

	hs_type = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_DIGITAL_TEST11);
	hwlog_info("%s: hs_type 0x%x\n", __func__, hs_type);
	hs_type = hs_type >> 8;
	if (hs_type & 0x8) {
		hwlog_info("%s: headphone is 4 pole\n", __func__);
		return AUDIO_JACK_HEADSET;
	} else if (hs_type & 0x4) {
		hwlog_info("%s: headphone is invert 4 pole\n", __func__);
		return AUDIO_JACK_INVERT;
	}
	hwlog_info("%s: headphone is 3 pole\n", __func__);
	return AUDIO_JACK_HEADPHONE;
}

static unsigned int hwcxext_codec_v1_repeat_get_correct_hs_type(
	struct hwcxext_mbhc_priv *mbhc,
	struct hwcxext_codec_v1_priv *hwcxext_codec)
{
	unsigned int type = AUDIO_JACK_NONE;
	unsigned int count = 0;
	unsigned long timeout;
	unsigned int status;

	timeout = jiffies + msecs_to_jiffies(HS_RECOGNIZE_LIMIT_TIME_MS);
	msleep(HS_RECOGNIZE_BEGIN_DELAY);
	mbhc->hs_type_recognize_timeout = 0;
	do {
		status = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_DIGITAL_TEST10);
		hwlog_info("%s: TEST10_status = %x\n", __func__, status);
		type = hwcxext_codec_v1_get_hs_type(mbhc);
		hwlog_info("%s: type:%d, count:%d\n", __func__, type, count++);
		if (time_after(jiffies, timeout)) {
			hwlog_warn("%s: it exceed the limit time\n", __func__);
			mbhc->hs_type_recognize_timeout = 1;
			break;
		}
		msleep(HS_RECOGNIZE_PROCESS_DELAY);
	} while ((status & HWCXEXT_CODEC_V1_BIT_07) == 0);

	hwlog_info("%s: hs type is %u\n", __func__, type);
	return type;
}

static int hwcxext_codec_v1_hs_type_recognize(
	struct hwcxext_mbhc_priv *mbhc)
{
	unsigned int type = AUDIO_JACK_NONE;
	struct hwcxext_codec_v1_priv *hwcxext_codec = NULL;

	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}

	hwcxext_codec = snd_soc_component_get_drvdata(mbhc->component);
	if (hwcxext_codec == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		return AUDIO_JACK_NONE;
	}

	type = hwcxext_codec_v1_repeat_get_correct_hs_type(mbhc, hwcxext_codec);
	if (mbhc->hs_type_recognize_timeout == 1) {
		hwlog_info("%s: hs type recognize timeout, need try again\n", __func__);
		if ((mbhc->mbhc_cb != NULL) && (mbhc->mbhc_cb->set_hs_detec_restart != NULL))
			mbhc->mbhc_cb->set_hs_detec_restart(mbhc);
		type = hwcxext_codec_v1_repeat_get_correct_hs_type(mbhc, hwcxext_codec);
		mbhc->hs_type_recognize_timeout = 0;
	}
	if (type == AUDIO_JACK_INVERT) {
		hwlog_info("%s: out invert 4 pole is handle as 4 pole\n", __func__);
		type = AUDIO_JACK_HEADSET;
		/* disable manual mode, disable micbias in mic */
		hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
			HWCXEXT_CODEC_V1_CODEC_TEST39, 0x83f, 0x000);
		/* enable manual mode, enable micbias in mic */
		hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
			HWCXEXT_CODEC_V1_CODEC_TEST39, 0x82f, 0x82f);
	} else if (type == AUDIO_JACK_HEADSET) {
		hwlog_info("%s: out handle as 4 pole\n", __func__);
		/* disable manual mode, disable micbias in mic */
		hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
			HWCXEXT_CODEC_V1_CODEC_TEST39, 0x83f, 0x000);
		/* enable manual mode, enable micbias in mic */
		hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
			HWCXEXT_CODEC_V1_CODEC_TEST39, 0x81f, 0x81f);
	}

	hwcxext_codec_v1_snd_soc_write(mbhc->component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x24);
	int portd_ctl = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL);
	hwlog_info("%s: end hs type recognize, set portd_ctl = %#04x\n", __func__, portd_ctl);
	if (type == AUDIO_JACK_HEADSET) {
		hwcxext_codec_v1_snd_soc_write(mbhc->component, HWCXEXT_CODEC_V1_ANALOG_TEST2, 0x10);
		int mic_cur_threshold = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_ANALOG_TEST2);
		hwlog_info("%s: hs type is 4 pole, set mic_cur_threshold = %#04x\n", __func__, mic_cur_threshold);
		mbhc->hs_port_status |= HWCXEXT_CODEC_V1_PORTD_BIT5;
	}
	return type;
}

static int hwcxext_codec_v1_btn_type_recognize(
	struct hwcxext_mbhc_priv *mbhc, int *report, int *status)
{
	int mb_status = 0;

	if ((mbhc == NULL) || (report == NULL) || (status == NULL)) {
		hwlog_err("%s: params is inavild\n", __func__);
		return -EFAULT;
	}

	mb_status = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST37);

	/* clear mb status */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST37,
		0x7ff, 0x7ff);
	mb_status = mb_status & 0x7ff;
	*status = (mb_status & (BTN_PRESS | BTN_RELEASED | BTN_PRESS_CNT));
	*report = (mb_status >> HWCXEXT_CODEC_V1_MB_UP);
	hwlog_info("%s: mb_status 0x%04x\n", __func__, mb_status);
	return 0;
}

static void hwcxext_codec_v1_set_hs_detec_restart(
	struct hwcxext_mbhc_priv *mbhc)
{
	if (mbhc == NULL) {
		hwlog_err("%s: params is inavild\n", __func__);
		return;
	}

	hwcxext_codec_v1_snd_soc_write(mbhc->component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST38, 0x20, 0x00);
	int restart = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST38);
	int portd_ctl = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL);
	int micbias = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_CODEC_TEST39);
	hwlog_info("%s: restart status = %d, portd_ctl = %#04x, micbias = %#04x\n", __func__, restart, portd_ctl, micbias);
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST38, 0x20, 0x20);
}

static struct hwcxext_mbhc_cb mbhc_cb = {
	.mbhc_check_headset_in = hwcxext_codec_v1_mbhc_check_headset_in,
	.enable_micbias = hwcxext_codec_v1_enable_micbias_for_hs_detect,
	.disable_micbias = hwcxext_codec_v1_disable_micbias_for_hs_detect,
	.enable_jack_detect = hwcxext_codec_v1_enable_jack_detect,
	.get_hs_type_recognize = hwcxext_codec_v1_hs_type_recognize,
	.get_btn_type_recognize = hwcxext_codec_v1_btn_type_recognize,
	.dump_regs = hwcxext_codec_v1_dump_regs,
	.clear_irq = hwcxext_codec_v1_clear_irq,
	.set_hs_detec_restart = hwcxext_codec_v1_set_hs_detec_restart,
};

static int hwcxext_codec_v1_init_pmu_audioclk(
	struct snd_soc_component *component,
	struct hwcxext_codec_v1_priv *hwcxext_codec)
{
	bool need_pmu_audioclk = false;
	int ret;

	need_pmu_audioclk = of_property_read_bool(component->dev->of_node,
		"clk_pmuaudioclk");
	if (!need_pmu_audioclk) {
		hwlog_info("%s: it no need pmu audioclk\n", __func__);
		return 0;
	}

	hwcxext_codec->mclk = devm_clk_get(&hwcxext_codec->i2c->dev,
		"clk_pmuaudioclk");
	if (IS_ERR_OR_NULL(hwcxext_codec->mclk)) {
		hwlog_err("%s: unable to get mclk\n", __func__);
		return PTR_ERR(hwcxext_codec->mclk);
	}

	ret = clk_prepare_enable(hwcxext_codec->mclk);
	if (ret) {
		hwlog_err("%s: unable to enable mclk\n", __func__);
		return ret;
	}

	return 0;
}

static void hwcxext_codec_v1_store_regmap(struct hwcxext_codec_regmap_cfg *cfg)
{
	if (cfg == NULL) {
		hwlog_err("%s: cfg is null\n", __func__);
		return;
	}
	g_cx_regmap_cfg = cfg;
}

static int hwcxext_codec_v1_soft_reset(struct hwcxext_codec_regmap_cfg *cfg)
{
	int ret;

	pr_info("%s function comein\n", __func__);
	if (cfg == NULL) {
		pr_err("%s: cfg is null\n", __func__);
		return -EINVAL;
	}

	ret = regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_CODEC_TEST24, 0xCBA);
	ret |= regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_CODEC_TEST24, 0xAAA);
	ret |= regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_CODEC_TEST25, 0xBC5);
	ret |= regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_CODEC_TEST25, 0x555);
	ret |= regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_DIGITAL_TEST2, 0x001);
	if (ret)
		pr_err("%s: regmap_write HWCXEXT_CODEC_V1_DIGITAL_TEST2 fail, errorcode = %d\n", __func__, ret);
	mdelay(CODEC_RESET_DELAY_TIME_MS);

	int i;
	for (i = 0; i < CODEC_RESET_MAX_RETRY_TIMES; i++) {
		ret = regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST3_MSB, 0x03);
		if (ret == 0) {
			pr_info("%s regmap_write HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST3_MSB success\n", __func__);
			break;
		}
		pr_err("%s regmap_write HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST3_MSB fail, loop cnt = %d, errorcode = %d\n",
			__func__, i, ret);
		mdelay(1);
	}

	pr_info("%s function comeout\n", __func__);
	return ret;
}

static int hwcxext_codec_v1_reboot_callback(struct notifier_block *self,
	unsigned long event, void *data)
{
	IN_FUNCTION;
	int ret = hwcxext_codec_v1_soft_reset(g_cx_regmap_cfg);
	if (ret)
		hwlog_err("%s: codec soft reset failed\n", __func__);

	return NOTIFY_OK;
}

struct notifier_block codec_reboot_notifier = {
	.notifier_call = hwcxext_codec_v1_reboot_callback,
};

void hwcxext_codec_v1_reboot_notifier(bool on)
{
	int ret;

	if (on) {
		ret = register_reboot_notifier(&codec_reboot_notifier);
		if (ret)
			hwlog_err("%s: reboot notifier register failed: %d\n", __func__, ret);
		return;
	}
	ret = unregister_reboot_notifier(&codec_reboot_notifier);
	if (ret)
		hwlog_err("%s: reboot notifier unregister failed: %d\n", __func__, ret);
}

static int hwcxext_codec_v1_probe(struct snd_soc_component *component)
{
    IN_FUNCTION;
    struct hwcxext_codec_v1_priv *hwcxext_codec = snd_soc_component_get_drvdata(component);

    hwlog_info("%s function comein hwcxext cx11880 probe v1 in\n", __func__);

    if (hwcxext_codec == NULL) {
        hwlog_info("%s: hwcxext_codec is invalid\n", __func__);
        return -EINVAL;
    }

    hwcxext_codec->component = component;
    int ret = hwcxext_codec_v1_init_pmu_audioclk(component, hwcxext_codec);
    if (ret) {
        hwlog_err("%s: hwcxext_codec_v1_init_pmu_audioclk failed\n", __func__);
        return ret;
    }

    ret = hwcxext_i2c_ops_regs_seq(hwcxext_codec->regmap_cfg, hwcxext_codec->init_regs_seq);
    if (ret) {
        hwlog_err("%s: init regs failed\n", __func__);
        return -ENXIO;
    }

    hwlog_info("%s: hwcxext_mbhc_init is ininin\n", __func__);
    ret = hwcxext_mbhc_init(&hwcxext_codec->i2c->dev, component, &hwcxext_codec->mbhc_data, &mbhc_cb);
    if (ret) {
        hwlog_err("%s: hwcxext mbhc init failed\n", __func__);
        return ret;
    }
    hwlog_info("%s: hwcxext_mbhc_init is outoutout\n", __func__);

    INIT_DELAYED_WORK(&hwcxext_codec->headset_unmute_work, hwcxext_codec_v1_unmute_mic);

    hwcxext_codec_v1_set_porta(component, false);
    hwcxext_codec_v1_set_portb(component, false);
    hwcxext_codec_v1_set_portc(component, false);
    hwcxext_codec_v1_set_portd(component, false);
    hwcxext_codec_v1_set_portg(component, false);

    hwcxext_mbhc_detect_init_state(hwcxext_codec->mbhc_data);

#ifdef AUDIO_AT_DEF
	static hwcxext_codec_ctrl_ops_t codec_ctrl_ops = {
		.set_hp_us = hwcxext_codec_v1_set_invert_headset,
		.enable_hp_playback = hwcxext_codec_v1_set_porta,
		.enable_hp_capture = hwcxext_codec_v1_set_portd,
		.enable_speaker = hwcxext_codec_v1_set_portg,
		.snd_soc_update_bits = hwcxext_codec_v1_snd_soc_update_bits,
	};
	ret = hwcxext_codec_ctrl_init(hwcxext_codec, &codec_ctrl_ops);
	if (ret < 0) {
		hwlog_err("%s error: hwcxext_codec_ctrl_init failed %d.\n", __func__, ret);
		return ret;
	}
#endif

    OUT_FUNCTION;

    return 0;
}

static void hwcxext_codec_v1_remove(struct snd_soc_component *component)
{
	struct hwcxext_codec_v1_priv *hwcxext_codec =
		snd_soc_component_get_drvdata(component);

	if (hwcxext_codec == NULL) {
		hwlog_info("%s: hwcxext_codec is invalid\n", __func__);
		return;
	}
	hwlog_info("%s function v1_remove cx11880 remove\n", __func__);
	cancel_delayed_work_sync(&hwcxext_codec->headset_unmute_work);
	clk_disable_unprepare(hwcxext_codec->mclk);
	hwcxext_mbhc_exit(&hwcxext_codec->i2c->dev, hwcxext_codec->mbhc_data);
}

static const struct snd_soc_component_driver soc_component_hwcxext_codec_v1 = {
	.probe			= hwcxext_codec_v1_probe,
	.remove			= hwcxext_codec_v1_remove,
	.controls		= hwcxext_codec_v1_snd_controls,
	.num_controls		= ARRAY_SIZE(hwcxext_codec_v1_snd_controls),
	.dapm_widgets		= hwcxext_codec_v1_dapm_widgets,
	.num_dapm_widgets	= ARRAY_SIZE(hwcxext_codec_v1_dapm_widgets),
	.dapm_routes		= hwcxext_codec_v1_dapm_routes,
	.num_dapm_routes	= ARRAY_SIZE(hwcxext_codec_v1_dapm_routes),
};

struct hwcxext_codec_info_ctl_ops hwcxext_codec_v1_info_ctl_ops = {
	.dump_regs  = hwcxext_codec_v1_i2c_dump_regs,
	.init_regs = hwcxext_codec_v1_i2c_init_regs,
};

static int hwcxext_codec_v1_get_hardvison_status(
	struct regmap *regmap)
{
	int ret;
	unsigned int vendor_id = 0;
	unsigned int revison_id = 0;

	ret = regmap_read(regmap, HWCXEXT_CODEC_V1_VENDOR_ID, &vendor_id);
	if (ret) {
		hwlog_err("Failed to get vendor_id: %d\n", __func__, ret);
		ret = -ENXIO;
		goto hwcxext_codec_v1_get_hardvison_status_err;
	}

	ret = regmap_read(regmap, HWCXEXT_CODEC_V1_REVISION_ID, &revison_id);
	if (ret) {
		hwlog_err("Failed to get revison_id: %d\n", __func__, ret);
		ret = -ENXIO;
		goto hwcxext_codec_v1_get_hardvison_status_err;
	}
	hwlog_info("%s: get chip version: %08x,%08x\n",
		__func__, vendor_id, revison_id);
	return 0;

hwcxext_codec_v1_get_hardvison_status_err:
	return ret;
}

static int hwcxext_codec_v1_register_component(struct device *dev)
{
	int ret;

	ret = devm_snd_soc_register_component(dev,
		&soc_component_hwcxext_codec_v1, &hwcxext_codec_v1_dai, 1);
	if (ret != 0) {
		hwlog_err("%s: failed to register codec: %d\n", __func__, ret);
		return -EFAULT;
	}
	OUT_FUNCTION;
	return 0;
}

static void hwcxext_codec_v1_info_set(struct i2c_client *i2c_client,
	struct hwcxext_codec_v1_priv *hwcxext_codec)
{
	hwcxext_codec_mute_gpio_down_ops(i2c_client);
	hwcxext_codec_register_info_ctl_ops(&hwcxext_codec_v1_info_ctl_ops);
	hwcxext_codec_info_store_regmap(hwcxext_codec->regmap_cfg);
	hwcxext_codec_v1_store_regmap(hwcxext_codec->regmap_cfg);
	hwcxext_codec_info_set_ctl_support(true);
	g_hwcxext_codec = hwcxext_codec;
	return;
}

static int hwcxext_codec_v1_i2c_probe(struct i2c_client *i2c_client, const struct i2c_device_id *id)
{
    struct device *dev = &i2c_client->dev;
    struct hwcxext_codec_v1_priv *hwcxext_codec = NULL;
    int ret;

    IN_FUNCTION;
    hwcxext_codec = devm_kzalloc(dev, sizeof(struct hwcxext_codec_v1_priv), GFP_KERNEL);
    if (hwcxext_codec == NULL) {
        hwlog_err("%s error: devm_kzalloc\n", __func__);
        return -ENOMEM;
    }

    i2c_set_clientdata(i2c_client, hwcxext_codec);
    hwcxext_codec->i2c = i2c_client;
    dev_set_name(&i2c_client->dev, "%s", "hwcxext_codec");

    ret = hwcxext_i2c_regmap_init(i2c_client, hwcxext_codec);
    if (ret < 0) {
        hwlog_err("%s error: hwcxext_codec_v1_i2c_probe_err1 init =%d.\n", __func__, ret);
        goto hwcxext_codec_v1_i2c_probe_err1;
    }

    ret = hwcxext_codec_v1_get_hardvison_status(hwcxext_codec->regmap_cfg->regmap);
    if (ret < 0) {
        hwlog_err("%s error: hwcxext_codec_v1_i2c_probe_err1 status =%d.\n", __func__, ret);
        goto hwcxext_codec_v1_i2c_probe_err1;
    }

    ret = hwcxext_i2c_parse_dt_reg_ctl(i2c_client, &hwcxext_codec->init_regs_seq, "init_regs");
    if (ret < 0) {
        hwlog_err("%s error: hwcxext_codec_v1_i2c_probe_err2 reg_ctl =%d.\n", __func__, ret);
        goto hwcxext_codec_v1_i2c_probe_err2;
    }
    g_init_regs_seq = hwcxext_codec->init_regs_seq;

    ret = hwcxext_codec_v1_register_component(&i2c_client->dev);
    if (ret < 0) {
        hwlog_err("%s error: hwcxext_codec_v1_i2c_probe_err3 component =%d.\n", __func__, ret);
        goto hwcxext_codec_v1_i2c_probe_err3;
    }
    hwcxext_codec_v1_info_set(i2c_client, hwcxext_codec);

    OUT_FUNCTION;
    return 0;

hwcxext_codec_v1_i2c_probe_err3:
    hwcxext_i2c_free_reg_ctl(&hwcxext_codec->init_regs_seq);
hwcxext_codec_v1_i2c_probe_err2:
    hwcxext_i2c_regmap_deinit(hwcxext_codec->regmap_cfg);
hwcxext_codec_v1_i2c_probe_err1:
    devm_kfree(dev, hwcxext_codec);
    return ret;
}

int hwcxext_codec_v1_enter_d4_power_mode(void)
{
    IN_FUNCTION;
    unsigned int status = 0;

    hwcxext_codec_v1_snd_soc_update_bits(
        g_hwcxext_codec->component, HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x10);
    hwcxext_codec_v1_snd_soc_update_bits(g_hwcxext_codec->component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x04);
    for (int time = 0; time < CODEC_AFG_POWER_STATE_MAX_TIMES; time++) {
        if (regmap_read(g_hwcxext_codec->regmap_cfg->regmap, HWCXEXT_CODEC_V1_AFG_POWER_STATE, &status)) {
            hwlog_err("%s: read reg 0x%x failed \n", __func__, HWCXEXT_CODEC_V1_AFG_POWER_STATE);
            return -EIO;
        }
		
        if (status == CODEC_D4_PWR_STATE) {
            msleep(10);
            return 0;
        }
        msleep(CODEC_AFG_POWER_STATE_DELAY);
    }
    return -ETIMEDOUT;
}

void hwcxext_codec_v1_power_down(void)
{
    IN_FUNCTION;
    if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
        hwlog_err("%s: hwcxext_codec is invalid\n", __func__);
        return;
    }

    for (int i = 0; i < CODEC_ENTER_D4_POWER_MODE_RETRIES; i++) {
        int ret = hwcxext_codec_v1_enter_d4_power_mode();
        if (ret == 0) {
            hwlog_info("%s hwcxext codec enter d4 power ok\n", __func__);
            return;
        }
        hwlog_warn("%s hwcxext codec retry enter d4, errorcode = %d\n", __func__, ret);
    }
    hwlog_err("%s hwcxext codec enter d4 power fail\n", __func__);
    return;
}

void hwcxext_codec_v1_power_up(void)
{
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		return;
	}
    IN_FUNCTION;
    hwcxext_codec_v1_snd_soc_update_bits(g_hwcxext_codec->component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x00);
    hwcxext_codec_v1_snd_soc_update_bits(
        g_hwcxext_codec->component, HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x00);
    OUT_FUNCTION;
    return;
}

static int hwcxext_codec_v1_i2c_remove(struct i2c_client *client)
{
	struct hwcxext_codec_v1_priv *hwcxext_codec = i2c_get_clientdata(client);
	IN_FUNCTION;
	if (hwcxext_codec == NULL) {
		hwlog_err("%s: hwcxext_codec invalid\n", __func__);
		return -EINVAL;
	}
	hwcxext_i2c_free_reg_ctl(&hwcxext_codec->init_regs_seq);
	hwcxext_codec_info_set_ctl_support(false);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0))
	snd_soc_unregister_codec(&client->dev);
#endif
	hwcxext_i2c_regmap_deinit(hwcxext_codec->regmap_cfg);
#ifdef AUDIO_AT_DEF
	hwcxext_codec_ctrl_deinit();
#endif
	return 0;
}

static void hwcxext_codec_v1_i2c_shutdown(struct i2c_client *client)
{
	IN_FUNCTION;
	audio_log_write_enable_change(0); /* disable write audio log */
	struct hwcxext_codec_v1_priv *hwcxext_codec = i2c_get_clientdata(client);
	if (hwcxext_codec == NULL || hwcxext_codec->regmap_cfg == NULL) {
		pr_err("%s: hwcxext_codec invalid\n", __func__);
		return;
	}
	pr_info("%s function comein, freeze_flag = %d\n", __func__, hwcxext_codec->regmap_cfg->freeze_flag);
	if (hwcxext_codec->regmap_cfg->freeze_flag == 1) {
		hwcxext_codec->regmap_cfg->freeze_flag = 0;
		pr_info("%s s4 comein\n", __func__);
		return;
	}
	int ret = hwcxext_codec_v1_soft_reset(hwcxext_codec->regmap_cfg);
	if (ret)
		pr_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);
	pr_info("%s function comeout\n", __func__);
	return;
}

static const struct i2c_device_id hwcxext_codec_v1_i2c_id[] = {
	{"hwcxext_codec_v1", 0 },
	{}
};
MODULE_DEVICE_TABLE(i2c, hwcxext_codec_v1_i2c_id);

static const struct of_device_id hwcxext_codec_v1_of_match[] = {
	{ .compatible = "huawei,hwcxext_codec_v1", },
	{},
};
MODULE_DEVICE_TABLE(of, hwcxext_codec_v1_of_match);

int hwcxext_codec_v1_suspend(struct device *dev)
{
	IN_FUNCTION;
	audio_log_write_enable_change(0); /* disable write audio log */
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		return 0;
	}

    if (g_hwcxext_codec->mbhc_data != NULL && g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
        disable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
        hwlog_info("%s: disable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
    }

    int ret = hwcxext_codec_v1_soft_reset(g_hwcxext_codec->regmap_cfg);
    if (ret)
        hwlog_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);

	hwcxext_mbhc_hs_jack_off(g_hwcxext_codec->mbhc_data);
	hwlog_info("%s function comeout\n", __func__);
	return 0;
}


int hwcxext_codec_v1_resume(struct device *dev)
{
	IN_FUNCTION;
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		return 0;
	}

	int ret = hwcxext_codec_v1_soft_reset(g_hwcxext_codec->regmap_cfg);
	if (ret)
		hwlog_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);

	/* init regs */
	ret = hwcxext_i2c_ops_regs_seq(g_hwcxext_codec->regmap_cfg, g_hwcxext_codec->init_regs_seq);
	if (ret)
		hwlog_err("%s: init regs failed\n", __func__);
	hwcxext_codec_v1_enable_jack_detect(g_hwcxext_codec->mbhc_data);
	/* init jack status */
	hwcxext_mbhc_detect_init_state(g_hwcxext_codec->mbhc_data);

	if (g_hwcxext_codec->mbhc_data != NULL && g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
		enable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
		hwlog_info("%s: enable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
	}

	hwlog_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_restore(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
		pr_err("%s: hwcxext_codec is inavild\n", __func__);
		return 0;
	}
	g_hwcxext_codec->regmap_cfg->freeze_flag = 0;

	int ret = hwcxext_codec_v1_soft_reset(g_hwcxext_codec->regmap_cfg);
	if (ret)
		pr_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);

	/* init regs */
	ret = hwcxext_i2c_ops_regs_seq(g_hwcxext_codec->regmap_cfg, g_hwcxext_codec->init_regs_seq);
	if (ret)
		pr_err("%s: init regs failed\n", __func__);
	hwcxext_codec_v1_enable_jack_detect(g_hwcxext_codec->mbhc_data);
	/* init jack status */
	hwcxext_mbhc_detect_init_state(g_hwcxext_codec->mbhc_data);

	if (g_hwcxext_codec->mbhc_data != NULL && g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
		enable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
		pr_info("%s: enable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
	}

	pr_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_freeze(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	audio_log_write_enable_change(0); /* disable write audio log */
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
		pr_err("%s: hwcxext_codec is inavild\n", __func__);
		return 0;
	}

    if (g_hwcxext_codec->mbhc_data != NULL && g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
        disable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
        pr_info("%s: disable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
    }

    int ret = hwcxext_codec_v1_soft_reset(g_hwcxext_codec->regmap_cfg);
	if (ret)
		pr_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);

	hwcxext_mbhc_hs_jack_off(g_hwcxext_codec->mbhc_data);

	g_hwcxext_codec->regmap_cfg->freeze_flag = 1;
	pr_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_thaw(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL) {
		pr_err("%s: hwcxext_codec is inavild\n", __func__);
		return 0;
	}

	int ret = hwcxext_codec_v1_soft_reset(g_hwcxext_codec->regmap_cfg);
	if (ret)
		pr_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);

	/* init regs */
	ret = hwcxext_i2c_ops_regs_seq(g_hwcxext_codec->regmap_cfg, g_hwcxext_codec->init_regs_seq);
	if (ret)
		pr_err("%s: init regs failed\n", __func__);
	hwcxext_codec_v1_enable_jack_detect(g_hwcxext_codec->mbhc_data);
	/* init jack status */
	hwcxext_mbhc_detect_init_state(g_hwcxext_codec->mbhc_data);

	if (g_hwcxext_codec->mbhc_data != NULL && g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
		enable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
		pr_info("%s: enable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
	}

	pr_info("%s function comeout\n", __func__);
	return 0;
}


static struct i2c_driver hwcxext_codec_v1_i2c_driver = {
	.driver = {
		.name = "hwcxext_codec",
		.owner = THIS_MODULE,
		.of_match_table	= of_match_ptr(hwcxext_codec_v1_of_match),
	},
	.probe		= hwcxext_codec_v1_i2c_probe,
	.remove		= hwcxext_codec_v1_i2c_remove,
	.shutdown	= hwcxext_codec_v1_i2c_shutdown,
	.id_table	= hwcxext_codec_v1_i2c_id,
};

static int __init hwcxext_codec_v1_i2c_init(void)
{
	audio_log_init();
	IN_FUNCTION;
	return i2c_add_driver(&hwcxext_codec_v1_i2c_driver);
}

static void __exit hwcxext_codec_v1_i2c_exit(void)
{
    IN_FUNCTION;
    i2c_del_driver(&hwcxext_codec_v1_i2c_driver);
    audio_log_exit();
}

module_init(hwcxext_codec_v1_i2c_init);
module_exit(hwcxext_codec_v1_i2c_exit);

MODULE_DESCRIPTION("hwcxext codec v1 driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_LICENSE("GPL v2");
