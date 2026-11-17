/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
 */

#include <product_config.h>
#include <osl_types.h>
#include <securec.h>
#include <bsp_slice.h>
#include <mdrv_errno.h>
#include <osl_cache.h>
#include <osl_malloc.h>
#include <osl_irq.h>
#include <osl_sem.h>
#include <bsp_mprobe.h>
#include <mdrv_diag.h>
#include <bsp_diag.h>
#include <linux/string.h>
#include <linux/module.h>
#include "mperf_odt_service.h"
#include "bsp_mperf.h"
#include "mperf_sppm.h"
#include "../sppm/sppm_device.h"
#include "../sppm/sppm_reg_base.h"
#include "../sppm/sppm_soc_interface.h"

#undef THIS_MODU
#define THIS_MODU mod_mperf

#define CACHELINE_LENGTH 0x80
#define MPERF_TYPE_MAX 7
#define CACHELINE_ALIGNED __attribute__((aligned(CACHELINE_LENGTH)))

#define DIAG_MPERF_ID(msg_id) DIAG_DRV_GEN_CMD_ID(DIAG_FRAME_MSG_MXT, DIAG_DRV_FIELD_OM, DIAG_DRV_MODULE_MPERF, msg_id)

enum {
    CTRL_BUF,
    BLOCK_COUNTER_BUF,
    TRACE_BUF,
    SPPM_BUF,
    MPERF_CONFIG_BUF,
    MPERF_NUM_BUFS
};

typedef struct {
    unsigned int sid : 4;
    unsigned int ver : 4;
    unsigned int ssid : 8;
    unsigned int trans_id : 8;
    unsigned int mt : 2;
    unsigned int fragment : 4;
    unsigned int eof_flag : 1;
    unsigned int ff_flag : 1;
    unsigned int timestamp;

    unsigned int cmd_id;

    unsigned int msg_len : 16;
    unsigned int modem_id : 3;
    unsigned int level : 3;
    unsigned int reserved : 2;
    unsigned int msg_ver : 8;
} diag_head_s;

typedef struct {
    unsigned int msg_len;
    unsigned int msg_type;
    unsigned int cpu;
} mperf_frame_head_s;

unsigned int buffer_commit = 0;
// each buff may have 2 list to fill if wrapped.
#define ODT_TRANS_LIST_GROUP 2

int diag_head_len = sizeof(diag_head_s);
int mperf_head_len = sizeof(mperf_frame_head_s);

int mperf_send_done_cb(unsigned long addr)
{
    mperf_dpa_dev_info *dpa_dev = mperf_get_dpa_dev_info();
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    if (addr == dpa_dev->rb_phy_addr) {
        mperf_dpa_ringbuff_release();
    } else {
        sppm_set_rb_rptr(buffer_commit);
        sppm_clear_int_status(SPPM_INT_RING_BUFF_INT);
        sppm_set_int_enable(SPPM_INT_RING_BUFF_INT);
        if (mperf_ctrl->final_buffer_flush == 1) {
            osl_sem_up(&mperf_ctrl->sppm_sem);
        }
    }
    return 0;
}

int mperf_send_done_cb_init(void)
{
    mperf_odt_reg_send_done_cb(mperf_send_done_cb);
    return 0;
}

