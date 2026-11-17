/*
 * ffts_hw_config.c
 *
 * ffts hw config
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
#include "ffts_hw_config.h"

#include <linux/mutex.h>
#include <linux/delay.h>
#include <asm/io.h>
#include <securec.h>

#include "dfx/ffts_log.h"
#include "inc/ffts_resource.h"
#include "uniform_id.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "ffts_platform.h"
#include "ffts_tid.h"
#include "communication/ffts_interrupt.h"
#include "dfx/bbox/ffts_dfx_black_box.h"
#include "inc/ffts_common.h"
#include "ffts_platform.h"
#include "core/ffts_proc_ctx.h"
#include "ffts_intr_config.h"
#include "core/ffts_ioctl_services.h"
#include "ffts_task.h"

#define NPU_EVENTID 1
#define PROC_BLOCK_HWTYPE2_EN_ALL 15
#define HTS_MAX_EVENT_NUM 1023

enum {
	CMO_CLEAN = 0x0,
	CMO_CLEAN_INVALID = 0x1,
	CMO_UID_CLEAN = 0x2,
	CMO_UID_CLEAN_INVALID = 0x3,
	CMO_IGNORE = 0x7,
};

static const uint32_t ffts_reg_debug_info_size = 0x440; // (0x10F8 / 4) + 2
static const uint32_t ffts_kernel_reg_base_offset = 0x2000;
static const uint32_t ffts_task_id_start = 1024;
static const uint32_t ffts_task_id_max = 16383;
static hw_proc_block_cb hw_proc_block_callback[FFTS_HW_MAX];
static ffap1_clear_cb g_ffap1_clear_callback[FFTS_HW_MAX];

struct ffts_hw_proc_ctx *ffts_plat_get_hw_proc_ctx(u16 uid)
{
	struct ffts_hw_proc_ctx *hw_proc_ctx = NULL;
	struct ffts_platform_info *plat_info = ffts_plat_get_info();
	if (plat_info == NULL) {
		ffts_drv_err("get platform info error\n");
		return NULL;
	}

	if (uid < FFRT_UNIFORM_ID_START || uid > FFRT_UNIFORM_ID_END) {
		ffts_drv_err("uid %u is invalid\n", uid);
		return NULL;
	}

	hw_proc_ctx = (struct ffts_hw_proc_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_PROCCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_proc_ctx) * uid);
	return hw_proc_ctx;
}

static void ffts_cache_cmo_proc_ctx(u16 uid)
{
	u32 wait_times = 0;
	SOC_FFTS_CACHE_CMO_CTRL_UNION cmo_ctl = {0};
	SOC_FFTS_CACHE_CMO_ST_UNION cmo_st = {0};
	vir_addr_t kernel_reg_base;
	kernel_reg_base = ffts_get_reg_base();
	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");

	cmo_ctl.reg.cache_flush_uid = uid;
	cmo_ctl.reg.cache_flush_type = 
		CMO_UID_CLEAN_INVALID | (CMO_IGNORE << 3) | (CMO_IGNORE << 6) | (CMO_IGNORE << 9) | (CMO_IGNORE << 12);
	cmo_ctl.reg.cache_flush_start = 1;
	writel(cmo_ctl.value, (volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_CTRL_ADDR(kernel_reg_base));
	while(wait_times < FFTS_RETRY_TIME) {
		// read block state
		cmo_st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_ST_ADDR(kernel_reg_base));
		if (cmo_st.reg.cache_flush_finish == 1) {
			ffts_drv_debug("cmo proc ctx finish, uid %u, wait_times %u.\n", uid, wait_times);
			return;
		}
		udelay(1);
		wait_times++;
		ffts_drv_debug("wait cmo proc ctx, wait_times %u, cmo state %u\n", wait_times, cmo_st.value);
	}

	ffts_drv_err("cmo proc ctx timeout, uid %u, cmo state %u\n", uid, cmo_st.value);
	ffts_rdr_exception_report(EXC_TYPE_CMO_EXCEPTION);
}

int ffts_set_tcb_procctx_table(int uid, vir_addr_t tcb_addr)
{
	struct ffts_hw_proc_ctx *hw_proc_ctx = ffts_plat_get_hw_proc_ctx(uid);
	cond_return_error(hw_proc_ctx == NULL, -EINVAL, "get hw_proc_ctx failed\n");

	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -EINVAL, "get dev_ctx failed\n");

	mutex_lock(&dev_ctx->ffts_cmo_lock);
    ffts_cache_cmo_proc_ctx(uid);
	mutex_unlock(&dev_ctx->ffts_cmo_lock);

	uint64_t *tmp = (uint64_t *)hw_proc_ctx;
	hw_proc_ctx->tcb_vaddr_l = tcb_addr;
	hw_proc_ctx->tcb_vaddr_h = tcb_addr >> 32;
 
	__asm__ __volatile__ ("dmb sy;");
	ffts_drv_debug("uid=%d, tcb_addr=%pK, tcb_vaddr_l=%pK, tcb_vaddr_h=%pK",
		uid, tcb_addr, hw_proc_ctx->tcb_vaddr_l, hw_proc_ctx->tcb_vaddr_h);

	return 0;
}

int ffts_plat_set_hw_proc_ctx(u16 uid, phys_addr_t rtb_addr)
{
	struct ffts_hw_proc_ctx *hw_proc_ctx = ffts_plat_get_hw_proc_ctx(uid);
	cond_return_error(hw_proc_ctx == NULL, -EINVAL, "get hw_proc_ctx failed\n");
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();

	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_proc_ctx(uid);
	mutex_unlock(&dev_ctx->ffts_cmo_lock);
	hw_proc_ctx->valid = 0x1;
	hw_proc_ctx->rtb_addr_l = rtb_addr >> 7; // set low 25 bit, remove low 7 bit.
	hw_proc_ctx->rtb_addr_h = rtb_addr >> 16; // set high 12 bit, total 37 bits.
	hw_proc_ctx->hw1_type_en = 0x0;
	hw_proc_ctx->hw2_type_en = 0xF; // Path2 enable: 0x2

	__asm__ __volatile__ ("dmb sy;");

	ffts_drv_debug("uid=%u, hw_proc_ctx=%pK, rtb addr=%pK.\n",
		uid, hw_proc_ctx, rtb_addr);
	return 0;
}

int ffts_plat_reset_hw_proc_ctx(u16 uid)
{
	int ret;
	struct ffts_hw_proc_ctx *hw_proc_ctx = ffts_plat_get_hw_proc_ctx(uid);
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();

	cond_return_error(hw_proc_ctx == NULL, -EINVAL, "get hw_proc_ctx failed\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "get dev_ctx failed\n");

	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_proc_ctx(uid);
	mutex_unlock(&dev_ctx->ffts_cmo_lock);
	ret = memset_s(hw_proc_ctx, sizeof(struct ffts_hw_proc_ctx), 0, sizeof(struct ffts_hw_proc_ctx));
	cond_return_error(ret != 0, ret, "reset hw_proc_ctx fail ret = %d.\n", ret);

	ffts_drv_debug("clear hw_proc_ctx succ, uid = %u\n", uid);
	return 0;
}

static struct ffts_hw_thread_ctx *ffts_plat_get_hw_thread_ctx(u16 ffts_tid)
{
	struct ffts_hw_thread_ctx *hw_thread_ctx = NULL;
	struct ffts_platform_info *plat_info = ffts_plat_get_info();
	if (plat_info == NULL) {
		ffts_drv_err("get platform info error\n");
		return NULL;
	}

	if (ffts_tid < FFTS_TID_START || ffts_tid > FFTS_TID_END) {
		ffts_drv_err("ffts_tid %u is invalid\n", ffts_tid);
		return NULL;
	}

	hw_thread_ctx = (struct ffts_hw_thread_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_THREADCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_thread_ctx) * ffts_tid);
	return hw_thread_ctx;
}

static void ffts_cache_cmo_thread_ctx(u16 tid)
{
	u32 wait_times = 0;
	SOC_FFTS_CACHE_CMO_CTRL_UNION cmo_ctl = {0};
	SOC_FFTS_CACHE_CMO_ST_UNION cmo_st = {0};
	vir_addr_t kernel_reg_base;
	kernel_reg_base = ffts_get_reg_base();
	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");

	cmo_ctl.reg.cache_flush_type = 
		CMO_IGNORE | (CMO_CLEAN_INVALID << 3) | (CMO_IGNORE << 6) | (CMO_IGNORE << 9) | (CMO_IGNORE << 12);
	cmo_ctl.reg.cache_flush_start = 1;
	writel(cmo_ctl.value, (volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_CTRL_ADDR(kernel_reg_base));
	while(wait_times < FFTS_RETRY_TIME) {
		// read block state
		cmo_st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_ST_ADDR(kernel_reg_base));
		if (cmo_st.reg.cache_flush_finish == 1) {
			ffts_drv_debug("cmo thread ctx finish, tid %u, wait_times %u.\n", tid, wait_times);
			return;
		}
		udelay(1);
		wait_times++;
		ffts_drv_debug("wait cmo thread ctx, wait_times %u, cmo state %u\n", wait_times, cmo_st.value);
	}

	ffts_drv_err("cmo thread ctx timeout, tid %u, cmo state %u\n", tid, cmo_st.value);
	ffts_rdr_exception_report(EXC_TYPE_CMO_EXCEPTION);
}

int ffts_plat_set_hw_thread_ctx(u16 ffts_tid, struct ffts_mem_info *sq_des)
{
	struct ffts_hw_thread_ctx *hw_thread_ctx = ffts_plat_get_hw_thread_ctx(ffts_tid);
	cond_return_error(hw_thread_ctx == NULL, -EINVAL, "get hw_thread_ctx failed\n");

	hw_thread_ctx->valid = 0x1;
	hw_thread_ctx->sq_vld = 0x0;
	__asm__ __volatile__ ("dmb sy;");

	ffts_drv_debug("ffts_tid=%u, hw_thread_ctx=0x%lx.\n", ffts_tid, hw_thread_ctx);
	return 0;
}

int ffts_plat_reset_hw_thread_ctx(u16 ffts_tid)
{
	int ret;
	struct ffts_hw_thread_ctx *hw_thread_ctx = ffts_plat_get_hw_thread_ctx(ffts_tid);
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();

	cond_return_error(hw_thread_ctx == NULL, -EINVAL, "get hw_thread_ctx failed\n");
	cond_return_error(dev_ctx == NULL, -EINVAL, "get dev_ctx failed\n");

	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_thread_ctx(ffts_tid);
	mutex_unlock(&dev_ctx->ffts_cmo_lock);
	ret = memset_s(hw_thread_ctx, sizeof(struct ffts_hw_thread_ctx), 0, sizeof(struct ffts_hw_thread_ctx));
	cond_return_error(ret != 0, ret, "reset hw_thread_ctx fail ret = %d.\n", ret);

	ffts_drv_debug("clear hw_thread_ctx succ, ffts_tid = %u\n", ffts_tid);
	return 0;
}

void ffts_cache_cmo_flush(void)
{
	u32 wait_times = 0;
	SOC_FFTS_CACHE_CMO_ST_UNION cmo_st = {0};
	SOC_FFTS_CACHE_CMO_CTRL_UNION cmo_ctrl = {0};
	vir_addr_t kernel_reg_base;
	kernel_reg_base = ffts_get_reg_base();
	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");

	cmo_ctrl.reg.cache_flush_start = 1;
	writel(cmo_ctrl.value, (volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_CTRL_ADDR(kernel_reg_base));
	while(wait_times < FFTS_RETRY_TIME) {
		// read block state
		cmo_st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_ST_ADDR(kernel_reg_base));
		if (cmo_st.reg.cache_flush_finish == 1) {
			ffts_drv_debug("cmo flush all finish, wait_times %u.\n", wait_times);
			break;
		}
		udelay(1);
		wait_times++;
		ffts_drv_debug("wait cmo all flush, wait_times %u, cmo state %u\n", wait_times, cmo_st.value);
	}

	ffts_drv_err("cmo flush all timeout, cmo state %u\n", cmo_st.value);
}

void write_ffts_acpu_reg(unsigned long long value)
{
    /* ACCDATA_EL1: s3_0_c13_c0_5 */
    __asm__ volatile("msr s3_0_c13_c0_5, %0" : : "r" (value));
}

