/*
 * hwcxext_codec_v1.c
 *
 * hwcxext codec v1 driver
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/reboot.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/tlv.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <dsm/dsm_pub.h>
#include "hwcxext_codec_v1.h"
#include "hwcxext_mbhc.h"
#include "hwcxext_codec_info.h"
#include "hwcxext_log.h"

#ifdef CONFIG_HUAWEI_DSM_AUDIO
#include <dsm_audio/dsm_audio.h>
#endif

#define HWLOG_TAG hwcxext_codec
HWLOG_REGIST();

#define IN_FUNCTION   hwlog_info("%s function comein\n", __func__)
#define OUT_FUNCTION  hwlog_info("%s function comeout\n", __func__)
#define _REAR_IN_NAME(TYPE, MIC, LINEIN) ((((TYPE) & (MIC)) != 0) ? #MIC : #LINEIN)
#define REAR_IN_NAME(TYPE) _REAR_IN_NAME(TYPE, AUDIO_JACK_MIC, AUDIO_JACK_LINEIN)
#define _REAR_IN_NAME_OR_NONE(TYPE, NONE) (((TYPE) == (NONE)) ? #NONE: REAR_IN_NAME(TYPE))
#define REAR_IN_NAME_OR_NONE(TYPE) _REAR_IN_NAME_OR_NONE(TYPE, AUDIO_JACK_NONE)

#define HS_RECOGNIZE_PROCESS_DELAY 20
#define HS_RECOGNIZE_LIMIT_TIME_MS 600
#define CODEC_RESET_DELAY_TIME_MS 5
#define CODEC_RESET_MAX_RETRY_TIMES 5
#define CODEC_HS_CHECK_DELAY_TIME_MS 20
#ifndef UNUSED_PARAMETER
#define UNUSED_PARAMETER(x) (void)(x)
#endif

static const DECLARE_TLV_DB_SCALE(adc_tlv, -7400, 100, 0); // max : 74 : 0 dB
static const DECLARE_TLV_DB_SCALE(dac_tlv, -7400, 100, 0); // min : 0 : -74 dB
static const DECLARE_TLV_DB_SCALE(boost_tlv, 0, 1200, 0);
static struct hwcxext_codec_v1_priv *g_hwcxext_codec = NULL;
static const char *g_codec_info_buffer = NULL;
static bool get_4_pole_type_init_state = false;
static unsigned int portin_en_state = 0;
static unsigned int portout_en_state = 0;
static struct mutex port_en_mutex;
// 保障允许上层调用的虚拟 virtual event事作不会被屏避
static volatile bool g_virtual_event = false;

static void hwcxext_codec_v1_snd_soc_update_bits(struct snd_soc_component *component,
	unsigned int reg, unsigned int mask, unsigned int value)
{
	int ret;
	ret = snd_soc_component_update_bits(component, reg, mask, value);
	if (ret < 0)
		hwlog_err("%s: update_bits failed = %d\n", __func__, ret);
}

static void hwcxext_codec_v1_snd_soc_write(struct snd_soc_component *component,
	unsigned int reg, unsigned int value)
{
	int ret;
	ret = snd_soc_component_write(component, reg, value);
	if (ret < 0)
		hwlog_err("%s: write failed = %d\n", __func__, ret);
}

static void hwcxext_codec_v1_set_mute(struct snd_soc_component *component)
{
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002000);
}

static void hwcxext_codec_power_down(struct snd_soc_component *component)
{
	hwcxext_codec_v1_snd_soc_update_bits(component,
		HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x10);
	hwcxext_codec_v1_snd_soc_update_bits(component,
		HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x03);
}

static void hwcxext_codec_v1_set_porta(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: porta set in enable=%d\n", __func__, enable);
	mutex_lock(&port_en_mutex);
	if (enable) {
		portout_en_state |= PORTA_EN;
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_CONNECTION_SELECT, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0xC0);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 0x48);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT, 0x48);
		goto hwcxext_codec_v1_set_porta_exit;
	}
	portout_en_state &= ~PORTA_EN;
	if (portout_en_state & PORTA_REAR_EN) {
		goto hwcxext_codec_v1_set_porta_exit;
	}
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x03);
	if (portout_en_state == 0) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002000);
	} else if (portout_en_state & PORTG_EN) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x8880000c);
	}

hwcxext_codec_v1_set_porta_exit:
	mutex_unlock(&port_en_mutex);
}

static void hwcxext_codec_v1_set_porta_rear(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: porta set in enable=%d\n", __func__, enable);
	mutex_lock(&port_en_mutex);
	if (enable) {
		portout_en_state |= PORTA_REAR_EN;
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_CONNECTION_SELECT, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0xC0);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 0x48);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT, 0x48);
		goto hwcxext_codec_v1_set_porta_rear_exit;
	}
	portout_en_state &= ~PORTA_REAR_EN;
	if (portout_en_state & PORTA_EN) {
		goto hwcxext_codec_v1_set_porta_rear_exit;
	}
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, 0x03);
	if (portout_en_state == 0) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002000);
	} else if (portout_en_state & PORTG_EN) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x8880000c);
	}

hwcxext_codec_v1_set_porta_rear_exit:
	mutex_unlock(&port_en_mutex);
}

static void hwcxext_codec_v1_set_portg(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portg set in enable=%d\n", __func__, enable);
	mutex_lock(&port_en_mutex);
	if (enable) {
		portout_en_state |= PORTG_EN;
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_CONNECTION_SELECT, 0x01);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_PIN_CTRL, 0x40);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x8880000c);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ANALOG_TEST1, 0x59);
		goto hwcxext_codec_v1_set_portg_exit;
	}
	portout_en_state &= ~PORTG_EN;
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, 0x03);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, 0x03);
	if (portout_en_state == 0) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002000);
	} else {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL3, 0x88002003);
	}

hwcxext_codec_v1_set_portg_exit:
	mutex_unlock(&port_en_mutex);
}

static void hwcxext_codec_v1_set_portb(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portb set in enable=%d\n", __func__, enable);
	mutex_lock(&port_en_mutex);
	if (enable) { // open portB
		portin_en_state |= PORTB_EN;
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 0x21);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_RIGHT, 0x2);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_LEFT, 0x2);
		goto hwcxext_codec_v1_set_portb_exit;
	}
	portin_en_state &= ~PORTB_EN;
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, 0x03);
	if (portin_en_state == 0) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x03);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002000);
	}

hwcxext_codec_v1_set_portb_exit:
	mutex_unlock(&port_en_mutex);
}

static void hwcxext_codec_v1_set_portc(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portc set in enable=%d\n", __func__, enable);
	mutex_lock(&port_en_mutex);
	if (enable) { // open portC
		portin_en_state |= PORTC_EN;
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0x02);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 0x20);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_RIGHT, 0x0);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_LEFT, 0x0);
		goto hwcxext_codec_v1_set_portc_exit;
	}
	portin_en_state &= ~PORTC_EN;
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, 0x03);
	if (portin_en_state == 0) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x03);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002000);
	}

hwcxext_codec_v1_set_portc_exit:
	mutex_unlock(&port_en_mutex);
}

static void hwcxext_codec_v1_set_portd(struct snd_soc_component *component, bool enable)
{
	hwlog_info("%s: portD set in enable=%d\n", __func__, enable);
	mutex_lock(&port_en_mutex);
	if (enable) { // open portD
		portin_en_state |= PORTD_EN;
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT, 0x01);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x24);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, 0x00);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002003);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_RIGHT, 0x2);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_LEFT, 0x2);
		hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ANALOG_TEST11, 0x02, 0x02);
		goto hwcxext_codec_v1_set_portd_exit;
	}
	portin_en_state &= ~PORTD_EN;
	hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_ANALOG_TEST11, 0x02, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x00);
	hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, 0x03);
	if (portin_en_state == 0) {
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, 0x03);
		hwcxext_codec_v1_snd_soc_write(component, HWCXEXT_CODEC_V1_I2SPCM_CONTROL2, 0x88002000);
	}

hwcxext_codec_v1_set_portd_exit:
	mutex_unlock(&port_en_mutex);
}

static void hwcxext_codec_v1_set_switch(struct snd_soc_component *component,
	enum switch_control ch)
{
	hwlog_info("%s: set switch = %d\n", __func__, ch);
	unsigned int mask = 1 << ch;
	hwcxext_codec_v1_snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DIGITAL_TEST22, mask, mask);
	hwlog_info("%s: update ok.\n", __func__);
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

static int get_4_pole_headset_type(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	if (kcontrol == NULL || ucontrol == NULL) {
		hwlog_info("%s: input pointer is null\n", __func__);
		return -EINVAL;
	}
	hwlog_info("%s: user input is %d\n", __func__, ucontrol->value.integer.value[0]);
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	unsigned int hs_type = snd_soc_component_read(component,
		HWCXEXT_CODEC_V1_DIGITAL_TEST11);
	hwlog_info("%s: hs_type 0x%x\n", __func__, hs_type);
	if (hs_type & 0x800) {
		ucontrol->value.integer.value[0] = 1;
		hwlog_info("%s: headphone is 4 pole\n", __func__);
	} else if (hs_type & 0x400) {
		ucontrol->value.integer.value[0] = 0;
		hwlog_info("%s: headphone is invert 4 pole\n", __func__);
	}
	get_4_pole_type_init_state = true;
	return 0;
}

static int set_4_pole_headset_type(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	if (kcontrol == NULL || ucontrol == NULL) {
		hwlog_info("%s: input pointer is null\n", __func__);
		return -EINVAL;
	}
	if (get_4_pole_type_init_state == false) {
		hwlog_info("%s: get_4_pole is not call, no need set invert headset type\n", __func__);
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
	}
	hwlog_info("%s: hs_type=%d, no 4 pole headset insert\n", __func__, hs_type);
	return 0;
}

static const struct snd_kcontrol_new hwcxext_codec_v1_snd_controls[] = {
	SOC_DOUBLE_R_TLV("PortD Boost Volume",
		HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_PORTD_AMP_GAIN_RIGHT, 0, 3, 0, boost_tlv),
	SOC_DOUBLE_R_TLV("PortC Boost Volume",
		HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_PORTC_AMP_GAIN_RIGHT, 0, 3, 0, boost_tlv),
	SOC_DOUBLE_R_TLV("PortB Boost Volume",
		HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_PORTB_AMP_GAIN_RIGHT, 0, 3, 0, boost_tlv),
	SOC_DOUBLE_R_TLV("PortB ADC1 Volume",
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_0,
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_0, 0, 0x4a, 0, adc_tlv),
	SOC_DOUBLE_R_TLV("PortD ADC1 Volume",
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_1,
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_1, 0, 0x4a, 0, adc_tlv),
	SOC_DOUBLE_R_TLV("PortC ADC1 Volume",
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_LEFT_2,
		HWCXEXT_CODEC_V1_ADC1_AMP_GAIN_RIGHT_2, 0, 0x4a, 0, adc_tlv),
	SOC_DOUBLE_R_TLV("DAC1 Volume",
		HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 0, 0x48, 0, dac_tlv),
	SOC_DOUBLE_R("DAC1 Switch", HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC1_AMP_GAIN_RIGHT, 7,  1, 0),
	SOC_DOUBLE_R_TLV("DAC2 Volume",
		HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0, 0x4a, 0, dac_tlv),
	SOC_DOUBLE_R("DAC2 Switch", HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT,
		HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 7,  1, 0),
	SOC_SINGLE("PortA HP Amp Switch",
		HWCXEXT_CODEC_V1_PORTA_PIN_CTRL, 7, 1, 0),
	SOC_SINGLE("Headset MIC Loop Switch",
		HWCXEXT_CODEC_V1_CODEC_TEST11, 8, 3, 0),
	SOC_SINGLE_EXT("INVERT_HEADSET_SWITCH", HWCXEXT_CODEC_V1_DIGITAL_TEST22,
		INVERT_SWITCH, 1, 0, get_4_pole_headset_type, set_4_pole_headset_type),
};

/* VIRTUAL pc kcontrol define */
static const struct snd_kcontrol_new dapm_speaker_playback_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, SPEAKER_PLAYBACK, 1, 0);
static const struct snd_kcontrol_new dapm_headset_playback_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, HEADSET_PLAYBACK, 1, 0);
static const struct snd_kcontrol_new dapm_headset_mic_capture_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, HEADSET_MIC, 1, 0);
static const struct snd_kcontrol_new dapm_rear_linein_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, REAR_LINEIN, 1, 0);
static const struct snd_kcontrol_new dapm_rear_head_mic_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, REAR_MIC, 1, 0);
static const struct snd_kcontrol_new dapm_rear_headphone_switch_controls =
	SOC_DAPM_SINGLE("Switch", HWCXEXT_CODEC_V1_DIGITAL_TEST22, REAR_HEADPHONE, 1, 0);
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
	SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_PORTA_CONNECTION_SELECT,
		0, 2, dac_enum_text);
