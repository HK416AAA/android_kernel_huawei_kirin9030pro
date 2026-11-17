#include <linux/version.h>
#include <linux/types.h>
#include <linux/kthread.h>  /* struct task_struct */
#include <linux/spinlock.h> /* struct spinlock */
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/ktime.h>
#include <linux/timer.h>
#include <bsp_rproc.h>
#include "bsp_dpa_msg.h"
#include "bsp_dpa_fipc.h"
#include "bsp_dmi.h"
#include "bsp_print.h"
#include "bsp_slice.h"
#include "dmi_msg.h"

#define DPA_MSG_FIPC_DEPTH (0xF000)
#define DMI_MSG_HEAD_LEN (sizeof(struct dmi_msg))
struct dmi_msg_ctx g_dmi_msg_recv_ctx;
struct dmi_msg_ctx_task g_dmi_recv_task[DMI_SERVICE_TYPE_PLANE_MAX];
struct dmi_msg *g_dmi_msg[DMI_SERVICE_TYPE_PLANE_MAX];

struct dmi_msg_merge_cfg g_dmi_merge_cfg[DMI_SERVICE_TYPE_COMM] = {
 /* msg_len/0:dis       [5]:1(ms)/0(us)     00:dis 01:1/2 10:3/4 11:7/8
                        [4:0]:val                                          */
    {400,               0x21,               0x1}, /* DMI_SERVICE_TYPE_CTRL */
    {400,               0x21,               0x1}, /* DMI_SERVICE_TYPE_DATA */
    {400,               0x21,               0x1}, /* DMI_SERVICE_TYPE_RAW */
};

#define RECV_BUF_SIZE (256)
#define RECV_BUF_BYTE_SIZE (RECV_BUF_SIZE * sizeof(struct dmi_dma_head))
struct dmi_dma_head g_dmi_recv_buf[DMI_SERVICE_TYPE_COMM][RECV_BUF_SIZE];
struct dmi_msg *g_dmi_recv_msg_buf[DMI_SERVICE_TYPE_COMM][RECV_BUF_SIZE];

static inline void dmi_msg_dispatch(int chn, struct dmi_msg *msg)
{
    if (g_dmi_msg_recv_ctx.cbk[chn] != NULL) {
        g_dmi_msg_recv_ctx.cbk[chn](msg, msg->data.len + DMI_MSG_HEAD_LEN, 1);
    } else {
        bsp_dmi_msg_free(&msg->data);
        dpa_pr_err("read cb null\n");
        dpa_fail_event_add(DPA_DMI_MSG_SEND_FAIL, FAIL_TYPE_RECV_FAIL);
    }
}

static int dmi_msg_mark(int chn, struct dmi_dma_head *heads, u32 cnt)
{
    struct dmi_msg *msg;
    int map[DMI_SERVICE_MAX] = {0};

    do {
        cnt--;
        msg = (struct dmi_msg *)bsp_dra_get_virt(heads[cnt].gaddr);
        g_dmi_recv_msg_buf[chn][cnt] = msg;
        if (!msg || msg->dmi_id >= DMI_SERVICE_MAX) {
            dpa_pr_err("bsp_dra_get_virt null\n");
            return -1;
        }
        if (map[msg->dmi_id] != 0) {
            msg->last = 0;
        } else {
            map[msg->dmi_id] = 1;
            msg->last = 1;
        }
    } while (cnt);
    return 0;
}

