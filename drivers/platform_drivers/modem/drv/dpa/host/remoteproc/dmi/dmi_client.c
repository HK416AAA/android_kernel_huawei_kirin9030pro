/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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

#include <linux/netdevice.h>
#include <linux/kthread.h>
#include <uapi/linux/sched/types.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/kfifo.h>
#include <linux/of_device.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <securec.h>
#include <bsp_print.h>
#include <bsp_dpa_msg.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>
#include <bsp_dmi.h>
#include <bsp_rproc.h>
#include <bsp_dpa.h>
#include <bsp_dra.h>
#include <bsp_dpa_net_om.h>
#include <bsp_dpa_syscache.h>
#include <dpa_reset.h>
#include "dmi_client.h"
#include "dmi_msg.h"
#include "rproc.h"

#define DMI_RPM_RESUME 0x0
#define DMI_RPM_RESET 0x222
#define DMI_DUMP_SIZE 0x400
spinlock_t g_dmi_lock;

unsigned int g_dmi_ch_map[DMI_SERVICE_TYPE_COMM][2] = {
    {DPA_FIPC_TEST_PRIVATE_SEND_1, DPA_FIPC_TEST_PRIVATE_RECV_1},
    {DPA_FIPC_TEST_PRIVATE_SEND_2, DPA_FIPC_TEST_PRIVATE_RECV_2},
    {DPA_FIPC_TEST_PRIVATE_SEND_3, DPA_FIPC_TEST_PRIVATE_RECV_3},
    {DPA_FIPC_TEST_PRIVATE_SEND_4, DPA_FIPC_TEST_PRIVATE_RECV_4},
};
struct dmi_client_map g_dmi_client_map[DMI_SERVICE_MAX];
struct dmi_client_dbg_info g_dmi_client_dbg[DMI_SERVICE_MAX];
struct net_om_info g_dmi_report_info = {0};
unsigned int g_dmi_stat = 0;
void *g_dmi_dump_base;

void dmi_client_chn_event_notify(unsigned int plane, enum dmi_event_type_e event)
{
    unsigned int dmi_idx;
    for (dmi_idx = 0; dmi_idx < DMI_SERVICE_MAX; dmi_idx++) {
        if (g_dmi_client_map[dmi_idx].service.dmi_client_event_cbk != NULL) {
            g_dmi_client_map[dmi_idx].service.dmi_client_event_cbk(plane, event);
        }
    }
}

int dpa_dmi_client_init(struct dmi_client *client)
{
    if (client == NULL) {
        return -1;
    }

    return memset_s(client, sizeof(*client), 0, sizeof(struct dmi_client));
}
EXPORT_SYMBOL(dpa_dmi_client_init);

int dpa_dmi_client_register(struct dmi_client *service)
{
    if (service == NULL || service->dmi_id >= DMI_SERVICE_MAX) {
        return -1;
    }

    memcpy_s(&g_dmi_client_map[service->dmi_id].service, sizeof(struct dmi_client), service, sizeof(*service));

    return 0;
}
EXPORT_SYMBOL(dpa_dmi_client_register);

int dpa_dmi_client_unregister(struct dmi_client *service)
{
    if (service == NULL || service->dmi_id >= DMI_SERVICE_MAX) {
        return -1;
    }

    memset_s(&g_dmi_client_map[service->dmi_id].service, sizeof(struct dmi_client), 0, sizeof(*service));

    return 0;
}
EXPORT_SYMBOL(dpa_dmi_client_unregister);

struct dmi_msg *dpa_dmi_msg_alloc(unsigned int dmi_id, unsigned int len)
{
    unsigned long long dra_buf;
    struct dmi_msg *dmi_msg = NULL;
    unsigned long flags;

    spin_lock_irqsave(&g_dmi_lock, flags);
    if (dmi_id >= DMI_SERVICE_MAX || len > DMI_BUF_SIZE || g_dmi_stat == DMI_RPM_RESET) {
        spin_unlock_irqrestore(&g_dmi_lock, flags);
        return NULL;
    }

    dra_buf = bsp_dra_alloc_buf(DMI_BUF_SIZE);
    if (dra_buf == 0) {
        spin_unlock_irqrestore(&g_dmi_lock, flags);
        return NULL;
    }
    g_dmi_client_dbg[dmi_id].alloc++;

    dmi_msg = (struct dmi_msg *)bsp_dra_get_virt(dra_buf);
    if (dmi_msg == NULL) {
        spin_unlock_irqrestore(&g_dmi_lock, flags);
        dpa_pr_err("dmi msg virt is null\n");
        return NULL;
    }
    dmi_msg->dmi_id = dmi_id;
    spin_unlock_irqrestore(&g_dmi_lock, flags);

