/*
 * touchpad.c
 *
 * touchpad driver
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/regulator/consumer.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/suspend.h>
#include <securec.h>
#include <platform_include/cee/linux/ulsr.h>
#include <../drivers/hid/i2c-hid/i2c-hid.h>
#include "touchpad_func.h"
#include "touchpad_api.h"

#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif

#define TOUCHPAD_SR_NOTIFIER_PRIORITY	0
#define TOUCHPAD_HID_PWR_ON		0x00
#define VERSION_MAX_LEN 50

struct touchpad_data {
	int reset_gpio;
	int reset_gpio_status;
	int shut_gpio;
	int post_power_delay_ms;
	int regulator_volt[2];
	bool wakeup_source;
	struct i2c_client *client;
	struct regulator_bulk_data supplies[2];
};

static struct touchpad_data *g_touchpad_data = NULL;
static struct touchpad_func* g_touchpad_func[TOUCHPAD_FUNC_MAX];
static int regulator_bulk_enable_sync(int num_consumers, struct regulator_bulk_data *consumers, const int *volts);

static void touchpad_parse_dts(struct device_node *np, struct touchpad_data *pdata)
{
	if (!np || !pdata) {
		pr_err("np or pdata is NULL\n");
		return;
	}
	if (of_property_read_u32(np, "reset-gpio", (u32 *)&pdata->reset_gpio))
		pdata->reset_gpio = -1;

	pr_info("touchpad reset-gpio: %d\n", pdata->reset_gpio);

	if (of_property_read_u32(np, "reset-gpio-status", (u32 *)&pdata->reset_gpio_status))
		pdata->reset_gpio_status = 1;

	pr_info("touchpad reset-gpio-status: %d\n", pdata->reset_gpio_status);

	if (of_property_read_u32(np, "shut-gpio", (u32 *)&pdata->shut_gpio))
		pdata->shut_gpio = -1;

	pr_info("touchpad shut-gpio: %d\n", pdata->shut_gpio);

	if (of_property_read_u32(np, "post-power-delay-ms", (u32 *)&pdata->post_power_delay_ms))
		pdata->post_power_delay_ms = 0;

	pr_info("touchpad post-power-delay-ms: %d\n", pdata->post_power_delay_ms);

	if (of_property_read_u32(np, "vdd-volt", (u32 *)&pdata->regulator_volt[0]))
		pdata->regulator_volt[0] = 0;

	pr_info("touchpad vdd-volt: %d\n", pdata->regulator_volt[0]);

	if (of_property_read_u32(np, "vddl-volt", (u32 *)&pdata->regulator_volt[1]))
		pdata->regulator_volt[1] = 0;

	pr_info("touchpad vddl-volt: %d\n", pdata->regulator_volt[1]);

	pdata->wakeup_source = of_property_read_bool(np, "wakeup_source");
	pr_info("touchpad wakeup_source: %d\n", pdata->wakeup_source);
}

int touchpad_register_func(struct touchpad_func *func)
{
	if (func == NULL || func->type >= TOUCHPAD_FUNC_MAX)
		return -EINVAL;

	if (g_touchpad_func[func->type] != NULL) {
		pr_info("repeated registration func: %s!\n", func->name);
		return -EINVAL;
	}

	g_touchpad_func[func->type] = func;

	if (g_touchpad_data && g_touchpad_data->client) {
		pr_info("touchpad aleardy online call func: %s!\n", func->name);
		return func->probe(g_touchpad_data->client);
	}
	return 0;
}

void touchpad_unregister_func(struct touchpad_func *func)
{
	if (func == NULL || func->type >= TOUCHPAD_FUNC_MAX)
		return;

	if (g_touchpad_func[func->type] == NULL)
		return;

	g_touchpad_func[func->type]->remove();
	g_touchpad_func[func->type] = NULL;
}

static int touchpad_power_up()
{
	if (!g_touchpad_data || !g_touchpad_data->supplies || !g_touchpad_data->regulator_volt) {
		return -EINVAL;
	}
	pr_info("touchpad_mcu_power_up\n");
	return regulator_bulk_enable_sync(ARRAY_SIZE(g_touchpad_data->supplies), g_touchpad_data->supplies,
		g_touchpad_data->regulator_volt);
}

static int touchpad_power_down()
{
	if (!g_touchpad_data || !g_touchpad_data->supplies) {
		return -EINVAL;
	}
	pr_info("touchpad_mcu_power_down\n");
	return regulator_bulk_disable(ARRAY_SIZE(g_touchpad_data->supplies), g_touchpad_data->supplies);
}

#ifdef CONFIG_HISYSEVENT
static void report_reset_bigdata(char *msg)
{
	struct hiview_hisysevent *event = NULL;
	event = hisysevent_create("THP", "DFT_STAT_NUM_EDGE_CLCIK", STATISTIC);
	if (event == NULL) {
        pr_info("create hisysevent failed in %s", __func__);
        return;
    }
	int ret = hisysevent_put_string(event, "FAULT_MSG", msg);
	pr_info("hisysevent_put_string: ret = %d\n", ret);
	ret = hisysevent_write(event);
	pr_info("hisysevent_write: ret = %d\n", ret);
	hisysevent_destroy(&event);
}
#endif

static void touchpad_reset(struct i2c_hid *ihid)
{
	ktime_t diff = 2 * NSEC_PER_SEC; // 2: 2s
	if (!ihid || !ihid->hid || !ihid->hid->driver || !ihid->hid->driver->reset_resume) {
		pr_err("Invalid parameter\n");
		return;
	}
	if (ktime_sub(ktime_get(), ihid->pdata.last_reset_time) < diff) {
		pr_info("touchpad reset too often, return\n");
		ihid->pdata.last_reset_time = ktime_get();
		return;
	}
	pr_info("power down touchpad\n");
	touchpad_power_down();
	msleep(100); // 100: Let touchpad power down complete
	pr_info("power up touchpad\n");
	touchpad_power_up();
	msleep(1500); // 1500: touchpad need about 1.5s to ready
	pr_info("start to send cmd\n");
	i2c_hid_set_power(ihid->client, TOUCHPAD_HID_PWR_ON);
	ihid->hid->driver->reset_resume(ihid->hid);
	ihid->pdata.last_reset_time = ktime_get();
#ifdef CONFIG_HISYSEVENT
	report_reset_bigdata("driver_reset");
#endif
}

static void check_touchpad_mcu(struct i2c_hid *ihid, int size)
{
	int i = 0;
	int try = 3; // 3: retry times;
	for (; i < try; i++) {
		pr_info("mcu may err, retry i = %d\n", i);
		if (i2c_master_recv(ihid->client, ihid->inbuf, size) == size)
			break;
		msleep(250); // 250: delay interval
	}
	if (i == try) {
		pr_info("mcu not ack, reset touchpad\n");
		touchpad_reset(ihid);
	}
}

static void lid_event(struct input_handle *handle, unsigned int type, unsigned int code, int value)
{
	struct touchpad_data *pdata;

	if (!handle || !handle->private || type != EV_SW || code != SW_LID)
		return;

	pdata = handle->private;
	pr_info("[touchpad] lid status: %d\n", value);

	if (!gpio_is_valid(pdata->shut_gpio))
		return;

	/* lid close: pull up shut-gpio, lid open: pull down shut-gpio */
	if (value)
		gpio_set_value(pdata->shut_gpio, 1);
	else
		gpio_set_value(pdata->shut_gpio, 0);
}

