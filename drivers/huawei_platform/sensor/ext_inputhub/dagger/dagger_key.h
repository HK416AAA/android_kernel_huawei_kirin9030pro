/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note
 * Copyright (c) Huawei Technologies Co., Ltd. 2024. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DAGGER_KEY_H_
#define DAGGER_KEY_H_

#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/pm.h>
#include <linux/pm_runtime.h>
#include <linux/sched.h>

#include <huawei_platform/log/hw_log.h>

#include "securec.h"
#include "ext_sensorhub_api.h"

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG dagger_key
HWLOG_REGIST();

#define DEVICE_MGR_SVR	0x01
#define APP_DEV_UPLOAD_VIRTUALKEY_EVENT	0x41
#define DAGGER_SERVICE_ID DEVICE_MGR_SVR
#define DAGGER_KEY_COMMAND_ID APP_DEV_UPLOAD_VIRTUALKEY_EVENT

#define DAGGER_SID_CID_COUNT 1
#define DAGGER_KEY_DATA_LEN 1

#define DAGGER_BASE_DEC 10

#define KEY_UP 0
#define KEY_DOWN 1

enum dagger_key_event_type {
	DAGGER_DOWN = 0,
	DAGGER_UP = 1,
	DAGGER_SINGLETAP = 2,
	DAGGER_LONGPRESS = 4,
	DAGGER_KEY_EVENT_TYPE_MAX,
};

struct dagger_key_payload {
	u8 event_type;
};

struct huawei_dagger_info {
	struct input_dev *input_dev;
	struct platform_device *pdev;
	struct mutex key_lock;
	int tap_keycode;
	int singletap_keycode;
	int longpress_keycode;
	int last_event_type;
};

#endif
