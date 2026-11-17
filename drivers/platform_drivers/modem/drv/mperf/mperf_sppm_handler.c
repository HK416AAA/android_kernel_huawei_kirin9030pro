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

#include <bsp_mprobe.h>
#include <bsp_dump.h>
#include <dpa_dmi.h>
#include <bsp_reset.h>
#include <securec.h>
#include <msg_id.h>
#include <bsp_msg.h>
#include <bsp_dpa.h>
#include <bsp_slice.h>
#include <drv_comm.h>
#include <product_config.h>
#include <bsp_diag.h>
#include <mdrv_diag.h>
#include <mdrv_errno.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <osl_sem.h>
#include "bsp_mperf.h"
#include "mperf_sppm.h"
#include "mperf_odt_service.h"
#include "../sppm/sppm_device.h"
#include "../sppm/sppm_reg_base.h"
#include "../sppm/sppm_soc_interface.h"

#undef THIS_MODU
#define THIS_MODU mod_mperf

#define DPA_MSG_MAX_LEN 0x4000

int mperf_msg_response_send(u32 type, int res)
{
    int data[2] = {0};
    data[0] = type;
    data[1] = res;
    mperf_msg_send(data, sizeof(data), MSG_CORE_TSP);
    return 0;
}

int mperf_msg_send_dpa(void *data, u32 data_len)
{
    int ret;
    struct dmi_msg *msg = NULL;
    unsigned int msg_len = ALIGN(sizeof(struct dmi_msg) + data_len, 4);

    msg = (struct dmi_msg *)kmalloc(msg_len, GFP_KERNEL);
    if (msg == NULL) {
        mperf_err("mperf dmi msg malloc fail\n");
        return BSP_ERROR;
    }

    msg->plane = DMI_SERVICE_TYPE_COMM;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_MPERF;

    msg->data.len = msg_len - sizeof(struct dmi_msg);
    ret = memcpy_s(msg->data.buf, msg->data.len, data, data_len);
    if (ret) {
        mperf_err("memcpy fail\n");
        return ret;
    }
    ret = dpa_dmi_client_request_comm_wake(msg, sizeof(*msg) + msg->data.len);
    if (ret) {
        mperf_err("mperf dmi send fail:%d\n", ret);
    }
    kfree(msg);
    return ret;
}

int mperf_dmi_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    if (msg == NULL || msg->len == 0) {
        mperf_err("mperf dmi msg is null\n");
        return BSP_ERROR;
    }
    if (msg->len > DPA_MSG_MAX_LEN) {
        mperf_err("mperf dmi msg len too long: %d\n", msg->len);
        return BSP_ERROR;
    }
    if (msg->len == sizeof(unsigned int)) {
        mperf_dpa_info_buf_alloc(msg->buf, msg->len);
    } else {
        mperf_dpa_info_buf_flush(msg->buf, msg->len);
    }
    return BSP_OK;
}

struct dmi_client g_mperf_dmi_client = {
    .dmi_id = DMI_SERVICE_MPERF,
    .service_cb = mperf_dmi_service_cb,
};

int mperf_dmi_client_init(void)
{
    int ret;
    ret = dpa_dmi_client_register(&g_mperf_dmi_client);
    if (ret) {
        mperf_err("mperf dmi register fail:%d\n", ret);
    }
    return ret;
}

void mperf_dump_handler_cb(void)
{
    sppm_dev_info *dev_info = sppm_get_dev_info();
    if (dev_info->running == SPPM_RUNNING) {
        sppm_wchan_disable();
        for (int i = 0; i < SPPM_MAX_RCHAN_NUM; i++) {
            sppm_rchan_disable(i);
        }
        mdrv_odt_mperf_chan_close();
        sppm_set_rb_wptr(0);
        sppm_set_rb_rptr(0);
        sppm_clear_int_status(SPPM_INT_ALL);
        bsp_sppm_stop_sampling();
    }
}

int mperf_dump_handler_init(void)
{
    int ret;
    ret = bsp_dump_register_hook("mperf", (dump_hook)mperf_dump_handler_cb);
    if (ret == MDRV_ERROR) {
        mperf_err("mperf register dump handler fail\n");
    }
    return ret;
}

int mperf_reset_cb_func(drv_reset_cb_moment_e eparam, int mac_id)
{
    UNUSED(mac_id);
    sppm_dev_info *dev_info = sppm_get_dev_info();
    if (eparam == MDRV_RESET_CB_BEFORE) {
        if (dev_info->running == SPPM_RUNNING) {
            sppm_wchan_disable();
            for (int i = 0; i < SPPM_MAX_RCHAN_NUM; i++) {
                sppm_rchan_disable(i);
            }
            mdrv_odt_mperf_chan_close();
            sppm_set_rb_wptr(0);
            sppm_set_rb_rptr(0);
            sppm_clear_int_status(SPPM_INT_ALL);
            bsp_sppm_stop_sampling();
        }
    }
    return BSP_OK;
}
 
int mperf_reset_handler_init(void)
{
    int ret;
    ret = bsp_reset_cb_func_register("mperf", mperf_reset_cb_func, 0, MDRV_RESET_CB_PIOR_MPERF);
    if (ret) {
        mperf_err("mdm reset mperf call back func failed\n");
    }
    return ret;
}

void mperf_sppm_handler_init(void)
{
    mperf_ctrl_t *mperf_ctrl = mperf_ctrl_get();
    osl_sem_init(0, &mperf_ctrl->sppm_sem);
    mperf_odt_init();
    mperf_odt_channel_init(MPERF_MXT);
    mperf_send_done_cb_init();
    (void)mperf_dmi_client_init();
    (void)mperf_dump_handler_init();
    (void)mperf_reset_handler_init();
}
