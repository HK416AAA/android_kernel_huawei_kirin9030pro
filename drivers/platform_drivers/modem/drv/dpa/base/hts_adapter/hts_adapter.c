/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#include "hts_adapter.h"
#include <bsp_slice.h>
#include <linux/interrupt.h>
#include <bsp_dt.h>

struct hts_adapter_ctx g_hts_adpt_ctx;
EXPORT_SYMBOL(g_hts_adpt_ctx);

void hts_adpt_clk_en(struct hts_adapter_ctx *ctx);
void hts_adpt_clk_dis(struct hts_adapter_ctx *ctx);
void hts_slv_adpt_e2i_cfg(enum hts_chn_id id);

int hts_adapter_sync_dpa_iomcu(struct hts_adpt_dst_ip_event *event_ctx)
{
    return 0;
}

int hts_event_sync_to_dst_ip(struct hts_adapter_ctx *ctx, enum hts_chn_id id)
{
    int ret;

    if (id >= HTS_CHN_MAX) {
        bsp_err("hts adpater chn id para error\n");
        return -1;
    }
    switch (id) {
        case HTS_CHN0_IOMCU_RULE0:
            ret = hts_adapter_sync_dpa_iomcu(&ctx->event_ctx[id].dst_ip_event);
            break;
        default:
            bsp_err("hts adapter chn id error:%s\n");
            return -1;
    }

    if (ret != 0) {
        bsp_err("hts adapter info sync failed, ret:%s\n", ret);
    } else {
        ctx->event_ctx[id].hts_adapter_status++;
    }

    return ret;
}

int hts_event_sync_dpa(struct hts_adapter_ctx *ctx, enum hts_chn_id id)
{
    struct hts_adpt_dpa_event hts_adpt_event;
    struct msg_addr dst;
    unsigned int ret;

    if (id >= HTS_CHN_MAX) {
        bsp_err("hts chn_id para error\n");
    }

    dst.core = MSG_CORE_DPA;
    dst.chnid = MSG_CHN_HTS;

    hts_adpt_event = ctx->event_ctx[id].dpa_event;
    ret = bsp_msg_sendto_dpa(g_hts_adpt_ctx.msg_chn_hdl, &dst, (void *)&hts_adpt_event, sizeof(struct hts_adpt_dpa_event));
    if (ret) {
        bsp_err("hts adapter sendto dpa failed!,ret:%d\n", ret);
        return -1;
    }

    return 0;
}
EXPORT_SYMBOL(hts_event_sync_dpa);

int hts_event_graph_sync(unsigned int id)
{
    int ret;

    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;

    if (id >= HTS_CHN_MAX) {
        bsp_err("hts adpater chn id para error\n");
    }

    ret = hts_event_sync_to_dst_ip(ctx, id);
    if (ret) {
        return ret;
    }

    hts_adpt_clk_en(ctx);

    hts_slv_adpt_e2i_cfg(id);

    ret = hts_event_sync_dpa(ctx, id);

    return 0;
}

static int hts_adapter_msg_rcv_proc(const struct msg_addr *src, void *msg, unsigned int len)
{
    return 0;
}

void hts_show_event_info(void)
{
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;
    unsigned int i;

    for (i = 0; i < HTS_CHN_MAX; i++) {
        bsp_err("hts adpt chn %u\n", ctx->event_ctx[i].dpa_event.chn_id);
        bsp_err("chn status: %u\n", ctx->event_ctx[i].hts_adapter_status);
        bsp_err("dpa src_event: %u\n", ctx->event_ctx[i].dpa_event.src_event);
        bsp_err("dpa dst_event: %u\n", ctx->event_ctx[i].dpa_event.dst_event);
        bsp_err("dpa dst_id: %u\n", ctx->event_ctx[i].dpa_event.dst_id);
        bsp_err("hts event uid: %u\n", ctx->event_ctx[i].dpa_event.uid);
        bsp_err("dst ip src_event: %u\n", ctx->event_ctx[i].dst_ip_event.src_event);
        bsp_err("dst ip dst_event: %u\n", ctx->event_ctx[i].dst_ip_event.dst_event);
    }
}

void hts_adpt_show_dbg(void)
{
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;

    bsp_err("clk enable:%u\n", ctx->pm_ctx.enable);
    bsp_err("resume_conut:%u\n", ctx->pm_ctx.resume_count);
    bsp_err("resume_ts:0x%x\n", ctx->pm_ctx.resume_ts);
    bsp_err("suspend_count:%u\n", ctx->pm_ctx.suspend_count);
    bsp_err("suspend_ts:%x\n", ctx->pm_ctx.suspend_ts);
    bsp_err("send_cnt:%u\n", ctx->dbg_ctx.send_cnt);
    bsp_err("recv_cnt:%u\n", ctx->dbg_ctx.recv_cnt);
    bsp_err("e2i_input_event_err:%u\n", ctx->dbg_ctx.e2i_input_event_err);
    bsp_err("e2i_cnt_event_err:%u\n", ctx->dbg_ctx.e2i_cnt_event_err);
    bsp_err("e2i_cnt_event:%u\n", ctx->dbg_ctx.e2i_cnt_event);
    bsp_err("last_recv_event:%u\n", ctx->dbg_ctx.last_recv_event);
    bsp_err("busy_cfg_err:%u\n", ctx->dbg_ctx.busy_cfg_err);
}

