/*
 * ffts_main.c
 *
 * ffts main
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
#include <linux/module.h>

#include "fpd_interface.h"
#include "ffts_hw_config.h"
#include "ffts_platform_pm.h"
#include "ffts_resmem.h"
#include "ffts_intr_config.h"

#ifdef CONFIG_FFRT_DEBUG
#include "ffts_perf_config.h"
#endif

static int ffts_power_manager(fpd_pm_t pm_type, long para1)
{
	int ret = 0;

	switch(pm_type)
	{
	case FPD_PM_POWER_UP:
		ret = ffts_plat_pm_powerup((u32)para1);
		break;
	case FPD_PM_POWER_DOWN:
		ret = ffts_plat_pm_powerdown();
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}

struct fpd_registry g_fpd_registry = {
	.fpd_power_manager = ffts_power_manager,
	.fpd_get_resmem_info = ffts_plat_get_resmem_info,
	.fpd_set_hw_proc_ctx = ffts_plat_set_hw_proc_ctx,
	.fpd_reset_hw_proc_ctx = ffts_plat_reset_hw_proc_ctx,
	.fpd_set_hw_thread_ctx = ffts_plat_set_hw_thread_ctx,
	.fpd_reset_hw_thread_ctx = ffts_plat_reset_hw_thread_ctx,
	.fpd_thread_switch_config = ffts_plat_thread_switch_config,
	.fpd_proc_block_handle = ffts_plat_proc_block_handle,
	.fpd_ffap1_clear_handle = ffts_ffap1_clear_handle,
	.fpd_dump_info = ffts_plat_dump_info,
	.fpd_normal_intr_work = ffts_normal_intr_work,
	.fpd_add_normal_intr_workqueue = ffts_add_normal_intr_workqueue,
	.fpd_abnormal_intr_work = ffts_abnormal_intr_work,
	.fpd_add_abnormal_intr_workqueue = ffts_add_abnormal_intr_workqueue,
#ifdef CONFIG_FFRT_DEBUG
	.fpd_perf_cmd = ffts_perf_cmd,
	.fpd_perf_dump = ffts_perf_dump_cmd,
#endif
	.fpd_set_device_info_mem_size = ffts_set_device_info_mem_size,
	.fpd_get_map_info = ffts_get_map_info,
	.fpd_get_qos_task_cnt = ffts_get_qos_task_cnt,
	.fpd_get_task_status_info = ffts_plat_get_task_status_info,
	.fpd_set_tcb_procctx_table = ffts_set_tcb_procctx_table,
};

static int __init fpd_init(void)
{
	ffts_register_plat_driver(&g_fpd_registry);

	return 0;
}
module_init(fpd_init);

static void __exit fpd_exit(void)
{
	ffts_unregister_plat_driver();
}
module_exit(fpd_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("FFTS Platform driver");
MODULE_VERSION("V1.0");