void ffts_plat_thread_switch_config(u8 lpid, u16 uid, u16 ffts_tid, u8 qos)
{
    unsigned long long value;
    vir_addr_t ffts_reg_base;
    SOC_FFTS_LPID_MAP_UNION lpid_map = {0};

    if (lpid >= 14) {
		ffts_drv_err("invalid lpid %d\n", lpid);
		return;
	}
	if (uid > FFRT_UNIFORM_ID_END) {
		ffts_drv_err("invalid uid %d\n", uid);
		return;
	}
	if (ffts_tid > FFTS_TID_END) {
		ffts_drv_err("invalid ffts_tid %d\n", ffts_tid);
		return;
	}
    if (qos >= FFTS_QOS_NUM) {
        ffts_drv_err("invalid qos %d\n", qos);
		return;
    }

    lpid_map.reg.lpid_uid_map = uid;
    lpid_map.reg.lpid_tid_map = ffts_tid;
    lpid_map.reg.lpid_qos_map = qos;

	ffts_reg_base = ffts_get_reg_base();
	if (ffts_reg_base == 0) {
		ffts_drv_err("ffts_reg_base is null\n");
		return;
	}
    value = lpid_map.value;
    writel(value, SOC_FFTS_LPID_MAP_ADDR(ffts_reg_base, lpid));
    write_ffts_acpu_reg(value);
}

