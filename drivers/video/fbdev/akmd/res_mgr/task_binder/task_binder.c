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
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/iommu/mm_svm.h>
#include <linux/regulator/consumer.h>
#include <linux/iommu/mm_iommu.h>
#include <soc_media_pmctrl_interface.h>
#include <securec.h>
#include <platform_include/display/akmd/akmd_aae.h>
#include "ffts_proc_block.h"
#include "uniform_id.h"
#include "task_binder/task_binder.h"
#include "aae_res_mgr.h"
#include "akmd_log.h"
#include "tcu_power_mgr.h"
#include "aae_config_utils.h"
#include "ukmd_utils.h"

#define AAE_POWER_OFF_TIMEOUT 6000 /* 300ms */
#define AAE_PWR_STAT_MASK 0x3
enum {
    AAE_PWR_ON     = 0x0,
    AAE_PWR_ONING  = 0x1,
    AAE_PWR_OFF    = 0x2,
    AAE_PWR_OFFING = 0x3,
};

static void task_binder_release(void *data, int32_t tgid);

static struct aae_binder_info_node *get_binder_info_node(struct list_head *task_info_head,
	int32_t tgid)
{
	struct aae_binder_info_node *user_node = NULL;
	struct aae_binder_info_node *_u_node_ = NULL;

	list_for_each_entry_safe(user_node, _u_node_, task_info_head, info_head) {
		if (unlikely(!user_node))
			continue;

		if (user_node->user_tgid == tgid)
			return user_node;
	}
	return NULL;
}

static bool is_ssid_invalid(uint16_t ssid) {
	return ssid < SSID_ASSIGN_MIN || ssid >= SSID_ASSIGN_MAX;
}

static int32_t copy_uid_to_user(struct aae_binder_info_node *info_node, void __user *argp)
{
	struct aae_task aumd_task = {0};

	aumd_task.uid = info_node->user_ssid;
	if (copy_to_user(argp, &aumd_task, sizeof(aumd_task)) != 0) {
		return -1;
	}

	return 0;
}

static int32_t tcu_power_on(struct aae_task_binder *task_binder)
{
	int32_t ret = 0;
	struct aae_res_mgr *rm_dev = NULL;
	aae_pr_info("+");
	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		return -1;

	ret = tcu_power_on_vote(rm_dev);
	aae_pr_info("tcu_power_ref_count: %d, tcu_power_status: %d\n",
		rm_dev->tcu_power_refcount, rm_dev->tcu_power_status);
	aae_pr_info("-");
	return ret;
}

static int32_t tcu_power_off(struct aae_task_binder *task_binder)
{
	struct aae_res_mgr *rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		return -1;

	if (!queue_work(task_binder->tcu_poweroff_wq, &(task_binder->tcu_poweroff_work))) {
		aae_pr_warn("queue tcu poweroff work failed for process %d, so we poweroff tcu immediately", current->tgid);
		tcu_power_off_vote(rm_dev);
		aae_pr_info("tcu_power_ref_count: %d, tcu_power_status: %d\n",
			rm_dev->tcu_power_refcount, rm_dev->tcu_power_status);
	}
	return 0;
}

