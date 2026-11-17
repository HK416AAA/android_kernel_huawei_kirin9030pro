/*
 * hpd_rule.h
 *
 * about hpd rule
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

#ifndef __HPD_RULE_H_
#define __HPD_RULE_H_

#include <linux/types.h>
#include "hts_common_resource.h"

typedef union {
	uint32_t value;
	struct {
		uint32_t src_event0         :10;  // bit 0~9
		uint32_t dst_event0         :10;  // bit 10~19
		uint32_t dst_id0            :6;   // bit 20~25
		uint32_t cmd_code           :4;   // bit 26~31
		uint32_t dst_profile_bit    :2;   // bit 30~31, 1to3 always 00
	} reg;
} hts_event_proc_rule_low;

typedef union {
	uint32_t value;
	struct {
		uint32_t cfg1               :10; /* bit 0~9
										   1 to 1 : src_repeat_time
										   1 to 2 : dst_event1
										   1 to 3 : dst_event1
										   2 to 1 : src_event1
										   3 to 1 : src_event1
										 */
		uint32_t cfg2               :10; /* bit 10~19
										   1 to 1 : dst_repeat_time
										   1 to 2 : 10~14:reserved 16~19:dst_user_bit + dst_qos_e
										   1 to 3 : dst_event2
										   2 to 1 : reserved
										   3 to 1 : src_event2
										 */
		uint32_t cfg3            	:6;  /* bit 20~25
										   1 to 1 : reserved
										   1 to 2 : dst1
										   1 to 3 : dst1
										   2 to 1 : reserved
										   3 to 1 : reserved
										 */
		uint32_t cfg4            	:6;  /* bit 26~31
										   1 to 1 : 26~29:dst_user_bit + dst_qos_e 29~31:reserved
										   1 to 2 : 26~29:dst_user_bit + dst_qos_e 29~31:reserved
										   1 to 3 : dst2
										   2 to 1 : 26~29:dst_user_bit + dst_qos_e 29~31:reserved
										   3 to 1 : 26~29:dst_user_bit + dst_qos_e 29~31:reserved
										 */
	} reg;
} hts_event_proc_rule_high;

typedef enum {
	CMD_ONE_TO_ONE= 0,
	CMD_ONE_TO_TWO,
	CMD_ONE_TO_THREE,
	CMD_TWO_TO_ONE,
	CMD_THREE_TO_ONE,
	CMD_MAX_NUM,
} hts_rule_table_cmd_mode;
 
struct hts_rule_table {
	uint32_t src_event[MAX_TRANS_NUM];
	uint32_t dst_event[MAX_TRANS_NUM];
	uint8_t dst_id[MAX_TRANS_NUM];
	uint32_t rule_id;
	uint8_t cmd_mode;
	uint8_t src_repeat_time;
	uint8_t dst_repeat_time;
	uint8_t dst_qos[HTS_MAX_QOS_NUM]; // CHS新增
	uint8_t dst_profile_bit[HTS_MAX_PROFILE_BIT_NUM]; // CHS新增
	uint8_t dst_user_bit[HTS_MAX_USER_BIT_NUM]; // CHS新增
};

int hts_set_rule(struct hts_rule_info *rule_info, uint32_t rule_num, uint32_t uid);
int hts_destroy_rule(struct hts_rule_info *rule_info, uint32_t rule_num, uint32_t uid);
void hts_resource_clear(void);
#endif // __HPD_RULE_H_