void hts_slv_adpt_e2i_cfg(enum hts_chn_id id)
{
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;
    unsigned int reg;

    if (id >= HTS_CHN_MAX) {
        bsp_err("hts adpt sync para err\n");
    }

    reg = ctx->event_ctx[id].dst_ip_event.dst_event;

    writel(reg, ctx->slv_reg + HTS_SLV_E2I_CFG_EVENT(id));
}

void hts_adpt_clk_en(struct hts_adapter_ctx *ctx)
{
    unsigned int reg = 0;

    reg |= HTS_MST_CLK_ENABLE;
    reg |= HTS_SLV_CLK_ENABLE;

    writel(reg, ctx->mdm_peri_crg);
    ctx->pm_ctx.enable = 1;
}

void hts_adpt_clk_dis(struct hts_adapter_ctx *ctx)
{
    unsigned int reg = 0;

    reg |= HTS_MST_CLK_DIS;
    reg |= HTS_SLV_CLK_DIS;

    writel(reg, ctx->mdm_peri_crg + MDMPERI_CRG_CLK_DIS_OFFSET);
    ctx->pm_ctx.enable = 0;
}

void hts_adpt_resume(void)
{
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;
    unsigned int i;

    hts_adpt_clk_en(ctx);

    for (i = 0; i < HTS_CHN_MAX; i++) {
        hts_slv_adpt_e2i_cfg(i);
    }
    ctx->pm_ctx.resume_count++;
    ctx->pm_ctx.resume_ts = bsp_get_slice_value();
}

void hts_adpt_suspend(void)
{
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;
    hts_adpt_clk_dis(ctx);

    ctx->pm_ctx.suspend_count++;
    ctx->pm_ctx.suspend_ts = bsp_get_slice_value();
}

void hts_adapter_reg_init(struct hts_adapter_ctx *ctx)
{
    ctx->mdm_peri_crg = ioremap((void *)(uintptr_t)MODEM_PERI_CRG_BASE, MODEM_PERI_CRG_LEN);
    ctx->mst_reg = ioremap((void *)(uintptr_t)HTS_MST_ADPT_BASE, HTS_ADPT_REG_LEN);
    ctx->slv_reg = ioremap((void *)(uintptr_t)HTS_SLV_ADPT_BASE, HTS_ADPT_REG_LEN);
}

int hts_adapter_msg_init(void)
{
    int ret = 0;
    struct msgchn_attr lite_attr = { 0 };

    bsp_msgchn_attr_init(&lite_attr);
    lite_attr.chnid = MSG_CHN_HTS;
    lite_attr.coremask = MSG_CORE_MASK(MSG_CORE_DPA);
    lite_attr.lite_notify = hts_adapter_msg_rcv_proc;
    ret = bsp_msg_lite_open(&g_hts_adpt_ctx.msg_chn_hdl, &lite_attr);
    if (unlikely(ret)) {
        bsp_err("hts adapter msg open err, ret=%d\n", ret);
    }

    return ret;
}

irqreturn_t hts_error_irq_handler(int irq, void *dev_id)
{
    unsigned int cnt_error_state;
    unsigned int wrong_evt;
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;

    cnt_error_state = readl(ctx->slv_reg + HTS_SLV_CNT_ERR_STAT);
    if (cnt_error_state != 0) {
        ctx->dbg_ctx.e2i_cnt_event = readl(ctx->slv_reg + HTS_SLV_CNT_ERR_EVENT);
        ctx->dbg_ctx.e2i_cnt_event_err++;
        bsp_err("hts slv adpt error isr, receive cnt_error_state:0x%x, cnt_error_event:%d\n", cnt_error_state, ctx->dbg_ctx.e2i_cnt_event);
        writel(cnt_error_state, (void *)(uintptr_t)(ctx->slv_reg + HTS_SLV_CNT_ERR_STAT));
    }

    wrong_evt = readl(ctx->slv_reg + HTS_SLV_WRONG_EVENT_STAT);
    if (wrong_evt != 0) {
        ctx->dbg_ctx.e2i_input_event_err++;
        ctx->dbg_ctx.last_recv_event = readl(ctx->slv_reg + HTS_SLV_LAST_EVENT);
        bsp_err("hts slv adpt error, receive wrong_event, last evt %d\n", ctx->dbg_ctx.last_recv_event);
        writel(wrong_evt, ctx->slv_reg + HTS_SLV_WRONG_EVENT_STAT);
    }

    return IRQ_HANDLED;
}

int hts_slv_adpt_register_intr(void)
{
    int ret;
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;

    device_node_s *np = bsp_dt_find_compatible_node(NULL, NULL, "hts_adapter_dpa");
    if (np == NULL) {
        return -1;
    }

    ctx->error_irq = bsp_dt_irq_parse_and_map(np, 0);
    if (ctx->error_irq < 0) {
        bsp_err("hts bsp_dt_irq_parse_and_map failed\n");
    }

    bsp_err("hts error irq:%u\n", ctx->error_irq);
    ret = request_irq(ctx->error_irq, hts_error_irq_handler, 0, "int_hts_slv_adapter_error", NULL);
    if (ret) {
        bsp_err("hts error irq request err %d\n", ret);
    }

    return ret;
}

int hts_adapter_init(void)
{
    struct hts_adapter_ctx *ctx = &g_hts_adpt_ctx;
    hts_adapter_reg_init(ctx);
    hts_adapter_msg_init();

    return 0;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(hts_adapter_init);
#endif