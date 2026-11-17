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

#include <linux/module.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/regulator/consumer.h>
#include <securec.h>

#include "aae_res_mgr.h"
#include "cmdlist_drv.h"
#include "aae_config_utils.h"
#include "akmd_log.h"
#include "aae_dvfs.h"
#include "aae_ddr_dvfs.h"
#include "mapper.h"
#include "scene_id_mgr.h"
#include "scene_mgr.h"
#include "task_binder.h"
#include "tcu_power_mgr.h"

#define AAE_RES_DEV_NAME "aae_resource"
#define UEVENT_BUF_LEN 120
struct aae_res_mgr *g_aae_rm_dev;

#ifdef CONFIG_AKMD_DEBUG_ENABLE
static ssize_t show_process_data(struct aae_res_mgr *aae_res_mgr, char *buf)
{
	struct aae_res_process_data *process_data = NULL;
	struct aae_res_process_data *tmp = NULL;
	ssize_t ret = 0;

	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "aae_res_process_data:\n");

	mutex_lock(&aae_res_mgr->process_data_lock);
	list_for_each_entry_safe(process_data, tmp, &aae_res_mgr->process_data_list, list) {
		if (unlikely(!process_data))
			continue;

		ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "tgid: %d, ref_count: %d\n",
			process_data->tgid, process_data->ref_cnt);
	}
	mutex_unlock(&aae_res_mgr->process_data_lock);
	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "----------------------\n");
	return ret;
}

static ssize_t aae_res_debug_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct aae_res_mgr *res_mgr = (struct aae_res_mgr*)dev_get_drvdata(dev);
	struct aae_res_resouce_node *_node_ = NULL;
	struct aae_res_resouce_node *res_node = NULL;
	ssize_t ret = 0;

	if (res_mgr == NULL)
		return 0;

	ret += show_process_data(res_mgr, buf + ret);

	list_for_each_entry_safe(res_node, _node_, &res_mgr->resource_list, list_node) {
		if (!res_node)
			continue;

		if (res_node->show != NULL)
			ret += res_node->show(res_node->data, buf + ret);
	}

	return ret;
}

static ssize_t aae_res_debug_store(struct device *device,
			struct device_attribute *attr, const char *buf, size_t count)
{
	struct aae_res_mgr *res_mgr = (struct aae_res_mgr*)dev_get_drvdata(device);
	struct aae_res_resouce_node *_node_ = NULL;
	struct aae_res_resouce_node *res_node = NULL;
	ssize_t ret = 0;

	if (res_mgr == NULL)
		return count;

	list_for_each_entry_safe(res_node, _node_, &res_mgr->resource_list, list_node) {
		if (!res_node)
			continue;

		if (res_node->store != NULL)
			ret += res_node->store(res_node->data, buf, count);
	}
	aae_pr_info("store ret %d", ret);
	return count;
}

static struct device_attribute rm_attrs[] = {
	__ATTR(rm_debug, S_IRUSR | S_IRGRP | S_IWUSR, aae_res_debug_show, aae_res_debug_store),

	/* TODO: other attrs */
};
#endif

static void aae_res_reset_resource_list(struct aae_res_process_data *process_data)
{
	struct aae_res_resouce_node *_node_ = NULL;
	struct aae_res_resouce_node *res_node = NULL;
	uint64_t res_types = 0;

	if (unlikely(!g_aae_rm_dev) || unlikely(process_data == NULL)) {
		aae_pr_err("g_aae_rm_dev or process_data is NULL");
		return;
	}

	res_types = process_data->res_types;

	list_for_each_entry_safe(res_node, _node_, &g_aae_rm_dev->resource_list, list_node) {
		if (!res_node)
			continue;

		aae_pr_info("res_node->res_types==0x%llx", res_node->res_type);
		if ((res_types & res_node->res_type) == 0)
			continue;

		if (res_node->release)
			res_node->release(res_node->data, process_data->tgid);
	}
}

