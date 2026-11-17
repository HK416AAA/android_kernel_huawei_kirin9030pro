/*
 * asp_codec_resource_control.h -- codec driver
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

#ifndef __ASP_CODEC_RESOURCE_CONTROL_H__
#define __ASP_CODEC_RESOURCE_CONTROL_H__

#include <linux/mutex.h>

#ifdef CONFIG_ASP_CODEC_RESOURCE_SHARED_WITH_SENSORHUB
void sensorhub_reset_notify_codec(void);
void asp_codec_resource_control_request(void);
void asp_codec_resource_control_release(void);
#define asp_codec_ctrl_mutex_lock(lock) mutex_lock(lock)
#define asp_codec_ctrl_mutex_unlock(lock) mutex_unlock(lock)
#else
#define sensorhub_reset_notify_codec()
#define asp_codec_resource_control_request()
#define asp_codec_resource_control_release()
#define asp_codec_ctrl_mutex_lock(lock)
#define asp_codec_ctrl_mutex_unlock(lock)
#endif

#endif