static const struct snd_kcontrol_new porta_mux =
	SOC_DAPM_ENUM("PortA Mux", porta_dac_enum);
static const struct soc_enum portg_dac_enum =
	SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_PORTG_CONNECTION_SELECT,
		0, 2, dac_enum_text);
static const struct snd_kcontrol_new portg_mux =
	SOC_DAPM_ENUM("PortG Mux", portg_dac_enum);
static const char * const adc1in_sel_text[] = {
	"PortB Switch", "PortD Switch", "PortC Switch",
	"Widget15 Switch",
};
static const struct soc_enum adc1in_sel_enum =
	SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT,
		0, 4, adc1in_sel_text);
static const struct snd_kcontrol_new adc1_mux =
	SOC_DAPM_ENUM("ADC1 Mux", adc1in_sel_enum);
static const char * const adc2in_sel_text[] = {
	"PortC Switch", "Widget15 Switch",
};
static const struct soc_enum adc2in_sel_enum =
	SOC_ENUM_SINGLE(HWCXEXT_CODEC_V1_ADC2_CONNECTION_SELECT,
	0, 2, adc2in_sel_text);
static const struct snd_kcontrol_new adc2_mux =
	SOC_DAPM_ENUM("ADC2 Mux", adc2in_sel_enum);
static const struct snd_kcontrol_new wid15_mix[] = {
	SOC_DAPM_SINGLE("DAC1L Switch",
		HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_LEFT_0, 7, 1, 1),
	SOC_DAPM_SINGLE("DAC1R Switch",
		HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_RIGHT_0, 7, 1, 1),
	SOC_DAPM_SINGLE("DAC2L Switch",
		HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_LEFT_1, 7, 1, 1),
	SOC_DAPM_SINGLE("DAC2R Switch",
		HWCXEXT_CODEC_V1_MIXER_AMP_GAIN_RIGHT_1, 7, 1, 1),
};

