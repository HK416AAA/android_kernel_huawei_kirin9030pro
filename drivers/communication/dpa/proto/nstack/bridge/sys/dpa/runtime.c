/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include <dpa_reset.h>
#include "bsp_dpa_white_list.h"
#include "ring.h"
#include "common_msg.h"
#include "msg/bridge_msg_consumer.h"
#include "sys_msg.h"
#include "socket/sbr_prot_com.h"
#include "bsp_dpa_net_om.h"
#include <bsp_dpa.h>
#include "runtime.h"
#include "dfx/conn_stats.h"
#include "dfx/global_res_stats.h"
#include "bsp_diag.h"
#include "cooperation/cooperation.h"

static mring_handle g_bridge_msg_box;
struct net_om_info g_bridge_report_info = {0};
struct net_om_info g_bridge_report_global_info = {0};

static s32 sys_msg_cb(void *msg)
{
    return call_acpu_msg_fun((data_com_msg *)msg, true);
}

static s32 sys_err_msg_cb(void *msg)
{
    return call_acpu_msg_fun((data_com_msg *)msg, false);
}

void dpa_event_report(sbr_socket_t *ssk, enum action_code code)
{
    host_dpa_stat_info_t info = {0};
    info.sk_id = ssk->sk_id;
    info.action = (u32)code;
    info.err_code = ssk->d2a_event;

    if (code == SOCKET_D2A) {
        (void)memcpy_s(&info.conn_info.del_tuple.stats, SBR_CONN_STATS_MAX_TYPE * sizeof(stat_unit),
            ssk->stats, SBR_CONN_STATS_MAX_TYPE * sizeof(stat_unit));
    }

    u32 msg_id = code == SOCKET_A2D ?
        DPA_HOST_NET_OM_DPA_ADD_TUPLE : DPA_HOST_NET_OM_DPA_DEL_TUPLE;
    (void)bsp_dpa_diag_trans_report(msg_id, DIAG_DPA_HOST_PID,
        (unsigned char *)&info, sizeof(host_dpa_stat_info_t));
}

static s32 bridge_msg_box_init(void)
{
    mring_handle box = sys_msg_box_create(BRIDGE_BOX_SIZE);
    if (box == NULL) {
        NS_ERR("create bridge table failed");
        return -SPL_ENOMEM;
    }
    g_bridge_msg_box = box;
    if (sys_msg_listen(g_bridge_msg_box, sys_msg_cb, sys_err_msg_cb) != 0) {
        NS_ERR("acpu bridge msg cb register failed");
        return -SPL_EPERM;
    }
    sys_msg_register_event_cb(sbr_send_msg_low_handle);
    return 0;
}

mring_handle get_instance_msg_box(u16 thread_index)
{
    (void)thread_index;
    return (void *)(u64)DMI_SERVICE_TYPE_DATA; // data msg
}

mring_handle get_instance_control_box(u16 thread_index)
{
    (void)thread_index;
    return (void *)(u64)DMI_SERVICE_TYPE_CTRL; // control msg
}

/* sk lock aleady hold */
void dpa_socket_pre_take(struct socket *sock)
{
    struct sock *sk = sock->sk;

    if (net_eq(sock_net(sk), &init_net) == 0) {
        return;
    }
    if ((sk->sk_family != AF_INET && sk->sk_family != AF_INET6) ||
        (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_UDP)) {
        return;
    }

    if (sbr_dpa_reseting()) {
        return;
    }

    inet_sk(sk)->dpa_opt = bsp_dpa_white_list_match(sk);
    if (inet_sk(sk)->dpa_opt == 0) {
        return;
    }

    if (get_dpa_stack_bypass_status()) {
        inet_sk(sk)->dpa_opt = 0;
        conn_bypass_inc();
        return;
    }

    if (inet_sk(sk)->dpa_opt == 1) {
        inet_sk(sk)->dpa_enable = 1;
    }
}

static int sbr_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    (void)arg;
    if (enparam == DPA_RESET_BEFORE) {
        NS_ERR("dpa rst before");
        sbr_dpa_rst_state_set(1);
        sbr_dpa_socket_reset();
        sbr_msg_queue_clear();
    } else if (enparam == DPA_RESET_AFTER) {
        NS_ERR("dpa rst after");
        msg_queue_dfx_deinit();
        global_dra_alloc_num_init();
        global_tx_num_init();
        global_rx_dra_num_init();
        sbr_dpa_rst_state_set(0);
    }
    return 0;
}

