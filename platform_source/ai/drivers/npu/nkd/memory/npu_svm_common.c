/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description:
 */

#include "npu_svm_common.h"
#include <linux/err.h>
#include <linux/iommu.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/iommu/mm_iommu.h>
#include <linux/pid.h>
#include <linux/iommu/mm_svm.h>
#include <linux/sched/task.h>
#include <securec.h>
#include <linux/time.h>
#include <linux/delay.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0))
#include <linux/sched/mm.h>
#endif

#include "mm_smmu.h"
#include "npu_platform.h"
#include "npu_log.h"
#ifdef CONFIG_FFRT_UNIFORM_ID
#include "uniform_id.h"
#endif
#include "npu_proc_ctx.h"

#define NUP_SSID_START 32


int npu_svm_manager_init(u8 devid)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;
	int i;

	if (devid >= NPU_DEV_NUM) {
		npu_drv_err("illegal npu dev id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	if (cur_dev_ctx == NULL) {
		npu_drv_err("cur_dev_ctx is null\n");
		return -1;
	}

	svm_manager = kmalloc(sizeof(struct t_svm_manager), GFP_KERNEL);
	if (svm_manager == NULL) {
		npu_drv_err("no sys mem to alloc svm manager\n");
		return -ENOMEM;
	}
	(void)memset_s(svm_manager, sizeof(struct t_svm_manager), 0x0,
		sizeof(struct t_svm_manager));
	for (i = 0; i < DRVDEV_APP_MAX_NUM; i++)
		svm_manager->svm_pid_info[i].ssid = UINT16_MAX;
	cur_dev_ctx->svm_manager = (void *)svm_manager;
	mutex_init(&svm_manager->lock);
#ifdef CONFIG_NPU_ASSIGN_SSID
	bitmap_zero(svm_manager->npu_ssid_bitmap, NPU_SSID_NUM);
	mutex_init(&svm_manager->npu_ssid_assign_lock);
#endif
	return 0;
}

#ifdef CONFIG_NPU_ASSIGN_SSID
static uint16_t npu_assign_ssid(struct t_svm_manager *svm_manager)
{
	unsigned long flags;
	unsigned long i = 0;
	mutex_lock(&svm_manager->npu_ssid_assign_lock);
	i = (uint16_t)find_first_zero_bit(svm_manager->npu_ssid_bitmap, NPU_SSID_NUM);
	if (i < NPU_SSID_NUM) {
		set_bit(i, svm_manager->npu_ssid_bitmap);
    } else {
        npu_drv_err("no available ssid\n");
	}
	mutex_unlock(&svm_manager->npu_ssid_assign_lock);
	i = i + NUP_SSID_START;
	return i;
}

static int npu_free_ssid(struct t_svm_manager *svm_manager, uint16_t ssid)
{
	int i = 0;
	unsigned long lock_flag = 0;
	if ((ssid < NUP_SSID_START) || (ssid >= (NPU_SSID_NUM + NUP_SSID_START))) {
		npu_drv_err("ssid is invalid\n");
        return -1;
    }
	mutex_lock(&svm_manager->npu_ssid_assign_lock);
	i = (int)(ssid - NUP_SSID_START);
    bitmap_clear(svm_manager->npu_ssid_bitmap, (uint32_t)i, 1);
	mutex_unlock(&svm_manager->npu_ssid_assign_lock);
	return 0;
}
#endif

#ifdef CONFIG_FFRT_UNIFORM_ID
static int npu_check_item_ssid(struct t_svm_manager *svm_manager, pid_t svm_pid, uint16_t ssid)
{
	int i;
	if(ssid == UINT16_MAX) 
		return 0;

	for (i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		if(svm_manager->svm_pid_info[i].ssid == ssid && svm_manager->svm_pid_info[i].svm_pid != svm_pid) {
			npu_drv_err("uid %u is already bind svm_pid = %d, new svm_pid = %d\n",
				ssid, svm_manager->svm_pid_info[i].svm_pid, svm_pid);
			return -1;
		}
	}

	return 0;
}
#endif

