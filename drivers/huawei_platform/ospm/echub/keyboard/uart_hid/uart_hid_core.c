/*
 * Huawei uart hid Driver for device control
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
#include <linux/string.h>
#include <linux/list.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/wait.h>
#include <linux/mutex.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/pm.h>
#include <linux/device.h>
#include <linux/jiffies.h>
#include <linux/hid.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/termios.h>
#include <securec.h>
#include <platform_include/cee/linux/ulsr.h>

#include "uart_hid_uart_protocol.h"
#include "uart_hid_report.h"
#include "uart_hid_uart_cmd.h"
#include "uart_hid_log.h"
#include "uart_hid_core.h"

static int g_irq_num = 0;
static struct timespec64 g_irq_ts = {0};
int uart_hid_get_irq_num(void)
{
	return g_irq_num;
}
struct timespec64 uart_hid_get_irq_ts(void)
{
	return g_irq_ts;
}
/* debug option */
static bool uart_hid_debug_flag = false;
bool uart_hid_debug_log_flag(void)
{
	return uart_hid_debug_flag;
}
module_param(uart_hid_debug_flag, bool, 0400);
MODULE_PARM_DESC(uart_hid_debug_flag, "print a lot of debug information");

static int uart_hid_recv_buf(u8 *in_buf, int len)
{
	int ret;
	size_t len_out;

	if (!in_buf)
		return -EINVAL;

	ret = uart_hid_cmd_recv_report(in_buf, len, &len_out);
	if (ret < 0)
		return ret;

	return 0;
}

int uart_hid_send_buf(struct uart_hid *ihid, u8 *out_buf, int args_len)
{
	int ret;

	if (!ihid || !out_buf)
		return -EINVAL;

	set_bit(UART_HID_WRITE_PENDING, &ihid->flags);
	ret = uart_hid_cmd_send_report(out_buf, (size_t)args_len);
	clear_bit(UART_HID_WRITE_PENDING, &ihid->flags);
	return ret;
}

#define HID_MAX_RESUM_WAIT_TIME 300
void uart_hid_read_work(struct work_struct *work)
{
	struct uart_hid *ihid = NULL;
	int size;
	int ret;
	int cnt = 0;

	if (!work)
		return;

	ihid = (struct uart_hid *)container_of(work,
			struct uart_hid, read_work.work);
	if (!ihid)
		return;
	size = le16_to_cpu(ihid->hdesc.max_input_length);
	if (size > ihid->buf_size)
		size = ihid->buf_size;

	if (test_bit(UART_HID_READ_SCHEDULE, &ihid->flags)) {
		while (test_bit(UART_HID_SUSPEND, &ihid->flags)
			&& cnt++ < HID_MAX_RESUM_WAIT_TIME)
			msleep(1);

		if (cnt == HID_MAX_RESUM_WAIT_TIME) {
			uart_hid_err("resum wait time = %d\n", cnt);
			goto exit_irq_process;
		}

		/* avoid uart resum wake up after the uart hid */
		msleep(10); // 10ms
	}

	ret = uart_hid_recv_buf(ihid->input_buf, size);
	if (ret < 0) {
		uart_hid_err("got %d data instead of %d\n", ret, size);
		goto exit_irq_process;
	}
	uart_hid_input_report(ihid);
exit_irq_process:
	__pm_relax(ihid->wake);
	enable_irq(ihid->irq);
	clear_bit(UART_HID_READ_SCHEDULE, &ihid->flags);
}

static irqreturn_t uart_hid_irq(int irq, void *dev_id)
{
	struct uart_hid *ihid = NULL;

	if (!dev_id)
		return IRQ_NONE;

	ihid = dev_id;
	disable_irq_nosync(ihid->irq);
	g_irq_num++;
	uart_hid_get_timeofday(&g_irq_ts);

	__pm_stay_awake(ihid->wake);
	if (!test_bit(UART_HID_SUSPEND, &ihid->flags)) {
		queue_delayed_work(system_power_efficient_wq, &ihid->read_work, 0);
	} else {
		__pm_relax(ihid->wake);
		enable_irq(ihid->irq);
		clear_bit(UART_HID_READ_SCHEDULE, &ihid->flags);
	}

	return IRQ_HANDLED;
}