static int dmi_msg_recv_cbk(int chn)
{
    u32 len;
    unsigned int i;
    struct dmi_msg *msg = NULL;
    int ret;
    int total_len = 0;
    struct dmi_dma_head *recv_buf = &g_dmi_recv_buf[chn][0];
    dpa_fipc_chn_t hdl = g_dmi_msg_recv_ctx.dmi_msg_hdl[chn];

    len = bsp_dpa_fipc_chn_recv_used_space_get(hdl);
    len = len - (len % sizeof(struct dmi_dma_head));
    len = len > RECV_BUF_BYTE_SIZE ? RECV_BUF_BYTE_SIZE : len;

    ret = bsp_dpa_fipc_chn_recv_raw(hdl, recv_buf, len);
    if (ret == 0) {
        return 0;
    } else if (ret != len) {
        return -1;
    }

    unsigned int cnt = len / sizeof(struct dmi_dma_head);
    if (dmi_msg_mark(chn, recv_buf, cnt)) {
        return -1;
    }

    for (i = 0 ; i < cnt ; i++) {
        msg = g_dmi_recv_msg_buf[chn][i];
        total_len += msg->data.len + DMI_MSG_HEAD_LEN;
        dmi_msg_dispatch(chn, msg);
    }

    return total_len;
}

void dmi_msg_pm_wakeup_timeout(struct wakeup_source *ws, unsigned int msec)
{
    ktime_t now, expires;
    s64 remaining_ms;

    if (!ws) {
        return;
    }

    if (!ws->active) {
        // 当前没有活跃的唤醒事件，直接调用
        __pm_wakeup_event(ws, msec);
        return;
    }

    // 获取当前时间和唤醒事件到期时间
    now = ktime_get();
    expires = ws->timer_expires;

    if (ktime_compare(expires, now) <= 0) {
        // 已经过期（理论上 active 应该为 false，但为了安全考虑）
        __pm_wakeup_event(ws, msec);
        return;
    }

    // 计算剩余时间（毫秒）
    remaining_ms = ktime_to_ms(ktime_sub(expires, now));

    if (remaining_ms <= 300) {
        // 剩余时间 <= 300ms，续期唤醒事件
        __pm_wakeup_event(ws, msec);
    }
}

static int dmi_msg_recv_notify(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    u32 chn = (u32)(uintptr_t)arg;
    struct dmi_msg_ctx_task *ctx = NULL;

    if (chn >= DMI_SERVICE_TYPE_COMM || g_dmi_recv_task[chn].stat == DMI_RST) {
        return -1;
    }
    ctx = &g_dmi_recv_task[chn];

    // 关闭全部中断
    bsp_dpa_fipc_channel_all_int_dis(event_info->data_event.chn_hdl);

    set_bit(chn, (void *)&ctx->event);
    wake_up(&ctx->wqueue);
    return 0;
}

void dmi_msg_recv_resume(void)
{
    unsigned int i;
    int ret;
    dpa_fipc_eventinfo event_info;
    for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
        event_info.data_event.chn_hdl = g_dmi_msg_recv_ctx.dmi_msg_hdl[i];
        ret = dmi_msg_recv_notify(DPA_FIPC_EVENT_RECV_TIMEOUT, (void *)(uintptr_t)i, &event_info);
        if (ret) {
            dpa_pr_err("dmi_msg_recv_resume[%d] failed %d\n", i, ret);
        }
    }
}

static inline void dmi_msg_enable_pkt_intr(struct dmi_msg_ctx_task *ctx, dpa_fipc_chn_t chn_hdl)
{
    if (ctx->is_intr_dis) {
        bsp_dpa_fipc_channel_int_en(chn_hdl);
        bsp_dpa_fipc_channel_timeout_int_dis(chn_hdl);
        ctx->is_intr_dis = 0;
        ctx->intr_en_cnt++;
    }
}

static inline void dmi_msg_disable_pkt_intr(struct dmi_msg_ctx_task *ctx, dpa_fipc_chn_t chn_hdl)
{
    if (!ctx->is_intr_dis) {
        bsp_dpa_fipc_channel_timeout_int_en(chn_hdl);
        bsp_dpa_fipc_channel_int_dis(chn_hdl);
        ctx->is_intr_dis = 1;
        ctx->intr_dis_cnt++;
    }
}

static void dmi_msg_intr_merge(struct dmi_msg_ctx_task *ctx, dpa_fipc_chn_t chn_hdl, int msg_len)
{
    if (ctx->intr_dis_thresh == 0 || msg_len == 0) {
        return;
    }
    if (msg_len > ctx->intr_dis_thresh) {
        dmi_msg_disable_pkt_intr(ctx, chn_hdl);
    } else {
        dmi_msg_enable_pkt_intr(ctx, chn_hdl);
    }
}

