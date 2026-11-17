/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include "dpa_fipc_plat.h"
#include "dpa_fipc_device.h"
#include "dpa_fipc_driver.h"
#include "dpa_fipc_err_code.h"


int dpa_fipc_ipipe_status_check(const void *base_addr, u32 ipipe_id)
{
    int ret = 0;
    u32 loop = 0;
    union dpa_fipc_ipipe_stat i_state = { 0 };
    while (loop++ < DPA_FIPC_IPIPE_IDLE_WAIT) {
        i_state.val = dpa_fipc_ipipe_local_status(base_addr, ipipe_id);
        if (i_state.union_stru.is_idle == 0x1) {
            break;
        }
    }
    if (loop >= DPA_FIPC_IPIPE_IDLE_WAIT) {
        ret = DPA_FIPC_ERR_ETIME;
    }

    return ret;
}

int dpa_fipc_opipe_status_check(const void *base_addr, u32 opipe_id)
{
    int loop = 0;
    while (loop++ < DPA_FIPC_OPIPE_STOP_WAIT) {
        if (!dpa_fipc_opipe_stat_isbusy(base_addr, opipe_id)) {
            break;
        }
    }
    if (loop >= DPA_FIPC_OPIPE_STOP_WAIT) {
        return DPA_FIPC_ERR_ETIME;
    }
    return 0;
}

void dpa_fipc_opipe_startup(void *base_addr, struct dpa_fipc_pipe_config *opipe)
{
    writel_relaxed(DPA_FIPC_ADDR_LO(opipe->ptr_paddr),
        (void *)((char *)base_addr + DPA_FIPC_OPIPE_PTR_ADDR_L(opipe->id)));
    writel_relaxed(DPA_FIPC_ADDR_HI(opipe->ptr_paddr),
        (void *)((char *)base_addr + DPA_FIPC_OPIPE_PTR_ADDR_H(opipe->id)));

    writel_relaxed(DPA_FIPC_ADDR_LO(opipe->ringbuf_pa),
        (void *)((char *)base_addr + DPA_FIPC_OPIPE_BASE_ADDR_L(opipe->id)));
    writel_relaxed(DPA_FIPC_ADDR_HI(opipe->ringbuf_pa),
        (void *)((char *)base_addr + DPA_FIPC_OPIPE_BASE_ADDR_H(opipe->id)));

    writel_relaxed(opipe->depth, (void *)((char *)base_addr + DPA_FIPC_OPIPE_DEPTH(opipe->id)));

    writel_relaxed(opipe->wptr & 0xFFFF, (void *)((char *)base_addr + DPA_FIPC_OPIPE_WPTR(opipe->id)));
    writel_relaxed(opipe->rptr & 0xFFFF, (void *)((char *)base_addr + DPA_FIPC_OPIPE_RPTR(opipe->id)));

    writel_relaxed(opipe->pipe_uctrl.opipe_uctrl.val, (void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(opipe->id)));
}

void dpa_fipc_ipipe_startup(void *base_addr, struct dpa_fipc_pipe_config *ipipe)
{
    writel_relaxed(DPA_FIPC_ADDR_LO(ipipe->ptr_paddr),
        (void *)((char *)base_addr + DPA_FIPC_IPIPE_PTR_ADDR_L(ipipe->id)));
    writel_relaxed(DPA_FIPC_ADDR_HI(ipipe->ptr_paddr),
        (void *)((char *)base_addr + DPA_FIPC_IPIPE_PTR_ADDR_H(ipipe->id)));

    writel_relaxed(DPA_FIPC_ADDR_LO(ipipe->ringbuf_pa),
        (void *)((char *)base_addr + DPA_FIPC_IPIPE_BASE_ADDR_L(ipipe->id)));
    writel_relaxed(DPA_FIPC_ADDR_HI(ipipe->ringbuf_pa),
        (void *)((char *)base_addr + DPA_FIPC_IPIPE_BASE_ADDR_H(ipipe->id)));

    writel_relaxed(ipipe->depth, (void *)((char *)base_addr + DPA_FIPC_IPIPE_DEPTH(ipipe->id)));

    writel_relaxed(ipipe->wptr & 0xFFFF, (void *)((char *)base_addr + DPA_FIPC_IPIPE_WPTR(ipipe->id)));
    writel_relaxed(ipipe->rptr & 0xFFFF, (void *)((char *)base_addr + DPA_FIPC_IPIPE_RPTR(ipipe->id)));

    writel_relaxed(ipipe->pipe_uctrl.ipipe_uctrl.val, (void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(ipipe->id)));
}