/*
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

#include "dagger_key.h"

static struct huawei_dagger_info *g_dagger_info;

static struct sid_cid g_dagger_sid_cid[DAGGER_SID_CID_COUNT] = {
	{ DAGGER_SERVICE_ID, DAGGER_KEY_COMMAND_ID },
};

static struct subscribe_cmds g_dagger_cmds = {
	g_dagger_sid_cid, DAGGER_SID_CID_COUNT,
};

/*
 * Function:dagger_report_key_event
 * Description:report diffrent dagger keycode by input
 * Parameters:event_type: event type of diffrent dagger keycode
 * return:return value = 0 report successful, value < 0 report fail
 *		   for other reason
 */
static int dagger_report_key_event(int event_type)
{
	if (!g_dagger_info || !g_dagger_info->input_dev) {
		hwlog_err("Dagger key or input isn't init\n");
		return -EINVAL;
	}

	mutex_lock(&g_dagger_info->key_lock);
	switch (event_type) {
	case DAGGER_DOWN:
		input_report_key(g_dagger_info->input_dev, g_dagger_info->tap_keycode, KEY_DOWN);
		break;
	case DAGGER_UP:
		if (g_dagger_info->last_event_type == DAGGER_LONGPRESS) {
			hwlog_info("Last keyevent is longpress, so report longpress key up\n");
			input_report_key(g_dagger_info->input_dev, g_dagger_info->longpress_keycode, KEY_UP);
		}
		input_report_key(g_dagger_info->input_dev, g_dagger_info->tap_keycode, KEY_UP);
		break;
	case DAGGER_SINGLETAP:
		input_report_key(g_dagger_info->input_dev, g_dagger_info->singletap_keycode, KEY_DOWN);
		input_report_key(g_dagger_info->input_dev, g_dagger_info->singletap_keycode, KEY_UP);
		break;
	case DAGGER_LONGPRESS:
		input_report_key(g_dagger_info->input_dev, g_dagger_info->longpress_keycode, KEY_DOWN);
		break;
	default:
		hwlog_err("Unkown key command:%d\n", event_type);
		break;
	}
	input_sync(g_dagger_info->input_dev);
	g_dagger_info->last_event_type = event_type;
	mutex_unlock(&g_dagger_info->key_lock);

	return 0;
}

/*
 * Function:watch_dagger_recv_mcu_cb
 * Description:callback of double machine communication and get
 *              mcu data
 * Parameters:service_id: service id of double machine communication
 *            command_id: command id of double machine communication
 *            data: mcu data of double machine communication
 *            data_len: mcu data length of double machine communication
 * return:return value >= 0 recive mcu data successful, value < 0 recive
 *		      mcu data fail for other reason
 */
static int watch_dagger_recv_mcu_cb(unsigned char service_id, unsigned char command_id,
			unsigned char *data, int data_len)
{
	int ret;
	struct dagger_key_payload dagger_key_payload;

	if (!g_dagger_info) {
		hwlog_err("Dagger key isn't init\n");
		return -EINVAL;
	}

	if (service_id != DAGGER_SERVICE_ID || command_id != DAGGER_KEY_COMMAND_ID) {
		hwlog_err("Service id:%d, Command id: %d\n", service_id, command_id);
		return -EINVAL;
	}

	if (!data || data_len != DAGGER_KEY_DATA_LEN) {
		hwlog_err("Recv mcu response keypad data error datalen:%d\n", data_len);
		return -EINVAL;
	}

	if (memcpy_s(&dagger_key_payload, sizeof(dagger_key_payload), data, DAGGER_KEY_DATA_LEN) != EOK) {
		hwlog_err("Copy dagger_key_payload data failed\n");
		return -EINVAL;
	}

	hwlog_info("Dagger keyevent type from mcu: %d.\n", dagger_key_payload.event_type);
	ret = dagger_report_key_event(dagger_key_payload.event_type);
	if (ret < 0)
		hwlog_err("Dagger report key event fail ret=%d\n", ret);

	return ret;
}

/*
 * Function:watch_register_mcu_report_callback
 * Description:regtister call back to double machine communication
 * Parameters:NA
 * return:return value >=0 register successful,value < 0 register fail
 *		  for other reason
 */
static int watch_register_mcu_report_callback(void)
{
	return register_data_callback(DAGGER_CHANNEL, &g_dagger_cmds, watch_dagger_recv_mcu_cb);
}

