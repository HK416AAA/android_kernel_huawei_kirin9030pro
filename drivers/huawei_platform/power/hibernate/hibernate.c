/*
 * hibernate.c
 *
 * add hibernate driver to set S4 boot stage
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
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
#include <linux/init.h>
#include <linux/module.h>
#include <linux/pm.h>
#include <linux/of.h>
#include <linux/suspend.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <hwbootfail/core/boot_detector.h>

/* ---- local static variables ---- */
static unsigned long last_hibernate_mode = 0;
static int is_hibernate_restored = false;

static int hibernate_probe(struct platform_device *pdev)
{
	/* reserved */
	return 0;
}

static int hibernate_remove(struct platform_device *pdev)
{
	/* reserved */
	return 0;
}

static int hibernate_restore(struct device *dev)
{
	pr_info("hibernate_restore set S4 restore flag\n");
	is_hibernate_restored = true;
	return 0;
}

static const struct dev_pm_ops hibernate_pm_ops = {
	.restore = hibernate_restore,
};

static const struct of_device_id hibernate_match_table[] = {
	{
		.compatible = "huawei,hibernate",
		.data = NULL,
	},
	{},
};

static struct platform_driver hibernate_driver = {
	.probe = hibernate_probe,
	.remove = hibernate_remove,
	.driver = {
		.name = "huawei,hibernate",
		.of_match_table = of_match_ptr(hibernate_match_table),
		.pm = &hibernate_pm_ops,
	},
};

static int hibernate_pm_notify(struct notifier_block* nb,
				   unsigned long mode, void* _unused)
{
	enum bootfail_errorcode errcode = BF_OK;

	switch (mode) {
	case PM_HIBERNATION_PREPARE: /* Going to hibernate */
		is_hibernate_restored = false;
		break;
	case PM_POST_HIBERNATION: /* Hibernation finished */
		/* when get PM_POST_HIBERNATION after got restore in driver, which means S4 restore success */
		if (is_hibernate_restored == true) {
			errcode = set_boot_stage(KERNEL_STAGE_S4_END);
			pr_info("get PM_POST_HIBERNATION after hibernate restored, set KERNEL_STAGE_S4_END [%d]\n", errcode);

			is_hibernate_restored = false;
		}
		break;
	case PM_RESTORE_PREPARE: /* Going to restore a saved image */
		errcode = set_boot_stage(KERNEL_STAGE_S4_START);
		pr_info("get PM_RESTORE_PREPARE, set KERNEL_STAGE_S4_START [%d]\n", errcode);

		is_hibernate_restored = false;
		break;
	case PM_POST_RESTORE: /* Restore failed */
		/* when get PM_POST_RESTORE after PM_RESTORE_PREPARE, which means S4 restore failed */
		if (last_hibernate_mode == PM_RESTORE_PREPARE) {
			pr_info("get PM_POST_RESTORE after PM_RESTORE_PREPARE, S4 restore failed\n");
		}
		break;
	default:
		/* do nothing */
		break;
	}
	last_hibernate_mode = mode;
	return 0;
}

static struct notifier_block hibernate_pm_nb = {
	.notifier_call = hibernate_pm_notify,
};

static int __init hibernate_init(void)
{
	int ret = 0;

	/* register platform driver */
	ret = platform_driver_register(&hibernate_driver);
	if (ret) {
		pr_err("[%s] platform_driver_register failed, err(%d)\n", __func__, ret);
		return ret;
	}

	/* register pm notifier */
	ret = register_pm_notifier(&hibernate_pm_nb);
	if (ret) {
		pr_err("[%s] register_pm_notifier failed, err(%d)\n", __func__, ret);
		return ret;
	}

	return ret;
}

static void __exit hibernate_exit(void)
{
	platform_driver_unregister(&hibernate_driver);
	unregister_pm_notifier(&hibernate_pm_nb);
}

module_init(hibernate_init);
module_exit(hibernate_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
