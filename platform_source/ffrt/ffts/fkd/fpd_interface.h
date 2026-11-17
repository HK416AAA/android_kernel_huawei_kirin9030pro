/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts fpd interface
 */

#ifndef _FPD_INTERFACE_H_
#define _FPD_INTERFACE_H_

#include "inc/ffts_common.h"
#include "ffts_platform.h"
#include "ffts_interrupt.h"
#include <linux/types.h>
#include "ffts_proc_ctx.h"
#include "ffts_ioctl_services.h"
#include "ffts_hw_config.h"

#ifdef CONFIG_FFRT_DEBUG
#include "ffts_perf_config.h"
#endif

struct fpd_registry {
	int (*fpd_power_manager)(enum fpd_pm pm_type, long para1);
	void (*fpd_get_resmem_info)(struct ffts_platform_info *plat_info);
	int (*fpd_set_hw_proc_ctx)(u16 uid, phys_addr_t rtb_addr);
	int (*fpd_reset_hw_proc_ctx)(u16 uid);
	int (*fpd_set_hw_thread_ctx)(u16 ffts_tid, struct ffts_mem_info *sq_des);
	int (*fpd_reset_hw_thread_ctx)(u16 ffts_tid);
	int (*fpd_set_device_info_mem_size)(ffts_device_info_t *device_info);
	int (*fpd_get_map_info)(struct ffts_proc_ctx *proc_ctx, ffts_mem_type map_type,
		unsigned long *base, unsigned long *len, struct list_head **vma_list);
	void (*fpd_thread_switch_config)(u8 lpid, u16 uid, u16 ffts_tid, u8 qos);
	void (*fpd_proc_block_handle)(struct ffts_dev_ctx *dev_ctx, struct ffts_proc_ctx *proc_ctx);
	void (*fpd_ffap1_clear_handle)(struct ffts_dev_ctx *dev_ctx, u16 task_id);
	void (*fpd_dump_info)(struct ffts_dev_ctx *dev_ctx);
	int (*fpd_normal_intr_work)(struct ffts_intr_info *g_intr_info_ptr, uint32_t st);
	int (*fpd_add_normal_intr_workqueue)(struct ffts_intr_info *g_intr_info_ptr);
	int (*fpd_abnormal_intr_work)(struct ffts_intr_info *g_intr_info_ptr, uint32_t st);
	int (*fpd_add_abnormal_intr_workqueue)(struct ffts_intr_info *g_intr_info_ptr);
#ifdef CONFIG_FFRT_DEBUG
	int (*fpd_perf_cmd)(struct ffts_perf_cfg *perf_cfg, ffts_perf_cmd_type cmd);
	int (*fpd_perf_dump)(void);
#endif
	int (*fpd_get_qos_task_cnt)(u16 uid, u8 qos);
	void (*fpd_get_task_status_info)(u16 uid, struct ffts_task_status_info *task_info);
	int (*fpd_set_tcb_procctx_table)(int uid, vir_addr_t tcb_addr);
};

int ffts_register_plat_driver(struct fpd_registry *fpd);
int ffts_unregister_plat_driver(void);

#endif