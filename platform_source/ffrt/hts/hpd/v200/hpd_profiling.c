/*
 * hpd_profiling.c
 *
 * hpd profiling
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
#include "hpd_profiling.h"
#include <linux/types.h>
#include <linux/io.h>
#include "soc_hts_interface.h"
#include "hts_platform.h"
#include "hts_common.h"
#include "hts_kernel_log.h"

#define HTS_DEVICE_TYPE_NUM 16

static void hts_dump_event_in_info(void)
{
	uint32_t i;
	SOC_HTS_EVENT_IN_READ_BACK_2_UNION reg_value2 = {0};
	SOC_HTS_EVENT_IN_READ_BACK_3_UNION reg_value3 = {0};
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uint32_t reg_value1 = readl(SOC_HTS_EVENT_IN_READ_BACK_1_ADDR(virt_addr));
	SOC_HTS_EVENT_IN_READ_BACK_0_UNION reg_value = {0};
	SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_UNION src_id_event_cnt = {0};

	if (virt_addr == (uintptr_t)NULL) {
		hts_drv_err("get reg vaddr type %u failed\n", HTS_REG_GLB_TABLE);
		return;
	}

	hts_drv_err("event in counter(%u)!", reg_value1);
	
	// event in
	reg_value.value = readl(SOC_HTS_EVENT_IN_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err("event in last uid(%u) srcid(%u) event(%u)!", reg_value.reg.event_in_last_rcv_uid,
		reg_value.reg.event_in_last_rcv_src_id, reg_value.reg.event_in_last_rcv_event);

	reg_value2.value = readl(SOC_HTS_EVENT_IN_READ_BACK_2_ADDR(virt_addr));
	hts_drv_err("event in last rcv event(%u)! last vp event(%u)",
		reg_value2.reg.event_in_ibuf_last_rcv_event, reg_value2.reg.event_in_ibuf_last_rcv_vp_event);

	reg_value3.value = readl(SOC_HTS_EVENT_IN_READ_BACK_3_ADDR(virt_addr));
	hts_drv_err("event in ibuf last event cnt(%u) last vp event cnt(%u)!",
		reg_value3.reg.event_in_ibuf_rcv_event_cnt, reg_value3.reg.event_in_ibuf_rcv_vp_event_cnt);

	for (i = 0; i < HTS_DEVICE_TYPE_NUM; i++) {
		src_id_event_cnt.value = readl(SOC_HTS_EVENT_IN_SRC_ID_EVENT_CNT_READ_BACK0_ADDR(virt_addr, i));
		hts_drv_err("event in src_id is %u, event num is %u\n", i, src_id_event_cnt.reg.hts_event_in_src_id_event_cnt);
	}
}

static void hts_dump_event_proc_info(void)
{
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uint32_t reg_value = 0;
    
	// proc
	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err ("proc process last event(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err ("pevent_proc_mapping_last_rcv_event(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_MAPPING_READ_BACK_1_ADDR(virt_addr));
	hts_drv_err ("event_proc_mapping_rcv_event_cnt(%u)!", reg_value);

	reg_value =
		readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_FETCH_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err ("event_proc_fetch_last_rcv_event(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_FETCH_READ_BACK_1_ADDR(virt_addr));
	hts_drv_err ("event_proc_fetch_last_rcv_rule_addr(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_FETCH_READ_BACK_2_ADDR(virt_addr));
	hts_drv_err ("event_proc_fetch_rcv_event_cnt(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err ("event_proc_process_last_rcv_event(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_1_ADDR(virt_addr));
	hts_drv_err ("event_proc_process_last_rcv_rule_h(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_2_ADDR(virt_addr));
	hts_drv_err ("event_proc_process_last_rcv_rule_l(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_3_ADDR(virt_addr));
	hts_drv_err ("event_proc_process_last_rcv_status(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_4_ADDR(virt_addr));
	hts_drv_err ("event_proc_process_last_snd_status(%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_ADDR(virt_addr));
	hts_drv_err ("event_proc_proces_rcv_event_cnt(%u)!", reg_value);
}

static void hts_dump_event_out_info(void)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_UNION reg_value2 = {0};
	SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_UNION reg_value3 = {0};
	uint32_t reg_value = 0;
	SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_UNION dst_id_event_cnt = {0};

	// event out
	reg_value = readl(SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_ADDR(virt_addr));
	hts_drv_err("event_out_lock_last_snd_event (%u)!", reg_value);

	reg_value = readl(SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_ADDR(virt_addr));
	hts_drv_err("event_out_dispatch_last_rcv_event (%u)!", reg_value);

	reg_value = readl(SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_ADDR(virt_addr));
	hts_drv_err("event_out_dispatch_rcv_event_cnt (%u)!", reg_value);

	reg_value2.value = readl(SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_2_ADDR(virt_addr));
	hts_drv_err("event_out_dispatch_last_snd_event (%u)!", reg_value2.reg.event_out_dispatch_last_snd_event);

	reg_value3.value = readl(SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_3_ADDR(virt_addr));
	hts_drv_err("event_out_dispatch_snd_event_cnt (%u)!", reg_value3.reg.event_out_dispatch_snd_event_cnt);

	reg_value = readl(SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_ADDR(virt_addr));
	hts_drv_err("event_out_lock_snd_event_cnt (%u)!", reg_value);

	reg_value = readl(SOC_HTS_EVENT_OUT_OBUF_READ_BACK_4_ADDR(virt_addr));
	hts_drv_err("event_out_obuf_dispatch_last_snd_event (%u)!", reg_value);

	reg_value = readl(SOC_HTS_EVENT_OUT_OBUF_READ_BACK_5_ADDR(virt_addr));
	hts_drv_err("event_out_obuf_dispatch_snd_event_cnt (%u)!", reg_value);

	reg_value = readl(SOC_HTS_EVENT_OUT_OBUF_READ_BACK_6_ADDR(virt_addr));
	hts_drv_err("event_out_obuf_arb_last_snd_event (%u)!", reg_value);

	reg_value = readl(SOC_HTS_EVENT_OUT_OBUF_READ_BACK_7_ADDR(virt_addr));
	hts_drv_err("event_out_obuf_arb_snd_event_cnt (%u)!", reg_value);

	for (i = 0; i < HTS_DEVICE_TYPE_NUM; i++) {
		dst_id_event_cnt.value = readl(SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_ADDR(virt_addr, i));
		hts_drv_err("event out dst_id is %u, event num is %u\n", i, dst_id_event_cnt.reg.hts_event_out_dst_id_event_cnt);
	}
}

void hts_dump_ffts_event_out_info(void)
{
	uint32_t i;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uint32_t reg_value = 0;
	SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_UNION dst_id_event_cnt = {0};

	// event out
	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_3_ADDR(virt_addr));
	hts_drv_err ("event_out_ffts_obuf_dispatch_last_snd_event (%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_4_ADDR(virt_addr));
	hts_drv_err ("event_out_ffts_obuf_dispatch_snd_event_cnt (%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_5_ADDR(virt_addr));
	hts_drv_err ("event_out_ffts_obuf_arb_last_snd_event (%u)!", reg_value);

	reg_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_FFTS_OBUF_READ_BACK_6_ADDR(virt_addr));
	hts_drv_err ("event_out_ffts_obuf_arb_snd_event_cnt (%u)!", reg_value);

	for (i = 0; i < HTS_DEVICE_TYPE_NUM; i++) {
		dst_id_event_cnt.value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_DST_ID_EVENT_CNT_READ_BACK0_ADDR(virt_addr, i));
		hts_drv_err ("event out dst_id is %u, event num is %u\n", i, dst_id_event_cnt.reg.hts_event_out_dst_id_event_cnt);
	}
}

uint16_t hts_obuf_overflow_profiling(void)
{
	uint16_t dst_event;
	SOC_HTS_EVENT_OUT_OBUF_ERROR_READ_BACK_0_UNION event_out_back0;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	event_out_back0.value = readl(SOC_HTS_EVENT_OUT_OBUF_ERROR_READ_BACK_0_ADDR(virt_addr));
	dst_event = event_out_back0.reg.event_out_obuf_overflow_error_last_event; 
	hts_drv_err("SOC_HTS_EVENT_OUT_ERROR_READ_BACK_0_ADDR: event_out_obuf_overflow_error_last_event = %u,\n",
		dst_event);
	return dst_event;
}

uint16_t hts_ffts_obuf_overflow_profiling(void)
{
	uint16_t dst_event;
	SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_UNION event_out_back0;
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);

	event_out_back0.value = readl(SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_ADDR(virt_addr));
	dst_event = event_out_back0.reg.event_out_ffts_obuf_overflow_error_last_event;
	hts_drv_err("SOC_HTS_EVENT_OUT_FFTS_OBUF_ERROR_READ_BACK_0_ADDR: event_out_ffts_obuf_overflow_error_last_event = %u,\n",
		dst_event);
	return dst_event;
}

static struct opt_mod g_opt_info_arr[] = {
	{"event_in", hts_dump_event_in_info},
	{"event_proc", hts_dump_event_proc_info},
	{"event_out", hts_dump_event_out_info},
	{"ffts_event_out", hts_dump_ffts_event_out_info},
};

void hts_dump_info(uint32_t id)
{
	if (id >= (sizeof(g_opt_info_arr) / sizeof(struct opt_mod))) {
		hts_drv_err("dump info id %u is not available,\n", id);
		return;
	}
	g_opt_info_arr[id].func();
}