/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */

#include "dpa_msg_plat.h"
#include "dpa_msg_core.h"
#include "dpa_msg_cmsg.h"
#include "bsp_print.h"
#include "dpa_msg_error_code.h"

#define DPA_MSG_CHN_OPEND 0x1

struct dpa_msg_chn_hdl {
    unsigned int state : 8; /* 通道状态 */
    unsigned int msgid : 8; /* msgid值 */
    unsigned int core_mask : 16;
    void *cmsg_hdl;
    int (*func)(const struct dpa_msg_addr *info, void *buf, unsigned int len);
};

static struct dpa_msg_chn_hdl g_dpa_msg_fd_info[DPA_MSG_CHN_CNT_MAX];

struct dpa_msg_chn_hdl *get_dpa_msgchn_hdl(unsigned char msgid)
{
    if (msgid >= DPA_MSG_CHN_CNT_MAX) {
        return NULL;
    }
    return &g_dpa_msg_fd_info[msgid];
}

int dpa_msg_lite_callback(const struct dpa_msg_addr *src_addr, const struct dpa_msg_addr *dst_addr, void *buf, unsigned int len)
{
    struct dpa_msg_chn_hdl *msg_hdl = NULL;
    if (src_addr == NULL || dst_addr == NULL || buf == NULL || len == 0 || dst_addr->chnid >= DPA_MSG_CHN_CNT_MAX ) {
        return MSG_ERR_EINVAL;
    }
    msg_hdl = get_dpa_msgchn_hdl(dst_addr->chnid);
    if (msg_hdl == NULL) {
        return MSG_ERR_EAGAIN;
    }
    if (msg_hdl->state != DPA_MSG_CHN_OPEND) {
        return MSG_ERR_SEND_BAD_DEST;
    }
    if ((msg_hdl->core_mask & DPA_MSG_CORE_MASK(src_addr->core)) == 0) {
        return MSG_ERR_SEND_BAD_SRC;
    }

    if (msg_hdl->func == NULL) {
        return MSG_ERR_SEND_NO_CBK;
    }

    msg_hdl->func(src_addr, buf, len);

    return MSG_OK;
}

void dpa_msg_lite_process(struct dpa_cmsg_lite_exthdr *lite_exthdr, void *buf, unsigned int len)
{
    int ret;
    struct dpa_msg_addr src_addr;
    struct dpa_msg_addr dst_addr;

    src_addr.core = (lite_exthdr->src >> 0x10);
    src_addr.chnid = (lite_exthdr->src & 0xFFFF);
    dst_addr.core = (lite_exthdr->dst >> 0x10);
    dst_addr.chnid = (lite_exthdr->dst & 0xFFFF);

    ret = dpa_msg_lite_callback(&src_addr, &dst_addr, buf, len);
    if (ret != 0) {
        dpa_msg_err("msg fw failed 0x%x->0x%x ret=%d\n", (unsigned)lite_exthdr->src,
            (unsigned)lite_exthdr->dst, ret);
    }

    return;
}

void bsp_dpa_msgchn_attr_init(struct dpa_msgchn_attr *pattr)
{
    if (pattr == NULL) {
        return;
    }
    (void)memset_s(pattr, sizeof(struct dpa_msgchn_attr), 0, sizeof(struct dpa_msgchn_attr));
    pattr->magic = MID_ATTR_INIT_MAGIC;
}

int bsp_dpa_msg_lite_open(struct dpa_msg_chn_hdl **ppchn_hdl, struct dpa_msgchn_attr *pattr)
{
    if (ppchn_hdl == NULL || pattr == NULL) {
        return MSG_ERR_EINVAL;
    }
    if (pattr->magic != MID_ATTR_INIT_MAGIC || pattr->chnid >= DPA_MSG_CHN_CNT_MAX) {
        return MSG_ERR_ENXIO;
    }

    if (g_dpa_msg_fd_info[pattr->chnid].state == DPA_MSG_CHN_OPEND) {
        return MSG_ERR_COMMON_BAD_STATE;
    }
    g_dpa_msg_fd_info[pattr->chnid].msgid = pattr->chnid;
    g_dpa_msg_fd_info[pattr->chnid].core_mask = pattr->coremask;
    g_dpa_msg_fd_info[pattr->chnid].func = pattr->lite_notify;
    g_dpa_msg_fd_info[pattr->chnid].state = DPA_MSG_CHN_OPEND;
    *ppchn_hdl = &g_dpa_msg_fd_info[pattr->chnid];
    return MSG_OK;
}

int bsp_dpa_msg_lite_sendto(struct dpa_msg_chn_hdl *chn_hdl, const struct dpa_msg_addr *dst, void *msg, unsigned len)
{
    struct dpa_msg_addr src_addr;
    if (chn_hdl == NULL || dst == NULL || msg == NULL || len == 0) {
        return MSG_ERR_EINVAL;
    }
    if (chn_hdl->state != DPA_MSG_CHN_OPEND) {
        return MSG_ERR_COMMON_BAD_STATE;
    }
    src_addr.core = THIS_CORE;
    src_addr.chnid = chn_hdl->msgid;
    if (dst->core == DPA_MSG_CORE_DPA) {
        return dpa_send_lite_msg(&src_addr, dst, msg, len);
    }
    return MSG_ERR_SEND_BAD_DEST;
}