static void init_gpio_to_ec(struct platform_device *pdev, int gpio)
{
	int ret = 0;

	if (!gpio_is_valid(gpio)) {
		uart_hid_err("gpio to ec invalid\n");
		return;
	}

	ret = devm_gpio_request(&pdev->dev, gpio, "uart_hid_response_ec_gpio");
	if (ret < 0) {
		uart_hid_err("soc to ec gpio request gpio fail\n");
		return;
	}

	ret = gpio_direction_output(gpio, 0);
	if (ret < 0) {
		uart_hid_err("soc to ec gpio direction output fail\n");
		return;
	}
}

static int uart_hid_init_irq(struct uart_hid *ihid)
{
	int ret;

	if (!ihid)
		return -ENODEV;

	uart_hid_dbg("Requesting IRQ: %d\n", ihid->pdata.irq_gpio);

	ret = gpio_request((unsigned int)ihid->pdata.irq_gpio, "uart_hid_irq");
	if (ret < 0) {
		uart_hid_err("Requesting gpio: %d,ret = %d\n",
			     ihid->pdata.irq_gpio, ret);
		return ret;
	}
	ihid->irq = gpio_to_irq(ihid->pdata.irq_gpio);
	if (ihid->irq < 0) {
		uart_hid_err("gpio_to_irq: %d,ret = %d\n", ihid->pdata.irq_gpio, ihid->irq);
        return -EFAULT;
	}
	uart_hid_err("Requesting gpio: %d,ihid->irq = %d\n",
			     ihid->pdata.irq_gpio, ihid->irq);
	ret = request_threaded_irq(ihid->irq, NULL, uart_hid_irq,
			IRQF_NO_SUSPEND | IRQF_TRIGGER_LOW |
			IRQF_ONESHOT,
			ihid->pdev->name, ihid);
	if (ret < 0) {
		uart_hid_err("Could not register for %s interrupt, irq = %d,"
			" ret = %d\n",
			ihid->pdev->name, ihid->irq, ret);
		return ret;
	}

	return 0;
}

#ifdef CONFIG_OF
static int uart_hid_of_dts_parse(struct platform_device *pdev,
			     struct uart_hid_platform_data *pdata)
{
	struct device_node *of_node = NULL;
	u32 addr = 0, baud = 0, delay = 0;
	int ret, gpio;
	const char *tty_name = NULL;

	if (!pdev || !pdata || !pdev->dev.of_node)
		return -ENODEV;

	of_node = pdev->dev.of_node;
	ret = of_property_read_u32(of_node, "hid-descr-addr", &addr);
	if (ret || (addr >> SHIFT_OFFSET_2_BYTE)) {
		uart_hid_err("addr error ret = %d, add =%d\n", ret, addr);
		return -EINVAL;
	}
	gpio = of_get_named_gpio(of_node, "dev_irq", 0);
	if (!gpio_is_valid(gpio)) {
		uart_hid_err("dev_irq gpio: is invalid \n");
		return -EINVAL;
	}
	ret = of_property_read_string(of_node, "tty_name", &tty_name);
	if (ret) {
		uart_hid_err("tty_name dts error\n");
		return -EINVAL;
	}
	ret = of_property_read_u32(of_node, "tty_baud", &baud);
	if (ret) {
		uart_hid_err("baud dts error\n");
		return -EINVAL;
	}
	ret = of_property_read_u32(of_node, "post-power-on-delay-ms", &delay);
	if (ret) {
		uart_hid_err("post-power-on-delay-ms dts error\n");
		return -EINVAL;
	}

	pdata->response_ec_gpio = of_get_named_gpio(of_node, "response_ec_gpio", 0);
	pdata->hid_descriptor_address = addr;
	pdata->irq_gpio = gpio;
	pdata->tty_name = tty_name;
	pdata->tty_baud = baud;
	pdata->post_power_delay_ms = delay;

	pdata->supplies[0].supply = "vdd";
	pdata->supplies[1].supply = "vddl";