void aae_send_uevent(int32_t event)
{
	char *envp[2];
	char event_buf[UEVENT_BUF_LEN];
	int ret;

	if (unlikely(!g_aae_rm_dev) || unlikely(!g_aae_rm_dev->rm_chrdev.chr_dev)) {
		aae_pr_info("g_rm_dev or chr_dev is NULL");
		return;
	}

	ret = snprintf_s(event_buf, sizeof(event_buf), sizeof(event_buf) - 1, "RES_EVENT=%d\n", event);
	if (ret < 0) {
		aae_pr_err("event_buf write failed, name=%s event=%d", g_aae_rm_dev->rm_chrdev.chr_dev->kobj.name, event);
		return;
	}

	envp[0] = event_buf;
	envp[1] = NULL;

	aae_pr_info("name=%s event=%d", g_aae_rm_dev->rm_chrdev.chr_dev->kobj.name, event);
	kobject_uevent_env(&(g_aae_rm_dev->rm_chrdev.chr_dev->kobj), KOBJ_CHANGE, envp);
}

static struct aae_res_process_data* get_process_data(struct aae_res_mgr *aae_res_mgr, int32_t tgid)
{
	struct aae_res_process_data *process_data = NULL;
	struct aae_res_process_data *tmp = NULL;

	list_for_each_entry_safe(process_data, tmp, &aae_res_mgr->process_data_list, list) {
		if (unlikely(!process_data))
			continue;

		if (process_data->tgid == tgid)
			return process_data;
	}

	return NULL;
}

static void insert_process_data(struct aae_res_mgr *aae_res_mgr, struct aae_res_process_data* process_data)
{
	list_add(&process_data->list, &aae_res_mgr->process_data_list);
}

static void remove_process_data(struct aae_res_mgr *aae_res_mgr, struct aae_res_process_data* process_data)
{
	list_del(&process_data->list);
}

static int32_t aae_res_open(struct inode *inode, struct file *filp)
{
	struct aae_res_process_data *process_data = NULL;

	if (!filp) {
		aae_pr_info("rm_dev or filp is null");
		return -1;
	}

	mutex_lock(&g_aae_rm_dev->process_data_lock);
	process_data = get_process_data(g_aae_rm_dev, current->tgid);
	if (!process_data) {
		aae_pr_info("cannot find process_data tgid=%d", current->tgid);

		process_data = kzalloc(sizeof(*process_data), GFP_KERNEL);
		if (!process_data) {
			aae_pr_err("kzalloc res process data fail");
			mutex_unlock(&g_aae_rm_dev->process_data_lock);
			return -ENOMEM;
		}
		atomic_set(&(process_data->ref_cnt), 0);
		process_data->tgid = current->tgid;

		aae_pr_info("insert process_data tgid=%d", process_data->tgid);
		insert_process_data(g_aae_rm_dev, process_data);
	} else {
		aae_pr_info("find process_data tgid=%d", process_data->tgid);

		if (atomic_read(&process_data->ref_cnt) >= DEV_OPEN_MAX_CNT) {
			aae_pr_err("ref_cnt=%d overflow, tgid=%d",
				atomic_read(&process_data->ref_cnt), current->tgid);
			mutex_unlock(&g_aae_rm_dev->process_data_lock);
			return -1;
		}
	}

	filp->private_data = process_data;

	atomic_inc(&process_data->ref_cnt);

	aae_pr_info("ref_cnt=%d tgid=%d, process_data->tgid=%d",
				atomic_read(&process_data->ref_cnt), current->tgid, process_data->tgid);
	mutex_unlock(&g_aae_rm_dev->process_data_lock);
	return 0;
}