    return dmi_msg;
}
EXPORT_SYMBOL(dpa_dmi_msg_alloc);

int dpa_dmi_msg_free(struct dmi_msg_data *data)
{
    struct dmi_msg *msg = NULL;

    if (data == NULL) {
        return -1;
    }
    msg = (struct dmi_msg *)((void *)data->buf - sizeof(struct dmi_msg));
    if (msg->dmi_id < DMI_SERVICE_MAX) {
        g_dmi_client_dbg[msg->dmi_id].free++;
    } else {
        dpa_pr_err("msg free id err:%d\n", msg->dmi_id);
    }

    bsp_dra_free_virt((unsigned char *)msg);

    return 0;
}
EXPORT_SYMBOL(dpa_dmi_msg_free);

int dpa_dmi_msg_maxsize(void)
{
    return DMI_BUF_SIZE;
}
EXPORT_SYMBOL(dpa_dmi_msg_maxsize);

extern struct rproc_dpa g_rproc_dpa;
int dpa_dmi_client_request(struct dmi_msg *msg, unsigned int len)
{
    unsigned long long phy_addr;
    unsigned int send_len;
    int ret;

    if (unlikely(msg == NULL || msg->dmi_id >= DMI_SERVICE_MAX || msg->plane >= DMI_SERVICE_TYPE_PLANE_MAX
        || msg->data.len == 0 || (msg->data.len + sizeof(struct dmi_msg) != len) || len > DMI_BUF_SIZE)) {
        dpa_pr_debug("msg param err:%d\n", msg->dmi_id);
        g_dmi_client_dbg[msg->dmi_id].send_fail++;
        dpa_fail_event_add(DPA_DMI_MSG_SEND_FAIL, FAIL_TYPE_PARAM_ERR);
        return -EINVAL;
    }

    send_len = ALIGN(len, 4);
    (void)bsp_dpa_sc_dma_map_single(g_rproc_dpa.dev, msg, send_len, DMA_TO_DEVICE);
    phy_addr = bsp_dra_virt_to_dra((unsigned char *)msg);
    ret = dmi_msg_send_sync(msg->plane, (void *)msg, phy_addr, send_len);
    if (ret) {
        g_dmi_client_dbg[msg->dmi_id].send_fail++;
    }
    g_dmi_client_dbg[msg->dmi_id].send_cnt++;
    return ret;
}
EXPORT_SYMBOL(dpa_dmi_client_request);

// 在msg上下文处理
static int dmi_client_msg_read_cb(void *buf, unsigned int len, unsigned int free)
{
    struct dmi_msg *msg = NULL;
    struct dmi_client_map *client_map = NULL;
    unsigned int dmi_id;
    unsigned char is_last;

    if (buf == NULL || len < sizeof(struct dmi_msg)) {
        dpa_pr_err("msg param err\n");
        return -1;
    }

    msg = (struct dmi_msg *)buf;
    dmi_id = msg->dmi_id;
    if (dmi_id >= DMI_SERVICE_MAX) {
        if (free) {
            bsp_dmi_msg_free(&msg->data);
        }
        return 0;
    }

    is_last = msg->last;

    client_map = &g_dmi_client_map[dmi_id];
    if (msg->type == DMI_SERVICE_TYPE_REQUEST && client_map->service.service_cb != NULL) {
        client_map->service.service_cb(client_map->service.priv, msg->sub_id, (struct dmi_msg_data *)&msg->data);
    } else if (msg->type == DMI_SERVICE_TYPE_ERR_PROC && client_map->service.err_process != NULL) {
        client_map->service.err_process(client_map->service.priv, msg->sub_id, (struct dmi_msg_data *)&msg->data);
    } else {
        dpa_pr_err("msg type not sup:%d\n", msg->type);
        g_dmi_client_dbg[dmi_id].read_type_err++;
        if (free) {
            bsp_dmi_msg_free(&msg->data);
        }
    }

    g_dmi_client_dbg[dmi_id].read_cnt++;
    if (is_last) {
        g_dmi_client_dbg[dmi_id].last_mark = g_dmi_client_dbg[dmi_id].read_cnt;
    }
    return 0;
}

dpa_msg_chn_t g_dmi_msg_chn;