	ret = devm_regulator_bulk_get(&pdev->dev, ARRAY_SIZE(pdata->supplies),
			pdata->supplies);
	if (ret) {
		uart_hid_err("devm_regulator_bulk_get error ret=%d\n", ret);
		return ret;
	}

	return 0;
}

static const struct of_device_id uart_hid_of_match[] = {
	{ .compatible = "hid-over-uart" },
	{},
};
MODULE_DEVICE_TABLE(of, uart_hid_of_match);
#else
static inline int uart_hid_of_dts_parse(struct platform_device *pdev,
		struct uart_hid_platform_data *pdata)
{
	return -ENODEV;
}
#endif /* CONFIG_OF */

static int uart_hid_dev_init_check(struct uart_hid *ihid)
{
	int ret;
	int retry = 0;

	if (!ihid)
		return -ENODEV;

	ret = uart_hid_cmd_init(ihid->pdata.tty_name, ihid->pdata.tty_baud);
	if (ret < 0) {
		uart_hid_err("uart hid uart_hid_cmd_init error ret=%d\n", ret);
		return ret;
	}

	ret = uart_hid_dev_check();
	if (ret < 0) {
		for (retry = 0; retry < UART_DEV_CHECK_RETRY_NUM; retry++) {
			ret = uart_hid_dev_check();
			uart_hid_err("uart hid uart_hid_dev_check error retry num=%d\n", retry);
			if (ret == 0) {
				break;
			}
			msleep(UART_DEV_CHECK_DELAY_TIME); /*30ms*/
		}
	}
	if (ret < 0) {
		uart_hid_err("uart hid uart_hid_dev_check error ret=%d\n", ret);
		goto err_cmd_init;
	}
	response_ack_to_ec(ihid->pdata.response_ec_gpio);

	ret = uart_hid_init_irq(ihid);
	if (ret < 0)
		goto err_cmd_init;

	return 0;

err_cmd_init:
	uart_hid_cmd_deinit();
	uart_hid_err("error\n");
	return ret;
}

static int uart_hid_add_device(struct uart_hid *ihid)
{
	int ret;
	struct hid_device *hid = NULL;

	if (!ihid || !ihid->pdev)
		return -ENODEV;
	
	ret = uart_hid_fetch_hid_descriptor(ihid);
	if (ret < 0)
		return ret;

	hid = hid_allocate_device();
	if (IS_ERR(hid)) {
		ret = PTR_ERR(hid);
		return ret;
	}

	ihid->hid = hid;
	hid->driver_data = ihid;
	hid->ll_driver = get_uart_hid_ll_driver();
	hid->dev.parent = &ihid->pdev->dev;
	hid->bus = BUS_RS232;
	hid->version = le16_to_cpu(ihid->hdesc.bcd_version);
	hid->vendor = le16_to_cpu(ihid->hdesc.vendor_id);
	hid->product = le16_to_cpu(ihid->hdesc.product_id);

	ret = snprintf_s(hid->name, sizeof(hid->name), sizeof(hid->name) - 1,
		"%s %04X:%04X", ihid->pdev->name, (u16)hid->vendor,
		(u16)hid->product);
	if (ret < 0)
		goto err_mem_free;

	strlcpy(hid->phys, dev_name(&ihid->pdev->dev), sizeof(hid->phys));

	ret = hid_add_device(hid);
	if (ret) {
		if (ret != -ENODEV)
			uart_hid_err("can't add hid device: %d\n", ret);
		goto err_mem_free;
	}
	return ret;

err_mem_free:
	hid_destroy_device(hid);
	uart_hid_err("error\n");
	return ret;
}

static void uart_hid_notify_work(struct work_struct *work)
{
	int cnt = 0;
	struct uart_hid *ihid = NULL;

	if (!work)
		return;

	ihid = (struct uart_hid *)container_of(work,
			struct uart_hid, read_work.work);
	if (!ihid)
		return;

	__pm_stay_awake(ihid->wake);
	/* wait for uart and tty ready */
	while (!uart_hid_uart_is_ready() && (cnt++ < UART_READY_LAST_WATING_TIME))
			msleep(1);
	/* send cmd to ec */
	if (uart_hid_dev_ready() < 0)
		uart_hid_err("dev ready notify EC fail\n");
	__pm_relax(ihid->wake);
}

