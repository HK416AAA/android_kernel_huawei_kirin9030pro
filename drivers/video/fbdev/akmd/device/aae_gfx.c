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

#include <linux/delay.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <aae/soc_dpu_define.h>
#include "aae_gfx.h"
#include "aae_pip.h"
#include "aae_manager.h"
#include "cmdlist_interface.h"
#include "aae_res_mgr.h"
#include "akmd_log.h"

#define AAE_DRV_NAME "aae_gfx"

static struct aae_gfx *g_aae_devs[AAE_PIP_MAX];

static int32_t aae_init_config(struct platform_device *pdev)
{
	return 0;
}

static int32_t aae_gfx_init_pip(struct aae_pipeline_sw **pip_sw)
{
	return aae_pip_init(pip_sw);
}

static void aae_gfx_deinit_pip(struct aae_pipeline_sw **pip_sw)
{
	aae_pip_deinit(pip_sw);
}

static void aae_gfx_close_pip(struct aae_pipeline_sw *pip_sw)
{
	return aae_pip_close(pip_sw);
}

static void aae_gfx_init_data(struct aae_gfx_data *data)
{
}

static int32_t aae_gfx_open(struct inode *inode, struct file *filp)
{
	uint32_t i = 0;

	if (unlikely(!inode)) {
		aae_pr_err("inode is null");
		return -1;
	}

	if (unlikely(!filp)) {
		aae_pr_err("filp is null");
		return -1;
	}

	if (!filp->private_data) {
		for (i = 0; i < AAE_PIP_MAX; ++i) {
			if (g_aae_devs[i] && inode->i_rdev == g_aae_devs[i]->chrdev.devno) {
				filp->private_data = g_aae_devs[i];
				break;
			}
		}
	}

	if (unlikely(!filp->private_data)) {
		aae_pr_err("filp->private_data is null");
		return -1;
	}

	if (atomic_read(&g_aae_devs[i]->ref_cnt) >= DEV_OPEN_MAX_CNT) {
		aae_pr_err("ref_cnt=%d overflow, tgid=%d",
			atomic_read(&g_aae_devs[i]->ref_cnt), current->tgid);
		return -1;
	}

	atomic_inc(&g_aae_devs[i]->ref_cnt);

	aae_pr_warn("ref_cnt = %d tgid=%d", atomic_read(&g_aae_devs[i]->ref_cnt), current->tgid);

	return 0;
}

static int32_t aae_gfx_release(struct inode *inode, struct file *filp)
{
	struct aae_gfx *aae_dev;

	if (unlikely(!filp)) {
		aae_pr_err("filp is null");
		return -1;
	}

	aae_dev = (struct aae_gfx *)filp->private_data;
	if (unlikely(!aae_dev)) {
		aae_pr_err("aae_dev is null");
		return -1;
	}

	aae_pr_warn("ref_cnt=%d tgid=%d", atomic_read(&aae_dev->ref_cnt), current->tgid);

	if (atomic_read(&aae_dev->ref_cnt) == 0) {
		aae_pr_warn("pdev is not opened, cannot release");
		return 0;
	}

	if (atomic_sub_and_test(1, &aae_dev->ref_cnt)) {
		aae_gfx_close_pip(aae_dev->pip_sw);
		filp->private_data = NULL;
		return 0;
	}
	aae_pr_warn("-");

	return 0;
}

static int32_t aae_commit_valid_check(struct aae_commit *commit)
{
	if (unlikely(commit->scene_id >= AAE_SCENE_MAX)) {
		aae_pr_err("invalid scene_id=%u AAE_SCENE_MAX=%d", commit->scene_id, AAE_SCENE_MAX);
		return -1;
	}

	if (unlikely(commit->layer_count > AAE_LAYER_MAX_COUNT)) {
		aae_pr_err("layer count=%u is out of range", commit->layer_count);
		return -1;
	}
	return 0;
}