int mperf_add_head(unsigned long long addr, u32 data_len, u32 mperf_msg_len)
{
    diag_head_s diag_head = {0};
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    if (mperf_ctrl->config_from_tool == MPERF_MXT) {
        diag_head.sid = DIAG_SID_DEBUG;
    } else {
        diag_head.sid = DIAG_SID_DIAG_TOOL;
        diag_head.mt = DIAG_FRAME_MT_IND;
    }
    diag_head.timestamp = bsp_get_slice_value();
    diag_head.ssid = DIAG_FRAME_SSID_APP_CPU;
    diag_head.ver = DIAG_FRAME_VER_2;
    diag_head.cmd_id = DIAG_MPERF_ID(MPERF_TYPE_MAX);
    if (mperf_msg_len == 0) {
        diag_head.msg_len = data_len;
    } else {
        diag_head.msg_len = data_len + mperf_head_len;
    }
    if (memcpy_s((void *)addr, diag_head_len, (void *)&diag_head, diag_head_len)) {
        mperf_err("mperf cpy diag head fail\n");
        return MDRV_ERROR;
    }
    if (mperf_msg_len != 0) {
        mperf_frame_head_s frame_head = {0};
        frame_head.msg_len = mperf_msg_len + mperf_head_len;
        frame_head.msg_type = SPPM_BUF;
        frame_head.cpu = 0;
        if (memcpy_s((void *)addr + diag_head_len, mperf_head_len, (void *)&frame_head, mperf_head_len)) {
            mperf_err("mperf cpy mperf head fail\n");
            return MDRV_ERROR;
        }
    }
    return 0;
}

// acore suspend : himxt disconnect when use himxt or hmiser disconnect when use hmiser
int mperf_reset_sppm_rb_rptr(void)
{
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    if (((mperf_ctrl->config_from_tool == MPERF_MXT) && (DIAG_GET_MXT_CONN_STATE(mdrv_diag_get_conn_state()) == 0)) ||
    ((mperf_ctrl->config_from_tool != MPERF_MXT) && (DIAG_GET_HMI_SRV_CONN_STATE(mdrv_diag_get_conn_state()) == 0))
    ) {
        sppm_set_rb_rptr(buffer_commit);
        sppm_clear_int_status(SPPM_INT_RING_BUFF_INT);
        sppm_set_int_enable(SPPM_INT_RING_BUFF_INT);
        return MDRV_ERROR;
    }
    return MDRV_OK;
}

int mperf_buffer_flush(void)
{
    mperf_odt_list_s read_odt, commit_odt, *ptrans[ODT_TRANS_LIST_GROUP];
    sppm_dev_info *sppm_dev = sppm_get_dev_info();
    unsigned int rptr = sppm_get_rb_rptr();
    unsigned int wptr = sppm_get_rb_wptr();
    buffer_commit = wptr;
    unsigned int list_count = 0;
    int len = (int)buffer_commit - (int)rptr;
    int length_tail = len;
    unsigned long long virt_read_data_addr, virt_commit_data_addr;
    unsigned short read_data_len, commit_data_len;

    if (mperf_reset_sppm_rb_rptr()) {
        mperf_err("mperf send channel err\n");
        return MDRV_ERROR;
    }

    len += (len < 0) ? sppm_dev->rb_size : 0;
    if (length_tail == len || buffer_commit == 0) {
        virt_read_data_addr = sppm_dev->virt_addr + rptr - diag_head_len - mperf_head_len;
        if (length_tail == len) {
            read_data_len = length_tail;
        } else {
            read_data_len = sppm_dev->rb_size - rptr;
        }
        mperf_add_head(virt_read_data_addr, (u32)read_data_len, (u32)read_data_len);
        read_odt.data_addr = sppm_dev->rb_phy_addr + rptr - diag_head_len - mperf_head_len;
        read_odt.data_len = read_data_len + diag_head_len + mperf_head_len;
        read_odt.using = 0x01;

        ptrans[list_count] = &read_odt;
        list_count++;
    } else {
        virt_read_data_addr = sppm_dev->virt_addr + rptr - diag_head_len - mperf_head_len;
        read_data_len = sppm_dev->rb_size - rptr;

        virt_commit_data_addr = sppm_dev->virt_addr - diag_head_len;
        commit_data_len = buffer_commit;

        read_odt.data_addr = sppm_dev->rb_phy_addr + rptr - diag_head_len - mperf_head_len;
        read_odt.data_len = read_data_len + diag_head_len + mperf_head_len;
        read_odt.using = 0x01;

        commit_odt.data_addr = sppm_dev->rb_phy_addr - diag_head_len;
        commit_odt.data_len = commit_data_len + diag_head_len;
        commit_odt.using = 0x01;

        mperf_add_head(virt_read_data_addr, (u32)read_data_len, (u32)read_data_len + commit_data_len);
        ptrans[list_count] = &read_odt;
        list_count++;

        mperf_add_head(virt_commit_data_addr, (u32)commit_data_len, 0);
        ptrans[list_count] = &commit_odt;
        list_count++;
    }
    (void)mperf_odt_list_node_fill(ptrans, list_count);
    return 0;
}

