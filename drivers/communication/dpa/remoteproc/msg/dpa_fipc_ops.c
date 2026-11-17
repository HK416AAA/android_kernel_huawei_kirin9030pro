/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: msg
 * Author:
 * Created: 2021-12-10
 * Last Modified:
 * History:
 * Modification: Create file
 */
#include <linux/version.h>
#include <linux/types.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <securec.h>
#include "bsp_dpa_fipc.h"
#include "dpa_fipc_ops.h"
#include "dpa_msg_task.h"
#include "bsp_print.h"
#include "dpa_msg_error_code.h"

struct dpa_channel_ctrl_t *dpa_fipc_recv_ctrl = NULL;
struct dpa_channel_ctrl_t *dpa_fipc_send2dpa_ctrl = NULL;

int dpa_msg_fipc_recv_process(struct dpa_channel_ctrl_t *chn_ctrl)
{
    int pktlen, hdrlen, total_len;
    struct dpa_cmsg_hdr *phdr;
    struct dpa_cmsg_lite_exthdr *lite_exthdr;

    if (chn_ctrl == NULL) {
        dpa_msg_trace("dpa_msg_fipc_recv_process bad chn_ctrl\n");
        return MSG_ERR_COMMON_INPUT;
    }
    pktlen = dpa_fipc_nextpkt_len(chn_ctrl);
    if (pktlen == 0) {
        /* 这属于正常情况,不要打印 */
        return MSG_ERR_EAGAIN;
    }
    if (pktlen < (int)sizeof(struct dpa_cmsg_hdr) || pktlen >= chn_ctrl->smsg_sz) {
        dpa_msg_trace("dpa_msg_fipc_recv_process bad pktlen[%d]\n", pktlen);
        /* skip this packet */
        return MSG_ERR_RECV_BAD_MSG_LENGTH;
    }
    total_len = dpa_fipc_default_recv(chn_ctrl, chn_ctrl->smsg_buf, pktlen);
    if (total_len != pktlen) {
        dpa_msg_trace("dpa_msg_fipc_recv_process unexpected pktlen[%d]\n", pktlen);
        /* skip this packet */
        return MSG_ERR_RECV_BAD_MSG_LENGTH;
    }
    phdr = (struct dpa_cmsg_hdr *)chn_ctrl->smsg_buf;
    hdrlen = sizeof(struct dpa_cmsg_hdr) + sizeof(struct dpa_cmsg_lite_exthdr);
    /* 重要：这个检查成立，就可以认为phdr->len是可信的，这样后面不用再检查phdr->len溢出等 */
    if (pktlen != phdr->len + hdrlen) {
        dpa_msg_trace("msg_recv_process len check failed\n");
        return MSG_ERR_RECV_BAD_MSG_LENGTH;
    }
    lite_exthdr = (struct dpa_cmsg_lite_exthdr *)(phdr + 1);
    dpa_msg_lite_process(lite_exthdr, (void *)(lite_exthdr + 1), phdr->len);

    return MSG_OK;
}

int dpa_fipc_recv_proc(void *arg)
{
    int ret;
    struct dpa_msg_task_ctrl_t *ptask_ctrl = (struct dpa_msg_task_ctrl_t *)arg;
    if (ptask_ctrl == NULL) {
        dpa_msg_err("dpa_fipc_recv_proc fasiled\n");
        return -1;
    }
    while (!kthread_should_stop()) {
        ret = down_interruptible(&ptask_ctrl->task.worker_sem);
        if (unlikely(ret < 0)) {
            dpa_msg_err("task was interrupted by a signal: %d\n", ret);
            continue;
        }
        do {
            ret = dpa_msg_fipc_recv_process(ptask_ctrl->p_channel_ctrl);
        } while (ret == 0);
        __pm_relax(ptask_ctrl->task.worker_wakelock);
    };
    return 0;
}

int dpa_fipc_default_cb(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    struct dpa_msg_task_t *p_task = NULL;
    struct dpa_channel_ctrl_t *p_ctrl = (struct dpa_channel_ctrl_t *)arg;
    if (p_ctrl == NULL || p_ctrl->task == NULL) {
        dpa_msg_err("dpa_msg_default_cb bad channel\n");
        return MSG_ERR_COMMON_INPUT;
    }
    p_task = p_ctrl->task;

    __pm_stay_awake(p_task->worker_wakelock);
    up(&p_task->worker_sem);
    return 0;
}

int dpa_fipc_default_open(struct dpa_channel_ctrl_t *chn_ctrl, unsigned type)
{
    int ret;
    dpa_fipc_chn_attr_t attr;
    dpa_fipc_chn_attr_t *pattr = &attr;
    struct dpa_fipc_cmsg_chn_t *dpa_fipc_cmsg_chn = NULL;

    ret = bsp_dpa_fipc_chn_attr_init(pattr);
    if (unlikely(ret)) {
        dpa_msg_err("chan attr init error\n");
        return ret;
    }
    dpa_fipc_cmsg_chn = (struct dpa_fipc_cmsg_chn_t *)(chn_ctrl->cmsg_chn);
    pattr->chnid = chn_ctrl->phychnid;
    pattr->type = type;
    if (pattr->type == DPA_FIPC_CHNL_RECV) {
        pattr->cbk_arg = chn_ctrl;
        pattr->cbk = dpa_fipc_default_cb;
    }
    pattr->size = dpa_fipc_cmsg_chn->buf_sz;
    pattr->va = dpa_msg_dma_buf_alloc(pattr->size, (dma_addr_t *)&pattr->ga);
    if (pattr->va == NULL) {
        dpa_msg_err("bsp_dpa_fipc_chn_open %d malloc failec\n", pattr->chnid);
        return MSG_ERR_ENOMEM;
    }

    ret = bsp_dpa_fipc_chn_open(&dpa_fipc_cmsg_chn->handle, &attr);
    if (ret) {
        dpa_msg_trace("bsp_dpa_fipc_chn_open %d error ret=%d\n", pattr->chnid, ret);
        return ret;
    }
    chn_ctrl->status = MSG_CHN_STATUS_INITED;
    return MSG_OK;
}

