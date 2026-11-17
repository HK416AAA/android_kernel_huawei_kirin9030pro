/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef BRIDGE_MSG_API_H
#define BRIDGE_MSG_API_H

#include "ring.h"
#include "common_msg.h"
#include "sys_msg.h"
#include "stack_log.h"
#include "stack_time.h"
#include "global_res_stats.h"
#include "socket/sbr_protocol_api.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MSG_ENTRY(_ptr, _type, _member) container_of((void *)(_ptr), _type, _member)

#define SET_MSG_ERR(m, error) ((m)->param.err = (error))
#define GET_MSG_ERR(m)        ((m)->param.err)

static inline void msg_init(data_com_msg *pmsg)
{
    pmsg->param.err = 0;
    pmsg->param.euid = -1;
    pmsg->param.msg_self = 0;
}

static inline data_com_msg *msg_malloc(mring_handle mhandle)
{
    data_com_msg *m = (data_com_msg *)sys_msg_malloc(mhandle);
    if (m == NULL) {
        NS_ERR("msg malloc failed");
        return NULL;
    }
    m->param.op_completed = 0;
    msg_init(m);
    return m;
}

/*
 need_to_free:
 when run on dpa_mode, false means not free(when send successfully, free actually by dmi channel), true means free
 when run on kenel_mode, this param has no effect(must free msg)
*/
static inline void msg_free(data_com_msg *m, bool need_to_free)
{
    if (m == NULL) {
        NS_ERR("m is null");
        return;
    }

    sys_msg_free(m, need_to_free);
}

static inline void sbr_msg_free(data_com_msg *msg, bool need_to_free)
{
    if (msg->param.is_dmi_msg) {
        msg_free(msg, need_to_free);
    } else {
        stack_free(msg);
    }
}

s32 msg_try_post(data_com_msg *m, mring_handle mhandle);

#ifdef __cplusplus
}
#endif

#endif /* BRIDGE_MSG_API_H */
