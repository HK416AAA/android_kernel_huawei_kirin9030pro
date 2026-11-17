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

#include <securec.h>
#include <osl_types.h>
#include <osl_cache.h>
#include <osl_malloc.h>
#include <osl_spinlock.h>
#include <bsp_odt.h>
#include <osl_list.h>
#include <mdrv_public.h>
#include <linux/of.h>
#include <linux/module.h>
#include "bsp_mperf.h"
#include "mperf_sppm.h"
#include "../sppm/sppm_device.h"
#include "mperf_odt_service.h"

#undef THIS_MODU
#define THIS_MODU mod_mperf
#define MPERF_ODT_BD_SIZE 0x2000

typedef struct {
    u32 odt_chnl_id;
    u8 *bd_vaddr;
    unsigned long bd_paddr;
    u32 bd_size;
    odt_callback pcb;
    spinlock_t lock;
    u32 chan_state;
} mperf_odt_srv_s;

mperf_odt_srv_s g_mperf_odt_srv = { 0 };

typedef enum { ODT_CHAN_CLOSE, ODT_CHAN_OPEN };

uintptr_t mperf_odt_phy_to_virt(unsigned long phy_addr)
{
    return (uintptr_t)g_mperf_odt_srv.bd_vaddr + (phy_addr - (unsigned long)g_mperf_odt_srv.bd_paddr);
}

int mperf_odt_send_done_cb(unsigned int debug_chnid)
{
    odt_buffer_rw_s odt_buf = {
        NULL, NULL, 0, 0
    };
    unsigned int i;
    u32 rd_size;
    odt_bd_data_s *rd_info;
    if (bsp_odt_get_rd_buffer(g_mperf_odt_srv.odt_chnl_id, &odt_buf)) {
        mperf_err("get odt buffer error!\n");
        return -1;
    }
    if ((odt_buf.buffer == NULL) || (odt_buf.size == 0)) {
        return -1;
    }
    odt_buf.buffer = (char *)(uintptr_t)mperf_odt_phy_to_virt((uintptr_t)odt_buf.buffer);
    odt_buf.rb_buffer = (char *)(uintptr_t)mperf_odt_phy_to_virt((uintptr_t)odt_buf.rb_buffer);

    rd_info = (odt_bd_data_s *)odt_buf.buffer;
    for (i = 0; i < odt_buf.size / sizeof(odt_bd_data_s); i++) {
        // call back to mperf buffer.
        g_mperf_odt_srv.pcb((unsigned long)(rd_info[i].data_addr));
    }

    rd_info = (odt_bd_data_s *)odt_buf.rb_buffer;
    for (i = 0; i < odt_buf.rb_size / sizeof(odt_bd_data_s); i++) {
        g_mperf_odt_srv.pcb((unsigned long)(rd_info[i].data_addr));
    }

    rd_size = (odt_buf.size + odt_buf.rb_size);
    bsp_odt_read_rd_done(g_mperf_odt_srv.odt_chnl_id, rd_size);
    return 0;
}

int mperf_odt_reg_send_done_cb(odt_callback pcb)
{
    g_mperf_odt_srv.pcb = pcb;
    bsp_odt_register_rd_cb(g_mperf_odt_srv.odt_chnl_id, mperf_odt_send_done_cb);
    return 0;
}

int mperf_odt_bd_info_fill(odt_buffer_rw_s *podt_buf, mperf_odt_list_s **ptrans, unsigned int list_count)
{
    unsigned int i;
    unsigned int j;
    u32 list_size = list_count * sizeof(odt_bd_data_s);
    odt_bd_data_s *bd_info;
    /* 判断当前支持最大的BD包数是否满足限额 */
    if (podt_buf->size + podt_buf->rb_size < list_size) {
        mperf_err("the avaliable bd buffer is not enough for bdinfo fill!\n");
        return -1;
    }
    if (podt_buf->size >= list_size) {
        bd_info = (odt_bd_data_s *)podt_buf->buffer;
        for (i = 0; i < list_count; i++) {
            (bd_info + i)->data_addr = (unsigned long)ptrans[i]->data_addr;
            (bd_info + i)->data_len = (u16)ptrans[i]->data_len;
            (bd_info + i)->data_type = 0;
            (bd_info + i)->reservd = 0;
        }
        (bd_info + list_count - 1)->data_type = (0x1 << 1); // the last pack will generate callback.
    } else {
        bd_info = (odt_bd_data_s *)podt_buf->buffer;
        for (i = 0; i < podt_buf->size / sizeof(odt_bd_data_s); i++) {
            (bd_info + i)->data_addr = (unsigned long)ptrans[i]->data_addr;
            (bd_info + i)->data_len = (u16)ptrans[i]->data_len;
            (bd_info + i)->data_type = 0;
            (bd_info + i)->reservd = 0;
        }
        bd_info = (odt_bd_data_s *)podt_buf->rb_buffer;
        for (j = 0; j < list_count - podt_buf->size / sizeof(odt_bd_data_s); i++, j++) {
            (bd_info + j)->data_addr = (unsigned long)ptrans[i]->data_addr;
            (bd_info + j)->data_len = (u16)ptrans[i]->data_len;
            (bd_info + j)->data_type = 0;
            (bd_info + j)->reservd = 0;
        }
        (bd_info + j - 1)->data_type = (0x1 << 1); // the last pack will generate callback.
    }

    return 0;
}

