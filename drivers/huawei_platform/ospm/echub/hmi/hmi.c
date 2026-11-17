/*
 * hmi.c
 *
 * hmi driver for echub
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
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/init.h>
#include <linux/notifier.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <asm/irq.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/suspend.h>
#include <platform_include/cee/linux/ulsr.h>
#include "hmi_private.h"
#include "hmi.h"


#define MAX_INPUT_BUF_LEN 64
#define MAX_OUTPUT_BUF_LEN 256
struct hmi_transfer_data {
	int cmd_index;
	u8  data_buf[MAX_INPUT_BUF_LEN];
	int data_len;
	u8  rev_buf[MAX_OUTPUT_BUF_LEN];
	int rev_buf_len;
};

#define HMI_IOC_MAGIC 'h'
#define HMI_IOC_TRANSFER _IOWR(HMI_IOC_MAGIC, 0, struct hmi_transfer_data)

struct hmi_dev *g_hmi_dev = NULL;
static int g_hmi_major;
static struct class *g_hmi_class;

static long hmi_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	long ret;
	struct hmi_transfer_data data;

	if (!file)
		return -EINVAL;

	switch (cmd) {
	case HMI_IOC_TRANSFER:
		echub_info("hmi_ioctl func transfer.\r\n");
		if (copy_from_user(&data, (struct hmi_transfer_data __user *) arg, sizeof(struct hmi_transfer_data))) {
			echub_err("hmi_transfer ioctl get data from user error.\r\n");
			ret = -EFAULT;
			break;
		}
		ret = hmi_transfer(data.cmd_index, data.data_buf, data.data_len, data.rev_buf, data.rev_buf_len);
		if (ret != 0) {
			echub_err("hmi_transfer ioctl data execter error.\r\n");
			break;
		}
		if (copy_to_user((struct hmi_transfer_data __user *) arg, &data, sizeof(struct hmi_transfer_data))) {
			ret = -EFAULT;
			break;
		}
		echub_info("hmi_transfer ioctl func success.\r\n");
		break;
	default:
		ret = -EOPNOTSUPP;
		break;
	}

	return ret;
}

static struct file_operations g_hmi_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = hmi_ioctl,
	/* add fops used in user space */
};

static int check_pare_invalid(int cmd_index, u8 *data_buf, int data_len, u8 *rev_buf, int rev_buf_len)
{
	if ((cmd_index >= HMI_CMD_END) || (cmd_index < 0))
		return -EINVAL;
	if (g_hmi_ec_cmd_table[cmd_index].rev_len > rev_buf_len)
		return -EINVAL;
	if (g_hmi_ec_cmd_table[cmd_index].rev_len != 0 && rev_buf == NULL)
		return -EINVAL;
	if (g_hmi_ec_cmd_table[cmd_index].input_para_len != 0 && g_hmi_ec_cmd_table[cmd_index].input_para_len > data_len)
		return -EINVAL;
	if (g_hmi_ec_cmd_table[cmd_index].input_para_len != 0 && data_buf == NULL)
		return -EINVAL;
	return 0;
}

static void prepare_send_buf(u8 *send_buf, int cmd_index, u8 *data_buf)
{
	int i;

	send_buf[0] = g_hmi_ec_cmd_table[cmd_index].sub_cmd;
	if ((g_hmi_ec_cmd_table[cmd_index].input_para_len == 0) || \
		(g_hmi_ec_cmd_table[cmd_index].input_para_len > (MAX_INPUT_BUF_LEN - 1)))
		return;
	for (i = 0; i < g_hmi_ec_cmd_table[cmd_index].input_para_len; i++)
		send_buf[i + 1] = data_buf[i];
}

int hmi_transfer(int cmd_index, u8 *data_buf, int data_len, u8 *rev_buf, int rev_buf_len)
{
	int ret;
	int cmd;
	int rev_len;
	int send_len;
	u8 send_buf[MAX_INPUT_BUF_LEN] = {0};
	 
	if (g_hmi_dev == NULL || g_hmi_dev->echub == NULL)
		return -EOPNOTSUPP;
	if (check_pare_invalid(cmd_index, data_buf, data_len, rev_buf, rev_buf_len) != 0) {
		echub_err("Input parameter is invalid!\r\n");
		return -EINVAL;
	}
	echub_info("hmi_transfer_func start:%d\n", cmd_index);
	mutex_lock(&g_hmi_dev->lock);
	cmd = g_hmi_ec_cmd_table[cmd_index].cmd;
	rev_len = g_hmi_ec_cmd_table[cmd_index].rev_len;
	if (g_hmi_ec_cmd_table[cmd_index].sub_cmd == 0xFF) { /* 0xFF means no need sendbuf */
		ret = g_hmi_dev->echub->transfer_func(g_hmi_dev->echub, cmd, NULL, 0, rev_buf, rev_len);
	} else {
		send_len = g_hmi_ec_cmd_table[cmd_index].input_para_len + 1;
		prepare_send_buf(send_buf, cmd_index, data_buf);
		ret = g_hmi_dev->echub->transfer_func(g_hmi_dev->echub, cmd, send_buf, send_len, rev_buf, rev_len);
	}
	mutex_unlock(&g_hmi_dev->lock);
	return ret;
}

