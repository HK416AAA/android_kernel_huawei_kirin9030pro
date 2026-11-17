/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <securec.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <bsp_dpa_ipc.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>
#include <bsp_rproc.h>
#include <dpa_reset.h>
#include "sys_reset.h"

#define reset_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)

sys_reset_ctrl_s g_sys_reset_ctrl;

static void sys_reset_dump_item_rec(sys_reset_dump_item_s *dump_base, unsigned int type, unsigned int result, unsigned int arg)
{
    sys_reset_dump_item_s *dump = NULL;
    if (unlikely((g_sys_reset_ctrl.dump_addr == 0) || ((uintptr_t)dump_base < g_sys_reset_ctrl.dump_addr) ||
        ((uintptr_t)dump_base >= g_sys_reset_ctrl.dump_addr + SYS_RESET_DUMP_SIZE))) {
        return;
    }
    dump = dump_base + type;
    dump->dump_type = type;
    dump->result = result;
    dump->arg = arg;
    dump->slice = bsp_get_slice_value();
}

static uintptr_t sys_reset_get_dump_addr(unsigned int sys_type, unsigned int ops_type)
{
    return (g_sys_reset_ctrl.dump_addr + (sys_type * DPA_SYS_RESET_OPS_TYPE_MAX + ops_type) * SYS_RESET_DUMP_SINGLE_HANDLE_SIZE);
}

static int dpa_sys_reset_handle(unsigned char sys_type, unsigned char ops_type)
{
    unsigned long time;
    dpa_ipc_res_id_e ipc_id;
    int ret;
    sys_reset_dump_item_s *dump_base = (sys_reset_dump_item_s *)(uintptr_t)sys_reset_get_dump_addr(sys_type, ops_type);
    reset_err("dpa_sys_reset sys %d ops %d start, 0x%x.\n", sys_type, ops_type, bsp_get_slice_value());
    sys_reset_dump_item_rec(dump_base, SYS_RESET_HANDLE_START, SYS_RESET_DUMP_PASS, sys_type);
    g_sys_reset_ctrl.sys_ctrl[sys_type].status = SYS_RESET_DPA_FW_DOING;
    ipc_id = (ops_type == DPA_SYS_RESET_OPS_BEFORE_TYPE) ? DPA_IPC_DPA_INT_SRC_ACPU_BEFORE_MDM_RESETTING :
        DPA_IPC_DPA_INT_SRC_ACPU_AFTER_MDM_RESETTING;
    ret = bsp_dpa_ipc_send(ipc_id);
    if (ret) {
        reset_err("dpa_sys_reset sys %d ops %d ipc 0x%x req fail,0x%x.\n", sys_type, ops_type, (unsigned int)ipc_id, ret);
        sys_reset_dump_item_rec(dump_base, SYS_RESET_IPC_REQ, SYS_RESET_DUMP_FAIL, ret);
        return ret;
    }
    sys_reset_dump_item_rec(dump_base, SYS_RESET_IPC_REQ, SYS_RESET_DUMP_PASS, (unsigned int)ipc_id);
    reset_err("dpa_sys_reset sys %d ops send ipc 0x%x  %d ok, 0x%x.\n", sys_type, ops_type, ipc_id, bsp_get_slice_value());
    time = wait_for_completion_timeout(&(g_sys_reset_ctrl.sys_ctrl[sys_type].wait_completion),
        msecs_to_jiffies(SYS_RESET_FW_TIMEOUT));
    if (time == 0) {
        sys_reset_dump_item_rec(dump_base, SYS_RESET_WAIT_DONE, SYS_RESET_DUMP_FAIL, SYS_RESET_FW_TIMEOUT);
        reset_err("dpa_sys_reset sys %d ops %d fw timeout.\n", sys_type, ops_type);
        return SYS_RESET_ERR_GEN(SYS_RESET_MSG_WAIT_FW_TIMEOUT);
    }
    sys_reset_dump_item_rec(dump_base, SYS_RESET_WAIT_DONE, SYS_RESET_DUMP_PASS, (unsigned int)time);
    reset_err("dpa_sys_reset sys %d ops %d ok, 0x%x.\n", sys_type, ops_type, bsp_get_slice_value());
    return 0;
}

