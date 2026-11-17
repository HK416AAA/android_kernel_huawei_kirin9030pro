/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef _DPA_FIPC_DEVICE_H
#define _DPA_FIPC_DEVICE_H
#include <linux/jiffies.h>
#include <linux/of_device.h>
#include "bsp_dpa_fipc.h"

#define DPA_FIPC_MAX_PIPES_NUM (32)
#define DPA_FIPC_CPU_ID_MAX 8
#define DPA_FIPC_IRQ_CNT 2

#define DPA_FIPC_HALT_QUERY_WAIT_TIMES 200

/* 芯片给出的值 */
#define DPA_FIPC_OPIPE_STOP_WAIT 100
#define DPA_FIPC_IPIPE_STOP_WAIT 300
#define DPA_FIPC_IPIPE_IDLE_WAIT 300

typedef u64 dpa_fipc_phychnl_ptr_t;


union dpa_fipc_opipe_stat {
    u32 val;
    struct {
        u32 is_empty : 1; /* 1:空0:不空 */
        u32 is_full : 1;  /* 1:满0:不满 */
        u32 is_idle : 1;  /* 1:idle  0:busy  */
        u32 reserved : 13;
        u32 left_cnt : 16; /* 该BD剩余的数据量，单位为BYTE；1、只在存储器和外设场景下有效；2、只在对应通道处于IDLE态有效； */
    } union_stru;
};

union dpa_fipc_ipipe_stat {
    u32 val;
    struct {
        u32 is_empty : 1; /* 1:空0:不空 */
        u32 is_full : 1;  /* 1:满0:不满 */
        u32 is_idle : 1;  /* 1:idle  0:busy  */
        u32 pt_stat : 2;  /* 00:不在低功耗状态  01:请求下电10:拒绝下电11:允许下电  */
        u32 reserved : 27;
    } union_stru;
};

union dpa_fipc_opipe_ctrl {
    u32 val;
    struct {
        u32 local_en : 1; /* 1:pipe使能 0:pipe不使能 */
        u32 type : 1; /* PIPE类型。0：opipe与ipipe有关联(MSG通道);1：opipe与ipipe无关联（DMA通道） */
        u32 priorv2 : 2; /* 高低优先级队列配置，支持4个优先级，0为高优先级，3为低优先级。 */
        u32 up_thrh : 2; /* PIPE上水线：00：一个数据块或则一个消息;01：1/2深度;10：3/4深度;11：7/8深度 */
        u32 dn_thrh : 2; /* PIPE下水线：00：一个数据块或则一个消息;01：1/8深度;10：1/4深度;11：1/2深度 */
        u32 pipe_abort : 1; /* PIPE abort控制，由local CPU控制，1：opipe abort; 0：opipe不abort */
        u32 reserved1 : 3;
        u32 req_sel : 4; /* 外设请求选择求号。如果是存储器到存储器模式，忽略该控制信号。最大支持16个外设请求, 静态配置。 */
        u32 reserved2 : 4;
        u32 priorv3 : 2; /* 高低优先级队列配置，支持4个优先级，0为高优先级，3为低优先级。 */
        u32 reserved3 : 6;
        u32 peri_en : 1; /* 存储器和存储器交互或者存储器和外设交互的控制信号：1：存储器和外设之间交互，对应的BD只能是格式四；0：存储器和存储器之间交互； */
        u32 reserved4 : 3;
    } union_stru;
};

union dpa_fipc_ipipe_ctrl {
    u32 val;
    struct {
        u32 local_en : 1; /* 1:pipe使能 0:pipe不使能 */
        u32 type : 2; /* PIPE类型。00：内部通道的ipipe;01：外部通道的实体ipipe;10：外部通道的影子ipipe;11：保留 */
        u32 prior : 2; /* 高低优先级队列配置，支持4个优先级，0为高优先级，3为低优先级。 */
        u32 up_thrh : 2; /* PIPE上水线：00：一个数据块或则一个消息;01：1/2深度;10：3/4深度;11：7/8深度 */
        u32 dn_thrh : 2; /* PIPE下水线：00：一个数据块或则一个消息;01：1/8深度;10：1/4深度;11：1/2深度 */
        u32 arv_timeout : 6; /* 数据到达超时：[5]：超时计时粒度，1表示按照ms计数，0表示按照us计数[4:0]：超时阈值，计数器计数到达阈值，上报数据到达超时中断，0表示不计时
                              */
        u32 reserved : 17;
    } union_stru;
};

