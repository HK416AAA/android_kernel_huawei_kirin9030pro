/*
 * hwcxext_codec_ctl_common.h
 *
 * hwcxext_codec ioctl common header file
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
 
#ifndef __HWCXEXT_CODEC_CTL_COMMON__
#define __HWCXEXT_CODEC_CTL_COMMON__

typedef enum {
	HP_TYPE_CTIA, // 美标
	HP_TYPE_OMTP  // 欧标
} HP_TYPE;

typedef enum {
	SPK_DIR_BOTH,
	SPK_DIR_LEFT,
	SPK_DIR_RIGHT
} SPK_DIR;

#define CODEC_GET_HEADPHONE_STATUS  _IOR('M', 0x01, int)
#define CODEC_SET_HEADPHONE_TYPE   _IOW('M', 0x02, HP_TYPE)
#define CODEC_SET_USE_SPEAKER 	_IOW('M', 0x03, int)
#define CODEC_SET_SPEAKER_DIR   _IOW('M', 0x04, SPK_DIR)
#define CODEC_SET_USE_DMIC 	_IOW('M', 0x05, bool)

#define CODEC_GET_HEADPHONE_STATUS_COMP   _IOR('M', 0x01, int)
#define CODEC_SET_HEADPHONE_TYPE_COMP   _IOW('M', 0x02, HP_TYPE)
#define CODEC_SET_USE_SPEAKER_COMP 	_IOW('M', 0x03, int)
#define CODEC_SET_SPEAKER_DIR_COMP   _IOW('M', 0x04, SPK_DIR)
#define CODEC_SET_USE_DMIC_COMP 	_IOW('M', 0x05, bool)
#endif
