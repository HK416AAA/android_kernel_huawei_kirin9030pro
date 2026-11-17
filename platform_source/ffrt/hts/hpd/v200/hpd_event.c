/*
 * hpd_event.c
 *
 * hpd event
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
#include "hpd_event.h"
#include <linux/io.h>
#include <linux/delay.h>
#include "soc_hts_interface.h"
#include "hts_platform.h"
#include "hts_kernel_log.h"
#include "hpd_rule.h"
#include "hts_graph_resource.h"
#include "hts_common.h"
#include "hts_resmem.h"

/*
 * **********************STATIC EVENT RANGE MAP************************************
 * -------------------------------------------------------------------------
 * |	|		|       DLSS      | 2 ~ 5    
 * |	|		| NEURAL_UPSCALE  | 6 ~ 9    
 * |	|		|  SMART_PALETTE  | 10 ~ 25
 * |NPU	|		|     SMART_AWB   | 26 ~ 41
 * |STATIC		|    SMART_FLOW   | 42 ~ 57
 * |	|		|    SMART_DME    | 58 ~ 73
 * |	|		|       AITM      | 74 ~ 89
 * |	|		|   MTL_BACKBONE  | 90 ~ 105
 * |	|	    |    CIE_FDODSC   | 106 ~ 113
 * |	|	    |      CIE_SAL    | 114 ~ 121
 * |	|		|    SMART_DEPTH  | 122 ~ 129
 * |	|	    |      AUDIO_NN   | 130 ~ 145
 * |	|	    | FLASHAI_PREFILL | 146 ~ 148
 * |	|	    | FLASHAI_DECODE  | 149 ~ 151
 * |	|	    |     AIGC_VAE    | 152 ~ 155
 * |	|	    |     GLES_DLSS   | 156 ~ 159
 * |	|	    |    NEURAL_FRAME | 160 ~ 163
 * ------------------------------------------------------------------------------
 * |	|		|   FLASH_LIGHT   | 897 ~ 902
 * |OTHER		|     DLSS_FI     | 903 ~ 914
 * |STATIC		| FLASHAI_ABNORMAL| 915 ~ 916
 * |	|		|     PUSH_AOD    | 917 ~ 918
 * ------------------------------------------------------------------------------
 */

#define DLSS_START 		   	          NPU_STATIC_EVENT_START
#define DLSS_EVENT_NUM      	      4
#define NEURAL_UPSCALE_START          (DLSS_START + DLSS_EVENT_NUM)
#define NEURAL_UPSCALE_EVENT_NUM      4
#define SMART_PALETTE_START           (NEURAL_UPSCALE_START + NEURAL_UPSCALE_EVENT_NUM)
#define SMART_PALETTE_EVENT_NUM       16
#define SMART_AWB_START        		  (SMART_PALETTE_START + SMART_PALETTE_EVENT_NUM)
#define SMART_AWB_EVENT_NUM           16
#define SMART_FLOW_START       		  (SMART_AWB_START + SMART_AWB_EVENT_NUM)
#define SMART_FLOW_EVENT_NUM          16
#define SMART_DME_START               (SMART_FLOW_START + SMART_FLOW_EVENT_NUM)
#define SMART_DME_EVENT_NUM           16
#define AITM_START                    (SMART_DME_START + SMART_DME_EVENT_NUM)
#define AITM_EVENT_NUM                16
#define MTL_BACKBONE_START            (AITM_START + AITM_EVENT_NUM)
#define MTL_BACKBONE_EVENT_NUM        16
#define CIE_FDODSC_START              (MTL_BACKBONE_START + MTL_BACKBONE_EVENT_NUM)
#define CIE_FDODSC_EVENT_NUM          8
#define CIE_SAL_START                 (CIE_FDODSC_START + CIE_FDODSC_EVENT_NUM)
#define CIE_SAL_EVENT_NUM             8
#define SMART_DEPTH_START             (CIE_SAL_START + CIE_SAL_EVENT_NUM)
#define SMART_DEPTH_EVENT_NUM         8
#define AUDIO_NN_START                (SMART_DEPTH_START + SMART_DEPTH_EVENT_NUM)
#define AUDIO_NN_EVENT_NUM            16
#define FLASHAI_PREFILL_START         (AUDIO_NN_START + AUDIO_NN_EVENT_NUM)
#define FLASHAI_PREFILL_EVENT_NUM     3
#define FLASHAI_DECODE_START          (FLASHAI_PREFILL_START + FLASHAI_PREFILL_EVENT_NUM)
#define FLASHAI_DECODE_EVENT_NUM      3
#define AIGC_VAE_START          	  (FLASHAI_DECODE_START + FLASHAI_DECODE_EVENT_NUM)
#define AIGC_VAE_EVENT_NUM            4
#define GLES_DLSS_START          	  (AIGC_VAE_START + AIGC_VAE_EVENT_NUM)
#define GLES_DLSS_EVENT_NUM           4
#define NEURAL_FRAME_START            (GLES_DLSS_START + GLES_DLSS_EVENT_NUM)
#define NEURAL_FRAME_EVENT_NUM        4
#define FLASH_LIGHT_START             OTHER_STATIC_EVENT_START
#define FLASH_LIGHT_EVENT_NUM         6
#define DLSS_FI_START                 (FLASH_LIGHT_START + FLASH_LIGHT_EVENT_NUM)
#define DLSS_FI_EVENT_NUM             12
#define FLASHAI_ABNORMAL_START        (DLSS_FI_START + DLSS_FI_EVENT_NUM)
#define FLASHAI_ABNORMAL_EVENT_NUM    2