static int lid_connect(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id)
{
	int ret;
	struct input_handle *handle;

	if (!handler)
		return -EINVAL;

	handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
	if (!handle)
		return -ENOMEM;

	handle->dev = dev;
	handle->handler = handler;
	handle->private = handler->private;
	handle->name = "lid_handler";

	ret = input_register_handle(handle);
	if (ret)
		goto err_free;

	ret = input_open_device(handle);
	if (ret)
		goto err_unregister;

	return 0;

err_unregister:
	input_unregister_handle(handle);
err_free:
	kfree(handle);
	return ret;
}

static void lid_disconnect(struct input_handle *handle)
{
	input_close_device(handle);
	input_unregister_handle(handle);
	kfree(handle);
}

static const struct input_device_id lid_ids[] = {
	{
		.flags = INPUT_DEVICE_ID_MATCH_SWBIT,
		.swbit = { BIT_MASK(SW_LID) },
	},
	{ },
};

MODULE_DEVICE_TABLE(input, lid_ids);

static struct input_handler lid_handler = {
	.name = "lid_handler",
	.event = lid_event,
	.connect = lid_connect,
	.disconnect = lid_disconnect,
	.id_table =	lid_ids,
};

static struct i2c_touchpad_ops touchpad_ops = {
	.check_touchpad = check_touchpad_mcu,
	.reset_touchpad = touchpad_reset,
};

