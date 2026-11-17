/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */

#ifndef _DPA_MSG_CORE_H
#define _DPA_MSG_CORE_H
#include "dpa_msg_plat.h"

#define MSG_CHN_STATUS_INITED 2
enum dpa_cmsg_type {
    DPA_CMSG_TYPE_PROTO = 1,
    DPA_CMSG_TYPE_SINGLE = 2, /* 单条消息 */
    DPA_CMSG_TYPE_SEGBEG = 3, /* 分段消息开始 */
    DPA_CMSG_TYPE_SEGMSG = 4, /* 分段消息中间 */
    DPA_CMSG_TYPE_SEGEND = 5, /* 分段消息结束 */
    DPA_CMSG_TYPE_LITE = 6,   /* 单条lite消息 */
};

struct dpa_cmsg_hdr {
    unsigned char type; /* cmsg_type */
    unsigned char rsv;
    unsigned short seq;   /* 跨核消息的计数，用于底层通道的检查 */
    unsigned short flags; /* 跨核消息的标记，目前还没有用到 */
    unsigned short len;   /* cmsg报文长度, 最大只能支持到65535 */
};
struct dpa_cmsg_lite_exthdr {
    unsigned int src;
    unsigned int dst;
};


struct dpa_msg_chn_hdl *get_dpa_msgchn_hdl(unsigned char msgid);
void dpa_msg_lite_process(struct dpa_cmsg_lite_exthdr *lite_exthdr, void *buf, unsigned int len);

#endif