int mperf_add_dpa_info_head(unsigned long long addr, u32 data_len)
{
    diag_head_s diag_head = {0};
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    if (mperf_ctrl->config_from_tool == MPERF_MXT) {
        diag_head.sid = DIAG_SID_DEBUG;
    } else {
        diag_head.sid = DIAG_SID_DIAG_TOOL;
        diag_head.mt = DIAG_FRAME_MT_IND;
    }
    diag_head.timestamp = bsp_get_slice_value();
    diag_head.ssid = DIAG_FRAME_SSID_APP_CPU;
    diag_head.ver = DIAG_FRAME_VER_2;
    diag_head.cmd_id = DIAG_MPERF_ID(MPERF_TYPE_MAX);
    diag_head.msg_len = data_len + mperf_head_len;

    if (memcpy_s((void *)addr, diag_head_len, (void *)&diag_head, diag_head_len)) {
        mperf_err("mperf cpy diag head fail\n");
        return MDRV_ERROR;
    }
    mperf_frame_head_s frame_head = {0};
    frame_head.msg_len = data_len + mperf_head_len;
    frame_head.msg_type = CTRL_BUF;
    frame_head.cpu = 0;
    if (memcpy_s((void *)addr + diag_head_len, mperf_head_len, (void *)&frame_head, mperf_head_len)) {
        mperf_err("mperf cpy mperf head fail\n");
        return MDRV_ERROR;
    }
    return MDRV_OK;
}

int mperf_dpa_info_buf_alloc(void *data, u32 data_len)
{
    int ret = 0;
    mperf_dpa_dev_info *dpa_dev = mperf_get_dpa_dev_info();
    unsigned long long virt_addr, rb_phy_addr;
    dpa_dev->rb_size = *(unsigned int *)data;
    ret = mperf_dpa_ringbuff_alloc();
    if (ret) {
        return MDRV_ERROR;
    }
    virt_addr = dpa_dev->virt_addr;
    rb_phy_addr = dpa_dev->rb_phy_addr;
    return MDRV_OK;
}

int mperf_dpa_info_buf_flush(void *data, u32 data_len)
{
    mperf_dpa_dev_info *dpa_dev = mperf_get_dpa_dev_info();
    mperf_odt_list_s *ptrans[ODT_TRANS_LIST_GROUP];
    mperf_odt_list_s odt = {0};
    if (dpa_dev->data_size == 0) {
        mperf_add_dpa_info_head(dpa_dev->virt_addr, dpa_dev->rb_size);
    }
    if (memcpy_s((void *)dpa_dev->virt_addr + dpa_dev->data_size + diag_head_len + mperf_head_len,
        data_len, (void *)data, data_len)) {
        mperf_err("mperf cpy dpa info fail\n");
        return MDRV_ERROR;
    }
    dpa_dev->data_size += data_len;
    if (dpa_dev->data_size == dpa_dev->rb_size) {
        odt.data_addr = dpa_dev->rb_phy_addr;
        odt.data_len = dpa_dev->data_size + diag_head_len + mperf_head_len;
        odt.using = 0x01;
        ptrans[0] = &odt;
        (void)mperf_odt_list_node_fill(ptrans, 1);
    }
    return MDRV_OK;
}