struct hmi_dev *get_hmi_dev(void)
{
	return g_hmi_dev;
}

static void parse_dts(struct platform_device *pdev, struct hmi_dev *echmi)
{
	int array_len;
	u32 *qevent_map_buf;
	int i;
	int ret;

	echmi->gpio_irq_wakeup = of_property_read_bool(pdev->dev.of_node, "gpio_irq_wakeup");

	array_len = of_property_count_u32_elems(pdev->dev.of_node, "qid_nid_map");
	if (array_len == 0) {
		echub_err("echmi parse_dts qid_nid_map len is 0.\r\n");
		return;
	}

	qevent_map_buf = kzalloc(array_len * sizeof(u32), GFP_KERNEL);
	if (qevent_map_buf == NULL) {
		echub_err("echmi parse_dts kzalloc fail.\n");
		return;
	}
	ret = of_property_read_u32_array(pdev->dev.of_node, "qid_nid_map", qevent_map_buf, array_len);
	if (ret != 0) {
		echub_err("echmi parse_dts qid_nid_map error.\r\n");
		kfree(qevent_map_buf);
		qevent_map_buf = NULL;
		return;
	}

	for (i = 0; (i + 1) < array_len;) {
		if (qevent_map_buf[i + 1] <= 0xFF) { /* Qevent id max is 0xFF */
			echmi->qid_nid_map[qevent_map_buf[i + 1]] = (u8)qevent_map_buf[i];
		} else {
			echub_err("echmi parse_dts qevent_map_buf index %d invalid.\n", i);
		}
		i += 2; /* 2:byte0 type byte1 eventid */
	}

	kfree(qevent_map_buf);
	qevent_map_buf = NULL;
}

static void init_echmi_data(struct platform_device *pdev, struct hmi_dev *echmi)
{
	int i;
	int map_len = sizeof(g_qevent_notify_map) / sizeof(struct hmi_qevent_notify_table);
	for (i = 0; i < map_len; i++) {
		echmi->qid_nid_map[g_qevent_notify_map[i].qevent_number] = g_qevent_notify_map[i].event_type;
	}
	parse_dts(pdev, echmi);
}

static int hmi_qevent_hibernate_callback(struct notifier_block *nb, unsigned long event, void *ptr)
{
	struct hmi_dev *di = g_hmi_dev;

	if (!di) {
		echub_err("hmi hibernate nb callback error!");
		return NOTIFY_BAD;
	}

	switch (event) {
	case PM_HIBERNATION_PREPARE:
		disable_irq(di->qevent_irq);
		break;
	case PM_POST_HIBERNATION:
		enable_irq(di->qevent_irq);
		break;
	default:
		break;
	}
	echub_info("hmi receive hibernate event %d", event);
    return NOTIFY_OK;
}

/**********************************************************
 *  Function:		hw_hmi_probe
 *  Discription:	module probe
 *  Parameters:	 pdev:platform_device
 *  return value:	0-sucess or others-fail
 **********************************************************/
static int hw_hmi_probe(struct platform_device *pdev)
{
	struct echub_i2c_dev *echub_dev = NULL;
	struct hmi_dev *echmi = NULL;
	int err;

	echub_info("armpc hmi driver probes start!\n");
	if (!pdev || !pdev->dev.parent) {
		echub_err("pdev is NULL\n");
		return -ENODEV;
	}
	echub_dev = dev_get_drvdata(pdev->dev.parent);
	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}
	echmi = devm_kzalloc(&pdev->dev, sizeof(struct hmi_dev), GFP_KERNEL);
	if (echmi == NULL) {
		echub_err("Failed to allocate struct hmi!\n");
		return -ENOMEM;
	}

	echmi->dev = &pdev->dev;
	echmi->echub = echub_dev;
	mutex_init(&echmi->lock);
	init_echmi_data(pdev, echmi);
	g_hmi_dev = echmi;
	hmi_init_qevent(pdev, echmi);

	echmi->hibernate_nb.notifier_call = hmi_qevent_hibernate_callback;
	register_pm_notifier(&echmi->hibernate_nb);
	platform_set_drvdata(pdev, echmi);

	/*
	 * Create a char device named hmi_virt_fs with hmp_fops
	 * /dev/hmi_virt_fs
	 */
	g_hmi_major = register_chrdev(0, "hmi_virt_fs", &g_hmi_fops);
	if (g_hmi_major < 0) {
		echub_err("register hmi_virt_fs dev fail\n");
		return -ENODEV;
	}
	g_hmi_class = class_create(THIS_MODULE, "hmi_virt_fs");
	if (IS_ERR(g_hmi_class)) {
		echub_err("class_create hmi_virt_fs fail\n");
		err = -ENODEV;
		goto err_unregister_chrdev;
	}
	device_create(g_hmi_class, NULL, MKDEV(g_hmi_major, 0), NULL, "hmi_virt_fs");

	echub_info("armpc hmi driver probes successfully!\n");
	return 0;
