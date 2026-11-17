/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */

#include "dpa_fipc_plat.h"
#include "dpa_fipc_err_code.h"
#include "bsp_dpa_fipc.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_mntn.h"
#include "bsp_diag.h"

#define DPA_FIPC_REGS_INFO_MSGID (0x9f38202a)
// 底软上报使用的公共mid，不能修改
#define DPA_FIPC_DIAG_DRV_HDS_PID (0x8003)

// 与dpa fw上的维测上报使用相同的MSGID，结构体内容也保持一致
struct dpa_fipc_pipe_regs_info {
    unsigned int    pipe_id;
    unsigned int    owptr;
    unsigned int    orptr;
    unsigned int    o_int_mask;
    unsigned int    o_int_raw;
    unsigned int    o_ctrl;
    unsigned int    o_state;
    unsigned int    o_debug0;
    unsigned int    o_debug1;
    unsigned int    iwptr;
    unsigned int    irptr;
    unsigned int    i_int_mask;
    unsigned int    i_int_raw;
    unsigned int    i_ctrl;
    unsigned int    i_state;
};

static struct dpa_fipc_debug_info *g_dpa_dpa_fipc_debug_info = NULL;
static u32 g_dpa_dpa_fipc_debug_pipe_num = 0;

int dpa_fipc_debug_init(unsigned int pipe_num)
{
    unsigned int len = sizeof(struct dpa_fipc_debug_info) * pipe_num;
    g_dpa_dpa_fipc_debug_pipe_num = pipe_num;
    g_dpa_dpa_fipc_debug_info = (struct dpa_fipc_debug_info *)kmalloc(len, GFP_KERNEL);
    if (g_dpa_dpa_fipc_debug_info != NULL) {
        (void)memset_s(g_dpa_dpa_fipc_debug_info, len, 0, len);
    } else {
        return DPA_FIPC_ERR_ENOMEM;
    }

    return DPA_FIPC_OK;
}

void dpa_fipc_debug_info_update_send(unsigned int pipe_id, int ret)
{
    static struct dpa_fipc_debug_info *pdebug;
    if (g_dpa_dpa_fipc_debug_info == NULL) {
        return;
    }
    pdebug = g_dpa_dpa_fipc_debug_info + pipe_id;
    pdebug->last_send_stamp = bsp_get_slice_value();
    pdebug->last_send_errno = ret;

}

void dpa_fipc_debug_info_update_send_done(unsigned int pipe_id)
{
    static struct dpa_fipc_debug_info *pdebug;
    if (g_dpa_dpa_fipc_debug_info == NULL) {
        return;
    }
    pdebug = g_dpa_dpa_fipc_debug_info + pipe_id;
    pdebug->last_send_done_stamp = bsp_get_slice_value();
}

void dpa_fipc_debug_info_update_recv(unsigned int pipe_id)
{
    static struct dpa_fipc_debug_info *pdebug;
    if (g_dpa_dpa_fipc_debug_info == NULL) {
        return;
    }
    pdebug = g_dpa_dpa_fipc_debug_info + pipe_id;
    pdebug->last_recv_stamp = bsp_get_slice_value();
}

// 记录最大的收发时间diff；超过时间阈值的计数；
int dpa_fipc_debug(void) {
    unsigned int pipe_id = 0;
    struct dpa_fipc_debug_info *pdebug;
    if (g_dpa_dpa_fipc_debug_info == NULL) {
        return DPA_FIPC_ERR_EIO;
    }
    for (pipe_id = 0; pipe_id < g_dpa_dpa_fipc_debug_pipe_num; pipe_id++) {
        pdebug = g_dpa_dpa_fipc_debug_info + pipe_id;
        dpa_fipc_print("pipe_id: 0x%x\r\n", pipe_id);
        dpa_fipc_print("  last_send: tm 0x%x, err 0x%x\r\n", pdebug->last_send_stamp, pdebug->last_send_errno);
        dpa_fipc_print("  last_send_done: tm 0x%x\r\n", pdebug->last_send_done_stamp);
        dpa_fipc_print("  last_recv: tm 0x%x\r\n", pdebug->last_recv_stamp);
    }
    return DPA_FIPC_OK;
}

