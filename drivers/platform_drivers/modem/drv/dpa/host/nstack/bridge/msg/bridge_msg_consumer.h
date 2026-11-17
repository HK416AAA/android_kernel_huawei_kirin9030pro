/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef BRIDGE_MSG_CONSUMER_H
#define BRIDGE_MSG_CONSUMER_H

#include "common_msg.h"

#ifdef __cplusplus
extern "C" {
#endif

s32 call_acpu_msg_fun(data_com_msg *m, bool msg_need_free);

#ifdef __cplusplus
}
#endif

#endif
