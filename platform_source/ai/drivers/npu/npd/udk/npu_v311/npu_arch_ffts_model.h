/*
 * npu_ffts_model.h
 *
 * about npu ffts model arch adapter
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 */
#ifndef __NPU_ARCH_FFTS_MODEL_H
#define __NPU_ARCH_FFTS_MODEL_H

#include "npu_osal.h"
#include "npu_model_description.h"

int npu_ffrt_load_mdc_buf(struct npu_ffrt_load_model_buf_info *model_desc);
int npu_ffrt_load_swap_buf_index(struct npu_ffrt_load_model_buf_info *model_desc, int swap_buf_index);
#ifdef CONFIG_NPU_FAULT_INJECT
struct npu_error_info *driver_npu_error_get_memory(void);
#endif

#endif

