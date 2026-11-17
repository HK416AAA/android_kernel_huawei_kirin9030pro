/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

#ifndef _BSP_DPA_CHR_H_
#define _BSP_DPA_CHR_H_

#include <linux/skbuff.h>

#define DPA_CHR_DEBUG                   1

enum {
    DPA_DMI_MSG_SEND_FAIL,

    DPA_FAIL_EVENT_MAX,
};

enum {
    FAIL_TYPE_PARAM_ERR,                /* 参数错误 */
    FAIL_TYPE_FULL,                     /* 队列满 */
    FAIL_TYPE_SEND_FAIL,                /* 发送失败 */
    FAIL_TYPE_RECV_FAIL,                /* 接收失败 */
    FAIL_TYPE_RESERVED_0,

    DPA_FAIL_TYPE_MAX = 5,              /* 通道约束，调整需同硬工对齐 */
};

#define CHR_EVENT_NAME_SIZE                 32

#define MAX_DPA_FREQ_LEVEL                  10               // equal to DFS_MAX_LEVEL
#define DPA_A2D_FAIL_REASON_MAX             20
#define DPA_D2A_REVERT_REASON_MAX           20
#define DPA_D2A_REVERT_NO_ERR_MAX           10
#define DPA_MAX_WAKEUP_SOURCE               10
#define DPA_A2D_FAIL_REASON_BASE            100
#define DPA_A2D_REVERT_REASON_BASE          200
#define DPA_A2D_REVERT_NO_ERR_BASE          300

#define DPA_CHR_MAX_REPORT_APP_COUNT        10
#define DPA_CHR_INTER_CORE_ERROR            10
#define RAT_TYPE                            3
#define IF_MAX_NUM                          4

typedef struct {
    unsigned char name[CHR_EVENT_NAME_SIZE];
    unsigned int cnt;
    unsigned int pkts;
    unsigned int bytes;
} chr_event_data_block;

typedef struct {
    unsigned short save_revert_event[DPA_D2A_REVERT_REASON_MAX];
    unsigned short save_fail_event[DPA_A2D_FAIL_REASON_MAX];
    unsigned short save_revert_no_err_event[DPA_D2A_REVERT_NO_ERR_MAX];
    unsigned short event_id;
    unsigned short data_block_size;
} dpa_chr_event_msg_header;

typedef struct {
    dpa_chr_event_msg_header header;
    chr_event_data_block data_block[0];
} dpa_chr_event_msg;

#ifdef CONFIG_DPA_CHR
/**
 * @brief dpa dmi异常事件记录
 *
 * @par 描述:
 * 记录dpa dmi异常事件次数，通过fail_type传递异常类型或原因值
 *
 * @attention
 * <ul><li>CHR上报。</li></ul>
 *
 * @param[in] fail_event, 异常事件枚举，chr上报对应的异常事件次数。
 * @param[in] fail_type, 异常类型index，可上报原因值或类型。超出最大值将上报失败。
 *
 * @retval 无。
 *
 * @par 依赖:
 * <ul><li>bsp_dpa_chr.h：该接口声明所在的头文件。</li></ul>
 */
void dpa_fail_event_add(unsigned int fail_event, unsigned int fail_type);

/**
 * @brief dpa协议栈输入钩子函数
 *
 * @par 描述:
 * dpa协议栈输入钩子函数
 *
 * @attention
 * <ul><li>CHR上报。</li></ul>
 *
 * @param[in] skb, 被检查的处理skb。
 *
 * @retval 无。
 *
 * @par 依赖:
 * <ul><li>bsp_dpa_chr.h：该接口声明所在的头文件。</li></ul>
 */
void dpa_hook_local_in(struct sk_buff *skb);

/**
 * @brief dpa协议栈输出钩子函数
 *
 * @par 描述:
 * dpa协议栈输出钩子函数
 *
 * @attention
 * <ul><li>CHR上报。</li></ul>
 *
 * @param[in] skb, 被检查的处理skb。
 *
 * @retval 无。
 *
 * @par 依赖:
 * <ul><li>bsp_dpa_chr.h：该接口声明所在的头文件。</li></ul>
 */
void dpa_hook_local_out(struct sk_buff *skb);

/**
 * @brief dpa设置tcp参数
 *
 * @par 描述:
 * dpa设置tcp参数
 *
 * @attention
 * <ul><li>CHR上报。</li></ul>
 *
 * @param[in] 无。
 *
 * @retval 无。
 *
 * @par 依赖:
 * <ul><li>bsp_dpa_chr.h：该接口声明所在的头文件。</li></ul>
 */
void set_tcp_for_dpa(void);
#else
static inline void dpa_fail_event_add(unsigned int fail_event, unsigned int fail_type)
{
    return;
}

static inline void dpa_hook_local_in(struct sk_buff *skb)
{
    return;
}

static inline void dpa_hook_local_out(struct sk_buff *skb)
{
    return;
}

static inline void set_tcp_for_dpa(void)
{
    return;
}
#endif
#endif