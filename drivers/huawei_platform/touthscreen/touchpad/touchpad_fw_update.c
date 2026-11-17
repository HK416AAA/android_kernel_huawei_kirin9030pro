/*
 * Huawei touchpad fw update driver
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

#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/firmware.h>
#include <linux/hid.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/syscalls.h>
#include <securec.h>
#include "touchpad_func.h"
#include "touchpad_api.h"
#include "touchpad_tp_ic_update.h"
#include "touchpad_log.h"

#ifdef CONFIG_HUAWEI_OHOS_DSM
#include <dfx/hiview_hisysevent.h>
#endif

#define BTL_BIN_VER_PKG_OFFSET		(0xfc2a)
#define CHECK_UPDATE_TYPE			4
#define BTL_BIN_VER_IC_OFFSET_LOW	5
#define BTL_BIN_VER_IC_OFFSET_HIGH	6
#define BIGDATA_REPORT_MAXLEN 256

enum {
	FW_UPDATE_CONFIRM = 0,
	FW_UPDATE_MCU = 1,
	FW_UPDATE_BTL = 2,
	BTL_ERR_NEED_NOT_UPDATE,
};


struct touchpad_fw_update_data {
	int mcu_status_gpio;
	int chip_type;
	u8 feature_code[FEATURE_CODE_LEN];
	struct delayed_work work;
	struct i2c_client *client;
};

static struct touchpad_fw_update_data *g_tp_update_data = NULL;
static bool g_enter_recovery = false;

int hid_dev_match(struct device *dev, const void *data)
{
	const struct i2c_client *client = data;
	struct hid_device *hid = to_hid_device(dev);

	if (!hid)
		return -EINVAL;

	return (hid->bus == BUS_I2C) && (hid->driver_data == client);
}

/**
 * @description: 
 * @brief	校验是否升级
 * @return {int} 0:升级
 * @param {fw_version} *pkg_ver 待升级文件
 * @param {fw_version} *ic_ver
 * @param {u32} update_type	0:mcu/1:btl
 */
static int firmware_update_judge(struct fw_version *pkg_ver, struct fw_version *ic_ver, u32 update_type) {
	if (!pkg_ver || !ic_ver)
		return -EINVAL;

	switch (update_type) {
		case MAIN_BIN: // mcu升级，版本校验
#ifdef TOUCHPAD_FACTORY_ENABLE
			for (int i = 0; i < HW_FREETOUCH_FW_MCU_VERSION_LEN; i++)
				if (ic_ver->version[i] != pkg_ver->version[i])
					return FW_UPDATE_CONFIRM;
#else
			for (int i = 0; i < HW_FREETOUCH_FW_MCU_VERSION_LEN; i++) {
				if (ic_ver->version[i] > pkg_ver->version[i])
					return -EINVAL;
				else if (ic_ver->version[i] < pkg_ver->version[i])
					return FW_UPDATE_CONFIRM;
			}
#endif
			break;
		case BTL_UPDATE_SIGN:
			/* major version range (0, 0x80) or 0xff，版本号invalid->更新 */
			if (ic_ver->version[BTL_BIN_VER_IC_OFFSET_LOW] == 0x00 || ic_ver->version[BTL_BIN_VER_IC_OFFSET_LOW] >= 0x80)
				return FW_UPDATE_CONFIRM;
			else if (ic_ver->version[BTL_BIN_VER_IC_OFFSET_LOW] < pkg_ver->version[BTL_BIN_VER_IC_OFFSET_LOW]) /* 老版本->更新 */
				return FW_UPDATE_CONFIRM;
			else if(ic_ver->version[BTL_BIN_VER_IC_OFFSET_LOW] == pkg_ver->version[BTL_BIN_VER_IC_OFFSET_LOW]) { /* 不需要更新 */
				tp_log_info("BTL Need not Update Fw\n");
				return BTL_ERR_NEED_NOT_UPDATE;
			}
			break;
		default:
			tp_log_err("invalid update type: %d\n", update_type);
			break;
	}
	return -EINVAL;
}

