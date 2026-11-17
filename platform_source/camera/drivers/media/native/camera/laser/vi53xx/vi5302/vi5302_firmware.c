/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/firmware.h>

#include "vi5302_firmware.h"

uint8_t vi5302_firmware[FIRMWARE_NUM];

uint32_t vi5302_loadfirmware(vi5302_dev dev)
{
	const struct firmware *firmware;
	const char *fw_name = NULL;
	uint32_t data_size;
	int err;

	fw_name = "VI5302_Firmware.bin";

	err = request_firmware(&firmware, fw_name, dev->dev);
	if (err  || !firmware) {
		vi5302_errmsg("Firmware request failed!\n");
		return err;
	} else {
		vi5302_infomsg("Firmware request succeeded!\n");
	}
	data_size = (uint32_t)firmware->size;
	vi5302_dbgmsg("vi5302_firmware size:%d\n", data_size);

	if (memcpy_s(vi5302_firmware, FIRMWARE_NUM, firmware->data, firmware->size) != EOK)
		vi5302_errmsg("memcpy_s failed");
	release_firmware(firmware);
	return data_size;
}