static int uart_ihid_init(struct platform_device *pdev,
		struct uart_hid *ihid)
{
	__u16 hid_register;
	int ret = 0;

	if (!pdev || !ihid)
		return -ENODEV;

	ret = uart_hid_of_dts_parse(pdev, &ihid->pdata);
	if (ret < 0) {
		uart_hid_err("uart_hid_of_probe error \n");
		return ret;
	}
	init_gpio_to_ec(pdev, ihid->pdata.response_ec_gpio);

	ihid->pdev = pdev;
	hid_register = ihid->pdata.hid_descriptor_address;
	ihid->hid_desc_reg = cpu_to_le16(hid_register);
	mutex_init(&ihid->send_lock);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	ihid->wake = wakeup_source_register(NULL, "uart_hid");
#else
	ihid->wake = wakeup_source_register("uart_hid");
#endif
	ihid->flags = 0;
	INIT_DELAYED_WORK(&ihid->read_work, uart_hid_read_work);
	INIT_WORK(&ihid->notify_work, uart_hid_notify_work);

	return ret;
}

static int uart_hid_probe(struct platform_device *pdev)
{
	int ret;
	struct uart_hid *ihid = NULL;

	if (!pdev)
		return -ENODEV;

	uart_hid_err("enter\n");
	ihid = devm_kzalloc(&pdev->dev, sizeof(*ihid), GFP_KERNEL);
	if (!ihid)
		return -ENOMEM;

	platform_set_drvdata(pdev, ihid);

	ret = uart_ihid_init(pdev, ihid);
	if (ret < 0)
		goto err_ihid_init;

	ret = regulator_bulk_enable(ARRAY_SIZE(ihid->pdata.supplies),
			ihid->pdata.supplies);
	if (ret < 0) {
		uart_hid_err("regulator_bulk_enable error ret=%d\n", ret);
		goto err_ihid_init;
	}

	device_enable_async_suspend(&pdev->dev);

	ret = uart_hid_dev_init_check(ihid);
	if (ret < 0)
		goto err_regulator;

	ret = uart_hid_add_device(ihid);
	if (ret < 0)
		goto err_dev_init_check;

	enable_irq_wake(ihid->irq);

	uart_hid_err("success\n");
	return 0;

err_dev_init_check:
	free_irq(ihid->irq, ihid);
	uart_hid_cmd_deinit();
err_regulator:
	regulator_bulk_disable(ARRAY_SIZE(ihid->pdata.supplies),
		ihid->pdata.supplies);
err_ihid_init:
	platform_set_drvdata(pdev, NULL);
	uart_hid_err("error\n");
	return ret;
}

static int uart_hid_remove(struct platform_device *pdev)
{
	struct uart_hid *ihid = NULL;
	struct hid_device *hid = NULL;

	if (!pdev)
		return -ENODEV;
	ihid = platform_get_drvdata(pdev);
	if (!ihid || !ihid->hid)
		return -ENODEV;
	hid = ihid->hid;
	cancel_delayed_work(&ihid->read_work);

	hid_destroy_device(hid);

	free_irq(ihid->irq, ihid);

	uart_hid_cmd_deinit();

	regulator_bulk_disable(ARRAY_SIZE(ihid->pdata.supplies),
			ihid->pdata.supplies);

	platform_set_drvdata(pdev, NULL);

	return 0;
}

static void uart_hid_shutdown(struct platform_device *pdev)
{
	struct uart_hid *ihid = NULL;

	if (!pdev)
		return;

	ihid = platform_get_drvdata(pdev);
	if (!ihid)
		return;
	free_irq(ihid->irq, ihid);
}