static int hwcxext_codec_v1_afg_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_snd_soc_update_bits(component,
			HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x00);
		hwcxext_codec_v1_snd_soc_update_bits(component,
			HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component,
			HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST0_LSB, 0x10, 0x10);
		hwcxext_codec_v1_snd_soc_update_bits(component,
			HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: power mode event err: %d\n", __func__, event);
		break;
	}
	return 0;
}

static int hwcxext_codec_v1_micbias_event(struct snd_soc_dapm_widget *w,
	unsigned int reg, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		/* Port Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, reg, 0x04, 0x04);
		break;
	case SND_SOC_DAPM_POST_PMD:
		/* Port Mic Bias */
		hwcxext_codec_v1_snd_soc_update_bits(component, reg, 0x04, 0x00);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	return 0;
}

static int hwcxext_codec_v1_power_event(struct snd_soc_dapm_widget *w,
	unsigned int reg, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	hwlog_info("%s: event:0x%x\n", __func__, event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		// 厂商建议全位操作
		hwcxext_codec_v1_snd_soc_update_bits(component, reg, 0xff, 0x00);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_snd_soc_update_bits(component, reg, 0xff, 0x03);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	return 0;
}

static int hwcxext_codec_v1_portb_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_PORTB_POWER_STATE, event);
}

static int hwcxext_codec_v1_portc_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_PORTC_POWER_STATE, event);
}

static int hwcxext_codec_v1_portd_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_PORTD_POWER_STATE, event);
}

static int hwcxext_codec_v1_widget15_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_MIXER_POWER_STATE, event);
}

static int hwcxext_codec_v1_adc1_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_ADC1_POWER_STATE, event);
}

static int hwcxext_codec_v1_adc2_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_ADC2_POWER_STATE, event);
}

static int hwcxext_codec_v1_portb_micbias_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_micbias_event(w, HWCXEXT_CODEC_V1_PORTB_PIN_CTRL, event);
}

static int hwcxext_codec_v1_portc_micbias_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_micbias_event(w, HWCXEXT_CODEC_V1_PORTC_PIN_CTRL, event);
}

static int hwcxext_codec_v1_portd_micbias_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_micbias_event(w, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, event);
}

static int hwcxext_codec_v1_porta_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_PORTA_POWER_STATE, event);
}

static int hwcxext_codec_v1_portg_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_PORTG_POWER_STATE, event);
}

static int hwcxext_codec_v1_dac1_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_DAC1_POWER_STATE, event);
}

static int hwcxext_codec_v1_dac2_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	hwlog_info("%s: event:0x%x\n", __func__, event);
	return hwcxext_codec_v1_power_event(w, HWCXEXT_CODEC_V1_DAC2_POWER_STATE, event);
}

static int hwcxext_codec_v1_headset_mic_capture_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	hwlog_info("%s: event:0x%x\n", __func__, event);
	g_virtual_event = true;
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portd(component, true);
		hwlog_info("%s: SND_SOC_DAPM_PRE_PMU event:0x%x\n", __func__, event);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portd(component, false);
		hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	g_virtual_event = false;
	return 0;
}

static int hwcxext_codec_v1_headset_playback_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	hwlog_info("%s: event:0x%x\n", __func__, event);
	g_virtual_event = true;
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_porta(component, true);
		hwlog_info("%s: SND_SOC_DAPM_PRE_PMU event:0x%x\n", __func__, event);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_porta(component, false);
		hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	g_virtual_event = false;
	return 0;
}

static struct hwcxext_mbhc_priv * hwcxext_codec_v1_get_mbhc_data(
	struct snd_soc_component *component)
{
	struct hwcxext_codec_v1_priv *hwcxext_codec = NULL;
	hwcxext_codec = snd_soc_component_get_drvdata(component);
	if (hwcxext_codec == NULL) {
		hwlog_err("%s: hwcxext_codec is inavild\n", __func__);
		return NULL;
	}
	return hwcxext_codec->mbhc_data; 
}

static int hwcxext_codec_v1_speaker_playback_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct hwcxext_mbhc_priv *mbhc_data = hwcxext_codec_v1_get_mbhc_data(component);
	if ((mbhc_data == NULL) || (!mbhc_data->item_type)) {
		hwlog_err("%s: is desktop pc, do not set speaker playback event.\n", __func__);
		return 0;
	}
	hwlog_info("%s: event:0x%x\n", __func__, event);
	g_virtual_event = true;
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portg(component, true);
		hwlog_info("%s: SND_SOC_DAPM_PRE_PMU event:0x%x\n", __func__, event);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portg(component, false);
		hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	g_virtual_event = false;
	return 0;
}

static int hwcxext_codec_v1_linein_capture_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct hwcxext_mbhc_priv *mbhc_data = hwcxext_codec_v1_get_mbhc_data(component);
	if ((mbhc_data == NULL) || (mbhc_data->item_type)) {
		hwlog_err("%s: is notebook pc, do not set linein capture event.\n", __func__);
		return 0;
	}
	hwlog_info("%s: event:0x%x\n", __func__, event);
	g_virtual_event = true;
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portc(component, true);
		hwlog_info("%s: SND_SOC_DAPM_PRE_PMU event:0x%x\n", __func__, event);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portc(component, false);
		hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	g_virtual_event = false;
	return 0;
}

static int hwcxext_codec_v1_rear_mic_capture_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct hwcxext_mbhc_priv *mbhc_data = hwcxext_codec_v1_get_mbhc_data(component);
	if ((mbhc_data == NULL) || (mbhc_data->item_type)) {
		hwlog_err("%s: is notebook pc, do not set rear mic capture event.\n", __func__);
		return 0;
	}
	g_virtual_event = true;
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_portb(component, true);
		hwlog_info("%s: SND_SOC_DAPM_PRE_PMU event:0x%x\n", __func__, event);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_portb(component, false);
		hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	g_virtual_event = false;
	return 0;
}

static int hwcxext_codec_v1_rear_headphone_playback_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
	struct hwcxext_mbhc_priv *mbhc_data = hwcxext_codec_v1_get_mbhc_data(component);
	if ((mbhc_data == NULL) || (mbhc_data->item_type)) {
		hwlog_err("%s: is notebook pc, do not set rear headphone playback event.\n", __func__);
		return 0;
	}
	hwlog_info("%s: event:0x%x\n", __func__, event);
	g_virtual_event = true;
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		hwcxext_codec_v1_set_porta_rear(component, true);
		hwlog_info("%s: SND_SOC_DAPM_PRE_PMU event:0x%x\n", __func__, event);
		break;
	case SND_SOC_DAPM_POST_PMD:
		hwcxext_codec_v1_set_porta_rear(component, false);
		hwlog_info("%s: SND_SOC_DAPM_POST_PMD event:0x%x\n", __func__, event);
		break;
	default:
		hwlog_err("%s: event err: %d\n", __func__, event);
		break;
	}
	g_virtual_event = false;
	return 0;
}

