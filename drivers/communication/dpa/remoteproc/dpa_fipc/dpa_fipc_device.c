/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

#include <linux/interrupt.h>
#include "bsp_dpa.h"
#include "dpa_fipc_device.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_err_code.h"
#include "dpa_fipc_plat.h"
#include "bsp_dpa_fipc.h"
#include "dpa_fipc_mntn.h"
#include "bsp_dump.h"
#ifdef CONFIG_LIBLINUX
#include <liblinux/pal.h>
#endif

static struct dpa_fipc_device_t g_dpa_fipc_device;


int dpa_fipc_device_clk_en(struct dpa_fipc_clock_t *pclock)
{
    if (pclock == NULL || pclock->dev_crg_base_va == NULL) {
        dpa_fipc_err("bad dpa fip clk, en failed!\n");
        return DPA_FIPC_ERR_EIO;
    }
    writel(pclock->dev_crg_clk_mask, (void *)((char *)(pclock->dev_crg_base_va) + pclock->dev_crg_clk_en_offset));
    return 0;
}

int dpa_fipc_device_clk_dis(struct dpa_fipc_clock_t *pclock)
{
    if (pclock == NULL || pclock->dev_crg_base_va == NULL) {
        dpa_fipc_err("bad dpa fip clk, en failed!\n");
        return DPA_FIPC_ERR_EIO;
    }
    writel(pclock->dev_crg_clk_mask, (void *)((char *)(pclock->dev_crg_base_va) + pclock->dev_crg_clk_dis_offset));
    return 0;
}

static void dpa_fipc_ipipe_irq_handler(struct dpa_fipc_device_t *pdev, u32 ipipe_id)
{
    u32 int_level_status;
    dpa_fipc_eventinfo eventinfo;
    struct dpa_fipc_channel *pchannel = NULL;

    if (ipipe_id >= pdev->pipepair_cnt) {
        dpa_fipc_crit("fipc_ipipe_irq_handler bad ipipe_id 0x%x\n", ipipe_id);
        return;
    }
    pchannel = pdev->p_phychnl[ipipe_id];
    if (pchannel == NULL) {
        dpa_fipc_crit("fipc_ipipe_irq_handler ipipe_id 0x%x no channel\n", ipipe_id);
        return;
    }

    int_level_status = dpa_fipc_ipipe_devint_stat(pdev->base_va, ipipe_id);
    if (int_level_status == 0) {
        return;
    }
    dpa_fipc_ipipe_devint_clr(pdev->base_va, ipipe_id, int_level_status);
    if (DPA_FIPC_INT_RD_DATA_ARV & int_level_status) {
        dpa_fipc_debug_info_update_recv(ipipe_id);
        if (pchannel->cbk) {
            eventinfo.data_event.chnid = ipipe_id;
            eventinfo.data_event.chn_hdl = (dpa_fipc_chn_t)pchannel;
            pchannel->cbk(DPA_FIPC_EVENT_DATA_ARRV, pchannel->cbk_arg, &eventinfo);
        }
    }
    if (DPA_FIPC_INT_RD_ARV_TIMEOUT & int_level_status) {
        dpa_fipc_debug_info_update_recv(ipipe_id);
        if (pchannel->cbk) {
            eventinfo.data_event.chnid = ipipe_id;
            eventinfo.data_event.chn_hdl = (dpa_fipc_chn_t)pchannel;
            pchannel->cbk(DPA_FIPC_EVENT_RECV_TIMEOUT, pchannel->cbk_arg, &eventinfo);
        }
    }
    if (DPA_FIPC_INT_RD_OVERFLOW & int_level_status) {
        dpa_fipc_debug_info_update_recv(ipipe_id);
        if (pchannel->cbk) {
            eventinfo.data_event.chnid = ipipe_id;
            eventinfo.data_event.chn_hdl = (dpa_fipc_chn_t)pchannel;
            pchannel->cbk(DPA_FIPC_EVENT_RECV_FLOWUP, pchannel->cbk_arg, &eventinfo);
        }
    }
    if (DPA_FIPC_INT_RD_UNDERFLOW & int_level_status) { // 当前不使用该中断，报中断后清除
        dpa_fipc_ipipe_devint_dis(pdev->base_va, ipipe_id, DPA_FIPC_INT_RD_UNDERFLOW);
    }
    return;
}

