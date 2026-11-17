#include <linux/delay.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <securec.h>
#include "soc_hts_interface.h"
#include "ffrt_configs.h"
#include "hts_platform.h"
#include "hts_kernel_log.h"
#include "hpd_rule.h"
#include "hts_common.h"
#include "hts_resmem.h"
#include "hts_rule.h"
#include "hts_cfg.h"

#define HTS_INITIAL_ACK_LOOP_TIMES 1000
#define HTS_INITIAL_ACK_LOOP_US 1000

static int hts_get_cmd_mode(struct hts_rule_info *rule_info, hts_rule_table_cmd_mode *cmd_code)
{
	// Verify the number of events and confirm the forwarding mode.
	if ((rule_info->src_event_num == 1) && (rule_info->dst_event_num == 1)) {
		*cmd_code = CMD_ONE_TO_ONE;
	} else if ((rule_info->src_event_num == 1) && (rule_info->dst_event_num == 2)) {
		*cmd_code = CMD_ONE_TO_TWO;
	} else if ((rule_info->src_event_num == 1) && (rule_info->dst_event_num == 3)) {
		*cmd_code = CMD_ONE_TO_THREE;
	} else if ((rule_info->src_event_num == 2) && (rule_info->dst_event_num == 1)) {
		*cmd_code = CMD_TWO_TO_ONE;
	} else if ((rule_info->src_event_num == 3) && (rule_info->dst_event_num == 1)) {
		*cmd_code = CMD_THREE_TO_ONE;	
	} else {
		hts_drv_err("error cmd\n");
		return -1;
	}
	return 0;
}

static int verify_one_to_one_rule(struct hts_rule_info *rule_info)
{
	if ((rule_info->src_repeat_time > HTS_MAX_REPEAT_NUM || rule_info->dst_repeat_time > HTS_MAX_REPEAT_NUM) ||
		(rule_info->src_repeat_time >= 1 && rule_info->dst_repeat_time >= 1)) {
		hts_drv_err("rule_info repeat_time is invalid, src_repeat_time:%u, dst_repeat_time %u\n",
						rule_info->src_repeat_time, rule_info->dst_repeat_time);
		return -1;
	}
	cond_return_error((rule_info->dst_qos[0] < HTS_MIN_QOS) || (rule_info->dst_qos[0] > HTS_MAX_QOS), 
			-1, "dst_qos is invalid, dst_qos:%u\n", rule_info->dst_qos[0]);
	cond_return_error((rule_info->dst_profile_bit[0] < 0) || (rule_info->dst_profile_bit[0] > 1), 
			-1, "dst_profile_bit is invalid, dst_profile_bit:%u\n", rule_info->dst_profile_bit[0]);
	cond_return_error((rule_info->dst_user_bit[0] < 0) || (rule_info->dst_user_bit[0] > 1), 
			-1, "dst_user_bit is invalid, dst_user_bit:%u\n", rule_info->dst_user_bit[0]);
	return 0;
}

static int verify_one_to_two_rule(struct hts_rule_info *rule_info)
{
	size_t i;
	for(i = 0; i < 2; i++) {
		cond_return_error((rule_info->dst_qos[i] < HTS_MIN_QOS) || (rule_info->dst_qos[i] > HTS_MAX_QOS), 
			-1, "dst_qos is invalid, dst_qos:%u\n", rule_info->dst_qos[i]);
		cond_return_error((rule_info->dst_profile_bit[i] < 0) || (rule_info->dst_profile_bit[i] > 1), 
			-1, "dst_profile_bit is invalid, dst_profile_bit:%u\n", rule_info->dst_profile_bit[i]);
		cond_return_error((rule_info->dst_user_bit[i] < 0) || (rule_info->dst_user_bit[i] > 1), 
			-1, "dst_user_bit is invalid, dst_user_bit:%u\n", rule_info->dst_user_bit[i]);
	}
	return 0;
}

static int verify_two_to_one_rule(struct hts_rule_info *rule_info)
{
	cond_return_error(rule_info->src_event[0] == rule_info->src_event[1],
		-1, "src_event[0] and src_event[1] are equal, src_event[0]:%u\n", rule_info->src_event[0]);
	cond_return_error((rule_info->dst_qos[0] < HTS_MIN_QOS) || (rule_info->dst_qos[0] > HTS_MAX_QOS), 
		-1, "dst_qos is invalid, dst_qos:%u\n", rule_info->dst_qos[0]);
	cond_return_error((rule_info->dst_profile_bit[0] < 0) || (rule_info->dst_profile_bit[0] > 1), 
		-1, "dst_profile_bit is invalid, dst_profile_bit:%u\n", rule_info->dst_profile_bit[0]);
	cond_return_error((rule_info->dst_user_bit[0] < 0) || (rule_info->dst_user_bit[0] > 1), 
		-1, "dst_user_bit is invalid, dst_user_bit:%u\n", rule_info->dst_user_bit[0]);
	return 0;
}

