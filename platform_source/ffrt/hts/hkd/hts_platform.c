/*
 * hts_platform.c
 *
 * about hts platform
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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

#include "hts_platform.h"
#include <linux/irq.h>
#include <linux/irqchip/arm-gic-v3.h>
#include <linux/module.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/cpu.h>
#include <linux/kthread.h>
#include <linux/dma-mapping.h>
#include <asm/io.h>
#include <securec.h>
#include "hts_kernel_log.h"
#include "hts_irq.h"
#include "hts_reg.h"
#include "hts_pm.h"
#include "hts_interface.h"
#include "hpd_interface.h"
static struct hts_platform_info *g_hts_platform_info;
static struct hpd_registry* g_hpd; // HPD driver registry data

struct hts_platform_info *hts_plat_get_info(void)
{
	return g_hts_platform_info;
}

struct hpd_registry *hts_get_hpd_registry(void)
{
	return g_hpd;
}

static int hts_plat_parse_irq(struct platform_device *pdev,
	struct hts_platform_info *plat_info)
{
	plat_info->dts_info.irq_abnormal = platform_get_irq(pdev, 0);
	hts_drv_warn("hts abnormal irq  %d\n", plat_info->dts_info.irq_abnormal);
	cond_return_error(plat_info->dts_info.irq_abnormal < 0,
		-EINVAL, "get normal irq fail %d\n", plat_info->dts_info.irq_abnormal);
	return 0;
}

static int hts_plat_parse_dtsi(struct platform_device *pdev,
	struct hts_platform_info *plat_info)
{
	int ret;

	ret = hts_plat_parse_irq(pdev, plat_info);
	cond_return_error(ret != 0, -EINVAL, "parse platform irq failed\n");

	ret = hts_plat_parse_reg_desc(pdev, plat_info);
	cond_return_error(ret != 0, -EINVAL, "parse platform reg desc failed\n");
	return 0;
}

static int hts_map_resmem(struct hts_resmem_info *resmem_desc)
{
	u64 virt_addr = 0;
	phys_addr_t phy_addr = resmem_desc->phy_addr;
	int ret = 0;

	if (phy_addr == 0 || resmem_desc->size == 0) {
		hts_drv_err("resmem desc error, size= 0x%x", resmem_desc->size);
		return -1;
	}

	virt_addr = (u64)(uintptr_t)ioremap_cache(phy_addr, resmem_desc->size);
	if (virt_addr == 0) {
		hts_drv_err("ioremap_cache failed!");
		return -1;
	}

	ret = memset_s((void *)virt_addr, resmem_desc->size, 0, resmem_desc->size);
	if (ret != 0) {
		iounmap((void *)(uintptr_t)virt_addr);
		hts_drv_err("memset 0 fail, ret = %d", ret);
		return -1;
	}

	resmem_desc->virt_addr = virt_addr;

	hts_drv_debug("ddr phyaddr=%pK, viraddr=%pK, size=0x%x", phy_addr, virt_addr, resmem_desc->size);

	return ret;
}


static void hts_unmap_resmem(struct hts_platform_info *plat_info)
{
	int i;
	hts_drv_info("destroy mem");

	for (i = 0; i < HTS_RESMEM_MAX_RESOURCE; i++) {
		if (plat_info->resmem_desc[i].virt_addr == 0)
			continue;
		iounmap((void *)(uintptr_t)plat_info->resmem_desc[i].virt_addr);
		plat_info->resmem_desc[i].virt_addr = NULL;
	}
}

static int hts_init_resmem(struct hts_platform_info *plat_info)
{
	int i;
	int ret = -1;

	if (g_hpd != NULL && g_hpd->hts_get_resmem_info)
		g_hpd->hts_get_resmem_info(plat_info);

	for (i = 0; i < HTS_RESMEM_MAX_RESOURCE; i++) {
		ret = hts_map_resmem(&plat_info->resmem_desc[i]);
		cond_goto_error(ret != 0, map_resmem_fail, ret, -EINVAL,
						"map resmem failed, i = %d\n", i);
	}

	return 0;
map_resmem_fail:
	hts_unmap_resmem(plat_info);
	return ret;
}

static int hts_platform_probe(struct platform_device *pdev)
{
	int ret;
	struct hts_platform_info *platform_info = NULL;
	hts_drv_warn("hts platform probe start\n");
	cond_return_error(pdev == NULL, -ENOMEM, "pdev is NULL\n");

	platform_info = kzalloc(sizeof(struct hts_platform_info), GFP_KERNEL);
	cond_return_error(platform_info == NULL, -ENOMEM,
		"kzalloc platform info failed\n");

	platform_info->pdev = &pdev->dev;

	ret = hts_plat_parse_dtsi(pdev, platform_info);
	if (ret != 0) {
		hts_drv_err("prase dtsi failed\n");
		goto prob_fail;
	}

	ret = hts_plat_map_reg(pdev, platform_info);
	if (ret != 0) {
		hts_drv_err("parse reg desc failed\n");
		goto prob_fail;
	}

	ret = hts_register_irq(platform_info);
	if (ret != 0) {
		hts_drv_err("register irq failed\n");
		goto prob_fail;
	}

	ret = hts_init_resmem(platform_info);
	if (ret != 0) {
		hts_drv_err("hts_init_resmem failed\n");
		goto prob_fail;
	}

	hts_drv_warn("hts platform probe success\n");
	g_hts_platform_info = platform_info;

	hts_drv_warn("hts platform probe end\n");
	return 0;
prob_fail:
	kfree(platform_info);
	platform_info = NULL;
	return ret;
}

uint8_t *hts_plat_get_reg_vaddr(hts_register_index idx)
{
	struct hts_platform_info *plat_info = NULL;

	plat_info = hts_plat_get_info();
	if (plat_info == NULL) {
		hts_drv_err("get plat_info failed\n");
		return NULL;
	}

	return (uint8_t *)plat_info->dts_info.reg_vaddr[idx];
}

static int hts_platform_remove(struct platform_device *pdev)
{
	hts_drv_warn("hts platform remove\n");
	cond_return_error(pdev == NULL, -ENOMEM, "pdev is NULL\n");

	hts_unregister_irq(g_hts_platform_info);
	hts_plat_unmap_reg(pdev, g_hts_platform_info);
	kfree(g_hts_platform_info);
	g_hts_platform_info = NULL;
	return 0;
}

static const struct of_device_id hts_of_match[] = {
	{ .compatible = "hisilicon,hts", },
	{},
};

static int hts_platform_suspend(struct platform_device *pdev, pm_message_t state)
{
	unused(pdev);
	unused(state);
	return 0;
}

static int hts_platform_resume(struct platform_device *pdev)
{
	unused(pdev);
	return 0;
}

static int hts_dev_pm_suspend(struct device *dev)
{
	unused(dev);
	hts_drv_warn("hts_dev suspend start\n");
	return 0;
}

static int hts_dev_pm_resume(struct device *dev)
{
	int ret;
	unused(dev);
	hts_drv_warn("hts_dev resume start\n");
	ret = hts_powerup();
	if (ret != 0) {
		hts_drv_err("hts_dev resume poweron failed\n");
		ret = -EINVAL;
	}
	return ret;
}

static const struct dev_pm_ops hts_dev_pm_ops = {
	.suspend = hts_dev_pm_suspend,
	.resume  = hts_dev_pm_resume,
};

static struct platform_driver hts_platform_driver = {
	.probe = hts_platform_probe,
	.remove = hts_platform_remove,
	.suspend = hts_platform_suspend,
	.resume = hts_platform_resume,
	.driver = {
		.name = "hts_platform",
		.of_match_table = hts_of_match,
		.pm = &hts_dev_pm_ops,
	},
};

int hkd_register_plat_driver(struct hpd_registry *hpd)
{
	int ret;
	const uint8_t dev_id = 0;
	cond_return_error(hpd == NULL, -ENOMEM, "hpd is null\n");
	g_hpd = hpd;

	hts_drv_warn("hpd is registering\n");

	ret = platform_driver_register(&hts_platform_driver);
	if (ret) {
		hts_drv_err("insmod devdrv platform driver fail\n");
		return ret;
	}

	ret = hts_dev_init(THIS_MODULE, dev_id);
	if (ret) {
		hts_drv_err("hts dev init fail\n");
		platform_driver_unregister(&hts_platform_driver);
		return ret;
	}
	hts_drv_warn("succeed\n");

	return ret;
}

int hkd_unregister_plat_driver(void)
{
	hts_drv_warn("hpd is unregistering\n");
	g_hpd = NULL;
	hts_dev_exit();
	platform_driver_unregister(&hts_platform_driver);
	return 0;
}
