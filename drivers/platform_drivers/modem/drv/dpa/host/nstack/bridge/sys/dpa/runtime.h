/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#ifndef RUNTIME_H
#define RUNTIME_H

#include <net/sock.h>
#include <net/inet_sock.h>
#include "sbr_protocol_api.h"
#include "sbr_socket.h"

typedef struct host_dpa_stat_info {
    u32 sk_id;
    u32 err_code;
    u32 action;
    union {
        struct {
            stat_unit stats[SBR_CONN_STATS_MAX_TYPE];
        } del_tuple;
    } conn_info;
} host_dpa_stat_info_t;

#define DIAG_DPA_HOST_PID (0x8003)

s32 init_runtime(void);
void dpa_socket_pre_take(struct socket *sock);
void dpa_event_report(sbr_socket_t *ssk, enum action_code code);
extern bool get_dpa_stack_bypass_status(void);

#endif
