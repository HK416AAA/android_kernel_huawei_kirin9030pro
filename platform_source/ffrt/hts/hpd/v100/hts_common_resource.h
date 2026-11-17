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
#define HTS_MAX_GRAPH_ID             110
#define HTS_DYNAMIC_GRAPH_ID_NUM     0
#define HTS_INT_MASK   				 0x7F

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

	STATIC_EVENT_START,
	STATIC_EVENT_END = STATIC_EVENT_START + HTS_MAX_STATIC_EVENT_NUM - 1, // 512 events are reserved for static graph

	DYNAMIC_EVENT_START,
	DYNAMIC_EVENT_END = HTS_MAX_EVENT_NUM,
} hts_event;

typedef enum {
	HTS_EVENT_IN_EVENT_ZERO_ERROR = 0,
	HTS_EVENT_IN_CHECK_ERROR,
	HTS_EVENT_IN_IBUF_OVERFLOW_EOORR,
	HTS_EVENT_PROC_NO_RULE_ERROR,
	HTS_EVENT_PROC_RULE_ILLEGAL_ERROR,
	HTS_EVENT_PROC_PROCESS_CNT_OVERFLOW_ERROR,
	HTS_EVENT_OUT_OBUF_OVERFLOW_ERROR,
	HTS_INTR_ERROR_NUM,
} hts_intr_error_type;

typedef enum event_alloc_type
{
	STATIC_ALLOC = 0,
	DYNAMIC_ALLOC,
	MAX_ALLOC_TYPE
} event_alloc_type;

struct hts_rule_info {
	uint32_t src_event[MAX_TRANS_NUM];
	uint32_t dst_event[MAX_TRANS_NUM];
	uint8_t src_id[MAX_TRANS_NUM];
	uint8_t dst_id[MAX_TRANS_NUM];
	uint8_t src_event_num;
	uint8_t dst_event_num;
	uint8_t src_repeat_time;
	uint8_t dst_repeat_time;
};

#define HTS_MAX_DYMAIC_EVENT_NUM \
	((HTS_MAX_EVENT_NUM) - (DYNAMIC_EVENT_START) + 1)

#endif