static void touchpad_device_online(struct i2c_client *client)
{
	int i;
	int ret;
	unsigned int support_reset = 0;

	if (!g_touchpad_data || !client)
		return;

	if (g_touchpad_data->client) {
		pr_info("touchpad aleardy online, ignore!\n");
		return;
	}
	g_touchpad_data->client = client;

	device_disable_async_suspend(&client->dev);

	lid_handler.private = g_touchpad_data;
	ret = input_register_handler(&lid_handler);
	if (ret)
		pr_err("failed to register handler for lid event\n");

	ret = of_property_read_u32(client->dev.of_node, "support-reset", &support_reset);
	if (!ret && support_reset)
		touchpad_register_ops(client, &touchpad_ops);

	for (i = 0; i < TOUCHPAD_FUNC_MAX; ++i) {
		if (g_touchpad_func[i] != NULL && g_touchpad_func[i]->probe != NULL) {
			pr_info("foreach func name: %s\n", g_touchpad_func[i]->name);
			ret = g_touchpad_func[i]->probe(client);
			if (ret)
				pr_info("touchpad func %s probe failed %d\n", g_touchpad_func[i]->name, ret);
		}
	}
}

static void touchpad_device_offline(struct i2c_client *client)
{
	int i;

	if (!g_touchpad_data)
		return;

	if (client != g_touchpad_data->client) {
		pr_info("touchpad addr not match, ignore!\n");
		return;
	}
	g_touchpad_data->client = NULL;

	input_unregister_handler(&lid_handler);

	for (i = 0; i < TOUCHPAD_FUNC_MAX; ++i) {
		if (g_touchpad_func[i] != NULL && g_touchpad_func[i]->remove != NULL)
			g_touchpad_func[i]->remove();
	}
}

static int touchpad_i2cdev_notifier_call(struct notifier_block *nb, unsigned long action, void *data)
{
	struct device *dev = data;
	struct i2c_client *client;

	if (dev->type != &i2c_client_type)
		return 0;

	client = to_i2c_client(dev);
	if(!client) {
		pr_err("client is NULL\n");
		return 0;
	}
	switch (action) {
	case BUS_NOTIFY_BOUND_DRIVER:
		if (!of_property_match_string(client->dev.of_node, "device-type", "touchpad")) {
			touchpad_device_online(client);
			pr_info("touchpad online\n");
		}
		break;
	case BUS_NOTIFY_UNBOUND_DRIVER:
		if (!of_property_match_string(client->dev.of_node, "device-type", "touchpad")) {
			touchpad_device_offline(client);
			pr_info("touchpad offline\n");
		}
		break;
	default:
		break;
	}

	return 0;
}

static struct notifier_block touchpad_i2cdev_notifier = {
	.notifier_call = touchpad_i2cdev_notifier_call,
};

