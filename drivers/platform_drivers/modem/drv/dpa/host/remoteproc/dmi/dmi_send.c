#include <linux/version.h>
#include <linux/types.h>
#include <linux/kthread.h>  /* struct task_struct */
#include <linux/spinlock.h> /* struct spinlock */
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/wait.h>
#include <bsp_rproc.h>
#include <bsp_dump.h>
#include "bsp_dpa_msg.h"
#include "bsp_dpa_fipc.h"
#include "bsp_print.h"
#include "dmi_msg.h"

#define DMI_EVENT_SEND 0
#define DMI_EVENT_SEND_STOPING 1
#define DMI_EVENT_SEND_STOP 2
#define DMI_TRY_AGAIN_TIME 10

#define DMI_MSG_FIPC_DEPTH (DMI_MSG_FIPC_SEND_TABLE_SIZE * DPA_FIPC_OPIPE_HEAD_LEN)
#define DMI_MSG_FIPC_SEND_TABLE_SIZE (256)

// 参考bsp_dpa_fipc.h中dpa_fipc_chn_attr_t.underflow_th说明
#define DMI_MSG_FIPC_SEND_FLOWDN_TH (0x3)

struct dmi_send_queue_entry {
    u64 gaddr;
    struct dmi_dma_head *addr;
    unsigned int len;
};
struct dmi_send_queue {
    spinlock_t wlock;
    // 软队列指针
    unsigned int wptr;           // entry的index，指向当前空闲的第一个资源；
    unsigned int depth;
    struct dmi_send_queue_entry entry[DMI_MSG_FIPC_SEND_TABLE_SIZE]; // 记录资源的ringbuf

    unsigned int send_cnt;
    unsigned int send_done;
    unsigned int send_full;
    unsigned int recycle_fail;
    unsigned int send_fipc_fail;
};

struct dmi_msg_ctx g_dmi_msg_send_ctx;
struct dmi_msg_ctx_task g_dmi_msg_send_ctx_task = {0};
struct dmi_send_queue g_dmi_send_queue[DMI_SERVICE_TYPE_COMM] = { 0 };

static inline unsigned int dmi_get_rptr(unsigned int chn)
{
    unsigned int rptr;

    if (bsp_dpa_fipc_chn_rptr_get(g_dmi_msg_send_ctx.dmi_msg_hdl[chn], &rptr)) {
        dpa_pr_err("dmi_get_rptr failed!\n");
        return DMI_CHN_FIPC_RPTR_INVALID;
    }

    return rptr / DPA_FIPC_OPIPE_HEAD_LEN;
}

void dmi_send_show(unsigned int chn)
{
    struct dmi_send_queue *q = NULL;

    if (chn >= DMI_SERVICE_TYPE_COMM) {
        return;
    }
    q = &g_dmi_send_queue[chn];
    dpa_pr_err("wptr          :0x%x\n", q->wptr);
    dpa_pr_err("rptr          :0x%x\n", dmi_get_rptr(chn));

    dpa_pr_err("send_cnt      :0x%x\n", q->send_cnt);
    dpa_pr_err("send_done     :0x%x\n", q->send_done);
    dpa_pr_err("send_full     :0x%x\n", q->send_full);
    dpa_pr_err("recycle fail  :0x%x\n", q->recycle_fail);
    dpa_pr_err("send_fipc_fail:0x%x\n", q->send_fipc_fail);
}

int dmi_msg_send_sync(int chn, void *msg, u64 pa, unsigned int len)
{
    unsigned long lockflag;
    unsigned int wptr, next_wptr;
    unsigned int rptr;
    struct dmi_msg_ctx_task *ctx = &g_dmi_msg_send_ctx_task;
    int ret = 0;
    struct dmi_send_queue *table = &g_dmi_send_queue[chn];

    spin_lock_irqsave(&table->wlock, lockflag);
    if (ctx->stat == DMI_RST) {
        spin_unlock_irqrestore(&table->wlock, lockflag);
        dpa_pr_err("dmi dpa in reset:%d\n", chn);
        return -EACCES;
    }
    wptr = table->wptr;
    next_wptr = (wptr + 1) % DMI_MSG_FIPC_SEND_TABLE_SIZE;
    rptr = dmi_get_rptr(chn);
    if (unlikely(rptr == DMI_CHN_FIPC_RPTR_INVALID)) {
        spin_unlock_irqrestore(&table->wlock, lockflag);
        dpa_fail_event_add(DPA_DMI_MSG_SEND_FAIL, FAIL_TYPE_SEND_FAIL);
        return -1;
    }
    if (next_wptr == rptr) {
        bsp_dpa_fipc_channel_underflow_int_en(g_dmi_msg_send_ctx.dmi_msg_hdl[chn]);
        spin_unlock_irqrestore(&table->wlock, lockflag);
        dpa_fail_event_add(DPA_DMI_MSG_SEND_FAIL, FAIL_TYPE_FULL);
        return -EAGAIN;
    }

    table->entry[wptr].addr->gaddr = pa;
    table->entry[wptr].addr->len = len;
    table->entry[wptr].addr->chn = chn;
    table->entry[wptr].len = len;

    bsp_dra_msg_set_flag(msg, DRA_OWN);
    ret = bsp_dpa_fipc_chn_blk2ring_send(g_dmi_msg_send_ctx.dmi_msg_hdl[chn], table->entry[wptr].gaddr, sizeof(struct dmi_dma_head),
        DPA_FIPC_SEND_FLAGS_NODONENOTIFY);
    if (ret) {
        bsp_dra_msg_set_flag(msg, DRA_UNMAP);
        table->send_fipc_fail++;
        spin_unlock_irqrestore(&table->wlock, lockflag);
        dpa_pr_err("dmi fipc send fail:%d\n", ret);
        dpa_fail_event_add(DPA_DMI_MSG_SEND_FAIL, FAIL_TYPE_SEND_FAIL);
        return ret;
    }
    table->wptr = next_wptr;
    spin_unlock_irqrestore(&table->wlock, lockflag);
    return ret;
}

