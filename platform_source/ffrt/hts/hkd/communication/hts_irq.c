/*
 * hts_irq.c
 *
 * about hts platform
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
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
#include "hts_irq.h"
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/io.h>
#include <linux/bitmap.h>
#include "soc_hts_interface.h"
#include "hts_kernel_log.h"
#include "hts_profiling.h"
#include "hts_interface.h"
#include "hts_cfg.h"
#include "hts_dmd_interface.h"
#include "hpd_interface.h"

void hts_zero_eventid_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx(); 
#endif
	SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_UNION event_in_back0;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	hts_drv_err("EVENT_IN:event_id is zero, interrupt no. =  %u\n", HTS_EVENT_IN_EVENT_ZERO_ERROR);

	event_in_back0.value = readl(SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err("HTS_EVENT_IN_ERROR_READ_BACK_0: last_event = %u, last_src_id = %u, last_uid = %u\n",
		event_in_back0.reg.event_in_check_error_last_event, event_in_back0.reg.event_in_check_error_last_src_id,
		event_in_back0.reg.event_in_check_error_last_uid);

#ifdef HTS_DEBUG_EN
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_IN_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif
}

void hts_event_in_check_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#endif
	SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_UNION event_in_back0; 
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	hts_drv_err("EVENT_IN: check uid failed,interrupt no. =  %u\n", HTS_EVENT_IN_CHECK_ERROR);

	event_in_back0.value = readl(SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err("HTS_EVENT_IN_ERROR_READ_BACK_0: last_event = %u, last_src_id = %u, last_uid = %u\n",
		event_in_back0.reg.event_in_check_error_last_event, event_in_back0.reg.event_in_check_error_last_src_id,
		event_in_back0.reg.event_in_check_error_last_uid);

#ifdef HTS_DEBUG_EN
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_IN_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif
}

void hts_ibuf_overflow_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx(); 
#endif
	SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_UNION event_in_back0;
	SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_UNION event_in_back1; 
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	hts_drv_err("EVENT_IN:event ibuf is overflow, interrupt no. =  %u\n", HTS_EVENT_IN_IBUF_OVERFLOW_EOORR);

	event_in_back0.value = readl(SOC_HTS_EVENT_IN_ERROR_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err("HTS_EVENT_IN_ERROR_READ_BACK_0: last_event = %u, last_src_id = %u, last_uid = %u\n",
		event_in_back0.reg.event_in_check_error_last_event, event_in_back0.reg.event_in_check_error_last_src_id,
		event_in_back0.reg.event_in_check_error_last_uid);

	event_in_back1.value = readl(SOC_HTS_EVENT_IN_ERROR_READ_BACK_1_ADDR(virt_addr));
	hts_drv_err("HTS_EVENT_IN_ERROR_READ_BACK_1: event_in_ibuf_overflow_error_last_event = %u\n",
		event_in_back1.reg.event_in_ibuf_overflow_error_last_event);

	if(sd_proxy_hts_record_and_notify(SD_PROXY_MINOR_CMD_FFRT_HTS_DMD_INBUF_OVERFLOW) != 0)
		hts_drv_err("hts dmd upload failed");

#ifdef HTS_DEBUG_EN
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_IN_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif

	hts_block_event(event_in_back1.reg.event_in_ibuf_overflow_error_last_event);
}

void hts_proc_no_rule_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN 
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#endif
	SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_UNION event_proc_back0;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	hts_drv_err("EVENT_PROC:event proc no rule, interrupt no. =  %u\n", HTS_EVENT_PROC_NO_RULE_ERROR);

	event_proc_back0.value = readl(SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err("HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_ADDR: event_proc_mapping_no_rule_error_last_event = %u\n",
		event_proc_back0.reg.event_proc_mapping_no_rule_error_last_event);

#ifdef HTS_DEBUG_EN 
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_PROC_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif
}

void hts_proc_illegal_rule_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN 
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#endif
	SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_UNION event_proc_back0;
	SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_UNION event_proc_back1;
	SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_UNION event_proc_back2;
	SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_UNION event_proc_back3;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	hts_drv_err("EVENT_PROC:hts rule is illegal or src_event is not match, interrupt no. =  %u\n",
		HTS_EVENT_PROC_RULE_ILLEGAL_ERROR);

	event_proc_back0.value = readl(SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_ADDR(virt_addr));
	event_proc_back1.value = readl(SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_ADDR(virt_addr));
	event_proc_back2.value = readl(SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_ADDR(virt_addr));
	event_proc_back3.value = readl(SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_ADDR(virt_addr));

	hts_drv_err("HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_0_ADDR: event_proc_mapping_no_rule_error_last_event = %u\n",
		event_proc_back0.reg.event_proc_mapping_no_rule_error_last_event);
	hts_drv_err("HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_1_ADDR: value = %u\n", event_proc_back1.value);
	hts_drv_err("HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_2_ADDR: value = %u\n", event_proc_back2.value);
	hts_drv_err("HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_3_ADDR: event_proc_process_illegal_rule_error_last_event = %u\n",
		event_proc_back3.reg.event_proc_process_illegal_rule_error_last_event);
#ifdef HTS_DEBUG_EN 
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_PROC_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif
}

void hts_proc_cnt_overflow_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN 
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#endif
	SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_UNION event_proc_back4;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	hts_drv_err("EVENT_PROC:status cnt is overflow, interrupt no. =  %u\n", HTS_EVENT_PROC_PROCESS_CNT_OVERFLOW_ERROR);

	event_proc_back4.value = readl(SOC_HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_ADDR(virt_addr));
	hts_drv_err("HTS_EVENT_PROC_PROCESS_ERROR_READ_BACK_4_ADDR: event_proc_mapping_no_rule_error_last_event = %u\n",
		event_proc_back4.reg.event_proc_process_status_overflow_error_last_event);
#ifdef HTS_DEBUG_EN 
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_PROC_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif
}

void hts_obuf_overflow_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN 
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#endif
	uint16_t src_event;
	uint16_t dst_event = 0;
	struct hpd_registry *hpd = NULL;
	hpd = hts_get_hpd_registry();
	
	hts_drv_err("EVENT_OUT:event obuf overflow, interrupt no. =  %u\n", HTS_EVENT_OUT_OBUF_OVERFLOW_ERROR);
	if (hpd != NULL && hpd->hts_obuf_overflow_profiling != NULL)
		dst_event = hpd->hts_obuf_overflow_profiling();
	else
		hts_drv_err("hpd or hts_obuf_overflow_profiling is null");
	
	if (sd_proxy_hts_record_and_notify(SD_PROXY_MINOR_CMD_FFRT_HTS_DMD_ONBUF_OVERFLOW) != 0)
		hts_drv_err("hts dmd upload failed");

#ifdef HTS_DEBUG_EN 
	mutex_lock(&dev_ctx->mtx);
	hts_info_readback(HTS_DUMP_EVENT_OUT_INFO);
	mutex_unlock(&dev_ctx->mtx);
#endif
	src_event = hts_get_src_event_by_dst_event(dst_event);
	if(src_event != 0)
		hts_block_event(src_event);
}

int hts_register_irq(struct hts_platform_info *platform_info)
{
	int ret;
	int irq_abnormal;
	struct hpd_registry *hpd = NULL;
	cond_return_error(platform_info == NULL, -ENOMEM,
		"platform_info is null\n");
	irq_abnormal = platform_info->dts_info.irq_abnormal;
	hts_drv_warn("irq_abnormal = %d \n", irq_abnormal);

	hpd = hts_get_hpd_registry();
	if (hpd == NULL || hpd->hts_irq_init == NULL) {
		hts_drv_err("hpd or hts_irq_init is null\n");
		return -EINVAL;
	}
	ret = hpd->hts_irq_init(irq_abnormal);
	if (ret != 0) {
		hts_drv_err("irq init failed, ret = %d", ret);
		return -EINVAL;
	}
	return 0;
}

void hts_unregister_irq(struct hts_platform_info *platform_info)
{
	int irq_abnormal;
	cond_return_void(platform_info == NULL, "platform_info is null\n");
	irq_abnormal = platform_info->dts_info.irq_abnormal;
	free_irq(irq_abnormal, NULL);
}