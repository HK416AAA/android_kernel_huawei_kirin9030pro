/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: Hisilicon hardware crypto engine driver.
 * Create : 2022/03/18
 */
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/iopoll.h>
#include <linux/dma-mapping.h>
#include <linux/mm_lb/mm_lb.h>
#include <asm/io.h>
#include <asm/memory.h>

#include "hicrypto_alg_hd_km.h"
#include "hicrypto_eng_ctrl.h"
#include "hicrypto_ioctl.h"
#include "hicrypto_driver.h"
#include "hicrypto_dev_chip.h"
#include "hicrypto_macro.h"
#include "hicrypto_regs.h"
#include "hicrypto_errno.h"
#include "hicrypto_log.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

/* DTS node path */
#define DTS_HIEPS_PATH  "/reserved-memory/hieps"
#define HICRYPTO_RESV_OFFSET    (0x100000)

struct hicrypto_drv_data {
	struct list_head dev_list;
	spinlock_t lock; /* List protection access */
};

static struct hicrypto_drv_data hicrypto_dev_list = {
	.dev_list = LIST_HEAD_INIT(hicrypto_dev_list.dev_list),
	.lock = __SPIN_LOCK_UNLOCKED(hicrypto_dev_list.lock),
};

struct hicrypto_device *hicrypto_find_dev(struct hicrypto_device **dev)
{
	struct hicrypto_device *hdev = NULL, *tmp;

	spin_lock_bh(&hicrypto_dev_list.lock);
	if (!(*dev)) {
		list_for_each_entry(tmp, &hicrypto_dev_list.dev_list, list)
		{
			hdev = tmp;
			break;
		}
		*dev = hdev;
	} else {
		hdev = *dev;
	}

	spin_unlock_bh(&hicrypto_dev_list.lock);

	return hdev;
}

static int hicrypto_drv_get_reserve_addr(struct hicrypto_device *hdev)
{
	struct device_node *dn = NULL;
	const char *name = NULL;
	int 	len;
	const unsigned long *p = NULL;

	dn = of_find_node_by_path(DTS_HIEPS_PATH);
	if (!dn) {
		pal_error("hicrypto ree find node failed\n");
		return -ENOMEM;
	}

	/* check if status = ok, or status not defined */
	name = of_get_property(dn, "status", &len);
	if (name && !strncmp("disabled", name, strlen("disabled"))) {
		pal_error("hicrypto ree get status not ok\n");
		return -ENOMEM;
	}

	p = (unsigned long *)of_get_property(dn, "reg", NULL);
	if (!p) {
		pal_error("hicrypto ree get reg not exist\n");
		goto err;
	}

	hdev->reserved_phy_base = (u64)(uintptr_t)(be64_to_cpup((const __be64 *)(uintptr_t)(p))) + HICRYPTO_RESV_OFFSET;
	hdev->reserved_size = ((unsigned int)(uintptr_t)(be64_to_cpup((const __be64 *)(uintptr_t)(++p)))) >> 1;
	if (!hdev->reserved_phy_base || !hdev->reserved_size)
		goto err;

	of_node_put(dn);
	return 0;
err:
	of_node_put(dn);
	return -ENOMEM;
}

static int hicrypto_memory_map(struct hicrypto_device *hdev)
{
	int ret;

	/* get reserved mem */
	ret = hicrypto_drv_get_reserve_addr(hdev);
	if (ret) {
		pal_error("hicrypto ree hicrypto_drv_get_reserve_addr failed\n");
		return ret;
	}

	/* reserved mem map */
	ret = hicrypto_reserved_mmap(hdev);
	if (ret) {
		pal_error("hicrypto ree hicrypto_reserved_mmap failed\n");
		return ret;
	}
	return 0;
}