static int touchpad_pm_notify(struct notifier_block *nb, unsigned long mode, void *dummy)
{
	if (!g_touchpad_data || !g_touchpad_data->client)
		return 0;
	(void)dummy;

	pr_info("%s mode: %d, wakeup_source: %d, is_ulsr: %d\n", __func__, mode, g_touchpad_data->wakeup_source, is_ulsr());
	if (mode == PM_SUSPEND_PREPARE && g_touchpad_data->wakeup_source && !is_ulsr()) /* suspend with no ulsr */
		device_init_wakeup(&g_touchpad_data->client->dev, true);
	else
		device_init_wakeup(&g_touchpad_data->client->dev, false);

	return 0;
}

static int regulator_bulk_enable_sync(int num_consumers, struct regulator_bulk_data *consumers, const int *volts)
{
	int i;
	int ret;
    int volt;

	if (consumers == NULL || volts == NULL)
		return -EINVAL;

	for (i = 0; i < num_consumers; i++) {
        volt = regulator_get_voltage(consumers[i].consumer);
        pr_info("old touchpad voltage %s: %d\n", consumers[i].supply, volt);
        if (volts[i] > 0 && volt > 0 && volts[i] != volt) {
            ret = regulator_set_voltage(consumers[i].consumer, volts[i], volts[i]);
            pr_info("set touchpad %s voltage:%d, ret: %d\n", consumers[i].supply, volts[i], ret);
            if (ret != 0) {
                pr_err("Failed to set touchpad voltage %s: %d\n", consumers[i].supply, ret);
                goto err;
            }
		}
		volt = regulator_get_voltage(consumers[i].consumer);
		if (is_ulsr() && volts[i] > 0 && volt > 0 && volt != volts[i]) {
			pr_info("set touchpad voltage %s failed, reset %d to volt:%d\n", consumers[i].supply, volt, volts[i]);
			ret = regulator_sync_voltage(consumers[i].consumer);
			if (ret != 0) {
				pr_err("Failed to sync touchpad voltage %s: %d\n", consumers[i].supply, ret);
				goto err;
			}
		}
		volt = regulator_get_voltage(consumers[i].consumer);
		pr_info("new touchpad voltage %s: %d\n", consumers[i].supply, volt);
        ret = regulator_enable(consumers[i].consumer);
        if (ret) {
            pr_err("Failed to enable %s: %d\n", consumers[i].supply, ret);
            goto err;
        }
    }

    return 0;

err:
	for (i = i - 1; i >= 0; i--) {
		regulator_disable(consumers[i].consumer);
	}

	return ret;
}

static struct platform_device huawei_touchpad = {
	.name = "huawei_touchpad",
	.id = -1,
};

static ssize_t touchpad_version_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct fw_version mcu_ver = {0};

	if (!dev || !attr || !buf || !g_touchpad_data || !g_touchpad_data->client) {
		pr_err("touchpad version attribute, invalid value\n");
		return 0;
	}

	struct device *touchpad_dev = bus_find_device(&hid_bus_type, NULL, g_touchpad_data->client, hid_dev_match);
	if (!touchpad_dev) {
		pr_err("touchpad version attribute, no touchpad device\n");
		return 0;
	}

	struct hid_device *touchpad_hdev = to_hid_device(touchpad_dev);
	if (!touchpad_hdev) {
		pr_err("touchpad version attribute, touchpad hid device error\n");
		return 0;
	}

	if (touchpad_get_mcu_fw_version(touchpad_hdev, &mcu_ver)) {
		pr_err("touchpad version attribute, mcu not ready\n");
		return 0;
	}
	/* 4 bits to describe touchpad version */
	return snprintf_s(buf, VERSION_MAX_LEN, VERSION_MAX_LEN - 1, "touchpad version:%d.%d.%d.%d",
		mcu_ver.version[0], mcu_ver.version[1], mcu_ver.version[2], mcu_ver.version[3]);
}