int mperf_odt_list_node_fill(mperf_odt_list_s **ptrans, unsigned int list_count)
{
    odt_buffer_rw_s odt_buf = {
        NULL, NULL, 0, 0
    };
    s32 ret;

    if (bsp_odt_get_write_buff(g_mperf_odt_srv.odt_chnl_id, &odt_buf)) {
        mperf_err("get odt buffer error!\n");
        return -1;
    }
    if ((odt_buf.buffer == NULL) || (odt_buf.size == 0)) {
        mperf_err("get odt buffer info error size %d!\n", odt_buf.size);
        return -1;
    }

    odt_buf.buffer = (char *)(uintptr_t)mperf_odt_phy_to_virt((uintptr_t)odt_buf.buffer);
    odt_buf.rb_buffer = (char *)(uintptr_t)mperf_odt_phy_to_virt((uintptr_t)odt_buf.rb_buffer);

    // if odt buffer'space is enough.
    if (mperf_odt_bd_info_fill(&odt_buf, ptrans, list_count) != 0) {
        mperf_err("get odt bd fill err!\n");
        return -1;
    }

    ret = bsp_odt_write_done(g_mperf_odt_srv.odt_chnl_id, list_count * sizeof(odt_bd_data_s)); /* 加入包头个数 */
    if (ret) {
        mperf_err("bsp_odt_write_done err!\n");
        return -1;
    }
    return 0;
}

int mperf_odt_channel_init(unsigned int config_from)
{
    odt_src_chan_cfg_s enc_src_att = {
        0,
    };
    mdrv_odt_mperf_chan_close();
    enc_src_att.data_type = ODT_DATA_TYPE_0;
    enc_src_att.data_type_en = ODT_DATA_TYPE_EN;
    enc_src_att.debug_en = ODT_ENC_DEBUG_DIS;
    enc_src_att.mode = ODT_ENCSRC_CHNMODE_LIST;
    enc_src_att.priority = ODT_CHAN_PRIORITY_2;
    enc_src_att.bypass_en = ODT_HDLC_ENABLE;
    if (config_from == MPERF_MXT) {
        enc_src_att.dest_chan_id = ODT_CODER_DST_LOGSERVER;
    } else {
        enc_src_att.dest_chan_id = ODT_CODER_DST_OM_IND;
    }
    enc_src_att.trans_id_en = ODT_TRANS_ID_DIS;
    enc_src_att.rptr_img_en = ODT_PTR_IMG_DIS;

    enc_src_att.coder_src_setbuf.input_start = (unsigned char *)g_mperf_odt_srv.bd_paddr;
    enc_src_att.coder_src_setbuf.input_end =
        (unsigned char *)(uintptr_t)(g_mperf_odt_srv.bd_paddr + g_mperf_odt_srv.bd_size - 1);
    enc_src_att.coder_src_setbuf.rd_input_start = enc_src_att.coder_src_setbuf.input_start;
    enc_src_att.coder_src_setbuf.rd_input_end = enc_src_att.coder_src_setbuf.input_end;

    /* 调用ODT接口进行编码源通道配置 */
    if (bsp_odt_coder_set_src_chan(g_mperf_odt_srv.odt_chnl_id, &enc_src_att)) {
        mperf_err("odt coder src chan cfg fail !\n");
        return -1;
    }

    mperf_err("mperf channel init ok !\n");

    bsp_odt_start(g_mperf_odt_srv.odt_chnl_id);
    g_mperf_odt_srv.chan_state = ODT_CHAN_OPEN;
    return 0;
}


#define ODT_MEM_ALIGN 8
/* no reserved odt mem, dynamic alloc memory */
int mperf_odt_bd_buffer_init(void)
{
    mperf_odt_srv_s *odt_cfg = &g_mperf_odt_srv;
    sppm_dev_info *sppm_dev = sppm_get_dev_info();
    odt_cfg->bd_vaddr = dma_alloc_coherent(sppm_dev->dev, MPERF_ODT_BD_SIZE, (u64 *)&g_mperf_odt_srv.bd_paddr,
        GFP_KERNEL);
    if (odt_cfg->bd_vaddr == NULL) {
        return MDRV_ERROR;
    }

    mperf_err("odt bd buffer size with:%d!\n", odt_cfg->bd_size);

    if (memset_s((void *)g_mperf_odt_srv.bd_vaddr, g_mperf_odt_srv.bd_size, 0, g_mperf_odt_srv.bd_size) != EOK) {
        mperf_err("mperf odt error\n");
    }

    return MDRV_OK;
}

void mdrv_odt_mperf_chan_close(void)
{
    int ret;
    mperf_odt_srv_s *odt_cfg = &g_mperf_odt_srv;
    if (odt_cfg->chan_state == ODT_CHAN_OPEN) {
        bsp_odt_stop(ODT_CODER_SRC_SPPM);
        ret = bsp_odt_wait_single_chan_idle(ODT_CODER_SRC_SPPM);
        if (ret) {
            mperf_err("stop sppm src chan fail:0x%x\n", ret);
            return;
        }
        odt_cfg->chan_state = ODT_CHAN_CLOSE;
    }
}

void mdrv_odt_mperf_chan_open(void)
{
    mperf_odt_srv_s *odt_cfg = &g_mperf_odt_srv;
    bsp_odt_start(ODT_CODER_SRC_SPPM);
    odt_cfg->chan_state = ODT_CHAN_OPEN;
}

void mperf_odt_ctrl_init(void)
{
    mperf_odt_srv_s *odt_cfg = &g_mperf_odt_srv;
    odt_cfg->odt_chnl_id = ODT_CODER_SRC_SPPM;
    odt_cfg->bd_size = MPERF_ODT_BD_SIZE;
    return;
}

int mperf_odt_init(void)
{
    (void)mperf_odt_ctrl_init();

    (void)mperf_odt_bd_buffer_init();

    return MDRV_OK;
}
