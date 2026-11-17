/*
 * super_privacy.c
 *
 * report super privacy switch event
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
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <huawei_platform/log/hw_log.h>
#include <linux/of_irq.h>
#include <platform_include/cee/linux/ulsr.h>

#define SP_RETURN_SUCCESS   0
#define SWITCH_STATUS_ON    1
#define SWITCH_STATUS_OFF   0
#define DEVICE_NAME         "super_privacy"
#define HWLOG_TAG           super_privacy
HWLOG_REGIST();

struct sp_data {
    struct input_dev *input_dev;
    int irq_num;
};

static const struct of_device_id super_privacy_of_match[] = {
    { .compatible = "huawei,super_privacy", },
    {}
};

MODULE_DEVICE_TABLE(of, super_privacy_of_match);

static int input_dev_open(struct input_dev *dev)
{
    hwlog_info("%s entry.\n", __func__);
    return SP_RETURN_SUCCESS;
}

static void input_dev_close(struct input_dev *dev)
{
    hwlog_info("%s entry.\n", __func__);
}

static irqreturn_t privacy_irq_handler(int irq, void *dev_id)
{
    struct sp_data *sp = (struct sp_data *)dev_id;

    if (sp == NULL) {
		hwlog_err("sp is null\n");
		return IRQ_HANDLED;
    }

    input_report_switch(sp->input_dev, SW_SUPER_PRIVACY, SWITCH_STATUS_ON);
    input_sync(sp->input_dev);

    input_report_switch(sp->input_dev, SW_SUPER_PRIVACY, SWITCH_STATUS_OFF);
    input_sync(sp->input_dev);

    return IRQ_HANDLED;
}

static void input_device_init(struct platform_device *pdev, struct sp_data *sp)
{
    struct input_dev *input_dev = sp->input_dev;

    input_dev->name = pdev->name;
    input_dev->id.bustype = BUS_HOST;
    input_dev->dev.parent = &pdev->dev;
    input_set_drvdata(input_dev, sp);

    set_bit(EV_SW, input_dev->evbit);
    set_bit(EV_SYN, input_dev->evbit);
    set_bit(SW_SUPER_PRIVACY, input_dev->swbit);

    input_dev->open = input_dev_open;
    input_dev->close = input_dev_close;
}

static int super_privacy_probe(struct platform_device *pdev)
{
    if (pdev == NULL) {
        hwlog_err("parameter error!\n");
        return -EINVAL;
    }

    hwlog_info("%s entry.\n", __func__);

    if (!of_match_node(super_privacy_of_match, pdev->dev.of_node)) {
        hwlog_err("dev node is not match. exiting.\n");
        return -ENODEV;
    }

    struct sp_data *sp = devm_kzalloc(&pdev->dev, sizeof(struct sp_data), GFP_KERNEL);
    if (sp == NULL) {
        hwlog_info("Failed to allocate struct sp_data!\n");
        return -ENOMEM;
    }

    struct input_dev *input_dev = input_allocate_device();
    if (input_dev == NULL) {
        hwlog_err("Failed to allocate struct input_dev!\n");
        devm_kfree(&pdev->dev, sp);
        return -ENOMEM;
    }
    sp->input_dev = input_dev;
    input_device_init(pdev, sp);

    int err = input_register_device(sp->input_dev);
    if (err) {
        hwlog_err("Failed to register input device!\n");
        goto exit;
    }

    sp->irq_num = irq_of_parse_and_map(pdev->dev.of_node, 0);
    if (sp->irq_num < 0) {
        hwlog_err("Failed to parse and map irq!\n");
        err = sp->irq_num;
        goto exit;
    }

    err = request_irq(sp->irq_num, privacy_irq_handler, IRQF_NO_SUSPEND, pdev->name, sp);
    if (err) {
        hwlog_err("Failed to request interupt handler!\n");
        goto exit;
    }

    device_init_wakeup(&pdev->dev, true);
    platform_set_drvdata(pdev, sp);

    hwlog_info("%s successfully!\n", __func__);
    return err;

exit:
    input_free_device(input_dev);
    hwlog_err("%s failed! ret = %d.\n", __func__, err);
    return err;
}

static int super_privacy_remove(struct platform_device *pdev)
{
    struct sp_data *sp = platform_get_drvdata(pdev);

    if (sp == NULL) {
        hwlog_err("get invalid sp pointer.\n");
        return -EINVAL;
    }

    free_irq(sp->irq_num, sp);
    input_unregister_device(sp->input_dev);
    platform_set_drvdata(pdev, NULL);
    devm_kfree(&pdev->dev, sp);

    return SP_RETURN_SUCCESS;
}

static int super_privacy_suspend(struct device *dev)
{
	hwlog_info("%s\n", __func__);
	return SP_RETURN_SUCCESS;
}

static int super_privacy_resume(struct device *dev)
{
	hwlog_info("%s\n", __func__);

    struct sp_data *sp = dev_get_drvdata(dev);
    if (sp == NULL)
		return -EINVAL;
    privacy_irq_handler(sp->irq_num, sp);

	if (is_ulsr()) {
		hwlog_info("%s in ulsr\n ", __func__);
		int ret = irq_set_irq_type(sp->irq_num, IRQF_TRIGGER_RISING |
			IRQF_TRIGGER_FALLING | IRQF_NO_SUSPEND);
		if (ret) {
			hwlog_err("irq_set_irq_type error");
			return -EINVAL;
		}
        enable_irq(sp->irq_num);
	}
	return SP_RETURN_SUCCESS;
}

static const struct dev_pm_ops super_privacy_pm = {
	.suspend = super_privacy_suspend,
	.resume = super_privacy_resume,
};

struct platform_driver super_privacy_driver = {
    .probe = super_privacy_probe,
    .remove = super_privacy_remove,
    .driver = {
        .name = "super_privacy",
        .owner = THIS_MODULE,
        .of_match_table = of_match_ptr(super_privacy_of_match),
        .pm = &super_privacy_pm,
    },
};

static int __init super_privacy_init(void)
{
    hwlog_info("%s entry.\n", __func__);

    int ret = platform_driver_register(&super_privacy_driver);
    if (ret)
        hwlog_err("%s error, ret = %d.\n", __func__, ret);

    return ret;
}

static void __exit super_privacy_exit(void)
{
    hwlog_info("%s entry.\n", __func__);
    platform_driver_unregister(&super_privacy_driver);
}

module_init(super_privacy_init);
module_exit(super_privacy_exit);

MODULE_ALIAS("super privacy event module");
MODULE_DESCRIPTION("super privacy event driver");
MODULE_LICENSE("GPL v2");
