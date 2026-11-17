/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef DPA_INET_SOCKET_H
#define DPA_INET_SOCKET_H

/* dpa getsockopt */
#define DPA_STATUS 101

struct dpa_status {
    unsigned int status;
    int fd;
};

void socket_take_over_init(void);

#endif
