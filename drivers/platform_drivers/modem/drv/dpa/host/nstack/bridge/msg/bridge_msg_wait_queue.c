/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#include <linux/workqueue.h>
#include "stack_types.h"
#include "dmm_spinlock.h"
#include "stack_log.h"
#include "dynamic_queue.h"
#include "socket/sbr_socket.h"
#include "dfx/global_res_stats.h"
#include "bridge_msg_api.h"
#include "bridge_msg_producer.h"

#define MSG_QUEUE_SIZE_INIT 4096

typedef struct {
    struct list_head sk_wq;
    dmm_spinlock_t lock;
    dmm_spinlock_t sk_wq_lock;
    struct work_struct work;
    dynamic_fifo_queue *msg_wq;
} msg_queue;

static msg_queue g_msg_wait_queue;

void sbr_msg_queue_lock(void)
{
    dmm_spin_lock(&g_msg_wait_queue.lock);
}

void sbr_msg_queue_unlock(void)
{
    dmm_spin_unlock(&g_msg_wait_queue.lock);
}

bool sbr_msg_queue_empty(void)
{
    return is_dynamic_fifo_queue_empty(g_msg_wait_queue.msg_wq);
}

bool sbr_msg_queue_empty_lock(void)
{
    bool is_empty;
    dmm_spin_lock(&g_msg_wait_queue.lock);
    is_empty = sbr_msg_queue_empty();
    dmm_spin_unlock(&g_msg_wait_queue.lock);
    return is_empty;
}

s32 sbr_msg_enqueue_tail(void *msg, void *mhandle)
{
    bool ret = false;
    data_com_msg *cur_msg = (data_com_msg *)msg;
    cur_msg->param.mhandle = (u64)mhandle;
    ret = dynamic_fifo_enqueue(g_msg_wait_queue.msg_wq, msg);
    if (ret == false) {
        return -1;
    }
    if (cur_msg->param.is_dmi_msg) {
        dmi_msg_post_enqueue_inc();
    } else {
        sysmem_msg_post_enqueue_inc();
    }
    return 0;
}

static void sbr_msg_dequeue_handle_lock(void)
{
    data_com_msg *cur_msg = NULL;
    data_com_msg *dmi_msg = NULL;
    void *mhandle = NULL;
    s32 ret;
    bool is_dmi_msg;
    dmm_spin_lock(&g_msg_wait_queue.lock);
    dmi_low_event_cnt_inc();
    while ((cur_msg = (data_com_msg *)dynamic_fifo_queue_first(g_msg_wait_queue.msg_wq)) != NULL) {
        is_dmi_msg = cur_msg->param.is_dmi_msg;
        if (!is_dmi_msg) {
            dmi_msg = (data_com_msg *)dmi_msg_malloc();
            if (dmi_msg == NULL) {
                NS_ERR("dmi_msg alloc failed when chn low");
                break;
            }
            void *dest = &(dmi_msg->param);
            void *src = &(cur_msg->param);
            size_t len = sizeof(data_com_msg) - DATA_MSG_PRE;
            (void)memcpy_s(dest, len, src, cur_msg->param.buffer_len);
        } else {
            dmi_msg = cur_msg;
        }
        mhandle = (void *)cur_msg->param.mhandle;
        ret = sys_msg_try_post(dmi_msg, mhandle);
        if (ret != 0) {
            if (!is_dmi_msg) {
                msg_free(dmi_msg, true);
            }
            NS_DBG("dmi_low_post_failed=%d", ret);
            break;
        }
        (void)dynamic_fifo_dequeue(g_msg_wait_queue.msg_wq);
        if (!is_dmi_msg) {
            stack_free(cur_msg);
        }
        if (is_dmi_msg) {
            dmi_msg_post_dequeue_inc();
        } else {
            sysmem_msg_post_dequeue_inc();
        }
    }
    dmm_spin_unlock(&g_msg_wait_queue.lock);
}

void sbr_sk_add_msg_wq(sbr_socket_t *sk)
{
    dmm_spin_lock(&g_msg_wait_queue.sk_wq_lock);
    if (sk->in_msg_wq) {
        dmm_spin_unlock(&g_msg_wait_queue.sk_wq_lock);
        return;
    }
    list_add_tail(&sk->sk_msg_wq_node, &g_msg_wait_queue.sk_wq);
    sk->in_msg_wq = true;
    sock_hold(sk->sk);
    sk_msg_queue_add_inc();
    dmm_spin_unlock(&g_msg_wait_queue.sk_wq_lock);
}

void sbr_sk_remove_msg_wq(sbr_socket_t *ssk)
{
    dmm_spin_lock(&g_msg_wait_queue.sk_wq_lock);
    if (!ssk->in_msg_wq) {
        dmm_spin_unlock(&g_msg_wait_queue.sk_wq_lock);
        return;
    }
    list_del(&ssk->sk_msg_wq_node);
    ssk->in_msg_wq = false;
    sk_msg_queue_remove_inc();
    dmm_spin_unlock(&g_msg_wait_queue.sk_wq_lock);
    sock_put(ssk->sk);
}