unsigned int dpa_fipc_chn_send_recv_tm_dump(unsigned char *buf, unsigned int len)
{
    unsigned int used_len = sizeof(struct dpa_fipc_debug_info) * g_dpa_dpa_fipc_debug_pipe_num;
    if (len < used_len || g_dpa_dpa_fipc_debug_info == NULL) {
        return 0;
    }
    (void)memcpy_s(buf, used_len, g_dpa_dpa_fipc_debug_info, used_len);
    return used_len;
}

void dpa_fipc_mntn_report_pipe_regs(struct dpa_fipc_device_t *pdev, unsigned int pipe_id)
{
    struct dpa_fipc_pipe_regs_info pipe_regs;

    if (unlikely(pdev == NULL || pipe_id >= pdev->pipepair_cnt)) {
        return ;
    }

    pipe_regs.pipe_id = pipe_id;

    pipe_regs.owptr = dpa_fipc_opipe_wptr_get(pdev->base_va, pipe_id);
    pipe_regs.orptr = dpa_fipc_opipe_rptr_get(pdev->base_va, pipe_id);
    pipe_regs.o_int_mask = dpa_fipc_opipe_devint_mask(pdev->base_va, pipe_id);
    pipe_regs.o_int_raw = dpa_fipc_opipe_devint_raw(pdev->base_va, pipe_id);
    pipe_regs.o_ctrl = dpa_fipc_opipe_ctrl(pdev->base_va, pipe_id);
    pipe_regs.o_state = dpa_fipc_opipe_local_status(pdev->base_va, pipe_id);
    pipe_regs.o_debug0 = dpa_fipc_opipe_debug0(pdev->base_va, pipe_id);
    pipe_regs.o_debug1 = dpa_fipc_opipe_debug1(pdev->base_va, pipe_id);

    pipe_regs.iwptr = dpa_fipc_ipipe_wptr_get(pdev->base_va, pipe_id);
    pipe_regs.irptr = dpa_fipc_ipipe_rptr_get(pdev->base_va, pipe_id);
    pipe_regs.i_int_mask = dpa_fipc_ipipe_devint_mask(pdev->base_va, pipe_id);
    pipe_regs.i_int_raw = dpa_fipc_ipipe_devint_raw(pdev->base_va, pipe_id);
    pipe_regs.i_ctrl = dpa_fipc_ipipe_ctrl(pdev->base_va, pipe_id);
    pipe_regs.i_state = dpa_fipc_ipipe_local_status(pdev->base_va, pipe_id);
    bsp_dpa_diag_trans_report(DPA_FIPC_REGS_INFO_MSGID, DPA_FIPC_DIAG_DRV_HDS_PID, (unsigned char *)&pipe_regs, sizeof(pipe_regs));
}

void dpa_fipc_mntn_print_pipe_regs(struct dpa_fipc_device_t *pdev, unsigned int pipe_id)
{
    struct dpa_fipc_pipe_regs_info pipe_regs;

    if (unlikely(pdev == NULL || pipe_id >= pdev->pipepair_cnt)) {
        return;
    }

    pipe_regs.owptr = dpa_fipc_opipe_wptr_get(pdev->base_va, pipe_id);
    pipe_regs.orptr = dpa_fipc_opipe_rptr_get(pdev->base_va, pipe_id);
    pipe_regs.o_int_mask = dpa_fipc_opipe_devint_mask(pdev->base_va, pipe_id);
    pipe_regs.o_int_raw = dpa_fipc_opipe_devint_raw(pdev->base_va, pipe_id);

    pipe_regs.iwptr = dpa_fipc_ipipe_wptr_get(pdev->base_va, pipe_id);
    pipe_regs.irptr = dpa_fipc_ipipe_rptr_get(pdev->base_va, pipe_id);
    pipe_regs.i_int_mask = dpa_fipc_ipipe_devint_mask(pdev->base_va, pipe_id);
    pipe_regs.i_int_raw = dpa_fipc_ipipe_devint_raw(pdev->base_va, pipe_id);
    dpa_fipc_err("pipe[0x%x]: o[0x%x 0x%x 0x%x 0x%x] i[0x%x 0x%x 0x%x 0x%x]\r\n", pipe_id, pipe_regs.owptr,
        pipe_regs.orptr, pipe_regs.o_int_mask, pipe_regs.o_int_raw, pipe_regs.iwptr, pipe_regs.irptr,
        pipe_regs.i_int_mask, pipe_regs.i_int_raw);
}