/**
 * @description: 
 * @brief	取pkg中mcu/btl版本号
 * @return {int} 0:success
 * @param {u32} update_type 0:mcu/4:btl
 */
static int check_version(struct fw_version *mcu_ver, const u8 *fw_data, u32 fw_len, u32 update_type)
{
	int ret;
	struct fw_version pkg_ver;

	if (!mcu_ver || !fw_data)
		return -EINVAL;
	// 从 fw_data 中取 pkg 版本
	switch (update_type) {
		case MAIN_BIN:
			ret = touchpad_get_package_version(fw_data, fw_len, &pkg_ver);
			if (ret) {
				tp_log_err("get package version failed, ret: %d\n", ret);
				return ret;
			}
			break;
		case BTL_UPDATE_SIGN:
			pkg_ver.version[BTL_BIN_VER_IC_OFFSET_LOW] = fw_data[BTL_BIN_VER_PKG_OFFSET];
			break;
		default:
			tp_log_err("invalid update type: %d\n", update_type);
			break;
	}
	tp_log_info("mcu package version: %d.%d.%d.%d.%d.%d.%d.%d\n",
				pkg_ver.version[0], pkg_ver.version[1], pkg_ver.version[2], pkg_ver.version[3],
				pkg_ver.version[4], pkg_ver.version[5], pkg_ver.version[6], pkg_ver.version[7]);
	ret = firmware_update_judge(&pkg_ver, mcu_ver, update_type);
	if (ret)
		tp_log_info("firmware update judge:%d\n", ret);
	return ret;
}

/**
 * @description: 
 * @brief	从mcu中取出固件信息，确认btl
 * @return {int} 0:success
 * @param {hid_device} *hdev
 * @param {int} &update_type 存储固件类型
 */
static int get_firmware_type_btl_goodix(struct hid_device *hdev, int *update_type, struct fw_version *mcu_ver) {
	int ret;

	if (!hdev || !mcu_ver)
		return -EINVAL;
	// 从mcu中读所有版本号
	ret = touchpad_get_mcu_fw_version(hdev, mcu_ver);
	if (ret) {
		tp_log_err("get mcu fw version failed, ret: %d\n", ret);
		return ret;
	}
	tp_log_info("mcu fw version: %d.%d.%d.%d.%d.%d.%d.%d\n",
		mcu_ver->version[0], mcu_ver->version[1], mcu_ver->version[2], mcu_ver->version[3],
		mcu_ver->version[4], mcu_ver->version[5], mcu_ver->version[6], mcu_ver->version[7]);
	*update_type = mcu_ver->version[CHECK_UPDATE_TYPE];
	return FW_UPDATE_CONFIRM;
}

#ifdef CONFIG_HUAWEI_OHOS_DSM
static void report_update_bigdata(char *msg)
{
	struct hiview_hisysevent *event = NULL;
	event = hisysevent_create("THP", "DFT_STAT_NUM_EDGE_CLCIK", STATISTIC);
	if (event == NULL) {
        tp_log_info("create hisysevent failed in %s", __func__);
        return;
    }
	int ret = hisysevent_put_string(event, "FAULT_MSG", msg);
	tp_log_info("hisysevent_put_string: ret = %d\n", ret);
	ret = hisysevent_write(event);
	tp_log_info("hisysevent_write: ret = %d\n", ret);
	hisysevent_destroy(&event);
}
#endif