static const unsigned int dapm_widgets_switch_regs[] = {
	HWCXEXT_CODEC_V1_I2SPCM_CONTROL3,
	HWCXEXT_CODEC_V1_I2SPCM_CONTROL2,
	HWCXEXT_CODEC_V1_PORTC_PIN_CTRL,
	HWCXEXT_CODEC_V1_PORTD_PIN_CTRL,
	HWCXEXT_CODEC_V1_PORTB_PIN_CTRL,
	HWCXEXT_CODEC_V1_PORTG_PIN_CTRL,
	HWCXEXT_CODEC_V1_PORTA_PIN_CTRL,
	HWCXEXT_CODEC_V1_ADC1_CONNECTION_SELECT,
};

bool hwcxext_codec_v1_is_noin_dapm_widgets(unsigned int reg)
{
	int i;
	// 如果是alsactl进程，并且还在dapm_widgets_switch_regs中，则不响应
	if ((g_virtual_event == true) || ((current != NULL) && (strcmp(current->comm, "alsactl") != 0))) {
		return true;
	}
	for (i = 0; i < sizeof(dapm_widgets_switch_regs) / sizeof(unsigned int); i++) {
		if (reg == dapm_widgets_switch_regs[i]) {
			return false;
		}
	}
	return true;
}

/* dapm widgets */
static const struct snd_soc_dapm_widget hwcxext_codec_v1_dapm_widgets[] = {
	/* Playback */
	SND_SOC_DAPM_AIF_IN("In AIF", "Playback", 0, SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_INPUT("DEC REF"),
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
	SND_SOC_DAPM_AIF_OUT("Out AIF", "Capture", 0, SND_SOC_NOPM, 0, 0),
	SND_SOC_DAPM_OUTPUT("AEC REF"),
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
	SND_SOC_DAPM_MIC("PortB Mic Bias", hwcxext_codec_v1_portb_micbias_event),
	SND_SOC_DAPM_MIC("PortC Mic Bias", hwcxext_codec_v1_portc_micbias_event),
	SND_SOC_DAPM_MIC("PortD Mic Bias", hwcxext_codec_v1_portd_micbias_event),
	SND_SOC_DAPM_INPUT("PORTB"),
	SND_SOC_DAPM_INPUT("PORTC"),
	SND_SOC_DAPM_INPUT("PORTD"),
	SND_SOC_DAPM_SWITCH_E("Headset Playback",
		SND_SOC_NOPM, 0, 0, &dapm_headset_playback_switch_controls,
		hwcxext_codec_v1_headset_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("Headset Mic Capture",
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
	SND_SOC_DAPM_SWITCH_E("Speaker Playback",
		SND_SOC_NOPM, 0, 0, &dapm_speaker_playback_switch_controls,
		hwcxext_codec_v1_speaker_playback_event,
		(SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),

	SND_SOC_DAPM_INPUT("Speaker_INPUT"),
	SND_SOC_DAPM_OUTPUT("Speaker_OUTPUT"),
	SND_SOC_DAPM_INPUT("PLAYBACK_INPUT"),
	SND_SOC_DAPM_OUTPUT("PLAYBACK_OUTPUT"),
	SND_SOC_DAPM_INPUT("CAPTURE_INPUT"),
	SND_SOC_DAPM_OUTPUT("CAPTURE_OUTPUT"),
	SND_SOC_DAPM_HP("Headphone Jack", NULL),
	SND_SOC_DAPM_HP("Rear HeadPhone Jack", NULL),
	SND_SOC_DAPM_MIC("Headset Mic Jack", NULL),
	SND_SOC_DAPM_MIC("Rear Mic Jack", NULL),
	SND_SOC_DAPM_LINE("LineIn Jack", NULL),
	SND_SOC_DAPM_SPK("Speaker Jack", NULL),
};

static const struct snd_soc_dapm_route hwcxext_codec_v1_dapm_routes[] = {
	/* Playback */
	{"In AIF", NULL, "AFG Power"},
	{"In AIF", NULL, "DEC REF"},
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
	{"Widget15 Mixer", "DAC1R Switch", "DAC1"},
	{"Widget15 Mixer", "DAC2L Switch", "DAC2"},
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
	{"AEC REF", NULL, "Out AIF"},
	{"PortB In En", NULL, "PortB Power"},
	{"PortC In En", NULL, "PortC Power"},
	{"PortD In En", NULL, "PortD Power"},

	{"Headset Playback", "Switch", "PLAYBACK_INPUT"},
	{"PLAYBACK_OUTPUT", NULL, "Headset Playback"},
	{"Rear Headphone Playback", "Switch", "PLAYBACK_INPUT"},
	{"PLAYBACK_OUTPUT", NULL, "Rear Headphone Playback"},
	{"Headset Mic Capture", "Switch", "CAPTURE_INPUT"},
	{"CAPTURE_OUTPUT", NULL, "Headset Mic Capture"},
	{"LineIn Capture", "Switch", "CAPTURE_INPUT"},
	{"CAPTURE_OUTPUT", NULL, "LineIn Capture"},
	{"Rear Mic Capture", "Switch", "CAPTURE_INPUT"},
	{"CAPTURE_OUTPUT", NULL, "Rear Mic Capture"},
	{"Speaker Playback", "Switch", "Speaker_INPUT"},
	{"Speaker_OUTPUT", NULL, "Speaker Playback"},
};

static unsigned int hwcxext_codec_v1_get_headset_state(
	struct hwcxext_mbhc_priv *mbhc, unsigned int *pa, int *tims)
{
	int tim = 0;
	if ((mbhc == NULL) || (pa == NULL) || (tims == NULL)) {
		hwlog_err("%s: mbhc or pa tims is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}
	static unsigned int flag_afg_old = HWCXEXT_CODEC_V1_BIT_02;
	unsigned int flag_afg = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_AFG_GPIO_DATA);
	hwlog_info("%s:afg = %#04x\n", __func__, flag_afg);
	unsigned int flag_pd = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_PORTD_PIN_SENSE);
	unsigned int flag_pa = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
	hwlog_info("%s:pa = %#04x, pd = %#04x\n", __func__, flag_pa, flag_pd);
	if ((flag_afg & HWCXEXT_CODEC_V1_BIT_02) == 0) {
		flag_afg_old = flag_afg;
		if ((flag_pa & HWCXEXT_CODEC_V1_BIT_31) || (flag_pd & HWCXEXT_CODEC_V1_BIT_31)) {
			return AUDIO_JACK_HEADSET;
		}
		return AUDIO_JACK_WAIT;
	}
	if (flag_pd & HWCXEXT_CODEC_V1_BIT_31) {
		do { // 可能已插入后置耳机，flag_afg反应需要150ms左右
			flag_afg = snd_soc_component_read(mbhc->component,
				HWCXEXT_CODEC_V1_AFG_GPIO_DATA);
			hwlog_info("%s:afg(tim = %d) = %#04x\n", __func__, tim, flag_afg);
			if ((flag_afg & HWCXEXT_CODEC_V1_BIT_02) == 0) {
				flag_afg_old = flag_afg;
				return AUDIO_JACK_HEADSET;
			}
			if (flag_pa != snd_soc_component_read(mbhc->component,
				HWCXEXT_CODEC_V1_PORTA_PIN_SENSE)) {
				hwlog_info("%s:flag_pa is changed %#04x\n", __func__, flag_pa);
				break; // 若pa发生变化，表示可以停止检测
			}
			if (tim < *tims)
				msleep(CODEC_HS_CHECK_DELAY_TIME_MS);
			tim += CODEC_HS_CHECK_DELAY_TIME_MS;
		} while (tim <= *tims);
	} else { // 若是没有执行上述延时，则表明没有浪费检测时间。
		*tims = 0;
	}
	*pa = flag_pa;
	if ((flag_afg_old & HWCXEXT_CODEC_V1_BIT_02) == 0) { // 需要在pd非置位下再判定
		flag_afg_old = flag_afg;
		hwlog_info("%s:afg_old = %#04x\n", __func__, flag_afg_old);
	}
	return AUDIO_JACK_NONE;
}

static unsigned int hwcxext_codec_v1_get_rearin_state(struct hwcxext_mbhc_priv *mbhc)
{
	unsigned int flag = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_PORTB_PIN_SENSE);
	hwlog_info("%s:portb = %#04x\n", __func__, flag);
	// 若portb生效，portc自动失效，因为有仅只能有一个port输入通路
	if (flag & HWCXEXT_CODEC_V1_BIT_31) {
		return AUDIO_JACK_MIC;
	}
	flag = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_PORTC_PIN_SENSE);
	hwlog_info("%s:portc = %#04x\n", __func__, flag);
	if (flag & HWCXEXT_CODEC_V1_BIT_31) {
		return AUDIO_JACK_LINEIN;
	}
	return AUDIO_JACK_NONE;
}

static unsigned int hwcxext_codec_v1_get_rearout_state(
	struct hwcxext_mbhc_priv *mbhc, unsigned int pa, int tims)
{
	int tim = 0;
	unsigned int flag = 0;
	unsigned int jack_pa_type = AUDIO_JACK_NONE;
	if (pa & HWCXEXT_CODEC_V1_BIT_31) {
		jack_pa_type = AUDIO_JACK_LINEOUT;
	}
	flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_CODEC_TEST38);
	if (flag & HWCXEXT_CODEC_V1_BIT_06) {
		// porta 快速响应
		flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
		hwlog_info("%s:porta(quick) = : %#04x\n", __func__, flag);
		goto hwcxext_codec_v1_rearout_state_exit;
	}
	do { // porta 慢速响应
		flag = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
		hwlog_info("%s:porta(tim = %d) = : %#04x\n", __func__, tim, flag);
		if (flag & HWCXEXT_CODEC_V1_BIT_31) {
			if (jack_pa_type == AUDIO_JACK_NONE) {
				// 前面是pa不在位，当前pa在位，说明pa数据有变动，可以提前退出循环
				break;
			}
			jack_pa_type = AUDIO_JACK_LINEOUT;
		} else {
			if (jack_pa_type == AUDIO_JACK_LINEOUT) {
				// 前面是pa在位，当前pa不在位，说明pa数据有变动，可以提前退出循环
				break;
			}
			jack_pa_type = AUDIO_JACK_NONE;
		}
		if (tim < tims)
			msleep(CODEC_HS_CHECK_DELAY_TIME_MS);
		tim += CODEC_HS_CHECK_DELAY_TIME_MS;
	} while (tim <= tims);

hwcxext_codec_v1_rearout_state_exit:
	if (flag & HWCXEXT_CODEC_V1_BIT_31) {
		return AUDIO_JACK_LINEOUT;
	}
	return AUDIO_JACK_NONE;
}

static unsigned int hwcxext_codec_v1_mbhc_check_headset_in(
	struct hwcxext_mbhc_priv *mbhc, int tims)
{
	int head_tim = 250;
	unsigned int pa = 0;
	unsigned int type = AUDIO_JACK_NONE;
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}
	type = hwcxext_codec_v1_get_headset_state(mbhc, &pa, &head_tim);
	if (type == AUDIO_JACK_HEADSET) {
		if (!mbhc->item_type) {
			// 允许三段式耳机+后置in型耳机合并处理
			type |= hwcxext_codec_v1_get_rearin_state(mbhc);
		}
		if (type == AUDIO_JACK_HEADSET) {
			hwlog_info("%s:check plug in = AUDIO_JACK_HEADSET\n", __func__);
			return AUDIO_JACK_HEADSET;
		}
		hwlog_info("%s:check plug in = AUDIO_JACK_HEADSET + %s\n", __func__, REAR_IN_NAME(type));
		return type;
	} else if (type == AUDIO_JACK_WAIT) {
		hwlog_info("%s:check plug in = AUDIO_JACK_WAIT\n", __func__);
		return type;
	}
	if (mbhc->item_type) {
		hwlog_info("%s:check plug in = AUDIO_JACK_NONE with book pc\n", __func__);
		return AUDIO_JACK_NONE;
	}
	tims = (tims >= head_tim) ? (tims - head_tim) : tims;
	type = hwcxext_codec_v1_get_rearin_state(mbhc);
	if (hwcxext_codec_v1_get_rearout_state(mbhc, pa, tims) == AUDIO_JACK_LINEOUT) {
		if (type == AUDIO_JACK_NONE) {
			hwlog_info("%s:check plug in = AUDIO_JACK_LINEOUT\n", __func__);
			return AUDIO_JACK_LINEOUT;
		}
		hwlog_info("%s:check plug in = AUDIO_JACK_LINEOUT + %s\n", __func__, REAR_IN_NAME(type));
		return AUDIO_JACK_LINEOUT | type;
	}
	hwlog_info("%s:check plug in = %s\n", __func__, REAR_IN_NAME_OR_NONE(type));
	return type;
}

