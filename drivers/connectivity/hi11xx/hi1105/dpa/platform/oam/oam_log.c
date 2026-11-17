/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: OAM log function
 * Author: dpa drivers
 */

/* 头文件包含 */
#include "hcc_slave.h"
#include "oal_mm.h"
#include "conn_dmi_oam.h"
#include "securec.h"
#include "oam_queue.h"
#include "oal_schedule.h"
#include "osl_thread.h"
#include "oam_log.h"

/* 宏定义 */
#define OAM_LOG_MSG_LEN          (sizeof(om_log_stru))  // 日志消息结构体 + SDT传输报文结构体长度
#define OAM_LOG_HEADER_LEN       (OAM_LOG_MSG_LEN - (OAM_LOG_ENTRY_PARA_NUM + 1) * 4)
#define WLAN_SDT_NETBUF_SIZE     464                    // SDT内存池空间大小
#define WLAN_SDT_NETBUF_CNT      8                      // SDT内存池个数
#define OM_FRAME_DELIMITER       0x7E                   // 帧定界符
#define OAM_THREAD_SIZE          0x1000
#define OAM_EVENT_MODE           (OS_EVENT_ANY)

/* primID pattern */
typedef enum {
    OM_WIFI = 0x01,
    OM_MODULEID_BUTT
} oam_msg_moduleid_enum;

/* data type */
typedef enum {
    OAM_DATA_TYPE_LOG = 0x1,
    OAM_DATA_TYPE_BUTT
} oam_data_type_enum;

typedef struct oam_info {
    mdrv_task_id task_id;
    uint32_t event_type;
    uint32_t running_flag;
    void *stack_addr;
} oam_info_t;

/* SDT传输报文结构体 */
typedef struct {
    uint8_t        frame_start;
    uint8_t        func_type;
    uint8_t        prime_id_t;
    uint8_t        reserver[1]; // sdt tool alreay used for sysinfo
    uint16_t       frame_len;
    uint16_t       sn_t;
} om_msg_header_stru;

/* VAP日志级别结构体 */
typedef struct {
    uint8_t bit_vap_id : 4;
    uint8_t bit_log_level : 4;
} oam_vap_log_level_stru;

/* SDT日志消息结构体 */
typedef struct {
    oam_vap_log_level_stru vap_log_level; /* vapid + loglevel */
    uint8_t feature_id;    /* 特性id */
    uint16_t resv;
    uint16_t file_id;  /* 文件号 */
    uint16_t line_num; /* 行号 */
    uint32_t tick;     /* 时间戳，精度ms */
    int32_t param[OAM_LOG_ENTRY_PARA_NUM + 1];
} oam_log_info_stru;

/* STRUCT定义 */
#pragma pack(push, 1)
typedef struct {
    om_msg_header_stru  oam_header;
    oam_log_info_stru   log_info;
} om_log_stru;
#pragma pack(pop)

/* oam日志打印入参聚合 */
typedef struct {
    uint32_t  bit16_file_id :  16;
    uint32_t  bit8_feature_id : 8;
    uint32_t  bit4_vap_id :     4;
    uint32_t  bit4_log_level :  4;
} om_log_wifi_para_stru;

/* 日志内存池模块管理结构体 */
typedef struct {
    uint8_t             *buffer;
    uint32_t            res_index;
    uint16_t            netbuf_len;
    uint16_t            used_len;
    struct osl_list     node;
} oam_log_buff_stru;

/* 日志内存池管理数组 */
static oam_log_buff_stru g_mng_buff_info[WLAN_SDT_NETBUF_CNT] = {0};
/* 日志内存池数据管理队列 */
static oal_uint g_queue_mng_idx[WLAN_SDT_NETBUF_CNT] = {0};
static oam_queue_stru g_st_queue = {0};

/* 全局变量定义 */
static oal_spin_lock_stru g_oam_spinlock;
static uint16_t g_oam_log_sn = 0;                      // 日志发送sn号
static uint32_t g_drop_log_overwrite_cnt  = 0;         // 记录日志内存池已满, 覆盖次数
static uint32_t g_drop_log_alloc_fail_cnt = 0;         // 记录内存分配失败次数
static oam_log_buff_stru*  g_curr_oam_buff = NULL;     // 当前正使用内存块
static struct osl_list g_wait_send_list;               // 待发送队列
static uint32_t(*oml_send_data)(uint8_t *, uint16_t) = NULL;
static oam_info_t g_oam_thread_info;
uint32_t g_spin_lock_alloc_succ_cnt = 0;
uint32_t g_spin_lock_free_cnt = 0;
static void oam_data_send(void);