static void update_mcu_firmware(struct hid_device *hdev)
{
	int ret = FW_UPDATE_CONFIRM;
	int update_type = -1;
	const struct firmware *fw = NULL;
	struct fw_version ver;
	struct fw_version mcu_ver;
	if (!hdev)
		return;

	struct i2c_client *client = hdev->driver_data;
	if (!client || get_firmware_type_btl_goodix(hdev, &update_type, &mcu_ver))
		return;
	// mcu升级判断
	if (!request_firmware_direct(&fw, "freetouch_mcu_fw.bin", &client->dev) &&
		!check_version(&mcu_ver, fw->data, fw->size, MAIN_BIN)) {
		update_type = MAIN_BIN;
	} else if (update_type == BTL_UPDATE_SIGN &&
		!request_firmware_direct(&fw, "freetouch_tp_ic_btl.bin", &client->dev) &&
		!check_version(&mcu_ver, fw->data, fw->size, update_type)) { // btl 升级
		update_type = BTL_BIN;
	} else {
		ret = -EINVAL;
	}
	tp_log_info("update type: %d , if update: %d\n", update_type, ret);
	if (ret != FW_UPDATE_CONFIRM)
		goto err_firmware;
	
	(void)set_fw_feature_code(g_tp_update_data->feature_code, sizeof(g_tp_update_data->feature_code));
	(void)disable_irq(client->irq);
	// 开始升级
	ret = touchpad_update_mcu_fw(hdev, fw->data, fw->size, update_type, g_tp_update_data->mcu_status_gpio);
	(void)enable_irq(client->irq);
	tp_log_info("firmware update: %d\n", ret);
	/* wait mcu ready */
	msleep(2000);
	(void)touchpad_get_mcu_fw_version(hdev, &ver);
	tp_log_info("version after update: %d.%d.%d.%d\n", ver.version[0], ver.version[1], ver.version[2], ver.version[3]);
	//report bigdata
#ifdef CONFIG_HUAWEI_OHOS_DSM
	char msg[BIGDATA_REPORT_MAXLEN] = { 0 };
	sprintf_s(msg, sizeof(msg), "version_after_update[%d.%d.%d.%d], is_recovery[%d]",
		ver.version[0], ver.version[1], ver.version[2], ver.version[3], g_enter_recovery);
	report_update_bigdata(msg);
	if (ret != 0) {
		memset_s(msg, sizeof(msg), 0, sizeof(msg));
		sprintf_s(msg, sizeof(msg), "update_failed[%d], is_recovery[%d]", ret, g_enter_recovery);
		report_update_bigdata(msg);
	}
#endif
err_firmware:
	release_firmware(fw);
}

static void update_tp_ic_firmware(struct i2c_client *client, int chip_type)
{
	int ret;
	const struct firmware *fw = NULL;
	const struct firmware *cfg = NULL;
	const struct tp_ic_update_ops *ops = get_tp_ic_update_ops(chip_type);

	if (!client || !ops || !ops->check_version || !ops->update_fw)
		return;

	tp_log_info("%s enter!\n", __func__);
	ret = request_firmware_direct(&fw, ops->fw_name, &client->dev);
	if (ret) {
		tp_log_err("request firmware failed, name: %s, ret: %d\n", ops->fw_name, ret);
		return;
	}
	tp_log_info("firmware size: %lld\n", fw->size);

	if (ops->cfg_name) {
		ret = request_firmware_direct(&cfg, ops->cfg_name, &client->dev);
		if (ret) {
			tp_log_err("request cfg failed, name: %s, ret: %d\n", ops->cfg_name, ret);
			goto err_firmware;
		}
	}

	(void)disable_irq(client->irq);
	ret = ops->check_version(client, fw->data, fw->size, cfg ? cfg->data : NULL, cfg ? cfg->size : 0);
	if (ret) {
		(void)enable_irq(client->irq);
		tp_log_err("check version failed, ret: %d\n", ret);
		goto err_firmware;
	}
	ret = ops->update_fw(client, fw->data, fw->size, cfg ? cfg->data : NULL, cfg ? cfg->size : 0);
	(void)enable_irq(client->irq);
	tp_log_info("tp ic firmware update: %d\n", ret);

err_firmware:
	release_firmware(cfg);
	release_firmware(fw);
}

void wait_chip_prod_mount(int timeout)
{
	int wait_time;
	unsigned long old_fs;
	const int schedule_time = 1000;
	const char *chip_prod_partition = "/chip_prod/etc/firmware/ts";

	old_fs = get_fs();

	for (wait_time = 0; wait_time < timeout; wait_time += schedule_time) {
		if (!ksys_access(chip_prod_partition, 0))
			break;

		msleep(schedule_time);
	}

	set_fs(old_fs);
}

