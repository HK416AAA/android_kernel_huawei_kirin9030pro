#include "hts_profiling.h"
#include <linux/io.h>
#include "soc_hts_interface.h"
#include "hts_kernel_log.h"
#include "hts_common.h"
#include "hts_platform.h"
#include "hts_common_resource.h"
#include "hpd_interface.h"

static void hts_dump_resource_info(void)
{
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uint32_t used_rule_num = 0;
	uint32_t used_event_num = 0;
	uint32_t i;
    for (i = 1; i < HTS_MAX_RULE_NUM + 1; i++) {
        if (test_bit(i, dev_ctx->res.rule_bitmap)) {
            used_rule_num++;
            hts_drv_warn("rule id is used %u", i);
        }
        if (test_bit(i, dev_ctx->res.event_bitmap)) {
            used_event_num++;
            hts_drv_warn("event id is used %u", i);
        }
    }

	hts_drv_err("used_rule_num: %u, used_event_num :%u", used_rule_num, used_event_num);
}

void hts_info_readback(uint32_t id)
{
	struct hpd_registry *hpd = hts_get_hpd_registry();
	if ((hpd == NULL) || (hpd->hts_dump_info == NULL)) {
		hts_drv_err("hpd or info-dumping is not registered\n");
		return;
	}

	if (id == HTS_DUMP_RESOURCE_INFO) {
		hts_dump_resource_info();
		return;
	}

	hpd->hts_dump_info(id);
}

void hts_record_event_counter(void)
{
	// event cnt  0x414    0x464    0x474   0x484
	uintptr_t virt_addr       = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uint32_t event_in_cnt     = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_IN_READ_BACK_1_ADDR(virt_addr));
	uint32_t event_proc_cnt   = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_5_ADDR(virt_addr));
	uint32_t event_out_in_cnt = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_1_ADDR(virt_addr));
	uint32_t event_out_cnt    = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_5_ADDR(virt_addr));

	hts_drv_warn("event counter:in(%u)-proc(%u)-out_in(%u)-out(%u)", event_in_cnt, event_proc_cnt, event_out_in_cnt, event_out_cnt);
}

void hts_record_event_id_info(void)
{
	// event id    0x410    0x450   0x470   0x480
	uintptr_t virt_addr        = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uint32_t event_in_info     = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_IN_READ_BACK_0_ADDR(virt_addr));
	uint32_t event_proc_info   = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_PROC_PROCESS_READ_BACK_0_ADDR(virt_addr));
	uint32_t event_out_in_info = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_0_ADDR(virt_addr));
	uint32_t event_out_info    = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_OUT_DISPATCH_READ_BACK_4_ADDR(virt_addr));

	hts_drv_warn("event_id info:in(0x%x)-proc(0x%x)-out_in(0x%x)-out(0x%x)", event_in_info, event_proc_info, event_out_in_info, event_out_info);
}

void hts_record_event_store_cfg(void)
{
	// HTS_EVENT_STORE    0x600
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uint32_t read_value;
	struct store_info record_info[MAX_EVENT_STORE_REG_NUM] = {{0, 0}};
	uint32_t i;
	uint32_t num = 0;
	uint32_t log_num;

	for (i = 0; i < MAX_EVENT_STORE_REG_NUM; i++) {
		read_value = readl((const volatile void *)(uintptr_t)SOC_HTS_EVENT_STORE_ADDR(virt_addr, i));
		if (read_value != 0) {
			record_info[num].idx = i;
			record_info[num].store_flag = read_value;
			num++;
		}
	}

	if (num == 0) {
		hts_drv_warn("stroe_cfg: no event store");
	} else {
		log_num = (num % 4) ? (num / 4 + 1) : (num / 4);
		for (i = 0; i < log_num; i++) {
			hts_drv_warn("stroe_cfg: :idx-value(%u)(0x%x)-(%u)(0x%x)-(%u)(0x%x)-(%u)(0x%x)", 
			record_info[i * 4].idx, record_info[i * 4].store_flag,
			record_info[i * 4 + 1].idx, record_info[i * 4 + 1].store_flag,
			record_info[i * 4 + 2].idx, record_info[i * 4 + 2].store_flag,
			record_info[i * 4 + 3].idx, record_info[i * 4 + 3].store_flag);
		}
	}
}

void hts_record_key_info(void)
{
	hts_record_event_counter();
	hts_record_event_id_info();
	hts_record_event_store_cfg();
}