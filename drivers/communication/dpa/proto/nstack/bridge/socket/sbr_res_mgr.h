/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SBR_RES_MGR_H
#define SBR_RES_MGR_H

#include <net/sock.h>
#include "socket/sbr_protocol_api.h"

#ifdef __cplusplus
extern "C" {
#endif

sbr_socket_t *sbr_lookup_sk(struct sock *lsk);
sbr_socket_t *sbr_get_sk(s32 fd);
sbr_socket_t *sbr_get_sbr_sk(struct sock *lsk);

#ifdef __cplusplus
}
#endif

#endif