int dpa_sys_reset(unsigned char sys_type, unsigned char ops_type)
{
    int ret = 0;
    int reset_ret;
    sys_reset_dump_item_s *dump_base = (sys_reset_dump_item_s *)(uintptr_t)sys_reset_get_dump_addr(sys_type, ops_type);

    ret = bsp_rproc_dpa_get_stat();
    if (ret == RPROC_OFFLINE || ret == RPROC_CRASHED) {
        reset_err("dpa_sys_reset dpa sta:%d, 0x%x.\n", ret, bsp_get_slice_value());
        return 0;
    }

    if ((sys_type >= RESET_TYPE_MAX) || (ops_type >= DPA_SYS_RESET_OPS_TYPE_MAX)) {
        reset_err("dpa sys reset invalid input: sys: %d, ops: %d.\n", sys_type, ops_type);
        return SYS_RESET_ERR_GEN(SYS_RESET_INPUT_ERR);
    }
    sys_reset_dump_item_rec(dump_base, SYS_RESET_GET_WAKELOCK, SYS_RESET_DUMP_PASS, ops_type);
    reset_ret = dpa_sys_reset_handle(sys_type, ops_type);
    sys_reset_dump_item_rec(dump_base, SYS_RESET_RELEASE_WAKELOCK, SYS_RESET_DUMP_PASS, ops_type);
    return reset_ret;
}

static int sys_reset_ipc_cb(unsigned int ops_type)
{
    unsigned int sys_type = SYS_MODEM_RESET;
    sys_reset_dump_item_s *dump_base = (sys_reset_dump_item_s *)(uintptr_t)sys_reset_get_dump_addr(sys_type, ops_type);
    sys_reset_dump_item_rec(dump_base, SYS_RESET_IPC_START, SYS_RESET_DUMP_PASS, ops_type);
    g_sys_reset_ctrl.sys_ctrl[sys_type].result = 0; // 使用IPC暂时获取不到fw执行结果, fw失败不会发IPC，host等超时退出
    g_sys_reset_ctrl.sys_ctrl[sys_type].status = SYS_RESET_DPA_FW_FINSH;
    complete(&(g_sys_reset_ctrl.sys_ctrl[sys_type].wait_completion));
    reset_err("dpa_sys_reset sys %d ops %d recv ipc ok, result %d.\n", sys_type, ops_type, g_sys_reset_ctrl.sys_ctrl[sys_type].result);
    sys_reset_dump_item_rec(dump_base, SYS_RESET_DMI_IPC_SET_FLAG, SYS_RESET_DUMP_PASS, g_sys_reset_ctrl.sys_ctrl[sys_type].result);
    return 0;
}

int sys_reset_before_ipc_cb(void *arg)
{
    return sys_reset_ipc_cb(DPA_SYS_RESET_OPS_BEFORE_TYPE);
}

int sys_reset_after_ipc_cb(void *arg)
{
    return sys_reset_ipc_cb(DPA_SYS_RESET_OPS_AFTER_TYPE);
}

static int sys_reset_ipc_init(void)
{
    int ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_BEFORE_MDM_RESETTING, sys_reset_before_ipc_cb, NULL);
    if (ret) {
        reset_err("dpa_sys_reset before ipc connect fail, 0x%x.\n", ret);
        return ret;
    }
    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_AFTER_MDM_RESETTING, sys_reset_after_ipc_cb, NULL);
    if (ret) {
        reset_err("dpa_sys_reset after ipc connect fail, 0x%x.\n", ret);
    }
    return ret;
}

static int sys_reset_dump_init(void)
{
    g_sys_reset_ctrl.dump_addr = (uintptr_t)bsp_dpa_dump_register_field(OM_DPAHOST_SYS_RESET, "sys_reset", SYS_RESET_DUMP_SIZE, 0);
    if (g_sys_reset_ctrl.dump_addr == 0) {
        reset_err("dpa_sys_reset dump init fail\n");
        return SYS_RESET_ERR_GEN(SYS_RESET_INIT_DUMP_ERR);
    }
    return 0;
}

int bsp_sys_reset_init(void)
{
    int ret, i;
    ret = (int)memset_s((void *)&g_sys_reset_ctrl, sizeof(g_sys_reset_ctrl), 0, sizeof(g_sys_reset_ctrl));
    if (ret) {
        reset_err("dpa_sys_reset memset fail 0x%x.\n", ret);
        return ret;
    }

    ret = sys_reset_dump_init();
    ret += sys_reset_ipc_init();
    if (ret) {
        reset_err("dpa_sys_reset dump or ipc init fail 0x%x.\n", ret);
        return ret;
    }
    for (i = 0; i < RESET_TYPE_MAX; i++) {
        init_completion(&(g_sys_reset_ctrl.sys_ctrl[i].wait_completion));
    }
    reset_err("dpa_sys_reset init ok.\n");

    return 0;
}

EXPORT_SYMBOL(dpa_sys_reset);