static int ffts_check_proc_ctx(u16 uid)
{
	struct ffts_hw_proc_ctx *hw_proc_ctx = ffts_plat_get_hw_proc_ctx(uid);
	cond_return_error(hw_proc_ctx == NULL, -EINVAL, "get hw_proc_ctx failed\n");

	if (hw_proc_ctx->tcnt == 0 && hw_proc_ctx->scnt == 0 && hw_proc_ctx->vcnt == 0)
		return 0;

	ffts_drv_err("the proc has residual resource, tcnt=%u, scnt=%u, vcnt=%u",
		hw_proc_ctx->tcnt, hw_proc_ctx->scnt, hw_proc_ctx->vcnt);
	return -1;
}

static int ffts_proc_block_disable(void)
{
	int ret = 0;
	SOC_FFTS_PROC_BLOCK_DIS_UNION blk_dis = {0};
	vir_addr_t ffts_reg_base = ffts_get_reg_base();
	cond_return_error(ffts_reg_base == 0, -EINVAL, "get reg base failed\n");
	ffts_drv_warn("proc block dis begin\n");
 
	blk_dis.reg.proc_block_dis = 1;
	writel(blk_dis.value, (volatile void *)(uintptr_t)SOC_FFTS_PROC_BLOCK_DIS_ADDR(ffts_reg_base));
	ffts_drv_warn("proc block dis end\n");
	return ret;
}

static void ffts_proc_release(struct ffts_proc_ctx *proc_ctx)
{
	int i;
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "get dev_ctx failed\n");
	mutex_lock(&dev_ctx->proc_ctx_lock);

	if (proc_ctx == NULL) {
		ffts_drv_err("proc ctx is NUll\n");
		mutex_unlock(&dev_ctx->proc_ctx_lock);
		return;
	}
	for (i = 0; i < FFTS_HW_MAX; i++) {
		if (proc_ctx->hw_rel_info[i].callback_func == NULL) {
			ffts_drv_info("%d callback not register\n", i);
			continue;
		}
		ffts_drv_debug("invoke %d callback func begin\n", i);
		proc_ctx->hw_rel_info[i].callback_func(proc_ctx->hw_rel_info[i].data, proc_ctx->pid);
		ffts_drv_debug("invoke %d callback func end\n", i);
	}
	mutex_unlock(&dev_ctx->proc_ctx_lock);
}

static void ffts_hw_workqueue_deinit(struct ffts_dev_ctx *dev_ctx, ffts_hw_t hw_type)
{
	ffts_drv_warn("workqueue %d deinit begin", hw_type);
	destroy_workqueue(dev_ctx->ffts_workequeue[hw_type].wq);
	ffts_drv_warn("workqueue %d deinit end", hw_type);
}

static int ffts_plat_config_proc_block(u16 uid)
{
	vir_addr_t ffts_reg_base;
	SOC_FFTS_PROC_BLOCK_START_UNION blk_start = {0};
	ffts_drv_debug("config proc block uid %u begin\n", uid);
	ffts_reg_base = ffts_get_reg_base();
	if (ffts_reg_base == 0) {
		ffts_drv_err("ffts_reg_base is null\n");
		return -1;
	}

	blk_start.reg.proc_block_uid = uid;
	blk_start.reg.proc_block_en = 1;
	blk_start.reg.proc_block_hwtype2_en = PROC_BLOCK_HWTYPE2_EN_ALL;
	writel(blk_start.value, (volatile void *)(uintptr_t)SOC_FFTS_PROC_BLOCK_START_ADDR(ffts_reg_base));
	return 0;
}