static void dpa_fipc_opipe_irq_handler(struct dpa_fipc_device_t *pdev, u32 opipe_id)
{
    u32 int_level_status;
    dpa_fipc_eventinfo eventinfo;
    struct dpa_fipc_channel *pchannel = NULL;
    if (opipe_id >= pdev->pipepair_cnt) {
        dpa_fipc_crit("dpa_fipc_opipe_irq_handler bad opipe_id 0x%x\n", opipe_id);
        return;
    }
    /* 需要判断这是个PIPE是不是自己可以直接访问的PIPE,
    比如FIPC_INT_RD_PIPE_WAKEUP可能是影子报过来的 */
    pchannel = pdev->p_phychnl[opipe_id];
    if (pchannel == NULL) {
        dpa_fipc_crit("dpa_fipc_opipe_irq_handler opipe_id 0x%x no channel\n", opipe_id);
        return;
    }
    int_level_status = dpa_fipc_opipe_devint_stat(pdev->base_va, opipe_id);
    if (int_level_status == 0) {
        return;
    }
    dpa_fipc_opipe_devint_clr(pdev->base_va, opipe_id, int_level_status);
    if (DPA_FIPC_INT_WR_DATA_DONE & int_level_status) {
        dpa_fipc_trace("DPA_FIPC_INT_WR_DATA_DONE detected for opipe_id 0x%x \n", opipe_id);
        dpa_fipc_opipe_devint_clr(pdev->base_va, opipe_id, DPA_FIPC_INT_WR_DATA_DONE);
        dpa_fipc_debug_info_update_send_done(opipe_id);
        if ( pchannel->cbk ) {
            eventinfo.data_event.chnid = opipe_id;
            eventinfo.data_event.chn_hdl = (dpa_fipc_chn_t)pchannel;
            pchannel->cbk(DPA_FIPC_EVENT_SEND_DONE, pchannel->cbk_arg, &eventinfo);
            return;
        }
        dpa_fipc_warn("dpa_fipc_opipe_irq_handler opipe_id 0x%x no send-done cbk\n", opipe_id);
    }
    if (DPA_FIPC_INT_WR_UNDERFLOW & int_level_status) {
        dpa_fipc_trace("DPA_FIPC_EVENT_SEND_FLOWDN detected for opipe_id 0x%x \n", opipe_id);
        if (pchannel->cbk) {
            eventinfo.data_event.chnid = opipe_id;
            eventinfo.data_event.chn_hdl = (dpa_fipc_chn_t)pchannel;
            pchannel->cbk(DPA_FIPC_EVENT_SEND_FLOWDN, pchannel->cbk_arg, &eventinfo);
            return;
        }
    }
    return;
}


static inline u32 dpa_fipc_ffs(u32 num)
{
    u32 i;
    for (i = 0; i < DPA_FIPC_PIPE_CNT_PER_REG; i++) {
        if ((num >> i) & 1) {
            return i + 1;
        }
    }
    return 0;
}

irqreturn_t dpa_fipc_localrecv_handler(int irq_no, void *arg)
{
    u32 int_pipe_status;
    u32 pipe_id;
    struct dpa_fipc_irq_bundle *bundle = (struct dpa_fipc_irq_bundle *)arg;
    struct dpa_fipc_device_t *pdev = bundle->pdev;

    atomic_inc(&(pdev->dev_int_hdl_flag));
    int_pipe_status =
        readl((void *)((char *)pdev->base_va + DPA_FIPC_CORE_IPIPE_INT_STAT0(bundle->cpu_id, DPA_FIPC_INT_OFFSET)));
    if (int_pipe_status) {
        pipe_id = dpa_fipc_ffs(int_pipe_status);
        dpa_fipc_ipipe_irq_handler(pdev, pipe_id - 1);
        atomic_dec(&(pdev->dev_int_hdl_flag));
        return IRQ_HANDLED;
    }
    atomic_dec(&(pdev->dev_int_hdl_flag));
    return IRQ_NONE;
}

irqreturn_t dpa_fipc_localsend_handler(int irq_no, void *arg)
{
    u32 int_pipe_status;
    u32 pipe_id;
    struct dpa_fipc_irq_bundle *bundle = (struct dpa_fipc_irq_bundle *)arg;
    struct dpa_fipc_device_t *pdev = bundle->pdev;

    atomic_inc(&(pdev->dev_int_hdl_flag));
    int_pipe_status =
        readl((void *)((char *)pdev->base_va + DPA_FIPC_CORE_OPIPE_INT_STAT0(bundle->cpu_id, DPA_FIPC_INT_OFFSET)));
    if (int_pipe_status) {
        pipe_id = dpa_fipc_ffs(int_pipe_status);
        dpa_fipc_opipe_irq_handler(pdev, pipe_id - 1);
        atomic_dec(&(pdev->dev_int_hdl_flag));
        return IRQ_HANDLED;
    }
    atomic_dec(&(pdev->dev_int_hdl_flag));
    return IRQ_NONE;
}

