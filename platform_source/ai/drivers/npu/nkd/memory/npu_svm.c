/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * Description:
 */
#include "npu_svm.h"

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

int npu_svm_bind(struct npu_dev_ctx *cur_dev_ctx, pid_t manager_pid, pid_t svm_pid, uint16_t *uid)
{
	int ret = 0;
	int item = 0;
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;
	struct t_svm_manager *svm_manager = NULL;
	struct npu_platform_info *plat_info = NULL;

	cond_return_error(cur_dev_ctx == NULL, -1, "illegal cur_dev_ctx\n");

	plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info failed\n");

	if (manager_pid <= 0 || svm_pid <= 0) {
		npu_drv_err("illegal pid\n");
		return -1;
	}

	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "illegal svm_manager\n");

	mutex_lock(&svm_manager->lock);

	item = npu_check_item_bypid(svm_manager, svm_pid);
	cond_goto_error(item == -1, free_lock, ret, -1, "get item failed\n");

	if (svm_manager->svm_pid_info[item].npu_svm != NULL) {
		npu_drv_info("pid:%d had svm bind task\n", svm_pid);
		ret = 0;
		goto free_lock;
	}

	pid_struct = find_get_pid(svm_pid);
	cond_goto_error(pid_struct == NULL, free_lock, ret, -1, "get pid failed\n");

	task = get_pid_task(pid_struct, PIDTYPE_PID);
	cond_goto_error(task == NULL, free_pid, ret, -1, "get pid task failed\n");

	svm_manager->svm_pid_info[item].npu_svm =
		(void*)mm_svm_bind_task(plat_info->pdev, task, svm_manager->svm_pid_info[item].ssid);
	if (svm_manager->svm_pid_info[item].npu_svm == NULL) {
		npu_drv_err("mm svm bind task failed\n");
		ret = -EBUSY;
		goto free_task;
	}

free_task:
	put_task_struct(task);
free_pid:
	put_pid(pid_struct);

free_lock:
	mutex_unlock(&svm_manager->lock);
	if (ret == 0 && uid != NULL)
		*uid = svm_manager->svm_pid_info[item].ssid;
	return ret;
}

int npu_get_ssid_bypid(u8 devid, pid_t manager_pid, pid_t svm_pid,
	uint16_t *ssid, uint64_t *ttbr, uint64_t *tcr)
{
	int ret = 0;
	int item = 0;
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;
	struct npu_dev_ctx *cur_dev_ctx = NULL;
	struct t_svm_manager *svm_manager = NULL;
	struct npu_platform_info *plat_info = NULL;

	plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info failed\n");

	if (devid >= NPU_DEV_NUM || manager_pid <= 0 || svm_pid <= 0 ||
		ssid == NULL || ttbr == NULL || tcr == NULL) {
		npu_drv_err("illegal input para\n");
		return -1;
	}

	cur_dev_ctx = get_dev_ctx_by_id(devid);
	cond_return_error(cur_dev_ctx == NULL, -1, "illegal cur_dev_ctx\n");

	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "illegal svm_manager\n");

	mutex_lock(&svm_manager->lock);

	item = npu_check_item_bypid(svm_manager, svm_pid);
	cond_goto_error(item == -1, free_resource, ret, -1, "get item failed\n");

	if (svm_manager->svm_pid_info[item].npu_svm == NULL) {
		pid_struct = find_get_pid(svm_pid);
		cond_goto_error(pid_struct == NULL, free_resource, ret, -1, "get pid failed\n");

		task = get_pid_task(pid_struct, PIDTYPE_PID);
		cond_goto_error(task == NULL, free_resource, ret, -1, "get pid task failed\n");

		svm_manager->svm_pid_info[item].npu_svm =
			(void*)mm_svm_bind_task(plat_info->pdev, task, svm_manager->svm_pid_info[item].ssid);
		if (svm_manager->svm_pid_info[item].npu_svm == NULL) {
			npu_drv_err("mm svm bind task failed\n");
			ret = -EBUSY;
			goto free_resource;
		}
	}

	ret = mm_svm_get_ssid(svm_manager->svm_pid_info[item].npu_svm, ssid, ttbr, tcr);
	if (ret != 0)
		npu_drv_err("fail to get ssid, ret = %d\n", ret);

free_resource:
	if (task != NULL)
		put_task_struct(task);
	if (pid_struct != NULL)
		put_pid(pid_struct);
	mutex_unlock(&svm_manager->lock);
	return ret;
}

int npu_svm_flushcache_bypid(struct npu_dev_ctx *cur_dev_ctx, pid_t svm_pid)
{
	int ret;
	struct t_svm_manager *svm_manager = NULL;
	int item = 0;
	struct mm_struct *mm = NULL;
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;

	cond_return_error(svm_pid <= 0, -1, "illegal pid: svm flush cache pid = %d\n", svm_pid);
	cond_return_error(cur_dev_ctx == NULL, -1, "illegal cur_dev_ctx\n");
	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "illegal svm_manager\n");

	mutex_lock(&svm_manager->lock);
	item = npu_check_item_bypid(svm_manager, svm_pid);
	cond_goto_error(item == -1, OUT, ret, -1, "get item failed\n");
	cond_goto_warn(svm_manager->svm_pid_info[item].npu_svm == NULL, OUT, ret, 0, "mm svm has not bind\n");

	npu_drv_warn("mm_svm_flush_cache, svm pid = %d\n", svm_pid);
	pid_struct = find_get_pid(svm_pid);
	cond_goto_error(pid_struct == NULL, OUT, ret, -ESRCH, "pid_struct is null\n");

	task = get_pid_task(pid_struct, PIDTYPE_PID);
	cond_goto_error(task == NULL, FREE_PID, ret, -ESRCH, "get task failed\n");

	mm = get_task_mm(task);
	cond_goto_error(mm == NULL, FREE_TASK, ret, -ESRCH, "get mm failed\n");
	
	ret = mm_svm_flush_cache(mm, 0, 1UL << VA_BITS);
	if (ret != 0)
		npu_drv_err("mm svm flush cache failed, ret = %d\n", ret);

	mmput(mm);
