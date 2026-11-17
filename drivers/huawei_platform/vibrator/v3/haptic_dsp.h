/*
 * haptic_dsp.h
 *
 * common define for dsp hapic
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

#ifndef _HAPTIC_TYPES_H_
#define _HAPTIC_TYPES_H_

#include <linux/device.h>
#include <linux/hrtimer.h>
#include <linux/i2c.h>
#include <linux/leds.h>
#include <linux/mutex.h>
#include <linux/pm_wakeup.h>
#include <linux/regmap.h>
#include <linux/types.h>
#include <linux/workqueue.h>

#include "pa_haptic.h"
#include "pahaptic_dmd.h"

#define HAPTIC_DSP_IOCTL_GROUP                     0x52
#define HAPTIC_DSP_GET_HWINFO                      _IO(HAPTIC_DSP_IOCTL_GROUP, 0x03)
#define HAPTIC_DSP_SET_FREQ                        _IO(HAPTIC_DSP_IOCTL_GROUP, 0x04)
#define HAPTIC_PA_POWER_ON                         _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x05, short)
#define HAPTIC_CODEC_CTRL                          _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x06, short)
#define HAPTIC_DSP_STREAM_MODE                     _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x0A, short)
#define HAPTIC_DSP_UPDATE_RAM                      _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x10, short)
#define HAPTIC_DSP_GET_F0                          _IO(HAPTIC_DSP_IOCTL_GROUP, 0x11)
#define HAPTIC_DSP_STOP_MODE                       _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x12, short)
#define HAPTIC_DSP_CHECK_UPDATE                    _IO(HAPTIC_DSP_IOCTL_GROUP, 0x13)
#define HAPTIC_PA_PARAMS_MSG                       _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x14, short)
#define HAPTIC_DSP_F0_TEST                         _IO(HAPTIC_DSP_IOCTL_GROUP, 0x15)
#define HAPTIC_DSP_F0_GET_TEST_RST                 _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x16, short)
#define HAPTIC_DSP_PA_CONFIGS                      _IOW(HAPTIC_DSP_IOCTL_GROUP, 0x17, short)
#define MAX_HAPTIC_NUM                             2
#define HAPTIC_L                                   0
#define HAPTIC_R                                   1
#define HAPTIC_PA_SET_POWER_ON                     1
#define HAPTIC_F0_LOW_THRE                         161
#define HAPTIC_F0_HIGH_THRE                        181
#define HAPTIC_SHARED_PRIVATE_DATA_START           9700
#define HAPTIC_Q_BASE                              16
#define FLOAT_TO_FIX                               10
#define HAPTIC_CALI_DATA_NV_NUM                    470
#define HAPTIC_CALI_DATA_NAME                      "HAPTIC"
#define HAPTIC_R0_DEFAULT                          8000
#define NV_READ_TAG                                1
#define R_Q15                                      32768
#define HAPTIC_DEFAULT_R0                          77725

struct haptic_shared_prv_data_t {
    bool need_update_ram;
    bool stream_play_done;
};

struct dsp_haptic_t {
    uint32_t haptic_num;
    bool play_done;
    bool start_play_succ;
    struct pa_paptic_t *pa_haptic[MAX_HAPTIC_NUM];
    char *virt_map;
    struct haptic_shared_prv_data_t *shared_prv_data;
    uint32_t haptic_uefi_f0;
    uint32_t haptic_re0;
    uint32_t f0_compensation;
    struct haptic_bigdata_work_t haptic_bigdata_work;
};

struct dsp_haptic_t *get_dsp_haptic(void);

#endif