int dmi_msg_recv_proc(void *arg)
{
    int ret;
    int msg_tot_len;
    struct dmi_msg_ctx_task *ctx = (struct dmi_msg_ctx_task *)arg;

    while (1) {
        msg_tot_len = 0;
        ret = wait_event_interruptible(ctx->wqueue, test_and_clear_bit(ctx->chn, (void *)&ctx->event)
            || test_bit(DMI_EVENT_THREAD_STOPING_BIT(ctx->chn), (void *)&ctx->event));
        if (unlikely(ret < 0)) {
            dpa_pr_err("%d task was interrupted by a signal. event:%d %d\n", ctx->chn, ctx->event, ret);
            continue;
        }
        if (unlikely((ctx->event & BIT(DMI_EVENT_THREAD_STOPING_BIT(ctx->chn))) || (ctx->event & BIT(DMI_EVENT_THREAD_STOPED_BIT(ctx->chn))))) {
            bsp_dpa_fipc_channel_all_int_dis(g_dmi_msg_recv_ctx.dmi_msg_hdl[ctx->chn]);
            clear_bit(ctx->chn, (void *)&ctx->event);
            clear_bit(DMI_EVENT_THREAD_STOPING_BIT(ctx->chn), (void *)&ctx->event);
            set_bit(DMI_EVENT_THREAD_STOPED_BIT(ctx->chn), (void *)&ctx->event);
            wake_up(&ctx->wqueue);
            dpa_pr_err("task stop:%d event:%d\n", ctx->chn, ctx->event);
            continue;
        }
        dmi_msg_pm_wakeup_timeout(ctx->wakelock, 600);

        do {
            ret = dmi_msg_recv_cbk(ctx->chn);
            if (ret > 0) {
                msg_tot_len += ret;
            }
        } while (ret > 0);
        dmi_msg_intr_merge(ctx, g_dmi_msg_recv_ctx.dmi_msg_hdl[ctx->chn], msg_tot_len);
        bsp_dpa_fipc_channel_all_int_en(g_dmi_msg_recv_ctx.dmi_msg_hdl[ctx->chn]);
    }

    return 0;
}

void dmi_msg_recv_stop(unsigned int chn)
{
    struct dmi_msg_ctx_task *ctx = &g_dmi_recv_task[chn];
    ctx->stat = DMI_RST;
    bsp_dpa_fipc_channel_all_int_dis(g_dmi_msg_recv_ctx.dmi_msg_hdl[chn]);
    set_bit(DMI_EVENT_THREAD_STOPING_BIT(ctx->chn), (void *)&ctx->event);
    wake_up(&ctx->wqueue);
    dpa_pr_err("stop:%d event:%d\n", ctx->chn, ctx->event);
    wait_event(ctx->wqueue, test_bit(DMI_EVENT_THREAD_STOPED_BIT(ctx->chn), (void *)&ctx->event));
}

void dmi_msg_recv_restart(unsigned int chn)
{
    g_dmi_recv_task[chn].event = 0;
    g_dmi_recv_task[chn].stat = 0;
    bsp_dpa_fipc_channel_all_int_en(g_dmi_msg_recv_ctx.dmi_msg_hdl[chn]);
}

int dmi_msg_task_init(struct dmi_msg_ctx_task *ctx)
{
    struct sched_param param = {
        .sched_priority = 0x60
    };
    int ret;

    ctx->worker = kthread_run(dmi_msg_recv_proc, ctx, "dmi_msg_recv%d", ctx->chn);
    if (IS_ERR(ctx->worker)) {
        return -2;
    }
    ret = sched_setscheduler(ctx->worker, SCHED_FIFO, &param);
    if (ret) {
        return ret;
    }
    return 0;
}