static int32_t aae_res_release(struct inode *inode, struct file *filp)
{
	struct aae_res_process_data *process_data = NULL;

	if (!filp) {
		aae_pr_err("filp is null");
		return -1;
	}

	process_data = (struct aae_res_process_data *)filp->private_data;
	if (!process_data) {
		aae_pr_err("process_data is null");
		return -1;
	}

	mutex_lock(&g_aae_rm_dev->process_data_lock);
	if (atomic_read(&process_data->ref_cnt) == 0) {
		aae_pr_warn("res_types=%llx is not opened, cannot release", process_data->res_types);
		mutex_unlock(&g_aae_rm_dev->process_data_lock);
		return 0;
	}

	if (atomic_sub_and_test(1, &process_data->ref_cnt)) {
		aae_pr_info("ref_cnt=%d res_types=0x%llx process-tgid=%d tgid=%d, to release resource",
			atomic_read(&process_data->ref_cnt), process_data->res_types, process_data->tgid, current->tgid);

		aae_res_reset_resource_list(process_data);
		remove_process_data(g_aae_rm_dev, process_data);

		kfree(filp->private_data);
		filp->private_data = NULL;
		mutex_unlock(&g_aae_rm_dev->process_data_lock);
		return 0;
	}

	aae_pr_info("ref_cnt=%d res_types=0x%llx process-tgid=%d tgid=%d",
		atomic_read(&process_data->ref_cnt), process_data->res_types, process_data->tgid, current->tgid);
	mutex_unlock(&g_aae_rm_dev->process_data_lock);
	return 0;
}

static int32_t aae_res_register_types(struct aae_res_process_data *process_data, const void __user *argp)
{
	uint64_t types = 0;

	if (process_data == NULL)
		return -1;

	if (!argp) {
		aae_pr_err("argp is null");
		return -EINVAL;
	}

	if (copy_from_user(&types, argp, sizeof(types))) {
		aae_pr_err("copy from user client types fail");
		return -1;
	}
	process_data->res_types |= types;
	aae_pr_debug("register types 0x%llx", types);

	return 0;
}

static int32_t aae_res_ioctl_resource(struct aae_res_process_data *process_data, uint32_t cmd, void __user *argp)
{
	struct aae_res_resouce_node *_node_ = NULL;
	struct aae_res_resouce_node *res_node = NULL;
	int32_t ret = -2;

	if (unlikely(!g_aae_rm_dev)) {
		aae_pr_err("g_aae_rm_dev is NULL");
		return -1;
	}

	// hanle each resource manager
	list_for_each_entry_safe(res_node, _node_, &g_aae_rm_dev->resource_list, list_node) {
		if (!res_node)
			continue;

		if (!res_node->ioctl)
			continue;

		res_node->tgid = process_data->tgid;
		ret = (int32_t)res_node->ioctl(res_node, cmd, argp);
		if (ret <= 0) { // mean this cmd have been handled by this node
			aae_pr_debug("res node res_type=0x%x hanle this cmd 0x%x", res_node->res_type, cmd);
			break;
		}
	}

	if (ret != 0)
		aae_pr_warn("aae_res_ioctl failed! cmd 0x%x ret=%d", cmd, ret);

	return ret;
}

static long aae_res_ioctl(struct file *filp, uint32_t cmd, unsigned long arg)
{
	int32_t ret;
	struct aae_res_process_data *process_data = NULL;
	void __user *argp = (void __user *)(uintptr_t)arg;

	if (unlikely(!filp)) {
		aae_pr_err("filp is null");
		return -1;
	}

	if (unlikely(!argp)) {
		aae_pr_err("argp is null");
		return -EINVAL;
	}

	process_data = (struct aae_res_process_data *)filp->private_data;
	if (unlikely(!process_data)) {
		aae_pr_err("process_data is null");
		return -EINVAL;
	}

	aae_pr_debug("cmd=%#x tgid=%d", cmd, current->tgid);
	switch (cmd) {
	case RES_REGISTER_TYPES:
		mutex_lock(&g_aae_rm_dev->process_data_lock);
		ret = aae_res_register_types(process_data, argp);
		mutex_unlock(&g_aae_rm_dev->process_data_lock);
		return ret;
	default:
		return aae_res_ioctl_resource(process_data, cmd, argp);
	}
}