static sbr_socket_t *sbr_pop_sk_msg_wq(void)
{
    sbr_socket_t *ssk = NULL;
    dmm_spin_lock(&g_msg_wait_queue.sk_wq_lock);
    ssk = list_first_entry_or_null(&g_msg_wait_queue.sk_wq, sbr_socket_t, sk_msg_wq_node);
    if (ssk != NULL) {
        list_del(&ssk->sk_msg_wq_node);
        ssk->in_msg_wq = false;
        sk_msg_queue_remove_inc();
    }
    dmm_spin_unlock(&g_msg_wait_queue.sk_wq_lock);
    return ssk;
}

s32 sbr_tcp_msg_wq_handle(sbr_socket_t *ssk)
{
    s32 ret = 0;
    struct sock *sk = ssk->sk;
    lock_sock(sk);
    ret = sbr_handle_tcp_recved(ssk, ssk->recvd_total_count);
    if (ret == 0) {
        ssk->recvd_total_count = 0;
    } else {
        goto END;
    }
    ret = sbr_handle_tcp_send(ssk, true);
END:
    release_sock(sk);
    sock_put(sk);
    return ret;
}

s32 sbr_udp_msg_wq_handle(sbr_socket_t *ssk)
{
    struct sock *sk = ssk->sk;
    lock_sock(sk);
    if (sk->sk_socket && test_bit(SOCK_NOSPACE, &sk->sk_socket->flags)) {
        sk->sk_write_space(sk);
    }
    release_sock(sk);
    sock_put(sk);
    return 0;
}

static void sbr_send_msg_handle(struct work_struct *arg)
{
    (void)arg;
    sbr_socket_t *ssk = NULL;
    sbr_msg_dequeue_handle_lock();
    while ((ssk = sbr_pop_sk_msg_wq()) != NULL) {
        if (ssk->sk_msg_recovery_handle == NULL) {
            continue;
        }
        if (ssk->sk_msg_recovery_handle(ssk) < 0) {
            break;
        }
    }
}

void sbr_send_msg_low_handle(void)
{
    schedule_work(&g_msg_wait_queue.work);
}

u32 get_msg_queue_capacity(void)
{
    return (u32)dynamic_fifo_queue_capacity_size(g_msg_wait_queue.msg_wq);
}

s32 sbr_msg_queue_init(void)
{
    g_msg_wait_queue.msg_wq = create_dynamic_fifo_queue(MSG_QUEUE_SIZE_INIT);
    if (g_msg_wait_queue.msg_wq == NULL) {
        NS_ERR("msg_wq init failed");
        return -1;
    }
    INIT_LIST_HEAD(&g_msg_wait_queue.sk_wq);
    dmm_spin_init(&g_msg_wait_queue.lock);
    dmm_spin_init(&g_msg_wait_queue.sk_wq_lock);
    INIT_WORK(&g_msg_wait_queue.work, sbr_send_msg_handle);
    return 0;
}

void sbr_msg_queue_clear(void)
{
    data_com_msg *cur_msg = NULL;
    dmm_spin_lock(&g_msg_wait_queue.lock);
    while ((cur_msg = (data_com_msg *)dynamic_fifo_dequeue(g_msg_wait_queue.msg_wq)) != NULL) {
        sbr_msg_free(cur_msg, true);
    }
    dmm_spin_unlock(&g_msg_wait_queue.lock);
}

#define MSG_WAIT_TIME_OUT_PERIOD 10000000U // 10 ms
#define MSG_LOCK_AGAIN_PERIOID 100000 // 100us
#define CORK_SEND_TIME_OUT_PERIOD 20000000U // 20 ms
#define MSG_RETRY_COUNT 10

typedef s32 (*msg_handle_function)(void *retry_handle);
typedef enum hrtimer_restart (*sbr_msg_retry_timeout_handle)(struct hrtimer *hr);

static enum hrtimer_restart sbr_msg_timeout_handle(sbr_msg_retry_common *common,
    msg_handle_function function, void *retry)
{
    struct sock *lsk = common->sbr_sk->sk;
    u64 timer_period = MSG_WAIT_TIME_OUT_PERIOD;
    bh_lock_sock(lsk);
    if (sock_owned_by_user(lsk)) {
        timer_period = MSG_LOCK_AGAIN_PERIOID;
        NS_DBG("bridge send msg timer restart for user lock");
        goto TIMER_RESTART;
    }
    if (common->is_timer_start == false) {
        if (common->is_sk_hold == true) {
            common->is_sk_hold = false;
            bh_unlock_sock(lsk);
            NS_DBG("sk_id=%lu, fd=%d, bridge send msg put sk in handle", common->sbr_sk->sk_id, common->sbr_sk->fd);
            sock_put(common->sbr_sk->sk);  // timer need to be cancelled
        } else {
            bh_unlock_sock(lsk);
        }
        NS_DBG("sk_id=%lu, fd=%d, bridge send msg retry deinit success in handle",
            common->sbr_sk->sk_id, common->sbr_sk->fd);
        return HRTIMER_NORESTART;
    }
    s32 ret = function(retry);
    if (ret == -SPL_EBUSY && common->retry_count <= MSG_RETRY_COUNT) {
        ++common->retry_count;
        NS_DBG("sk_id=%lu, fd=%d, bridge send msg timer restart for failed %u",
            common->sbr_sk->sk_id, common->sbr_sk->fd, common->retry_count);
        goto TIMER_RESTART;
    }
    if (ret >= 0) {
        common->retry_count = 0;
        NS_DBG("sk_id=%lu, fd=%d, bridge send msg retry success fd=%d", common->sbr_sk->sk_id, common->sbr_sk->fd);
    } else {
        NS_ERR("sk_id=%lu, fd=%d, bridge msg retry count MAX fd=%d", common->sbr_sk->sk_id, common->sbr_sk->fd);
    }
    common->is_timer_start = false;
    bh_unlock_sock(lsk);
    return HRTIMER_NORESTART;
TIMER_RESTART:
    bh_unlock_sock(lsk);
    u64 interval = (u64)ktime_set(0, timer_period);
    hrtimer_forward_now(&common->sbr_msg_retry_timer, (ktime_t)interval);
    return HRTIMER_RESTART;
}

