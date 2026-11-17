/*
 * hwcxext_codec_ctl.h
 *
 * hwcxext_codec ioctl header file
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
 */
 
#ifndef __HWCXEXT_CODEC_CTL__
#define __HWCXEXT_CODEC_CTL__
#include "hwcxext_codec_def.h"
#include "hwcxext_codec_ctl_common.h"


typedef struct {
 void (*set_hp_us)(struct snd_soc_component *component, bool hp_type_us);
 void (*enable_hp_playback)(struct snd_soc_component *component, bool enable);
 void (*enable_hp_capture)(struct snd_soc_component *component, bool enable);
 void (*enable_speaker)(struct snd_soc_component *component, bool enable);
 void (*snd_soc_update_bits)(struct snd_soc_component *component, unsigned int reg,
     unsigned int mask, unsigned int value);
} hwcxext_codec_ctrl_ops_t;

struct hwcxext_codec_ctrl_priv {
	struct hwcxext_codec_v1_priv* hwcxext_codec;
	struct mutex do_ioctl_lock;
	hwcxext_codec_ctrl_ops_t* ops;
};

int hwcxext_codec_ctrl_init(struct hwcxext_codec_v1_priv *hwcxext_codec, hwcxext_codec_ctrl_ops_t *codec_ctrl_ops);
int hwcxext_codec_ctrl_deinit(void);

#endif