static ssize_t touchpad_trigger_update(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	if (!dev || !attr || !buf) {
		pr_err("touchpad trigger update attribute, invalid value\n");
		return 0;
	}
	if (!strcmp(buf, "trigger update")) {
		pr_err("touchpad update triggered, update start");
		touchpad_fw_update(NULL);
	}
	return 0;
}

static struct device_attribute touchpad_version_attr = __ATTR(touchpad_version,
	S_IRUGO, touchpad_version_show, NULL);

static struct device_attribute touchpad_updater_attr = __ATTR(updater_tag,
	0660, NULL, touchpad_trigger_update);

static void touchpad_register_tp_device()
{
	int ret;

	ret = platform_device_register(&huawei_touchpad);
	if (ret < 0) {
		pr_err("touchpad, register touchpad device error: %d\n", ret);
		return;
	}
	ret = device_create_file(&huawei_touchpad.dev, &touchpad_version_attr);
	if (ret) {
		pr_err("touchpad, Unable to create touchpad_version_attr interface: %d\n", ret);
	}
	ret = device_create_file(&huawei_touchpad.dev, &touchpad_updater_attr);
	if (ret) {
		pr_err("touchpad, Unable to create touchpad_updater_attr interface: %d\n", ret);
	}
}

static int touchpad_probe(struct platform_device *pdev)
{
	int ret;
	struct touchpad_data *pdata = NULL;
	if(pdev == NULL) {
		pr_err("pdev is NULL\n");
		return -EINVAL;
	}

	pdata = devm_kzalloc(&pdev->dev, sizeof(struct touchpad_data), GFP_KERNEL);
	if (pdata == NULL) {
		pr_err("failed to allocate mem for touchpad\n");
		return -ENOMEM;
	}

	touchpad_parse_dts(pdev->dev.of_node, pdata);
	platform_set_drvdata(pdev, pdata);

	pdata->supplies[0].supply = "vdd";
	pdata->supplies[1].supply = "vddl";
	ret = devm_regulator_bulk_get(&pdev->dev, ARRAY_SIZE(pdata->supplies), pdata->supplies);
	if (ret) {
		pr_err("query regulator failed, ret: %d\n", ret);
		devm_kfree(&pdev->dev, pdata);
		return ret;
	}

	if (gpio_is_valid(pdata->reset_gpio)) {
		gpio_request(pdata->reset_gpio, "touchpad_rest");
		gpio_direction_output(pdata->reset_gpio, !pdata->reset_gpio_status);
	}

	ret = regulator_bulk_enable_sync(ARRAY_SIZE(pdata->supplies), pdata->supplies, pdata->regulator_volt);
	if (ret) {
		pr_err("enable regulator failed, ret: %d\n", ret);
		devm_kfree(&pdev->dev, pdata);
		return ret;
	}

	if (pdata->post_power_delay_ms)
		mdelay(pdata->post_power_delay_ms);

	if (gpio_is_valid(pdata->reset_gpio)) {
		gpio_set_value(pdata->reset_gpio, pdata->reset_gpio_status);
	}

	if (gpio_is_valid(pdata->shut_gpio)) {
		gpio_request(pdata->shut_gpio, "touchpad_shut");
		gpio_direction_output(pdata->shut_gpio, 0);
	}

	pdata->client = NULL;
	g_touchpad_data = pdata;

	ret = bus_register_notifier(&i2c_bus_type, &touchpad_i2cdev_notifier);
	if (ret)
		pr_err("failed to register bus notifier\n");
	
	pm_notifier(touchpad_pm_notify, TOUCHPAD_SR_NOTIFIER_PRIORITY);
	touchpad_register_tp_device();
	return 0;
}