int dpa_fipc_default_send(dpa_msg_blkx3_desc_t *send_desc)
{
    struct dpa_fipc_cmsg_chn_t *dpa_fipc_chn = (struct dpa_fipc_cmsg_chn_t *)(dpa_fipc_send2dpa_ctrl->cmsg_chn);
    return bsp_dpa_fipc_chn_blks_send(dpa_fipc_chn->handle, (dpa_fipc_blk_desc_t *)send_desc);
}

int dpa_fipc_default_recv(struct dpa_channel_ctrl_t *chn_ctrl, void *buf, unsigned int len)
{
    int ret;
    struct dpa_fipc_cmsg_chn_t *dpa_fipc_chn = (struct dpa_fipc_cmsg_chn_t *)(chn_ctrl->cmsg_chn);
    ret = bsp_dpa_fipc_chn_recv(dpa_fipc_chn->handle, buf, len);
    if (ret != (int)(len)) {
        dpa_msg_err("dpa_fipc_default_recv too small,len=%d, ret = %d\n", len, ret);
        return MSG_ERR_EBADMSG;
    }
    return ret;
}

int dpa_fipc_nextpkt_len(struct dpa_channel_ctrl_t *chn_ctrl)
{
    int ret;
    ioctl_dpa_nxtpkt pktinfo;
    struct dpa_fipc_cmsg_chn_t *dpa_fipc_chn = (struct dpa_fipc_cmsg_chn_t *)(chn_ctrl->cmsg_chn);
    ret = bsp_dpa_fipc_chn_ioctl(dpa_fipc_chn->handle, DPA_FIPC_IOCTL_CHN_NXTPKT_INF, &pktinfo, sizeof(pktinfo));
    if (ret) {
        dpa_msg_err("dpa_fipc ioctrl err: %d\n", ret);
        return ret;
    }
    return pktinfo.len;
}

struct dpa_msg_task_ctrl_t *dpa_malloc_msg_task_ctrl(void)
{
    int ret;
    struct dpa_msg_task_ctrl_t *p_task_ctrl = NULL;
    p_task_ctrl = kmalloc(sizeof(struct dpa_msg_task_ctrl_t), GFP_KERNEL);
    if (p_task_ctrl == NULL) {
        return NULL;
    }
    ret = memset_s(p_task_ctrl, sizeof(*p_task_ctrl), 0, sizeof(struct dpa_msg_task_ctrl_t));
    if (ret) {
        return NULL;
    }
    return p_task_ctrl;
}

int dpa_fipc_phychn_init(struct dpa_channel_ctrl_t *channel_ctrl, dpa_msg_phychn_dts_t *phy_node)
{
    int ret = 0;
    struct dpa_fipc_cmsg_chn_t *dpa_fipc_cmsg_chn = NULL;
    struct dpa_msg_task_ctrl_t *p_task_ctrl = NULL;

    dpa_fipc_cmsg_chn = (struct dpa_fipc_cmsg_chn_t *)kmalloc(sizeof(struct dpa_fipc_cmsg_chn_t), GFP_KERNEL);
    if (dpa_fipc_cmsg_chn == NULL) {
        return MSG_ERR_ENOMEM;
    }
    channel_ctrl->phychnid = phy_node->phychnid;
    channel_ctrl->cmsg_chn = dpa_fipc_cmsg_chn;
    channel_ctrl->smsg_sz = phy_node->smsg_sz;
    dpa_fipc_cmsg_chn->buf_sz = phy_node->buf_sz;
    if (DPA_MSG_PHYCHN_SEND(phy_node->dir)) {
        dpa_fipc_send2dpa_ctrl = channel_ctrl;
        ret = dpa_fipc_default_open(channel_ctrl, DPA_FIPC_CHNL_SEND);
    } else if (DPA_MSG_PHYCHN_RECV(phy_node->dir)) {
        channel_ctrl->smsg_buf = kmalloc(channel_ctrl->smsg_sz, GFP_KERNEL);
        if (channel_ctrl->smsg_buf == NULL) {
            return MSG_ERR_ENOMEM;
        }
        dpa_fipc_recv_ctrl = channel_ctrl;
        p_task_ctrl = dpa_malloc_msg_task_ctrl();
        if (p_task_ctrl == NULL) {
            return MSG_ERR_COMMON_MEM_OP_ERROR;
        }
        p_task_ctrl->p_channel_ctrl = channel_ctrl;
        ret = dpa_msg_task_init(p_task_ctrl);
        if (ret) {
            return ret;
        }
        channel_ctrl->task = &p_task_ctrl->task;
        ret = dpa_fipc_default_open(channel_ctrl, DPA_FIPC_CHNL_RECV);
    }
    return ret;
}
