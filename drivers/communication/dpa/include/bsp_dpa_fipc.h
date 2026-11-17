/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef _BSP_DPA_FIPC_H
#define _BSP_DPA_FIPC_H
#include <linux/types.h>
#include <securec.h>

/* * @brief 错误码：当前资源不足，请重试 */
#define DPA_FIPC_ERR_EAGAIN (-11)

typedef enum {
    DPA_FIPC_EVENT_DATA_ARRV,
    DPA_FIPC_EVENT_SEND_DONE,
    DPA_FIPC_EVENT_SEND_FLOWUP,
    DPA_FIPC_EVENT_SEND_FLOWDN,
    DPA_FIPC_EVENT_RECV_TIMEOUT,
    DPA_FIPC_EVENT_RECV_FLOWUP,
    DPA_FIPC_EVENT_INVAILD,
} dpa_fipc_event;

typedef enum {
    DPA_FIPC_CHNL_SEND = 1,
    DPA_FIPC_CHNL_RECV,
    DPA_FIPC_CHNL_TYPE_MAX
} dpa_fipc_chnl_type_e;

struct dpa_fipc_channel;
typedef struct dpa_fipc_channel *dpa_fipc_chn_t;
typedef u64 dpafipcsoc_ptr_t;

typedef union {
    struct {
        unsigned chnid;
        dpa_fipc_chn_t chn_hdl;
    } data_event; /* used for give information for event DPA_FIPC_EVENT_DATA_ARRV/DPA_FIPC_EVENT_SEND_DONE */
} dpa_fipc_eventinfo;

typedef int (*dpa_fipc_cbk)(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info);

typedef struct {
    unsigned chnid;      /* *< 通道的id定义, 在attr_init后用户填写 */
    unsigned type;       /* *< 通道收发属性，例如DPA_FIPC_CHN_TYPE_SEND ,在attr_init后用户填写 */
    dpafipcsoc_ptr_t ga; /* *< ringbuf全局地址，硬件有对齐要求 8Bytes, 在attr_init后用户填写 */
    void *va;            /* *< ringbuf虚拟地址,在attr_init后用户填写 */
    unsigned size;       /* *< ringbuf大小，硬件有对齐要求 128Bytes,在attr_init后用户填写 */
    dpa_fipc_cbk cbk;    /* *< ficc事件发生时的回调函数, 在attr_init后用户填写 */
    void *cbk_arg; /* *< 回调时，透传的用户私有数据，用户需要保证cbk_arg的生命周期,在attr_init后用户填写 */
    unsigned flags; /* *< 一些标志，比如唤醒，报中断等, 不清楚用处的在attr_init后不要操作 */
    unsigned checksum_mod; /* checksum功能，配置mode使用 */
    /*   设置水线
         00：一个数据块或一个消息；设置为0时，不使能上水线中断
         01：1/2深度；
         10：3/4深度；
         11：7/8深度;
    */
    unsigned overflow_th;
    unsigned underflow_th;
    /* [5]：超时计时粒度，1表示按照ms计数，0表示按照us计数；
       [4:0]：超时阈值，计数器计数到达阈值，上报数据到达超时中断，0表示不计时
       设置为0，表示不使能超时中断
    */
    unsigned timeout_val;
} dpa_fipc_chn_attr_t;

typedef struct {
    unsigned cnt;
    struct {
        void *buf;
        unsigned len;
    } datablk[0];
} dpa_fipc_blk_desc_t;

typedef struct {
    unsigned cnt;
    struct {
        void *buf;
        unsigned len;
    } datablk[0x2];
} dpa_fipc_blkx2_desc_t;

typedef struct {
    unsigned cnt;
    struct {
        void *buf;
        unsigned len;
    } datablk[0x3];
} dpa_fipc_blkx3_desc_t;

typedef struct {
    unsigned int len;
    unsigned int pkthdl;
} ioctl_dpa_nxtpkt;

#define DPA_FIPC_SEND_FLAGS_NOARRVNOTIFY (1UL << 0)
#define DPA_FIPC_SEND_FLAGS_NODONENOTIFY (1UL << 1)

#define DPA_FIPC_RECV_FLAGS_DATAPEEK (1UL << 0)

#define DPA_FIPC_IOCTL_CHN_NXTPKT_INF 0x40000002
#define DPA_FIPC_IOCTL_CHN_PACKET_SKIP 0x40000003
#define DPA_FIPC_IOCTL_CHN_CAPSET_INF 0x40000004
#define DPA_FIPC_IOCTL_CHN_STATUS_INF 0x40000005

#define DPA_FIPC_OPIPE_HEAD_LEN (12)