static int touchpad_remove(struct platform_device *pdev)
{
	int ret;
	struct touchpad_data *pdata = platform_get_drvdata(pdev);

	if (pdata == NULL)
		return 0;

	if (gpio_is_valid(pdata->shut_gpio)) {
		gpio_free(pdata->shut_gpio);
	}

	if (gpio_is_valid(pdata->reset_gpio)) {
		gpio_set_value(pdata->reset_gpio, !pdata->reset_gpio_status);
		gpio_free(pdata->reset_gpio);
	}

	if (pdata->post_power_delay_ms)
		mdelay(pdata->post_power_delay_ms);

	ret = regulator_bulk_disable(ARRAY_SIZE(pdata->supplies), pdata->supplies);
	if (ret)
		pr_err("disable regulator failed when remove, ret: %d\n", ret);

	return ret;
}

#ifdef CONFIG_PM_SLEEP
static int touchpad_suspend(struct device *dev)
{
	int ret;
	struct platform_device *pdev = to_platform_device(dev);
	struct touchpad_data *pdata = platform_get_drvdata(pdev);

	if (!pdata || !pdata->client)
		return 0;

	if (device_may_wakeup(&pdata->client->dev)) {
		enable_irq(pdata->client->irq);
		return 0;
	}

	if (gpio_is_valid(pdata->reset_gpio))
		gpio_set_value(pdata->reset_gpio, !pdata->reset_gpio_status);

	if (pdata->post_power_delay_ms)
		mdelay(pdata->post_power_delay_ms);

	ret = regulator_bulk_disable(ARRAY_SIZE(pdata->supplies), pdata->supplies);
	if (ret)
		pr_err("disable regulator failed when suspend, ret: %d\n", ret);

    return ret;
}

static int touchpad_resume(struct device *dev)
{
	int ret;
	unsigned int irq_type = 0;
	struct platform_device *pdev = to_platform_device(dev);
	struct touchpad_data *pdata = platform_get_drvdata(pdev);

	if (!pdata || !pdata->client)
		return 0;

	if (device_may_wakeup(&pdata->client->dev)) {
		disable_irq(pdata->client->irq);
		return 0;
	}

	if (is_ulsr()) {
		irq_type = irq_get_trigger_type(pdata->client->irq);
		if (!irq_type)
			irq_type = IRQF_TRIGGER_LOW;

		pr_info("%s irq_type:%d", __func__, irq_type);
		irq_set_irq_type(pdata->client->irq, irq_type);
	}

	ret = regulator_bulk_enable_sync(ARRAY_SIZE(pdata->supplies), pdata->supplies, pdata->regulator_volt);
	if (ret) {
		pr_err("enable regulator failed when resume, ret: %d\n", ret);
		return ret;
	}

	if (pdata->post_power_delay_ms)
		mdelay(pdata->post_power_delay_ms);

	if (gpio_is_valid(pdata->reset_gpio))
		gpio_set_value(pdata->reset_gpio, pdata->reset_gpio_status);

	return 0;
}
#endif /* CONFIG_PM_SLEEP */

static struct of_device_id touchpad_match_table[] = {
	{ .compatible = "huawei,touchpad", },
	{},
};

static const struct dev_pm_ops touchpad_pm = {
	SET_SYSTEM_SLEEP_PM_OPS(touchpad_suspend, touchpad_resume)
};

static struct platform_driver touchpad_driver = {
	.probe        = touchpad_probe,
	.remove       = touchpad_remove,
	.driver       = {
		.name           = "huawei,touchpad",
		.owner          = THIS_MODULE,
		.pm				= &touchpad_pm,
		.of_match_table = of_match_ptr(touchpad_match_table),
	},
};

int __init touchpad_init(void)
{
	return platform_driver_register(&touchpad_driver);
}

void __exit touchpad_exit(void)
{
	platform_driver_unregister(&touchpad_driver);
}

rootfs_initcall(touchpad_init);
module_exit(touchpad_exit);

MODULE_AUTHOR("Huawei Technologies Co., Ltd");
MODULE_DESCRIPTION("touchpad module driver");
MODULE_LICENSE("GPL");