static int dmi_msg_read_cb(const struct dpa_msg_addr *src, void *msg, unsigned len)
{
    if (src == NULL || src->core != DPA_MSG_CORE_DPA || msg == NULL || src->chnid != DPA_MSG_CHN_DMI) {
        dpa_pr_err("param err\n");
        return -1;
    }

    return dmi_client_msg_read_cb(msg, len, 0); // 不能释放内存
}

int bsp_dmi_client_request_comm(struct dmi_msg *msg, unsigned int len)
{
    struct dpa_msg_addr dst;
    int ret;
    unsigned long flags;

    spin_lock_irqsave(&g_dmi_lock, flags);
    if (msg == NULL || msg->dmi_id >= DMI_SERVICE_MAX || g_dmi_stat != DMI_RPM_RESUME) {
        dpa_pr_err("msg param err:%d\n", msg->dmi_id);
        dpa_fail_event_add(DPA_DMI_MSG_SEND_FAIL, FAIL_TYPE_PARAM_ERR);
        spin_unlock_irqrestore(&g_dmi_lock, flags);
        return -EINVAL;
    }

    msg->plane = DMI_SERVICE_TYPE_COMM;
    dst.core = DPA_MSG_CORE_DPA;
    dst.chnid = DPA_MSG_CHN_DMI;

    g_dmi_client_dbg[msg->dmi_id].send_cnt++;
    ret = bsp_dpa_msg_lite_sendto(g_dmi_msg_chn, &dst, msg, len);
    spin_unlock_irqrestore(&g_dmi_lock, flags);

    return ret;
}

int dpa_dmi_client_request_comm_wake(struct dmi_msg *msg, unsigned int len)
{
    return bsp_dmi_client_request_comm(msg, len);
}
EXPORT_SYMBOL(dpa_dmi_client_request_comm_wake);


int dmi_msg_lite_init(void)
{
    struct dpa_msgchn_attr attr;
    int ret;

    bsp_dpa_msgchn_attr_init(&attr);

    attr.chnid = DPA_MSG_CHN_DMI;
    attr.coremask = DPA_MSG_CORE_MASK(DPA_MSG_CORE_DPA);
    attr.lite_notify = dmi_msg_read_cb;

    ret = bsp_dpa_msg_lite_open(&g_dmi_msg_chn, &attr);
    if (ret) {
        dpa_pr_err("dmi msg lite init fail:%d\n", ret);
    }
    return ret;
}

// 在dmi用户之前调用，置rst状态，申请释放均都失败，关闭收到流程
int dmi_dpa_reset_cb_step1(dpa_reset_stage_e enparam, int arg)
{
    unsigned long flags;
    unsigned int i;
    int ret = 0;

    if (enparam == DPA_RESET_BEFORE) {
        spin_lock_irqsave(&g_dmi_lock, flags);
        g_dmi_stat = DMI_RPM_RESET;
        spin_unlock_irqrestore(&g_dmi_lock, flags);
        for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
            dmi_msg_recv_stop(i);
        }
        dmi_msg_send_stop();
    }
    return ret;
}

int dmi_dpa_reset_cb_step2(dpa_reset_stage_e enparam, int arg)
{
    unsigned long flags;
    unsigned int i;
    int ret = 0;

    if (enparam == DPA_RESET_AFTER) {
        spin_lock_irqsave(&g_dmi_lock, flags);
        g_dmi_stat = DMI_RPM_RESUME;
        spin_unlock_irqrestore(&g_dmi_lock, flags);
        for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
            dmi_msg_recv_restart(i);
        }
        ret = dmi_msg_send_restart();
    }
    return ret;
}

int dmi_client_init(void)
{
    int ret, i;

    spin_lock_init(&g_dmi_lock);

    for (i = 0; i < DMI_SERVICE_TYPE_COMM; i++) {
        ret = dmi_msg_send_ch_init(i, g_dmi_ch_map[i][0]);
        if (ret) {
            dpa_pr_err("dmi client send init fail:%d\n", ret);
            return -1;
        }
        ret = dmi_msg_recv_ch_init(i, g_dmi_ch_map[i][1], dmi_client_msg_read_cb);
        if (ret) {
            dpa_pr_err("dmi client recv init fail:%d\n", ret);
            return -1;
        }
    }
    ret = dmi_msg_lite_init();
    if (ret) {
        return ret;
    }

    ret = bsp_dpa_reset_register_cb("dmi_step1", dmi_dpa_reset_cb_step1, 0, DPA_RESET_CB_LEVEL_COMMON);
    if (ret) {
        dpa_pr_err("reg dpa rst before fail:%d\n", ret);
        return ret;
    }

    ret = bsp_dpa_reset_register_cb("dmi_step2", dmi_dpa_reset_cb_step2, 0, DPA_RESET_CB_LEVEL_DMI);
    if (ret) {
        dpa_pr_err("reg dpa rst after fail:%d\n", ret);
        return ret;
    }

    dpa_pr_err("dmi client init ok\n");
    return ret;
}

