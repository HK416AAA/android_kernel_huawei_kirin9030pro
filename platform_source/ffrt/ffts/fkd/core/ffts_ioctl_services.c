/*
 * ffts_ioctl_services.c
 *
 * ffts device ioctl services
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

#include "ffts_ioctl_services.h"

#include <linux/fs.h>

#include "ffts_log.h"
#include "ffts_resource.h"
#include "ffts_proc_ctx.h"
#include "ffts_common.h"
#include "ffts_hw_config.h"
#include "fpd_interface.h"
#include "ffts_dfx_debug.h"

static int ffts_ioctl_get_device_info(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret = 0;
	ffts_device_info_t device_info = {0};
	struct fpd_registry* fpd = get_fpd();

	if (fpd->fpd_set_device_info_mem_size != NULL) {
		ret = fpd->fpd_set_device_info_mem_size(&device_info);
		cond_return_error(ret != 0, -EINVAL, "ffts_get_device_info_mem_size failed\n");
	}
	cond_return_error(ret != 0, -EINVAL, "fpd or fpd_set_device_info_mem_size ptr is null\n");

	ret = ffts_copy_to_user_safe((void __user *)(uintptr_t)arg, &device_info, sizeof(ffts_device_info_t));
	cond_return_error(ret != 0, -EBUSY, "ffts_copy_to_user_safe failed\n");
	return ret;
}

static int ffts_ioctl_get_global_excp_info(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret = 0;
	struct ffts_global_excp_info global_excp_info = {0};

	ret = ffts_get_global_excp_info(proc_ctx->uid, &global_excp_info);
	cond_return_error(ret != 0, -EINVAL, "get ffts global excp info failed, ret= %d\n", ret);

	ret = ffts_copy_to_user_safe((void __user *)(uintptr_t)arg,
		&global_excp_info, sizeof(struct ffts_global_excp_info));
	cond_return_error(ret != 0, -EINVAL, "fail to copy ffts_check_info, ret= %d\n", ret);
	return ret;
}

static bool ffts_is_submit_unit_busy(uint16_t debug_cfg_addr, u16 uid, u16 ffts_tid)
{
	u32 debug_info[4];
	u16 read_uid;
	u16 read_tid;

	ffts_get_whole_debug_info(debug_cfg_addr, debug_info);
	read_uid = ((debug_info[3] & 0x3FF) << 2) | ((debug_info[2] >> 30) & 0x3);
	read_tid = (debug_info[2] >> 14) & 0xFFFF;
	if ((uid == read_uid) && (ffts_tid == read_tid) && ((debug_info[0] & 0x1) == 0)) {
		ffts_drv_warn("uid %u tid %u is submitting", uid, ffts_tid);
		return true;
	}
	return false;
}

static int ffts_ioctl_check_submit_unit_done(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret = 0;
	u16 uid = proc_ctx->uid;
	u16 ffts_tid = proc_ctx->ffts_tid;
	u32 check_result = 0; // 0 for idle, 1 for busy

	if (ffts_is_submit_unit_busy(SUBMIT_PROCESS_UNIT_STATE_0, uid, ffts_tid) ||
		(ffts_is_submit_unit_busy(SUBMIT_PROCESS_UNIT_STATE_1, uid, ffts_tid)))
		check_result = 1;

	ret = ffts_copy_to_user_safe((void __user *)(uintptr_t)arg,	&check_result, sizeof(u32));
	cond_return_error(ret != 0, -EINVAL, "fail to copy pid_tid_info, ret= %d\n", ret);

	return ret;
}

static int ffts_ioctl_get_qos_task_cnt(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret;
	ffts_qos_info_t ffts_qos_info = {0};
	struct fpd_registry* fpd = get_fpd();

	ret = ffts_copy_from_user_safe(&ffts_qos_info, (void __user *)(uintptr_t)arg, sizeof(ffts_qos_info_t));
	cond_return_error(ret != 0 || ffts_qos_info.qos < 0 || ffts_qos_info.qos >= FFTS_QOS_NUM, -EINVAL,
		"ffts ioctl get_qos_task_cnt copy from user error, ret = %d, qos = %d\n", ret, ffts_qos_info.qos);

	ffts_qos_info.qos_task_cnt = 0;
	if (fpd != NULL && fpd->fpd_get_qos_task_cnt != NULL)
		ffts_qos_info.qos_task_cnt = fpd->fpd_get_qos_task_cnt(proc_ctx->uid, (u8)(ffts_qos_info.qos));

	ret = ffts_copy_to_user_safe((void __user *)(uintptr_t)arg, &ffts_qos_info, sizeof(ffts_qos_info_t));
	cond_return_error(ret != 0, -EBUSY, "ffts ioctl get_qos_task_cnt copy to user failed\n");
	return ret;
}

int ffts_ioctl_get_task_status_info(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret = 0;
	struct ffts_task_status_info ffts_task_info = {0};
	struct fpd_registry* fpd = get_fpd();

	if (fpd != NULL && fpd->fpd_get_task_status_info != NULL)
		fpd->fpd_get_task_status_info(proc_ctx->uid, &ffts_task_info);

	ret = ffts_copy_to_user_safe((void __user *)(uintptr_t)arg, &ffts_task_info, sizeof(struct ffts_task_status_info));
	cond_return_error(ret != 0, -EBUSY, "ffts ioctl get_task_status_info copy to user failed\n");
	return ret;
}

static int ffts_ioctl_set_tcb_addr(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret = 0;
	vir_addr_t addr = (vir_addr_t)arg;
	struct fpd_registry* fpd = get_fpd();

	if (addr == 0) {
		ffts_drv_err("set tcb addr is NULL\n");
		return -1;
	}

	if (fpd != NULL && fpd->fpd_set_tcb_procctx_table != NULL) {
		fpd->fpd_set_tcb_procctx_table(proc_ctx->uid, addr);
	} else {
		ffts_drv_err("fpd ptr is NULL\n");
		ret = -EBUSY;
	}

	return ret;
}

int ffts_ioctl_get_dfx_resource_info(struct ffts_proc_ctx *proc_ctx, unsigned long arg)
{
	int ret;
	SOC_FFTS_DFX_TASKCNT_UNION ffts_dfx_taskcnt = {0};
	SOC_FFTS_DFX_VERCNT_UNION ffts_dfx_vercnt = {0};
	SOC_FFTS_DFX_SIGCNT_UNION ffts_dfx_sigcnt = {0};
	ffts_dfx_res_info_t ffts_dfx_res_info = {0};
	vir_addr_t kernel_reg_base = ffts_get_reg_base();
	cond_return_error(kernel_reg_base == 0, -EFAULT, "get reg base failed\n");

	ffts_dfx_taskcnt.value = readl(SOC_FFTS_DFX_TASKCNT_ADDR(kernel_reg_base));
	ffts_dfx_vercnt.value = readl(SOC_FFTS_DFX_VERCNT_ADDR(kernel_reg_base));
	ffts_dfx_sigcnt.value = readl(SOC_FFTS_DFX_SIGCNT_ADDR(kernel_reg_base));

	ffts_dfx_res_info.total_taskcnt = ffts_dfx_taskcnt.reg.taskctx_cnt;
	ffts_dfx_res_info.total_vercnt = ffts_dfx_vercnt.reg.verctx_cnt;
	ffts_dfx_res_info.total_sigcnt = ffts_dfx_sigcnt.reg.sigctx_cnt;

	ret = ffts_copy_to_user_safe((void __user *)(uintptr_t)arg, &ffts_dfx_res_info, sizeof(ffts_dfx_res_info_t));
	cond_return_error(ret != 0, -EBUSY, "ffts ioctl get_dfx_resource_info copy to user failed\n");
	return ret;
}

static int (*ffts_ioctl_call[FFTS_MAX_CMD])(struct ffts_proc_ctx *proc_ctx, unsigned long arg) = {
	[_IOC_NR(FFTS_GET_DEVICE_INFO)] = ffts_ioctl_get_device_info,
	[_IOC_NR(FFTS_GET_GLOBAL_EXCP_INFO)] = ffts_ioctl_get_global_excp_info,
	[_IOC_NR(FFTS_CHECK_SUBMIT_UNIT_DONE)] = ffts_ioctl_check_submit_unit_done,
	[_IOC_NR(FFTS_GET_QOS_TASK_CNT)] = ffts_ioctl_get_qos_task_cnt,
	[_IOC_NR(FFTS_GET_TASK_STATUS_INFO)] = ffts_ioctl_get_task_status_info,
	[_IOC_NR(FFTS_SET_TASK_TCB_INFO)] = ffts_ioctl_set_tcb_addr,
	[_IOC_NR(FFTS_GET_DFX_RES_INFO)] = ffts_ioctl_get_dfx_resource_info,
};

long ffts_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
	int ret;
	struct ffts_proc_ctx *proc_ctx = NULL;

	cond_return_error(arg == 0, -EINVAL, "invalid arg == 0, cmd = %d.\n", cmd);
	cond_return_error(cmd < _IO(FFTS_ID_MAGIC, 1) || cmd >= _IO(FFTS_ID_MAGIC, FFTS_MAX_CMD),
		-EINVAL, "invalid cmd = %d.\n", cmd);
	cond_return_error(ffts_ioctl_call[_IOC_NR(cmd)] == NULL,
		-EINVAL, "invalid cmd = %d.\n", cmd);

	proc_ctx = (struct ffts_proc_ctx *)filep->private_data;
	cond_return_error(proc_ctx == NULL, -EBUSY, "proc_ctx is NULL, tgid=%d.\n", current->tgid);
	cond_return_error(proc_ctx->pid != current->tgid, -EBUSY,
		"can't make ioctl in child process, proc_ctx pid=%d, tgid=%d.\n", proc_ctx->pid, current->tgid);

	// porcess ioctl
	ret = ffts_ioctl_call[_IOC_NR(cmd)](proc_ctx, arg);
	cond_return_error(ret != 0, -EBUSY, "ioctl failed, cmd = %d.\n", cmd);

	return ret;
}