static int hicrypto_drv_probe(struct platform_device *pdev)
{
	struct hicrypto_device *hdev;
	struct device *dev = &pdev->dev;
	struct resource *res;
	int ret;

	hdev = devm_kzalloc(dev, sizeof(*hdev), GFP_KERNEL);
	if (!hdev) {
		pal_error("hicrypto ree dev devm_kzalloc failed\n");
		return -ENOMEM;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	hdev->io_base = devm_ioremap_resource(dev, res);
	if (IS_ERR(hdev->io_base)) {
		pal_error("hicrypto ree dev devm_ioremap_resource failed\n");
		return PTR_ERR(hdev->io_base);
	}

	hdev->cfg_base = hdev->io_base + HISI_REG_CFG_BASE_OFF;
	hdev->km_base = hdev->io_base + HISI_REG_KM_BASE_OFF;
	hdev->sce_base = hdev->io_base + HISI_REG_SCE_BASE_OFF;
	hdev->dev = dev;

	platform_set_drvdata(pdev, hdev);

	ret = hicrypto_memory_map(hdev);
	if (ret) {
		pal_error("hicrypto ree hicrypto_memory_map failed, ret = %d\n", ret);
		return ret;
	}

	ret = hicrypto_prof_register_cdev(hdev);
	if (ret) {
		pal_error("hicrypto_prof_register_cdev failed, ret = %d\n", ret);
		return ret;
	}
	// todo:使用中断方式，对中断进行注册，并在中断处理函数中唤醒等待队列

	init_waitqueue_head(&hdev->int_queue);
	hdev->polled = true;
	hdev->en_intr = false;
	hdev->int_rcvd = 0;
	hdev->km_valid_flag = HISI_KM_VALID_UNINIT;

	/* add device */
	spin_lock(&hicrypto_dev_list.lock);
	list_add_tail(&hdev->list, &hicrypto_dev_list.dev_list);
	spin_unlock(&hicrypto_dev_list.lock);
	hicrypto_hd_rs_init();

	ret = hicrypto_ree_km_rtldec();
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hicrypto rtl dec failed, init failed, ret = 0x%x\n", ret);
	}
	hicrypto_km_gid_derive_selftest(hdev);

	pal_error("%s success\n", __func__);
	return 0;
}

static int hicrypto_drv_remove(struct platform_device *pdev)
{
	struct hicrypto_device *hdev;

	hdev = platform_get_drvdata(pdev);
	if (!hdev)
		return -ENODEV;
	hicrypto_prof_unregister_cdev(hdev);
	spin_lock(&hicrypto_dev_list.lock);
	list_del(&hdev->list);
	spin_unlock(&hicrypto_dev_list.lock);
	return 0;
}

static int hicrypto_drv_suspend(struct platform_device *pdev, struct pm_message state)
{
	pr_err("%s: suspend +\n", __func__);
	int ret = err_api(ERRCODE_UNKNOWN);
	unused(pdev);
	unused(state);
	ret = hicrypto_wait_hd_idle();
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hicrypto wait hd idle failed, suspend failed, ret = 0x%x\n", ret);
	}
	pr_err("%s: suspend -\n", __func__);
	return 0;
}

static int hicrypto_drv_resume(struct platform_device *pdev)
{
	pr_err("%s: resume +\n", __func__);
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hicrypto_device *hdev;
	ret = hicrypto_ree_km_rtldec();
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hicrypto rtl dec failed, resume failed, ret = 0x%x\n", ret);
		goto end_handle;
	}
	hdev = platform_get_drvdata(pdev);
	if (pal_check(!hdev)) {
		pal_error("hicrypto ree resume failed, get drvdata failed\n");
		goto end_handle;
	}
	hicrypto_km_gid_derive_selftest(hdev);
end_handle:
	pr_err("%s: resume -\n", __func__);
	return 0;
}

static const struct of_device_id hicrypto_of_match[] = { 
	{.compatible = "hisilicon,hicrypto",},
	{},
};

MODULE_DEVICE_TABLE(of, hicrypto_of_match);

static struct platform_driver hicrypto_driver = {
	.probe = hicrypto_drv_probe,
	.remove = hicrypto_drv_remove,
	.suspend = hicrypto_drv_suspend,
	.resume = hicrypto_drv_resume,
	.driver =
	{
		.name = "hicrypto",
		.of_match_table = hicrypto_of_match,
	},
};
module_platform_driver(hicrypto_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Hisilicon crypto engine driver");
MODULE_ALIAS("platform:hicrypto");
MODULE_AUTHOR("sec engine");