const static struct event_range event_range_table[] = {
	{NPU_STATIC_ALLOC, NPU_STATIC_EVENT_START, NPU_STATIC_EVENT_END},
	{NPU_DYNAMIC_ALLOC, NPU_DYNAMIC_EVENT_START, NPU_DYNAMIC_EVENT_END},
	{OTHER_DYNAMIC_ALLOC, OTHER_DYNAMIC_EVENT_START, OTHER_DYNAMIC_EVENT_END},
	{OTHER_STATIC_ALLOC, OTHER_STATIC_EVENT_START, OTHER_STATIC_EVENT_END},
};

const static struct graph_event_range graph_event_range_table[] = {
	{DLSS,             DLSS_START,             DLSS_START + DLSS_EVENT_NUM - 1},
	{NEURAL_UPSCALE,   NEURAL_UPSCALE_START,   NEURAL_UPSCALE_START + NEURAL_UPSCALE_EVENT_NUM - 1},
	{SMART_PALETTE,    SMART_PALETTE_START,    SMART_PALETTE_START + SMART_PALETTE_EVENT_NUM - 1},
	{SMART_AWB,        SMART_AWB_START,        SMART_AWB_START + SMART_AWB_EVENT_NUM - 1},
	{SMART_FLOW,       SMART_FLOW_START,       SMART_FLOW_START + SMART_FLOW_EVENT_NUM - 1},
	{SMART_DME,        SMART_DME_START,        SMART_DME_START + SMART_DME_EVENT_NUM - 1},
	{AITM,             AITM_START,             AITM_START + AITM_EVENT_NUM - 1},
	{MTL_BACKBONE,     MTL_BACKBONE_START,     MTL_BACKBONE_START + MTL_BACKBONE_EVENT_NUM - 1},
	{CIE_FDODSC,   	   CIE_FDODSC_START,       CIE_FDODSC_START + CIE_FDODSC_EVENT_NUM - 1},
	{CIE_SAL,   	   CIE_SAL_START,          CIE_SAL_START + CIE_SAL_EVENT_NUM - 1},
	{SMART_DEPTH,      SMART_DEPTH_START,      SMART_DEPTH_START + SMART_DEPTH_EVENT_NUM - 1},
	{AUDIO_NN,         AUDIO_NN_START,         AUDIO_NN_START + AUDIO_NN_EVENT_NUM - 1},
	{FLASHAI_PREFILL,  FLASHAI_PREFILL_START,  FLASHAI_PREFILL_START + FLASHAI_PREFILL_EVENT_NUM - 1},
	{FLASHAI_DECODE,   FLASHAI_DECODE_START,   FLASHAI_DECODE_START + FLASHAI_DECODE_EVENT_NUM - 1},
	{AIGC_VAE,  	   AIGC_VAE_START,   	   AIGC_VAE_START + AIGC_VAE_EVENT_NUM - 1},
	{GLES_DLSS,  	   GLES_DLSS_START,   	   GLES_DLSS_START + GLES_DLSS_EVENT_NUM - 1},
	{NEURAL_FRAME,     NEURAL_FRAME_START,     NEURAL_FRAME_START + NEURAL_FRAME_EVENT_NUM - 1},
	{FLASH_LIGHT,      FLASH_LIGHT_START,      FLASH_LIGHT_START + FLASH_LIGHT_EVENT_NUM - 1},
	{DLSS_FI,    	   DLSS_FI_START,          DLSS_FI_START + DLSS_FI_EVENT_NUM - 1},
	{FLASHAI_ABNORMAL, FLASHAI_ABNORMAL_START, FLASHAI_ABNORMAL_START + FLASHAI_ABNORMAL_EVENT_NUM - 1},
};

