/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Audio Resource Control Mutex
 * Author: Shengzexuan Shengzexuan@huawei.com
 * Create: 2025-05-13
 */
#ifndef AUDIO_RESOURCE_MUTEX_H
#define AUDIO_RESOURCE_MUTEX_H

#include <linux/err.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/hwspinlock.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/wait.h>
#include <linux/mutex.h>

#include "contexthub_boot.h"
#include "contexthub_ext_log.h"
#include "contexthub_recovery.h"
#include "contexthub_route.h"
#include "sensor_info.h"
#include <securec.h>
#include <platform_include/smart/linux/base/ap/protocol.h>

enum audio_resource_control_type {
    AP_CODEC_CONTROL,
    AP_VIB_CONTROL,
    AP_AUDIO_CONTROL,
    SH_CODEC_CONTROL,
    SH_VIB_CONTROL,
    SH_AUDIO_CONTROL,
	RESOURCE_TYPE_MAX
};

enum dsp_reset_event {
    DSP_RESET_EVENT_SUSPEND,
    DSP_RESET_EVENT_RESUME,
    DSP_RESET_EVENT_BUTT
};

enum notify_kernel_type {
    SEND_SMARTPA_PARAM_NOTIFY = 0,
    RELEASE_CONTROL_NOTIFY = 1,
};

typedef struct {
	struct pkt_header hd;
	uint32_t value;
} pkt_arm_mcu_data;

int audio_resource_control_request(enum audio_resource_control_type usr_type);
int audio_resource_control_release(enum audio_resource_control_type usr_type);
int audiodsp_reset_notify(enum dsp_reset_event event);
#endif
