/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#ifndef SYS_MSG_H
#define SYS_MSG_H

#include <linux/types.h>
#include "bsp_dmi.h"

#define DATA_MSG_PRE sizeof(struct dmi_msg)

typedef s32 (*sys_msg_func)(void *msg);
typedef void (*dmi_client_event)(void);

void *sys_msg_pool_create(u32 pool_size, u32 msg_len);
void *sys_msg_box_create(u32 size);
void *sys_msg_malloc(void *mhandle);
void sys_msg_free(void *msg, bool need_to_free);
s32 sys_msg_try_post(void *msg, void *mhandle);
s32 sys_msg_listen(void *mhandle, sys_msg_func func, sys_msg_func err_func);
void sys_msg_register_event_cb(dmi_client_event cb);

static inline bool stack_msg_is_last(void *msg)
{
    return (((struct dmi_msg *)msg)->last != 0) ? true : false;
}

#endif