int dpa_fipc_irqs_local_init(struct dpa_fipc_device_t *pdev)
{
    u32 idx;
    int uret;
    int ret = 0;
    struct dpa_fipc_irq_bundle *bundle = NULL;
    if (pdev == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    for (idx = 0; idx < DPA_FIPC_CPU_ID_MAX; idx++) {
        bundle = &pdev->maps[idx];
        if (bundle->pdev == NULL) {
            continue;
        }
        bundle->cpu_id = idx;
        uret = request_irq(bundle->irq[0x1], dpa_fipc_localrecv_handler, 0, "dpa_fipc_irq_lrecv", (void *)bundle);
        uret |= request_irq(bundle->irq[0x0], dpa_fipc_localsend_handler, 0, "dpa_fipc_irq_lsend", (void *)bundle);
        if (uret) {
            dpa_fipc_err("dpa_msg_irqs_local_init req irq[%d][%d] failed[%d]!\n", bundle->irq[0x0], bundle->irq[0x1], uret);
            ret = DPA_FIPC_ERR_IRQ_FAILED;
        }
        enable_irq_wake(bundle->irq[0x0]);
        enable_irq_wake(bundle->irq[0x1]);
#ifdef CONFIG_LIBLINUX
        if (bundle->hwirq_ipipe) {
            ret = liblinux_pal_local_irq_setfast(bundle->hwirq_ipipe, 1);
            if (ret) {
                dpa_fipc_err("liblinux_pal_local_irq_setfast hwirq_ipipe[%d] failed[%d]!\n", bundle->hwirq_ipipe, ret);
                ret = DPA_FIPC_ERR_IRQ_FAILED;
            }
        }
        if (bundle->hwirq_opipe) {
            ret = liblinux_pal_local_irq_setfast(bundle->hwirq_opipe, 1);
            if (ret) {
                dpa_fipc_err("liblinux_pal_local_irq_setfast hwirq_opipe[%d] failed[%d]!\n", bundle->hwirq_opipe, ret);
                ret = DPA_FIPC_ERR_IRQ_FAILED;
            }
        }
#endif
    }
    return ret;
}

struct dpa_fipc_device_t *dpa_get_fipc_device(void)
{
    return &g_dpa_fipc_device;
}

void dpa_fipc_glb_ctrl_init(struct dpa_fipc_device_t *dev)
{
    unsigned int reg;
    void *base_addr = dev->base_va;
    reg = readl((void *)((char *)base_addr + DPA_FIPC_GLB_CTRL));
    reg = reg | DPA_FIPC_GLB_CTRL_SR_PUSH | DPA_FIPC_GLB_CTRL_CLK_AUTO;
    writel(reg, (void *)((char *)base_addr + DPA_FIPC_GLB_CTRL));
}

#define DPA_FIPC_DUMP_SIZE (0x600)
struct dpa_ficc_mem_info_t {
    unsigned char *addr;
    unsigned int len;
};
struct dpa_ficc_mem_info_t g_dpa_fipc_dump_mem_info;

void dpa_fipc_dump(void)
{
    dpa_fipc_do_dump(g_dpa_fipc_dump_mem_info.addr, g_dpa_fipc_dump_mem_info.len);
}

int dpa_fipc_dump_init(void)
{
    int ret;
    g_dpa_fipc_dump_mem_info.len = DPA_FIPC_DUMP_SIZE;
    g_dpa_fipc_dump_mem_info.addr =
        bsp_dpa_dump_register_field(OM_DPAHOST_FIELD_DPA_FIPC, "DPA_FIPC", DPA_FIPC_DUMP_SIZE, 0);
    if (g_dpa_fipc_dump_mem_info.addr == NULL) {
        dpa_fipc_err("ficc_dump_init space register failed!\n");
        return DPA_FIPC_ERR_ENOMEM;
    }
    (void)memset_s(g_dpa_fipc_dump_mem_info.addr, g_dpa_fipc_dump_mem_info.len, 0, g_dpa_fipc_dump_mem_info.len);

    ret = bsp_dpa_dump_register_hook("DPA_FIPC", dpa_fipc_dump);
    if (ret == -1) {
        dpa_fipc_err("dpa_fipc_dump_init register hook failed, ret=%d\n", ret);
        return DPA_FIPC_ERR_ESRCH;
    }
    return DPA_FIPC_OK;
}

int dpa_fipc_device_probe(void)
{
    int ret = 0;

    g_dpa_fipc_device.push_ptr_va = (u32 *)dpa_fipc_alloc_coherent(sizeof(u32) * DPA_FIPC_MAX_PIPES_NUM,
        &g_dpa_fipc_device.push_ptr_pa, sizeof(u32));
    if (g_dpa_fipc_device.push_ptr_va == NULL) {
        return DPA_FIPC_ERR_ENOMEM;
    }

    ret = dpa_fipc_debug_init(g_dpa_fipc_device.pipepair_cnt);
    if (ret) {
        dpa_fipc_err("dpa_fipc_debug_init failed!\n");
        return ret;
    }

    // enable clock
    ret = dpa_fipc_device_clk_en(&g_dpa_fipc_device.clock);
    if (ret) {
        dpa_fipc_err("dpa fipc clk en failed!\n");
        return ret;
    }

    dpa_fipc_glb_ctrl_init(&g_dpa_fipc_device);

    // enable irq
    ret = dpa_fipc_irqs_local_init(&g_dpa_fipc_device);
    if (ret) {
        dpa_fipc_err("dpa_fipc_irqs_local_init failed!\n");
        return ret;
    }

    ret = dpa_fipc_dump_init();
    if (ret) {
        dpa_fipc_err("dpa_fipc_dump_init failed!\n");
        return ret;
    }

    return ret;
}