static int npu_get_item_bypid(struct t_svm_manager *svm_manager,
	pid_t svm_pid)
{
	// if find the item, return its index,
	// otherwise return the first empty item.
	int i;
	int j = -1;

	for (i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		if (svm_manager->svm_pid_info[i].svm_pid == svm_pid)
			break;
		if (svm_manager->svm_pid_info[i].manager_pid == 0 && j < 0)
			j = i;
	}
	return i < DRVDEV_APP_MAX_NUM ? i : j;
}

int npu_check_item_bypid(struct t_svm_manager *svm_manager,
	pid_t svm_pid)
{
	int i;

	for (i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		if (svm_manager->svm_pid_info[i].svm_pid == svm_pid)
			return i;
	}
	return -1;
}

int npu_svm_unbind(u8 devid, pid_t svm_pid)
{
	int item = 0;
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	cond_return_error(cur_dev_ctx == NULL, -1, "illegal cur_dev_ctx\n");

	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "illegal svm_manager\n");

	mutex_lock(&svm_manager->lock);

	item = npu_check_item_bypid(svm_manager, svm_pid);
	if (item == -1) {
		mutex_unlock(&svm_manager->lock);
		npu_drv_warn("not find item, svm_pid=%d\n", svm_pid);
		return 0;
	}

	if (svm_manager->svm_pid_info[item].npu_svm != NULL) {
		mm_svm_unbind_task(svm_manager->svm_pid_info[item].npu_svm);
		svm_manager->svm_pid_info[item].npu_svm = NULL;
		npu_drv_warn("unbind item, mnt_pid=%d svm_pid=%d",
			svm_manager->svm_pid_info[item].manager_pid, svm_pid);
	}

	mutex_unlock(&svm_manager->lock);
	return 0;
}

// app process:called by CreateProcess(Runtime)
// AicpServer:called by open manager device
// 1. item  should not exist
// 2. insert a item, and set flag
int npu_insert_item_bypid(u8 devid, pid_t manager_pid, pid_t ori_pid, pid_t svm_pid)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;
	int i;
	int ret = 0;

#ifdef CONFIG_MM_SVM
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;
#endif
#ifdef CONFIG_FFRT_UNIFORM_ID
	uint16_t ssid = 0;
#endif

	cond_return_error(manager_pid <= 0 || ori_pid <= 0 || svm_pid <= 0, -1,
		"illegal manager_pid=%d, ori_pid=%d, svm_pid=%d\n", manager_pid, ori_pid, svm_pid);
	cond_return_error(devid >= NPU_DEV_NUM, -1, "illegal npu dev id, devid=%u\n", devid);

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	cond_return_error(cur_dev_ctx == NULL, -1, "cur_dev_ctx is null\n");

	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "illegal svm_manager\n");

	mutex_lock(&svm_manager->lock);

#ifdef CONFIG_FFRT_UNIFORM_ID
	ssid = ffrt_get_uniform_id(svm_pid);
	ret = npu_check_item_ssid(svm_manager, svm_pid, ssid);
	if (ret < 0) {
		mutex_unlock(&svm_manager->lock);
		return ret;
	}