static struct file_operations aae_res_fops = {
	.owner = THIS_MODULE,
	.open = aae_res_open,
	.release = aae_res_release,
	.unlocked_ioctl = aae_res_ioctl,
	.compat_ioctl =  aae_res_ioctl,
};

static void aae_res_create_chrdev(struct aae_res_mgr *rm_dev)
{
	int32_t ret;

	rm_dev->rm_chrdev.chr_class = class_create(THIS_MODULE, rm_dev->pdev->dev.of_node->name);
	if (IS_ERR(rm_dev->rm_chrdev.chr_class)) {
		ret = PTR_ERR(rm_dev->rm_chrdev.chr_class);
		aae_pr_err("Unable to create fb class; errno=%d", ret);
		rm_dev->rm_chrdev.chr_class = NULL;
	}
	rm_dev->rm_chrdev.name = AAE_RES_DEV_NAME;
	rm_dev->rm_chrdev.fops = &aae_res_fops;
	rm_dev->rm_chrdev.drv_data = rm_dev;

	ukmd_create_chrdev(&rm_dev->rm_chrdev);
#ifdef CONFIG_AKMD_DEBUG_ENABLE
	ukmd_create_attrs(rm_dev->rm_chrdev.chr_dev, rm_attrs, ARRAY_SIZE(rm_attrs));
#endif
}

static void aae_res_init_data(struct aae_res_data *data)
{
	data->offline_scene_ids = aae_config_get_offline_scene_ids(&data->offline_scene_id_count);
}

static void aae_res_init_resource_list(struct list_head *res_head, struct aae_res_data *rm_data)
{
	struct aae_res_resouce_node *_node_ = NULL;
	struct aae_res_resouce_node *res_node = NULL;

	INIT_LIST_HEAD(res_head);

	aae_res_register_dvfs(res_head);
	aae_res_register_mapper(res_head);
	aae_res_register_scene_id_mgr(res_head);
	aae_res_register_scene_mgr(res_head);
	aae_res_register_task_binder(res_head);
	aae_res_register_ddr_dvfs(res_head);

	list_for_each_entry_safe(res_node, _node_, res_head, list_node) {
		if (!res_node)
			continue;

		if (res_node->init) {
			res_node->data = res_node->init(rm_data);
			if (!res_node->data)
				aae_pr_warn("init resource node data fail, res_type=0x%llx", res_node->res_type);
		}
	}
}

static void aae_res_deinit_resouce_list(struct list_head *res_head)
{
	struct aae_res_resouce_node *_node_ = NULL;
	struct aae_res_resouce_node *res_node = NULL;

	list_for_each_entry_safe(res_node, _node_, res_head, list_node) {
		if (!res_node)
			continue;

		list_del(&res_node->list_node);
		if (res_node->deinit)
			res_node->deinit(res_node->data);

		kfree(res_node);
		res_node = NULL;
	}
}

static int32_t aae_res_parse_dt(struct aae_res_mgr *rm_dev)
{
	int32_t ret;
	struct platform_device *pdev = rm_dev->pdev;

	rm_dev->vivobus_regulator = devm_regulator_get(&pdev->dev, "regulator_vivobus");
	if (IS_ERR(rm_dev->vivobus_regulator)) {
		ret = (int32_t)PTR_ERR(rm_dev->vivobus_regulator);
		aae_pr_err("vivobus_regulator error, ret=%d", ret);
		return ret;
	}

	rm_dev->media1_subsys_regulator = devm_regulator_get(&pdev->dev, "regulator_media_subsys");
	if (IS_ERR(rm_dev->media1_subsys_regulator)) {
		ret = (int32_t)PTR_ERR(rm_dev->media1_subsys_regulator);
		aae_pr_err("media1_subsys_regulator error, ret=%d", ret);
		return ret;
	}

	return 0;
}