static void hwcxext_codec_v1_disable_micbias_for_hs_detect(
	struct hwcxext_mbhc_priv *mbhc)
{
	IN_FUNCTION;
	/* disable manual mode, disable micbias in mic */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST39, 0x83f, 0x000);
	hwcxext_codec_v1_snd_soc_write(mbhc->component,
		HWCXEXT_CODEC_V1_ANALOG_TEST2, 0x00);
}

static void hwcxext_codec_v1_clear_irq(struct hwcxext_mbhc_priv *mbhc)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return;
	}
	/* Use GPOI0 as interrupt pin */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_UM_INTERRUPT_CRTL, 0x10, 0x10);
}

static void hwcxext_codec_v1_enable_jack_detect(struct hwcxext_mbhc_priv *mbhc)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return;
	}
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

static unsigned int hwcxext_codec_v1_repeat_get_correct_hs_type(
	struct hwcxext_mbhc_priv *mbhc)
{
	bool flag_timout = false;
	unsigned int count = 0;
	unsigned int status;
	unsigned long tims = jiffies + msecs_to_jiffies(HS_RECOGNIZE_LIMIT_TIME_MS);
	msleep(HS_RECOGNIZE_PROCESS_DELAY);
	do {
		status = snd_soc_component_read(mbhc->component,
			HWCXEXT_CODEC_V1_DIGITAL_TEST10);
		hwlog_info("%s: status=0x%x count:%d\n", __func__, status, count++);
		if (time_after(jiffies, tims)) {
			flag_timout = true;
			break;
		}
		msleep(HS_RECOGNIZE_PROCESS_DELAY);
	} while ((status & HWCXEXT_CODEC_V1_BIT_07) == 0);