static int32_t aae_gfx_commit(struct aae_gfx *aae_dev, const void __user* argp)
{
	int32_t ret;
	struct aae_pipeline_sw *pip_sw = aae_dev->pip_sw;
	struct aae_commit *commit = &pip_sw->commit;

	down(&pip_sw->sem);
	if (copy_from_user(commit, argp, sizeof(*commit)) != 0) {
		aae_pr_err("copy from user commit info fail");
		up(&pip_sw->sem);
		return -EINVAL;
	}

	if (aae_commit_valid_check(commit) != 0) {
		aae_pr_err("aae pip index=%u commit_index=%u valid check fail", pip_sw->index, commit->commit_index);
		ukmd_cmdlist_present_release_locked(CMDLIST_DEV_ID_AAE,
			commit->scene_id, commit->cmdlist_id);
		up(&pip_sw->sem);
		return -1;
	}

	/* if there is no poweron, need to call poweron here, and then call poweroff at task end */
	if (!pip_sw->power_on) {
		if (pip_sw->on_func_no_lock(pip_sw)) {
			aae_pr_err("aae pip index=%u commit_index=%u power on fail", pip_sw->index, commit->commit_index);
			ukmd_cmdlist_present_release_locked(CMDLIST_DEV_ID_AAE, commit->scene_id, commit->cmdlist_id);
			up(&pip_sw->sem);
			return -1;
		}
	}

	ret = pip_sw->commit_func(pip_sw);
	if (unlikely(ret != 0)) {
		aae_pr_err("aae pip index=%u commit fail: scene_id=%u cmdlist_id=%u layer_count=%u commit_index=%u",
			pip_sw->index, commit->scene_id, commit->cmdlist_id, commit->layer_count, commit->commit_index);
		ukmd_cmdlist_present_release_locked(CMDLIST_DEV_ID_AAE, commit->scene_id, commit->cmdlist_id);
	}

	up(&pip_sw->sem);
	return ret;
}

static long aae_gfx_ioctl(struct file *filp, uint32_t cmd, unsigned long arg)
{
	struct aae_gfx *aae_dev = NULL;
	void __user *argp = (void __user *)(uintptr_t)arg;

	if (unlikely(!filp)) {
		aae_pr_err("filp is null");
		return -1;
	}

	if (unlikely(!argp)) {
		aae_pr_err("argp is null");
		return -EINVAL;
	}

	aae_dev = (struct aae_gfx *)filp->private_data;
	if (unlikely(!aae_dev)) {
		aae_pr_err("aae_dev is null");
		return -EINVAL;
	}

	aae_pr_debug("aae pip index=%u cmd=%#x tgid=%d", aae_dev->pip_sw->index, cmd, current->tgid);
	switch (cmd) {
	case AAE_COMMIT:
		return aae_gfx_commit(aae_dev, argp);
	default:
		return 0;
	}
}

static struct file_operations aae_gfx_fops = {
	.owner = THIS_MODULE,
	.open = aae_gfx_open,
	.release = aae_gfx_release,
	.unlocked_ioctl = aae_gfx_ioctl,
	.compat_ioctl =  aae_gfx_ioctl,
};

static int32_t aae_gfx_parse_dt(struct aae_gfx *aae_dev)
{
	int32_t ret;
	uint32_t index = 0;

	ret = of_property_read_u32(aae_dev->parent_node, "index", &index);
	if (ret) {
		aae_pr_err("aae_dev read index fail ret=%d", ret);
		return -1;
	}

	aae_pr_info("index=%u", index);
	if (index > AAE_PIP_MAX) {
		aae_pr_err("index=%u over %d", index, AAE_PIP_MAX);
		return -1;
	}
	aae_dev->pip_sw->index = index;

	return aae_pip_parse_dt(aae_dev->pip_sw, aae_dev->parent_node);
}

static void aae_gfx_create_chrdev(struct aae_gfx *aae_dev)
{
	int32_t ret;

	aae_dev->chrdev.chr_class = class_create(THIS_MODULE, aae_dev->pdev->dev.of_node->name);
	if (unlikely(IS_ERR(aae_dev->chrdev.chr_class))) {
		ret = PTR_ERR(aae_dev->chrdev.chr_class);
		aae_pr_err("Unable to create fb class; errno = %d", ret);
		aae_dev->chrdev.chr_class = NULL;
	}
	aae_dev->chrdev.name = aae_dev->pdev->dev.of_node->name;
	aae_dev->chrdev.fops = &aae_gfx_fops;

	ukmd_create_chrdev(&aae_dev->chrdev);
}