static void sbr_msg_retry_common_init(sbr_msg_retry_common *common,
    sbr_socket_t *sk, sbr_msg_retry_timeout_handle timeout_handle)
{
    common->sbr_sk = sk;
    common->is_timer_start = false;
    common->is_sk_hold = false;
    common->retry_count = 0;
    hrtimer_init(&common->sbr_msg_retry_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL_SOFT);
    common->sbr_msg_retry_timer.function = timeout_handle;
}

void sbr_msg_retry_deinit(sbr_msg_retry_common *retry)
{
    s32 ret = 0;
    if (retry->is_timer_start == true) {
        ret = hrtimer_try_to_cancel(&retry->sbr_msg_retry_timer);
        retry->is_timer_start = false;
        NS_DBG("bridge send msg retry cancel timer ret %d", ret);
    }
    if (ret >= 0 && retry->is_sk_hold == true) {
        retry->is_sk_hold = false;
        sock_put(retry->sbr_sk->sk);
        NS_DBG("bridge msg put sk success");
    }
    NS_DBG("bridge msg retry deinit success");
}

static s32 sbr_cork_send_timeout_function(void *timer)
{
    sbr_cork_send_timer *send_timer = (sbr_cork_send_timer *)timer;
    sbr_msg_retry_common *common = &send_timer->common;
    return send_timer->cork_send_handle(common->sbr_sk, true);
}

static enum hrtimer_restart sbr_cork_send_timeout_handle(struct hrtimer *hr)
{
    sbr_msg_retry_common *common = (sbr_msg_retry_common *)hr;
    sbr_cork_send_timer *timer = (sbr_cork_send_timer *)common;
    return sbr_msg_timeout_handle(common, sbr_cork_send_timeout_function, (void *)timer);
}

static void sbr_cork_send_timer_common_start(sbr_msg_retry_common *common)
{
    common->is_timer_start = true;
    if (common->is_sk_hold == false) {
        sock_hold(common->sbr_sk->sk);
        common->is_sk_hold = true;
        NS_DBG("bridge msg start hold sk");
    }
    u64 interval = (u64)ktime_set(0, CORK_SEND_TIME_OUT_PERIOD);
    hrtimer_start(&common->sbr_msg_retry_timer, (ktime_t)interval, HRTIMER_MODE_REL_SOFT);
}

static void sbr_cork_send_timer_init(sbr_socket_t *sk,
    cork_send_timer_handle cork_send_handle, sbr_msg_retry_timeout_handle timeout_handle)
{
    sbr_cork_send_timer *timer = &sk->cork_send_timer;
    timer->cork_send_handle = cork_send_handle;
    sbr_msg_retry_common_init(&timer->common, sk, timeout_handle);
    NS_INF("sk_id=%lu, fd=%d, bridge cork send timer init", sk->sk_id, sk->fd);
}

static void sbr_cork_send_timer_start_inner(sbr_socket_t *sk, cork_send_timer_handle cork_send_handle)
{
    sbr_msg_retry_common *common = &sk->cork_send_timer.common;
    if (common->is_init == false) {
        sbr_cork_send_timer_init(sk, cork_send_handle, sbr_cork_send_timeout_handle);
        common->is_init = true;
        NS_DBG("bridge cork send timer start fd=%d", sk->fd);
    }
    sbr_cork_send_timer_common_start(common);
}

void sbr_cork_send_timer_start(sbr_socket_t *sk, cork_send_timer_handle cork_send_handle, bool need_send)
{
    if (sk->cork_send_timer.common.is_timer_start) {
        if (need_send) {
            hrtimer_try_to_cancel(&sk->cork_send_timer.common.sbr_msg_retry_timer);
            u64 interval = (u64)ktime_set(0, CORK_SEND_TIME_OUT_PERIOD);
            hrtimer_start(&sk->cork_send_timer.common.sbr_msg_retry_timer, (ktime_t)interval, HRTIMER_MODE_REL_SOFT);
        }
    } else {
        sbr_cork_send_timer_start_inner(sk, cork_send_handle);
    }
}