FREE_TASK:
	put_task_struct(task);
FREE_PID:
	put_pid(pid_struct);
OUT:
	mutex_unlock(&svm_manager->lock);
	return ret;
}

int npu_get_ttbr(u64 *ttbr, u64 *tcr, pid_t process_id)
{
	unsigned long asid;
	struct mm_struct *mm = NULL;
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;

	if ((ttbr == NULL) || (tcr == NULL)) {
		npu_drv_err("ttbr or tcr is null\n");
		return -EINVAL;
	}

	pid_struct = find_get_pid(process_id);
	if (pid_struct == NULL) {
		npu_drv_err("pid_struct is null\n");
		return -ESRCH;
	}

	task = get_pid_task(pid_struct, PIDTYPE_PID);
	if (task == NULL) {
		put_pid(pid_struct);
		npu_drv_err("get pid task failed\n");
		return -ESRCH;
	}

	mm = get_task_mm(task);
	if (mm == NULL) {
		put_task_struct(task);
		put_pid(pid_struct);
		npu_drv_err("get mm is null\n");
		return -ESRCH;
	}

	asid = ASID(mm);
	*ttbr = virt_to_phys(mm->pgd) | (asid << 48);
	*tcr  = read_sysreg(tcr_el1);
	npu_drv_debug("pgdaddr:0x:%pK, context:0x%pK, pa:0x%pK\n",
		mm->pgd, (u64 *)(mm->pgd), (void *)(uintptr_t)virt_to_phys(mm->pgd));

	mmput(mm);
	npu_drv_debug("asid:%lu ,ttbr:0x%pK, tcr:0x%pK\n", asid,
		(void *)(uintptr_t)*ttbr, (void *)(uintptr_t)*tcr);

	put_task_struct(task);
	put_pid(pid_struct);
	return 0;
}

static int npu_svm_rebind(struct t_svm_pid_info *item)
{
	int ret = 0;
	struct pid *pid_struct = NULL;
	struct task_struct *task = NULL;
	struct npu_platform_info *plat_info = NULL;

	plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info failed\n");

	if (item->npu_svm == NULL) {
		pid_struct = find_get_pid(item->svm_pid);
		cond_goto_error(pid_struct == NULL, free_resource, ret, -1, "get pid failed\n");

		task = get_pid_task(pid_struct, PIDTYPE_PID);
		cond_goto_error(task == NULL, free_resource, ret, -1, "get pid task failed\n");

		item->npu_svm =
			(void*)mm_svm_bind_task(plat_info->pdev, task, item->ssid);
		if (item->npu_svm == NULL) {
			npu_drv_err("mm svm bind task failed\n");
			ret = -EBUSY;
			goto free_resource;
		}
	}

free_resource:
	if (task != NULL)
		put_task_struct(task);
	if (pid_struct != NULL)
		put_pid(pid_struct);

	return ret;
}

#ifdef CONFIG_FFRT_UNIFORM_ID
int npu_manager_svm_bind(struct npu_dev_ctx *cur_dev_ctx)
{
	struct t_svm_manager *svm_manager = NULL;
	struct t_svm_pid_info *item = NULL;
	int i;
	int ret = 0;
	cond_return_error(cur_dev_ctx == NULL, -1, "cur_dev_ctx is null\n");
	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "svm manager is null\n");
	mutex_lock(&svm_manager->lock);
	for(i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		item = &svm_manager->svm_pid_info[i];
		if (item->svm_pid > 0 && item->ssid != UINT16_MAX)
			ret += npu_svm_rebind(item);
	}
	mutex_unlock(&svm_manager->lock);
	return ret;
}
#else
int npu_manager_svm_bind(struct npu_dev_ctx *cur_dev_ctx)
{
	struct t_svm_manager *svm_manager = NULL;
	struct t_svm_pid_info *item = NULL;
	int i = 0;
	int ret = 0;
	struct npu_platform_info *plat_info = NULL;

	plat_info = npu_plat_get_info();
	cond_return_error(plat_info == NULL, -1, "get platform info failed\n");

	cond_return_error(cur_dev_ctx == NULL, -1, "cur_dev_ctx is null\n");
	svm_manager = (struct t_svm_manager *)cur_dev_ctx->svm_manager;
	cond_return_error(svm_manager == NULL, -1, "svm manager is null\n");

	mutex_lock(&svm_manager->lock);
	for(i = 0; i < DRVDEV_APP_MAX_NUM; i++) {
		item = &svm_manager->svm_pid_info[i];
		if (item->svm_pid > 0 && 
			svm_manager->svm_pid_info[i].manager_pid == svm_manager->svm_pid_info[i].svm_pid)
			ret += npu_svm_rebind(item);
	}
	mutex_unlock(&svm_manager->lock);

	return ret;
}
#endif