static int aae_res_probe(struct platform_device *pdev)
{
	struct aae_res_mgr *rm_dev = NULL;

	if (unlikely(!pdev)) {
		aae_pr_err("pdev is null");
		return -EINVAL;
	}

	aae_pr_warn("%s is probing now!", pdev->name);

	/* 1, read config from dtsi */
	if (aae_res_init_config(pdev)) {
		aae_pr_err("init aae config fail");
		return -1;
	}

	rm_dev = devm_kzalloc(&pdev->dev, sizeof(*rm_dev), GFP_KERNEL);
	if (!rm_dev) {
		aae_pr_err("alloc rm device data fail");
		return -1;
	}
	rm_dev->pdev = pdev;

	if (aae_res_parse_dt(rm_dev) != 0) {
		aae_pr_err("aae_res_mgr parse dt failed!");
		devm_kfree(&pdev->dev, rm_dev);
		return -EINVAL;
	}

	aae_res_init_data(&rm_dev->data);
	aae_res_init_resource_list(&rm_dev->resource_list, &rm_dev->data);
	INIT_LIST_HEAD(&rm_dev->process_data_list);
	mutex_init(&rm_dev->process_data_lock);

	mutex_init(&rm_dev->tcu_power_lock);
	rm_dev->tcu_power_refcount = 0;

	/* create chrdev */
	aae_res_create_chrdev(rm_dev);

	dev_set_drvdata(&pdev->dev, rm_dev);
	g_aae_rm_dev = rm_dev;

	aae_pr_warn("%s probe succ!", pdev->name);

	return 0;
}

static int32_t aae_res_remove(struct platform_device *pdev)
{
	struct aae_res_mgr *rm_dev = NULL;

	rm_dev = platform_get_drvdata(pdev);
	if (!rm_dev)
		return -1;

	aae_res_deinit_resouce_list(&rm_dev->resource_list);
	ukmd_destroy_chrdev(&rm_dev->rm_chrdev);
	g_aae_rm_dev = NULL;

	return 0;
}

int32_t aae_res_mgr_tcu_suspend(void)
{
	struct aae_res_mgr *rm_dev = g_aae_rm_dev;
	if (unlikely(!rm_dev)) {
		aae_pr_err("rm_dev is null");
		return -1;
	}

	tcu_power_suspend(rm_dev);

	aae_pr_info("%s suspend succ!", rm_dev->pdev->name);
	return 0;
}

int32_t aae_res_mgr_tcu_resume(void)
{
	struct aae_res_mgr *rm_dev = g_aae_rm_dev;
	if (unlikely(!rm_dev)) {
		aae_pr_err("rm_dev is null");
		return -1;
	}

	tcu_power_resume(rm_dev);

	aae_pr_info("%s resume succ!", rm_dev->pdev->name);
	return 0;
}

#define DTS_COMP_DISP_RM_NAME "akmd,aae_resource"

static const struct of_device_id aae_res_match_table[] = {
	{
		.compatible = DTS_COMP_DISP_RM_NAME,
		.data = NULL,
	},
	{},
};
MODULE_DEVICE_TABLE(of, aae_res_match_table);

static struct platform_driver g_aae_res_driver = {
	.probe = aae_res_probe,
	.remove = aae_res_remove,
	.suspend = NULL,
	.resume = NULL,
	.shutdown = NULL,
	.driver = {
		.name = AAE_RES_DEV_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(aae_res_match_table),
	},
};

static int32_t __init aae_res_register(void)
{
	return platform_driver_register(&g_aae_res_driver);
}

static void __exit aae_res_unregister(void)
{
	platform_driver_unregister(&g_aae_res_driver);
}

module_init(aae_res_register);
module_exit(aae_res_unregister);

MODULE_AUTHOR("Graphics Display");
MODULE_DESCRIPTION("Display AAE Resource Manager Driver");
MODULE_LICENSE("GPL");