void hts_set_dev_ctx_events(void)
{
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	dev_ctx->res.event_num[NPU_STATIC_ALLOC] = HTS_MAX_NPU_STATIC_EVENT_NUM;
	dev_ctx->res.event_num[NPU_DYNAMIC_ALLOC] = HTS_MAX_NPU_DYNAMIC_EVENT_NUM;
	dev_ctx->res.event_num[OTHER_DYNAMIC_ALLOC] = HTS_MAX_OTHER_DYNAMIC_EVENT_NUM;
	dev_ctx->res.event_num[OTHER_STATIC_ALLOC] = HTS_MAX_OTHER_STATIC_EVENT_NUM;
}

event_alloc_type hts_get_alloc_type_by_eventid(uint16_t event_id)
{
	if (event_id >= NPU_STATIC_EVENT_START && event_id <= NPU_STATIC_EVENT_END) {
		return NPU_STATIC_ALLOC;
	} else if (event_id <= NPU_DYNAMIC_EVENT_END) {
		return NPU_DYNAMIC_ALLOC;
	} else if (event_id <= OTHER_DYNAMIC_EVENT_END) {
		return OTHER_DYNAMIC_ALLOC;
	} else if (event_id <= OTHER_STATIC_EVENT_END) {
		return OTHER_STATIC_ALLOC;
	} else {
		hts_drv_err("invalid event_id:%hu\n", event_id);
		return MAX_ALLOC_TYPE;
	}
	return MAX_ALLOC_TYPE;
}

static event_alloc_type hts_get_alloc_event_type(uint32_t dev_type, uint32_t event_type) 
{
	if (dev_type == DEV_NPU) {
		if (event_type == STATIC_EVENT)
			return NPU_STATIC_ALLOC;
		return NPU_DYNAMIC_ALLOC;	
	}
	if (event_type == STATIC_EVENT)
		return OTHER_STATIC_ALLOC;
	return OTHER_DYNAMIC_ALLOC;
}

static int hts_check_graph(uint32_t event_type, uint32_t dev_type, uint32_t graph_id)
{
	uint32_t graph_num;
	graph_num = sizeof(graph_event_range_table) / sizeof(graph_event_range_table[0]);
 
	cond_return_error((event_type == STATIC_EVENT) && (graph_id >= HTS_TEST_GRAPH_ID_BEGIN + HTS_TEST_GRAPH_NUM), -1,
		"static graphid must less than reserve graphid, event_type:%u, graph_id:%u\n", event_type, graph_id);
	cond_return_error((event_type == DYNAMIC_EVENT) && (graph_id < graph_num), -1,
		"dynamic graphid must more than reserve graphid, event_type:%u, graph_id:%u\n", event_type, graph_id);
	cond_return_error((graph_id < FLASH_LIGHT) && (dev_type != DEV_NPU), -1,
		"npu static must contain npu, dev:%u, graph_id:%u\n", dev_type, graph_id);
	cond_return_error((graph_id >= FLASH_LIGHT) && (graph_id < graph_num) && (dev_type == DEV_NPU), -1,
		"other static dont contain npu, dev:%u, graph_id:%u\n", dev_type, graph_id);
 
	return 0;
}