static int verify_three_to_one_rule(struct hts_rule_info *rule_info)
{
	cond_return_error(rule_info->src_event[0] == rule_info->src_event[1],
		-1, "src_event[0] and src_event[1] are equal, src_event[0]:%u\n", rule_info->src_event[0]);
	cond_return_error((rule_info->dst_qos[0] < HTS_MIN_QOS) || (rule_info->dst_qos[0] > HTS_MAX_QOS), 
		-1, "dst_qos is invalid, dst_qos:%u\n", rule_info->dst_qos[0]);
	cond_return_error((rule_info->dst_profile_bit[0] < 0) || (rule_info->dst_profile_bit[0] > 1), 
		-1, "dst_profile_bit is invalid, dst_profile_bit:%u\n", rule_info->dst_profile_bit[0]);
	cond_return_error((rule_info->dst_user_bit[0] < 0) || (rule_info->dst_user_bit[0] > 1), 
		-1, "dst_user_bit is invalid, dst_user_bit:%u\n", rule_info->dst_user_bit[0]);
	cond_return_error(rule_info->src_event[0] == rule_info->src_event[2],
		-1, "src_event[0] and src_event[2] are equal, src_event[0]:%u\n", rule_info->src_event[0]);
	cond_return_error(rule_info->src_event[1] == rule_info->src_event[2],
		-1, "src_event[1] and src_event[2] are equal, src_event[1]:%u\n", rule_info->src_event[1]);
	return 0;
}

static int (*verify_specific_cmd_mode_rule[CMD_MAX_NUM])(struct hts_rule_info *rule_info) = {
	verify_one_to_one_rule,
	verify_one_to_two_rule,
	NULL,
	verify_two_to_one_rule,
	verify_three_to_one_rule
};

static int verify_rule(struct hts_rule_info *rule_info, hts_rule_table_cmd_mode *mode)
{
	int ret;
	hts_rule_table_cmd_mode cmd_mode = CMD_ONE_TO_ONE;
	uint8_t i;
	uint8_t dev_id;
	uint32_t event_id;

	ret = hts_get_cmd_mode(rule_info, &cmd_mode);
	if (ret != 0) {
		hts_drv_err("hts_get_cmd_mode fail src_event_num=%d dst_event_num=%d, ret = %d\n", rule_info->src_event_num,
			rule_info->dst_event_num, ret);
		return ret;
	}
	// Check whether all src_event src_id values are valid
	for (i = 0; i < rule_info->src_event_num; i++) {
		event_id = rule_info->src_event[i];
		dev_id = rule_info->src_id[i];
		cond_return_error((event_id <= 0) || (event_id > HTS_MAX_EVENT_NUM), -1, "src event_id is invalid, event_id:%u\n", event_id);
		cond_return_error((dev_id >= SOC_IPMAX), -1, "src_id is invalid, src_id:%u\n", dev_id);
	}

	// Check whether all dst_event src_id values are valid
	for (i = 0; i < rule_info->dst_event_num; i++) {
		event_id = rule_info->dst_event[i];
		dev_id = rule_info->dst_id[i];
		cond_return_error((event_id <= 0) || (event_id > HTS_MAX_EVENT_NUM), -1, "dst event_id is invalid, event_id:%u\n", event_id);
		cond_return_error((dev_id == SOC_IPP) || (dev_id >= SOC_IPMAX), -1, "dst_id is invalid, dst_id:%u\n", dev_id);
	}

	if (cmd_mode != CMD_ONE_TO_THREE) { // 1to3 dont need verify
		ret = verify_specific_cmd_mode_rule[cmd_mode](rule_info);
		cond_return_error(ret != 0, -1, "check_rule_by_cmd_mode (%d)fail\n", cmd_mode);
	}
	*mode = cmd_mode;
	return 0;
}

