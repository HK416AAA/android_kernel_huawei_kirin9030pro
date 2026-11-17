/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:plat_ipc.c
 * Author: platform drivers
 */

#ifdef _PRE_PLAT_FEATURE_IPC
#include "plat_ipc.h"
#include <linux/types.h>
#include "bfgx_dev.h"
#include "oal_util.h"
#include "ipc_interface.h"
#include "plat_exception_rst.h"
#include "plat_debug.h"
#include "plat_pm_mcu.h"

oal_completion g_mcu_uart_loop_done;
uint8_t g_mcu_uart_loop_result;
oal_completion g_mcu_init_done;
uint8_t g_mcu_init_result;

#define IPC_BUFFER_MAX       128
#define IPC_WAKELOCK_TIMEOUT 100
#define WAIT_RESUME_TIMEOUT (15 * HZ)

typedef struct hw_plat_ipc_ctx {
    uint8_t msg_buffer[IPC_BUFFER_MAX];
    oal_workqueue_stru *wq_ipc;
    oal_work_stru op_work;
    oal_mutex_stru ipc_mutex;
} hw_plat_ipc_ctx_t;

static hw_plat_ipc_ctx_t g_hw_ipc_ctx;
static oal_wakelock_stru g_ipc_wake_lock;

static void plat_mcu_dfr_notify_proc(uint8_t *msg_buffer, uint16_t len)
{
#ifdef PLATFORM_DEBUG_ENABLE
    dfr_notify_cmd_t *dfr_cmd = (dfr_notify_cmd_t *)msg_buffer;
    if (dfr_cmd->dfx_len > 0) {
        oal_print_hex_dump(dfr_cmd->dfx_info, dfr_cmd->dfx_len, HEX_DUMP_GROUP_SIZE, "sensorhub exception: ");
    }
#endif
    if (is_hi110x_debug_type() != OAL_TRUE) {
        ps_print_info("user mode or maybe beta user,ssi dump bypass\n");
    } else {
        (void)ssi_dump_err_regs(SSI_ERR_BFG_WAKE_UP_FAIL);
    }
    plat_exception_handler(SUBSYS_BFGX, THREAD_IDLE, SENSORHUB_EXCEP);
    ps_print_info("call mcu_notify_bt_dfr\n");
    return;
}

static void plat_ipc_mcu2ap_msg_handle(uint8_t *msg_buffer, uint16_t len)
{
    plat_ipc_hdr_t* ipc_hdr = (plat_ipc_hdr_t*)msg_buffer;

    ps_print_warning("plat_ipc_mcu2ap_msg_handle, op_code = %d\n", ipc_hdr->msg_code);
    switch (ipc_hdr->msg_code) {
        case BFGN_OP_CODE_DRF_NOTIFY: {
            plat_mcu_dfr_notify_proc(msg_buffer, len);
            break;
        }
        case BFGN_OP_CODE_UART_LOOP_DONE: {
            uart_loop_cmd_t* loop_cmd;
            if (len < sizeof(uart_loop_cmd_t)) {
                ps_print_err("Invalid message length\n");
                return;
            }
            loop_cmd = (uart_loop_cmd_t*)msg_buffer;
            ps_print_info("mcu uart loop done ret 0x%x\n", loop_cmd->result);
            g_mcu_uart_loop_result = loop_cmd->result;
            complete(&g_mcu_uart_loop_done);
            break;
        }
        case BFGN_OP_CODE_PM_STATUS_NOTIFY: {
            pm_status_notify_msg_process(msg_buffer, len);
            break;
        }
        case BFGN_OP_CODE_BT_INIT_STATUS_ACK: {
            mcu_init_status_cmd_t *init_status;
            if (len < sizeof(mcu_init_status_cmd_t)) {
                ps_print_err("Invalid message length\n");
                return;
            }
            init_status = (mcu_init_status_cmd_t *)msg_buffer;
            ps_print_info("mcu init status 0x%x\n", init_status->status);
            g_mcu_init_result = init_status->status;
            complete(&g_mcu_init_done);
            break;
        }
        default:
            return;
    }
}

static int32_t cmd_connect_msg_handle(const uint8_t *data, uint16_t len)
{
    int32_t ret;
    if (len > IPC_BUFFER_MAX) {
        ps_print_err("cmd_connect_msg_handle, invalid param\n");
        return -OAL_FAIL;
    }

    ret = memcpy_s(g_hw_ipc_ctx.msg_buffer, IPC_BUFFER_MAX, data, len);
    if (unlikely(ret != EOK)) {
        ps_print_err("g_hw_ipc_ctx.op_param data copy failed\n");
        return -OAL_FAIL;
    }

    oal_queue_work(g_hw_ipc_ctx.wq_ipc, &g_hw_ipc_ctx.op_work);
    ps_print_info("oal_queue_work wq_ipc\n");
    return OAL_SUCC;
}

