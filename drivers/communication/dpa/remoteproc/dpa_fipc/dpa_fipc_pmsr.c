/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include "dpa_fipc_plat.h"
#include "dpa_fipc_device.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_err_code.h"
#include "dpa_fipc_mntn.h"

struct dpa_fipc_pmsr_info g_dpa_fipc_pmsr_info;

static int dpa_fipc_opipe_int_check (struct dpa_fipc_device_t *pdev, u32 cpu_id)
{
    u32 int_pipe_status;
    u32 idx;
    u32 pipes = 0;

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        if (pdev->p_phychnl[idx] == NULL || pdev->p_phychnl[idx]->state == DPA_FIPC_CHN_INIT ||
            pdev->p_phychnl[idx]->type != DPA_FIPC_CHNL_SEND) {
            continue;
        }
        pipes |= (1 << pdev->p_phychnl[idx]->pipe_id);
    }
    int_pipe_status =
        readl((void *)((char *)pdev->base_va + DPA_FIPC_CORE_OPIPE_INT_STAT0(cpu_id, DPA_FIPC_INT_OFFSET)));
    if (int_pipe_status & pipes) {
        return DPA_FIPC_ERR_IN_INT_OPIPE;
    }
    return 0;
}

static int dpa_fipc_ipipe_int_check (struct dpa_fipc_device_t *pdev, u32 cpu_id)
{
    u32 int_pipe_status;
    u32 idx;
    u32 pipes = 0;

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        if (pdev->p_phychnl[idx] == NULL || pdev->p_phychnl[idx]->state == DPA_FIPC_CHN_INIT ||
            pdev->p_phychnl[idx]->type != DPA_FIPC_CHNL_RECV) {
            continue;
        }
        pipes |= (1 << pdev->p_phychnl[idx]->pipe_id);
    }
    int_pipe_status =
        readl((void *)((char *)pdev->base_va + DPA_FIPC_CORE_IPIPE_INT_STAT0(cpu_id, DPA_FIPC_INT_OFFSET)));
    if (int_pipe_status & pipes) {
        return DPA_FIPC_ERR_IN_INT_IPIPE;
    }
    return 0;
}

static void dpa_fipc_pm_recovery(struct dpa_fipc_device_t *pdev)
{
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;
    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg_pm_recovery bad input\n");
        return ;
    }

    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state == DPA_FIPC_CHN_INIT || pchannel->state == DPA_FIPC_CHN_OPEN) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            dpa_fipc_ipipe_local_en(pdev->base_va, pchannel->pipe_id);
            pchannel->state = (u32)DPA_FIPC_CHN_OPEN;
        } else {
            dpa_fipc_opipe_local_en(pdev->base_va, pchannel->pipe_id);
            pchannel->state = (u32)DPA_FIPC_CHN_OPEN;
        }
    }
    return;
}

static int dpa_fipc_check_int(struct dpa_fipc_device_t *pdev)
{
    int i;
    int ret;
    struct dpa_fipc_irq_bundle *pmap;
    for (i = 0; i < DPA_FIPC_CPU_ID_MAX; i++) {
        pmap = &pdev->maps[i];
        if (pmap->pdev == NULL) {
            continue;
        }
        ret = dpa_fipc_opipe_int_check(pdev, pmap->cpu_id);
        ret |= dpa_fipc_ipipe_int_check(pdev, pmap->cpu_id);
        if (ret) {
            dpa_fipc_pm_recovery(pdev);
            return ret;
        }
    }
    if (atomic_read(&(pdev->dev_int_hdl_flag))) {
        dpa_fipc_pm_recovery(pdev);
        return DPA_FIPC_ERR_PIPE_INT_HDL;
    }
    return 0;
}

int dpa_fipc_pm_disable_all_opipe(struct dpa_fipc_device_t *pdev)
{
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;
    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg_pm_disable_all_opipe bad input\n");
        return DPA_FIPC_ERR_EIO;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_OPEN) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            pchannel->state = DPA_FIPC_CHN_OSUSPENDING;
            continue;
        }
        dpa_fipc_opipe_local_dis(pdev->base_va, pchannel->pipe_id);
        pchannel->state = DPA_FIPC_CHN_OSUSPENDING;
    }
    return 0;
}

int dpa_fipc_pm_checkpd_all_opipe(struct dpa_fipc_device_t *pdev)
{
    int ret;
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;
    if (pdev == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_OSUSPENDING) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            pchannel->state = DPA_FIPC_CHN_OSUSPENDED;
            continue;
        }
        ret = dpa_fipc_opipe_status_check(pdev->base_va, pchannel->pipe_id);
        if (ret) {
            g_dpa_fipc_pmsr_info.last_failed_pipe = pchannel->pipe_id;
            dpa_fipc_mntn_print_pipe_regs(pdev, pchannel->pipe_id);
            return ret;
        }
        pchannel->state = DPA_FIPC_CHN_OSUSPENDED;
    }
    return 0;
}

