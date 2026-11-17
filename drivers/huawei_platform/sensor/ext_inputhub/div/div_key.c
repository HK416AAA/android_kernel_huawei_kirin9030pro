/*
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
 
#include "div_key.h"
 
static struct huawei_div_info *g_div_info;
 
static struct sid_cid g_div_sid_cid[DIV_SID_CID_COUNT] = {
	{ DIV_SERVICE_ID, DIV_KEY_COMMAND_ID },
};
 
static struct subscribe_cmds g_div_cmds = {
	g_div_sid_cid, DIV_SID_CID_COUNT,
};
 
/*
 * Function:div_report_key_event
 * Description:report diffrent div keycode by input
 * Parameters:event_type: event type of diffrent div keycode
 * return:return value = 0 report successful, value < 0 report fail
 *		   for other reason
 */
static int div_report_key_event(int event_type)
{
	int ret = -EINVAL;

	if (!g_div_info || !g_div_info->input_dev) {
		hwlog_err("Div key or input isn't init\n");
		return ret;
	}
 
	mutex_lock(&g_div_info->key_lock);
	switch (event_type) {
	    case DIV_KEY_EVENT_DOWN:
		    input_report_key(g_div_info->input_dev, g_div_info->tap_keycode, DIV_KEY_DOWN);
		    ret = 0;
		    break;
	    case DIV_KEY_EVENT_UP:
		    input_report_key(g_div_info->input_dev, g_div_info->tap_keycode, DIV_KEY_UP);
		    ret = 0;
		    break;
	    default:
		    hwlog_err("Unkown key command:%d\n", event_type);
		    break;
	}
	input_sync(g_div_info->input_dev);
	mutex_unlock(&g_div_info->key_lock);
 
	return ret;
}
 
/*
 * Function:watch_div_recv_mcu_cb
 * Description:callback of double machine communication and get
 *              mcu data
 * Parameters:service_id: service id of double machine communication
 *            command_id: command id of double machine communication
 *            data: mcu data of double machine communication
 *            data_len: mcu data length of double machine communication
 * return:return value >= 0 recive mcu data successful, value < 0 recive
 *		      mcu data fail for other reason
 */
static int watch_div_recv_mcu_cb(unsigned char service_id, unsigned char command_id,
			unsigned char *data, int data_len)
{
	int ret;
	struct div_key_payload div_key_payload;
 
	if (!g_div_info) {
		hwlog_err("Div key isn't init\n");
		return -EINVAL;
	}
 
	if (service_id != DIV_SERVICE_ID || command_id != DIV_KEY_COMMAND_ID) {
		hwlog_err("Service id:%d, Command id: %d\n", service_id, command_id);
		return -EINVAL;
	}
 
	if (!data || data_len != DIV_KEY_DATA_LEN) {
		hwlog_err("Recv mcu response keypad data error datalen:%d\n", data_len);
		return -EINVAL;
	}
 
	if (memcpy_s(&div_key_payload, sizeof(div_key_payload), data, DIV_KEY_DATA_LEN) != EOK) {
		hwlog_err("Copy div_key_payload data failed\n");
		return -EINVAL;
	}
 
	hwlog_info("Div keyevent type from mcu: %d.\n", div_key_payload.event_type);
	ret = div_report_key_event(div_key_payload.event_type);
	if (ret < 0) {
		hwlog_err("Div report key event fail ret=%d\n", ret);
	}
 
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
	return register_data_callback(DIV_CHANNEL, &g_div_cmds, watch_div_recv_mcu_cb);
}
 
static int config_init_div_keycode(struct huawei_div_info *info)
{
	struct device_node *np = of_find_compatible_node(NULL, NULL, "huawei,div_key");
 
	if (!np) {
		hwlog_err("Div devicetree node isn't found\n");
		return -ENODEV;
	}
 
	if (of_property_read_u32(np, "div_tap_keycode", &info->tap_keycode)) {
		hwlog_err("of_property_read: tap_keycode not find\n");
		return -EFAULT;
	}

	return 0;
}
 
static int div_register_input_device(struct huawei_div_info *info)
{
	int ret;
	struct input_dev *input_dev = NULL;
 
	input_dev = input_allocate_device();
	if (!input_dev) {
		hwlog_err("Failed to allocate div input device\n");
		return -ENOMEM;
	}
 
	info->input_dev = input_dev;
	info->input_dev->name = "div_key";
	set_bit(EV_KEY, info->input_dev->evbit);
	set_bit(EV_SYN, info->input_dev->evbit);
	set_bit(info->tap_keycode, info->input_dev->keybit);
	input_set_drvdata(input_dev, info);
 
	ret = input_register_device(info->input_dev);
	if (ret) {
		hwlog_err("Failed to register div input device\n");
		input_free_device(info->input_dev);
		return -ENODEV;
	}
 
	return 0;
}
 
static int div_key_probe(struct platform_device *pdev)
{
	int ret;
	struct huawei_div_info *info = NULL;
 
	info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
	if (!info) {
		hwlog_err("Failed to allocate div key info\n");
		return -ENOMEM;
	}
 
	ret = config_init_div_keycode(info);
	if (ret < 0) {
		hwlog_err("Failed to config div keycode\n");
		return ret;
	}
 
	ret = div_register_input_device(info);
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
	info->pdev = pdev;
	platform_set_drvdata(pdev, info);
	g_div_info = info;
 
	hwlog_info("Div key probe end\n");
	return 0;
}
 
static int div_key_remove(struct platform_device *pdev)
{
	int ret;
	struct huawei_div_info *info = platform_get_drvdata(pdev);
 
	if (!info) {
		hwlog_err("Div_key_data is NULL\n");
		return -ENODEV;
	}
 
	if (info->input_dev) {
		input_unregister_device(info->input_dev);
		info->input_dev = NULL;
	}
 
	ret = unregister_data_callback(DIV_CHANNEL);
	if (ret < 0) {
		hwlog_err("Callback unreg fail ret=%d\n", ret);
	}
	
	mutex_destroy(&info->key_lock);
	platform_set_drvdata(pdev, NULL);
	g_div_info = NULL;
 
	hwlog_info("Div key removed end\n");
	return 0;
}
 
static const struct of_device_id div_key_match_table[] = {
	{
		.compatible = "huawei,div_key",
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, div_key_match_table);
 
static struct platform_driver div_key_driver = {
	.probe = div_key_probe,
	.remove = div_key_remove,
	.driver = {
		.name = "huawei,div_key",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(div_key_match_table),
	},
};
 
static int __init div_key_init(void)
{
	hwlog_info("Div key init enter\n");
	return platform_driver_register(&div_key_driver);
}
 
static void __exit div_key_exit(void)
{
	hwlog_info("Div key exit enter\n");
	platform_driver_unregister(&div_key_driver);
}
 
late_initcall(div_key_init);
module_exit(div_key_exit);
 
MODULE_DESCRIPTION("Huawei div keypad driver");
MODULE_LICENSE("GPL v2");