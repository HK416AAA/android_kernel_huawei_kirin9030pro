/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */
#ifndef DPA_HTS_ADAPTER_H
#define DPA_HTS_ADAPTER_H

#include <bsp_print.h>
#include <bsp_dpa.h>
#include <linux/delay.h>
#include <securec.h>
#include <mdrv_msg.h>
#include <bsp_msg.h>
#include <osl_bio.h>
#include <msg_id.h>

#undef THIS_MODU
#define THIS_MODU mod_dpa

#define HTS_SLV_ADPT_BASE 0xe6804000
#define HTS_MST_ADPT_BASE 0xe6803000
#define HTS_ADPT_REG_LEN 0x1000

#define MODEM_PERI_CRG_BASE 0xE6800000
#define MDMPERI_CRG_CLK_DIS_OFFSET 0x4
#define MODEM_PERI_CRG_LEN 0x1000

#define HTS_MST_CLK_ENABLE BIT(20)
#define HTS_SLV_CLK_ENABLE BIT(21)
#define HTS_MST_CLK_DIS BIT(20)
#define HTS_SLV_CLK_DIS BIT(21)

#define HTS_SLV_ERR_IRQ 514
#define HTS_SLV_CNT_ERR_STAT 0x80
#define HTS_SLV_CNT_ERR_MSK 0x84
#define HTS_SLV_CNT_ERR_EVENT 0x88
#define HTS_SLV_WRONG_EVENT_STAT 0x8c
#define HTS_SLV_WRONG_EVENT_MSK 0x90
#define HTS_SLV_EVENT_STAT 0x100
#define HTS_SLV_EVENT_MSK 0x104
#define HTS_SLV_ADPT_RECV_EVENT_CNT 0x18c
#define HTS_SLV_LAST_EVENT 0x190

#define HTS_SLV_E2I_CFG_EVENT(index) ((index) * 4)

enum hts_chn_id {
    HTS_CHN0_IOMCU_RULE0 = 0,
    HTS_CHN_MAX = 32
};

struct hts_adpt_dpa_event {
    unsigned int src_event;
    unsigned int dst_event;
    unsigned int dst_id;
    unsigned int chn_id;
    unsigned int uid;
};

struct hts_adpt_dst_ip_event {
    unsigned int src_event;
    unsigned int dst_event;
    unsigned int uid;
};

struct hts_adpt_event_ctx{
    char *name;
    struct hts_adpt_dpa_event dpa_event;
    struct hts_adpt_dst_ip_event dst_ip_event;
    unsigned int hts_adapter_status;
};

struct hts_adapter_dbg {
    unsigned int send_cnt;
    unsigned int recv_cnt;
    unsigned int e2i_input_event_err;
    unsigned int e2i_cnt_event_err;
    unsigned int e2i_cnt_event;
    unsigned int last_recv_event;
    unsigned int busy_cfg_err;
};

struct hts_adapter_pm_ctx {
    unsigned int enable;
    unsigned int suspend_count;
    unsigned int suspend_ts;
    unsigned int resume_count;
    unsigned int resume_ts;
};

struct hts_adapter_ctx {
    void *mdm_peri_crg;
    void *mst_reg;
    void *slv_reg;
    msg_chn_t msg_chn_hdl;
    unsigned int error_irq;
    struct hts_adpt_event_ctx event_ctx[HTS_CHN_MAX];
    struct hts_adapter_dbg dbg_ctx;
    struct hts_adapter_pm_ctx pm_ctx;
};

extern struct hts_adapter_ctx g_hts_adpt_ctx;

int hts_event_sync_dpa(struct hts_adapter_ctx *ctx, enum hts_chn_id id);
#endif