static int aae_gfx_probe(struct platform_device *pdev)
{
	struct aae_gfx *aae_dev = NULL;

	if (unlikely(!pdev)) {
		aae_pr_err("pdev is null");
		return -EINVAL;
	}

	if (!is_aae_manager_available()) {
		aae_pr_warn("aae_gfx_probe g_aae_mgr, retry later");
		return -EPROBE_DEFER;
	}

	aae_pr_warn("%s is probing now!", pdev->name);

	aae_dev = platform_get_drvdata(pdev);
	if (aae_dev && aae_dev->is_init) {
		aae_pr_warn("aae gfx %s index=%u has been inited", aae_dev->chrdev.name, aae_dev->pip_sw->index);
		return 0;
	}

	/* 1, read config from dtsi */
	if (unlikely(aae_init_config(pdev))) {
		aae_pr_err("init aae config fail");
		return -1;
	}

	aae_dev = devm_kzalloc(&pdev->dev, sizeof(*aae_dev), GFP_KERNEL);
	if (unlikely(!aae_dev)) {
		aae_pr_err("alloc rm pdev data fail");
		return -1;
	}
	aae_dev->pdev = pdev;
	aae_dev->parent_node = pdev->dev.of_node;

	aae_gfx_init_data(&aae_dev->data);
	if (aae_gfx_init_pip(&aae_dev->pip_sw) != 0) {
		aae_pr_err("aae_gfx init pip failed!");
		return -EINVAL;
	}

	if (aae_gfx_parse_dt(aae_dev) != 0) {
		aae_pr_err("aae_dev parse dt failed!");
		aae_gfx_deinit_pip(&aae_dev->pip_sw);
		return -EINVAL;
	}

	/* create chrdev */
	aae_gfx_create_chrdev(aae_dev);

	dev_set_drvdata(&pdev->dev, aae_dev);

	register_aae_pipeline(aae_dev->pip_sw);

	aae_pip_setup(aae_dev->pip_sw);

	aae_dev->is_init = true;
	g_aae_devs[aae_dev->pip_sw->index] = aae_dev;

	aae_pr_warn("aae gfx %s index=%u probe succ", aae_dev->chrdev.name, aae_dev->pip_sw->index);

	return 0;
}

static int32_t aae_gfx_remove(struct platform_device *pdev)
{
	struct aae_gfx *aae_dev = platform_get_drvdata(pdev);
	if (unlikely(!aae_dev)) {
		aae_pr_err("aae_dev remove failed!");
		return -EINVAL;
	}

	if (aae_dev->pip_sw->index >= AAE_PIP_MAX) {
		aae_pr_err("aae_dev index=%u is overflow!", aae_dev->pip_sw->index);
		return -EINVAL;
	}
	aae_pip_release(aae_dev->pip_sw);
	g_aae_devs[aae_dev->pip_sw->index] = NULL;
	unregister_aae_pipeline(aae_dev->pip_sw);
	ukmd_destroy_chrdev(&aae_dev->chrdev);

	return 0;
}

#define DTS_AAE_GFX_NAME "akmd,aae_gfx"

static const struct of_device_id aae_gfx_match_table[] = {
	{
		.compatible = DTS_AAE_GFX_NAME,
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, aae_gfx_match_table);

static struct platform_driver g_aae_gfx_driver = {
	.probe = aae_gfx_probe,
	.remove = aae_gfx_remove,
	.suspend = NULL,
	.resume = NULL,
	.shutdown = NULL,
	.driver = {
		.name = AAE_DRV_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(aae_gfx_match_table),
	},
};

static int32_t __init aae_gfx_register(void)
{
	return platform_driver_register(&g_aae_gfx_driver);
}

static void __exit aae_gfx_unregister(void)
{
	platform_driver_unregister(&g_aae_gfx_driver);
}

module_init(aae_gfx_register);
module_exit(aae_gfx_unregister);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("Display AAE Device Driver");
MODULE_LICENSE("GPL");
