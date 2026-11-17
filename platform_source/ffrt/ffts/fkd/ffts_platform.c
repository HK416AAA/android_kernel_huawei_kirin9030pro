/*
 * ffts_platform.c
 *
 * ffts platform
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
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
#include "ffts_platform.h"

#include <linux/device.h>
#include <linux/module.h>

#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <securec.h>
#include <platform_include/cee/linux/sched/ffrt/ffts_sched.h>

#include "ffts_devinit.h"
#include "ffts_irq.h"
#include "ffts_interrupt.h"
#include "ffts_resource.h"
#include "ffts_log.h"
#include "ffts_reg.h"
#include "ffts_lpid.h"
#include "ffts_tid.h"
#include "ffts_dfx_black_box.h"
#include "ffts_dfx_debug.h"
#include "ffts_bbit_debug.h"
#include "fpd_interface.h"

#ifdef CONFIG_FFRT_DEBUG
#include "ffts_pmu.h"
#include "ffts_perf.h"
#endif

struct fpd_registry* g_fpd; // FPD driver registry data
static struct ffts_platform_info *g_ffts_platform_info;

struct fpd_registry* get_fpd(void)
{
	return g_fpd;
}

vir_addr_t ffts_get_reg_base(void)
{
	cond_return_error(g_ffts_platform_info == NULL, 0, "get platform info error\n");

	return ((vir_addr_t)(uintptr_t)g_ffts_platform_info->dts_info.reg_vaddr[FFTS_KERNEL_BASE_REG]
		- FFTS_RESERVED_SIZE - FFTS_USER_REG_SIZE);
}

static int ffts_power_up(uint32_t flag)
{
	if (g_fpd != NULL && g_fpd->fpd_power_manager)
		return g_fpd->fpd_power_manager(FPD_PM_POWER_UP, flag);
	return 0;
}

static int ffts_power_down(void)
{
	if (g_fpd != NULL && g_fpd->fpd_power_manager)
		return g_fpd->fpd_power_manager(FPD_PM_POWER_DOWN, 0);
	return 0;
}

static int ffts_map_resmem(struct ffts_mem_info *resmem_desc)
{
	vir_addr_t virt_addr = 0;
	phys_addr_t phy_addr = resmem_desc->phy_addr;
	int ret = 0;

	if (phy_addr == 0 || resmem_desc->size == 0) {
		ffts_drv_err("resmem desc error, size= 0x%x\n", resmem_desc->size);
		return -1;
	}

	virt_addr = (vir_addr_t)(uintptr_t)ioremap_cache(phy_addr, resmem_desc->size);
	if (virt_addr == 0) {
		ffts_drv_err("ioremap_cache failed!\n");
		return -1;
	}

	ret = memset_s(virt_addr, resmem_desc->size, 0, resmem_desc->size);
	if (ret != 0) {
		iounmap((void *)(uintptr_t)virt_addr);
		ffts_drv_err("memset 0 fail, ret = %d\n", ret);
		return -1;
	}

	resmem_desc->virt_addr = virt_addr;

	ffts_drv_debug("ddr phyaddr=%pK, viraddr=%pK, size=0x%x\n", (void *)(uintptr_t)phy_addr, (void *)(uintptr_t)virt_addr, resmem_desc->size);

	return ret;
}

static void ffts_destroy_resmem(struct ffts_platform_info *plat_info)
{
	int i;
	ffts_drv_info("destroy mem\n");

	for (i = 0; i < FFTS_RESMEM_MAX; i++) {
		if (plat_info->resmem_desc[i].virt_addr == 0)
			continue;

		iounmap((void *)(uintptr_t)plat_info->resmem_desc[i].virt_addr);
		plat_info->resmem_desc[i].virt_addr = 0;
	}
}

static int ffts_set_resmem(struct ffts_platform_info *plat_info)
{
	int i;
	int ret = -1;
	if (g_fpd != NULL && g_fpd->fpd_get_resmem_info)
		g_fpd->fpd_get_resmem_info(plat_info);

	for (i = 0; i < FFTS_RESMEM_MAX; i++) {
		ret = ffts_map_resmem(&plat_info->resmem_desc[i]);
		cond_goto_error(ret != 0, map_resmem_fail, ret, -EINVAL,
			"map resmem failed, i = %d\n", i);
	}

	return 0;
map_resmem_fail:
	ffts_destroy_resmem(plat_info);
	return ret;
}

static int ffts_plat_parse_dtsi(struct platform_device *pdev,
	struct ffts_platform_info *plat_info)
{
	int ret;

	ret = ffts_plat_parse_reg_desc(pdev, plat_info);
	cond_return_error(ret != 0, ret, "parse platform reg desc failed\n");
	ret = ffts_plat_map_reg(pdev, plat_info);
	cond_return_error(ret != 0, ret, "map platform reg failed\n");

	ret = ffts_plat_parse_irq(pdev, plat_info);
	cond_goto_error(ret != 0, register_irq_fail, ret, -EINVAL, "parse platform irq failed\n");
	ret = ffts_register_irq(plat_info);
	cond_goto_error(ret != 0, register_irq_fail, ret, -EINVAL, "request irq failed\n");

	ret = ffts_set_resmem(plat_info);
	cond_goto_error(ret != 0, set_resmem_fail, ret, -EINVAL, "set platform resmem failed\n");

	ret = ffts_plat_parse_lpid(pdev, plat_info);
	cond_goto_error(ret != 0 && ret != -EINVAL, parse_lpid_fail, ret, ret,
		"parse platform lpid_max failed, ret = %d\n", ret); // 属性存在且ret不为0返回失败

	return 0;
parse_lpid_fail:
	ffts_destroy_resmem(plat_info);
set_resmem_fail:
	ffts_unregister_irq(plat_info);
register_irq_fail:
	ffts_plat_unmap_reg(pdev, plat_info);
	return ret;
}

struct ffts_platform_info *ffts_plat_get_info(void)
{
	return g_ffts_platform_info;
}

static int ffts_platform_probe(struct platform_device *pdev)
{
	int ret;
	struct ffts_platform_info *platform_info = NULL;
	ffts_drv_info("ffts platform probe\n");

	platform_info = kzalloc(sizeof(struct ffts_platform_info), GFP_KERNEL);
	cond_return_error(platform_info == NULL, -ENOMEM,
		"kzalloc platform info failed\n");

	// 1. parse dts
	ret = ffts_plat_parse_dtsi(pdev, platform_info);
	if (ret != 0) {
		ffts_drv_err("prase dtsi failed\n");
		goto PROB_FAIL;
	}

	ffts_drv_info("ffts platform probe success\n");
	g_ffts_platform_info = platform_info;
	return 0;

PROB_FAIL:
	kfree(platform_info);
	platform_info = NULL;
	return ret;
}

static int ffts_platform_remove(struct platform_device *pdev)
{
	struct ffts_platform_info *platform_info = NULL;

	ffts_drv_info("ffts platform remove\n");

	platform_info = ffts_plat_get_info();
	cond_return_error(platform_info == NULL, -EINVAL,
		"get platform info failed\n");

	ffts_destroy_resmem(platform_info);

	ffts_unregister_irq(platform_info);

	ffts_plat_unmap_reg(pdev, platform_info);

	kfree(platform_info);
	g_ffts_platform_info = NULL;

	ffts_drv_info("ffts platform remove succeed\n");

	return 0;
}

static int ffts_plt_pm_suspend(struct device *dev)
{
	int ret = 0;
	ffts_drv_warn("suspend enter\n");
	ret = ffts_power_down();
	cond_return_error(ret != 0, -EINVAL, "ffts power down failed\n");
	ffts_drv_warn("suspend exit\n");
	return 0;
}

static int ffts_plt_pm_resume(struct device *dev)
{
	int ret = 0;
	ffts_drv_warn("resume enter\n");
	ret = ffts_power_up(RESUME_POWER_UP);
	cond_return_error(ret != 0, -EINVAL, "ffts resume power up failed\n");
	ffts_drv_warn("resume exit\n");
	return 0;
}

const struct dev_pm_ops ffts_plt_pm_ops = {
	.suspend = ffts_plt_pm_suspend,
	.resume  = ffts_plt_pm_resume,
};

static const struct of_device_id ffts_of_match[] = {
	{ .compatible = "hisilicon,ffts", },
	{},
};
MODULE_DEVICE_TABLE(of, ffts_of_match);

static struct platform_driver ffts_platform_driver = {
	.probe = ffts_platform_probe,
	.remove = ffts_platform_remove,
	.driver = {
		.name = "ffts_platform",
		.of_match_table = ffts_of_match,
		.pm = &ffts_plt_pm_ops,
	},
};

static void ffts_thread_switch_config(u8 lpid, u16 uid, u16 ffts_tid, u8 qos)
{
	if (g_fpd != NULL && g_fpd->fpd_thread_switch_config)
		g_fpd->fpd_thread_switch_config(lpid, uid, ffts_tid, qos);
}

static struct ffts_sched_callback g_sched_callback = {
	.thread_switch = ffts_thread_switch_config,
};

int ffts_register_plat_driver(struct fpd_registry *fpd)
{
	int ret;
	g_fpd = fpd;
	ffts_drv_warn("fpd is registering\n");

	ret = ffts_power_up(NORMAL_POWER_UP);
	cond_return_error(ret != 0, -EINVAL,
		"ffts normal power up fail\n");

	ret = platform_driver_register(&ffts_platform_driver);
	cond_goto_error(ret != 0, driver_register_fail, ret, -EINVAL,
		"ffts platform driver register fail\n");

	ffts_drv_info("platform driver register succeed\n");

	ret = ffts_dev_register();
	cond_goto_error(ret != 0, dev_register_fail, ret, -EINVAL,
		"ffts dev register fail\n");
#ifdef CONFIG_FFRT_DEBUG
	ret = ffts_pmu_dev_init();
	cond_goto_error(ret != 0, pmu_dev_exit_fail, ret, -EINVAL,
		"ffts pmu dev register fail\n");

	ret = ffts_perf_dev_init();
	cond_goto_error(ret != 0, perf_dev_exit_fail, ret, -EINVAL,
		"ffts pmu dev register fail\n");
#endif

	ffts_tid_init();

	// register callback to os
	ffts_sched_register_callback(&g_sched_callback);

	ffts_black_box_init();
	ffts_bbit_debug_init();
	ffts_debug_info_init();

	ffts_drv_warn("fpd register succeed\n");
	return 0;

#ifdef CONFIG_FFRT_DEBUG
perf_dev_exit_fail:
	ffts_pmu_dev_exit();
pmu_dev_exit_fail:
	ffts_dev_unregister();
#endif
dev_register_fail:
	platform_driver_unregister(&ffts_platform_driver);
driver_register_fail:
	ffts_power_down();
	return ret;
}

int ffts_unregister_plat_driver(void)
{
	ffts_drv_warn("fpd is unregistering\n");

	ffts_debug_info_deinit();

	ffts_black_box_exit();

	ffts_tid_deinit();

#ifdef CONFIG_FFRT_DEBUG
	ffts_pmu_dev_exit();
	ffts_perf_dev_exit();
#endif

	ffts_dev_unregister();

	platform_driver_unregister(&ffts_platform_driver);

	(void)ffts_power_down();

	ffts_drv_warn("fpd unregister succeed\n");

	return 0;
}