#ifdef CONFIG_LDK_SVM
static int32_t do_mm_svm_bind_task_ohos(struct device *dev, pid_t tgid, struct aae_binder_info_node *info_node)
{
	int32_t ret = 0;
	info_node->aae_svm = mm_svm_bind_task(dev, (u32)tgid, info_node->user_ssid);
	if (!info_node->aae_svm) {
		aae_pr_err("bind task failed, ssid = %d tgid = %d", info_node->user_ssid, tgid);
		ret = -1;
	}
	return ret;
}
#else
static int32_t do_mm_svm_bind_task(struct device *dev, pid_t tgid, struct aae_binder_info_node *info_node)
{
	struct task_struct *task = NULL;
	struct pid *pid_struct = NULL;
	int32_t ret = 0;

	pid_struct = find_get_pid(tgid);
	if (!pid_struct) {
		aae_pr_err("get pid struct failed, ssid = %d tgid = %d", info_node->user_ssid, tgid);
		ret = -1;
		goto out;
	}

	task = get_pid_task(pid_struct, PIDTYPE_PID);
	if (!task) {
		aae_pr_err("get pid struct failed, ssid = %d tgid = %d", info_node->user_ssid, tgid);
		ret = -1;
		goto out_put_pid;
	}

	info_node->aae_svm = mm_svm_bind_task(dev, task, info_node->user_ssid);
	if (!info_node->aae_svm) {
		aae_pr_err("bind task failed, ssid = %d tgid = %d", info_node->user_ssid, tgid);
		ret = -1;
	}

	put_task_struct(task);
out_put_pid:
	put_pid(pid_struct);
out:
	return ret;
}
#endif

static void print_ssid(struct aae_task_binder *task_binder)
{
	uint16_t cnt = 0;
	struct aae_binder_info_node *bind_info_node = NULL;
	struct aae_binder_info_node *_bind_info_node_ = NULL;

	aae_pr_err("The current tasks for binding the shared page table are as follows:");
	list_for_each_entry_safe(bind_info_node, _bind_info_node_, &task_binder->task_info_head, info_head) {
		aae_pr_err("%hu ssid: %hu tgid is: %d", cnt, bind_info_node->user_ssid, bind_info_node->user_tgid);
		cnt++;
	}
	return;
}

static int32_t bind_task(pid_t tgid, struct aae_task_binder *task_binder, void __user *argp)
{
	int32_t ret = 0;
	struct aae_binder_info_node *info_node;
	struct aae_res_mgr *rm_dev = NULL;

	if (!task_binder || !task_binder->pdev) {
		aae_pr_err("task_binder or task_binder->pdev is null!");
		return -1;
	}
	
	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		aae_pr_warn("get rm_dev failed!");

	down(&task_binder->sem);
	info_node = (struct aae_binder_info_node *)(void *)get_binder_info_node(&task_binder->task_info_head, tgid);
	if (!info_node) {
		if (task_binder->list_len >= BIND_ID_USER_TGID_MAX) {
			aae_pr_err("The process exceeds the maximum limit supported by AAE, and the current number of nodes is %hu.", task_binder->list_len);
			print_ssid(task_binder);
			ret = -EUSERS;
			goto out;
		}

		info_node = kzalloc(sizeof(struct aae_binder_info_node), GFP_KERNEL);
		if (likely(info_node)) {
			info_node->user_tgid = tgid;
			list_add_tail(&info_node->info_head, &task_binder->task_info_head);
			task_binder->list_len++;
		} else {
			aae_pr_err("kzalloc return err!");
			ret = -ENOMEM;
			goto out;
		}
	}
	if (info_node->ref_cnt > 0) {
		info_node->ref_cnt++;
		aae_pr_info("ref_cnt : %d, tgid: %d has binded", info_node->ref_cnt, tgid);
		if (copy_uid_to_user(info_node, argp)) {
			aae_pr_err("copy to user failed");
			ret = -1;
		}
		goto out;
	}

	info_node->user_ssid = ffrt_get_uniform_id(tgid);
	if (is_ssid_invalid(info_node->user_ssid)) {
		aae_pr_err("ssid %u is invalid, tgid = %d", info_node->user_ssid, tgid);
		ret = -1;
		goto out_free_node;
	}

	ret = tcu_power_on(task_binder);
	if (ret) {
		aae_pr_err("smmu power on failed, tgid = %d", tgid);
		goto out_free_node;
	}

#ifdef CONFIG_LDK_SVM
	ret = do_mm_svm_bind_task_ohos(&(task_binder->pdev->dev), tgid, info_node);
#else
	ret = do_mm_svm_bind_task(&(task_binder->pdev->dev), tgid, info_node);
#endif
	if (ret) {
		aae_pr_err("bind task failed, ssid: %u, tgid = %d", info_node->user_ssid, tgid);
		goto out_power_off_tcu;
	}

	if (copy_uid_to_user(info_node, argp) != 0) {
		aae_pr_err("ssid copy to user failed");
		ret = -1;
		goto out_unbind_task;
	}

	ret = ffts_proc_release_register(FFTS_HW_AAE, task_binder_release, task_binder, tgid);
	if (ret) {
		aae_pr_err("regis ffts task bind release failed,  ssid = %u tgid = %d", info_node->user_ssid, tgid);
		ret = -1;
		goto out_unbind_task;
	}
	aae_pr_info("ffts_proc_release_register succ, tgid: %d", tgid);

	info_node->ref_cnt++;

	aae_pr_info("bind task success, ref_cnt: %d, ssid: %u, tgid: %d", info_node->ref_cnt, info_node->user_ssid, tgid);
	goto out;

out_unbind_task:
	mm_svm_unbind_task(info_node->aae_svm);
out_power_off_tcu:
	tcu_power_off(task_binder);
out_free_node:
	list_del(&info_node->info_head);
	task_binder->list_len--;
	kfree(info_node);
out:
	up(&task_binder->sem);
	return ret;
}