	if (flag_timout) {
		hwlog_warn("%s: it exceed the limit time\n", __func__);
		return AUDIO_JACK_NONE;
	}
	unsigned int hs_type = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_DIGITAL_TEST11);
	hwlog_info("%s: hs_type 0x%x\n", __func__, hs_type);
	if (hs_type & 0x800) {
		hwlog_info("%s: headphone is 4 pole\n", __func__);
		hwcxext_codec_v1_set_invert_headset(mbhc->component, true);
		return AUDIO_JACK_HEADSET;
	} else if (hs_type & 0x400) {
		hwlog_info("%s: headphone is invert 4 pole\n", __func__);
		hwcxext_codec_v1_set_invert_headset(mbhc->component, false);
		return AUDIO_JACK_HEADSET;
	}
	hwlog_info("%s: headphone is 3 pole\n", __func__);
	return AUDIO_JACK_HEADPHONE;
}

static void hwcxext_codec_v1_set_hs_detect_restart(
	struct hwcxext_mbhc_priv *mbhc)
{
	if (mbhc == NULL) {
		hwlog_err("%s: params is inavild\n", __func__);
		return;
	}
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST39, 0x83f, 0x000);
	hwcxext_codec_v1_snd_soc_write(mbhc->component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x20);
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST38, 0x20, 0x00);
	int restart = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST38);
	int portd_ctl = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_PORTD_PIN_CTRL);
	int micbias = snd_soc_component_read(mbhc->component, HWCXEXT_CODEC_V1_CODEC_TEST39);
	hwlog_info("%s: restart status = %d, portd_ctl = %#04x, micbias = %#04x\n",
		__func__, restart, portd_ctl, micbias);
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST38, 0x20, 0x20);
}

static unsigned int hwcxext_codec_v1_hs_type_recognize(
	struct hwcxext_mbhc_priv *mbhc)
{
	unsigned int type;

	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return AUDIO_JACK_NONE;
	}

	type = hwcxext_codec_v1_repeat_get_correct_hs_type(mbhc);
	if (type == AUDIO_JACK_NONE) {
		hwlog_info("%s: hs type recognize timeout, need try again\n", __func__);
		hwcxext_codec_v1_set_hs_detect_restart(mbhc);
		type = hwcxext_codec_v1_repeat_get_correct_hs_type(mbhc);
	}
	return type;
}

static unsigned int hwcxext_codec_v1_btn_type_recognize(
	struct hwcxext_mbhc_priv *mbhc)
{
	unsigned int mb_status = 0;
	if (IS_ERR_OR_NULL(mbhc)) {
		hwlog_err("%s: mbhc is NULL\n", __func__);
		return 0;
	}
	mb_status = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST37);
	/* clear mb status */
	hwcxext_codec_v1_snd_soc_update_bits(mbhc->component,
		HWCXEXT_CODEC_V1_CODEC_TEST37, 0x7ff, 0x7ff);
	return (mb_status & 0x7ff);
}

static void hwcxext_codec_v1_enable_micbias_for_hs_detect(
	struct hwcxext_mbhc_priv *mbhc)
{
	IN_FUNCTION;
	hwcxext_codec_v1_snd_soc_write(mbhc->component,
		HWCXEXT_CODEC_V1_PORTD_PIN_CTRL, 0x24);
	int portd_ctl = snd_soc_component_read(mbhc->component,
		HWCXEXT_CODEC_V1_PORTD_PIN_CTRL);
	hwlog_info("%s: enable detect, portd_ctl = %#04x\n", __func__, portd_ctl);
	hwcxext_codec_v1_snd_soc_write(mbhc->component,
		HWCXEXT_CODEC_V1_ANALOG_TEST2, 0x10);

	(void)hwcxext_codec_v1_btn_type_recognize(mbhc);
}

static struct hwcxext_mbhc_cb mbhc_cb = {
	.mbhc_check_headset_in = hwcxext_codec_v1_mbhc_check_headset_in,
	.enable_micbias = hwcxext_codec_v1_enable_micbias_for_hs_detect,
	.disable_micbias = hwcxext_codec_v1_disable_micbias_for_hs_detect,
	.get_hs_type_recognize = hwcxext_codec_v1_hs_type_recognize,
	.set_hs_detect_restart = hwcxext_codec_v1_set_hs_detect_restart,
	.get_btn_type_recognize = hwcxext_codec_v1_btn_type_recognize,
	.clear_irq = hwcxext_codec_v1_clear_irq,
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

static int hwcxext_codec_v1_soft_reset(struct hwcxext_codec_regmap_cfg *cfg)
{
	int ret, i;
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
		pr_err("%s: regmap write soft_reset fail, err = %d\n", __func__, ret);
	mdelay(CODEC_RESET_DELAY_TIME_MS);
	for (i = 0; i < CODEC_RESET_MAX_RETRY_TIMES; i++) {
		ret = regmap_write(cfg->regmap, HWCXEXT_CODEC_V1_DIGITAL_BIOS_TEST3_MSB, 0x03);
		if (ret == 0) {
			pr_info("%s regmap write TEST3_MSB success\n", __func__);
			break;
		}
		pr_err("%s regmap write TEST3_MSB fail, cnt=%d, err=%d\n", __func__, i, ret);
		mdelay(1);
	}
	pr_info("%s function comeout\n", __func__);
	return ret;
}

static void hwcxext_codec_v1_copy_codec_info(struct snd_info_entry *entry,
	struct snd_info_buffer *buffer)
{
	UNUSED_PARAMETER(entry);
	snd_iprintf(buffer, g_codec_info_buffer);
}

static void hwcxext_codec_v1_pc_info_select(struct snd_soc_component *component)
{	
	int ret;
	struct snd_info_entry *entry = NULL;

	if (component == NULL || component->card == NULL) {
		hwlog_err("%s: component is invalid\n", __func__);
		return;
	}
	ret = snd_card_proc_new(component->card->snd_card, "codec#1", &entry);
	if (ret < 0) {
		hwlog_err("%s: select info failed\n", __func__);
		return;
	}
	ret = of_property_read_string(component->dev->of_node,
		"hwcxext_codec_v1_info", &g_codec_info_buffer);
	if (ret != 0) {
		hwlog_err("%s: read dts hwcxext codec info failed\n", __func__);
		return;
	}
	snd_info_set_text_ops(entry, NULL, hwcxext_codec_v1_copy_codec_info);
}

static int hwcxext_codec_v1_probe(struct snd_soc_component *component)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(component)) {
		hwlog_err("%s: component is NULL\n", __func__);
		return -EINVAL;
	}
	struct hwcxext_codec_v1_priv *hwcxext_codec =
		snd_soc_component_get_drvdata(component);
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
	ret = hwcxext_i2c_ops_regs_seq(hwcxext_codec->regmap_cfg,
			hwcxext_codec->init_regs_seq);
	if (ret) {
		hwlog_err("%s: init regs failed\n", __func__);
		return -ENXIO;
	}
	hwlog_info("%s: hwcxext_mbhc_init is ininin\n", __func__);
	ret = hwcxext_mbhc_init(&hwcxext_codec->i2c->dev, component,
		&hwcxext_codec->mbhc_data, &mbhc_cb);
	if (ret) {
		hwlog_err("%s: hwcxext mbhc init failed\n", __func__);
		return ret;
	}
	hwlog_info("%s: hwcxext_mbhc_init is outoutout\n", __func__);
	hwcxext_codec_v1_enable_jack_detect(hwcxext_codec->mbhc_data);
	hwcxext_codec_v1_set_mute(component);
	hwcxext_mbhc_detect_init_state(hwcxext_codec->mbhc_data);
	hwlog_info("%s: hwcxext_codec_v1_info in\n", __func__);
	if (of_property_read_bool(component->dev->of_node, "hwcxext_codec_v1_info")) {
		hwlog_info("%s: hwcxext_codec_v1_info has dts config\n", __func__);
		hwcxext_codec_v1_pc_info_select(component);
	}

	hwlog_info("%s: hwcxext_codec_v1_info out\n", __func__);
	OUT_FUNCTION;
	return 0;
}

