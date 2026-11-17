/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SBR_MISC_H
#define SBR_MISC_H

#include "socket/sbr_protocol_api.h"
#include "stack_log.h"
#include "spl_common_opt.h"
#include "ring.h"
#include "opt.h"

#ifdef __cplusplus
extern "C" {
#endif

extern mring_handle get_instance_msg_box(u16 thread_index);
static inline mring_handle sbr_get_msg_box(const sbr_socket_t *sk)
{
    (void)sk;
    return get_instance_msg_box(GLOBAL_THREAD_INDEX);
}

#ifdef __cplusplus
}
#endif

#endif
