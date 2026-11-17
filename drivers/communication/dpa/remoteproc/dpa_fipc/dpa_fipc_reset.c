/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <linux/interrupt.h>
#include "dpa_fipc_plat.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_device.h"
#include "dpa_fipc_err_code.h"
#include <dpa_reset.h>
#include "dpa_fipc_mntn.h"

struct dpa_fipc_rst_info g_dpa_fipc_rst_info;

#define DPA_FIPC_WAIT_INT_HDL_CNT 600

int dpa_fipc_opipe_rst_halt(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel)
{
    u32 opipe_wptr, opipe_id, query_times;

    if (pdev == NULL || pchannel == NULL) {
        return -1;
    }
    opipe_id = pchannel->pipe_id;
    if (!dpa_fipc_opipe_is_en(pdev->base_va, opipe_id)) {
        return 0;
    }
    dpa_fipc_opipe_abort_set(pdev->base_va, opipe_id);
    for (query_times = 0; query_times < DPA_FIPC_HALT_QUERY_WAIT_TIMES; query_times++) {
        if (DPA_FIPC_INT_WR_ABORT & dpa_fipc_opipe_devint_raw(pdev->base_va, opipe_id)) {
            break;
        }
    }
    if (query_times >= DPA_FIPC_HALT_QUERY_WAIT_TIMES) {
        dpa_fipc_err("fipc_opipe_rst_halt wait abort status timeout");
        dpa_fipc_opipe_devint_clr(pdev->base_va, opipe_id, DPA_FIPC_INT_WR_ABORT);
        dpa_fipc_opipe_local_dis(pdev->base_va, opipe_id);
        opipe_wptr = dpa_fipc_opipe_wptr_get(pdev->base_va, opipe_id);
        dpa_fipc_opipe_rptr_update(pdev->base_va, opipe_id, opipe_wptr);
        *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr) = opipe_wptr;
        for (query_times = 0; query_times < DPA_FIPC_HALT_QUERY_WAIT_TIMES; query_times++) {
            if (0x1 & dpa_fipc_opipe_local_status(pdev->base_va, opipe_id)) {
                break;
            }
        }
        if (query_times >= DPA_FIPC_HALT_QUERY_WAIT_TIMES) {
            return DPA_FIPC_ERR_HALT_QUERY_WAIT_TIMEOUT;
        }
        dpa_fipc_opipe_abort_clr(pdev->base_va, opipe_id);
        return 0;
    }
    dpa_fipc_opipe_devint_clr(pdev->base_va, opipe_id, DPA_FIPC_INT_WR_ABORT);
    dpa_fipc_opipe_local_dis(pdev->base_va, opipe_id);
    dpa_fipc_opipe_abort_clr(pdev->base_va, opipe_id);
    opipe_wptr = dpa_fipc_opipe_wptr_get(pdev->base_va, opipe_id);
    dpa_fipc_opipe_rptr_update(pdev->base_va, opipe_id, opipe_wptr);
    *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr) = opipe_wptr;
    for (query_times = 0; query_times < DPA_FIPC_HALT_QUERY_WAIT_TIMES; query_times++) {
        if (0x1 & dpa_fipc_opipe_local_status(pdev->base_va, opipe_id)) {
            break;
        }
    }
    if (query_times >= DPA_FIPC_HALT_QUERY_WAIT_TIMES) {
        return DPA_FIPC_ERR_HALT_QUERY_WAIT_TIMEOUT;
    }
    return 0;
}

void dpa_fipc_rst_halt_all_opipe(void)
{
    int ret = 0;
    u32 idx = 0;
    unsigned long flags;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = NULL;

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL|| pchannel->state != DPA_FIPC_CHN_OPEN) {
            continue;
        }
        // 避免dpa单独复位流程，与发送核间消息并发，通道状态不正确导致，导致单独复位失败，或者dpa下电后发送消息
        // 仅在进入单独复位处理的第一步添加保护，后续操作不需要
        spin_lock_irqsave(&pchannel->lock, flags);
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            pchannel->state = DPA_FIPC_CHN_ORESETTED;
            spin_unlock_irqrestore(&pchannel->lock, flags);
            continue;
        }
        ret = dpa_fipc_opipe_rst_halt(pdev, pchannel);
        if (ret) {
            dpa_fipc_err("dpa fipc pipe[%d] halt fail, ret 0x%x\n", pchannel->pipe_id, ret);
        }
        pchannel->state = DPA_FIPC_CHN_ORESETTED;
        spin_unlock_irqrestore(&pchannel->lock, flags);
    }
    return;
}

void dpa_fipc_rst_disable_all_ipipe(void)
{
    u32 idx = 0;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = NULL;

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_ORESETTED) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_SEND) {
            pchannel->state = DPA_FIPC_CHN_IRESETTING;
            continue;
        }
        dpa_fipc_ipipe_local_dis(pdev->base_va, pchannel->pipe_id);
        pchannel->state = DPA_FIPC_CHN_IRESETTING;
    }
}


int fipc_rst_check_all_ipipe(void)
{
    int ret = DPA_FIPC_OK;
    u32 idx = 0;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = NULL;

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_IRESETTING) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_SEND) {
            pchannel->state = DPA_FIPC_CHN_IRESETTED;
            continue;
        }
        ret = dpa_fipc_opipe_status_check(pdev->base_va, pchannel->pipe_id);
        if (ret == 0) {
            ret = dpa_fipc_ipipe_status_check(pdev->base_va, pchannel->pipe_id);
        }
        if (ret) {
            g_dpa_fipc_rst_info.last_failed_pipe_id = pchannel->pipe_id;
            dpa_fipc_mntn_print_pipe_regs(pdev, pchannel->pipe_id);
            return ret;
        }
        pchannel->state = DPA_FIPC_CHN_IRESETTED;
    }
    return 0;
}