void dmi_msg_send_stop(void)
{
    struct dmi_msg_ctx_task *ctx = &g_dmi_msg_send_ctx_task;
    struct dmi_send_queue *table = NULL;
    unsigned long lockflag;
    int i;

    for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
        bsp_dpa_fipc_channel_all_int_dis(g_dmi_msg_send_ctx.dmi_msg_hdl[i]);
        table = &g_dmi_send_queue[i];
        spin_lock_irqsave(&table->wlock, lockflag);
        ctx->stat = DMI_RST;
        spin_unlock_irqrestore(&table->wlock, lockflag);
    }
}


int dmi_send_queue_clear(void)
{
    int i;
    unsigned int rptr;
    struct dmi_send_queue *table = NULL;
    unsigned long lockflag;

    for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
        table = &g_dmi_send_queue[i];
        spin_lock_irqsave(&table->wlock, lockflag);
        rptr = dmi_get_rptr(i);
        if (unlikely(rptr == DMI_CHN_FIPC_RPTR_INVALID)) {
            g_dmi_send_queue[i].wptr = 0;
            spin_unlock_irqrestore(&table->wlock, lockflag);
            dpa_pr_err("dmi_send_queue_clear chn:%d failed\n", i);
            return -1;
        } else {
            g_dmi_send_queue[i].wptr = rptr;
        }
        spin_unlock_irqrestore(&table->wlock, lockflag);
    }
    return 0;
}

int dmi_msg_send_restart(void)
{
    int i;
    int ret;

    ret = dmi_send_queue_clear();
    if (ret) {
        return ret;
    }
    g_dmi_msg_send_ctx_task.stat = 0;

    for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
        bsp_dpa_fipc_channel_all_int_en(g_dmi_msg_send_ctx.dmi_msg_hdl[i]);
    }
    return 0;
}

int dmi_client_chn_event_cbk(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    unsigned int plane = (unsigned int)(uintptr_t)arg;
    if (unlikely(event_info == NULL || plane >= DMI_SERVICE_TYPE_COMM)) {
        return -1;
    }

    if (event == DPA_FIPC_EVENT_SEND_FLOWDN) {
        bsp_dpa_fipc_channel_underflow_int_dis(event_info->data_event.chn_hdl);
        dmi_client_chn_event_notify(plane, DMI_EVENT_CHN_NOT_FULL);
    }
    return 0;
}

int dmi_msg_send_ch_init(int chn, int chnid)
{
    dpa_fipc_chn_attr_t attr;
    int ret;
    int i;
    struct dmi_dma_head *base;
    dma_addr_t phys;

    struct dmi_msg_ctx *ctx = &g_dmi_msg_send_ctx;

    spin_lock_init(&g_dmi_send_queue[chn].wlock);
    ret = bsp_dpa_fipc_chn_attr_init(&attr);
    if (ret) {
        dpa_pr_err("bsp_dpa_msg_attr_init failed!\n");
        return ret;
    }

    base = (struct dmi_dma_head *)dmi_client_dma_buf_alloc(
        sizeof(struct dmi_dma_head) * DMI_MSG_FIPC_SEND_TABLE_SIZE, &phys);
    for (i = 0; i < DMI_MSG_FIPC_SEND_TABLE_SIZE; i++) {
        g_dmi_send_queue[chn].entry[i].addr = &base[i];
        g_dmi_send_queue[chn].entry[i].gaddr = phys + sizeof(struct dmi_dma_head) * i;
    }

    attr.chnid = chnid;
    attr.type = DPA_FIPC_CHNL_SEND;
    attr.size = DMI_MSG_FIPC_DEPTH;
    attr.underflow_th = DMI_MSG_FIPC_SEND_FLOWDN_TH;
    attr.cbk = dmi_client_chn_event_cbk;
    attr.cbk_arg = (void *)(uintptr_t)chn;
    attr.va = dmi_client_dma_buf_alloc(attr.size, (dma_addr_t *)&attr.ga);
    if (attr.va == NULL) {
        dpa_pr_err("dmi_msg_send_ch_init dma malloc failed\n");
        return -1;
    }
    g_dmi_send_queue[chn].depth = DMI_MSG_FIPC_SEND_TABLE_SIZE;

    ret = bsp_dpa_fipc_chn_open(&ctx->dmi_msg_hdl[chn], &attr);
    return ret;
}
