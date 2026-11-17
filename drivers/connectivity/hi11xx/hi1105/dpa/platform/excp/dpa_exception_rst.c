/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dpa异常处理
 * Author: dpa drivers
 */

/* 头文件包含 */
#include "conn_dmi_msg.h"
#include "oal_util.h"
#include "bsp_console.h"
#include "bsp_dump.h"
#include "board_pm.h"
#include "oal_schedule.h"
#include "oal_mm.h"
#include "oal_mutex.h"
#include "mdrv_kevent.h"
#include "oam_logger.h"
#include "dpa_exception_rst.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_DPA_EXCEPTION_RST_C

#define DPA_EXCEP_BUF_LEN 28
#define DPA_EXCEP_SUPPORT_NUM 32

#define DPA_EXCEPTION_RESET_IDLE  0 /* 没有在处理异常 */
#define DPA_EXCEPTION_RESET_BUSY  1 /* 正在处理异常 */

/* DPA异常信息保存结构体 */
struct exception_info_str {
    uint32_t mod_id;                // 记录当前异常类型
    uint8_t buf[DPA_EXCEP_BUF_LEN];
};

/* DPA异常线程信息结构体 */
struct thread_excep_info_str {
    mdrv_task_id task_id;           // 记录当前线程id
    uint32_t excep_event;           // 记录当前触发异常事件
};

/* DPA异常管理结构体 */
struct excep_mng_info {
    oal_mutex_stru excep_mutex;
    uint32_t excep_status;        // 记录当前异常状态
    struct exception_info_str excep_info;   // 记录当前提交异常信息
    uint32_t thread_bitmap;         // 记录当前线程注册情况(每bit表示注册情况: 默认1为空闲, 0为注册)
    uint32_t thread_status;         // 记录当前线程异常处理情况(每bit与thread_bitmap对应, 1表示处理完成, 0表示待处理)
    struct thread_excep_info_str thread_excep_info[DPA_EXCEP_SUPPORT_NUM]; // 存储需要响应异常的线程信息
};

static struct excep_mng_info g_dpa_excep_info;

/*
 * 函 数 名  : dpa_exception_submit
 * 功能描述  : 异常处理请求提交请求函数
 * 输入参数  : mod_id 当前DPA上异常类型; buf 异常信息上报
 * 返 回 值  : 异常处理提交成功返回0
 */
