/*
 * ffts_intr_config.c
 *
 * ffts interrupt config
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

#include "ffts_intr_config.h"

#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <platform_include/cee/linux/sched/ffrt/ffts_sched.h>
#include <securec.h>

#include "dfx/ffts_log.h"
#include "soc_ffts_interface.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "uniform_id.h"
#include "bbox/ffts_dfx_black_box.h"
#include "ffts_log.h"
#include "ffts_platform.h"
#include "ffts_interrupt.h"
#include "ffts_hw_config.h"

#ifdef CONFIG_FFRT_DEBUG
#include "perf/ffts_perf.h"
#include "ffts_perf_config.h"
#include "ffts_resmem.h"
#endif

#define FFTS_PERF_BUFF_LEN_MAX 128

int ffts_normal_intr_work(struct ffts_intr_info *intr_info, uint32_t st)
{
    // At present, this chip version doesn't have any queued or nonqueued normal interrupt to handle
    return 0;
}

int ffts_add_normal_intr_workqueue(struct ffts_intr_info *intr_info)
{
    // At present, this chip version doesn't have any queued or nonqueued normal interrupt to handle
    return 0;
}

static ffts_acpu_intrq_abnormal_info_u *ffts_get_intrq_abnormal_info(struct ffts_platform_info *plat_info, uint16_t id)
{
	vir_addr_t acpu_intrq_base = plat_info->resmem_desc[FFTS_ACPU_INT_QUEUE_DDR].virt_addr;
	ffts_acpu_intrq_abnormal_info_u *intrq;

	intrq = (ffts_acpu_intrq_abnormal_info_u *)(uintptr_t)
		(acpu_intrq_base + sizeof(ffts_acpu_intrq_abnormal_info_u) * id);
	return intrq;
}

void ffts_get_intr_abnormal_ptr(struct ffts_platform_info *plat_info, uint16_t *read, uint16_t *write)
{
	SOC_FFTS_INTRQ_ABNM_PTR_UNION ptr = {0};
	vir_addr_t kernel_reg_base = ffts_get_reg_base();

	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");
	ptr.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_INTRQ_ABNM_PTR_ADDR(kernel_reg_base));
	*read = ptr.reg.intrq_abnormal_rptr;
	*write = ptr.reg.intrq_abnormal_wptr;
}

void ffts_cancel_abnormal_by_uid(u16 uid)
{
	uint16_t read = 0;
	uint16_t write = 0;
	ffts_acpu_intrq_abnormal_info_u *info =NULL;
	struct ffts_platform_info *plat_info = NULL;

	plat_info = ffts_plat_get_info();
	cond_return_void(plat_info == NULL, "get platform info fail\n");

	ffts_get_intr_abnormal_ptr(plat_info, &read, &write);

	while (read != write) {
		info = ffts_get_intrq_abnormal_info(plat_info, read);
		if (info->data.uid == uid)
			info->data.uid = 0;
		read = (read + 1) % FFTS_ACPU_INTRQ_NUM;
	}
}

static void ffts_abnormal_intr_case_handler_a(ffts_acpu_intrq_abnormal_info_u *info)
{
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	int ret;
	pid_t pid;
	struct ffts_intr_info* ptr = ffts_get_intr_info_ptr();
	cond_return_void(ptr == NULL, "get intr info fail\n");

	ptr->abnormal_intr_count[info->data.opc]++;
	pid = ffrt_get_pid_by_uid(info->data.uid);
	ffts_drv_err("get except, opc = %d, uid = %d, pid = %d, qos = %d, cmd = %d, tid = %d, taskidx = %d\n",
		info->data.opc, info->data.uid, pid, info->data.qos, info->data.cmd, info->data.tid, info->data.taskidx);

	ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX,
		"\r\nabnormal info:\r\nget typeA except, type = %d, uid = %d, taskIdx = %d, cmd = %d",
		info->data.opc, info->data.uid, info->data.taskidx, info->data.cmd);
	cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
	ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	ffts_dump_task_info(info->data.uid, info->data.tid, info->data.taskidx);
	ffts_rdr_exception_report(EXC_TYPE_ABNORMAL_EXCEPTION);	
}

static void ffts_abnormal_intr_case_handler_b(ffts_acpu_intrq_abnormal_info_u *info)
{
	pid_t pid;
	struct ffts_intr_info* ptr = ffts_get_intr_info_ptr();
	cond_return_void(ptr == NULL, "get intr info fail\n");

	ptr->abnormal_intr_count[info->data.opc]++;
	pid = ffrt_get_pid_by_uid(info->data.uid);
	ffts_drv_err("get except, opc = %d, uid = %d, pid = %d, qos = %d, cmd = %d, tid = %d, taskidx = %d\n",
		info->data.opc, info->data.uid, pid, info->data.qos, info->data.cmd, info->data.tid, info->data.taskidx);
}

static void ffts_abnormal_intr_case_handler_c(ffts_acpu_intrq_abnormal_info_u *info)
{
	char log_buf[FFTS_BUF_LEN_MAX + 1] = {0};
	int ret;
	pid_t pid;
	struct ffts_intr_info* ptr = ffts_get_intr_info_ptr();
	cond_return_void(ptr == NULL, "get intr info fail\n");

	ptr->abnormal_intr_count[info->data.opc]++;
	pid = ffrt_get_pid_by_uid(info->data.uid);
	ffts_drv_err("get except, opc = %d, uid = %d, pid = %d, qos = %d, cmd = %d, tid = %d, taskidx = %d\n",
		info->data.opc, info->data.uid, pid, info->data.qos, info->data.cmd, info->data.tid, info->data.taskidx);
	ret = snprintf_s(log_buf, FFTS_BUF_LEN_MAX + 1, FFTS_BUF_LEN_MAX,
		"\r\nabnormal info:\r\nget typeC except, type = %d, uid = %d, tid = %d, cmd = %d",
		info->data.opc, info->data.uid, info->data.tid, info->data.cmd);
	cond_return_void(ret < 0, "snprintf_s fail, ret = %d\n", ret);
	ffts_mntn_copy_reg_to_bbox(log_buf, (unsigned int)strlen(log_buf));
	ffts_dump_task_info(info->data.uid, info->data.tid, info->data.taskidx);
	ffts_rdr_exception_report(EXC_TYPE_ABNORMAL_EXCEPTION);
}

static void ffts_abnormal_intr_case_handler_default(ffts_acpu_intrq_abnormal_info_u *info)
{
	ffts_drv_err("invalid opc = %d, value = 0x%x\n", info->data.opc, info->data.taskidx);
}

typedef void (*ffts_abnormal_intr_case_handler)(ffts_acpu_intrq_abnormal_info_u *);

static ffts_abnormal_intr_case_handler ffts_abnormal_intr_list[FFTS_INTRQ_ABNORMAL_MAX] = {
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_a,
	ffts_abnormal_intr_case_handler_a,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_c,
	ffts_abnormal_intr_case_handler_c,
	ffts_abnormal_intr_case_handler_c,
	ffts_abnormal_intr_case_handler_c,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
	ffts_abnormal_intr_case_handler_b,
};

static void ffts_abnormal_list_intr_handler(ffts_acpu_intrq_abnormal_info_u *info)
{
	uint32_t key = info->data.opc;
	if (key >= FFTS_INTRQ_ABNORMAL_ACC_ABNM_0 && key < FFTS_INTRQ_ABNORMAL_MAX) {
		ffts_abnormal_intr_list[key](info);
	} else {
		ffts_abnormal_intr_case_handler_default(info);
	}
}

static void ffts_update_intr_abnormal_ptr(struct ffts_platform_info *plat_info, uint16_t read)
{
	SOC_FFTS_INTRQ_ABNM_PTR_UNION ptr = {0};
	vir_addr_t kernel_reg_base = ffts_get_reg_base();

	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");
	ptr.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_INTRQ_ABNM_PTR_ADDR(kernel_reg_base));
	ptr.reg.intrq_abnormal_rptr = read;
	ptr.reg.intrq_abnormal_rptr_upd = 1;
	writel(ptr.value, (volatile void *)(uintptr_t)SOC_FFTS_INTRQ_ABNM_PTR_ADDR(kernel_reg_base));
}

static void ffts_abnormal_list_intr_work(struct work_struct *work __attribute__((__unused__)))
{
	uint16_t read = 0;
	uint16_t write = 0;
	struct ffts_dev_ctx *dev_ctx = NULL;
	ffts_acpu_intrq_abnormal_info_u *info =NULL;
	struct ffts_platform_info *plat_info = NULL;

	plat_info = ffts_plat_get_info();
	cond_return_void(plat_info == NULL, "get platform info fail\n");

	dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "get dev ctx fail\n");

	// Must be mutually exclusive with the process block
	mutex_lock(&dev_ctx->ffts_hw_operation_lock);
	ffts_get_intr_abnormal_ptr(plat_info, &read, &write);

	while (read != write) {
		info = ffts_get_intrq_abnormal_info(plat_info, read);
		if (info->data.uid != 0)
			ffts_abnormal_list_intr_handler(info);
		read = (read + 1) % FFTS_ACPU_INTRQ_NUM;
	}

	ffts_update_intr_abnormal_ptr(plat_info, read);
	mutex_unlock(&dev_ctx->ffts_hw_operation_lock);
}

static void ffts_abnormal_proc_block_work(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_warn("proc block handle finish\n");
}

static void ffts_abnormal_gpu_intr_work(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_warn("gpu rtb threshold exceeded\n");
}

static void ffts_abnormal_npu_intr_work(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_warn("npu rtb threshold exceeded\n");
}

extern hw_ffap1_connect_cb g_hw_ffap1_connect_cb[FFTS_HW_MAX];
static void ffts_abnormal_ffap1_awake_work(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_warn("gpu ffap need to be awaken\n");

	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_void(dev_ctx == NULL, "get dev ctx fail\n");

	if (dev_ctx->ffap1_register_status[FFTS_HW_GPU] == false) {
		ffts_drv_warn("gpu not register ffap1 connect cb");
		return;
	}

	if (g_hw_ffap1_connect_cb[FFTS_HW_GPU].connect_cb == NULL) {
		ffts_drv_warn("gpu register ffap1 connect cb is nullptr");
		return;
	}

	g_hw_ffap1_connect_cb[FFTS_HW_GPU].connect_cb();
}

static void ffts_abnormal_ffap1_gpu_timeout(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("gpu ffap1 timeout intr!!!");
}
 
static void ffts_abnormal_ffap1_npu_hwts_timeout(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("npu hwts ffap1 timeout intr!!!");
}
 
static void ffts_abnormal_ffap1_aae_timeout(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("aae ffap1 timeout intr!!!");
}

static void ffts_abnormal_cache_flush_complete(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("cache flush complete intr!!!");
}

static void ffts_abnormal_perf_overflow(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("perf overflow intr!!!");
}

static void ffts_abnormal_pmu_overflow(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("pmu overflow intr!!!");
}

static void ffts_abnormal_acpu_abnormal_list_overflow(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("acpu abnormal list overflow intr!!!");
}

static void ffts_abnormal_msg_bus_overflow(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("msg bus overflow intr!!!");
}

static void ffts_acpu_awake_list_overflow(struct work_struct *work __attribute__((__unused__)))
{
	ffts_drv_err("acpu awake list overflow intr!!!");
}

#ifdef CONFIG_FFRT_DEBUG
static void ffts_record_perf_to_dynamic_mem(void)
{
	struct ffts_mem_info *ptr;
	ffts_perf_profiling_device_t *prof_dev;
	vir_addr_t perf_ddr_base;
	char perf_file_name[FFTS_PERF_BUFF_LEN_MAX] = {0};
	int ret;
	uint64_t len;
	ffts_drv_warn("enter into perf overflow interrupt handle\n");

	if (!ffts_get_perf_status()) {
		ffts_drv_err("ffts hardware perf is not enable\n");
	}

	if (ffts_get_perf_status() && ffts_get_mem_status()) {
		ffts_drv_warn("begin to record perf data into allocated mem\n");

		ptr = get_resmem_desc(FFTS_PERF_DDR);
		cond_return_void(ptr == NULL, "get plat info error\n");
		prof_dev = ffts_get_perf_dev_ptr();
		cond_return_void(prof_dev == NULL, "get perf info error\n");

		perf_ddr_base = ptr->virt_addr;
		len = prof_dev->perf_data_mem.write + prof_dev->perf_data_mem.perf_ddr_size - prof_dev->perf_data_mem.read;
		ffts_drv_warn("ffts dynamic mem write ptr: %llx, ffts dynamic mem read ptr: %llx, ffts dynamic mem usage: %d", 
            prof_dev->perf_data_mem.write, prof_dev->perf_data_mem.read, len);

		if (len >= prof_dev->perf_data_mem.mem_size) {
			ffts_drv_err("ffts perf record in dynamic memory will be overwritten!!!\n");
			// when overwritten happened, only update write ptr = read ptr and record err log
			prof_dev->perf_data_mem.write = prof_dev->perf_data_mem.read;
		}

		ret = memcpy_s(prof_dev->perf_data_mem.write, prof_dev->perf_data_mem.perf_ddr_size, perf_ddr_base, FFTS_PERF_DDR_LEN);
		cond_return_void(ret != EOK, "memcpy perf data failed\n");

		// after memory copy, update memory write ptr
		prof_dev->perf_data_mem.write += prof_dev->perf_data_mem.perf_ddr_size;
	}
}
#endif

int ffts_abnormal_intr_work(struct ffts_intr_info *intr_info, uint32_t st)
{
	ffts_drv_info("abnormal st reg value:%d\n", st);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_LIST)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_LIST]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_PROC_BLOCK_COMPLETE)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_PROC_BLOCK_COMPLETE]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_HWRTB_OVERFLOW_GPU)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_HWRTB_OVERFLOW_GPU]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_FFAP1_AWAKE_GPU)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_AWAKE_GPU]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_NPU_HWTS)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_NPU_HWTS]);
	if ((st & (0x1 << FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_GPU)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_GPU]);
	if ((st & (0x1 << FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_AAE)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_AAE]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_CACHE_FLUSH_COMPLETE)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_CACHE_FLUSH_COMPLETE]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_PERF_OVERFLOW)) != 0) {
#ifdef CONFIG_FFRT_DEBUG
		ffts_record_perf_to_dynamic_mem();
#endif
		queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_PERF_OVERFLOW]);
	}
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_PMU_OVERFLOW)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_PMU_OVERFLOW]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_ACPU_ABNORMAL_LIST_OVERFLOW)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_ACPU_ABNORMAL_LIST_OVERFLOW]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_MSG_BUS_OVERFLOW)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_MSG_BUS_OVERFLOW]);
    if ((st & (0x1 << FFTS_INTR_ABNORMAL_AWAKE_INTRQ_OVERFLOW_ACPU)) != 0)
        queue_work(intr_info->abnormal_intr_wq, &intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_AWAKE_INTRQ_OVERFLOW_ACPU]);
    return 0;
}

int ffts_add_abnormal_intr_workqueue(struct ffts_intr_info *intr_info)
{
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_LIST], ffts_abnormal_list_intr_work);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_PROC_BLOCK_COMPLETE], ffts_abnormal_proc_block_work);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_HWRTB_OVERFLOW_GPU], ffts_abnormal_gpu_intr_work);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_AWAKE_GPU], ffts_abnormal_ffap1_awake_work);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_GPU], ffts_abnormal_ffap1_gpu_timeout);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_NPU_HWTS], ffts_abnormal_ffap1_npu_hwts_timeout);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_FFAP1_TASK_TIMEOUT_AAE], ffts_abnormal_ffap1_aae_timeout);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_CACHE_FLUSH_COMPLETE], ffts_abnormal_cache_flush_complete);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_PERF_OVERFLOW], ffts_abnormal_perf_overflow);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_PMU_OVERFLOW], ffts_abnormal_pmu_overflow);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_ACPU_ABNORMAL_LIST_OVERFLOW], ffts_abnormal_acpu_abnormal_list_overflow);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_MSG_BUS_OVERFLOW], ffts_abnormal_msg_bus_overflow);
	INIT_WORK(&intr_info->abnormal_intr_work[FFTS_INTR_ABNORMAL_AWAKE_INTRQ_OVERFLOW_ACPU], ffts_acpu_awake_list_overflow);
    return 0;
}