#define DPA_FIPC_TEST_COMMON_SEND_1 (0x1)
#define DPA_FIPC_TEST_COMMON_RECV_1 (0x0)
#define DPA_FIPC_TEST_PRIVATE_SEND_1 (0x3)
#define DPA_FIPC_TEST_PRIVATE_RECV_1 (0x2)
#define DPA_FIPC_TEST_PRIVATE_SEND_2 (0x5)
#define DPA_FIPC_TEST_PRIVATE_RECV_2 (0x4)
#define DPA_FIPC_TEST_PRIVATE_SEND_3 (0x7)
#define DPA_FIPC_TEST_PRIVATE_RECV_3 (0x6)
#define DPA_FIPC_TEST_PRIVATE_SEND_4 (0x9)
#define DPA_FIPC_TEST_PRIVATE_RECV_4 (0x8)

#define FICC_CHN_RECV_DPA2AP_MDRVRFILE (0xa)
#define FICC_CHN_SEND_AP2DPA_MDRVRFILE (0xb)

int bsp_dpa_fipc_chn_attr_init(dpa_fipc_chn_attr_t *pattr);
int bsp_dpa_fipc_chn_open(dpa_fipc_chn_t *pchn_hdl, dpa_fipc_chn_attr_t *pattr);
int bsp_dpa_fipc_chn_blks_send(dpa_fipc_chn_t chn_hdl, dpa_fipc_blk_desc_t *pblkdesc);
int bsp_dpa_fipc_chn_blk2ring_send(dpa_fipc_chn_t pchn_hdl, unsigned long long data_pa, unsigned int len, u32 flags);
int bsp_dpa_fipc_chn_recv(dpa_fipc_chn_t chn_hdl, void *buf, unsigned len);
// 返回值为负数时，表示异常；正数则表示读取的数据长度
int bsp_dpa_fipc_chn_recv_raw(dpa_fipc_chn_t chn_hdl, void *buf, unsigned len);
int bsp_dpa_fipc_chn_ioctl(dpa_fipc_chn_t chn_hdl, unsigned req, void *arg, unsigned int size);
// 仅用于获取发送通道的rptr值，传入接收通道，会报错
int bsp_dpa_fipc_chn_rptr_get(dpa_fipc_chn_t chn_hdl, unsigned int *rptr);
u32 bsp_dpa_fipc_chn_recv_used_space_get(dpa_fipc_chn_t chn);
int bsp_dpa_fipc_channel_int_en(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_channel_int_dis(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_channel_overflow_int_en(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_channel_overflow_int_dis(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_channel_timeout_int_en(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_channel_timeout_int_dis(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_chn_before_resetting(void);
int bsp_dpa_fipc_chn_after_resetting(void);
/* *
 * @brief bsp_dpa_fipc_channel_all_int_en
 *
 * @par 描述:
 * 使能eicc通道chn_hdl的中断，控制通道各类型中断的汇总信息，使能后，打开的中断类型可以上报；
 *
 * @attention
 * 该接口为action，设置的core int mask不会在低功耗中进行备份恢复
 *
 * @param[in]
 * chn_hdl: 通道handle
 *
 * @retval 0 操作成功，其他值 操作失败
 *
 * @par 依赖:
 *
  */
int bsp_dpa_fipc_channel_all_int_en(dpa_fipc_chn_t chn_hdl);

/* *
 * @brief bsp_dpa_fipc_channel_all_int_dis
 *
 * @par 描述:
 * 去使能eicc通道chn_hdl的中断，控制通道各类型中断的汇总信息，去使能后，通道任何类型中断均无法上报
 *
 * @attention
 * 该接口为action，设置的core int mask不会在低功耗中进行备份恢复
 *
 * @param[in]
 * chn_hdl: 通道handle
 *
 * @retval 0 操作成功，其他值 操作失败
 *
 * @par 依赖:
 *
  */
int bsp_dpa_fipc_channel_all_int_dis(dpa_fipc_chn_t chn_hdl);

/* *
 * @brief bsp_dpa_fipc_send_channel_regs_report
 *
 * @par 描述:
 * 维测使用，将通道的寄存器信息上报到hids
 *
 * @attention
 *
 * @param[in]
 * chn_hdl: 通道handle
 *
 * @retval 无
 *
 * @par 依赖: 调用上下文，需要确保dpa处于唤醒状态
 *
  */
void bsp_dpa_fipc_send_channel_regs_report(dpa_fipc_chn_t chn_hdl);


int bsp_dpa_fipc_channel_underflow_int_en(dpa_fipc_chn_t chn_hdl);
int bsp_dpa_fipc_channel_underflow_int_dis(dpa_fipc_chn_t chn_hdl);

#endif
