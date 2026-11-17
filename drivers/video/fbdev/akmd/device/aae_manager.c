/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/regulator/consumer.h>
#include <linux/delay.h>
#include <soc_media_pmctrl_interface.h>
#include <platform_include/display/linux/dpu_drmdriver.h>
#include <platform_include/see/bl31_smc.h>
#include "aae_res_mgr.h"
#include "aae_manager.h"
#include "aae_gfx.h"
#include "aae_isr.h"
#include "aae_power.h"
#include "akmd_pip.h"
#include "akmd_log.h"
#include "aae_xpu_proxy.h"
#include "ukmd_utils.h"
#include "aae_dacc_log_read.h"

#ifdef CONFIG_AKMD_AAE_OHOS
#include "sd_proxy.h"
#endif

#define DTS_AAE_MANAGER_NAME "akmd,aae_manager"
#define AAE_MANAGER_DRV_NAME "aae_manager"

#ifdef CONFIG_AKMD_AAE_OHOS
enum UDK_FFTS_CMD {
	CMD_FFTS_SR_REF_CNT_INC = 9,
	CMD_FFTS_SR_REF_CNT_DEC = 10,
};
#endif

static struct aae_manager *g_aae_mgr;

void register_aae_pipeline(struct aae_pipeline_sw *pip_sw)
{
	// no need check pip_sw valid, cause we have checked before we use, and
	// this function is not a kernel public interface
	aae_assert(!pip_sw);

	if (unlikely(!g_aae_mgr)) {
		aae_pr_err("g_aae_mgr is null");
		return;
	}

	pip_sw->aae_mgr = g_aae_mgr;
	aae_power_set_up(pip_sw);
	g_aae_mgr->pip_sws[pip_sw->index] = pip_sw;
}

bool is_aae_manager_available(void)
{
	return g_aae_mgr != NULL;
}

void unregister_aae_pipeline(struct aae_pipeline_sw *pip_sw)
{
	// no need check pip_sw valid, cause we have checked before we use, and
	// this function is not a kernel public interface
	aae_assert(!pip_sw);

	if (unlikely(!g_aae_mgr)) {
		aae_pr_err("g_aae_mgr is null");
		return;
	}

	g_aae_mgr->pip_sws[pip_sw->index] = NULL;
}

void aae_manager_lock_all(void)
{
	uint32_t index;
	struct aae_pipeline_sw *pip_sw = NULL;

	if (unlikely(!g_aae_mgr))
		return;

	for (index = 0; index < AAE_PIP_MAX; index++) {
		pip_sw = g_aae_mgr->pip_sws[index];
		if (!pip_sw)
			continue;

		down(&pip_sw->sem);
	}

	down(&g_aae_mgr->power_sem);
}

void aae_manager_unlock_all(void)
{
	int32_t index;
	struct aae_pipeline_sw *pip_sw = NULL;

	if (unlikely(!g_aae_mgr))
		return;

	up(&g_aae_mgr->power_sem);

	for (index = (AAE_PIP_MAX - 1); index >= 0; index--) {
		pip_sw = g_aae_mgr->pip_sws[index];
		if (!pip_sw)
			continue;

		up(&pip_sw->sem);
	}
}

static void aae_manager_setup(struct aae_manager *aae_mgr)
{
	mutex_init(&aae_mgr->tbu_sr_lock);
	mutex_init(&aae_mgr->vote_pw_lock);

	aae_mgr->vote_pw_refcount = 0;
	aae_mgr->power_status.status = 0;
	sema_init(&aae_mgr->power_sem, 1);
	atomic_set(&aae_mgr->xpu_aae_power_status, 0);
	INIT_LIST_HEAD(&aae_mgr->isr_list);

	aae_isr_init((void *)aae_mgr, &aae_mgr->isr_ctrl,
		aae_mgr->glb_irq, "aae_glb_irq", aae_glb_isr_get_unmask(), aae_glb_isr);
	list_add_tail(&aae_mgr->isr_ctrl.list_node, &aae_mgr->isr_list);
	// msg isr
	aae_isr_init((void *)aae_mgr, &aae_mgr->xpu_isr_ctrl,
		aae_mgr->xpu_irq, "aae_xpu_irq", aae_xpu_isr_get_unmask(), aae_xpu_isr);
	list_add_tail(&aae_mgr->xpu_isr_ctrl.list_node, &aae_mgr->isr_list);
	enable_irq(aae_mgr->xpu_irq);
}