static void ffts_plat_proc_block_hw_mode(u16 uid, u16 ffts_tid)
{
	SOC_FFTS_PROC_BLOCK_CTRL_UNION blk_ctl = {0};
	SOC_FFTS_PROC_BLOCK_ST_UNION blk_st = {0};
	SOC_FFTS_MISC_CTRL2_UNION misc_ctrl2 = {0};

	vir_addr_t ffts_reg_base;
	int trytimes;
	int proc_block_ret;
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();

	ffts_reg_base = ffts_get_reg_base();
	if (ffts_reg_base == 0) {
		ffts_drv_err("ffts_reg_base is null\n");
		return;
	}

	ffts_drv_warn("process block begin\n");
	// step 1. set ffts hardware auto clean
	blk_ctl.reg.proc_block_auto_clean = 1;
	blk_ctl.reg.proc_block_auto_cmo = 3;
	writel(blk_ctl.value, (volatile void *)(uintptr_t)SOC_FFTS_PROC_BLOCK_CTRL_ADDR(ffts_reg_base));
	
	/**
	 * 通路2 DrainReq(Sync)发送优化控制开关, 1:开启 0:关闭
	 * 
	 * 关闭后: 进程清理时如果加速器对应的hwtype2_en比特置1,一定需要向加速器发送排空任务(DrainReq)的消息
	 * 开启后: 进程清理时即使加速器对应的hwtype2_en比特置1,若加速器没有任务(OSTD==0),则不会向加速器发送排空任务(DrainReq)的消息
	 */
	misc_ctrl2.reg.sync_opt_en = 1;
	writel(misc_ctrl2.value, (volatile void *)(uintptr_t)SOC_FFTS_MISC_CTRL2_ADDR(ffts_reg_base));

	// step 2. start process block
	proc_block_ret = ffts_plat_config_proc_block(uid);
	ffts_drv_debug("start proc block result: %d, uid: %u \n", proc_block_ret, uid);

	// step 3. wait process block end
	trytimes = 0;
	while(trytimes < FFTS_PROC_BLOCK_TIMEOUT) {
		// read block state
		blk_st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_PROC_BLOCK_ST_ADDR(ffts_reg_base));
 
		if ((blk_st.reg.proc_block_state == PROC_BLOCK_STATE_COMPLETE) ||
			(blk_st.reg.proc_block_state == PROC_BLOCK_STATE_IDLE)) {
			atomic_set(&dev_ctx->proc_block_hw_reg.ready_cnt, 0);
			atomic_set(&dev_ctx->excp_status_manager, FFTS_EXCP_POWER_UP);
			ffts_drv_info("process block complete: block_state %u, uid %u, trytimes %u.\n", blk_st.reg.proc_block_state, uid, trytimes);
			goto ffts_reset_ctx;
		}
		mdelay(1);
		trytimes++;
	}

	// step 4. process block timeout finished, clean ddr resource
	ffts_drv_warn("process block end, block_state %u, trytimes %u.\n", blk_st.reg.proc_block_state, trytimes);
	if (blk_st.reg.proc_block_state != PROC_BLOCK_STATE_COMPLETE &&
		blk_st.reg.proc_block_state != PROC_BLOCK_STATE_IDLE) {
		ffts_drv_err("proc block is not finish value = %d, uid = %u\n", blk_st.value, uid);
		ffts_rdr_exception_report(EXC_TYPE_BLOCK_PROC_EXCEPTION);
		goto ffts_reset_ctx;
	}

ffts_reset_ctx:
	ffts_plat_reset_hw_proc_ctx(uid);
	ffts_plat_reset_hw_thread_ctx(ffts_tid);
	(void)ffts_proc_block_disable();
	return;
}

int ffts_npu_local_excp_status_set(void)
{
	int trytimes = FFTS_RETRY_TIME;
	int ret = 0;
	ffts_excp_s status;
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	while (trytimes-- > 0) {
		status = (ffts_excp_s)(atomic_cmpxchg(&dev_ctx->excp_status_manager, FFTS_EXCP_POWER_UP, FFTS_EXCP_LOCAL_EXCP));
		ffts_drv_warn("proc block status is %d", status);
		switch (status) {
		case FFTS_EXCP_LOCAL_EXCP:
		case FFTS_EXCP_GLOBAL_EXCP:
		case FFTS_EXCP_PROC_BLOCK:
			udelay(10);
			break;
		case FFTS_EXCP_POWER_UP:
			return ret;
		default:
			ret = -1;
			ffts_drv_err("ffts exception status is invalid\n");
			return ret;
		}
	}

	if (trytimes == 0) {
		ret = -1;
		ffts_drv_err("ffts exception status cant set\n");
		return ret;
	}
	return ret;
}

void ffts_npu_local_excp_status_set_back(void)
{
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	atomic_set(&dev_ctx->excp_status_manager, FFTS_EXCP_POWER_UP);
}

void ffts_plat_proc_block_handle(struct ffts_dev_ctx *dev_ctx, struct ffts_proc_ctx *proc_ctx)
{
	ffts_drv_warn("block and cleanup process FFTS resource and cache\n");
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_proc_ctx(proc_ctx->uid);
	mutex_unlock(&dev_ctx->ffts_cmo_lock);

	if (ffts_check_proc_ctx(proc_ctx->uid) == 0) {
		goto proc_release;
	}

	mutex_lock(&dev_ctx->ffts_hw_operation_lock);
	ffts_plat_proc_block_hw_mode(proc_ctx->uid, proc_ctx->ffts_tid);
	ffts_cancel_abnormal_by_uid(proc_ctx->uid);
	mutex_unlock(&dev_ctx->ffts_hw_operation_lock);

proc_release:
	ffts_proc_release(proc_ctx);
	return;
}

void ffts_ffap1_clear_handle(struct ffts_dev_ctx *dev_ctx, u16 task_id)
{
	u32 i;
	int ret;
	ffts_drv_warn("clean up ffap1 entry\n");
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	for (i = 0; i < FFTS_HW_MAX; i++)
		if (dev_ctx->ffap1_clear_info.registered_hw[i] == 1 && g_ffap1_clear_callback[i] != NULL) {
				ffts_drv_warn("call ffap1 clear callback, hw = %u, task = %u\n", i, task_id);
				ret = g_ffap1_clear_callback[i](task_id);
				if (ret != 0)
					ffts_drv_err("ffap1 call hw = %u failed, ret = %d", i, ret);
				else
					ffts_drv_warn("ffap1 call hw = %u succ", i);
			}
}

static void ffts_plat_dump_reg_info(void)
{
	vir_addr_t kernel_reg_base = ffts_get_reg_base();
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	int i;
	int ret;
	uint32_t buf[ffts_reg_debug_info_size];

	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");
	ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "reg info:\r\n");
	cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
	ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	for (i = 0; i < ffts_reg_debug_info_size; i++)
		buf[i] = readl((const volatile void *)(uintptr_t)(kernel_reg_base + ffts_kernel_reg_base_offset + i * 4));

	for (i = 0; i < ffts_reg_debug_info_size; i += 4) {
		ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "0x%x:%x %x %x %x\r\n",
			ffts_kernel_reg_base_offset + i * 4, buf[i], buf[i + 1], buf[i + 2], buf[i + 3]);
		cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
		ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	}
}

