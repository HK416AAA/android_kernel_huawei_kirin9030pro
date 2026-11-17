/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SBR_SOCKET_H
#define SBR_SOCKET_H

#include <net/sock.h>
#include <linux/socket.h>
#include "stack_types.h"
#include "socket/sbr_protocol_api.h"

s8 set_dpa_sk(sbr_socket_t *sk);
sbr_socket_t *get_dpa_sk(int fd);
void put_dpa_sk(sbr_socket_t *sk);
void release_dpa_sk(const sbr_socket_t *sk);

s8 sbr_init_socket(struct sock *lsk);
s32 sbr_migrate_a2d(struct sock *lsk);
s32 sbr_migrate_d2a(struct sock *lsk, s32 d2a_event);
s32 sbr_connect(struct sock *lsk, const struct sockaddr *name, socklen_t namelen, s32 flags);
s32 sbr_setsockopt(struct sock *lsk, s32 level, s32 optname, const void *optval, socklen_t optlen);
s32 sbr_getsockopt(struct sock *lsk, s32 level, s32 optname, const void *optval, socklen_t *optlen);
s32 sbr_recvmsg(struct sock *lsk, struct msghdr *msg, size_t size, int flags);
s32 sbr_sendmsg(struct sock *lsk, struct msghdr *msg, size_t size);
s32 sbr_shutdown(struct sock *lsk, s32 how);
s32 sbr_close(struct sock *lsk);
void sbr_passive_close(struct sock *lsk);
s32 sbr_init(void);
s32 sbr_get_fd(struct sock *lsk);
s32 sbr_filter_add(sbr_socket_t *ssk, struct dpa_filter_tuple *tuple, s32 ifidx);
void sbr_filter_purge(sbr_socket_t *ssk);
void sbr_dpa_socket_reset(void);
void sbr_dpa_rst_state_set(u8 stat);
u8 sbr_dpa_reseting(void);

enum opt_action {
    OPT_ACTION_LINUX,
    OPT_ACTION_DPA,
    OPT_ACTION_BOTH,
    OPT_ACTION_FALLBACK,
};

enum action_code {
    SOCKET_A2D,
    SOCKET_D2A,
};

enum opt_action sbr_sockopt_get_action(int level, int optname);
bool sbr_sockopt_is_support(int level, int optname);

#endif
