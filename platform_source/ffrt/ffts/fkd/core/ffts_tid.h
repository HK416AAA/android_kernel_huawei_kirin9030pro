/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts tid
 */
#ifndef _FFTS_TID_H_
#define _FFTS_TID_H_

#include <linux/types.h>

#define FFTS_TID_START 1
#define FFTS_TID_NUM_MAX 1023
#define FFTS_TID_END (FFTS_TID_START + FFTS_TID_NUM_MAX - 1)
#define FFTS_INVALID_TID 0

void ffts_tid_init(void);
void ffts_tid_deinit(void);

uint16_t ffts_request_tid(pid_t pid);
void ffts_release_tid(uint16_t ffts_tid);
#endif