void touchpad_fw_update(struct work_struct *work)
{
	struct device *dev;
	struct hid_device *hdev;

	tp_log_info("%s enter\n", __func__);

	if (g_tp_update_data == NULL) {
		tp_log_err("g_tp_update_data is NULL\n");
		return;
	}

	dev = bus_find_device(&hid_bus_type, NULL, g_tp_update_data->client, hid_dev_match);
	if (dev == NULL) {
		tp_log_err("cannot find hid device\n");
		return;
	}

	if (!g_enter_recovery) {
		/* 600000: Wait for chip_prod image mount complete, timeout 60s */
		wait_chip_prod_mount(60000);
	}
	hdev = to_hid_device(dev);
	tp_log_err("delay 2s before mcu update!\n");
	msleep(2000); // 2000: Wait for 2s until the MCU ready, The MCU maybe processing the nfc work
	update_mcu_firmware(hdev);
}

static int touchpad_fw_update_probe(struct i2c_client *client)
{
	int ret;

	if (client == NULL || g_tp_update_data != NULL)
		return -EINVAL;

	g_tp_update_data = kmalloc(sizeof(struct touchpad_fw_update_data), GFP_KERNEL);
	if (g_tp_update_data == NULL)
		return -ENOMEM;

	/* mcu feature code, distinguish between different projects */
	ret = of_property_read_u8_array(client->dev.of_node, "feature-code",
		g_tp_update_data->feature_code, sizeof(g_tp_update_data->feature_code));
	if (ret) {
		tp_log_err("feature code not provided\n");
		goto err;
	}

	ret = of_property_read_u32(client->dev.of_node, "mcu-status-gpio", &g_tp_update_data->mcu_status_gpio);
	if (ret) {
		tp_log_err("mcu status gpio not provided\n");
		goto err;
	}

	ret = of_property_read_u32(client->dev.of_node, "chip-type", &g_tp_update_data->chip_type);
	if (ret) {
		tp_log_err("chip type not provided\n");
		g_tp_update_data->chip_type = TP_IC_TYPE_UNKNOWN;
	}

	g_tp_update_data->client = client;

	if (g_enter_recovery) {
		tp_log_info("mode is recovery, skip kernel update");
        return 0;
	}

	INIT_DELAYED_WORK(&g_tp_update_data->work, touchpad_fw_update);
	queue_delayed_work(system_wq, &g_tp_update_data->work, msecs_to_jiffies(10000)); // 10000: delay 10s
	return 0;

err:
	kfree(g_tp_update_data);
	g_tp_update_data = NULL;
	return ret;
}

static int __init enter_recovery_setup(char *arg)
{
	if (arg) {
		g_enter_recovery = (strncmp(arg, "1", 1) == 0) ? true : false; // strlen"1" is 1
		tp_log_info("enter_mode = %s\n", g_enter_recovery ? "recovery" : "normal");
	}
	return 0;
}
early_param("enter_recovery", enter_recovery_setup);

static void touchpad_fw_update_remove()
{
	if (g_tp_update_data) {
		kfree(g_tp_update_data);
		g_tp_update_data = NULL;
	}
}

static struct touchpad_func tp_fw_update = {
	.name = "tp_fw_update",
	.type = TOUCHPAD_FW_UPDATE,
	.probe = touchpad_fw_update_probe,
	.remove = touchpad_fw_update_remove,
};

static int __init touchpad_fw_update_init(void)
{
	return touchpad_register_func(&tp_fw_update);
}

static void __exit touchpad_fw_update_exit(void)
{
	touchpad_unregister_func(&tp_fw_update);
}

late_initcall(touchpad_fw_update_init);
module_exit(touchpad_fw_update_exit);

MODULE_AUTHOR("Huawei Technologies Co., Ltd");
MODULE_DESCRIPTION("touchpad module driver");
MODULE_LICENSE("GPL");