void dpa_fipc_save_rwptr(struct dpa_fipc_device_t *pdev, struct dpa_fipc_channel *pchannel)
{
    if (pdev == NULL || pchannel == NULL) {
        return ;
    }
    if (pchannel->type == DPA_FIPC_CHNL_SEND) {
        pchannel->p_pipe_config->rptr = pchannel->p_pipe_config->wptr;
        dpa_fipc_opipe_rptr_update(pdev->base_va, pchannel->pipe_id, pchannel->p_pipe_config->rptr);
        *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr) = pchannel->p_pipe_config->rptr;
    }
    if (pchannel->type == DPA_FIPC_CHNL_RECV) {
        pchannel->p_pipe_config->wptr = pchannel->p_pipe_config->rptr;
        dpa_fipc_ipipe_wptr_update(pdev->base_va, pchannel->pipe_id, pchannel->p_pipe_config->wptr);
        *(volatile u32 *)(pchannel->p_pipe_config->ptr_vaddr) = pchannel->p_pipe_config->wptr;
    }
}

void dpa_fipc_rst_pipe_rptr_config(void)
{
    u32 idx = 0;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = NULL;

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_IRESETTED) {
            continue;
        }
        dpa_fipc_save_rwptr(pdev, pchannel);
        pchannel->state = DPA_FIPC_CHN_RESETTED;
    }
    return;
}

int dpa_fipc_int_check(void)
{
    struct dpa_fipc_irq_bundle *pmap;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    u32 int_pipe_status;
    u32 idx = 0;
    for (idx = 0; idx < DPA_FIPC_CPU_ID_MAX; idx++) {
        pmap = &pdev->maps[idx];
        if (pmap->pdev == NULL) {
            continue;
        }
        int_pipe_status =
            readl((void *)((char *)pdev->base_va + DPA_FIPC_CORE_IPIPE_INT_STAT0(pmap->cpu_id, DPA_FIPC_INT_OFFSET)));
        if (int_pipe_status) {
            return DPA_FIPC_ERR_IN_INT_IPIPE;
        }
        int_pipe_status =
            readl((void *)((char *)pdev->base_va + DPA_FIPC_CORE_OPIPE_INT_STAT0(pmap->cpu_id, DPA_FIPC_INT_OFFSET)));
        if (int_pipe_status) {
            return DPA_FIPC_ERR_IN_INT_OPIPE;
        }
    }
    return DPA_FIPC_OK;
}

int dpa_fipc_wait_int_hdl(void)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    u32 idx = DPA_FIPC_WAIT_INT_HDL_CNT;
    int ret = DPA_FIPC_ERR_IN_INT_CBK;
    while (idx--) {
        ret = dpa_fipc_int_check();
        if (ret != DPA_FIPC_OK) {
            continue;
        }
        if (atomic_read(&(pdev->dev_int_hdl_flag))) {
            ret = DPA_FIPC_ERR_IN_INT_CBK;
            continue;
        }
        return DPA_FIPC_OK;
    }

    return ret;
}

int bsp_dpa_fipc_chn_before_resetting(void)
{
    int ret;
    dpa_fipc_rst_halt_all_opipe();
    dpa_fipc_rst_disable_all_ipipe();
    ret = fipc_rst_check_all_ipipe();
    if (ret) {
        dpa_fipc_err("dpa reset check ipipe status failed, ret %d\n", ret);
        g_dpa_fipc_rst_info.last_failed_ret = ret;
        g_dpa_fipc_rst_info.last_before_rst_failed_tm = bsp_get_slice_value();
        return ret;
    }
    dpa_fipc_rst_pipe_rptr_config();

    ret = dpa_fipc_wait_int_hdl();
    if (ret) {
        dpa_fipc_err("dpa fipc wait int hdl timeout:%d\n", ret);
        g_dpa_fipc_rst_info.last_failed_ret = ret;
        g_dpa_fipc_rst_info.last_before_rst_failed_tm = bsp_get_slice_value();
    }
    g_dpa_fipc_rst_info.last_before_rst_tm = bsp_get_slice_value();
    return 0;
}

void dpa_fipc_chn_recovery(void)
{
    int idx;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    struct dpa_fipc_channel *pchannel = NULL;
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_RESETTED) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            dpa_fipc_ipipe_en(pdev->base_va, pchannel->p_pipe_config, pchannel->core_id);
        } else {
            dpa_fipc_opipe_en(pdev->base_va, pchannel->p_pipe_config, pchannel->core_id);
        }
        pchannel->state = DPA_FIPC_CHN_OPEN;
    }
}
int bsp_dpa_fipc_chn_after_resetting(void)
{
    int ret;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();

    // 开钟处理
    ret = dpa_fipc_device_clk_en(&pdev->clock);
    if (ret) {
        dpa_fipc_err("dpa_fipc_chn_after_resetting clk en failed!\n");
        g_dpa_fipc_rst_info.last_after_rst_failed_tm = bsp_get_slice_value();
        g_dpa_fipc_rst_info.last_failed_ret = DPA_FIPC_ERR_CLK_FAILED;
        return ret;
    }
    dpa_fipc_glb_ctrl_init(pdev);
    dpa_fipc_chn_recovery();
    g_dpa_fipc_rst_info.last_after_rst_tm = bsp_get_slice_value();
    return 0;
}

unsigned int dpa_fipc_rst_dump(unsigned char *buf, unsigned int len)
{
    unsigned int used_len = sizeof(struct dpa_fipc_rst_info);
    if (len < used_len) {
        return 0;
    }
    (void)memcpy_s(buf, len, &g_dpa_fipc_rst_info, used_len);
    return used_len;
}