static int32_t aae_manager_parse_dt(struct aae_manager *aae_mgr)
{
	int32_t ret;
	struct platform_device *pdev = aae_mgr->pdev;

	aae_mgr->aae_base = of_iomap(aae_mgr->parent_node, 0);
	if (!aae_mgr->aae_base) {
		aae_pr_err("failed to get aae_base!");
		return -ENXIO;
	}
	aae_mgr->pctrl_base = of_iomap(aae_mgr->parent_node, 1);
	if (!aae_mgr->pctrl_base)
		aae_pr_warn("failed to get pctrl_base!");

	aae_mgr->media1_ctrl_base = of_iomap(aae_mgr->parent_node, 2);
	if (!aae_mgr->media1_ctrl_base)
		aae_pr_warn("failed to get media1_ctrl_base!");

	aae_mgr->actrl_base = of_iomap(aae_mgr->parent_node, 3);
	if (!aae_mgr->actrl_base)
		aae_pr_warn("failed to get actrl_base!");
    aae_mgr->media1_pmc_base = of_iomap(aae_mgr->parent_node, 4);
	if (!aae_mgr->media1_pmc_base)
		aae_pr_warn("failed to get media1_pmc_base!");
    aae_mgr->media_lpctrl_apb_base = of_iomap(aae_mgr->parent_node, 5);
	if (!aae_mgr->media_lpctrl_apb_base)
		aae_pr_warn("failed to get media_lpctrl_apb_base!");
	aae_mgr->media1_crg_base = of_iomap(aae_mgr->parent_node, 6);
	if (!aae_mgr->media1_crg_base)
		aae_pr_warn("failed to get media1_crg_base!");
	aae_mgr->bisr_ctrl_base = of_iomap(aae_mgr->parent_node, 7);
	if (!aae_mgr->bisr_ctrl_base)
		aae_pr_warn("failed to get bisr_ctrl_base!");

	aae_mgr->aae_regulator = devm_regulator_get(&pdev->dev, "regulator_aae");
	if (IS_ERR(aae_mgr->aae_regulator)) {
		ret = (int32_t)PTR_ERR(aae_mgr->aae_regulator);
		aae_pr_err("aae_regulator error, ret=%d", ret);
		return ret;
	}

	aae_mgr->vivobus_regulator = devm_regulator_get(&pdev->dev, "regulator_vivobus");
	if (IS_ERR(aae_mgr->vivobus_regulator)) {
		ret = (int32_t)PTR_ERR(aae_mgr->vivobus_regulator);
		aae_pr_err("vivobus_regulator error, ret=%d", ret);
		return ret;
	}

	aae_mgr->media1_subsys_regulator = devm_regulator_get(&pdev->dev, "regulator_media_subsys");
	if (IS_ERR(aae_mgr->media1_subsys_regulator)) {
		ret = (int32_t)PTR_ERR(aae_mgr->media1_subsys_regulator);
		aae_pr_err("media1_subsys_regulator error, ret=%d", ret);
		return ret;
	}

	aae_mgr->glb_irq = of_irq_get(aae_mgr->parent_node, 0);
	aae_mgr->xpu_irq = of_irq_get(aae_mgr->parent_node, 1);
	aae_pr_info("aae_mgr glb_irq=%d, xpu_irq=%d", aae_mgr->glb_irq, aae_mgr->xpu_irq);

	return 0;
}

