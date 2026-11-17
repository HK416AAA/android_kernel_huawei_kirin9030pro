/*
* npu_ffts_exception_udk.c
*
* about npu aicore plat
*
* Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#include "npu_ffts_exception_udk.h"

#include "ffts_hw_config.h"
#include "hwts_driver.h"
#include "npu_common.h"
#include "npu_common_resource.h"
#include "npu_platform_resource.h"
#include "npu_exception.h"
#include "npu_except_mgr.h"
#include "npu_platform.h"
#include "npu_hwts_plat.h"
#include "npu_log.h"
#include "npu_platform_exception.h"
#include "npu_ffts_model.h"
#include "npu_soc_defines.h"
#include "soc_ffap1_interface.h"

enum FFAP_STATUS {
	FFAP_DISCONNECTED = 0,
	FFAP_CONNECTING = 1,
	FFAP_CONNECTED = 2,
	FFAP_DISCONNECTING = 3
};

struct npu_ffap1_task_payload {
	unsigned int opcode       : 3;
	unsigned int groupid      : 3;
	unsigned int res0         : 3;
	unsigned int taskidx      : 16;
	unsigned int error        : 1;
	unsigned int errProcess   : 1;
	unsigned int res1         : 5;
};

struct npu_ffap1_drainack_payload {
	unsigned int opcode  : 3;
	unsigned int res0    : 6;
	unsigned int ssid    : 12;
	unsigned int ssidv   : 1;
	unsigned int res1    : 10;
};

typedef union {
	unsigned int  value;
	struct npu_ffap1_task_payload task;
	struct npu_ffap1_drainack_payload drainack;
} npu_ffap1_payload_u;

bool is_entry_id_valid(uint16_t entry_id)
{
	if (entry_id >= MAX_NPU_ENTRY) {
		npu_drv_err("invalid param entry_id = %u\n", entry_id);
		return false;
	}
	return true;
}

static bool is_rtsq_idx_valid(uint16_t rtsq_idx)
{
	if (rtsq_idx >= NPU_FFRT_MODEL_STREAM_NUM_MAX) {
		npu_drv_err("invalid param rtsq_idx = %u\n", rtsq_idx);
		return false;
	}
	return true;
}

int npd_dump_exception_ffts(struct ffts_exception_report_info *report)
{
	if (report == NULL) {
		npu_drv_warn("exception form ts has no report");
		return NPU_EXCEPTION_CONTINUE;
	}

	switch (report->exception_type) {
		case NPU_EXCEPTION_TYPE_HWTS_FFRT_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_FFRT_DRAIN:
			npu_ffrt_error_exception_dump(report->entry_id);
			break;
		case NPU_EXCEPTION_TYPE_HWTS_TASK_EXCEPTION:
		case NPU_EXCEPTION_TYPE_HWTS_TASK_TIMEOUT:
		case NPU_EXCEPTION_TYPE_HWTS_TRAP_EXCEPTION:
		case NPU_EXCEPTION_TYPE_HWTS_SQE_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_SW_STATUS_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_BUS_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_ECC_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_POOL_CONFLICT_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_HTS_ERROR:
		case NPU_EXCEPTION_TYPE_HWTS_POWER_TIMEOUT:
		case NPU_EXCEPTION_TYPE_HWTS_TIMEOUT:
			npu_hwts_exception_dump(report->exception_type, 0, report->channel_id);
			break;
		default:
			npu_drv_err("invalid exception type:%u", report->exception_type);
	}
	return NPU_EXCEPTION_CONTINUE;
}

static void npu_ffrt_reply_task_err(uint64_t hwts_base, uint16_t entry_id, uint16_t is_global_err)
{
	SOC_NPU_HWTS_HWTS_FFRT_CTRL1_UNION ffrt_ctrl1 = {0};
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_UNION info1 = {0};
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_UNION info2 = {0};
	npu_ffap1_payload_u payload = {0};
	int trytime = HWTS_RETRY_TIMES;
	uint16_t err_process;

	ffrt_ctrl1.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));
	while (trytime-- > 0) {
		if (ffrt_ctrl1.reg.ffrt_task_done == 0)
			break;
		mdelay(1);
		ffrt_ctrl1.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));
	}
	if (ffrt_ctrl1.reg.ffrt_task_done == 1) {
		npu_drv_err("reply task err fail");
		return;
	}

	info1.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(hwts_base, entry_id));
	info2.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_ADDR(hwts_base, entry_id));
	err_process = is_global_err == 1 ? 0 : info1.reg.err_mode;
	payload.task.opcode = 0;
	payload.task.groupid = info1.reg.grpid;
	payload.task.taskidx = info2.reg.taskidx;
	payload.task.error = 1;

	// errProcess: 0:must handle exception; 1:can ignore exception
	payload.task.errProcess = err_process;
	writel(payload.value, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL0_ADDR(hwts_base));
	ffrt_ctrl1.reg.ffrt_task_done = 1;
	writel(ffrt_ctrl1.value, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));

	// clear ffrt entry
	writel(0x1, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
}

static void npu_ffrt_reply_drain_uid(uint64_t hwts_base, uint16_t ssid, uint16_t entry_id)
{
	SOC_NPU_HWTS_HWTS_FFRT_CTRL1_UNION ffrt_ctrl1 = {0};
	npu_ffap1_payload_u payload = {0};
	int trytime = HWTS_RETRY_TIMES;

	ffrt_ctrl1.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));
	while (trytime-- > 0) {
		if (ffrt_ctrl1.reg.ffrt_task_done == 0)
			break;
		mdelay(1);
		ffrt_ctrl1.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));
	}
	if (ffrt_ctrl1.reg.ffrt_task_done == 1) {
		npu_drv_err("reply task err fail");
		return;
	}

	payload.drainack.opcode = 2;
	payload.drainack.ssid = ssid;
	payload.drainack.ssidv = 1;
	writel(payload.value, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL0_ADDR(hwts_base));
	ffrt_ctrl1.reg.ffrt_task_done = 1;
	writel(ffrt_ctrl1.value, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));

	// clear ffrt entry
	writel(0x1, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
}

static enum npu_hwts_sqe_type npu_get_hwts_sqe_type_by_acsq(uint64_t hwts_base, uint16_t acsq_id)
{
	SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_UNION acsq_fsm_dfx_ctrl0;

	acsq_fsm_dfx_ctrl0.value =
		readl((const volatile void *)(uintptr_t)SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_ADDR(hwts_base, acsq_id));
	return (enum npu_hwts_sqe_type)acsq_fsm_dfx_ctrl0.reg.sqe_type;
}

static int npu_handle_ffts_task_kill(uint16_t rtsq, uint32_t *need_reset)
{
	uint16_t acsq_id;
	uint64_t hwts_base = npu_hwts_get_base_addr();
	uint64_t timeout = 100000;
	int ret = 0;
	SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_UNION task_ctrl_0 = {0};
	SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_UNION rtsq_cfg3 = {0};

	cond_return_error(hwts_base == 0ULL, -1, "hwts_base is NULL\n");

	// send task kill cmd
	task_ctrl_0.value = readl((const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_ADDR(hwts_base, rtsq));
	task_ctrl_0.reg.p0_task_kill = 0x1;
	writel(task_ctrl_0.value, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_ADDR(hwts_base, rtsq));

	// check p0_rtsq_en
	rtsq_cfg3.value = readl((const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_ADDR(hwts_base, rtsq));
	if (rtsq_cfg3.reg.p0_rtsq_en == 0) {
		hwts_driver_hwts_task_terminate(rtsq);
		return 0;
	}
	// polling P0_RTSQ_DFX0
	ret = npu_hwts_polling_rtsq_fsm_state(rtsq, timeout);
	cond_return_error(ret != 0, -1, "polling P0_RTSQ_DFX0 failed\n");

	// check rtsq swapped in or not + check sqe
	acsq_id = hwts_get_acsq_id_by_rtsq_id(rtsq);
	if (acsq_id == UINT16_MAX || npu_get_hwts_sqe_type_by_acsq(hwts_base, acsq_id) == NPU_HWTS_SQE_NOTIFY_WAIT) {
		npu_drv_warn("not swapin or hts event wait task, no need to cancel aicore, acsq = %u\n", acsq_id);
		goto disable_sq;
	}

	// make sure acsq is ready to handle exception
	ret = npu_hwts_polling_acsq_fsm_state(acsq_id, timeout);

	// polling owned ip until it becomes 0: no need to do software aic/aiv reset
	timeout = 250000;
	ret += npu_hwts_polling_acsq_ip_own_state(acsq_id, timeout, need_reset);
	cond_return_error(*need_reset != 0, ret, "aic has excp\n");

disable_sq:
	hwts_driver_clear_channel_sq_en(rtsq);
	hwts_driver_hwts_task_terminate(rtsq);
	return ret;
}

static int npu_handle_ffts_exception_hwts(uint16_t rtsq)
{
	// check rtsq swapped in or not
	uint16_t acsq_id = hwts_get_acsq_id_by_rtsq_id(rtsq);
	int ret = 0;
	if (acsq_id == UINT16_MAX) {
		npu_drv_warn("the rtsq %u is not swapped in\n", rtsq);
		hwts_driver_clear_channel_sq_en(rtsq);
		hwts_driver_hwts_task_terminate(rtsq);
		return 0;
	}

	// polling state and reset aicore
	ret = npu_exception_aicore_reset(rtsq);
	if (ret != 0) {
		npu_drv_warn("aicore reset failed, need reset npu to handle exception");
		return -1;
	}
	return 0;
}

static int npu_check_and_handle_rtsq(uint16_t entry_id, uint16_t rtsq_id, uint32_t rtsq_err)
{
	HWTS_RTSQ_TABLE_BITMAP_INIT();
	uint64_t channel_bitmap = NPU_HWTS_RTSQ_FFRT_BITMAP;
	uint64_t rtsq_low_limit = find_first_bit((unsigned long *)(void *)&channel_bitmap, NPU_HWTS_CHANNEL_NUM);
	uint32_t rtsq_len = get_hwts_rtsq_num(HWTS_RTSQ_TYPE_FFRT);
	uint32_t need_reset = 0;
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	uint64_t hwts_base = npu_hwts_get_base_addr();

	if (rtsq_len == 0 || rtsq_id < rtsq_low_limit || rtsq_id > (rtsq_low_limit + rtsq_len))
		npu_drv_err("the entry %u rtsq %u rtsq_len %u invalid", entry_id, rtsq_id, rtsq_len);
	if (rtsq_err == 1) {
		npu_drv_err("the entry %u rtsq %u has err", entry_id, rtsq_id);
		if (npu_handle_ffts_exception_hwts(rtsq_id) != 0)
			return -1;
	} else {
		npu_drv_err("the entry %u need kill rtsq %u", entry_id, rtsq_id);
		if (npu_handle_ffts_task_kill(rtsq_id, &need_reset) != 0) {
			if (need_reset != 0){
				ctrl0.value = readl(
					(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
				// find aic excep during kill, aic need to soft reset
        		npu_drv_warn("rtsq0_err = %u, rtsq1_err = %u, rtsq2_err = %u",
					ctrl0.reg.rtsq0_err, ctrl0.reg.rtsq1_err, ctrl0.reg.rtsq2_err);
					return npu_handle_ffts_exception_hwts(rtsq_id);
			}
			return -1;
		}
	}
	return 0;
}

static void npu_print_mdc(uint64_t hwts_base, uint16_t entry_id)
{
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_UNION info1 = {0};
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_UNION info3 = {0};
	uint32_t model_id;
	int i;
	struct npu_ffrt_model_buff* ffrt_mdc_buf = NULL;
	info1.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(hwts_base, entry_id));
	if (info1.reg.usrbit == 1) {
		npu_drv_err("no support usrbit");
		return;
	}

	info3.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_ADDR(hwts_base, entry_id));
	// if kernel MDC funcptr means model id
	model_id = info3.reg.funcptr_l;
	if (model_id >= NPU_MAX_MODEL_ID) {
		npu_drv_err("invalid model id %u", model_id);
		return;
	}
	ffrt_mdc_buf = get_ffrt_mdc_buf(model_id);
	if (ffrt_mdc_buf != NULL) {
		npu_drv_err("mdc: model_id = %u, pmu_idx = %u, blkdim = %u", info3.reg.funcptr_l, ffrt_mdc_buf->pmu_idx, ffrt_mdc_buf->blkdim);

		for (i = 0; i < HWTS_FFRT_ENTRY_RTSQ_NUM; i++) {
			npu_drv_err("r_vld = %u, r_swapbuf_idx = %u, r_length = %u, r_head = %u, r_tail = %u",
				ffrt_mdc_buf->rtsq_info[i].r_vld, ffrt_mdc_buf->rtsq_info[i].r_swapbuf_idx, ffrt_mdc_buf->rtsq_info[i].r_length,
				ffrt_mdc_buf->rtsq_info[i].r_head, ffrt_mdc_buf->rtsq_info[i].r_tail);
		}
		npu_drv_err("stack_base_addr_l = %u, stack_base_addr_h = %u, slow_context_switch_base_addr_l = %u, slow_context_switch_base_addr_h = %u,"
			"task_param_base_addr_l = %u, task_param_base_addr_h = %u, task_pc_base_addr_l = %u, task_pc_base_addr_h = %u", ffrt_mdc_buf->stack_base_addr_l,
			ffrt_mdc_buf->stack_base_addr_h, ffrt_mdc_buf->slow_context_switch_base_addr_l, ffrt_mdc_buf->slow_context_switch_base_addr_h,
			ffrt_mdc_buf->task_param_base_addr_l, ffrt_mdc_buf->task_param_base_addr_h, ffrt_mdc_buf->task_pc_base_addr_l, ffrt_mdc_buf->task_pc_base_addr_h);
	}
}

static int npu_handle_ffrt_entry_err(uint16_t entry_id)
{
	uint64_t hwts_base = npu_hwts_get_base_addr();
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = {0};

	cond_return_error(hwts_base == 0ULL, NPU_EXCEPTION_HANDLED, "hwts_base is NULL\n");

	// 1. ctrl0
	ctrl0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
	if ((ctrl0.reg.rtsq0_err == 1) || (ctrl0.reg.rtsq1_err == 1) || (ctrl0.reg.rtsq2_err == 1)){
        npu_drv_err("mdc error = %u, kernrl mdc validate error = %u, swapbuf_idx error = %u",
			ctrl0.reg.rtsq0_err, ctrl0.reg.rtsq1_err, ctrl0.reg.rtsq2_err);
		npu_print_mdc(hwts_base, entry_id);
    } else {
		npu_drv_err("no find rtsq error");
	}

	// 3. reply task_error + clear ffrt entry
	npu_ffrt_reply_task_err(hwts_base, entry_id, 0);
	return NPU_EXCEPTION_HANDLED;
}

static int npu_handle_ffrt_err(uint16_t entry_id)
{
	int ret;
	struct npu_dev_ctx *dev_ctx = get_dev_ctx_by_id(0);
	cond_return_error(dev_ctx == NULL, NPU_EXCEPTION_HANDLED, "dev_ctx is null\n");

	mutex_lock(&dev_ctx->ffrt_entry_mutex);
	ret = npu_handle_ffrt_entry_err(entry_id);
	mutex_unlock(&dev_ctx->ffrt_entry_mutex);
	return ret;
}

static int npu_handle_ffrt_entry(uint16_t entry_id)
{
	uint64_t hwts_base = npu_hwts_get_base_addr();
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_UNION info0 = { 0 };
	int trytimes = HWTS_RETRY_TIMES;
	int ret = 0;
	npu_drv_warn("npu handle ffrt entry begin");
	cond_return_error(hwts_base == 0ULL, -1, "hwts_base is NULL\n");

	ctrl0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));

	// polling
	while (trytimes-- > 0) {
		if (ctrl0.reg.rtsq_assign == 0) {
			break;
		}
		mdelay(1);
		ctrl0.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
	}
	cond_return_error(trytimes == 0, -1, "rtsq assign timeout");
   
	info0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_ADDR(hwts_base, entry_id));
	if (ctrl0.reg.rtsq0_vld == 1) {
		ret = npu_check_and_handle_rtsq(entry_id, info0.reg.rtsqid_0, ctrl0.reg.rtsq0_err);
	}
	if (ctrl0.reg.rtsq1_vld == 1) {
		ret += npu_check_and_handle_rtsq(entry_id, info0.reg.rtsqid_1, ctrl0.reg.rtsq1_err);
	}
	if (ctrl0.reg.rtsq2_vld == 1) {
		ret += npu_check_and_handle_rtsq(entry_id, info0.reg.rtsqid_2, ctrl0.reg.rtsq2_err);
	}

	// reply taskerr + clear ffrt entry
	npu_ffrt_reply_task_err(hwts_base, entry_id, 0);

	npu_drv_warn("npu handle ffrt entry end");
	return ret;
}

static int npu_handle_ffrt_entry_drain(uint16_t entry_id)
{
	uint64_t hwts_base = npu_hwts_get_base_addr();
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_UNION info0 = { 0 };
	int trytimes = HWTS_RETRY_TIMES;
	int ret = 0;
	npu_drv_warn("npu handle ffrt entry drain begin");
	cond_return_error(hwts_base == 0ULL, -1, "hwts_base is NULL\n");

	ctrl0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));

	// polling
	while (trytimes-- > 0) {
		if (ctrl0.reg.rtsq_assign == 0) {
			break;
		}
		mdelay(1);
		ctrl0.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
	}
	cond_return_error(trytimes == 0, -1, "rtsq assign timeout");
	// rtsq0/1/2_vld is 0, the rtsq0/1/2_err is 0, and rtsq0/1/2_done is 0
    if (ctrl0.value == 0x0) {
		goto clear_entry;
	}
	// rtsq0/1/2_vld is 0,  any one of rtsq0/1/2_err is 1.
    if (ctrl0.reg.rtsq0_vld == 0 && ctrl0.reg.rtsq1_vld == 0 && ctrl0.reg.rtsq2_vld == 0 && 
	    (ctrl0.reg.rtsq0_err || ctrl0.reg.rtsq1_err || ctrl0.reg.rtsq2_err)) {
		return npu_handle_ffrt_entry_err(entry_id);
	}
	info0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_ADDR(hwts_base, entry_id));
	if (ctrl0.reg.rtsq0_vld == 1) {
		ret = npu_check_and_handle_rtsq(entry_id, info0.reg.rtsqid_0, ctrl0.reg.rtsq0_err);
	}
	if (ctrl0.reg.rtsq1_vld == 1) {
		ret += npu_check_and_handle_rtsq(entry_id, info0.reg.rtsqid_1, ctrl0.reg.rtsq1_err);
	}
	if (ctrl0.reg.rtsq2_vld == 1) {
		ret += npu_check_and_handle_rtsq(entry_id, info0.reg.rtsqid_2, ctrl0.reg.rtsq2_err);
	}
clear_entry:
	// reply taskerr + clear ffrt entry
	npu_ffrt_reply_task_err(hwts_base, entry_id, 0);
	npu_drv_warn("npu handle ffrt entry drain end");
	return ret;
}

static void npu_get_entry_info(uint16_t entry_id, uint16_t rtsq_idx, unsigned int *rtsq_vld, unsigned int *rtsq_err, unsigned int *rtsq_id)
{
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_UNION info0 = { 0 };
	uint64_t hwts_base = npu_hwts_get_base_addr();
	ctrl0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
	info0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_ADDR(hwts_base, entry_id));
	if (rtsq_idx == 0) {
		*rtsq_vld = ctrl0.reg.rtsq0_vld;
		*rtsq_err = ctrl0.reg.rtsq0_err;
		*rtsq_id = info0.reg.rtsqid_0;
	} else if (rtsq_idx == 1) {
		*rtsq_vld = ctrl0.reg.rtsq1_vld;
		*rtsq_err = ctrl0.reg.rtsq1_err;
		*rtsq_id = info0.reg.rtsqid_1;
	} else if (rtsq_idx == 2) {
		*rtsq_vld = ctrl0.reg.rtsq2_vld;
		*rtsq_err = ctrl0.reg.rtsq2_err;
		*rtsq_id = info0.reg.rtsqid_2;
	} else {
		npu_drv_warn("invalid rtsq  %u", rtsq_idx);
	}
}

static int npu_handle_local_task_exception_for_ffts(uint16_t entry_id, uint16_t rtsq_idx, uint16_t channel_id)
{
	uint64_t hwts_base = npu_hwts_get_base_addr();
	int ret = 0;
	unsigned int rtsq_vld = 0;
    unsigned int rtsq_err = 0;
	unsigned int rtsq_id = 0;
	struct npu_dev_ctx *dev_ctx = get_dev_ctx_by_id(0);

	cond_return_error(dev_ctx == NULL, NPU_EXCEPTION_CONTINUE, "dev_ctx is null\n");
	cond_return_error(hwts_base == 0ULL, NPU_EXCEPTION_CONTINUE, "hwts_base is NULL\n");
	if ((!is_channel_id_valid(channel_id)) || (!is_entry_id_valid(entry_id)) || (!is_rtsq_idx_valid(rtsq_idx)))
		return NPU_EXCEPTION_CONTINUE;

	// skip the entry handled by e.g. proc block
	mutex_lock(&dev_ctx->ffrt_entry_mutex);
	npu_get_entry_info(entry_id, rtsq_idx, &rtsq_vld, &rtsq_err, &rtsq_id);
	if (rtsq_vld == 1 && rtsq_err == 1 && rtsq_id == channel_id) {
		ret = npu_handle_ffrt_entry(entry_id);
	} else {
		npu_drv_warn("entry %u is handled by others, rtsq_vld = %u, rtsq_err = %u, rtsq_id = %u, channel_id = %u",
			entry_id, rtsq_vld, rtsq_err, rtsq_id, channel_id);
	}
	mutex_unlock(&dev_ctx->ffrt_entry_mutex);

	if (ret != 0) {
		npu_drv_err("npu process task exception with entry %u failed", entry_id);
		return NPU_EXCEPTION_CONTINUE;
	}
	npu_drv_warn("npu process task exception with entry %u done", entry_id);
	return NPU_EXCEPTION_HANDLED;
}

static int npu_ffrt_polling_hwts2ffrt_taskdone(uint64_t hwts_base)
{
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_UNION dfx0 = { 0 };
	int trytime = HWTS_RETRY_TIMES;

	dfx0.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_ADDR(hwts_base));
	while (trytime-- > 0) {
		if (dfx0.reg.hwts2ffrt_taskdone_valid == 0)
			return 0;
		mdelay(1);
		dfx0.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_ADDR(hwts_base));
	}
	npu_drv_err("polling hwts2ffrt_taskdone_valid fail");
	return -1;
}

static int npu_handle_ffrt_drain(uint16_t entry_id)
{
	// only drain_uid, no drain_all
	struct npu_dev_ctx *dev_ctx = get_dev_ctx_by_id(0);
	uint64_t hwts_base = npu_hwts_get_base_addr();
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_UNION info1 = { 0 };
	uint16_t ssid = 0;
	int i, result;
	neh_reply_t ret = NPU_EXCEPTION_HANDLED;

	npu_drv_warn("npu handle ffrt drain_uid begin");
	cond_return_error(dev_ctx == NULL, -1, "dev_ctx is null\n");
	cond_return_error(hwts_base == 0ULL, -1, "hwts_base is NULL\n");
	// 1. polling hwts2ffrt_taskdone_valid
	if (npu_ffrt_polling_hwts2ffrt_taskdone(hwts_base) != 0)
		return NPU_EXCEPTION_CONTINUE;

	mutex_lock(&dev_ctx->ffrt_entry_mutex);
	// 2. read ssid
	info1.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(hwts_base, entry_id));
	ssid = info1.reg.ssid;

	// 3. loopup entry by ssid  +  proc entry (proc sq + reply taskerror + clear entry)
	for (i = 0; i < MAX_NPU_ENTRY; i++) {
		if (i == entry_id)
			continue;
		ctrl0.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, i));
		if (ctrl0.reg.task_vld == 1) {
			info1.value = readl(
				(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(hwts_base, i));
			if (info1.reg.ssid == ssid && info1.reg.ssidv == 1) {
				result = npu_handle_ffrt_entry_drain(i);
				if (result != 0) {
					npu_drv_warn("npu handle ffrt entry:%d drain error", i);
					ret = NPU_EXCEPTION_CONTINUE;
				}
				info1.value = readl(
					(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(hwts_base, i));
				// reply task_error + clear ffrt entry
				npu_ffrt_reply_task_err(hwts_base, i, 0);
			}
		}
	}

	// 4. reply request_drain_uid + clear ffrt entry
	npu_ffrt_reply_drain_uid(hwts_base, ssid, entry_id);
	mutex_unlock(&dev_ctx->ffrt_entry_mutex);
	
	return ret;;
}

int npu_handle_ffts_exception(struct ffts_exception_report_info *report)
{
	int ret = NPU_EXCEPTION_CONTINUE;
	npu_drv_warn("ffts report message type:%u", report->exception_type);

	switch (report->exception_type) {
	case NPU_EXCEPTION_TYPE_HWTS_TASK_EXCEPTION:
	case NPU_EXCEPTION_TYPE_HWTS_TASK_TIMEOUT:
	case NPU_EXCEPTION_TYPE_HWTS_TRAP_EXCEPTION:
		ret = npu_handle_local_task_exception_for_ffts(report->entry_id, report->rtsq_idx, report->channel_id);
		break;
	case NPU_EXCEPTION_TYPE_HWTS_FFRT_ERROR:
		ret = npu_handle_ffrt_err(report->entry_id);
		break;
	case NPU_EXCEPTION_TYPE_HWTS_FFRT_DRAIN:
		ret = npu_handle_ffrt_drain(report->entry_id);
		break;
	case NPU_EXCEPTION_TYPE_HWTS_SQE_ERROR:
	case NPU_EXCEPTION_TYPE_HWTS_BUS_ERROR:
	case NPU_EXCEPTION_TYPE_HWTS_ECC_ERROR:
	case NPU_EXCEPTION_TYPE_HWTS_POOL_CONFLICT_ERROR:
	case NPU_EXCEPTION_TYPE_HWTS_HTS_ERROR:
	case NPU_EXCEPTION_TYPE_HWTS_POWER_TIMEOUT:
	case NPU_EXCEPTION_TYPE_HWTS_TIMEOUT:
		break;
	default:
		npu_drv_err("invalid ts report message type:%u", report->exception_type);
	}

	return ret;
}

static u64 npu_get_ffap1_npu_base_addr(void)
{
	u64 ffap1_base = 0ULL;
	struct npu_platform_info *plat_info = npu_plat_get_info();

	cond_return_error(plat_info == NULL, 0ULL, "get platform info failed\n");
	ffap1_base = (u64)(uintptr_t)plat_info->dts_info.reg_vaddr[NPU_REG_FFAP1_NPU_BASE];
	npu_drv_debug("ffap1_base = 0x%pK\n", ffap1_base);
	return ffap1_base;
}

static void npu_disconnect_ffts_hwts_pt_link(void)
{
	uint64_t ffap1_base = npu_get_ffap1_npu_base_addr();
	SOC_FFAP1_CONNECT_ST_UNION st = {0};
	SOC_FFAP1_LINK_CTRL_PT_UNION pt = {0};
	int trytimes = HWTS_MORE_RETRY_TIMES;

	st.value = readl(
		(const volatile void *)(uintptr_t)SOC_FFAP1_CONNECT_ST_ADDR(ffap1_base));
	if (st.reg.pushtask_link_st != FFAP_DISCONNECTED) {
		writel(0x0, (volatile void *)(uintptr_t)SOC_FFAP1_LINK_CTRL_PT_ADDR(ffap1_base));
		npu_drv_warn("start ffap push task disconnect");
		pt.value = readl(
			(const volatile void *)(uintptr_t)SOC_FFAP1_LINK_CTRL_PT_ADDR(ffap1_base));
		while (pt.reg.cfg_pt_link_ack != FFAP_DISCONNECTED && trytimes-- > 0) {
			udelay(1);
			pt.value = readl(
				(const volatile void *)(uintptr_t)SOC_FFAP1_LINK_CTRL_PT_ADDR(ffap1_base));
		}
		npu_drv_warn("ffap1 connect pt push task %d", st.reg.pushtask_link_st);
	}
}

static void npu_disconnect_ffts_hwts_td_link(void)
{
	uint64_t ffap1_base = npu_get_ffap1_npu_base_addr();
	SOC_FFAP1_CONNECT_ST_UNION st = {0};
	SOC_FFAP1_LINK_CTRL_TD_UNION td = {0};
	int trytimes = HWTS_MORE_RETRY_TIMES;

	st.value = readl(
		(const volatile void *)(uintptr_t)SOC_FFAP1_CONNECT_ST_ADDR(ffap1_base));
	if (st.reg.taskdone_link_st != FFAP_DISCONNECTED) {
		writel(0x0, (volatile void *)(uintptr_t)SOC_FFAP1_LINK_CTRL_TD_ADDR(ffap1_base));
		npu_drv_warn("start ffap task done disconnect");
		td.value = readl(
			(const volatile void *)(uintptr_t)SOC_FFAP1_LINK_CTRL_TD_ADDR(ffap1_base));
		while (td.reg.cfg_td_link_ack != FFAP_DISCONNECTED && trytimes-- > 0) {
			udelay(1);
			td.value = readl(
				(const volatile void *)(uintptr_t)SOC_FFAP1_LINK_CTRL_TD_ADDR(ffap1_base));
		}
		npu_drv_warn("ffap1 connect st task done %d", st.reg.taskdone_link_st);
	}
}
 
static void npu_read_entry_info(SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION *ctrl0,
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_UNION *info1, SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_UNION *info2,
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_UNION *dfx0, int entry_id)
{
	uint64_t hwts_base = npu_hwts_get_base_addr();
 
	cond_return_void(hwts_base == 0ULL, "hwts_base is NULL\n");
 
	ctrl0->value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, entry_id));
	info1->value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(hwts_base, entry_id));
	info2->value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_ADDR(hwts_base, entry_id));
	dfx0->value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_ADDR(hwts_base));
}

int npu_handle_global_exception_for_ffts(void)
{
	uint16_t i = 0;
	uint16_t drain_uid = 0;
	uint16_t drain_uid_entry_id;
	struct npu_dev_ctx *dev_ctx = get_dev_ctx_by_id(0);
	uint64_t hwts_base = npu_hwts_get_base_addr();
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_UNION info1 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_UNION info2 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_UNION dfx0 = { 0 };
	SOC_NPU_HWTS_HWTS_FFRT_CTRL1_UNION ffrt_ctrl1 = {0};

	npu_drv_warn("npu handle global exception for ffts begin");
	cond_return_error(dev_ctx == NULL, -1, "dev_ctx is null\n");
	cond_return_error(hwts_base == 0ULL, -1, "hwts_base is NULL\n");

	// 1. cut off pushtask_link
	npu_disconnect_ffts_hwts_pt_link();

	// 2. set ffrt_task_done_block
	ffrt_ctrl1.value = readl(
		(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));
	ffrt_ctrl1.reg.ffrt_task_done_block = 1;
	writel(ffrt_ctrl1.value, (volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(hwts_base));

	mutex_lock(&dev_ctx->ffrt_entry_mutex);
	// 3. lookup entry (task_vld == 1 + opcode == 0) + proc entry(reply taskerr + clear entry)
	for (i = 0; i < MAX_NPU_ENTRY; i++) {
		npu_read_entry_info(&ctrl0, &info1, &info2, &dfx0, i);
		if (ctrl0.reg.task_vld == 1 && dfx0.value == 0) {
			if (info1.reg.opcode == 0) {
				npu_drv_warn("ffrt entry %u has task, ctrl0 0x%x, info1 0x%x, info2 0x%x, dfx0 0x%x",
					i, ctrl0.value, info1.value, info2.value, dfx0.value);
				// reply task err + clear ffrt entry
				npu_ffrt_reply_task_err(hwts_base, i, 1);
			} else if (info1.reg.opcode == 2 && info1.reg.ssidv == 1) {
				drain_uid = info1.reg.ssid;
				drain_uid_entry_id = i;
			}
		}
	}
	// 4. drain entry(reply drain_uid + clear ffrt entry)
	if (drain_uid > 0)
		npu_ffrt_reply_drain_uid(hwts_base, drain_uid, drain_uid_entry_id);
	mutex_unlock(&dev_ctx->ffrt_entry_mutex);

	// 5. cut off taskdone_link
	npu_disconnect_ffts_hwts_td_link();

	npu_drv_warn("npu handle global exception for ffts end");
	return 0;
}

int npu_ffts_entry_is_clear(void)
{
	uint64_t hwts_base = npu_hwts_get_base_addr();
	SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION ctrl0 = { 0 };
	uint16_t i;

	cond_return_error(hwts_base == 0ULL, -1, "hwts_base is NULL\n");

	for (i = 0; i < MAX_NPU_ENTRY; i++) {
		ctrl0.value = readl(
			(const volatile void *)(uintptr_t)SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(hwts_base, i));
		if (ctrl0.reg.task_vld == 1)
			return -1;
	}
	return 0;
}
int npu_proc_block_kill_task(u16 uid)
{
	unused(uid);
	return 0;
}

int npu_ffts_clear_entry(uint16_t task_idx, uint16_t entry_id)
{
	unused(task_idx);
	unused(entry_id);
	return 0;
}