static struct dpa_dmi_ops g_dmi_ops = {
    .dpa_dmi_client_init = dpa_dmi_client_init,
    .dpa_dmi_client_register = dpa_dmi_client_register,
    .dpa_dmi_client_request = dpa_dmi_client_request,
    .dpa_dmi_msg_alloc = dpa_dmi_msg_alloc,
    .dpa_dmi_msg_free = dpa_dmi_msg_free,
    .dpa_dmi_msg_maxsize = dpa_dmi_msg_maxsize,
};

static struct platform_device g_dmi_client_plat_device = {
    .name = "dmi_client_plat",
};

static struct platform_driver g_dmi_client_plat_driver = {
    .probe = NULL,
    .driver =
        {
            .name = "dmi_client_plat",
            .owner = THIS_MODULE,
            .probe_type = PROBE_FORCE_SYNCHRONOUS,
        },
};

void *dmi_client_dma_buf_alloc(size_t size, dma_addr_t *dma_handle)
{
    void *mem_addr = NULL;
    mem_addr = dma_alloc_coherent(&g_dmi_client_plat_device.dev, size, dma_handle, GFP_KERNEL);
    if (mem_addr == NULL) {
        return NULL;
    }
    return mem_addr;
}

void dmi_client_dma_buf_free(size_t size, void *cpu_addr, dma_addr_t dma_handle)
{
    dma_free_coherent(&g_dmi_client_plat_device.dev, size, cpu_addr, dma_handle);
    return;
}

static void dmi_dump_hook(void)
{
    (void)memcpy_s(g_dmi_dump_base, DMI_DUMP_SIZE, g_dmi_client_dbg, sizeof(g_dmi_client_dbg));
}

static void dmi_dump_init(void)
{
    int ret;

    g_dmi_dump_base = (unsigned int *)bsp_dpa_dump_register_field(OM_DPAHOST_DMI, "DMI", DMI_DUMP_SIZE, 0);
    if (g_dmi_dump_base == NULL) {
        dpa_pr_err("dump mem alloc fail\n");
        return;
    }
    ret = (int)memset_s(g_dmi_dump_base, DMI_DUMP_SIZE, 0, DMI_DUMP_SIZE);
    if (ret) {
        dpa_pr_err("dump memset_s fail\n");
    }

    ret = bsp_dpa_dump_register_hook("dmi", dmi_dump_hook);
    if (ret == -1) {
        dpa_pr_err("register om fail\n");
    }
}

static void dmi_report_cb(void)
{
    return;
}

void dmi_report_init(void)
{
    struct net_om_info *info = &g_dmi_report_info;
    int ret;

    info->ul_msg_id = (int)DPA_HOST_NET_OM_HOST_DMI;
    info->func_cb = dmi_report_cb;
    info->data = g_dmi_client_dbg;
    info->size = sizeof(g_dmi_client_dbg);
    INIT_LIST_HEAD(&info->list);

    ret = bsp_dpa_net_report_register(info);
    if (ret != 0) {
        dpa_pr_err("dmi report register fail\n");
    }
}

int dmi_client_device_init(void)
{
    s32 ret;

    ret = platform_device_register(&g_dmi_client_plat_device);
    if (ret) {
        return ret;
    }
    ret = platform_driver_register(&g_dmi_client_plat_driver);
    if (ret) {
        platform_device_unregister(&g_dmi_client_plat_device);
        return ret;
    }

    ret = dpa_dmi_api_register(&g_dmi_ops);
    if (ret) {
        return ret;
    }
    dmi_dump_init();
    dmi_report_init();

    return 0;
}


// test
// 注册服务
enum {
    DMI_SERVICE_STACK_FUNC0,
    DMI_SERVICE_STACK_FUNC1,
    DMI_SERVICE_STACK_FUNC_MAX
};

unsigned int g_dmi_cnt;
unsigned int g_dmi_len;