static int32_t unbind_task(pid_t tgid, struct aae_task_binder *task_binder, bool is_final_release)
{
	int32_t ret = 0;
	struct aae_binder_info_node *info_node;
	struct aae_res_mgr *rm_dev = NULL;

	if (!task_binder->pdev) {
		aae_pr_err("task_binder->pdev is null!");
		return -1;
	}

	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		aae_pr_warn("get rm_dev failed!");

	down(&task_binder->sem);
	info_node = (struct aae_binder_info_node*)get_binder_info_node(&task_binder->task_info_head, tgid);
	if (unlikely(!info_node)) {
		aae_pr_warn("cannot find node with tgid=%d", tgid);
		ret = -1;
		goto out;
	}

	if (info_node->ref_cnt <= 0) {
		aae_pr_warn("ref_cnt : %d, tgid: %d has not been binded", info_node->ref_cnt, tgid);
		ret = -1;
		goto out;
	}

	if (!is_final_release) { /* if not final release, we need to check ref_cnt */
		if (info_node->ref_cnt > 1) {
			info_node->ref_cnt--;
			aae_pr_info("ref_cnt : %d, tgid: %d ", info_node->ref_cnt, tgid);
			ret = 0;
			goto out;
		}
	}

	if (info_node->aae_svm == NULL) {
		aae_pr_err("aae_svm is NULL, tgid = %d", tgid);
		ret = -1;
		goto out_free_node;
	}

	mm_svm_unbind_task(info_node->aae_svm);

	tcu_power_off(task_binder);

	info_node->ref_cnt--;
	aae_pr_info("unbind task success, ref_cnt: %d, substream_id: %u, tgid: %d", info_node->ref_cnt, info_node->user_ssid, tgid);

out_free_node:
	list_del(&info_node->info_head);
	task_binder->list_len--;
	kfree(info_node);
out:
	up(&task_binder->sem);
	return ret;
}