int32_t dpa_exception_submit(uint32_t mod_id, uint8_t *buf, uint8_t buf_len)
{
    uint32_t idx;
    if (mod_id >= EXCEPTION_TYPE_BOTTOM) {
        oam_error_log1(0, OAM_SF_DPA, "[DPA_DFR] dpa exception submit mod_id %u invalid", mod_id);
        return -OAL_FAIL;
    }

    oal_mutex_lock(&g_dpa_excep_info.excep_mutex);
    if (g_dpa_excep_info.excep_status == DPA_EXCEPTION_RESET_BUSY) {
        oal_mutex_unlock(&g_dpa_excep_info.excep_mutex);
        oam_error_log1(0, OAM_SF_DPA, "[DPA_DFR] dpa exception is working, %u dis allow to submit", mod_id);
        return -OAL_FAIL;
    }

    /* 保存当前提交异常申请信息 */
    g_dpa_excep_info.excep_info.mod_id = mod_id;
    if (buf != NULL && buf_len != 0) {
        if (memcpy_s(g_dpa_excep_info.excep_info.buf, DPA_EXCEP_BUF_LEN, buf, buf_len) != EOK) {
            oal_mutex_unlock(&g_dpa_excep_info.excep_mutex);
            oam_error_log0(0, OAM_SF_DPA, "[DPA_DFR] dpa exception submit memcpy fail");
            return -OAL_FAIL;
        }
    }
    g_dpa_excep_info.excep_status = DPA_EXCEPTION_RESET_BUSY;
    oal_mutex_unlock(&g_dpa_excep_info.excep_mutex);

    oam_warning_log0(0, OAM_SF_DPA, "[DPA_DFR] dpa_exception_submit succ");
    /* 触发所有已经注册线程调度异常处理 */
    for (idx = 0; idx < DPA_EXCEP_SUPPORT_NUM; idx++) {
        if ((g_dpa_excep_info.thread_bitmap & BIT(idx)) != 0) {
            break;
        }
        mdrv_kevent_send(g_dpa_excep_info.thread_excep_info[idx].task_id,
                         g_dpa_excep_info.thread_excep_info[idx].excep_event);
        oam_info_log2(0, OAM_SF_DPA, "[DPA_DFR] dpa thread %u exception event %u submit succ",
                      g_dpa_excep_info.thread_excep_info[idx].task_id,
                      g_dpa_excep_info.thread_excep_info[idx].excep_event);
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : dpa_exception_register
 * 功能描述  : 异常处理注册接口, DPA进入异常, 线程需要异常处理需调用该接口注册
 * 输入参数  : excep_id 当前线程返回注册号, 异常处理完成后发送使用; task_id 当前线程id; event 当前异常事件
 * 返 回 值  : 注册成功返回0
 */
int32_t dpa_exception_register(uint8_t *excep_id, mdrv_task_id task_id, uint32_t event)
{
    uint8_t excep_bit = 0;
    uint32_t idx;
    if (g_dpa_excep_info.thread_bitmap == 0) {
        oam_error_log2(0, OAM_SF_DPA, "[DPA_DFR] dpa exception register fail, task_id = %u, event = %u",
                       task_id, event);
        return -OAL_FAIL;
    }

    /* 判断当前是否重复注册 */
    for (idx = 0; idx < DPA_EXCEP_SUPPORT_NUM; idx++) {
        if ((g_dpa_excep_info.thread_bitmap & BIT(idx)) != 0) {
            break;
        }
        if (g_dpa_excep_info.thread_excep_info[idx].task_id == task_id) {
            oam_error_log2(0, OAM_SF_DPA, "[DPA_DFR] dpa exception duplicate register, task_id = %u, event = %u",
                           task_id, event);
            return -OAL_FAIL;
        }
    }

    excep_bit = oal_bit_find_first_bit_four_byte(g_dpa_excep_info.thread_bitmap);
    g_dpa_excep_info.thread_bitmap &= ~BIT(excep_bit); // 获取的event bit置0

    g_dpa_excep_info.thread_excep_info[excep_bit].task_id = task_id;
    g_dpa_excep_info.thread_excep_info[excep_bit].excep_event = event;

    *excep_id = excep_bit;
    return OAL_SUCC;
}

/*
 * 函 数 名  : dpa_exception_handler
 * 功能描述  : 异常处理总入口函数，填充异常信息
 * 输入参数  : excep_id 当前线程注册异常号
 * 返 回 值  : 异常处理成功返回0
 */
int32_t dpa_exception_handler(uint32_t excep_id)
{
    int32_t ret;

    oam_warning_log1(0, OAM_SF_DPA, "[DPA_DFR] dpa exception handler, %d thread exception completed", excep_id);
    oal_mutex_lock(&g_dpa_excep_info.excep_mutex);
    /* 当前线程已经处理完成 */
    g_dpa_excep_info.thread_status |= BIT(excep_id);
    /* 遍历当前已经注册线程调度异常处理结果 */
    if ((~g_dpa_excep_info.thread_bitmap & g_dpa_excep_info.thread_status) != ~g_dpa_excep_info.thread_bitmap) {
        oal_mutex_unlock(&g_dpa_excep_info.excep_mutex);
        oam_warning_log2(0, OAM_SF_DPA, "[DPA_DFR] dpa thread %u, status %u, disallow to send dfr",
                         g_dpa_excep_info.thread_bitmap, g_dpa_excep_info.thread_status);
        return OAL_SUCC;
    }

    ret = conn_dmi_msg_data_send(CONN_DMI_MSG_DPA_EXCEP,
                                 (uint8_t *)&g_dpa_excep_info.excep_info, sizeof(struct exception_info_str));
    if (ret != OAL_SUCC) {
        oal_mutex_unlock(&g_dpa_excep_info.excep_mutex);
        oam_error_log1(0, OAM_SF_DPA, "[DPA_DFR] dpa exception handler msg send fail, ret = %d", ret);
        return ret;
    }
    oal_mutex_unlock(&g_dpa_excep_info.excep_mutex);
    return OAL_SUCC;
}

/*
 * 函 数 名  : notify_msg_from_acpu
 * 功能描述  : 接收从A核过来的消息，触发dpa侧注册线程的异常处理，避免dfr过程中dpa非法访问等情况
 */
int32_t notify_msg_from_acpu(uint8_t *buf, uint16_t buf_len)
{
    const uint8_t dpa_msg[] = "dpa reset";
    oam_warning_log0(0, OAM_SF_DPA, "receive acpu exception notify");
    if (dpa_in_excepion_reset() == OAL_TRUE) {
        // dpa 复位场景下的dfr恢复，不需要通知线程恢复
        return conn_dmi_msg_data_send(CONN_DMI_MSG_DPA_EXCEP, dpa_msg, sizeof(dpa_msg));
    } else {
        return dpa_exception_submit(EXCEPTION_TYPE_ACPU_MSG, NULL, 0);
    }
}

/*
 * 函 数 名  : exception_module_init
 * 功能描述  : 异常处理初始化
 * 返 回 值  : 异常处理初始化成功返回0
 */
void exception_module_init(void)
{
    memset_s(&g_dpa_excep_info, sizeof(struct excep_mng_info), 0, sizeof(struct excep_mng_info));
    g_dpa_excep_info.thread_bitmap = 0xFFFFFFFF;
    if (oal_mutex_init(&g_dpa_excep_info.excep_mutex) != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_ERR, "[DPA_DFR] dpa exception module mutex init fail");
    }

    if (conn_dmi_msg_regiser(CONN_DMI_MSG_H2D_EXCP_NOTIFY, notify_msg_from_acpu, NULL) != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_ERR, "[DPA_DFR] excep notify register fail");
    }
}

/*
 * 函 数 名  : exception_module_deinit
 * 功能描述  : 异常处理去初始化
 */
void exception_module_deinit(void)
{
    memset_s(&g_dpa_excep_info, sizeof(struct excep_mng_info), 0, sizeof(struct excep_mng_info));
    g_dpa_excep_info.thread_bitmap = 0xFFFFFFFF;
    oal_mutex_free(&g_dpa_excep_info.excep_mutex);
    conn_dmi_msg_regiser(CONN_DMI_MSG_H2D_EXCP_NOTIFY, NULL, NULL);
}

/*
 * 函 数 名  : exception_open_init
 * 功能描述  : 异常处打开初始化
 * 返 回 值  : 异常处理初始化成功返回0
 */
void exception_open_init(void)
{
    g_dpa_excep_info.excep_status = DPA_EXCEPTION_RESET_IDLE;
    g_dpa_excep_info.thread_status = 0;
    memset_s(&g_dpa_excep_info.excep_info, sizeof(struct exception_info_str), 0, sizeof(struct exception_info_str));
}