void ffts_plat_dump_info(struct ffts_dev_ctx *dev_ctx)
{
	struct ffts_hw_proc_ctx *hw_proc_ctx = NULL;
	struct ffts_hw_thread_ctx *hw_thread_ctx = NULL;
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;
	struct ffts_platform_info *plat_info = ffts_plat_get_info();
	uint32_t i;
	int ret;
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	u32 *tmp = NULL;

	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	if (plat_info == NULL) {
		ffts_drv_err("get platform info error\n");
		return;
	}

	// 1. reg info
	ffts_plat_dump_reg_info();

	// 2. ddr info
	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_flush();
	mutex_unlock(&dev_ctx->ffts_cmo_lock);

	// 2.1 proc ctx
	ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "\r\nproc ctx info:\r\n");
	cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
	ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));

	hw_proc_ctx = (struct ffts_hw_proc_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_PROCCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_proc_ctx) * FFRT_UNIFORM_ID_START);
	for (i = FFRT_UNIFORM_ID_START; i <= FFRT_UNIFORM_ID_END; i++) {
		if (hw_proc_ctx->valid == 1) {
			tmp = (u32 *)hw_proc_ctx;
			ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "%u:%x %x %x %x %x\r\n",
				i, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
			cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
			ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		}
		hw_proc_ctx++;
	}

	// 2.2 thread ctx
	ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "\r\nthread ctx info:\r\n");
	cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
	ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));

	hw_thread_ctx = (struct ffts_hw_thread_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_THREADCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_thread_ctx) * FFTS_TID_START);
	for (i = FFTS_TID_START; i <= FFTS_TID_END; i++) {
		if (hw_thread_ctx->valid == 1) {
			tmp = (u32 *)hw_thread_ctx;
			ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "%u:%x %x\r\n",
				i, tmp[0], tmp[1]);
			cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
			ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		}
		hw_thread_ctx++;
	}

	// 2.3 task ctx
	ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "\r\ntask ctx info:\r\n");
	cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
	ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	hw_task_ctx = (struct ffts_hw_task_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_TASKCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_task_ctx) * ffts_task_id_start);
	for (i = ffts_task_id_start; i <= ffts_task_id_max; i++) {
		if (hw_task_ctx->status != 0) {
			tmp = (u32 *)hw_task_ctx;
			ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "%u:%x %x %x %x\r\n",
				i, tmp[0], tmp[1], tmp[2], tmp[3]);
			cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
			ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		}
		hw_task_ctx++;
	}
}

void ffts_hw_proc_block_regist(void* hw_ffap1_status_hold_cb, void* hw_resource_clear_cb, ffts_hw_t hw_type) {
	struct ffts_dev_ctx *dev_ctx;
	cond_return_void(hw_type < 0 || hw_type >= FFTS_HW_MAX, "hwtype is invalid\n");
	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	atomic_inc(&dev_ctx->proc_block_hw_reg.target_cnt);
	dev_ctx->proc_block_hw_reg.registered_hw[hw_type] = 1;
	hw_proc_block_callback[hw_type].hold_cb = hw_ffap1_status_hold_cb;
	hw_proc_block_callback[hw_type].release_cb = hw_resource_clear_cb;
}

void ffts_hw_proc_block_unregist(ffts_hw_t hw_type) {
	struct ffts_dev_ctx *dev_ctx;
	cond_return_void(hw_type < 0 || hw_type >= FFTS_HW_MAX, "hwtype is invalid\n");
	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	atomic_dec(&dev_ctx->proc_block_hw_reg.target_cnt);
	dev_ctx->proc_block_hw_reg.registered_hw[hw_type] = 0;
	hw_proc_block_callback[hw_type].hold_cb = NULL;
	hw_proc_block_callback[hw_type].release_cb = NULL;
}

void ffts_ffap1_clear_entry_regist(ffap1_clear_cb clear_cb, ffts_hw_t hw_type)
{
	struct ffts_dev_ctx *dev_ctx;
	cond_return_void(hw_type < 0 || hw_type >= FFTS_HW_MAX, "hwtype is invalid\n");
	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	atomic_inc(&dev_ctx->ffap1_clear_info.target_cnt);
	dev_ctx->ffap1_clear_info.registered_hw[hw_type] = 1;
	g_ffap1_clear_callback[hw_type] = clear_cb;
}

void ffts_ffap1_clear_entry_unregist(ffts_hw_t hw_type)
{
	struct ffts_dev_ctx *dev_ctx;
	cond_return_void(hw_type < 0 || hw_type >= FFTS_HW_MAX, "hwtype is invalid\n");
	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "dev_ctx is null\n");
	atomic_dec(&dev_ctx->ffap1_clear_info.target_cnt);
	dev_ctx->ffap1_clear_info.registered_hw[hw_type] = 0;
	g_ffap1_clear_callback[hw_type] = NULL;
}

int ffts_get_global_excp_info(u16 uid, struct ffts_global_excp_info *global_excp_info)
{
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	int i;
	int ret = 0;

	mutex_lock(&dev_ctx->ffts_excp_lock);
	cond_goto_error((dev_ctx->global_excp_info_cnt > FFTS_GLOBAL_EXCP_INFO_MAX), ffts_excp_release_lock, ret, -1,
		"get global excp info failed, uid %u, cnt %d", uid, dev_ctx->global_excp_info_cnt);

	ret = memset_s(global_excp_info, sizeof(struct ffts_global_excp_info), 0, sizeof(struct ffts_global_excp_info));
	cond_goto_error(ret != 0, ffts_excp_release_lock, ret, -1, "memset_s failed");

	for (i = 0; i < dev_ctx->global_excp_info_cnt; i++) {
		if (dev_ctx->global_excp_info[i].uid == uid) {
			global_excp_info->info[global_excp_info->cnt].modelid = dev_ctx->global_excp_info[i].modelid;
			global_excp_info->info[global_excp_info->cnt].taskid = dev_ctx->global_excp_info[i].taskid;
			global_excp_info->cnt++;
			ffts_drv_warn("uid = %u, modelid = %u, taskid = %u, cnt = %d",
				uid, dev_ctx->global_excp_info[i].modelid, dev_ctx->global_excp_info[i].taskid, dev_ctx->global_excp_info_cnt);
		}
	}
	if (global_excp_info->cnt == 0) {
		ffts_drv_err("has no task in this proc, uid %u", uid);
		ret = -1;
	}
ffts_excp_release_lock:
	mutex_unlock(&dev_ctx->ffts_excp_lock);
	return ret;
}

void ffts_hw_block_rdr_exception_report(ffts_hw_t hw_type)
{
	if (hw_type == FFTS_HW_NPU)
		ffts_rdr_exception_report(EXC_TYPE_BLOCK_NPU_EXCEPTION);
	else if (hw_type == FFTS_HW_GPU)
		ffts_rdr_exception_report(EXC_TYPE_BLOCK_GPU_EXCEPTION);
	else
		ffts_drv_err("invalid hw_type");
}

