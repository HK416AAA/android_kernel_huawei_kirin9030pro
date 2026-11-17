/*
 * ffts_interrupt.c
 *
 * ffts interrupt
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
#include "ffts_interrupt.h"

#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <platform_include/cee/linux/sched/ffrt/ffts_sched.h>
#include <securec.h>

#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "uniform_id.h"
#include "ffts_dfx_black_box.h"
#include "ffts_log.h"
#include "fpd_interface.h"
#include "ffts_platform.h"

static struct ffts_intr_info g_intr_info;

struct ffts_intr_info* ffts_get_intr_info_ptr(void)
{
	return &g_intr_info;
}

uint32_t ffts_get_abnormal_count(ffts_intrq_abnormal_type_e type)
{
	if (type >= FFTS_INTRQ_ABNORMAL_ACC_ABNM_0 && type < FFTS_INTRQ_ABNORMAL_MAX)
		return g_intr_info.abnormal_intr_count[type];
	return 0;
}
uint32_t ffts_get_dfx_count(void)
{
	return g_intr_info.abnormal_dfx_info_count;
}

static uint32_t ffts_get_intr_normal_st_and_clear(void)
{
	SOC_FFTS_INTR_NRML_ST_UNION st = {0};
	SOC_FFTS_INTR_NRML_CLR_UNION clr = {0};
	u64 kernel_reg_base;

	kernel_reg_base = ffts_get_reg_base();
	cond_return_error(kernel_reg_base == 0, 0, "get reg base failed\n");

	st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_INTR_NRML_ST_ADDR(kernel_reg_base));

	clr.reg.intr_normal_clr = st.reg.intr_normal_st;
	writel(clr.value, (volatile void *)(uintptr_t)SOC_FFTS_INTR_NRML_CLR_ADDR(kernel_reg_base));
	return st.reg.intr_normal_st;
}

static void ffts_get_intr_normal_ptr(u16 *read, u16 *write)
{
	SOC_FFTS_INTRQ_NRML_PTR_UNION ptr = {0};
	u64 kernel_reg_base;

	kernel_reg_base = ffts_get_reg_base();
	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");

	ptr.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_INTRQ_NRML_PTR_ADDR(kernel_reg_base));
	*read = ptr.reg.intrq_normal_rptr;
	*write = ptr.reg.intrq_normal_wptr;
}

static void ffts_update_intr_normal_ptr(u16 read)
{
	SOC_FFTS_INTRQ_NRML_PTR_UNION ptr = {0};
	u64 kernel_reg_base;

	kernel_reg_base = ffts_get_reg_base();
	cond_return_void(kernel_reg_base == 0, "get reg base failed\n");

	ptr.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_INTRQ_NRML_PTR_ADDR(kernel_reg_base));
	ptr.reg.intrq_normal_rptr = read;
	ptr.reg.intrq_normal_rptr_upd = 1;
	writel(ptr.value, (volatile void *)(uintptr_t)SOC_FFTS_INTRQ_NRML_PTR_ADDR(kernel_reg_base));
}

static void ffts_get_intrq_normal_info(u16 id, u16 *uid, u8 *qos)
{
	struct ffts_platform_info *plat_info = NULL;
	vir_addr_t acpu_intrq_base;
	ffts_acpu_intrq_normal_info_u *intrq = NULL;

	plat_info = ffts_plat_get_info();
	cond_return_void(plat_info == NULL, "get platform info fail\n");

	acpu_intrq_base = plat_info->resmem_desc[FFTS_ACPU_INT_QUEUE_DDR].virt_addr;

	intrq = (ffts_acpu_intrq_normal_info_u *)(uintptr_t)
		(acpu_intrq_base + FFTS_ACPU_ABNORMAL_INT_QUEUE_DDR_LEN + sizeof(ffts_acpu_intrq_normal_info_u) * id);
	*uid = intrq->data.uid;
	*qos = intrq->data.qos;
}

static void ffts_normal_list_intr_proc(void)
{
	uint16_t read = 0;
	uint16_t write = 0;
	u16 uid = 0;
	u8 qos = 0;
	pid_t pid;

	ffts_get_intr_normal_ptr(&read, &write);

	while (read != write) {
		ffts_get_intrq_normal_info(read, &uid, &qos);
		pid = ffrt_get_pid_by_uid(uid);
		if (pid > 0)
			ffts_sched_worker_wakeup(pid, qos);
		read++;
		if (read == FFTS_ACPU_INTRQ_NUM)
			read = 0;
	}

	ffts_update_intr_normal_ptr(read);
}

static irqreturn_t ffts_normal_handler(int irq, void *data)
{
	// 1. read intr st
	uint32_t st = ffts_get_intr_normal_st_and_clear();
	struct fpd_registry* fpd = NULL;
	// 2. intr normal list
	if ((st & (0x1 << FFTS_INTR_NORMAL_LIST)) != 0) {
		ffts_normal_list_intr_proc();
		st &= ~(0x1 << FFTS_INTR_NORMAL_LIST);
	}

	fpd = get_fpd();
	if (fpd->fpd_normal_intr_work != NULL) {
		fpd->fpd_normal_intr_work(&g_intr_info, st);
	}

	return IRQ_HANDLED;
}

static void ffts_abnormal_dfx_intr_work(struct work_struct *work __attribute__((__unused__)))
{
	uint8_t read = g_intr_info.abnormal_dfx_info_read;
	uint8_t write = g_intr_info.abnormal_dfx_info_write;

	while (read != write) {
		ffts_drv_err("dfx info: org_status 0x%x, mask_status 0x%x, type 0x%x, info 0x%x\n",
			g_intr_info.abnormal_dfx_info[read].org_status,
			g_intr_info.abnormal_dfx_info[read].mask_status,
			g_intr_info.abnormal_dfx_info[read].type,
			g_intr_info.abnormal_dfx_info[read].info);
		read = (read + 1) % FFTS_DFX_INFO_MAX;
	}
	g_intr_info.abnormal_dfx_info_read = read;
}

static void ffts_get_dfx_info(u64 kernel_reg_base)
{
	uint8_t read = g_intr_info.abnormal_dfx_info_read;
	uint8_t write = g_intr_info.abnormal_dfx_info_write;

	if (write + 1 != read) {
		g_intr_info.abnormal_dfx_info[write].org_status =
			readl((const volatile void *)(uintptr_t)SOC_FFTS_INTR_DFX_ORG_STATUS_ADDR(kernel_reg_base));
		g_intr_info.abnormal_dfx_info[write].mask_status =
			readl((const volatile void *)(uintptr_t)SOC_FFTS_INTR_DFX_MASK_STATUS_ADDR(kernel_reg_base));
		g_intr_info.abnormal_dfx_info[write].type =
			readl((const volatile void *)(uintptr_t)SOC_FFTS_INTR_DFX_TYPE_ADDR(kernel_reg_base));
		g_intr_info.abnormal_dfx_info[write].info =
			readl((const volatile void *)(uintptr_t)SOC_FFTS_INTR_DFX_INFO_ADDR(kernel_reg_base));
		g_intr_info.abnormal_dfx_info_write = (g_intr_info.abnormal_dfx_info_write + 1) % FFTS_DFX_INFO_MAX;
		g_intr_info.abnormal_dfx_info_count++;
	} else {
		g_intr_info.abnormal_dfx_info_lose_count++;
	}
}

static irqreturn_t ffts_abnormal_handler(int irq, void *data)
{
	// 1. read intr st
	struct ffts_platform_info *plat_info = NULL;
	SOC_FFTS_INTR_ABNM_ST_UNION st = {0};
	SOC_FFTS_INTR_ABNM_CLR_UNION clr = {0};
	struct fpd_registry* fpd = NULL;
	u64 kernel_reg_base;

	plat_info = ffts_plat_get_info();
	cond_return_error(plat_info == NULL, IRQ_NONE, "get platform info fail\n");

	kernel_reg_base = ffts_get_reg_base();
	cond_return_error(kernel_reg_base == 0, IRQ_NONE, "get reg base failed\n");

	st.value = readl((const volatile void *)(uintptr_t)SOC_FFTS_INTR_ABNM_ST_ADDR(kernel_reg_base));

	// 2. intr abnormal proc
	if (g_intr_info.abnormal_intr_wq != NULL) {
		fpd = get_fpd();
		if (fpd->fpd_abnormal_intr_work != NULL) {
			fpd->fpd_abnormal_intr_work(&g_intr_info, st.value);
		}

		if ((st.reg.intr_abnormal_st & (0x1 << FFTS_INTR_ABNORMAL_DFX)) != 0) {
			// read dfx info
			ffts_get_dfx_info(kernel_reg_base);
			queue_work(g_intr_info.abnormal_intr_wq, &g_intr_info.abnormal_intr_work[FFTS_INTR_ABNORMAL_DFX]);
		}
	}

	// 3. clr intr
	clr.reg.intr_abnormal_clr = st.reg.intr_abnormal_st;
	writel(clr.value, (volatile void *)(uintptr_t)SOC_FFTS_INTR_ABNM_CLR_ADDR(kernel_reg_base));
	return IRQ_HANDLED;
}

static int create_normal_intr_workqueue(struct ffts_platform_info *platform_info)
{
	struct fpd_registry* fpd = NULL;

    g_intr_info.normal_intr_wq = create_workqueue("ffts-drv-normal");
    if (g_intr_info.normal_intr_wq == NULL) {
        ffts_drv_err("create normal intr workqueue error\n");
        return -ENOMEM;
    }

	fpd = get_fpd();
	if (fpd->fpd_add_normal_intr_workqueue != NULL) {
		fpd->fpd_add_normal_intr_workqueue(&g_intr_info);
	}

    return 0;
}

static int create_abnormal_intr_workqueue(struct ffts_platform_info *platform_info)
{
	uint32_t i;
	struct fpd_registry* fpd = NULL;

    g_intr_info.abnormal_intr_wq = create_workqueue("ffts-drv-abnormal");
    if (g_intr_info.abnormal_intr_wq == NULL) {
        ffts_drv_err("create except intr workqueue error\n");
        return -ENOMEM;
    }

	fpd = get_fpd();
	if (fpd->fpd_add_abnormal_intr_workqueue != NULL) {
		fpd->fpd_add_abnormal_intr_workqueue(&g_intr_info);
	}

    INIT_WORK(&g_intr_info.abnormal_intr_work[FFTS_INTR_ABNORMAL_DFX], ffts_abnormal_dfx_intr_work);

    for (i = 0; i < FFTS_INTRQ_ABNORMAL_MAX; i++)
        g_intr_info.abnormal_intr_count[i] = 0;
	
    g_intr_info.abnormal_dfx_info_read = 0;
    g_intr_info.abnormal_dfx_info_write = 0;
    g_intr_info.abnormal_dfx_info_count = 0;
    g_intr_info.abnormal_dfx_info_lose_count = 0;

    return 0;
}

int ffts_register_irq(struct ffts_platform_info *platform_info)
{
    int ret;
    unsigned int irq_normal, irq_abnormal;

    cond_return_error(platform_info == NULL, -ENOMEM, "platform_info is null\n");

    ret = create_normal_intr_workqueue(platform_info);
    if (ret != 0)
        return ret;

    ret = create_abnormal_intr_workqueue(platform_info);
    if (ret != 0)
        goto create_abnormal_wq_fail;

    irq_normal = platform_info->dts_info.irq_normal;
    irq_abnormal = platform_info->dts_info.irq_abnormal;
    ffts_drv_info("ffts irq_normal = %d irq_abnormal = %d \n", irq_normal, irq_abnormal);

  	ret = request_irq(irq_normal, ffts_normal_handler, IRQF_TRIGGER_NONE, "ffts_normal_handler", NULL);
	if (ret != 0) {
		ffts_drv_err("request normal irq failed, ret = %d, id[%u]\n", ret, irq_normal);
		goto request_normal_irq_fail;
	}

    ret = request_irq(irq_abnormal, ffts_abnormal_handler, IRQF_TRIGGER_NONE, "ffts_abnormal_handler", NULL);
	if (ret != 0) {
		ffts_drv_err("request except irq failed, ret = %d, id[%u]\n", ret, irq_abnormal);
		goto request_abnormal_irq_fail;
	}

    return ret;

request_abnormal_irq_fail:
    free_irq(irq_normal, NULL);
request_normal_irq_fail:
    destroy_workqueue(g_intr_info.abnormal_intr_wq);
	g_intr_info.abnormal_intr_wq = NULL;
create_abnormal_wq_fail:
    destroy_workqueue(g_intr_info.normal_intr_wq);
	g_intr_info.normal_intr_wq = NULL;
    return ret;
}

void ffts_unregister_irq(struct ffts_platform_info *platform_info)
{
	int irq_normal, irq_abnormal;

	irq_normal = platform_info->dts_info.irq_normal;
	irq_abnormal = platform_info->dts_info.irq_abnormal;
	ffts_drv_info("unregister irq\n");
	free_irq(irq_normal, NULL);
	free_irq(irq_abnormal, NULL);
	destroy_workqueue(g_intr_info.normal_intr_wq);
	g_intr_info.normal_intr_wq = NULL;
	destroy_workqueue(g_intr_info.abnormal_intr_wq);
	g_intr_info.abnormal_intr_wq = NULL;
}