#endif

	i = npu_get_item_bypid(svm_manager, svm_pid);
	if (i < 0) {
		// table is full
		npu_drv_err("svm manager table is full\n");
		ret = -1;
		goto Complete;
	}
	if (svm_manager->svm_pid_info[i].manager_pid == 0) {
#ifdef CONFIG_MM_SVM
		// only kirin990 and denver enabled CONFIG_MM_SVM, other platforms do not need mm_svm_flag_set
		pid_struct = find_get_pid(svm_pid);
		if (pid_struct == NULL) {
			npu_drv_err("find get pid failed, svm_pid = %d\n", svm_pid);
			ret = -1;
			goto Complete;
		}
		task = get_pid_task(pid_struct, PIDTYPE_PID);
		if (task == NULL) {
			npu_drv_err("get pid task failed, svm_pid = %d\n", svm_pid);
			ret = -1;
			goto Complete;
		}
		if (task->tgid != svm_pid) {
			npu_drv_err("the svm pid %d is not tgid %d\n", svm_pid, task->tgid);
			ret = -1;
			goto Complete;
		}
		ret = mm_svm_flag_set(task, 1);
		if (ret != 0) {
			npu_drv_err("mm svm flag set failed\n");
			goto Complete;
		}
#endif
		svm_manager->svm_pid_info[i].manager_pid = manager_pid;
		svm_manager->svm_pid_info[i].svm_pid = svm_pid;
		// save original pid because when client die we cannot get rootpid
		svm_manager->svm_pid_info[i].ori_pid = ori_pid;
#ifdef CONFIG_FFRT_UNIFORM_ID
		svm_manager->svm_pid_info[i].ssid = ssid;
#elif defined CONFIG_NPU_ASSIGN_SSID
		svm_manager->svm_pid_info[i].ssid = npu_assign_ssid(svm_manager);
#else
		svm_manager->svm_pid_info[i].ssid = UINT16_MAX;
#endif
		svm_manager->item_num++;

		npu_drv_warn("insert a new item, manager_pid=%d, ori_pid=%d, svm_pid=%d, item_num=%u",
			manager_pid, ori_pid, svm_pid, svm_manager->item_num);
	} else {
		npu_drv_err("the pid is existed, exe_p_pid=%d, manager_pid=%d, svm_pid=%d\n",
			svm_manager->svm_pid_info[i].manager_pid, manager_pid, svm_pid);
		ret = -1;
		goto Complete;
	}

Complete:
#ifdef CONFIG_MM_SVM
	if (task != NULL)
		put_task_struct(task);
	if (pid_struct != NULL)
		put_pid(pid_struct);
#endif

	mutex_unlock(&svm_manager->lock);
	return ret;
}

// for app process
// 1. item should exist
// 2. unbind + unsetflag + delete item
int npu_release_item_bypid(u8 devid, pid_t manager_pid, pid_t svm_pid)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;
#ifdef CONFIG_MM_SVM
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;
#endif
	int ret = 0;
	int i;

	cond_return_error(manager_pid <= 0 || svm_pid <= 0, -1,
		"illegal manager_pid=%d, svm_pid=%d\n", manager_pid, svm_pid);
	cond_return_error(devid >= NPU_DEV_NUM, -1, "illegal npu dev id, devid=%u\n", devid);

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	cond_return_error(cur_dev_ctx == NULL, -1, "cur_dev_ctx is null\n");

	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "illegal svm_manager\n");

	mutex_lock(&svm_manager->lock);
	i = npu_check_item_bypid(svm_manager, svm_pid);
	if (i < 0 || svm_manager->svm_pid_info[i].manager_pid != manager_pid) {
		npu_drv_err("pid is invalid, the manager_pid=%d, svm_pid=%d, i=%d \n",
			manager_pid, svm_pid, i);
		goto Complete;
	}
	// unbind the svm
	if (svm_manager->svm_pid_info[i].npu_svm) {
		mm_svm_unbind_task(svm_manager->svm_pid_info[i].npu_svm);
		svm_manager->svm_pid_info[i].npu_svm = NULL;
	}

	// delete the item
#ifdef CONFIG_NPU_ASSIGN_SSID
	(void)npu_free_ssid(svm_manager, svm_manager->svm_pid_info[i].ssid);
#endif
	svm_manager->svm_pid_info[i].manager_pid = 0;
	svm_manager->svm_pid_info[i].ori_pid = 0;
	svm_manager->svm_pid_info[i].svm_pid = 0;
	svm_manager->svm_pid_info[i].ssid = UINT16_MAX;
	svm_manager->item_num--;
	npu_drv_warn("delete a new item, manager_pid=%d, svm_pid=%d, item_num=%u",
		manager_pid, svm_pid, svm_manager->item_num);

	// unsetflag, ai client exit first, then call api rtProcessDestory, so pid is invalid
#ifdef CONFIG_MM_SVM
	pid_struct = find_get_pid(svm_pid);
	if (pid_struct == NULL) {
		npu_drv_warn("pid_struct is null, pid = %d", svm_pid);
		goto Complete;
	}
	task = get_pid_task(pid_struct, PIDTYPE_PID);
	if (task == NULL) {
		npu_drv_warn("pid task is null, pid = %d", svm_pid);
		goto Pid_out;
	}
	mm_svm_flag_set(task, 0);
	put_task_struct(task);