static int config_init_dagger_keycode(struct huawei_dagger_info *info)
{
	struct device_node *np = of_find_compatible_node(NULL, NULL, "huawei,dagger_key");

	if (!np) {
		hwlog_err("Dagger devicetree node isn't found\n");
		return -ENODEV;
	}

	if (of_property_read_u32(np, "dagger_tap_keycode", &info->tap_keycode)) {
		hwlog_err("of_property_read: tap_keycode not find\n");
		return -EFAULT;
	}

	if (of_property_read_u32(np, "dagger_singletap_keycode", &info->singletap_keycode)) {
		hwlog_err("of_property_read: singletap_keycode not find\n");
		return -EFAULT;
	}

	if (of_property_read_u32(np, "dagger_longpress_keycode", &info->longpress_keycode)) {
		hwlog_err("of_property_read: longpress_keycode not find\n");
		return -EFAULT;
	}

	return 0;
}

static int dagger_register_input_device(struct huawei_dagger_info *info)
{
	int ret;
	struct input_dev *input_dev = NULL;

	input_dev = input_allocate_device();
	if (!input_dev) {
		hwlog_err("Failed to allocate dagger input device\n");
		return -ENOMEM;
	}

	info->input_dev = input_dev;
	info->input_dev->name = "dagger_key";
	set_bit(EV_KEY, info->input_dev->evbit);
	set_bit(EV_SYN, info->input_dev->evbit);
	set_bit(info->tap_keycode, info->input_dev->keybit);
	set_bit(info->singletap_keycode, info->input_dev->keybit);
	set_bit(info->longpress_keycode, info->input_dev->keybit);
	input_set_drvdata(input_dev, info);

	ret = input_register_device(info->input_dev);
	if (ret) {
		hwlog_err("Failed to register dagger input device\n");
		input_free_device(info->input_dev);
		return -ENODEV;
	}

	return 0;
}

static int dagger_key_probe(struct platform_device *pdev)
{
	int ret;
	struct huawei_dagger_info *info = NULL;

	info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
	if (!info) {
		hwlog_err("Failed to allocate dagger key info\n");
		return -ENOMEM;
	}

	ret = config_init_dagger_keycode(info);
	if (ret < 0) {
		hwlog_err("Failed to config dagger keycode\n");
		return ret;
	}

	ret = dagger_register_input_device(info);
	if (ret < 0) {
		hwlog_err("Failed to register input device\n");
		return ret;
	}

	ret = watch_register_mcu_report_callback();
	if (ret < 0) {
		hwlog_err("Callback register fail ret=%d\n", ret);
		input_unregister_device(info->input_dev);
		info->input_dev = NULL;
		return -ENODEV;
	}

	mutex_init(&info->key_lock);
	info->last_event_type = DAGGER_DOWN;
	info->pdev = pdev;
	platform_set_drvdata(pdev, info);
	g_dagger_info = info;

	hwlog_info("Dagger key probe end\n");
	return 0;
}

static int dagger_key_remove(struct platform_device *pdev)
{
	int ret;
	struct huawei_dagger_info *info = platform_get_drvdata(pdev);

	if (!info) {
		hwlog_err("Dagger_key_data is NULL\n");
		return -ENODEV;
	}

	if (info->input_dev) {
		input_unregister_device(info->input_dev);
		info->input_dev = NULL;
	}

	ret = unregister_data_callback(SENSOR_CHANNEL);
	if (ret < 0)
		hwlog_err("Callback unreg fail ret=%d\n", ret);

	platform_set_drvdata(pdev, NULL);
	if (g_dagger_info) {
		kfree(g_dagger_info);
		g_dagger_info = NULL;
	}

	hwlog_info("Dagger key removed end\n");
	return 0;
}

static const struct of_device_id dagger_key_match_table[] = {
	{
		.compatible = "huawei,dagger_key",
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, dagger_key_match_table);

static struct platform_driver dagger_key_driver = {
	.probe = dagger_key_probe,
	.remove = dagger_key_remove,
	.driver = {
		.name = "huawei,dagger_key",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(dagger_key_match_table),
	},
};

static int __init dagger_key_init(void)
{
	hwlog_info("Dagger key init enter\n");
	return platform_driver_register(&dagger_key_driver);
}

static void __exit dagger_key_exit(void)
{
	hwlog_info("Dagger key exit enter\n");
	platform_driver_unregister(&dagger_key_driver);
}

late_initcall(dagger_key_init);
module_exit(dagger_key_exit);

MODULE_DESCRIPTION("Huawei dagger keypad driver");
MODULE_LICENSE("GPL v2");