static int sbr_dpa_rst_init(void)
{
    int ret;
    ret = bsp_dpa_reset_register_cb("stack", sbr_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_STACK);
    if (ret) {
        NS_ERR("reg dpa rst fail:%d", ret);
    }
    return ret;
}

void bridge_om_report_init(void *data, unsigned int data_size)
{
    struct net_om_info *info = &g_bridge_report_info;
    int ret;

    info->ul_msg_id = (int)DPA_HOST_NET_OM_DFX_CONN_STATS_INFO;
    info->func_cb = bridge_om_cb;
    info->data = data;
    info->size = data_size;
    INIT_LIST_HEAD(&info->list);

    ret = bsp_dpa_net_report_register(info);
    if (ret != 0) {
        NS_ERR("dfx_conn_stats_info report register fail\n");
    }
}

void bridge_global_om_cb(void)
{
    sbr_dfx_sock_info *info = get_dfx_sock_info();
    info->msg_queue_capacity = get_msg_queue_capacity();
    info->rx_dra_alloc_num = get_global_rx_dra_alloc_num();
    return;
}

void bridge_global_om_report_init(void *data, unsigned int data_size)
{
    struct net_om_info *info = &g_bridge_report_global_info;
    int ret;
    info->ul_msg_id = (int)DPA_HOST_NET_OM_DFX_SOCK_INFO;
    info->func_cb = bridge_global_om_cb;
    info->data = data;
    info->size = data_size;
    INIT_LIST_HEAD(&info->list);

    ret = bsp_dpa_net_report_register(info);
    if (ret != 0) {
        NS_ERR("dfx_sock_info report register fail\n");
    }
}

static u8 g_migrate_num_one_turn = 0;
#define MAX_CPU_OVERLOAD_TIMES 4
static void sbr_dpa_cpu_overload_cb(void)
{
    sbr_dpa_cpu_overload_times_inc();
    if (sbr_dpa_cpu_overload_times_get() == 1) {
        g_migrate_num_one_turn = dmm_atomic_read(&(get_dfx_sock_info()->cur_tot_sock)) / MAX_CPU_OVERLOAD_TIMES;
    }
    u16 fd = 1;
    u8 i = 0;
    sbr_socket_t *ssk = NULL;
    for (; fd < SOCKET_NUM + 1; fd++) {
        ssk = get_dpa_sk(fd);
        if (ssk != NULL) {
            struct sock *sk = ssk->sk;
            lock_sock(sk);
            if (ssk->status == SK_MIGRATE_OK) {
                sbr_msg_retry_deinit(&ssk->cork_send_timer.common);
                sbr_sk_remove_msg_wq(ssk);
                NS_INF("migrate_d2a start sk_id=%lu, fd=%d d2a_event=%d", ssk->sk_id, ssk->fd, D2A_EVT_CPU_OVERLOAD);
                ssk->d2a_event = D2A_EVT_CPU_OVERLOAD;
                (void)ssk->fdopt->migrate_d2a(ssk);
            }
            release_sock(sk);
            put_dpa_sk(ssk);
            i++;
        }
        if (sbr_dpa_cpu_overload_times_get() < MAX_CPU_OVERLOAD_TIMES && i == g_migrate_num_one_turn) {
            break;
        }
    }
}

static void sbr_dpa_cpu_load_recover_cb(void)
{
    sbr_dpa_cpu_overload_times_reset();
    g_migrate_num_one_turn = 0;
}

struct clk_notify g_sbr_notify = {
    .dpa_clk_max_notify = sbr_dpa_cpu_overload_cb,
    .dpa_clk_descent_notify = sbr_dpa_cpu_load_recover_cb,
};

static int sbr_dpa_register_cpu_overload_cb(void)
{
    int ret = 0;
    ret = bsp_clk_reg_notify(&g_sbr_notify);
    if (ret) {
        NS_ERR("reg dpa load fail:%d", ret);
    }
    return ret;
}

s32 init_runtime(void)
{
    s32 ret;
    ret = bridge_msg_box_init();
    if (ret < 0) {
        return ret;
    }
    ret = sbr_dpa_rst_init();
    if (ret < 0) {
        return ret;
    }
    ret = sbr_dpa_register_cpu_overload_cb();
    if (ret < 0) {
        return ret;
    }
    bridge_om_report_init((void *)get_dfx_conn_stats_info(), get_dfx_conn_stats_size());
    bridge_global_om_report_init((void *)get_dfx_sock_info(), get_dfx_sock_info_size());
    return 0;
}
