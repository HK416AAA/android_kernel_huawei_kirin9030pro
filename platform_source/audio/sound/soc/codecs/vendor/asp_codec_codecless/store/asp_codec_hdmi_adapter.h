/*
 * asp_codec_hdmi_adapter.h -- codec driver
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

#ifndef __ASP_CODEC_HDMI_ADAPTER_H__
#define __ASP_CODEC_HDMI_ADAPTER_H__

#include <sound/soc.h>

enum audio_display_output_type {
	HDMI_AUDIO_OUTPUT = 0,
	DP_AUDIO_OUTPUT,
};

void audio_display_jack_report(enum audio_display_output_type audio_display_type, bool is_plug_in);
int audio_display_jack_new(struct snd_soc_component *codec, enum audio_display_output_type audio_display_type);

#endif