union dpa_fipc_pipe_ctrl {
    union dpa_fipc_opipe_ctrl opipe_uctrl;
    union dpa_fipc_ipipe_ctrl ipipe_uctrl;
};

struct dpa_fipc_pipe_config {
    u32 id; /* pipe编号  0-63 */
    void *ringbuf_va;
    dpa_fipc_phychnl_ptr_t ringbuf_pa;
    u32 depth;    /* 通道使用的buff大小， 128Bytes对齐 */
    u32 wptr;
    u32 rptr;
    u32 *ptr_vaddr;
    dpa_fipc_phychnl_ptr_t ptr_paddr;
    union dpa_fipc_pipe_ctrl pipe_uctrl;
    u32 int_level;
};

struct dpa_fipc_channel {
    u32 pipe_id;
    u32 core_id;
    u32 state;
    spinlock_t lock;
    struct dpa_fipc_pipe_config *p_pipe_config;
    u32 depth;
    u32 type;
    dpa_fipc_cbk cbk;
    void *cbk_arg;
};


struct dpa_fipc_clock_t {
    u32 dev_crg_base;
    u32 dev_crg_size;
    void *dev_crg_base_va;
    u32 dev_crg_clk_en_offset;
    u32 dev_crg_clk_dis_offset;
    u32 dev_crg_clk_mask;
};

struct dpa_fipc_irq_bundle {
    u32 cpu_id;
    u32 irq[DPA_FIPC_IRQ_CNT];    /* 一组最多FIPC_IRQ_CNT个中断 */
    struct dpa_fipc_device_t *pdev; /* 用于反向索引dev */
#ifdef CONFIG_LIBLINUX
    u32 hwirq_opipe;
    u32 hwirq_ipipe;
#endif
};

struct dpa_fipc_device_t {
    u32 device_id;
    u32 version;
    u32 pipepair_cnt;
    struct dpa_fipc_irq_bundle maps[DPA_FIPC_CPU_ID_MAX]; /* 大部分设备只有一组，这样节省内存 */
    void *base_va;
    dpa_fipc_phychnl_ptr_t base_pa;
    u32 *push_ptr_va;
    dpa_fipc_phychnl_ptr_t push_ptr_pa;
    struct dpa_fipc_clock_t clock; // dpa fipc的时钟配置
    struct dpa_fipc_channel *p_phychnl[DPA_FIPC_MAX_PIPES_NUM]; // 物理通道
    atomic_t dev_int_hdl_flag;
};

struct dpa_fipc_device_t *dpa_get_fipc_device(void);
int dpa_fipc_device_probe(void);
int dpa_fipc_device_dts_parse(struct device_node *p_dev_node);
int dpa_fipc_device_clk_en(struct dpa_fipc_clock_t *pclock);
int dpa_fipc_device_clk_dis(struct dpa_fipc_clock_t *pclock);
void dpa_fipc_opipe_en(void *base_va, struct dpa_fipc_pipe_config *p_opipe_config, u32 core_id);
void dpa_fipc_ipipe_en(void *base_va, struct dpa_fipc_pipe_config *p_ipipe_config, u32 core_id);
int dpa_fipc_pre_suspend(void);
void dpa_fipc_post_suspend(void);
void dpa_fipc_pre_resume(void);
void dpa_fipc_post_resume(void);
void dpa_fipc_do_dump(unsigned char *buf, u32 len);
void dpa_fipc_glb_ctrl_init(struct dpa_fipc_device_t *dev);
#endif