static void tcu_poweroff_work_handler(struct work_struct *work)
{
	struct aae_task_binder *task_binder = NULL;
	struct aae_res_mgr *rm_dev = NULL;
	char __iomem *media1_pmctrl_base = aae_config_get_ip_base(AKMD_IP_BASE_MEDIA1_PMCTRL);
	uint32_t aae_power_stat = 0;
	uint32_t delay_count = 0;

	aae_check_and_no_retval(!media1_pmctrl_base, err, "media1_pmctrl_base is NULL!");

	task_binder = container_of(work, struct aae_task_binder, tcu_poweroff_work);
	aae_check_and_no_retval(!task_binder, err, "task_binder is null!");

	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		return;

	/* wait aae power off if ready to power off, over 300 ms the hardware maybe abnormal */
	do {
		aae_power_stat = inp32(SOC_MEDIA_PMCTRL_CURR_VOTE_POWER_STAT_ADDR(media1_pmctrl_base));
		if ((aae_power_stat & AAE_PWR_STAT_MASK) == AAE_PWR_OFF)
			break;

		udelay(50);
		delay_count++;
	} while (tcu_ready_to_power_off(rm_dev) && delay_count < AAE_POWER_OFF_TIMEOUT);

	if (delay_count >= AAE_POWER_OFF_TIMEOUT) {
		aae_pr_err("media1 subsys maybe blocking when aae power off, aae_power_stat = 0x%x", aae_power_stat);
	}

	tcu_power_off_vote(rm_dev);
	aae_pr_info("tcu_power_ref_count: %d, tcu_power_status: %d\n",
		rm_dev->tcu_power_refcount, rm_dev->tcu_power_status);
}

static void *task_binder_init(struct aae_res_data *rm_data)
{
	struct aae_res_mgr *rm = NULL;
	struct aae_task_binder *task_binder = NULL;

	rm = container_of(rm_data, struct aae_res_mgr, data);

	task_binder = kzalloc(sizeof(struct aae_task_binder), GFP_KERNEL);
	if (task_binder == NULL)
		return NULL;

	task_binder->pdev = rm->pdev;
	sema_init(&task_binder->sem, 1);
	INIT_LIST_HEAD(&task_binder->task_info_head);
	task_binder->list_len = 0;

	task_binder->tcu_poweroff_wq = create_singlethread_workqueue("tcu_poweroff_wq");
	INIT_WORK(&task_binder->tcu_poweroff_work, tcu_poweroff_work_handler);

	aae_pr_info("task_binder_init called");
	return task_binder;
}

static void task_binder_deinit(void *data)
{
	struct aae_task_binder *task_binder = (struct aae_task_binder *)data;

	if (task_binder == NULL)
		return;

	destroy_workqueue(task_binder->tcu_poweroff_wq);
	kfree(task_binder);
	aae_pr_info("task_binder_deinit called");
}

static long task_binder_ioctl(struct aae_res_resouce_node *res_node, uint32_t cmd, void __user *argp)
{
	pid_t pid;

	if (!res_node || !res_node->data || !argp) {
		aae_pr_err("res_node or node data or argp is NULL");
		return -EINVAL;
	}

	pid = current->tgid;
	aae_pr_info("cmd %#x, tgid %d", cmd, pid);

	switch (cmd) {
	case RES_BIND_TASK:
		return bind_task(pid, res_node->data, argp);
	case RES_UNBIND_TASK:
		return unbind_task(pid, res_node->data, false /* is_final_release */);
	default:
		aae_pr_debug("task binder unsupport cmd, need processed by other module");
		return 1;
	}

	return 0;
}

static void task_binder_release(void *data, int32_t tgid)
{
	struct aae_task_binder *task_binder;

	task_binder = (struct aae_task_binder *)data;
	aae_check_and_no_retval(!task_binder, err, "task_binder is nullptr!");

	unbind_task(tgid, task_binder, true /* is_final_release */);
}

#ifdef CONFIG_AKMD_DEBUG_ENABLE
static int get_tcu_power_ref_count(struct aae_task_binder *task_binder)
{
	struct aae_res_mgr *rm_dev = NULL;
	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		return -1;

	return rm_dev->tcu_power_refcount;
}

static int get_tcu_power_status(struct aae_task_binder *task_binder)
{
	struct aae_res_mgr *rm_dev = NULL;
	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		return -1;

	return rm_dev->tcu_power_status;
}

