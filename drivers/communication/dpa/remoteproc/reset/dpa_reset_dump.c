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
#include <linux/string.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>
#include <dpa_reset.h>
#include "dpa_reset_frame.h"
#include "dpa_reset_dump.h"

#define reset_err(fmt, ...) dpa_pr_err("[dpa_reset]"fmt, ##__VA_ARGS__)

static void dpa_reset_fw_dump_set_head(reset_dump_head_s *fw_head)
{
    fw_head->magic = DPA_RESET_DUMP_HEAD_MAGIC;
    fw_head->size = DPA_RESET_FW_DUMP_SIZE;
    fw_head->host_num = 0;
    fw_head->core_num = 0;
    fw_head->frame_num = 0;
    fw_head->end_magic = DPA_RESET_DUMP_HEAD_END_MAGIC;
}

static int dpa_reset_fw_dump_init(void)
{
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    ctrl->fw_dump_addr =
        (uintptr_t)bsp_dpa_dump_register_field(OM_DPAHOST_DPA_RESET_FW, "DPA_RESET_FW", DPA_RESET_FW_DUMP_SIZE, 0);
    if (ctrl->fw_dump_addr == 0) {
        reset_err("dpa_reset dump fw reg fail\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_DUMP_MALLOC_ERR);
    }
    dpa_reset_fw_dump_set_head((reset_dump_head_s *)ctrl->fw_dump_addr);
    return 0;
}

static uintptr_t dpa_reset_fw_dump_print_frame(uintptr_t dump_addr, unsigned int core_num, unsigned int frame_num)
{
    unsigned int i, j;
    dpa_reset_frame_record_s *frame = (dpa_reset_frame_record_s *)dump_addr;
    if (core_num * frame_num * sizeof(dpa_reset_frame_record_s) >=
        (DPA_RESET_FW_DUMP_SIZE - sizeof(reset_dump_head_s))) {
        reset_err("[fw]head info check fail, core_num %d, frame_num: %d.\n", core_num, frame_num);
        return 0;
    }
    for (i = 0; i < core_num; i++) {
        reset_err("[fw]core %d info:\n", i);
        for (j = 0; j < frame_num; j++) {
            reset_err("[fw] step %s slice: 0x%x.\n", frame[i * frame_num + j].name, frame[i * frame_num + j].slice);
            if (strcmp(frame[i * frame_num + j].name, "rst_end") == 0) {
                break;
            }
        }
    }

    return (uintptr_t)(frame + core_num * frame_num);
}

static void dpa_reset_fw_dump_print_host(uintptr_t dump_addr, unsigned int host_num, uintptr_t dump_end)
{
    dpa_reset_host_record_s *host = (dpa_reset_host_record_s *)dump_addr;
    unsigned int i, j, cnt;
    reset_err("[fw]--------master_info start------------- \n");
    for (i = 0; i < host_num; i++) {
        if ((uintptr_t)&host[i] > dump_end) {
            reset_err("[fw]--------master_info end------------- \n");
            return;
        }
        reset_err("[fw] host id: %d, name: %s, record_num: %d.\n", i, host[i].name, host[i].record_num);
        reset_err("[fw] start: 0x%x, end: 0x%x, result: 0x%x.\n", host[i].start_slice, host[i].end_slice, host[i].result);
        cnt = min((unsigned int)host[i].record_num, DPA_RESET_RECORD_MAX_NUM);
        for (j = 0; j < cnt; j++) {
            reset_err("[fw] record %d, val: 0x%x.\n", i, host[i].records[j]);
        }
    }
    reset_err("[fw]--------master_info end------------- \n");
    return;
}

void dpa_reset_fw_dump_parse(void)
{
    uintptr_t dump_addr;
    reset_dump_head_s *head = NULL;
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    if (ctrl->fw_dump_addr == 0) {
        reset_err("dpa_reset dump fw init err\n");
        return;
    }
    head = (reset_dump_head_s *)ctrl->fw_dump_addr;
    reset_err("[fw]dpa_fw reset info: host_num: 0x%x.\n", head->host_num);
    dump_addr =
        dpa_reset_fw_dump_print_frame(ctrl->fw_dump_addr + sizeof(reset_dump_head_s), head->core_num, head->frame_num);
    if (dump_addr == 0) {
        return;
    }
    dpa_reset_fw_dump_print_host(dump_addr, head->host_num, ctrl->fw_dump_addr + DPA_RESET_FW_DUMP_SIZE);
}

void dpa_reset_fw_dump_clear(void)
{
    unsigned int size = DPA_RESET_FW_DUMP_SIZE - sizeof(reset_dump_head_s);
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    if (ctrl->fw_dump_addr == 0) {
        reset_err("dpa_reset clear dump fw init err\n");
        return;
    }
    (void)memset_s((void *)(uintptr_t)(ctrl->fw_dump_addr + sizeof(reset_dump_head_s)), size, 0, size);
}

static int dpa_reset_host_dump_init(void)
{
    dpa_reset_host_dump_s *dump = NULL;
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    ctrl->host_dump_addr = (uintptr_t)bsp_dpa_dump_register_field(OM_DPAHOST_DPA_RESET, "DPA_RESET_HOST",
        sizeof(dpa_reset_host_dump_s), 0);
    if (ctrl->host_dump_addr == 0) {
        reset_err("dpa_reset dump host reg fail\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_DUMP_MALLOC_ERR);
    }
    dump = (dpa_reset_host_dump_s *)ctrl->host_dump_addr;
    dump->head.dump_size = sizeof(dpa_reset_host_dump_s);
    dump->head.magic = DPA_RESET_HOST_MAGIC;
    dump->head.record_num = DPA_RESET_HOST_DUMP_MAX;
    return 0;
}

int dpa_reset_dump_init(void)
{
    int ret = dpa_reset_fw_dump_init();
    ret += dpa_reset_host_dump_init();
    return ret;
}

void dpa_reset_host_dump(unsigned int dos, unsigned int type, unsigned int val)
{
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    dpa_reset_host_dump_item_s *items = NULL;
    if (dos > DPA_RESET_HOST_DUMP_MAX) {
        reset_err("[host] stamp %d illegal\n", dos);
        return;
    }
    if (ctrl->host_dump_addr == 0) {
        reset_err("dpa_reset dump host init fail\n");
        return;
    }
    items = (dpa_reset_host_dump_item_s *)((dpa_reset_host_dump_s *)ctrl->host_dump_addr)->items;
    items[dos].type = type + dos;
    items[dos].val = val;
    items[dos].slice = bsp_get_slice_value();
}

static uintptr_t dpa_reset_dump_get_mod_base(unsigned int stage)
{
    uintptr_t addr = 0;
    uintptr_t offset = 0;
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    if (ctrl->host_dump_addr == 0) {
        reset_err("dpa_reset dump host init fail\n");
        return 0;
    }
    addr = (uintptr_t)((dpa_reset_host_dump_s *)ctrl->host_dump_addr)->mods;
    if (stage == DPA_RESET_AFTER) {
        offset = sizeof(dpa_reset_mod_dump_s) * DPA_RESET_HOST_MAX_NUM;
    }
    return (addr + offset);
}

void dpa_reset_mod_dump_before(unsigned int stage, unsigned int idx, const char *name, unsigned int prio)
{
    dpa_reset_mod_dump_s *mods = (dpa_reset_mod_dump_s *)dpa_reset_dump_get_mod_base(stage);
    if (mods == NULL) {
        return;
    }
    if (idx >= DPA_RESET_HOST_MAX_NUM) {
        return;
    }
    strncpy_s(mods[idx].name, DPA_RESET_DUMP_NAME_LEN, name, DPA_RESET_MOD_NAME_LEN + 1);
    mods[idx].prio = prio;
    mods[idx].start_slice = bsp_get_slice_value();
}

void dpa_reset_mod_dump_after(unsigned int stage, unsigned int idx, unsigned int ret)
{
    dpa_reset_mod_dump_s *mods = (dpa_reset_mod_dump_s *)dpa_reset_dump_get_mod_base(stage);
    if (mods == NULL) {
        return;
    }
    if (idx >= DPA_RESET_HOST_MAX_NUM) {
        return;
    }
    mods[idx].end_slice = bsp_get_slice_value();
    mods[idx].ret = ret;
}

static dpa_reset_bypass_info_s *dpa_rest_dump_get_bypass_info(void)
{
    struct dpa_reset_ctrl *ctrl = dpa_reset_get_ctrl();
    dpa_reset_bypass_info_s *bypass_info = NULL;
    if (ctrl->host_dump_addr == 0) {
        reset_err("dpa_reset dump host init fail\n");
        return NULL;
    }
    bypass_info = (dpa_reset_bypass_info_s *)&(((dpa_reset_host_dump_s *)ctrl->host_dump_addr)->bypass_info);
    return bypass_info;
}

void dpa_reset_time_dump(unsigned int cnts, unsigned int time)
{
    dpa_reset_bypass_info_s *bypass_info = dpa_rest_dump_get_bypass_info();
    if (bypass_info == NULL) {
        reset_err("dpa_reset dump host init fail\n");
        return;
    }
    bypass_info->reset_times[cnts % DPA_RESET_TIME_CNT] = time;
}

void dpa_reset_bypass_dump(unsigned int flag)
{
    dpa_reset_bypass_info_s *bypass_info = dpa_rest_dump_get_bypass_info();
    if (bypass_info == NULL) {
        reset_err("dpa_reset dump host init fail\n");
        return;
    }
    bypass_info->bypass_flag = flag;
    bypass_info->bypass_slice = bsp_get_slice_value();
}