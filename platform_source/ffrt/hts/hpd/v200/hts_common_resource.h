/*
 * npu_common_resource.h
 *
 * about v200 common resource specification
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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
#ifndef __HTS_COMMON_RESOURCE_H
#define __HTS_COMMON_RESOURCE_H

#include <linux/types.h>
#include <linux/bitmap.h>
#include <linux/workqueue.h>

#define HTS_MAX_EVENT_NUM            1023
#define HTS_MAX_RULE_NUM             1023
#define HTS_MAX_UID                  4095
#define MAX_TRANS_NUM                3
#define HTS_MAX_REPEAT_NUM           64
#define HTS_GRAPH_MAX_RULE           30
#define HTS_MAX_STATIC_EVENT_NUM     512
#define HTS_MAX_EVENT_LOCK_NUM       64
#define HTS_GRAPH_MAX_EVENT          100
#define HTS_MAX_RULE_PROC            50
#define HTS_MIN_QOS             	 0
#define HTS_MAX_QOS             	 7
#define HTS_MAX_QOS_NUM              2
#define HTS_MAX_PROFILE_BIT_NUM		 2
#define HTS_MAX_USER_BIT_NUM		 2
#define HTS_MAX_GRAPH_ID             560
#define HTS_DYNAMIC_GRAPH_ID_NUM     360
#define HTS_MAX_NPU_STATIC_EVENT_NUM 191
#define HTS_MAX_NPU_DYNAMIC_EVENT_NUM 382
#define HTS_MAX_OTHER_DYNAMIC_EVENT_NUM 322
#define HTS_MAX_OTHER_STATIC_EVENT_NUM 	127
#define HTS_INT_MASK   0xFF

#define hts_event_lock(n)          (0x10001 << (n))
#define hts_event_unlock(n)        (0x10000 << (n))

#define hts_event_store_en(n)      (0x10001 << (n))
#define hts_event_store_dis(n)     (0x10000 << (n))

#define OTS_COUNT_TIMES            20
#define OBUF_NOPRESS_TRYTIMES      10000
#define NODE_MAP_LENGTH            100
#define HTS_DYNAMIC_ALLOC_EVENT_MAX_NUM   8

typedef enum  {
	HTS_REG_CHECK_TABLE = 0,
	HTS_REG_MAPPING_TABLE,
	HTS_REG_RULE_TABLE,
	HTS_REG_STATUS_TABLE,
	HTS_REG_GLB_TABLE,
	HTS_REG_WRAP_REG,
	HTS_REG_MAX_RESOURCE,
} hts_register_index;
 
typedef enum {
	HTS_RESMEM_AUTH_TABLE = 0,
	HTS_RESMEM_MAX_RESOURCE,
} hts_resmem_index;
 
typedef enum {
	HTS_IRQ_ERROR = 0,
	HTS_IRQ_MAX_RESOURCE,
} hts_irq_index;
 
typedef enum {
	EVENT_UNUSE = 0,

	EVENT_FOR_FFTS, // ffts path2 exception handling use

	NPU_STATIC_EVENT_START,
	NPU_STATIC_EVENT_END = NPU_STATIC_EVENT_START + HTS_MAX_NPU_STATIC_EVENT_NUM - 1, // 512 events are reserved for static graph

	NPU_DYNAMIC_EVENT_START,
	NPU_DYNAMIC_EVENT_END = NPU_DYNAMIC_EVENT_START + HTS_MAX_NPU_DYNAMIC_EVENT_NUM - 1,

	OTHER_DYNAMIC_EVENT_START,
	OTHER_DYNAMIC_EVENT_END = OTHER_DYNAMIC_EVENT_START + HTS_MAX_OTHER_DYNAMIC_EVENT_NUM - 1,

	OTHER_STATIC_EVENT_START,
	OTHER_STATIC_EVENT_END = HTS_MAX_EVENT_NUM,
} hts_event;

typedef enum {
	HTS_EVENT_IN_EVENT_ZERO_ERROR = 0,
	HTS_EVENT_IN_CHECK_ERROR,
	HTS_EVENT_IN_IBUF_OVERFLOW_EOORR,
	HTS_EVENT_PROC_NO_RULE_ERROR,
	HTS_EVENT_PROC_RULE_ILLEGAL_ERROR,
	HTS_EVENT_PROC_PROCESS_CNT_OVERFLOW_ERROR,
	HTS_EVENT_OUT_OBUF_OVERFLOW_ERROR,
    HTS_EVENT_FFTS_OUT_OBUF_OVERFLOW_ERROR,
	HTS_INTR_ERROR_NUM,
} hts_intr_error_type;

typedef enum event_alloc_type
{
	NPU_STATIC_ALLOC = 0,
	NPU_DYNAMIC_ALLOC,
	OTHER_DYNAMIC_ALLOC,
	OTHER_STATIC_ALLOC,
	MAX_ALLOC_TYPE
} event_alloc_type;

typedef enum event_type
{
	STATIC_EVENT = 0,
	DYNAMIC_EVENT,
	MAX_EVENT_TYPE
} event_type;

typedef enum {
    DEV_NPU = 3,
    DEV_OTHER,
} hts_device_type;

struct hts_rule_info {
	uint32_t src_event[MAX_TRANS_NUM];
	uint32_t dst_event[MAX_TRANS_NUM];
	uint8_t src_id[MAX_TRANS_NUM];
	uint8_t dst_id[MAX_TRANS_NUM];
	uint8_t src_event_num;
	uint8_t dst_event_num;
	uint8_t src_repeat_time;
	uint8_t dst_repeat_time;
	uint8_t dst_qos[HTS_MAX_QOS_NUM]; // CHS新增
	uint8_t dst_profile_bit[HTS_MAX_PROFILE_BIT_NUM]; // CHS新增
	uint8_t dst_user_bit[HTS_MAX_USER_BIT_NUM]; // CHS新增
};

struct exception_event {
    struct work_struct work;
    uint16_t events[HTS_DYNAMIC_GRAPH_ID_NUM];
	uint16_t length;
	uint16_t dev_id;
	int32_t pid;
};

#endif
