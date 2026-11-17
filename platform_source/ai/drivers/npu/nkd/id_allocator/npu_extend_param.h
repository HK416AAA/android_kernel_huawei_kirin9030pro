/*
 * npu_extend_param.h
 *
 * about npu model extend param
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 *
 */
#ifndef _NPU_EXTEND_PARAM_H
#define _NPU_EXTEND_PARAM_H

#include "npu_common.h"
#define NPU_MAX_EXTEND_PARAM_FFN_LAYER_NUM 32
#define MAX_DFA_EVENT_NUM 5
#define MAX_IOVA_ADDR_NUM 2
#define MAX_EXTEND_PARAM_NUM 5
#define MAX_EXTEND_PARAM_LIST_NUM 10
#define PAGE_4K 4096

#define IOMMU_READ      (1 << 0)
#define IOMMU_WRITE     (1 << 1)

typedef enum npu_exparam_event_e {
    NPU_EXPARAM_EVENT_RCV_DFA_SUCCESS = 0,
    NPU_EXPARAM_EVENT_RCV_DFA_FAILED = 1,
    NPU_EXPARAM_EVENT_TRANS_TO_DFA_SUCCESS = 2,
    NPU_EXPARAM_EVENT_TRANS_TO_DFA_FAILED = 3,
    NPU_EXPARAM_EVENT_MAX
} npu_exparam_event_type;

typedef enum npu_exparam_list_e {
    NPU_EXPARAM_LIST_PREFILL_START = 0,
    NPU_EXPARAM_LIST_PREFILL_END = 1,
    NPU_EXPARAM_LIST_TYPE_MAX
} npu_exparam_list_type;

typedef enum npu_exparam_e {
    NPU_EXPARAM_BLOCK_FFN_LOAD = 0,
    NPU_EXPARAM_DFA_EVENTID = 1,
    NPU_EXPARAM_INPUT_OUTPUT_ADDR = 2,
    NPU_EXPARAM_IOVA_ADDR = 3,
    NPU_EXPARAM_TYPE_MAX
} npu_exparam_type;

typedef struct {
    uint8_t n;
    uint8_t k;
    uint8_t lun[2];
    uint32_t va_map_offset[2];
    uint32_t lba_base[2];
    uint32_t reserved;
} npu_exparam_block_fnn_load_desc_t;

typedef struct {
    uint16_t event_type;
    uint16_t event_id;
} npu_exparam_event_id_e;

typedef struct {
    uint32_t uid;
    npu_exparam_event_id_e event_id_e[MAX_DFA_EVENT_NUM];
} npu_exparam_event_id_t;

typedef struct {
    int32_t fd[MAX_IOVA_ADDR_NUM];
    uint32_t offset[MAX_IOVA_ADDR_NUM];
    uint32_t size[MAX_IOVA_ADDR_NUM];
} npu_exparam_io_addr_t;

typedef struct {
    uint64_t iova_addr;
    uint64_t iova_size;
    int32_t fd;
    uint32_t reserved;
} npu_exparam_iova_addr_t;

typedef struct {
	// acpu-->tscpu
    uint32_t exparam_type:16;
    uint32_t param_cnt:4;
    uint32_t reserved0:12;
    uint32_t reserved1;
    union {
        npu_exparam_block_fnn_load_desc_t prefillLoadDesc;
        npu_exparam_event_id_t eventID;
        npu_exparam_io_addr_t ioAddr;
        npu_exparam_iova_addr_t iovaAddr;
        uint32_t value[6];
    } param_value;
} npu_exparam_t;
 
typedef struct {
    uint8_t type;
    uint8_t extend_param_cnt;
    uint16_t model_id;
    uint8_t exparam_list_id;
    uint8_t reserved[3];
    npu_exparam_t extend_param[MAX_EXTEND_PARAM_NUM];
} npu_exparam_list_t;

struct npu_id_entity *npu_alloc_extend_param_id(u8 dev_ctx_id);
int npu_free_extend_param_id(u8 dev_ctx_id, u32 exparam_id);
int npu_set_extend_param(u8 devid, npu_exparam_list_t *extend_param_info);
int npu_bind_extend_param(u8 devid, u32 exparam_id, u32 model_id);

#endif