static int32_t plat_ipc_mcu_msg_proc(const struct pkt_header *head)
{
    int32_t ret = 0;
    if (head == NULL) {
        ps_print_err("plat_ipc_mcu_msg_proc: param error\n");
        return -OAL_FAIL;
    }

    ps_print_warning("plat_ipc_mcu_msg_proc, cmd = %d\n", head->cmd);
    switch (head->cmd) {
        case CMD_CONNECT_MCU_TO_AP:
            ret = cmd_connect_msg_handle((const uint8_t *)&head[1], head->length);
            break;
        default:
            break;
    }

    return ret;
}

int32_t plat_ipc_send_cmd(uint8_t cmd, const uint8_t *data, uint16_t len)
{
    int32_t ret;
    struct write_info winfo = { 0 };
    if (((data == NULL) && (len != 0)) || ((data != NULL) && (len == 0))) {
        ps_print_err("plat_ipc_send_cmd: param error\n");
        return -OAL_FAIL;
    }

    winfo.tag = TAG_CONNECTIVITY_SW;
    winfo.cmd = cmd;
    winfo.wr_buf = data;
    winfo.wr_len = len;
    ret = write_customize_cmd(&winfo, NULL, false);
    if (ret != OAL_SUCC) {
        ps_print_err("plat_ipc_send_cmd, ret = %d\n", ret);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static void hw_ipc_op_work(oal_work_stru *work)
{
    hw_plat_ipc_ctx_t *ctx = NULL;
    oal_wake_lock_timeout(&g_ipc_wake_lock, IPC_WAKELOCK_TIMEOUT);
    ctx = container_of(work, hw_plat_ipc_ctx_t, op_work);

    mutex_lock(&ctx->ipc_mutex);
    ps_print_info("enter hw_ipc_op_work\n");
    plat_ipc_mcu2ap_msg_handle(ctx->msg_buffer, (uint16_t)sizeof(ctx->msg_buffer));
    mutex_unlock(&ctx->ipc_mutex);
    oal_wake_unlock_force(&g_ipc_wake_lock);
}

int plat_ipc_init(void)
{
    int ret;
    if (get_iomcu_ipc_support() == OAL_FALSE) {
        ps_print_info("iomcu ipc not support\n");
        return OAL_SUCC;
    }

    ret = register_mcu_event_notifier(TAG_CONNECTIVITY_SW, CMD_CONNECT_MCU_TO_AP, plat_ipc_mcu_msg_proc);
    if (ret != OAL_SUCC) {
        ps_print_err("Failed to register CMD_CONNECT_MCU_TO_AP ipc ret = 0x%x!", ret);
        return -OAL_FAIL;
    }

    g_hw_ipc_ctx.wq_ipc = oal_create_singlethread_workqueue("hw_ipc_queue");
    if (g_hw_ipc_ctx.wq_ipc == NULL) {
        ps_print_err("Failed to create hw_ipc_queue!");
        unregister_mcu_event_notifier(TAG_CONNECTIVITY_SW, CMD_CONNECT_MCU_TO_AP, plat_ipc_mcu_msg_proc);
        return -OAL_FAIL;
    }

    INIT_WORK(&g_hw_ipc_ctx.op_work, hw_ipc_op_work);
    oal_wake_lock_init(&g_ipc_wake_lock, "plat ipc wakelock");
    mutex_init(&g_hw_ipc_ctx.ipc_mutex);

    ps_print_info("plat_ipc_init succ\n");
    return OAL_SUCC;
}

void plat_ipc_exit(void)
{
    if (get_iomcu_ipc_support() == OAL_FALSE) {
        ps_print_info("iomcu ipc not support\n");
        return;
    }

    mutex_destroy(&g_hw_ipc_ctx.ipc_mutex);
    oal_wake_lock_exit(&g_ipc_wake_lock);
    oal_destroy_workqueue(g_hw_ipc_ctx.wq_ipc);
    unregister_mcu_event_notifier(TAG_CONNECTIVITY_SW, CMD_CONNECT_MCU_TO_AP, plat_ipc_mcu_msg_proc);
}
#endif