int ffts_set_device_info_mem_size(ffts_device_info_t *device_info)
{
	if (device_info == NULL) {
		ffts_drv_err("device_info is null");
		return -1;
	}
	device_info->mem_size[FFTS_MEM_USER_REG] = FFTS_USER_REG_SIZE + PAGE_SIZE_OFFSET;
	device_info->mem_size[FFTS_MEM_RTB] = FFTS_RTB_SIZE;
	return 0;
}

int ffts_get_map_info(struct ffts_proc_ctx *proc_ctx, ffts_mem_type map_type,
	unsigned long *base, unsigned long *len, struct list_head **vma_list)
{
	int ret = 0;
	struct ffts_platform_info *platform_info = NULL;
	cond_return_error(proc_ctx == NULL || base == NULL || len == NULL || vma_list == NULL,
		-EINVAL, "get map info failed, ptr is null\n");

	switch (map_type) {
	case FFTS_MEM_USER_REG:
		platform_info = ffts_plat_get_info();
		cond_return_error(platform_info == NULL, -EFAULT, "get platform info fail\n");
		*base = platform_info->dts_info.reg_desc[FFTS_USER_BASE_REG].base;
		*len =  FFTS_USER_REG_SIZE + PAGE_SIZE_OFFSET;
		*vma_list = &proc_ctx->vma_list[map_type];
		break;
	case FFTS_MEM_RTB:
		*base = proc_ctx->rtb_des.phy_addr;
		*len = proc_ctx->rtb_des.size;
		*vma_list = &proc_ctx->vma_list[map_type];
		break;
	default:
		ret = -EINVAL;
		break;
	}
	ffts_drv_warn("type=%d, base=%pK, len=0x%x\n", map_type, *base, *len);
	return ret;
}

static void ffts_cache_cmo_task_ctx(void)
{
	u32 wait_times = 0;
	SOC_FFTS_CACHE_CMO_CTRL_UNION cmo_ctl = { 0 };
	SOC_FFTS_CACHE_CMO_ST_UNION cmo_st = { 0 };
	vir_addr_t kernel_reg_base;
	kernel_reg_base = ffts_get_reg_base();
	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");

	cmo_ctl.reg.cache_flush_type = CMO_IGNORE | (CMO_IGNORE << 3) | (CMO_CLEAN << 6) | (CMO_IGNORE << 9) |
		(CMO_IGNORE << 12);
	cmo_ctl.reg.cache_flush_start = 1;
	writel(cmo_ctl.value, (volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_CTRL_ADDR(kernel_reg_base));
	while (wait_times < FFTS_RETRY_TIME) {
		cmo_st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_CACHE_CMO_ST_ADDR(kernel_reg_base));
		if (cmo_st.reg.cache_flush_finish == 1) {
			ffts_drv_debug("cmo task ctx finish, wait_times %u.\n", wait_times);
			return;
		}
		udelay(1);
		wait_times++;
		ffts_drv_debug("wait cmo task ctx, wait_times %u, cmo state %u\n", wait_times, cmo_st.value);
	}

	ffts_drv_err("cmo task ctx timeout, cmo state %u\n", cmo_st.value);
	ffts_rdr_exception_report(EXC_TYPE_CMO_EXCEPTION);
}

int ffts_get_qos_task_cnt(u16 uid, u8 qos)
{
	uint32_t i;
	int ret = 0;
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;
	struct ffts_platform_info *plat_info = ffts_plat_get_info();
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -EINVAL, "get dev_ctx failed\n");

	if (uid < FFRT_UNIFORM_ID_START || uid > FFRT_UNIFORM_ID_END) {
		ffts_drv_err("invalid uid %hu\n", uid);
		return -1;
	}
    if (qos >= FFTS_QOS_NUM) {
        ffts_drv_err("invalid qos %d\n", qos);
		return -1;
    }
	if (plat_info == NULL) {
		ffts_drv_err("get platform info error\n");
		return ret;
	}

	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_task_ctx();
	mutex_unlock(&dev_ctx->ffts_cmo_lock);

	hw_task_ctx = (struct ffts_hw_task_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_TASKCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_task_ctx) * ffts_task_id_start);
	for (i = ffts_task_id_start; i <= ffts_task_id_max; i++, hw_task_ctx++) {
		// status 0 is IDLE, invalid task; ParentTaskIdx 0 means root task, and the root task is ready status.
		if (hw_task_ctx->procid != uid || hw_task_ctx->qos != qos || hw_task_ctx->status == TASK_STATUS_IDLE ||
			(hw_task_ctx->parent_task_idx == 0 && hw_task_ctx->status == TASK_STATUS_READY)) {
			continue;
		}
		ret++;
	}

	return ret;
}

void ffts_plat_get_task_status_info(u16 uid, struct ffts_task_status_info *task_info)
{
	uint32_t i;
	struct ffts_dev_ctx *dev_ctx = NULL;
	struct ffts_platform_info *plat_info = NULL;
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;

	cond_return_void(task_info == NULL, "get task_info failed\n");
	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "get dev_ctx failed\n");

	plat_info = ffts_plat_get_info();
	if (plat_info == NULL) {
		ffts_drv_err("get platform info error\n");
		return;
	}

	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_task_ctx();
	mutex_unlock(&dev_ctx->ffts_cmo_lock);

	hw_task_ctx = (struct ffts_hw_task_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_TASKCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_task_ctx) * ffts_task_id_start);
	for (i = ffts_task_id_start; i <= ffts_task_id_max; i++) {
		if (hw_task_ctx->status != 0 && hw_task_ctx->procid == uid && hw_task_ctx->status < TASK_STATUS_MAX) {
			if (hw_task_ctx->parent_task_idx == 0)
				task_info->taskRequestStatusCnt[hw_task_ctx->status]++;
			else
				task_info->taskStatusCnt[hw_task_ctx->status]++;
		}
		hw_task_ctx++;
	}
}

static struct ffts_hw_task_ctx *ffts_get_taskctx(uint16_t taskidx)
{
	struct ffts_dev_ctx *dev_ctx = NULL;
	struct ffts_platform_info *plat_info = NULL;
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;

	if (taskidx > ffts_task_id_max) {
		ffts_drv_err("taskidx is invalid\n");
		return NULL;
	}
	dev_ctx = ffts_get_dev_ctx();
	if (dev_ctx == NULL) {
		ffts_drv_err("get dev_ctx failed\n");
		return NULL;
	}

