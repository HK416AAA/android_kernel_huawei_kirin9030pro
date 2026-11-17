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

#include <linux/module.h>
#include <linux/slab.h>
#include <stdbool.h>
#include <securec.h>
#include <bsp_slice.h>
#include <linux/delay.h>
#include <msg_id.h>
#include <bsp_diag.h>
#include <mdrv_diag.h>
#include <osl_sem.h>
#include "bsp_mperf.h"
#include "mperf_sppm.h"
#include "mperf_odt_service.h"
#include "../sppm/sppm_device.h"

#undef THIS_MODU
#define THIS_MODU mod_mperf

#define SPPM_WAIT_TIME_MS 1000

int mperf_sppm_en(sppm_acore_config *data)
{
    sppm_ipc_buf_config mode_config;
    sppm_acore_config *config = (sppm_acore_config *)data;

    sppm_pwr_enable();

    mode_config.buffer_size = config->buffer_size;
    mode_config.sample_type = config->flag_circular;
    mode_config.dest_chan = 0x01;

    if (sppm_ui_mode_config(&mode_config) != SPPM_OK) {
        return BSP_ERROR;
    }
    if (sppm_shreshold_cb_reg(mperf_buffer_flush) != SPPM_OK) {
        mperf_err("sppm_shreshold_cb_reg err.\n");
        return BSP_ERROR;
    }
    return BSP_OK;
}

int mperf_sppm_read_event_parse(sppm_read_event *event)
{
    sppm_rchan_cfg rchan_cfg;
    rchan_cfg.name = event->name;
    rchan_cfg.freq = event->freq;
    rchan_cfg.type_id = event->type_id;
    rchan_cfg.event_ids = event->event_ids;
    rchan_cfg.event_num = event->event_id_num;
    rchan_cfg.private_data = event->private_data;
    bsp_sppm_rchan_alloc(&rchan_cfg);
    return BSP_OK;
}

int mperf_init_sppm_config(sppm_acore_config *data)
{
    u32 i;
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    sppm_acore_config *config = (sppm_acore_config *)data;
    u32 read_event_num = config->read_event_num;
    sppm_read_event* read_events = config->read_events;

    mperf_ctrl->config_from_tool = config->from_tool;
    mperf_odt_channel_init(config->from_tool);

    bsp_sppm_rchan_free();
    bsp_sppm_client_deinit();
    bsp_sppm_client_init();

    if (read_event_num > 0) {
        for (i = 0; i < read_event_num; i++) {
            mperf_sppm_read_event_parse(&read_events[i]);
        }
    }
    return BSP_OK;
}

bool have_dpa_config = false;

int mperf_send_info_dpa(int msg_type, sppm_dpa_config *dpa_data)
{
    mperf_dpa_message msg_dpa;
    msg_dpa.type = msg_type;
    if (!have_dpa_config) {
        return BSP_OK;
    }
    if (msg_type == MPERF_MSG_INIT) {
        msg_dpa.dpa_data = *dpa_data;
    }
    mperf_msg_send_dpa(&msg_dpa, sizeof(mperf_dpa_message));
    return BSP_OK;
}

void mperf_sppm_pwr_en(sppm_acore_config *acore_data)
{
    int ret;
    mperf_err("mperf msg sppm_pwr_en\n");
    ret = mperf_sppm_en(acore_data);
    mperf_msg_response_send(MPERF_MSG_SPPM_PWR_EN_RES, ret);
}

void mperf_sppm_init(sppm_acore_config *acore_data, sppm_dpa_config *dpa_data)
{
    int ret;
    mperf_err("mperf msg init config\n");
    ret = (u32)mperf_init_sppm_config(acore_data);
    have_dpa_config = (dpa_data->write_event_num == 1);
    ret |= (u32)mperf_send_info_dpa(MPERF_MSG_INIT, dpa_data);
    mperf_msg_response_send(MPERF_MSG_INIT_RES, ret);
}