void dmi_show(void)
{
    int i;

    dpa_pr_err("max_msg_size: 0x%lx\n", MAX_MSG_SIZE);

    for (i = 0; i < DMI_SERVICE_MAX; i++) {
        dpa_pr_err("id %d info\n", i);
        dpa_pr_err("send_cnt :%u\n", g_dmi_client_dbg[i].send_cnt);
        dpa_pr_err("send_fail:%u\n", g_dmi_client_dbg[i].send_fail);
        dpa_pr_err("read_cnt :%u\n", g_dmi_client_dbg[i].read_cnt);
        dpa_pr_err("read_fail:%u\n", g_dmi_client_dbg[i].read_fail);
        dpa_pr_err("last_mark:%u\n", g_dmi_client_dbg[i].last_mark);
        dpa_pr_err("alloc    :%u\n", g_dmi_client_dbg[i].alloc);
        dpa_pr_err("free     :%u\n", g_dmi_client_dbg[i].free);
    }
    dpa_pr_err("g_dmi_cnt:%u\n", g_dmi_cnt);
    dpa_pr_err("g_dmi_len:%u\n", g_dmi_len);
}

int dpa_service_test_service_cb(char *priv, unsigned int service_sub_id, struct dmi_msg_data *msg)
{
    unsigned int i;

    g_dmi_cnt++;
    g_dmi_len += msg->len;
    for (i = 0; i < msg->len; i++) {
        dpa_pr_err("msg->buf[%u]:%u\n", i, msg->buf[i]);
    }
    bsp_dmi_msg_free(msg);

    return 0;
}

void dpa_service_test_send_done(unsigned int free_size)
{
    dpa_pr_err("free_size:%u\n", free_size);
}

void dmi_client_test_init(void)
{
    int ret;
    struct dmi_client dmi_client_test;

    ret = bsp_dmi_client_init(&dmi_client_test);
    if (ret) {
        dpa_pr_err("dpa client test init fail:%d\n", ret);
        return;
    }

    dmi_client_test.dmi_id = DMI_SERVICE_TEST;
    dmi_client_test.service_cb = dpa_service_test_service_cb;
    dmi_client_test.send_done = dpa_service_test_send_done;

    ret = bsp_dmi_client_register(&dmi_client_test);
    if (ret) {
        dpa_pr_err("dpa client test register fail:%d\n", ret);
        return;
    }
}

void dmi_client_test_send(int plane, unsigned int size, unsigned int cnt)
{
    int ret, i;
    struct dmi_msg *msg = NULL;

    for (i = 0; i < cnt; i++) {
        // 专用通道申请dmi msg内存
        msg = (struct dmi_msg *)bsp_dmi_msg_alloc(DMI_SERVICE_TEST, sizeof(struct dmi_msg) + size);
        if (msg == NULL) {
            dpa_pr_err("malloc fail\n");
            break;
        }

        // 填充dmi msg数据
        msg->plane = plane;
        msg->type = DMI_SERVICE_TYPE_REQUEST;
        msg->dmi_id = DMI_SERVICE_TEST;

        msg->data.len = size;
        msg->data.buf[0] = 1;
        msg->data.buf[1] = 2;
        msg->data.buf[2] = 3;
        msg->data.buf[3] = 4;
        msg->data.buf[4] = '\n';

        // 专用通道发送dmi msg数据
        ret = bsp_dmi_client_request(msg, sizeof(struct dmi_msg) + size);
        if (ret) {
            dpa_pr_err("dpa client test send fail:%d\n", ret);
            // 发送失败释放dmi msg内存
            bsp_dmi_msg_free(&msg->data);
            msleep(10);
        }
    }
}

void dmi_client_test_send_comm(unsigned int size, unsigned int cnt)
{
    int ret, i;
    struct dmi_msg *msg = NULL;
    unsigned int len = sizeof(struct dmi_msg) + size;

    // 申请dmi msg内存
    msg = (struct dmi_msg *)kmalloc(len, GFP_KERNEL);
    if (msg == NULL) {
        dpa_pr_err("malloc fail\n");
        return;
    }

    for (i = 0; i < cnt; i++) {
        // 填充dmi msg数据
        msg->type = DMI_SERVICE_TYPE_REQUEST;
        msg->dmi_id = DMI_SERVICE_TEST;

        msg->data.len = size;
        msg->data.buf[0] = 1;
        msg->data.buf[1] = 2;
        msg->data.buf[2] = 3;
        msg->data.buf[3] = 4;
        msg->data.buf[4] = '\n';

        // 发送dmi msg数据
        ret = bsp_dmi_client_request_comm_wake(msg, sizeof(*msg) + msg->data.len);
        if (ret) {
            dpa_pr_err("dmi comm test send %d fail:%d\n", i, ret);
            msleep(10);
        }
    }
    // 释放dmi msg内存
    kfree(msg);
}