static void hwcxext_codec_v1_remove(struct snd_soc_component *component)
{
	struct hwcxext_codec_v1_priv *hwcxext_codec =
		snd_soc_component_get_drvdata(component);
	IN_FUNCTION;
	if (hwcxext_codec == NULL) {
		hwlog_info("%s: hwcxext_codec is invalid\n", __func__);
		return;
	}
	hwlog_info("%s function v1_remove cx11880 remove\n", __func__);
	clk_disable_unprepare(hwcxext_codec->mclk);
	hwcxext_mbhc_exit(&hwcxext_codec->i2c->dev, hwcxext_codec->mbhc_data);
}

static int hwcxext_codec_v1_set_bias_level(struct snd_soc_component *component,
	enum snd_soc_bias_level level)
{
	hwlog_info("%s: level=%d\n", __func__, level);
	return 0;
}

static int hwcxext_codec_v1_set_dai_sysclk(struct snd_soc_dai *codec_dai,
	int clk_id, unsigned int freq, int dir)
{
	hwlog_info("%s: clk_id=%d, freq=%d, dir=%d\n", __func__, clk_id, freq, dir);
	return 0;
}

static int hwcxext_codec_v1_set_dai_fmt(struct snd_soc_dai *codec_dai,
	unsigned int fmt)
{
	hwlog_info("%s: fmt=%d\n", __func__, fmt);
	return 0;
}

static int hwcxext_codec_v1_pcm_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	int state = substream->runtime->status->state;
	hwlog_info("%s: hw_params state=%d\n", __func__, state);
	return 0;
}

static int hwcxext_codec_v1_set_dai_bclk_ratio(struct snd_soc_dai *dai,
	unsigned int ratio)
{
	hwlog_info("%s: ratio=%d\n", __func__, ratio);
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

static const struct snd_soc_component_driver soc_component_hwcxext_codec_v1 = {
	.probe			= hwcxext_codec_v1_probe,
	.set_bias_level = hwcxext_codec_v1_set_bias_level,
	.remove			= hwcxext_codec_v1_remove,
	.controls		= hwcxext_codec_v1_snd_controls,
	.num_controls		= ARRAY_SIZE(hwcxext_codec_v1_snd_controls),
	.dapm_widgets		= hwcxext_codec_v1_dapm_widgets,
	.num_dapm_widgets	= ARRAY_SIZE(hwcxext_codec_v1_dapm_widgets),
	.dapm_routes		= hwcxext_codec_v1_dapm_routes,
	.num_dapm_routes	= ARRAY_SIZE(hwcxext_codec_v1_dapm_routes),
};

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

static int hwcxext_codec_v1_get_hardvison(struct regmap *regmap)
{
	int ret = -ENXIO;
	unsigned int vendor_id = 0;
	unsigned int revison_id = 0;
	ret = regmap_read(regmap, HWCXEXT_CODEC_V1_VENDOR_ID, &vendor_id);
	if (ret) {
		hwlog_err("%s Failed to get vendor_id: %d\n", __func__, ret);
		return ret;
	}
	ret = regmap_read(regmap, HWCXEXT_CODEC_V1_REVISION_ID, &revison_id);
	if (ret) {
		hwlog_err("%s Failed to get revison_id: %d\n", __func__, ret);
		return ret;
	}
	hwlog_info("%s: get chip version: %08x, %08x\n", __func__, vendor_id, revison_id);
	return 0;
}

static int hwcxext_codec_v1_i2c_probe(struct i2c_client *i2c_client,
	const struct i2c_device_id *id)
{
	IN_FUNCTION;
	if (IS_ERR_OR_NULL(i2c_client)) {
		hwlog_err("%s: i2c_client is error\n", __func__);
		return -EFAULT;
	}
	struct device *dev = &i2c_client->dev;
	struct hwcxext_codec_v1_priv *hwcxext_codec = NULL;
	int ret;
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
		hwlog_err("%s error: hwcxext_i2c_regmap_init =%d.\n", __func__, ret);
		goto hwcxext_codec_v1_i2c_probe_err1;
	}
	ret = hwcxext_codec_v1_get_hardvison(hwcxext_codec->regmap_cfg->regmap);
	if (ret < 0) {
		hwlog_err("%s error: get_hardvison =%d.\n", __func__, ret);
		goto hwcxext_codec_v1_i2c_probe_err1;
	}
	ret = hwcxext_i2c_parse_dt_reg_ctl(i2c_client,
		&hwcxext_codec->init_regs_seq, "init_regs");
	if (ret < 0) {
		hwlog_err("%s error: hwcxext_codec_v1_i2c_probe_err2 reg_ctl =%d.\n", __func__, ret);
		goto hwcxext_codec_v1_i2c_probe_err2;
	}
	ret = hwcxext_codec_v1_register_component(&i2c_client->dev);
	if (ret < 0) {
		hwlog_err("%s error: hwcxext_codec_v1_i2c_probe_err3 component =%d.\n", __func__, ret);
		goto hwcxext_codec_v1_i2c_probe_err3;
	}
	hwcxext_codec_info_store_regmap(hwcxext_codec->regmap_cfg);
	hwcxext_codec_info_set_ctl_support(true);
	g_hwcxext_codec = hwcxext_codec;
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
	return 0;
}

static void hwcxext_codec_v1_i2c_shutdown(struct i2c_client *client)
{
	struct hwcxext_codec_v1_priv *hwcxext_codec = i2c_get_clientdata(client);
	if (hwcxext_codec == NULL || hwcxext_codec->regmap_cfg == NULL) {
		pr_err("%s: hwcxext_codec invalid\n", __func__);
		return;
	}
	pr_info("%s function comein\n", __func__);
	if (hwcxext_codec->regmap_cfg->freeze_flag == 1) {
		hwcxext_codec->regmap_cfg->freeze_flag = 0;
		pr_info("%s s4 comein\n", __func__);
		return;
	}
	int ret = hwcxext_codec_v1_soft_reset(hwcxext_codec->regmap_cfg);
	if (ret)
		pr_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);
	pr_info("%s function comeout\n", __func__);
}