static void destroy_cmdlist_and_irq(struct aae_manager *aae_mgr)
{
	if (unlikely(!aae_mgr)) {
		aae_pr_err("aae_mgr is null!");
		return;
	}
	disable_irq(aae_mgr->xpu_irq);
	aae_cmd_destroy();
}

static void destory_io_resource(struct aae_manager *aae_mgr)
{
	if (unlikely(!aae_mgr)) {
		aae_pr_err("aae_mgr is null!");
		return;
	}

	if (aae_mgr->aae_base) {
        iounmap(aae_mgr->aae_base);
        aae_mgr->aae_base = NULL;
    }

	if (aae_mgr->pctrl_base) {
        iounmap(aae_mgr->pctrl_base);
        aae_mgr->pctrl_base = NULL;
    }

	if (aae_mgr->media1_ctrl_base) {
        iounmap(aae_mgr->media1_ctrl_base);
        aae_mgr->media1_ctrl_base = NULL;
    }

	if (aae_mgr->media1_pmc_base) {
        iounmap(aae_mgr->media1_pmc_base);
        aae_mgr->media1_pmc_base = NULL;
    }
}

static int ffts_sr_ref_inc(void)
{
#ifdef CONFIG_AKMD_AAE_OHOS
	int ret = liblinux_pal_proxy_udk_invoke(PAL_PROXY_COMBINE_CMD(UDK_FFTS_MAJOR_CMD,
		CMD_FFTS_SR_REF_CNT_INC), NULL, 0, NULL, 0);
	if (ret != 0)
		aae_pr_warn("increment ffts ref failed, ret = %d", ret);
	return ret;
#endif
	return 0;
}

static void ffts_sr_ref_dec(void)
{
#ifdef CONFIG_AKMD_AAE_OHOS
	int ret = liblinux_pal_proxy_udk_invoke(PAL_PROXY_COMBINE_CMD(UDK_FFTS_MAJOR_CMD,
		CMD_FFTS_SR_REF_CNT_DEC), NULL, 0, NULL, 0);
	if (ret != 0)
		aae_pr_err("decrement ffts ref failed, ret = %d", ret);
#endif
}

static void config_aae_mem_shutdown(void)
{
	int32_t ret = 0;

	ret = configure_dss_service_security(AAE_SEC_CONFIG, 1 /* shutdown aae retention */,  AAE_SEC_RETENTION_SD, 0);
	if (ret != 0)
		aae_pr_err("send aae_retention_sd msg to tzsp failed: 0x%x", ret);

	aae_pr_info("config_aae_mem_shutdown ok");
}

static int aae_manager_probe(struct platform_device *pdev)
{
	struct aae_manager *aae_mgr = NULL;
	int32_t ret;
	char __iomem *aae_base = NULL;

	if (unlikely(!pdev)) {
		aae_pr_err("pdev is null");
		return -EINVAL;
	}

	aae_pr_info("%s is probing now!", pdev->name);

	ret = ffts_sr_ref_inc();
	if (ret == -ENODEV) {
		aae_pr_warn("ffts plat drv is not ready, try later!");
        ret = -EPROBE_DEFER;
		goto error_out;
    }

	ret = aae_cmd_prepare();
	if (ret != 0) {
		aae_pr_warn("NOTICE aae_manager prepare cmd failed, retry later");
		ret = -EPROBE_DEFER;
		goto ffts_ref_dec;
	}
	aae_mgr = (struct aae_manager *)devm_kzalloc(&pdev->dev, sizeof(*aae_mgr), GFP_KERNEL);
	if (!aae_mgr) {
		aae_pr_err("alloc aae_manager failed!");
		ret = -EINVAL;
		goto ffts_ref_dec;
	}
	aae_mgr->pdev = pdev;
	aae_mgr->parent_node = pdev->dev.of_node;
	aae_mgr->hardware_reseted = 0;

	if (aae_manager_parse_dt(aae_mgr) != 0) {
		aae_pr_err("aae_manager parse dt failed!");
		ret = -EINVAL;
		goto ffts_ref_dec;
	}

	platform_set_drvdata(pdev, aae_mgr);
	aae_manager_setup(aae_mgr);
	g_aae_mgr = aae_mgr;

	config_aae_mem_shutdown();

	aae_pr_info("%s probe succ!", pdev->name);

	aae_base = aae_mgr->aae_base;
	aae_dacc_log_read_init(aae_base);
	return 0;

ffts_ref_dec:
	ffts_sr_ref_dec(); /* if probe failed, need dec ref */
error_out:
	return ret;
}