static ssize_t aae_binder_info_node_show(struct aae_task_binder *task_binder, char *buf)
{
	struct aae_binder_info_node *user_node = NULL;
	struct aae_binder_info_node *_u_node_ = NULL;
	ssize_t ret = 0;

	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "task_binder_info_node:\n");
	list_for_each_entry_safe(user_node, _u_node_, &task_binder->task_info_head, info_head) {
		if (unlikely(!user_node))
			continue;

		ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "tgid = %d, ssid = %u, ref_cnt = %d\n",
			user_node->user_tgid, user_node->user_ssid, user_node->ref_cnt);
	}
	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "----------------------\n");

	return ret;
}

static ssize_t tcu_power_status_show(struct aae_task_binder *task_binder, char *buf)
{
	ssize_t ret = 0;
	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "tcu_power_status:\n");
	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "tcu_power_ref_count: %d, tcu_power_status: %d\n",
		get_tcu_power_ref_count(task_binder), get_tcu_power_status(task_binder));
	ret += scnprintf(buf + ret, PAGE_SIZE - ret - 1, "----------------------\n");

	return ret;
}

static ssize_t task_binder_show(void *data, char *buf)
{
	struct aae_task_binder *task_binder = (struct aae_task_binder *)data;
	ssize_t ret = 0;

	if (unlikely(data == NULL || buf == NULL)) {
		aae_pr_err("data or buf is null");
		return -ENODEV;
	}

	ret += aae_binder_info_node_show(task_binder, buf + ret);
	ret += tcu_power_status_show(task_binder, buf + ret);

	return ret;
}

static ssize_t task_binder_store(void *data, const char *buf, size_t count)
{
	struct aae_task_binder *task_binder = (struct aae_task_binder *)data;
	struct aae_res_mgr *rm_dev = NULL;
	const char *str;

	rm_dev = platform_get_drvdata(task_binder->pdev);
	if (!rm_dev)
		return -1;

	str = strstr(buf, "tcu_power_on");
	if (str != NULL) {
		aae_pr_info("tcu_power_on");
		tcu_power_on_vote(rm_dev);
		return count;
	}

	str = strstr(buf, "tcu_power_off");
	if (str != NULL) {
		aae_pr_info("tcu_power_off");
		tcu_power_off_vote(rm_dev);
		return count;
	}

	str = strstr(buf, "tcu_power_suspend");
	if (str != NULL) {
		aae_pr_info("tcu_power_suspend");
		tcu_power_suspend(rm_dev);
		return count;
	}

	str = strstr(buf, "tcu_power_resume");
	if (str != NULL) {
		aae_pr_info("tcu_power_resume");
		tcu_power_resume(rm_dev);
		return count;
	}

	str = strstr(buf, "task_binder_vote_tcu_power_on");
	if (str != NULL) {
		aae_pr_info("task_binder_vote_tcu_power_on");
		tcu_power_on(task_binder);
		return count;
	}

	str = strstr(buf, "task_binder_vote_tcu_power_off");
	if (str != NULL) {
		aae_pr_info("task_binder_vote_tcu_power_off");
		tcu_power_off(task_binder);
		return count;
	}

	aae_pr_info("invaild cmd");

	return count;
}
#endif

void aae_res_register_task_binder(struct list_head *resource_head)
{
	struct aae_res_resouce_node *task_binder_node = NULL;
	if (!resource_head)
		return;

	task_binder_node = kzalloc(sizeof(struct aae_res_resouce_node), GFP_KERNEL);
	if (!task_binder_node)
		return;

	task_binder_node->res_type = RES_TASK_BINDER;

	task_binder_node->init = task_binder_init;
	task_binder_node->deinit = task_binder_deinit;
	task_binder_node->ioctl = task_binder_ioctl;
#ifdef CONFIG_AKMD_DEBUG_ENABLE
	task_binder_node->show = task_binder_show;
	task_binder_node->store = task_binder_store;
#endif

	list_add_tail(&task_binder_node->list_node, resource_head);
	aae_pr_info("aae_res_register_task_binder success!");
}