	plat_info = ffts_plat_get_info();
	if (plat_info == NULL) {
		ffts_drv_err("get platform info failed\n");
		return NULL;
	}

	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_task_ctx();
	mutex_unlock(&dev_ctx->ffts_cmo_lock);

	hw_task_ctx = (struct ffts_hw_task_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_TASKCTX_DDR].virt_addr +
		(unsigned long)sizeof(struct ffts_hw_task_ctx) * taskidx);
	return hw_task_ctx;
}

static int verify_task_and_info(struct ffts_hw_task_ctx *task_ctx, struct exception_task *task_info)
{
	// status匹配，任务要求在执行中
	if (task_ctx->status < TASK_STATUS_PENDING || task_ctx->status >= TASK_STATUS_MAX) {
		return -1;
	}
	// recv_event匹配，通路三任务funcPtr高16位对应recv_event
	if (((task_ctx->funcptr1 >> 16) & 0xFFFF) != task_info->recv_event) {
		return -1;
	}
	// uid和hstype匹配
	if (task_ctx->procid != task_info->uid || task_ctx->hwtype != task_info->hwtype) {
		return -1;
	}
	return 0;
}

int ffts_query_exception_task(struct exception_task *task_info)
{
	uint16_t i = 0;
	int ret = 0;
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;
	if (task_info == NULL) {
		ffts_drv_err("task_info is null\n");
		return -1;
	}
	hw_task_ctx = ffts_get_taskctx(ffts_task_id_start);
	if (hw_task_ctx == NULL) {
		ffts_drv_err("get taskctx failed\n");
		return -1;
	}

	for (i = ffts_task_id_start; i <= ffts_task_id_max; i++) {
		ret = verify_task_and_info(hw_task_ctx, task_info);
		if (ret == 0) {
			task_info->qos = hw_task_ctx->qos;
			task_info->taskidx = i;
			ffts_drv_warn("query taskidx=%u, send_event=%u, recv_event=%u, status=%u, hwtype=%u\n", i, 
				hw_task_ctx->funcptr1 & 0xFFFF, (hw_task_ctx->funcptr1 >> 16) & 0xFFFF, hw_task_ctx->status, 
				hw_task_ctx->hwtype);
			return i;
		}
		hw_task_ctx++;
	}

	ffts_drv_warn("no task matching event_id:%u\n", task_info->recv_event);
	return 0;
}

int ffts_process_exception_task(struct exception_task *task_info)
{
	int ret = 0;
	uint32_t st;
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;

	if (task_info == NULL) {
		ffts_drv_err("task_info is null\n");
		return 1;
	}
	hw_task_ctx = ffts_get_taskctx(task_info->taskidx);
	if (hw_task_ctx == NULL) {
		ffts_drv_err("get taskctx failed\n");
		return 1;
	}
 
	ret = verify_task_and_info(hw_task_ctx, task_info);
	if (ret != 0) {
		// task信息不匹配，不需要处理
		task_info->taskidx = 0;
		return 0;
	}

	// 若status!=ReadyTask，这次不处理，下个try_cnt可以重试
	if (hw_task_ctx->status != TASK_STATUS_READY) {
		ffts_drv_warn("status mismatch, taskidx:%u, event_id:%u, status:%u\n",
			task_info->taskidx, task_info->recv_event, hw_task_ctx->status);
		return 1;
	}

	// 生成RTB任务并通知清理
	st = ffts_notify_excep_event_to_rtb(task_info);
	ffts_drv_warn("notify event_to_rtb, taskidx:%u, event_id:%u, qos:%u, st:%u\n",
		task_info->taskidx, task_info->recv_event, task_info->qos, st);
	task_info->taskidx = 0;
	return 0;
}