err_unregister_chrdev:
    unregister_chrdev(g_hmi_major, "hmi_virt_fs");
    return err;
}

/**********************************************************
 *  Function:		hw_hmi_remove
 *  Discription:	module remove
 *  Parameters:	 pdev:platform_device
 *  return value:	0-sucess or others-fail
 **********************************************************/
static int hw_hmi_remove(struct platform_device *pdev)
{
	struct hmi_dev *echmi = NULL;

	if (!pdev) {
		echub_err("[%s:%dL] pdev is NULL\n", __func__, __LINE__);
		return -ENODEV;
	}
	echmi = platform_get_drvdata(pdev);
	if (echmi == NULL) {
		echub_err("get invalid gpio_key pointer\n");
		return -EINVAL;
	}

	unregister_pm_notifier(&echmi->hibernate_nb);

	free_irq(echmi->qevent_irq, echmi);
	gpio_free((unsigned int)echmi->qevent_gpio);

	platform_set_drvdata(pdev, NULL);
	cancel_delayed_work(&(echmi->get_event_work));

	device_destroy(g_hmi_class, MKDEV(g_hmi_major, 0));
	class_destroy(g_hmi_class);
	unregister_chrdev(g_hmi_major, "hmi_virt_fs");
	g_hmi_dev = NULL;

	return 0;
}

#ifdef CONFIG_PM
/**********************************************************
*  Function:       hw_hmi_suspend
*  Discription:    module suspend
*  Parameters:     pdev:platform_device pm_message_t state
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_hmi_suspend(struct platform_device *pdev, pm_message_t state)
{
	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is null\n", __func__, __LINE__);
		return -ENODEV;
	}
	struct hmi_dev *echmi = platform_get_drvdata(pdev);
	if (echmi == NULL) {
		echub_err("[%s:%dL] echmi is null\n", __func__, __LINE__);
		return -ENODEV;
	}
	if (is_ulsr()) {
		disable_irq(echmi->qevent_irq);
	}
	return 0;
}
 
/**********************************************************
*  Function:       hw_hmi_resume
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int hw_hmi_resume(struct platform_device *pdev)
{
	if (pdev == NULL) {
		echub_err("[%s:%dL] pdev is null\n", __func__, __LINE__);
		return -ENODEV;
	}
	struct hmi_dev *echmi = platform_get_drvdata(pdev);
	if (echmi == NULL) {
		echub_err("[%s:%dL] echmi is null\n", __func__, __LINE__);
		return -ENODEV;
	}
	if (is_ulsr()) {
		if (echmi->gpio_irq_wakeup) {
			irq_set_irq_type(echmi->qevent_irq, IRQF_NO_SUSPEND |IRQF_TRIGGER_FALLING);
		} else {
			irq_set_irq_type(echmi->qevent_irq, IRQF_TRIGGER_FALLING);
		}
		enable_irq(echmi->qevent_irq);
	}
	return 0;
}
#endif /* CONFIG_PM */
 
static const struct of_device_id hw_hmi_match[] = {
	{.compatible = "huawei,echub-hmi"},
	{},
};
MODULE_DEVICE_TABLE(of, hw_hmi_match);

struct platform_driver hw_hmi_driver = {
	.probe = hw_hmi_probe,
	.remove = hw_hmi_remove,
	.driver =
		{
			.name = "hw_hmi",
			.owner = THIS_MODULE,
			.of_match_table = of_match_ptr(hw_hmi_match),
		},
	#ifdef CONFIG_PM
		.suspend = hw_hmi_suspend,
		.resume = hw_hmi_resume,
	#endif
};

/**********************************************************
 *  Function:		hw_hmi_init
 *  Discription:	module initialization
 *  Parameters:	 pdev:platform_device
 *  return value:	0-sucess or others-fail
 **********************************************************/
int __init hw_hmi_init(void)
{
	int ret;

	echub_info("%s\n", __func__);
	ret = platform_driver_register(&hw_hmi_driver);
	if (ret)
		echub_err("hmi_dev misc_register err\n");

	return ret;
}

/**********************************************************
 *  Function:		hw_gpio_key_exit
 *  Discription:	module exit
 *  Parameters:	 NULL
 *  return value:	NULL
 **********************************************************/
void __exit hw_hmi_exit(void)
{
	echub_info("%s\n", __func__);
	platform_driver_unregister(&hw_hmi_driver);
}

module_init(hw_hmi_init);
module_exit(hw_hmi_exit);

MODULE_ALIAS("armpc hmi module");
MODULE_DESCRIPTION("armpc hmi driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");