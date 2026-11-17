/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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
 
#ifndef DIV_KEY_H_
#define DIV_KEY_H_
 
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
#define HWLOG_TAG div_key
HWLOG_REGIST();
 
#define DIV_SERVICE_ID	0x01
#define DIV_KEY_COMMAND_ID	0x42
 
#define DIV_SID_CID_COUNT 1
#define DIV_KEY_DATA_LEN 1
 
#define DIV_KEY_UP 0
#define DIV_KEY_DOWN 1
 
enum div_key_event_type {
	DIV_KEY_EVENT_UP = 0,
	DIV_KEY_EVENT_DOWN = 1,
	DIV_KEY_EVENT_TYPE_MAX,
};
 
struct div_key_payload {
	u8 event_type;
};
 
struct huawei_div_info {
	struct input_dev *input_dev;
	struct platform_device *pdev;
	struct mutex key_lock;
	int tap_keycode;
};
 
#endif