static int32_t aae_manager_remove(struct platform_device *pdev)
{
	struct aae_manager *aae_mgr = NULL;

	aae_dacc_log_read_deinit();

	ffts_sr_ref_dec();

	aae_mgr = platform_get_drvdata(pdev);
	if (unlikely(!aae_mgr))
		return -1;

	destroy_cmdlist_and_irq(aae_mgr);
	destory_io_resource(aae_mgr);
	g_aae_mgr = NULL;

	return 0;
}

static int32_t bypass_ffts_vote(struct aae_manager *aae_mgr)
{
	set_reg(SOC_MEDIA_PMCTRL_FFTS_REQ_INFO_ADDR(aae_mgr->media1_pmc_base), 0x1, 1, 0);
	return 0;
}

static int32_t enable_ffts_vote(struct aae_manager *aae_mgr)
{
	set_reg(SOC_MEDIA_PMCTRL_FFTS_REQ_INFO_ADDR(aae_mgr->media1_pmc_base), 0x0, 1, 0);
	return 0;
}

static void print_aae_vote_power_status(struct aae_manager *aae_mgr)
{
	/**
	* FFTS power vote control.
	* bit0: ffts power vote control for aae, 1 for bypass
	* bit1: ffts power vote result for aae
	*/
	aae_pr_info("FFTS_REQ_INFO = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_FFTS_REQ_INFO_ADDR(aae_mgr->media1_pmc_base)));

	aae_pr_info("VOTE_POWER_REQ = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_VOTE_POWER_REQ_ADDR(aae_mgr->media1_pmc_base)));
	aae_pr_info("VOTE_POWER_REQ_STAT = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_VOTE_POWER_REQ_STAT_ADDR(aae_mgr->media1_pmc_base)));

	aae_pr_info("INTR_VOTE_POWER_ON_RAW = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_INTR_VOTE_POWER_ON_RAW_ADDR(aae_mgr->media1_pmc_base)));
	aae_pr_info("INTR_VOTE_POWER_OFF_RAW = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_INTR_VOTE_POWER_OFF_RAW_ADDR(aae_mgr->media1_pmc_base)));
	aae_pr_info("INTR_VOTE_POWER_ON = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_INTR_VOTE_POWER_ON_ADDR(aae_mgr->media1_pmc_base)));
	aae_pr_info("INTR_VOTE_POWER_OFF = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_INTR_VOTE_POWER_OFF_ADDR(aae_mgr->media1_pmc_base)));

	aae_pr_info("CURR_VOTE_POWER_STAT = 0x%x",
		inp32(SOC_MEDIA_PMCTRL_CURR_VOTE_POWER_STAT_ADDR(aae_mgr->media1_pmc_base)));
}

#define AAE_POWER_OFF_TIMEOUT 1000 /* ms */
#define AAE_PWR_STAT_MASK 0x3
enum {
    AAE_PWR_ON     = 0x0,
    AAE_PWR_ONING  = 0x1,
    AAE_PWR_OFF    = 0x2,
    AAE_PWR_OFFING = 0x3,
};

static void wait_aae_power_off(struct aae_manager *aae_mgr)
{
	uint32_t aae_power_stat = 0;
	uint32_t delay_count = 0;

	do {
		aae_power_stat = inp32(SOC_MEDIA_PMCTRL_CURR_VOTE_POWER_STAT_ADDR(aae_mgr->media1_pmc_base));
		if ((aae_power_stat & AAE_PWR_STAT_MASK) == AAE_PWR_OFF)
			break;

		mdelay(1);
		delay_count++;
	} while (delay_count < AAE_POWER_OFF_TIMEOUT);

	if (delay_count == AAE_POWER_OFF_TIMEOUT) {
		aae_pr_warn("aae power off timeout!, aae_power_stat = 0x%x", aae_power_stat);
		print_aae_vote_power_status(aae_mgr);
	}
}

static int32_t aae_manager_pm_suspend(struct device *dev)
{
	struct aae_manager *aae_mgr = (struct aae_manager *)dev->driver_data;
	if (unlikely(!aae_mgr)) {
		aae_pr_err("aae_mgr is null");
		return -1;
	}

	destroy_cmdlist_and_irq(aae_mgr);

	bypass_ffts_vote(aae_mgr);
	wait_aae_power_off(aae_mgr);

	(void)aae_res_mgr_tcu_suspend();

	ffts_sr_ref_dec();

	aae_pr_info("%s suspend succ!", aae_mgr->pdev->name);

	return 0;
}

static int32_t aae_manager_pm_resume(struct device *dev)
{
	int32_t ret;
	struct aae_manager *aae_mgr = (struct aae_manager *)dev->driver_data;
	if (unlikely(!aae_mgr)) {
		aae_pr_err("aae_mgr is null");
		return -1;
	}

	(void)ffts_sr_ref_inc();

	(void)aae_res_mgr_tcu_resume();

	enable_ffts_vote(aae_mgr);

	ret = aae_cmd_prepare();
	if (ret != 0) {
		aae_pr_err("aae_manager prepare cmd failed");
		return -1;
	}

	aae_pr_info("%s resume succ!", aae_mgr->pdev->name);

	return 0;
}

#ifdef CONFIG_HIBERNATION
static int aae_manager_pm_freeze(struct device *dev)
{
	if (dpm_get_message_event() == PM_EVENT_QUIESCE)
		return 0;

	return aae_manager_pm_suspend(dev);
}

static int aae_manager_pm_restore(struct device *dev)
{
	return aae_manager_pm_resume(dev);
}
#endif

static const struct of_device_id aae_manager_match_table[] = {
	{
		.compatible = DTS_AAE_MANAGER_NAME,
		.data = NULL,
	},
	{},
};

static const struct dev_pm_ops aae_manager_pm_ops = {
#ifdef CONFIG_PM_SLEEP
	.suspend = aae_manager_pm_suspend,
	.resume = aae_manager_pm_resume,
#endif
#ifdef CONFIG_HIBERNATION
	.freeze_noirq = aae_manager_pm_freeze,
	.restore_noirq = aae_manager_pm_restore,
#endif
};

MODULE_DEVICE_TABLE(of, aae_manager_match_table);

static struct platform_driver g_aae_manager_driver = {
	.probe = aae_manager_probe,
	.remove = aae_manager_remove,
	.suspend = NULL,
	.resume = NULL,
	.shutdown = NULL,
	.driver = {
		.name = AAE_MANAGER_DRV_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(aae_manager_match_table),
		.pm = &aae_manager_pm_ops,
	},
};

static int32_t __init aae_manager_register(void)
{
	return platform_driver_register(&g_aae_manager_driver);
}

static void __exit aae_manager_unregister(void)
{
	platform_driver_unregister(&g_aae_manager_driver);
}

module_init(aae_manager_register);
module_exit(aae_manager_unregister);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("Display AAE Manager Device Driver");
MODULE_LICENSE("GPL");