uint32_t ffts_notify_excep_event_to_rtb(struct exception_task *task_info)
{
	vir_addr_t kernel_reg_base;
	SOC_FFTS_EVENT2RTB_CTRL0_UNION ctrl_0 = {0};
	SOC_FFTS_EVENT2RTB_CTRL1_UNION ctrl_1 = {0};
	SOC_FFTS_EVENT2RTB_CTRL2_UNION ctrl_2 = {0};
	SOC_FFTS_EVENT2RTB_ST_UNION st = {0};
	int trytimes = FFTS_RETRY_TIME;
	struct ffts_dev_ctx *dev_ctx;

	if (task_info == NULL) {
		ffts_drv_err("task_info is null\n");
		return 0;
	}

	kernel_reg_base = ffts_get_reg_base();
	if (kernel_reg_base == 0) {
		ffts_drv_err("get reg base failed\n");
		return 0;
	}

	dev_ctx = ffts_get_dev_ctx();
	if (dev_ctx == NULL) {
		ffts_drv_err("get dev_ctx failed\n");
		return 0;
	}

	mutex_lock(&dev_ctx->ffts_hw_operation_lock);
	ctrl_0.reg.event2rtb_en = 1;
	ctrl_0.reg.event2rtb_qos = task_info->qos;
	ctrl_0.reg.event2rtb_uid = task_info->uid;
	ctrl_0.reg.event2rtb_taskidx = task_info->recv_event;

	ctrl_1.reg.event2rtb_pathtype = 0;
	ctrl_1.reg.event2rtb_opcode = 1;
	ctrl_1.reg.event2rtb_hwtype = task_info->hwtype;

	ctrl_2.reg.event2rtb_funcptr_0_31 = task_info->recv_event;

	// according to ffts manual, write ctrl1/2 first
	writel(ctrl_1.value, (volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_CTRL1_ADDR(kernel_reg_base));
	writel(ctrl_2.value, (volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_CTRL2_ADDR(kernel_reg_base));
	writel(ctrl_0.value, (volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_CTRL0_ADDR(kernel_reg_base));

	while(trytimes-- > 0) {
		st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_ST_ADDR(kernel_reg_base));
		if (st.reg.event2rtb_done == 1) {
			if (st.reg.event2rtb_succ == 1) {
				mutex_unlock(&dev_ctx->ffts_hw_operation_lock);
				return st.value;
			} else {
				writel(ctrl_1.value, (volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_CTRL1_ADDR(kernel_reg_base));
				writel(ctrl_2.value, (volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_CTRL2_ADDR(kernel_reg_base));
				writel(ctrl_0.value, (volatile void *)(uintptr_t)SOC_FFTS_EVENT2RTB_CTRL0_ADDR(kernel_reg_base));
			}
		} else {
			udelay(1);
		}
	}

	mutex_unlock(&dev_ctx->ffts_hw_operation_lock);
	return st.value;
}

void ffts_dump_sig_ctx_info(struct ffts_hw_task_ctx *hw_task_ctx)
{
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	struct ffts_hw_task_ctx_sig_info *tmp = NULL;
	struct ffts_hw_sig_ctx *hw_sig_ctx = NULL;
	int ret;
	struct ffts_platform_info *plat_info = ffts_plat_get_info();
 
	cond_return_void(plat_info == NULL, "get platform info error\n");
	if (hw_task_ctx != NULL) {
		tmp = (struct ffts_hw_task_ctx_sig_info *)(&hw_task_ctx->other[0]);
		for (int i = 0; i < FFTS_SIG_INFO_NUM; i++) {
			if (tmp[i].sigType != 0) {
				cond_return_void(tmp[i].sigidx > FFTS_SIG_CTX_NUM_MAX || tmp[i].sighashidx >= FFTS_SIG_HASH_NUM,
					"sigidx 0x%x sighashidx 0x%x is invalid\n", tmp[i].sigidx, tmp[i].sighashidx);
				hw_sig_ctx = (struct ffts_hw_sig_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_SIGCTX_DDR].virt_addr +
					(unsigned long)sizeof(struct ffts_hw_sig_ctx) * tmp[i].sigidx);
				ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX,
					"\r\nsigType=%u, signature=0x%llx, uid=%u, status=%u, vld=%u, veridx=%u", tmp[i].sigType,
					hw_sig_ctx->sig_value[tmp[i].sighashidx].signature,
					hw_sig_ctx->sig_value[tmp[i].sighashidx].procid,
					hw_sig_ctx->sig_value[tmp[i].sighashidx].status,
					hw_sig_ctx->sig_value[tmp[i].sighashidx].vld,
					hw_sig_ctx->sig_value[tmp[i].sighashidx].veridx);
				cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
				ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
			}
		}
	}
}
 
void ffts_dump_task_ctx_info(u16 taskidx)
{
	struct ffts_hw_task_ctx *hw_task_ctx = NULL;
	u32 *tmp = NULL;
	int ret;
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	struct ffts_platform_info *plat_info = ffts_plat_get_info();
 
	cond_return_void(plat_info == NULL, "get platform info error\n");
	if (taskidx >= ffts_task_id_start && taskidx <= ffts_task_id_max) {
		hw_task_ctx = (struct ffts_hw_task_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_TASKCTX_DDR].virt_addr +
			(unsigned long)sizeof(struct ffts_hw_task_ctx) * taskidx);
		if (hw_task_ctx->status != 0) {
			tmp = (u32 *)hw_task_ctx;
			ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX,
				"\r\nparent_task_idx=%u, taskidx=%hu, status=%u, wait_submit_cnt=%u, wait_task_cnt=%u,"
				"uid:%u:%x %x %x %x", hw_task_ctx->parent_task_idx, taskidx, hw_task_ctx->status,
				hw_task_ctx->wait_submit_cnt, hw_task_ctx->wait_child_cnt, hw_task_ctx->procid,
				tmp[0], tmp[1], tmp[2], tmp[3]);
			cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
			ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
			ffts_dump_sig_ctx_info(hw_task_ctx);
		}
		if (hw_task_ctx->parent_task_idx >= ffts_task_id_start && hw_task_ctx->parent_task_idx <= ffts_task_id_max) {
			u16 parent_task_idx = hw_task_ctx->parent_task_idx;
			hw_task_ctx = (struct ffts_hw_task_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_TASKCTX_DDR].virt_addr +
				(unsigned long)sizeof(struct ffts_hw_task_ctx) * hw_task_ctx->parent_task_idx);
			if (hw_task_ctx->status != 0) {
				tmp = (u32 *)hw_task_ctx;
				ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX,
					"\r\nparent_task_idx=%u, taskidx=%hu, status=%u, uid:%u:%x %x %x %x", hw_task_ctx->parent_task_idx,
					parent_task_idx, hw_task_ctx->status, hw_task_ctx->procid, tmp[0], tmp[1], tmp[2], tmp[3]);
				cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
				ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
			}
		}
	}
}
 
void ffts_dump_task_info(u16 uid, u16 tid, u16 taskidx)
{
	int ret;
	u32 *tmp = NULL;
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	ffts_hts_auth_table *auth_table = NULL;
	struct ffts_hw_thread_ctx *hw_thread_ctx = NULL;
	struct ffts_platform_info *plat_info = NULL;
	struct ffts_dev_ctx *dev_ctx = NULL;
 
	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "get dev_ctx failed\n");
	plat_info = ffts_plat_get_info();
	cond_return_void(plat_info == NULL, "get platform info error\n");
	cond_return_void(uid < FFRT_UNIFORM_ID_START || uid > FFRT_UNIFORM_ID_END, "invalid uid %hu\n", uid);
	mutex_lock(&dev_ctx->ffts_cmo_lock);
	ffts_cache_cmo_flush();
	mutex_unlock(&dev_ctx->ffts_cmo_lock);
 
	if (taskidx > 0 && taskidx < ffts_task_id_start) { // 通路3
		auth_table = (ffts_hts_auth_table *)(uintptr_t)(plat_info->resmem_desc[FFTS_HTS_AUTH_TABLE_DDR].virt_addr +
			(unsigned long)sizeof(ffts_hts_auth_table) * taskidx);
		ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX,
			"\r\ntaskidx=%hu, uid=%hu, auth_table_uid=%hu", taskidx, uid, auth_table->data.uid);
		cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
		ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
		return;
	}
 
	if (tid >= FFTS_TID_START && tid <= FFTS_TID_END) {
		hw_thread_ctx = (struct ffts_hw_thread_ctx *)(uintptr_t)(plat_info->resmem_desc[FFTS_THREADCTX_DDR].virt_addr +
			(unsigned long)sizeof(struct ffts_hw_thread_ctx) * tid);
		cond_return_void(hw_thread_ctx->valid != 1, "hw_thread_ctx is invalid\n");
		tmp = (u32 *)hw_thread_ctx;
		ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX, "\r\ntid=%u thread_ctx:%x %x",
			tid, tmp[0], tmp[1]);
		cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
		ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	}
	ffts_dump_task_ctx_info(taskidx);
}