static int hts_alloc_rule_id_all(uint32_t *rule_id_info, uint32_t rule_num)
{
	uint32_t alloc_id_num = 0;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uint32_t find_id = 0;
	uint32_t start_offset = 1;
	
	while(alloc_id_num < rule_num) {
		find_id = (uint32_t)find_next_zero_bit(dev_ctx->res.rule_bitmap, HTS_MAX_RULE_NUM + 1, start_offset);
		if (find_id == HTS_MAX_RULE_NUM + 1) 
			break;
		hts_drv_info("alloc rule %d", find_id);
		rule_id_info[alloc_id_num] = find_id;
		alloc_id_num++;
		start_offset = find_id + 1;
	}
	
	if (alloc_id_num < rule_num ) {
		hts_drv_err("available rule num: %u is not enough, needed rule_num :%u,\n", alloc_id_num, rule_num);
		return -1;
	}
	return 0;
}

// Authentication involves only src events. Virtual events do not need to be configured.
static void hts_check_table_cfg(struct hts_rule_info *rule_info, uint32_t uid)
{
	uint8_t i;
	SOC_HTS_EVENT_IN_CHECK_UNION check_table = { 0 };
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_CHECK_TABLE);
	if (virt_addr == (uintptr_t)NULL) {
		hts_drv_err("get reg vaddr type %u failed\n", HTS_REG_CHECK_TABLE);
		return;
	}

	for (i = 0; i < rule_info->src_event_num; i++) {
		if (rule_info->src_id[i] != SOC_HTS) {
			check_table.reg.cfg_mapping_idx = uid;
			writel(check_table.value,
				SOC_HTS_EVENT_IN_CHECK_ADDR(virt_addr, rule_info->src_event[i]));
		}
	}

	for (i = 0; i < rule_info->dst_event_num; i++) {
		if (rule_info->dst_id[i] != SOC_HTS) {
			check_table.reg.cfg_mapping_idx = uid;
			writel(check_table.value,
				SOC_HTS_EVENT_IN_CHECK_ADDR(virt_addr, rule_info->dst_event[i]));
		}
	}
}
// Mapping table only Configures src events.
static void hts_mapping_table_cfg(struct hts_rule_info *rule_info, uint32_t rule_id)
{
	uint8_t i;
	SOC_HTS_EVENT_PROC_MAPPING_IDX_UNION mapping_table = { 0 };
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_MAPPING_TABLE);
	if (virt_addr == (uintptr_t)NULL) {
		hts_drv_err("get reg vaddr type %u failed\n", HTS_REG_MAPPING_TABLE);
		return;
	}

	for (i = 0; i < rule_info->src_event_num; i++) {
		mapping_table.reg.cfg_mapping_idx = rule_id;
		writel(mapping_table.value,
			SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr, rule_info->src_event[i]));
	}
}

static int hts_rule_info_to_rule_table(struct hts_rule_info *rule_info, struct hts_rule_table *rule_table, uint32_t rule_id)
{
	uint8_t i;
	int ret;
	hts_rule_table_cmd_mode cmd_mode = ONE_TO_ONE;

	ret = memset_s(rule_table, sizeof(struct hts_rule_table), 0, sizeof(struct hts_rule_table));
	if (ret != 0) {
		hts_drv_err("memset_s rule_table is failed\n");
		return ret;
	}

	ret = verify_rule(rule_info, &cmd_mode);
	if (ret != 0) {
		hts_drv_err("verify_valid_rule is fail rule id = %u\n", rule_id);
		return ret;
	}

	for (i = 0; i < rule_info->src_event_num; i++)
		rule_table->src_event[i] = rule_info->src_event[i];

	for (i = 0; i < rule_info->dst_event_num; i++) {
		rule_table->dst_event[i] = rule_info->dst_event[i];
		rule_table->dst_id[i] = rule_info->dst_id[i];
	}
	rule_table->rule_id = rule_id;
	rule_table->cmd_mode = cmd_mode;

	if (cmd_mode == CMD_ONE_TO_ONE) {
		rule_table->src_repeat_time = rule_info->src_repeat_time;
		rule_table->dst_repeat_time = rule_info->dst_repeat_time;
		rule_table->dst_qos[0] = rule_info->dst_qos[0];
		rule_table->dst_profile_bit[0] = rule_info->dst_profile_bit[0];
		rule_table->dst_user_bit[0] = rule_info->dst_user_bit[0];
	}else if (cmd_mode == CMD_ONE_TO_TWO) {
		for (i = 0; i < 2; i++) {
			rule_table->dst_qos[i] = rule_info->dst_qos[i];
			rule_table->dst_profile_bit[i] = rule_info->dst_profile_bit[i];
			rule_table->dst_user_bit[i] = rule_info->dst_user_bit[i];
		}
	}else if (cmd_mode == CMD_TWO_TO_ONE || cmd_mode == CMD_THREE_TO_ONE) {
		rule_table->dst_qos[0] = rule_info->dst_qos[0];
		rule_table->dst_profile_bit[0] = rule_info->dst_profile_bit[0];
		rule_table->dst_user_bit[0] = rule_info->dst_user_bit[0];
	}
	return ret;
}