bool oam_thread_is_running(void)
{
    return g_oam_thread_info.running_flag;
}

void oam_thread_stop(void)
{
    g_oam_thread_info.running_flag = false;
}

/*
 * 函 数 名  : oam_thread_process
 * 功能描述  : oam线程处理函数
 */
static int32_t oam_thread_process(void *param)
{
    uint32_t recv_event;

    oal_print_mpxx_log(MPXX_LOG_INFO, "oam_thread_process enter");
    while (oam_thread_is_running()) {
        recv_event = 0;
        mdrv_kevent_recv(g_oam_thread_info.event_type, OAM_EVENT_MODE, OS_EVENT_WAIT_FOREVER, &recv_event);
        oam_data_send();
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_thread_create
 * 功能描述  : oam线程创建函数
 */
static int32_t oam_thread_create(void)
{
    mdrv_task_attr_t task_attr = { 0 };
    int32_t ret;

    g_oam_thread_info.stack_addr = mdrv_mem_alloc(OAM_THREAD_SIZE, MEM_CACHE | MDRV_MEM_ALIGN_016);
    if (g_oam_thread_info.stack_addr == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_thread_create stack mem alloc fail");
        return -OAL_FAIL;
    }

    task_attr.type = THRD_TASK;
    task_attr.prio = OS_TSK_PRIORITY_01;
    task_attr.stackSize = OAM_THREAD_SIZE;
    task_attr.stackAddr = (uintptr_t)g_oam_thread_info.stack_addr;
    task_attr.queNum = 1;
    task_attr.args[0] = 0;
    task_attr.entryFunc = oam_thread_process,
    ret = (int32_t)osl_task_create("hisi_oam", &task_attr, 1, &g_oam_thread_info.task_id);
    if (ret) {
        mdrv_free(g_oam_thread_info.stack_addr);
        oal_print_mpxx_log(MPXX_LOG_ERR, "osl_task_create hisi_oam fail, ret = 0x%x", ret);
        return -OAL_FAIL;
    }
    g_oam_thread_info.event_type = 0xFFFFFFFF;
    g_oam_thread_info.running_flag = true;
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_thread_destory
 * 功能描述  : oam线程销毁函数
 */
void oam_thread_destory(void)
{
    uint32_t ret;

    ret = mdrv_task_delete(g_oam_thread_info.task_id);
    if (ret) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "mdrv_task_delete hisi_oam fail, ret = 0x%x", ret);
    }
    mdrv_free(g_oam_thread_info.stack_addr);
}

/*
 * 函 数 名  : oam_sched_transfer
 * 功能描述  : oam线程调度函数
 */
static void oam_sched_transfer(void)
{
    mdrv_kevent_send(g_oam_thread_info.task_id, 1);
}

/*
 * 函 数 名  : oam_log_res_init
 * 功能描述  : 初始化log缓存结构资源:
 */
int32_t oam_log_res_init(void)
{
    uintptr_t loop;
    int32_t ret;

    ret = oam_queue_init(&g_st_queue, g_queue_mng_idx, WLAN_SDT_NETBUF_CNT);
    if (ret != OAL_SUCC) {
        return ret;
    }

    for (loop = 0; loop < WLAN_SDT_NETBUF_CNT; loop++) {
        /* 初始值保存的是对应数组下标值加1 */
        oam_queue_enqueue(&g_st_queue, (void *)(loop + 1));
    }

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_log_res_alloc
 * 功能描述  : 分配一个log缓存结构资源:
 */
static oam_log_buff_stru *oam_log_res_alloc(void)
{
    uint32_t idx_temp;
    idx_temp = (uint32_t)(uintptr_t)oam_queue_dequeue(&g_st_queue);
    /* 0为无效值 */
    if (idx_temp == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_log_res_alloc inalid index");
        return NULL;
    }

    g_mng_buff_info[idx_temp - 1].res_index = idx_temp;
    return &g_mng_buff_info[idx_temp - 1];
}

/*
 * 函 数 名  : oam_log_res_free
 * 功能描述  : 分配一个log缓存结构资源:
 */
static void oam_log_res_free(uint32_t idx)
{
    if (oal_unlikely(idx > WLAN_SDT_NETBUF_CNT) || oal_unlikely(idx == 0)) {
        return;
    }

    g_mng_buff_info[idx - 1].buffer = NULL;
    g_mng_buff_info[idx - 1].res_index = 0;
    g_mng_buff_info[idx - 1].netbuf_len = 0;
    g_mng_buff_info[idx - 1].used_len = 0;

    /* 入队索引值 */
    oam_queue_enqueue(&g_st_queue, (void *)((uintptr_t)idx));
}

/*
 * 函 数 名  : oam_log_buffer_list_init
 * 功能描述  : 初始化等待发送buffer单向链:
 */
static int32_t oam_log_buffer_list_init(void)
{
    int32_t ret;

    ret = oam_log_res_init();
    if (ret != OAL_SUCC) {
        return ret;
    }

    /* init wait send list */
    OSL_LIST_INIT(&g_wait_send_list);
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_log_buff_alloc_from_wait_list
 * 功能描述  : 从等待发送buff 链表头申请一块oam log
 */
static oam_log_buff_stru *oam_log_buff_alloc_from_wait_list(void)
{
    oam_log_buff_stru   *log_buff = NULL;

    if (osl_list_empty_careful(&g_wait_send_list)) {
        return NULL;
    }

    g_drop_log_overwrite_cnt++;

    log_buff = osl_list_get_first_node(&g_wait_send_list, oam_log_buff_stru, node);
    osl_list_remove(&log_buff->node);

    if (log_buff->buffer == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_log_buff_alloc_from_wait_list return buf NULL");
        return NULL;
    }

    // 初始化节点
    log_buff->netbuf_len = WLAN_SDT_NETBUF_SIZE;
    log_buff->used_len = 0;

    return log_buff;
}

/*
 * 函 数 名  : oam_log_buffer_alloc
 * 功能描述  : 空闲链表非空，从空闲链表中申请一块
 *             空闲链表空，从等待发送链表中申请一块
 */
static oam_log_buff_stru *oam_log_buffer_alloc(void)
{
    oam_log_buff_stru *log_buff = NULL;
    uint8_t *netbuf = NULL;

    log_buff = oam_log_res_alloc();
    if (log_buff == NULL) {
        /* 当前内存池资源已满, 从待发送链表中申请 */
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_log_res_alloc alloc res fail");
        log_buff = oam_log_buff_alloc_from_wait_list();
        return log_buff;
    }

    netbuf = (uint8_t *)oal_memalloc(WLAN_SDT_NETBUF_SIZE);
    if (netbuf == NULL) {
        /* 当前本地内存已满, 从待发送链表中申请 */
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_memalloc alloc mem fail");
        oam_log_res_free(log_buff->res_index);
        log_buff = oam_log_buff_alloc_from_wait_list();
        return log_buff;
    }

    log_buff->buffer     = netbuf;
    log_buff->netbuf_len = WLAN_SDT_NETBUF_SIZE;
    log_buff->used_len   = 0;
    return log_buff;
}

/*
 * 函 数 名  : oam_log_buffer_free
 * 功能描述  : 释放netbuf, oam log res回收
 *             仅在异常场景下调用，正常场景下，内存发送完成即可释放
 */
int32_t oam_log_buffer_free(oam_log_buff_stru *log_buff)
{
    if (log_buff == NULL) {
        return OAL_FAIL;
    }

    if (log_buff->buffer != NULL) {
        oal_free(log_buff->buffer);
    }

    oam_log_res_free(log_buff->res_index);
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_log_wait_send
 * 功能描述  : 日志待发送接口
 */
static int32_t oam_log_wait_send(oam_log_buff_stru *log_buff)
{
    if (log_buff == NULL) {
        return OAL_FAIL;
    }

    osl_list_insert_tail(&(log_buff->node), &g_wait_send_list);
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_send_sdt_log
 * 功能描述  : oam日志发送
 */
static int32_t oam_send_sdt_log(uint8_t *param, uint16_t len)
{
    conn_dmi_oam_send(param, len);
    oal_free(param);
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_data_send
 * 功能描述  : 输出可维可测数据
 */
static void oam_data_send(void)
{
    oam_log_buff_stru *cur_wait_log = NULL;
    oam_log_buff_stru *next_wait_log = NULL;
    oal_uint irq_sts;

    /* 判断发送函数是否注册，若没注册，则不打印log，否则申请空间无法释放 */
    if (oml_send_data == NULL) {
        return;
    }

    oal_spin_lock_irq_save(&g_oam_spinlock, &irq_sts);

    /* 先发送wait list中的log */
    osl_list_loop_node_safe(cur_wait_log, next_wait_log, &g_wait_send_list, node) {
        osl_list_remove(&cur_wait_log->node);
        if (cur_wait_log->buffer != NULL) {
            /* 调用发送函数发送数据 */
            if (oml_send_data != NULL) {
                (void)oml_send_data((uint8_t *)cur_wait_log->buffer, cur_wait_log->used_len);
            }
            oam_log_res_free(cur_wait_log->res_index);
        }
    }

    /* 当前已填充的log也发送掉 */
    if (g_curr_oam_buff != NULL && g_curr_oam_buff->used_len != 0) {
        /* 调用发送函数发送数据 */
        if (oml_send_data != NULL) {
            (void)oml_send_data((uint8_t *)g_curr_oam_buff->buffer, g_curr_oam_buff->used_len);
        }
        oam_log_res_free(g_curr_oam_buff->res_index);
        g_curr_oam_buff = NULL;
    }

    oal_spin_unlock_irq_restore(&g_oam_spinlock, &irq_sts);
}

static int32_t oam_data_check_param(const uint8_t *pucdata, uint16_t usdatalen)
{
    if ((pucdata == NULL) || (usdatalen == 0) || (usdatalen > OAM_LOG_MSG_LEN)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_data_check_param::param invalid! data = 0x%x datalen = %d",
                           (uint32_t)(uintptr_t)pucdata, usdatalen);
        return OAL_FAIL;
    }

    /* 判断发送函数是否注册，若没注册，则不打印log，否则申请空间无法释放 */
    if (oml_send_data == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_data_check_param::oml_send_data invalid!");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_data_converge
 * 功能描述  : 可维可测数据聚合
 */
void oam_data_converge(const uint8_t *pucdata, uint16_t usdatalen)
{
    uint8_t *pst_pos = NULL;
    oal_uint irq_sts;

    if (oam_data_check_param(pucdata, usdatalen) != OAL_SUCC) {
        return;
    }

    oal_spin_lock_irq_save(&g_oam_spinlock, &irq_sts);
    if (g_curr_oam_buff == NULL) {
        g_curr_oam_buff = oam_log_buffer_alloc();
        if (g_curr_oam_buff == NULL) {
            g_drop_log_alloc_fail_cnt++;
            oal_spin_unlock_irq_restore(&g_oam_spinlock, &irq_sts);
            return;
        }
    }

    if (g_curr_oam_buff->netbuf_len < (usdatalen + g_curr_oam_buff->used_len)) {
        /* 放入等待发送队列 */
        if (oam_log_wait_send(g_curr_oam_buff) != OAL_SUCC) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "release free list failed!");
        }

        /* 分配新的log buff,可能从sdt netbuf池获取，也可能从等待发送队列取1片覆盖 */
        g_curr_oam_buff = oam_log_buffer_alloc();
        if (g_curr_oam_buff == NULL) {
            g_drop_log_alloc_fail_cnt++;
            oal_spin_unlock_irq_restore(&g_oam_spinlock, &irq_sts);
            return;
        }
    }

    pst_pos = (uint8_t *)(g_curr_oam_buff->buffer + g_curr_oam_buff->used_len);
    if (memcpy_s(pst_pos, g_curr_oam_buff->netbuf_len - g_curr_oam_buff->used_len, pucdata, usdatalen) != EOK) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam_data_converge:: memcpy_s failed!");
    }

    g_curr_oam_buff->used_len += usdatalen;

    oal_spin_unlock_irq_restore(&g_oam_spinlock, &irq_sts);
    oam_sched_transfer();
}

static uint16_t oam_log_get_sn(void)
{
    uint16_t sn;
    oal_uint irq_sts;
    oal_spin_lock_irq_save(&g_oam_spinlock, &irq_sts);
    sn = g_oam_log_sn++;
    oal_spin_unlock_irq_restore(&g_oam_spinlock, &irq_sts);
    return sn;
}

static void oam_log_header_fill(om_log_stru *log_msg, uint32_t para_press, uint16_t line_num)
{
    om_log_wifi_para_stru para = {0};
    if (log_msg == NULL) {
        return;
    }

    memcpy_s(&para, sizeof(om_log_wifi_para_stru), &para_press, sizeof(om_log_wifi_para_stru));

    log_msg->oam_header.frame_start                 = OM_FRAME_DELIMITER;
    log_msg->oam_header.func_type                   = OAM_DATA_TYPE_LOG;
    log_msg->oam_header.prime_id_t                    = OM_WIFI;
    log_msg->oam_header.frame_len                   = 0;
    log_msg->oam_header.sn_t                         = oam_log_get_sn();
    log_msg->log_info.vap_log_level.bit_vap_id    = para.bit4_vap_id;
    log_msg->log_info.vap_log_level.bit_log_level = para.bit4_log_level;
    log_msg->log_info.feature_id                  = para.bit8_feature_id;
    log_msg->log_info.file_id                     = para.bit16_file_id;
    log_msg->log_info.line_num                    = line_num;
}

static oal_switch_enum_uint8 oam_get_log_switch(uint8_t vap_id, uint8_t feature_id, uint8_t en_log_level)
{
    if (en_log_level > g_oam_mng_ctx.log_ctx.log_level) {
        return OAL_SWITCH_OFF;
    } else if (g_oam_mng_ctx.log_ctx.en_global_log_switch == OAL_SWITCH_OFF) {
        return OAL_SWITCH_OFF;
    }

    return OAL_SWITCH_ON;
}

uint32_t oam_log_print0_press(uint32_t para_press,
                              uint16_t line_num)
{
    om_log_wifi_para_stru para = {0};
    om_log_stru log_msg = { 0 };
    uint8_t para_num = 0;

    memcpy_s(&para, sizeof(om_log_wifi_para_stru), &para_press, sizeof(om_log_wifi_para_stru));

    if (oam_get_log_switch(para.bit4_vap_id, para.bit8_feature_id, para.bit4_log_level) != OAL_SWITCH_ON) {
        return OAL_SUCC;
    }

    oam_log_header_fill(&log_msg, para_press, line_num);
    log_msg.oam_header.frame_len = (uint16_t)(OAM_LOG_HEADER_LEN + sizeof(uint8_t));
    log_msg.log_info.param[para_num] = OM_FRAME_DELIMITER;

    oam_data_converge((uint8_t *)&log_msg, log_msg.oam_header.frame_len);

    return OAL_SUCC;
}

uint32_t oam_log_print1_press(uint32_t para_press,
                              uint16_t line_num,
                              int32_t  param1)
{
    om_log_wifi_para_stru para = {0};
    om_log_stru log_msg = { 0 };
    uint8_t para_num = 1;

    memcpy_s(&para, sizeof(om_log_wifi_para_stru), &para_press, sizeof(om_log_wifi_para_stru));

    if (oam_get_log_switch(para.bit4_vap_id, para.bit8_feature_id, para.bit4_log_level) != OAL_SWITCH_ON) {
        return OAL_SUCC;
    }

    oam_log_header_fill(&log_msg, para_press, line_num);
    log_msg.oam_header.frame_len = (uint16_t)(OAM_LOG_HEADER_LEN +
                                              para_num * sizeof(uint32_t) +
                                              sizeof(uint8_t));
    log_msg.log_info.param[0] = param1;
    log_msg.log_info.param[para_num] = OM_FRAME_DELIMITER;
    oam_data_converge((uint8_t *)&log_msg, log_msg.oam_header.frame_len);
    return OAL_SUCC;
}

uint32_t oam_log_print2_press(uint32_t para_press,
                              uint16_t line_num,
                              int32_t  param1,
                              int32_t  param2)
{
    om_log_wifi_para_stru para = {0};
    om_log_stru log_msg = { 0 };
    uint8_t para_num = 2;

    memcpy_s(&para, sizeof(om_log_wifi_para_stru), &para_press, sizeof(om_log_wifi_para_stru));

    if (oam_get_log_switch(para.bit4_vap_id, para.bit8_feature_id, para.bit4_log_level) != OAL_SWITCH_ON) {
        return OAL_SUCC;
    }

    oam_log_header_fill(&log_msg, para_press, line_num);
    log_msg.oam_header.frame_len = (uint16_t)(OAM_LOG_HEADER_LEN +
                                              para_num * sizeof(uint32_t) +
                                              sizeof(uint8_t));
    log_msg.log_info.param[0] = param1;
    log_msg.log_info.param[1] = param2;
    log_msg.log_info.param[para_num] = OM_FRAME_DELIMITER;
    oam_data_converge((uint8_t *)&log_msg, log_msg.oam_header.frame_len);
    return OAL_SUCC;
}

uint32_t oam_log_print3_press(uint32_t para_press,
                              uint16_t line_num,
                              int32_t param1,
                              int32_t param2,
                              int32_t param3)
{
    om_log_wifi_para_stru para = {0};
    om_log_stru log_msg = { 0 };
    uint8_t para_num = 3;

    memcpy_s(&para, sizeof(om_log_wifi_para_stru), &para_press, sizeof(om_log_wifi_para_stru));

    if (oam_get_log_switch(para.bit4_vap_id, para.bit8_feature_id, para.bit4_log_level) != OAL_SWITCH_ON) {
        return OAL_SUCC;
    }

    oam_log_header_fill(&log_msg, para_press, line_num);
    log_msg.oam_header.frame_len = (uint16_t)(OAM_LOG_HEADER_LEN +
                                              para_num * sizeof(uint32_t) +
                                              sizeof(uint8_t));
    log_msg.log_info.param[0] = param1;
    log_msg.log_info.param[1] = param2;
    log_msg.log_info.param[2] = param3; // 2：可变入参2
    log_msg.log_info.param[para_num] = OM_FRAME_DELIMITER;
    oam_data_converge((uint8_t *)&log_msg, log_msg.oam_header.frame_len);
    return OAL_SUCC;
}

uint32_t oam_log_print4_press(uint32_t para_press,
                              uint16_t line_num,
                              int32_t  param1,
                              int32_t  param2,
                              int32_t  param3,
                              int32_t  param4)
{
    om_log_wifi_para_stru para = {0};
    om_log_stru log_msg = { 0 };
    uint8_t para_num = 4;

    memcpy_s(&para, sizeof(om_log_wifi_para_stru), &para_press, sizeof(om_log_wifi_para_stru));

    if (oam_get_log_switch(para.bit4_vap_id, para.bit8_feature_id, para.bit4_log_level) != OAL_SWITCH_ON) {
        return OAL_SUCC;
    }

    oam_log_header_fill(&log_msg, para_press, line_num);
    log_msg.oam_header.frame_len = (uint16_t)(OAM_LOG_HEADER_LEN +
                                              para_num * sizeof(uint32_t) +
                                              sizeof(uint8_t));
    log_msg.log_info.param[0] = param1;
    log_msg.log_info.param[1] = param2;
    log_msg.log_info.param[2] = param3; // 2：可变入参2
    log_msg.log_info.param[3] = param4; // 3：可变入参3
    log_msg.log_info.param[para_num] = OM_FRAME_DELIMITER;
    oam_data_converge((uint8_t *)&log_msg, log_msg.oam_header.frame_len);
    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_send_func_register
 * 功能描述  : wifi调用该函数来注册SDIO发送OAM可维可测数据函数
 */
void oam_send_func_register(void *pfunc)
{
    /* 消除向void*传函数指针提示判断未知的提示 */
    oml_send_data = (uint32_t(*)(uint8_t *, uint16_t))pfunc;
}

/*
 * 函 数 名  : oam_log_init
 * 功能描述  : 对LOG模块进行初始化操作
 *             (系统上电和系统复位调用，在oam_init函数执行完后调用)
 */
int32_t oam_log_init(void)
{
    int32_t ret;

    oal_spin_lock_init(&g_oam_spinlock);

    /* 日志发送线程初始化 */
    ret = oam_thread_create();
    if (ret != OAL_SUCC) {
        oal_spin_lock_exit(&g_oam_spinlock);
        oal_print_mpxx_log(MPXX_LOG_ERR, "oam thread create fail");
        return ret;
    }

    /* 日志内存池管理以及发送链表初始化 */
    ret = oam_log_buffer_list_init();
    if (ret != OAL_SUCC) {
        oam_thread_destory();
        oal_spin_lock_exit(&g_oam_spinlock);
        return ret;
    }

    /* 数据发送回调函数初始化 */
    oam_send_func_register(oam_send_sdt_log);

    return OAL_SUCC;
}

/*
 * 函 数 名  : oam_log_deinit
 * 功能描述  : 对LOG模块进行注销操作
 *             (系统上电和系统复位调用，在oam_init函数执行完后调用)
 */
void oam_log_deinit(void)
{
    /* SDIO数据发送回调函数初始化 */
    oml_send_data = NULL;
    oam_thread_destory();
    oal_spin_lock_exit(&g_oam_spinlock);
}
