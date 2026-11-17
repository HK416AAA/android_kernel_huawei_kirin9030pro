/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#include "stack_mem.h"
#include "common_msg.h"
#include "socket/sbr_prot_com.h"
#include "config.h"
#include "sbr_res_mgr.h"

sbr_socket_t *sbr_get_sbr_sk(struct sock *lsk)
{
    sbr_socket_t *sk = (sbr_socket_t *)inet_sk(lsk)->dpa_ctx;
    return sk;
}

sbr_socket_t *sbr_lookup_sk(struct sock *lsk)
{
    sbr_socket_t *sk = sbr_get_sbr_sk(lsk);
    return sk;
}