static void hts_rule_table_cfg(struct hts_rule_table *rule_table)
{
	hts_event_proc_rule_low rule_low = { 0 };
	hts_event_proc_rule_high rule_high = { 0 };
	uintptr_t virt_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_RULE_TABLE);
	if (virt_addr == (uintptr_t)NULL) {
		hts_drv_err("get reg vaddr type %u failed\n", HTS_REG_RULE_TABLE);
		return;
	}

	rule_low.reg.src_event0 = rule_table->src_event[0];
	rule_low.reg.dst_event0 = rule_table->dst_event[0];
	rule_low.reg.dst_id0 = rule_table->dst_id[0];

	switch (rule_table->cmd_mode) {
	case CMD_ONE_TO_ONE:
		rule_low.reg.cmd_code = ONE_TO_ONE;
		rule_low.reg.dst_profile_bit = rule_table->dst_profile_bit[0];
		rule_high.reg.cfg1 = rule_table->src_repeat_time;
		rule_high.reg.cfg2 = rule_table->dst_repeat_time;
		rule_high.reg.cfg4 = (rule_table->dst_user_bit[0] | (rule_table->dst_qos[0] << 1));
		break;
	case CMD_ONE_TO_TWO:
		rule_low.reg.cmd_code = ONE_TO_N;
		rule_low.reg.dst_profile_bit = (rule_table->dst_profile_bit[0] | (rule_table->dst_profile_bit[1] << 1));
		rule_high.reg.cfg1 = rule_table->dst_event[1];
		rule_high.reg.cfg2 = ((rule_table->dst_user_bit[1] << 6) | (rule_table->dst_qos[1] << 7));
		rule_high.reg.cfg3 = rule_table->dst_id[1];
		rule_high.reg.cfg4 = (rule_table->dst_user_bit[0] | (rule_table->dst_qos[0] << 1));
		break;
	case CMD_ONE_TO_THREE:
		rule_low.reg.cmd_code = ONE_TO_N;
		rule_high.reg.cfg1 = rule_table->dst_event[1];
		rule_high.reg.cfg2 = rule_table->dst_event[2];
		rule_high.reg.cfg3 = rule_table->dst_id[1];
		rule_high.reg.cfg4 = rule_table->dst_id[2];
		break;
	case CMD_TWO_TO_ONE:
		rule_low.reg.cmd_code = N_TO_ONE;
		rule_low.reg.dst_profile_bit = rule_table->dst_profile_bit[0];
		rule_high.reg.cfg1 = rule_table->src_event[1];
		rule_high.reg.cfg4 = (rule_table->dst_user_bit[0] | (rule_table->dst_qos[0] << 1));
		break;
	case CMD_THREE_TO_ONE:
		rule_low.reg.cmd_code = N_TO_ONE;
		rule_low.reg.dst_profile_bit = rule_table->dst_profile_bit[0];
		rule_high.reg.cfg1 = rule_table->src_event[1];
		rule_high.reg.cfg2 = rule_table->src_event[2];
		rule_high.reg.cfg4 = (rule_table->dst_user_bit[0] | (rule_table->dst_qos[0] << 1));
		break;
	default:
		break;
	};
	writel(rule_low.value, SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, rule_table->rule_id * 2));
	writel(rule_high.value, SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr, (rule_table->rule_id * 2) + 1));
}