static void hwcxext_codec_v1_soft_shutdown(void)
{
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL ||
		 g_hwcxext_codec->regmap_cfg->regmap == NULL) {
		pr_err("%s: g_hwcxext_codec invalid\n", __func__);
		return;
	}
	unsigned int status = 0;
	struct regmap *rmap = g_hwcxext_codec->regmap_cfg->regmap;
	pr_info("%s function comein\n", __func__);
	int ret = regmap_write(rmap, HWCXEXT_CODEC_V1_AFG_POWER_STATE, 0x03);
	if (ret)
		pr_err("%s: write AFG_POWER reg failed, error = %d\n", __func__, ret);

	ret = regmap_read(rmap, HWCXEXT_CODEC_V1_AFG_POWER_STATE, &status);
	if (ret) {
		pr_err("%s: read AFG_POWER reg failed, err = %d\n", __func__, ret);
	}
	pr_info("%s AFG_POWER reg values 0x%x\n", __func__, status);
}

const struct hwcxext_port_switch port_switch_out[] = {
	{PORTA_EN, HEADSET_PLAYBACK, hwcxext_codec_v1_set_porta},
	{PORTA_REAR_EN, REAR_HEADPHONE, hwcxext_codec_v1_set_porta_rear},
	{PORTG_EN, SPEAKER_PLAYBACK, hwcxext_codec_v1_set_portg},
};

const struct hwcxext_port_switch port_switch_in[] = {
	{PORTD_EN, HEADSET_MIC, hwcxext_codec_v1_set_portd},
	{PORTB_EN, REAR_MIC, hwcxext_codec_v1_set_portb},
	{PORTC_EN, REAR_LINEIN, hwcxext_codec_v1_set_portc},
};

static void hwcxext_codec_v1_set_port(struct hwcxext_mbhc_priv *mbhc)
{
	if (IS_ERR_OR_NULL(mbhc)) {
		pr_err("%s : mbhc_data is NULL!\n", __func__);
		return;
	}
	pr_info("%s hs_status = %d outen=%d, inen=%d\n", __func__,
		mbhc->hs_status, portout_en_state, portin_en_state);
	int i;
	for (i = 0; i < sizeof(port_switch_out) / sizeof(struct hwcxext_port_switch); i++) {
		// 单一优先级原则，若匹配成功，则可提前退出循环，无需匹配所有端口输出
		if (portout_en_state & port_switch_out[i].port) {
			hwcxext_codec_v1_set_switch(mbhc->component, port_switch_out[i].sw);
			port_switch_out[i].set_port(mbhc->component, true);
			break;
		}
	}
	for (i = 0; i < sizeof(port_switch_in) / sizeof(struct hwcxext_port_switch); i++) {
		// 单一优先级原则，若匹配成功，则可提前退出循环，无需匹配所有端口入
		if (portin_en_state & port_switch_in[i].port) {
			hwcxext_codec_v1_set_switch(mbhc->component, port_switch_in[i].sw);
			port_switch_in[i].set_port(mbhc->component, true);
			break;
		}
	}
	pr_info("%s function comeout\n", __func__);
}

static void hwcxext_codec_v1_hardware_disable(void)
{
	pr_info("%s function comein\n", __func__);
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL ||
		g_hwcxext_codec->mbhc_data == NULL || g_hwcxext_codec->component == NULL) {
		pr_err("%s: hwcxext_codec is inavild\n", __func__);
		return;
	}
	if (g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
		disable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
		pr_info("%s: disable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
	}
	hwcxext_codec_power_down(g_hwcxext_codec->component);
	hwcxext_codec_v1_set_mute(g_hwcxext_codec->component);
	int ret = hwcxext_codec_v1_soft_reset(g_hwcxext_codec->regmap_cfg);
	if (ret)
		pr_err("%s: codec soft reset failed, errorcode = %d\n", __func__, ret);
	hwcxext_mbhc_hs_jack_off(g_hwcxext_codec->mbhc_data);
}

static void hwcxext_codec_v1_hardware_enable(void)
{
	pr_info("%s function comein\n", __func__);
	if (g_hwcxext_codec == NULL || g_hwcxext_codec->regmap_cfg == NULL ||
		g_hwcxext_codec->init_regs_seq == NULL || g_hwcxext_codec->mbhc_data == NULL) {
		pr_err("%s: hwcxext_codec is inavild\n", __func__);
		return;
	}
	/* init regs */
	int ret = hwcxext_i2c_ops_regs_seq(g_hwcxext_codec->regmap_cfg, g_hwcxext_codec->init_regs_seq);
	if (ret)
		pr_err("%s: init regs failed\n", __func__);
	hwcxext_codec_v1_enable_jack_detect(g_hwcxext_codec->mbhc_data);
	hwcxext_codec_v1_set_port(g_hwcxext_codec->mbhc_data);
	/* init jack status */
	(void)hwcxext_codec_v1_btn_type_recognize(g_hwcxext_codec->mbhc_data);
	hwcxext_mbhc_detect_init_state(g_hwcxext_codec->mbhc_data);
	if (g_hwcxext_codec->mbhc_data->plug_btn_irq >= 0) {
		enable_irq(g_hwcxext_codec->mbhc_data->plug_btn_irq);
		pr_info("%s: enable irq : %d\n", __func__, g_hwcxext_codec->mbhc_data->plug_btn_irq);
	}
}

int hwcxext_codec_v1_suspend(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	hwcxext_codec_v1_hardware_disable();
	hwcxext_codec_v1_soft_shutdown();
	pr_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_resume(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	hwcxext_codec_v1_hardware_enable();
	pr_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_freeze(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	hwcxext_codec_v1_hardware_disable();
	g_hwcxext_codec->regmap_cfg->freeze_flag = 1;
	hwcxext_codec_v1_soft_shutdown();
	pr_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_restore(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	g_hwcxext_codec->regmap_cfg->freeze_flag = 0;
	hwcxext_codec_v1_hardware_enable();
	pr_info("%s function comeout\n", __func__);
	return 0;
}

int hwcxext_codec_v1_thaw(struct device *dev)
{
	pr_info("%s function comein\n", __func__);
	hwcxext_codec_v1_hardware_enable();
	pr_info("%s function comeout\n", __func__);
	return 0;
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
	IN_FUNCTION;
	mutex_init(&port_en_mutex);
	return i2c_add_driver(&hwcxext_codec_v1_i2c_driver);
}

static void __exit hwcxext_codec_v1_i2c_exit(void)
{
	IN_FUNCTION;
	i2c_del_driver(&hwcxext_codec_v1_i2c_driver);
	mutex_destroy(&port_en_mutex);
}

module_init(hwcxext_codec_v1_i2c_init);
module_exit(hwcxext_codec_v1_i2c_exit);

MODULE_DESCRIPTION("hwcxext codec v1 driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_LICENSE("GPL v2");