int dmi_msg_recv_init(unsigned int chn)
{
    int ret;
    struct dmi_msg_ctx_task *ctx = &g_dmi_recv_task[chn];

    ctx->chn = chn;
    init_waitqueue_head(&ctx->wqueue);
    ctx->wakelock = wakeup_source_register(NULL, "dmi_msg_recv_wl");
    if (ctx->wakelock == NULL) {
        dpa_pr_err("wakelock reg fail\n");
        return -1;
    }
    
    ret = dmi_msg_task_init(ctx);
    if (ret) {
        dpa_pr_err("dmi_msg_task_init failed: %d\n", ret);
        return ret;
    }

    g_dmi_msg[chn] = (struct dmi_msg *)kmalloc(DMI_BUF_SIZE, GFP_KERNEL);
    if (g_dmi_msg[chn] == NULL) {
        dpa_pr_err("dmi recv buf[%d] alloc failed\n", chn);
        return -1;
    }
    ctx->is_intr_dis = 0;
    ctx->intr_dis_thresh = g_dmi_merge_cfg[chn].msglen_thresh;

    return 0;
}

int dmi_msg_recv_ch_init(int chn, int chnid, void *cbk)
{
    int ret;
    dpa_fipc_chn_attr_t attr;
    ret = dmi_msg_recv_init(chn);
    if (ret) {
        return ret;
    }
    ret = bsp_dpa_fipc_chn_attr_init(&attr);
    if (ret) {
        return ret;
    }

    attr.chnid = chnid;
    attr.cbk = dmi_msg_recv_notify;
    attr.cbk_arg = (void *)(uintptr_t)chn;
    attr.type = DPA_FIPC_CHNL_RECV;
    attr.size = DPA_MSG_FIPC_DEPTH;
    attr.va = dmi_client_dma_buf_alloc(attr.size, (dma_addr_t *)&attr.ga);
    attr.overflow_th = g_dmi_merge_cfg[chn].overflow_th;
    attr.timeout_val = g_dmi_merge_cfg[chn].intr_timeout;
    if (attr.va == NULL) {
        dpa_pr_err("dmi_msg_recv_ch_init dma malloc failed\n");
        return -1;
    }
    g_dmi_msg_recv_ctx.cbk[chn] = (dmi_msg_cbk)cbk;

    ret = bsp_dpa_fipc_chn_open(&g_dmi_msg_recv_ctx.dmi_msg_hdl[chn], &attr);
    return ret;
}

void dmi_recv_debug_set_thresh(u32 chn, u32 val)
{
    struct dmi_msg_ctx_task *ctx;

    if (chn >= DMI_SERVICE_TYPE_COMM) {
        return;
    }
    ctx = &g_dmi_recv_task[chn];
    ctx->intr_dis_thresh = val;
    return;
}

void dmi_recv_debug_show(void)
{
    int chn;
    struct dmi_msg_ctx_task *ctx = NULL;

    for (chn = DMI_SERVICE_TYPE_CTRL; chn < DMI_SERVICE_TYPE_COMM; chn++) {
        ctx = &g_dmi_recv_task[chn];
        dpa_pr_fatal("dmi_msg_ctx_task[%d]:\n", chn);
        dpa_pr_fatal(" is_intr_dis: %d\n", ctx->is_intr_dis);
        dpa_pr_fatal(" intr_dis_thresh: %d (bytes)\n", ctx->intr_dis_thresh);
        dpa_pr_fatal(" intr_dis_cnt: %d\n", ctx->intr_dis_cnt);
        dpa_pr_fatal(" intr_en_cnt: %d\n", ctx->intr_en_cnt);
        dpa_pr_fatal(" intr_timeout: %d (%s)\n", (g_dmi_merge_cfg[chn].intr_timeout & 0x1F),
            (g_dmi_merge_cfg[chn].intr_timeout & 0x20) ? ("ms"):("us"));
        dpa_pr_fatal(" overflow_th: 0x%x\n", g_dmi_merge_cfg[chn].overflow_th);
    }
}