static void hts_clear_rule(struct hts_rule_info *rule_info, uint32_t uid)
{
	uint32_t i = 0;
	uint32_t rule_id;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uintptr_t virt_addr_check_table = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_CHECK_TABLE);
	uintptr_t virt_addr_mapping_table = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_MAPPING_TABLE);
	uintptr_t virt_addr_rule_table = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_RULE_TABLE);

	rule_id = readl(SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr_mapping_table, rule_info->src_event[0]));
	// clear check table and mapping table
	for (i = 0; i < rule_info->src_event_num; i++) {
		writel(0U, SOC_HTS_EVENT_IN_CHECK_ADDR(virt_addr_check_table, rule_info->src_event[i]));
		writel(0U, SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(virt_addr_mapping_table, rule_info->src_event[i]));
	}
	for (i = 0; i < rule_info->dst_event_num; i++) {
		writel(0U, SOC_HTS_EVENT_IN_CHECK_ADDR(virt_addr_check_table, rule_info->dst_event[i]));
	}

	hts_drv_warn("free rule %d, src event %d", rule_id, rule_info->src_event[0]);
	// clear hts rule bitmap
	bitmap_clear(dev_ctx->res.rule_bitmap, rule_id, 1);
	// clear hts rule
	writel(0U, SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr_rule_table, rule_id * 2));
	writel(0U, SOC_HTS_EVENT_PROC_RULE_ADDR(virt_addr_rule_table, (rule_id * 2) + 1));

	hts_outbuf_clear(rule_info->src_event, rule_info->src_event_num);
	hts_cfg_event_unstore(rule_info->src_event, rule_info->src_event_num);

	hts_outbuf_clear(rule_info->dst_event, rule_info->dst_event_num);
	hts_cfg_event_unstore(rule_info->dst_event, rule_info->dst_event_num);
}

static void hts_set_auth(struct hts_rule_info *rule_info, uint32_t uid) {
	uint32_t i;
	hts_check_table table = {0};

	for (i = 0 ; i < rule_info->src_event_num; i++) {
		table.data.valid = 1;
		table.data.src_id = rule_info->src_id[i];
		hts_drv_debug("current src_id %d and index %d, uid %d", rule_info->src_id[i], i, uid);
		table.data.dst_id = SOC_IPMAX;
		table.data.uid = uid;
		(void)hts_set_auth_table(rule_info->src_event[i], &table);
	}

	for (i = 0 ; i < rule_info->dst_event_num; i++) {
		table.data.valid = 1;
		table.data.src_id = SOC_IPMAX;
		table.data.dst_id = rule_info->dst_id[i];
		hts_drv_debug("current dst_id %d and index %d, uid %d", rule_info->dst_id[i], i, uid);
		table.data.uid = uid;
		(void)hts_set_auth_table(rule_info->dst_event[i], &table);
	}
}

static void hts_clear_auth(struct hts_rule_info *rule_info, uint32_t uid) {
	uint32_t i;
	hts_check_table table = {0};
	hts_check_table table_get = {0};

	table.data.src_id = SOC_IPMAX;
	table.data.dst_id = SOC_IPMAX;
	for (i = 0; i < rule_info->src_event_num; i++) {
		hts_get_auth_table(rule_info->src_event[i], &table_get);
		table.data.valid = table_get.data.valid;
		table.data.uid = table_get.data.uid;
		(void)hts_set_auth_table(rule_info->src_event[i], &table);
	}

	for (i = 0; i < rule_info->dst_event_num; i++){
		hts_get_auth_table(rule_info->dst_event[i], &table_get);
		table.data.valid = table_get.data.valid;
		table.data.uid = table_get.data.uid;
		(void)hts_set_auth_table(rule_info->dst_event[i], &table);
	}
}

int hts_set_rule(struct hts_rule_info *rule_info, uint32_t rule_num, uint32_t uid)
{
	int ret;
	uint32_t i;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uint32_t *rule_id = NULL;
	struct hts_rule_table *rule_tables = NULL;

	hts_drv_warn("start set rule,rule_num:%u \n", rule_num);
	rule_id = (uint32_t*)kmalloc(sizeof(uint32_t) * rule_num, GFP_KERNEL);
	if (rule_id == NULL) {
		hts_drv_err("malloc failed, need memeory size=%u\n", sizeof(uint32_t) * rule_num);
		return -1;
	}

	ret = hts_alloc_rule_id_all(rule_id, rule_num);
	if (ret != 0) {
		hts_drv_err("alloc rule id failed, need rule num is %u", rule_num);
		kfree(rule_id);
		return ret;
	}
	rule_tables = (struct hts_rule_table*)kmalloc(sizeof(struct hts_rule_table) * rule_num,
											GFP_KERNEL);
	if (rule_tables == NULL) {
		hts_drv_err("malloc failed, need memeory size=%u\n", sizeof(struct hts_rule_table) * rule_num);
		ret = -1;
		goto set_rule_fail;
	}
	for (i = 0; i < rule_num; i++) {
		ret = hts_rule_info_to_rule_table(&rule_info[i], &rule_tables[i], rule_id[i]);
		if (ret != 0) {
			hts_drv_err("hts_rule_2_rule_table failed, rule_id is %u", rule_id[i]);
			goto set_rule_fail;
		}
	}

	// Configure HTS rules one by one.
	for (i = 0; i < rule_num; i++) {
		hts_set_auth(&rule_info[i], uid);
		bitmap_set(dev_ctx->res.rule_bitmap, rule_id[i], 1);
		hts_check_table_cfg(&rule_info[i], uid);
		hts_mapping_table_cfg(&rule_info[i], rule_id[i]);
		hts_rule_table_cfg(&rule_tables[i]);
	}
set_rule_fail:
	if (rule_id != NULL)
		kfree(rule_id);
	if (rule_tables != NULL)
		kfree(rule_tables);

	return ret;
}