void dpa_fipc_pm_disable_all_ipipe(struct dpa_fipc_device_t *pdev)
{
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;
    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg_pm_disable_all_ipipe bad input\n");
        return ;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_OSUSPENDED) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_SEND) {
            pchannel->state = DPA_FIPC_CHN_ISUSPENDING;
            continue;
        }
        dpa_fipc_ipipe_local_dis(pdev->base_va, pchannel->pipe_id);
        pchannel->state = DPA_FIPC_CHN_ISUSPENDING;
    }
}

int dpa_fipc_pm_checkpd_all_ipipe(struct dpa_fipc_device_t *pdev)
{
    int ret;
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;
    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg_pm_checkpd_all_ipipe bad input\n");
        return DPA_FIPC_ERR_EIO;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_ISUSPENDING) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_SEND) {
            pchannel->state = DPA_FIPC_CHN_ISUSPENDED;
            continue;
        }
        ret = dpa_fipc_opipe_status_check(pdev->base_va, pchannel->pipe_id);
        if (ret == 0) {
            ret = dpa_fipc_ipipe_status_check(pdev->base_va, pchannel->pipe_id);
        }
        if (ret) {
            g_dpa_fipc_pmsr_info.last_failed_pipe = pchannel->pipe_id;
            dpa_fipc_mntn_print_pipe_regs(pdev, pchannel->pipe_id);
            return ret;
        }
        pchannel->state = DPA_FIPC_CHN_ISUSPENDED;
    }
    return 0;
}

int dpa_fipc_pm_check_pipe_empty(struct dpa_fipc_device_t *pdev)
{
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;

    union dpa_fipc_ipipe_stat i_state = { 0 };
    union dpa_fipc_opipe_stat o_state = { 0 };

    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg_pm_check_pipe_empty bad input\n");
        return DPA_FIPC_ERR_EIO;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != (u32)DPA_FIPC_CHN_ISUSPENDED) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            i_state.val = dpa_fipc_ipipe_local_status(pdev->base_va, pchannel->pipe_id);
            if (!i_state.union_stru.is_empty) {
                g_dpa_fipc_pmsr_info.last_failed_pipe = pchannel->pipe_id;
                dpa_fipc_mntn_print_pipe_regs(pdev, pchannel->pipe_id);
                return DPA_FIPC_ERR_PM_IPIPE_NOT_EMPTY;
            }
        } else {
            o_state.val = dpa_fipc_opipe_local_status(pdev->base_va, pchannel->pipe_id);
            if (!o_state.union_stru.is_empty) {
                g_dpa_fipc_pmsr_info.last_failed_pipe = pchannel->pipe_id;
                dpa_fipc_mntn_print_pipe_regs(pdev, pchannel->pipe_id);
                return DPA_FIPC_ERR_PM_OPIPE_NOT_EMPTY;
            }
        }
        pchannel->state = DPA_FIPC_CHN_SUSPENDED;
    }
    return 0;
}

static void dpa_fipc_pm_chn_save_config(struct dpa_fipc_device_t *pdev)
{
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;

    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg_pm_chn_save_config bad input\n");
        return ;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_SUSPENDED) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            pchannel->p_pipe_config->wptr = dpa_fipc_ipipe_wptr_get(pdev->base_va, pchannel->pipe_id);
        } else {
            pchannel->p_pipe_config->rptr = dpa_fipc_opipe_rptr_get(pdev->base_va, pchannel->pipe_id);
        }
    }
    return;
}

// 低功耗备份时不会备份bsp_dpa_fipc_channel_all_int_dis、bsp_dpa_fipc_channel_all_int_en修改的core int mask
int dpa_fipc_chn_suspend(struct dpa_fipc_device_t *pdev)
{
    int ret;
    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg suspend:bad pdev\n");
        return DPA_FIPC_ERR_EIO;
    }
    dpa_fipc_pm_disable_all_opipe(pdev);
    ret = dpa_fipc_pm_checkpd_all_opipe(pdev);
    if (ret) {
        dpa_fipc_pm_recovery(pdev);
        dpa_fipc_err("dpa_msg_pm_checkpd_all_opipe ret %d\n", ret);
        return ret;
    }

    dpa_fipc_pm_disable_all_ipipe(pdev);
    ret = dpa_fipc_pm_checkpd_all_ipipe(pdev);
    if (ret) {
        dpa_fipc_pm_recovery(pdev);
        dpa_fipc_err("dpa_msg_pm_checkpd_all_ipipe ret %d\n", ret);
        return ret;
    }

    ret = dpa_fipc_pm_check_pipe_empty(pdev);
    if (ret) {
        dpa_fipc_pm_recovery(pdev);
        dpa_fipc_err("dpa_msg_pm_check_pipe_empty ret %d\n", ret);
        return ret;
    }
    dpa_fipc_pm_chn_save_config(pdev);
    return 0;
}