void mperf_sppm_chan_en(void)
{
    int ret;
    mperf_err("mperf msg sppm_chan_en\n");
    ret = (u32)bsp_sppm_chan_en();
    ret |= (u32)mperf_send_info_dpa(MPERF_MSG_SPPM_CHAN_EN, NULL);
    mperf_msg_response_send(MPERF_MSG_SPPM_CHAN_EN_RES, ret);
}

void mperf_sppm_online(void)
{
    int ret;
    mperf_err("mperf msg sppm_online\n");
    mdrv_odt_mperf_chan_open();
    ret = bsp_sppm_start_sampling();
    mperf_msg_response_send(MPERF_MSG_SPPM_ONLINE_RES, ret);
}

void mperf_sppm_start_trace(void)
{
    int ret;
    mperf_err("mperf msg start trace\n");
    ret = mperf_send_info_dpa(MPERF_MSG_SPPM_START_TRACE, NULL);
    mperf_msg_response_send(MPERF_MSG_SPPM_START_TRACE_RES, ret);
}

void mperf_sppm_stop_trace(void)
{
    int ret;
    mperf_err("mperf msg stop trace\n");
    ret = mperf_send_info_dpa(MPERF_MSG_SPPM_STOP_TRACE, NULL);
    mperf_msg_response_send(MPERF_MSG_SPPM_STOP_TRACE_RES, ret);
}

void mperf_sppm_pwr_dis(void)
{
    int ret;
    mperf_err("mperf msg sppm_pwr_dis\n");
    ret = sppm_pwr_disable();
    mperf_msg_response_send(MPERF_MSG_SPPM_PWR_DIS_RES, ret);
}

void mperf_sppm_chan_dis(void)
{
    int ret;
    mperf_err("mperf msg sppm_chan_dis\n");
    ret = (u32)bsp_sppm_chan_disable();
    ret |= (u32)mperf_send_info_dpa(MPERF_MSG_SPPM_CHAN_DIS, NULL);
    mperf_msg_response_send(MPERF_MSG_SPPM_CHAN_DIS_RES, ret);
}

void mperf_sppm_offline(void)
{
    int ret;
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    mperf_err("mperf msg sppm_offline\n");
    mperf_ctrl->final_buffer_flush = 1;
    mperf_buffer_flush();
    ret = osl_sem_downtimeout(&mperf_ctrl->sppm_sem, msecs_to_jiffies(SPPM_WAIT_TIME_MS));
    if (ret) {
        mperf_err("buffer flush timeout\n");
        mperf_msg_response_send(MPERF_MSG_SPPM_PWR_DIS_RES, ret);
        return;
    }
    ret = bsp_sppm_stop_sampling();
    mperf_ctrl->final_buffer_flush = 0;
    mperf_msg_response_send(MPERF_MSG_SPPM_OFFLINE_RES, ret);
}

void mperf_sppm_message_parse(unsigned char *data)
{
    mperf_acore_message *message = (mperf_acore_message *)data;
    switch (message->type) {
        case MPERF_MSG_SPPM_PWR_EN:
            mperf_sppm_pwr_en(&message->acore_data);
            break;
        case MPERF_MSG_INIT:
            mperf_sppm_init(&message->acore_data, &message->dpa_data);
            break;
        case MPERF_MSG_SPPM_CHAN_EN:
            mperf_sppm_chan_en();
            break;
        case MPERF_MSG_SPPM_ONLINE:
            mperf_sppm_online();
            break;
        case MPERF_MSG_SPPM_START_TRACE:
            mperf_sppm_start_trace();
            break;
        case MPERF_MSG_SPPM_STOP_TRACE:
            mperf_sppm_stop_trace();
            break;
        case MPERF_MSG_SPPM_PWR_DIS:
            mperf_sppm_pwr_dis();
            break;
        case MPERF_MSG_SPPM_CHAN_DIS:
            mperf_sppm_chan_dis();
            break;
        case MPERF_MSG_SPPM_OFFLINE:
            mperf_sppm_offline();
            break;
        default:
            mperf_err("mperf unkown msg\n");
            break;
    }
    return;
}