int hts_destroy_rule(struct hts_rule_info *rule_info, uint32_t rule_num, uint32_t uid)
{
	uint32_t i;
	hts_rule_table_cmd_mode cmd_mode = 0;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();

	hts_drv_warn("npu static:%hu, other static:%hu\n",
		dev_ctx->res.event_num[NPU_STATIC_ALLOC], dev_ctx->res.event_num[OTHER_STATIC_ALLOC]);
	// 1.Check whether hts_rule is valid.
	for (i = 0; i < rule_num; i++) {
		if (verify_rule(&rule_info[i], &cmd_mode)) {
			hts_drv_err("rule id: %u is invalid, stop setting rule\n", i);
			return -1;
		}
	}

	for (i = 0; i < rule_num; i++) {
		(void)hts_clear_rule(&rule_info[i], uid);
		(void)hts_clear_auth(&rule_info[i], uid);
	}
	return 0;
}

void hts_resource_clear(void)
{
	uint32_t i;
	SOC_HTS_EVENT_LOCK_UNION event_lock = {0};
	uintptr_t glb_table_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_GLB_TABLE);
	uintptr_t check_table_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_CHECK_TABLE);
	uintptr_t mapping_table_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_MAPPING_TABLE);
	uintptr_t rule_table_addr = (uintptr_t)hts_plat_get_reg_vaddr(HTS_REG_RULE_TABLE);
	hts_check_table table_set = {0};
	table_set.data.src_id = SOC_IPMAX;
	table_set.data.dst_id = SOC_IPMAX;
	hts_drv_warn("start\n");

	event_lock.value = 0xffffffff;
	// event lock enable
	for (i = 0; i < HTS_MAX_EVENT_LOCK_NUM; i++)
		writel(event_lock.value, SOC_HTS_EVENT_LOCK_ADDR(glb_table_addr, i));

	// clear all tables
	for (i = 1; i <= HTS_MAX_EVENT_NUM; i++) {
		writel(0U, SOC_HTS_EVENT_IN_CHECK_ADDR(check_table_addr, i));
		writel(0U, SOC_HTS_EVENT_PROC_MAPPING_IDX_ADDR(mapping_table_addr, i));
		writel(0U, SOC_HTS_EVENT_PROC_RULE_ADDR(rule_table_addr, i * 2));
		writel(0U, SOC_HTS_EVENT_PROC_RULE_ADDR(rule_table_addr, (i * 2) + 1));
	}

	// clear all auth
	for (i = 1; i <= HTS_MAX_EVENT_NUM; i++)
		(void)hts_set_auth_table(i, &table_set);

	// cfg hts initial req
	writel(1U, SOC_HTS_INITIAL_REQ_ADDR(glb_table_addr));

	// read util hts initial ack equal 1
	i = HTS_INITIAL_ACK_LOOP_TIMES;
	while (i > 0) {
		if (readl(SOC_HTS_INITIAL_ACK_ADDR(glb_table_addr)) == 1U) {
			break;
		}
		udelay(HTS_INITIAL_ACK_LOOP_US);
		i--;
	}
	if (i == 0) {
		hts_drv_err("wait HTS_INITIAL_ACK timeout");
	}

	// enable store event
	writel(0U, SOC_HTS_STORE_BYPASS_MODE_ADDR(glb_table_addr));

	// cfg bypass register
	writel(0U, SOC_HTS_EVENT_IN_CKG_BYPASS_ADDR(glb_table_addr));
	writel(0U, SOC_HTS_UID_TABLE_CKG_BYPASS_ADDR(glb_table_addr));
}