// 低功耗恢复时不会恢复bsp_dpa_fipc_channel_all_int_dis、bsp_dpa_fipc_channel_all_int_en修改的core int mask
void dpa_fipc_chn_resume(struct dpa_fipc_device_t *pdev)
{
    u32 idx = 0;
    struct dpa_fipc_channel *pchannel = NULL;

    if (pdev == NULL) {
        dpa_fipc_err("dpa_msg resume:bad pdev\n");
        return;
    }
    for (idx = 0; idx < pdev->pipepair_cnt; idx++) {
        pchannel = pdev->p_phychnl[idx];
        if (pchannel == NULL || pchannel->state != DPA_FIPC_CHN_SUSPENDED) {
            continue;
        }
        if (pchannel->type == DPA_FIPC_CHNL_RECV) {
            dpa_fipc_ipipe_en(pdev->base_va, pchannel->p_pipe_config, pchannel->core_id);
        } else {
            dpa_fipc_opipe_en(pdev->base_va, pchannel->p_pipe_config, pchannel->core_id);
        }
        pchannel->state = DPA_FIPC_CHN_OPEN;
    }
    return;
}

int dpa_fipc_pre_suspend(void)
{
    int ret;
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (unlikely(pdev == NULL)) {
        dpa_fipc_err("dpa_msg resume:no dev\n");
        return DPA_FIPC_ERR_EIO;
    }
    ret = dpa_fipc_chn_suspend(pdev);
    if (ret) {
        g_dpa_fipc_pmsr_info.failed_cnt++;
        g_dpa_fipc_pmsr_info.last_failed_ret = ret;
        g_dpa_fipc_pmsr_info.last_pre_suspend_tm_failed = bsp_get_slice_value();
        return ret;
    }
    ret = dpa_fipc_check_int(pdev);
    if (ret) {
        g_dpa_fipc_pmsr_info.failed_cnt++;
        g_dpa_fipc_pmsr_info.last_failed_ret = ret;
        g_dpa_fipc_pmsr_info.last_pre_suspend_tm_failed = bsp_get_slice_value();
        return ret;
    }
    g_dpa_fipc_pmsr_info.failed_cnt = 0;
    g_dpa_fipc_pmsr_info.last_pre_suspend_tm = bsp_get_slice_value();
    return DPA_FIPC_OK;
}

void dpa_fipc_post_suspend(void)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (unlikely(pdev == NULL)) {
        dpa_fipc_err("dpa_msg resume:no dev\n");
        g_dpa_fipc_pmsr_info.last_post_suspend_tm_failed = bsp_get_slice_value();
        return;
    }

    (void)dpa_fipc_device_clk_dis(&pdev->clock);
    g_dpa_fipc_pmsr_info.last_post_suspend_tm = bsp_get_slice_value();
}

void dpa_fipc_pre_resume(void)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (unlikely(pdev == NULL)) {
        dpa_fipc_err("dpa_msg resume:no dev\n");
        g_dpa_fipc_pmsr_info.last_pre_resume_tm_failed = bsp_get_slice_value();
        return;
    }
    (void)dpa_fipc_device_clk_en(&pdev->clock);
    dpa_fipc_glb_ctrl_init(pdev);
    g_dpa_fipc_pmsr_info.last_pre_resume_tm = bsp_get_slice_value();
}

void dpa_fipc_post_resume(void)
{
    struct dpa_fipc_device_t *pdev = dpa_get_fipc_device();
    if (unlikely(pdev == NULL)) {
        dpa_fipc_err("dpa_msg resume:no dev\n");
        g_dpa_fipc_pmsr_info.last_post_resume_tm_failed = bsp_get_slice_value();
        return;
    }
    dpa_fipc_chn_resume(pdev);
    g_dpa_fipc_pmsr_info.last_post_resume_tm = bsp_get_slice_value();
}

unsigned int dpa_fipc_pmsr_dump(unsigned char *buf, unsigned int len)
{
    unsigned int used_len = sizeof(struct dpa_fipc_pmsr_info);
    if (len < used_len) {
        return 0;
    }
    (void)memcpy_s(buf, len, &g_dpa_fipc_pmsr_info, used_len);
    return used_len;
}

int bsp_dpa_fipc_suspend(void)
{
    int ret;
    ret = dpa_fipc_pre_suspend();
    if (ret) {
        dpa_fipc_err("dpa_fipc_pre_suspend faild: %d\n", ret);
        return ret;
    }
    return 0;
}

int bsp_dpa_fipc_resume(void)
{
    dpa_fipc_post_resume();
    return 0;
}