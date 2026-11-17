/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */

#include <linux/module.h>
#include "log/stack_log.h"
#include "socket/sbr_socket.h"
#include "socket/dpa_inet_socket.h"
#include "runtime.h"
#include "sys_msg.h"
#include "msg/bridge_msg_producer.h"
#include "msg/bridge_msg_consumer.h"
#include "socket/sbr_prot_com.h"
#include "cooperation/cooperation.h"
#include "dfx/dfx_display.h"

MODULE_LICENSE("GPL");
MODULE_ALIAS("BRIDGE");

#ifndef _DEBUG
u32 g_bridge_log_level = (u32)NSLOG_INF;
#else
u32 g_bridge_log_level = (u32)NSLOG_DBG;
#endif

static s32 msg_resource_init(void)
{
    s32 ret = bridge_msg_pool_init();
    if (ret != 0) {
        return ret;
    }

    ret = init_runtime();
    if (ret != 0) {
        return ret;
    }
    return 0;
}

void stack_set_level(unsigned int level)
{
    g_bridge_log_level = level;
}

s32 bridge_module_init(void)
{
    s32 ret = sbr_init();
    if (ret != 0) {
        NS_ERR("sbr_init failed");
        return -1;
    }

    ret = msg_resource_init();
    if (ret != 0) {
        NS_ERR("msg_resource_init failed");
        return -1;
    }

    global_tx_num_init();
    global_dra_alloc_num_init();
    ret = sbr_msg_queue_init();
    if (ret != 0) {
        NS_ERR("sbr_msg_queue_init failed");
        return -1;
    }
    init_cooperation();

    socket_take_over_init();

    if (bridge_dfx_info_init() != 0) {
        NS_ERR("init bridge dfx info file failed");
    }
    NS_INF("bridge inited");
    return 0;
}
#ifndef DPA_MODE
module_init(bridge_module_init);
#endif
