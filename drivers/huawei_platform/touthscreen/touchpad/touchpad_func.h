/*
 * Huawei touchpad ops
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef __HUAWEI_TOUCHPAD_FUNC_H__
#define __HUAWEI_TOUCHPAD_FUNC_H__

enum touchpad_func_type {
	TOUCHPAD_CMD_CHL,
	TOUCHPAD_FW_UPDATE,
	TOUCHPAD_THIRD_UPDATE,
	TOUCHPAD_FUNC_MAX,
};

struct touchpad_func {
	const char *name;
	enum touchpad_func_type type;
	int (*probe)(struct i2c_client *client);
	void (*remove)();
};

struct touchpad_device_info {
    const char* name;
    int (*entry)(struct hid_device *hdev);
    struct hid_device_id device_id;
};

int touchpad_register_func(struct touchpad_func *func);
void touchpad_unregister_func(struct touchpad_func *func);
void touchpad_fw_update(struct work_struct *work);
void touchpad_thirdparty_register(struct touchpad_device_info *info);
void wait_chip_prod_mount(int timeout);

#ifdef TOUCHPAD_FACTORY_ENABLE
#define TOUCHPAD_FAC_TEST_IN_SOC	_IO(0xED, 0x16)

typedef int (*TestFunc)(void);
void touchpad_register_test_func(TestFunc func);
#endif

#endif