int hts_event_alloc(uint16_t uid, struct hts_alloc_info* events_info, uint32_t graph_id)
{
	uint32_t event_id_start;
	uint32_t event_id_end;
	uint32_t i;
	uint32_t graph_num;
	uint16_t *event_idle_num = NULL;
	hts_check_table table = {0};
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	uint16_t* tmp_events = &events_info->events[0];
	uint32_t num = events_info->event_num;
	uint32_t event_type = events_info->event_type;
	uint32_t dev_type = events_info->dev_type;
	event_alloc_type type = 0;

	if (hts_check_graph(event_type, dev_type, graph_id) != 0)
		return -1;

	type = hts_get_alloc_event_type(dev_type, event_type);
	hts_drv_warn("alloc dev_type :%u, event_type:%u, type:%u\n", dev_type, event_type, type);

	cond_return_error(type >= MAX_ALLOC_TYPE, -EINVAL, "event_alloc_type type is invalid\n");
	event_id_start = event_range_table[type].event_id_start;
	event_id_end = event_range_table[type].event_id_end;
	event_idle_num = &dev_ctx->res.event_num[type];
	
	hts_drv_warn("npu static:%hu, npu dynamic:%hu, other static:%hu, other dynamic:%hu",
		dev_ctx->res.event_num[NPU_STATIC_ALLOC], dev_ctx->res.event_num[NPU_DYNAMIC_ALLOC],
		dev_ctx->res.event_num[OTHER_STATIC_ALLOC], dev_ctx->res.event_num[OTHER_DYNAMIC_ALLOC]);
	if (*event_idle_num < num) {
		if (type == OTHER_DYNAMIC_ALLOC && dev_ctx->res.event_num[NPU_DYNAMIC_ALLOC] >= num) {
			hts_drv_warn("take from npu events");
			event_id_start = NPU_DYNAMIC_EVENT_START;
			event_id_end = NPU_DYNAMIC_EVENT_END;
			event_idle_num = &dev_ctx->res.event_num[NPU_DYNAMIC_ALLOC];
		} else {
			hts_drv_err("idle num not enough, event type:%d, need event num %u\n", type, num);
			return -EINVAL;
		}	
	}

	graph_num = sizeof(graph_event_range_table) / sizeof(graph_event_range_table[0]);
	if (graph_id < graph_num) {
		event_id_start = graph_event_range_table[graph_id].event_id_start;
		event_id_end = graph_event_range_table[graph_id].event_id_end;
	}

	cond_return_error(((event_id_end - event_id_start + 1) < num), -EINVAL,
		"event_num not enough, event_id_start:%d, event_id_end=%d alloc num=%u", event_id_start, event_id_end, num);
	hts_drv_warn("event_idle_num:%d, alloc_num:%d", *event_idle_num, num);
	for (i = 0; i < num; i++) {
		tmp_events[i] = find_next_zero_bit(dev_ctx->res.event_bitmap, event_id_end + 1, event_id_start);
		if (tmp_events[i] >= event_id_end + 1) {
			hts_drv_err("event_id_start:%d, event_id_end=%d", event_id_start, event_id_end);
			hts_drv_err("event bitmap is not enough, surplus num=%d", i);
			(void)hts_event_free(uid, tmp_events, i);
			return -EINVAL;
		}
		hts_drv_warn("alloc event =%hu", tmp_events[i]);
		set_bit(tmp_events[i], dev_ctx->res.event_bitmap);
		hts_get_auth_table(tmp_events[i], &table);
		table.data.valid = 1;
		table.data.uid = uid;
		table.data.dst_id = dev_type;
		(void)hts_set_auth_table(tmp_events[i], &table);
	}
	*event_idle_num -= i;
	
	return 0;
}