#ifdef CONFIG_PM_SLEEP
static int uart_hid_suspend(struct device *dev)
{
	struct platform_device *pdev = NULL;
	struct uart_hid *ihid = NULL;
	struct hid_device *hid = NULL;
	int ret;
	int cnt = 0;

	if (!dev)
		return -ENODEV;
	pdev = to_platform_device(dev);
	if (!pdev)
		return -ENODEV;
	ihid = platform_get_drvdata(pdev);
	if (!ihid || !ihid->hid)
		return -ENODEV;
	hid = ihid->hid;

	set_bit(UART_HID_SUSPEND, &ihid->flags);
	cancel_delayed_work_sync(&ihid->read_work);
	cancel_work_sync(&ihid->notify_work);
	if (hid->driver && hid->driver->suspend) {
		ret = hid->driver->suspend(hid, PMSG_SUSPEND);
		if (ret < 0)
			return ret;
	}
	/* just delay 5ms to let hid led control send */
	mdelay(5);

	while (test_bit(UART_HID_WRITE_PENDING, &ihid->flags)
		&& cnt++ < UART_WRITE_TIMEOUT)
		mdelay(1);
	if (cnt == UART_WRITE_TIMEOUT)
		uart_hid_err("suspend wait time = %d\n", cnt);
	/* The keyboard needs to wake up system,
	* so cannot disable its irq in S3. */
	enable_irq(ihid->irq);

	return 0;
}

static int uart_hid_resume(struct device *dev)
{
	int ret = 0;
	int cnt = 0;
	struct platform_device *pdev = NULL;
	struct uart_hid *ihid = NULL;
	struct hid_device *hid = NULL;

	if (!dev)
		return -ENODEV;
	pdev = to_platform_device(dev);
	if (!pdev)
		return -ENODEV;
	ihid = platform_get_drvdata(pdev);
	if (!ihid || !ihid->hid)
		return -ENODEV;
	hid = ihid->hid;

	if (!test_bit(UART_HID_READ_SCHEDULE, &ihid->flags)) {
		disable_irq(ihid->irq);
		enable_irq(ihid->irq);
	} else {
		/* wait for uart ready */
		while (!uart_hid_uart_is_ready() && (cnt++ < UART_READY_LAST_WATING_TIME))
			msleep(1);
	}

	if (is_ulsr()) {
		ret = uart_hid_init_irq(ihid);
		if (ret < 0) {
			/*
			 * after ulsr, if uart_hid_init_irq return error, this means that the IRQ state initialized
			 * during probe remains valid and is not an error that requires exception handling. 
			 */
			uart_hid_err("after ulsr,uart_hid_init_irq repeately,ret = %d\n", ret);
		}
	}

	if (gpio_is_valid(ihid->pdata.response_ec_gpio))
		gpio_direction_output(ihid->pdata.response_ec_gpio, 0);

	if (hid->driver && hid->driver->reset_resume) {
		ret = hid->driver->reset_resume(hid);
	}

	schedule_work(&ihid->notify_work);
	clear_bit(UART_HID_SUSPEND, &ihid->flags);
	return ret;
}
#endif

static const struct dev_pm_ops uart_hid_pm = { SET_SYSTEM_SLEEP_PM_OPS(
	uart_hid_suspend, uart_hid_resume) };

static const struct platform_device_id uart_hid_id_table[] = {
	{ "hid", 0 },
	{ "hid-over-uart", 0 },
	{},
};
MODULE_DEVICE_TABLE(platform, uart_hid_id_table);

static struct platform_driver uart_hid_driver = {
	.driver = {
		.name = "uart_hid",
		.pm = &uart_hid_pm,
		.of_match_table = of_match_ptr(uart_hid_of_match),
	},

	.probe = uart_hid_probe,
	.remove = uart_hid_remove,
	.shutdown = uart_hid_shutdown,
	.id_table = uart_hid_id_table,
};

static int __init uart_hid_init(void)
{
	printk("uart_hid_init init\n");
	return platform_driver_register(&uart_hid_driver);
}

static void __exit uart_hid_exit(void)
{
	printk("uart_hid_exit exit\n");
	platform_driver_unregister(&uart_hid_driver);
}

module_init(uart_hid_init);
module_exit(uart_hid_exit);

MODULE_DESCRIPTION("HID over UART core driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
MODULE_LICENSE("GPL v2");
