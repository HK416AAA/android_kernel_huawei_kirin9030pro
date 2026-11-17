/*
 * hpd_intr.c
 *
 * hpd intr
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

#include "hpd_intr.h"
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/io.h>
#include "hts_irq.h"
#include "hts_cfg.h"
#include "soc_hts_interface.h"
#include "hts_profiling.h"
#include "hts_kernel_log.h"
#include "hts_interface.h"
#include "dmd/hts_dmd_interface.h"
#include "hpd_interface.h"
#include "hts_platform.h"
#include "hts_common_resource.h"
#include "hpd_profiling.h"

static struct hts_intr_info g_intr_info[HTS_INTR_MAX];

static void hts_ffts_obuf_overflow_func(struct work_struct *work __attribute__((__unused__)))
{
#ifdef HTS_DEBUG_EN 
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#endif
	uint16_t dst_event = 0;
	struct hpd_registry *hpd = NULL;
	hpd = hts_get_hpd_registry();
	
	hts_drv_err("EVENT_OUT:event ffts_obuf overflow, interrupt no. = %u\n", HTS_EVENT_FFTS_OUT_OBUF_OVERFLOW_ERROR);
	dst_event = hts_ffts_obuf_overflow_profiling ();

	if (sd_proxy_hts_record_and_notify(SD_PROXY_MINOR_CMD_FFRT_HTS_DMD_ONBUF_OVERFLOW) != 0)
		hts_drv_err("hts dmd upload failed");
 
#ifdef HTS_DEBUG_EN 
	mutex_lock(&dev_ctx->mtx);
	hts_dump_ffts_event_out_info();
	mutex_unlock(&dev_ctx->mtx);
#endif
	if (dst_event != 0)
		ffts_outbuff_block_event(dst_event);
}

static struct hts_intr_proc_handle g_hts_intr_proc_handle[HTS_INTR_ERROR_NUM] = {
	{HTS_EVENT_IN_EVENT_ZERO_ERROR,                hts_zero_eventid_func},
	{HTS_EVENT_IN_CHECK_ERROR,                     hts_event_in_check_func},
	{HTS_EVENT_IN_IBUF_OVERFLOW_EOORR,             hts_ibuf_overflow_func},
	{HTS_EVENT_PROC_NO_RULE_ERROR,                 hts_proc_no_rule_func},
	{HTS_EVENT_PROC_RULE_ILLEGAL_ERROR,            hts_proc_illegal_rule_func},
	{HTS_EVENT_PROC_PROCESS_CNT_OVERFLOW_ERROR,    hts_proc_cnt_overflow_func},
	{HTS_EVENT_OUT_OBUF_OVERFLOW_ERROR,            hts_obuf_overflow_func},
	{HTS_EVENT_FFTS_OUT_OBUF_OVERFLOW_ERROR,       hts_ffts_obuf_overflow_func}
};

irqreturn_t hts_except_handler(int irq, void *data)
{
	uint32_t reg_value;
	uint32_t intr_mask = HTS_INT_MASK;
	uint32_t i;

	reg_value = readl(SOC_HTS_INT_ADDR(hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE)));
	// clear interrupts
	writel(reg_value & intr_mask, SOC_HTS_INT_ADDR(hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE)));

	for (i = 0; i < HTS_INTR_ERROR_NUM; i++) {
		if (g_intr_info[HTS_INTR_EXCEPT].intr_wq != NULL && ((reg_value >> i) & 0x1) == 1) 
			queue_work(g_intr_info[HTS_INTR_EXCEPT].intr_wq, &g_intr_info[HTS_INTR_EXCEPT].intr_work[i]);
	}
	
	return IRQ_HANDLED;
}

int hts_irq_init(int irq_abnormal)
{
	uint32_t i;
    int ret;

    ret = request_irq(irq_abnormal, hts_except_handler, IRQF_TRIGGER_NONE, "hts_except_handler", NULL);
    if (ret != 0) {
		hts_drv_err("request except irq failed, ret = %d, id[%d]", ret, irq_abnormal);
		return -EINVAL;
	}

	g_intr_info[HTS_INTR_EXCEPT].intr_wq = create_workqueue("hts-drv-except");
	if (g_intr_info[HTS_INTR_EXCEPT].intr_wq == NULL) {
		hts_drv_err("create except intr workqueue error\n");
        free_irq(irq_abnormal, NULL);
		return -EINVAL;
	}

    for (i = 0; i < HTS_INTR_ERROR_NUM; i++)
		INIT_WORK(&g_intr_info[HTS_INTR_EXCEPT].intr_work[i], g_hts_intr_proc_handle[i].intr_proc_proc);
    
    return 0;
}