Pid_out:
	put_pid(pid_struct);
#endif

Complete:
	mutex_unlock(&svm_manager->lock);
	return ret;
}

// for current and app process
// if pid == 0, do device clear
// if called by powerdown(flag=0):unbind
// if called by close device(flag=1):
// unbind + (unsetflag + delete item)(exept current->tgid)
int npu_clear_pid_ssid_table(u8 devid, pid_t pid, int flag)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;
#ifdef CONFIG_MM_SVM
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;
#endif
	pid_t svm_pid;
	int i;

	if (devid >= NPU_DEV_NUM) {
		npu_drv_err("illegal npu dev id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	if (cur_dev_ctx == NULL) {
		npu_drv_err("cur_dev_ctx is null\n");
		return -1;
	}
	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;

	mutex_lock(&svm_manager->lock);
	for (i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		svm_pid = svm_manager->svm_pid_info[i].svm_pid;
		if ((svm_manager->svm_pid_info[i].manager_pid != pid) && (pid != 0))
			continue;
		// 1. unbind
		if (svm_manager->svm_pid_info[i].npu_svm != NULL) {
			mm_svm_unbind_task(svm_manager->svm_pid_info[i].npu_svm);
			npu_drv_warn("unbind item, mnt_pid=%d svm_pid=%d",
				svm_manager->svm_pid_info[i].manager_pid, svm_pid);
			svm_manager->svm_pid_info[i].npu_svm = NULL;
		}

		if (flag != 0 && svm_pid != pid) {
#ifdef CONFIG_NPU_ASSIGN_SSID
			(void)npu_free_ssid(svm_manager, svm_manager->svm_pid_info[i].ssid);
#endif
			svm_manager->svm_pid_info[i].manager_pid = 0;
			svm_manager->svm_pid_info[i].svm_pid = 0;
			svm_manager->svm_pid_info[i].ssid = UINT16_MAX;
			svm_manager->item_num--;

			// 2. unset flag + delete item
#ifdef CONFIG_MM_SVM
			pid_struct = find_get_pid(svm_pid);
			if (pid_struct == NULL) {
				npu_drv_warn("find get pid failed\n");
				continue;
			}
			task = get_pid_task(pid_struct, PIDTYPE_PID);
			if (task == NULL) {
				put_pid(pid_struct);
				npu_drv_warn("get pid task failed\n");
				continue;
			}
			mm_svm_flag_set(task, 0);
			put_task_struct(task);
			put_pid(pid_struct);
#endif
		}
	}
	mutex_unlock(&svm_manager->lock);
	npu_drv_warn("clear table when %s", flag == 0 ? "powerdown" :
		"close npu device");
	return 0;
}

int npu_svm_manager_destroy(u8 devid)
{
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;

	if (devid >= NPU_DEV_NUM) {
		npu_drv_err("illegal npu dev id\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	if (cur_dev_ctx == NULL) {
		npu_drv_err("cur_dev_ctx is null\n");
		return -1;
	}

	npu_clear_pid_ssid_table(devid, 0, 1);

	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	mutex_destroy(&svm_manager->lock);
	kfree(svm_manager);
	cur_dev_ctx->svm_manager = NULL;
	return 0;
}

int npu_check_app_pid(struct npu_dev_ctx *cur_dev_ctx, pid_t process_id)
{
	struct t_svm_manager *svm_manager = NULL;
	cond_return_error(cur_dev_ctx == NULL, -1, "cur_dev_ctx is null\n");
	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "svm manager is null\n");
	return npu_check_item_bypid(svm_manager, process_id);
}

int npu_get_server_pid(struct npu_dev_ctx *cur_dev_ctx, pid_t process_id, pid_t *server_id)
{
	struct t_svm_manager *svm_manager = NULL;
	int i = 0;
	cond_return_error(cur_dev_ctx == NULL, -1, "cur_dev_ctx is null\n");
	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "svm manager is null\n");

	for (i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		if (svm_manager->svm_pid_info[i].svm_pid == process_id) {
			*server_id = svm_manager->svm_pid_info[i].manager_pid;
            return 0;
		}
	}
	return -1;
}