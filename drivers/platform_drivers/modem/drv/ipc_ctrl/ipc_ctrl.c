/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
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

#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>
#include <linux/spinlock.h>

#include <osl_malloc.h>
#include <bsp_ipc_fusion.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_reset.h>
#include <bsp_dt.h>
#include <securec.h>

#include "ipc_ctrl.h"
#include "ipc_ctrl_dump.h"

static spinlock_t g_modem_reset_flag_lock;
u32 g_dbg_print_sw = 0;
u32 g_ipcctrl_init_status = 0;
u32 g_modem_reset_flag = 0;
u32 g_ipcctrl_chn_index = 0; // 这个值初始化完后就不会再变
struct ipcctrl_channel_t *g_ipcctrl_chn[CHN_MAX_NUM] = { 0 };

struct ipc_handle *ipcctrl_handle_get(ipc_res_id_e ipc_res_id)
{
    u32 i, j;
    struct ipcctrl_res_t *pres = NULL;

    for (i = 0; i < g_ipcctrl_chn_index; ++i) {
        if (g_ipcctrl_chn[i] == NULL) {
            continue;
        }
        for (j = 0; j < RES_MAX_NUM; ++j) {
            pres = g_ipcctrl_chn[i]->res[j];
            if (pres == NULL) {
                continue;
            }
            if (pres->res_id == ipc_res_id) {
                return &pres->handle;
            }
        }
    }
    return NULL;
}

s32 ipcctrl_get_byhandle(struct ipc_handle *pipcctrl_hdl, struct ipcctrl_channel_t **ppchn,
    struct ipcctrl_res_t **ppres)
{
    struct ipcctrl_channel_t *pchn = NULL;
    struct ipcctrl_res_t *pres = NULL;

    if (pipcctrl_hdl == NULL) {
        return IPCCTRL_ERR;
    }
    if (pipcctrl_hdl->magic != IPCCTRL_MAGIC || pipcctrl_hdl->chn_index >= CHN_MAX_NUM ||
        pipcctrl_hdl->res_bit >= RES_MAX_NUM) {
        ipcctrl_err("ipcctrl handle param check failed, magic=%d, chn_index=%d, res_bit=%d\n",
            pipcctrl_hdl->magic, pipcctrl_hdl->chn_index, pipcctrl_hdl->res_bit);
        return IPCCTRL_HANDLE_ERR;
    }

    pchn = g_ipcctrl_chn[pipcctrl_hdl->chn_index];
    if (pchn == NULL) {
        goto HANDLE_ERR;
    }
    pres = pchn->res[pipcctrl_hdl->res_bit];
    if (pres == NULL || pipcctrl_hdl != &pres->handle) {
        goto HANDLE_ERR;
    }

    *ppchn = pchn;
    *ppres = pres;

    return IPCCTRL_OK;
HANDLE_ERR:
    ipcctrl_err("ipcctrl handle get failed\n");
    return IPCCTRL_HANDLE_ERR;
}

irqreturn_t ipcctrl_int_handler(int irq_no, void *intput_arg)
{
    u32 int_stat;
    u32 bit_value;
    u32 i;
    void *arg = intput_arg;
    struct ipcctrl_channel_t *pchn = NULL;
    struct ipcctrl_res_t *pres = NULL;

    pchn = (struct ipcctrl_channel_t *)(uintptr_t)arg;
    int_stat = readl((void *)((char *)pchn->base_addr + IPCCTRL_CPU_INT_MSK_INT_STAT)); // 读屏蔽后的电平中断状态寄存器，对已经屏蔽的中断，不清除。
    writel(int_stat, (void *)((char *)pchn->base_addr + IPCCTRL_CPU_INT_CLR));

    for (i = 0; i < RES_MAX_NUM; ++i) {
        bit_value = int_stat & IPCCTRL_BIT_MASK(i);
        if (bit_value == 0) {
            continue;
        }
        pres = pchn->res[i];
        if (pres == NULL) {
            ipcctrl_err("ipcctrl unexpected interrupt, chn_id=%d, res_bit=%d\n", pchn->chn_id, i);
            continue;
        }
        ipcctrl_dump_trace(pchn->dump_index, i);
        if (pres->ipc_int_table.routine != NULL) {
            pres->ipc_int_table.routine(pres->ipc_int_table.arg);
            ipcctrl_dump_trace(pchn->dump_index, i);
        } else {
            ipcctrl_err("ipcctrl no interrupt routine, chn_id=%d, res_bit=%d\n", pchn->chn_id, i);
        }
    }
    return IRQ_HANDLED;
}

s32 ipcctrl_resources_init(device_node_s *chn_node, struct ipcctrl_channel_t *pchn)
{
    s32 ret;
    u32 i;
    u32 res_num, chn_id, res_mem_size;
    u32 id_array[RES_MAX_NUM] = { 0 };
    u32 bit_array[RES_MAX_NUM] = { 0 };
    struct ipcctrl_res_t *pres = NULL;

    chn_id = pchn->chn_id;
    ret = bsp_dt_property_read_u32(chn_node, "res_num", &res_num);
    if (ret || res_num >= RES_MAX_NUM) {
        ipcctrl_err("ipcctrl res_num get failed, chn_id=%d, res_num=%d, ret=%d\n", chn_id, res_num, ret);
        return IPCCTRL_ERR;
    }
    ret |= bsp_dt_property_read_u32_array(chn_node, "res_id_array", id_array, res_num);
    ret |= bsp_dt_property_read_u32_array(chn_node, "res_bit_array", bit_array, res_num);
    if (ret) {
        ipcctrl_err("ipcctrl res array get failed, chn_id=%d, ret=%d\n", chn_id, ret);
        return IPCCTRL_ERR;
    }

    res_mem_size = sizeof(struct ipcctrl_res_t) * res_num;
    pres = (struct ipcctrl_res_t *)osl_malloc(res_mem_size);
    if (pres == NULL) {
        ipcctrl_err("ipcctrl res malloc failed, chn_id=%d\n", chn_id);
        return IPCCTRL_MEM_ERR;
    }
    (void)memset_s(pres, res_mem_size, 0, res_mem_size);
    for (i = 0; i < res_num; ++i) {
        if (bit_array[i] >= RES_MAX_NUM || pchn->res[bit_array[i]]) {
            ipcctrl_err("ipcctrl res bit init failed, chn_id=%d, res_bit=%d\n", chn_id, bit_array[i]);
            goto RES_INIT_ERR;
        }
        (pres + i)->res_id = id_array[i];
        (pres + i)->res_id = id_array[i];
        (pres + i)->res_bit = bit_array[i];
        (pres + i)->handle.res_bit = bit_array[i];
        (pres + i)->handle.chn_index = g_ipcctrl_chn_index;
        (pres + i)->handle.magic = IPCCTRL_MAGIC;
        pchn->res[(pres + i)->res_bit] = (pres + i);
    }

    return IPCCTRL_OK;
RES_INIT_ERR:
    osl_free(pres);
    pres = NULL;
    return IPCCTRL_ERR;
}

struct ipcctrl_channel_t *ipcctrl_create_channel(device_node_s *chn_node, void *base_addr, u32 size)
{
    s32 ret;
    u32 i, chn_id, irq_no, is_mdm;
    u32 int_attr[0x3] = { 0 };   // send/recv unsafe/safe
    struct ipcctrl_channel_t *pchn = NULL;

    // 获取通道号
    ret = bsp_dt_property_read_u32(chn_node, "chn_id", &chn_id);
    if (ret || g_ipcctrl_chn_index >= CHN_MAX_NUM || g_ipcctrl_chn[g_ipcctrl_chn_index]) {
        ipcctrl_err("ipcctrl chn_id get failed, chn_id=%d, ret=%d\n", chn_id, ret);
        return NULL;
    }
    // 申请pchn堆内存
    pchn = (struct ipcctrl_channel_t *)osl_malloc(sizeof(struct ipcctrl_channel_t));
    if (pchn == NULL) {
        ipcctrl_err("ipcctrl channel malloc failed, chn_id=%d\n", chn_id);
        return NULL;
    }
    (void) memset_s((void *)pchn, sizeof(struct ipcctrl_channel_t), 0, sizeof(struct ipcctrl_channel_t));

    pchn->chn_id = chn_id;
    pchn->base_addr = (void *)((char *)base_addr + ((unsigned long)(chn_id) * 0x20));
    if ((char *)pchn->base_addr >= (char *)((char *)base_addr + size)) {
        ipcctrl_err("ipcctrl chn_id[%d] base_addr overflow\n", chn_id);
        goto CREATE_ERR;
    }
    // 获取通道接收属性 没读到表示是发送通道，否则为接收通道
    ret = bsp_dt_property_read_u32_array(chn_node, "interrupts", int_attr, sizeof(int_attr) / sizeof(int_attr[0]));
    if (ret == 0) { // 接收通道
        irq_no = bsp_dt_irq_parse_and_map(chn_node, 0);
        if (irq_no == 0) {
            ipcctrl_err("ipcctrl irq_no get failed, chn_id=%d\n", chn_id);
            goto CREATE_ERR;
        }
        pchn->irq_no = irq_no;
        pchn->is_recv = 1;
    } else { // 发送通道
        ret = bsp_dt_property_read_u32(chn_node, "is_mdm", &is_mdm);
        if (ret == 0) {
            pchn->is_mdm = 1;
        }
    }
    // 获取资源分配情况
    ret = ipcctrl_resources_init(chn_node, pchn);
    if (ret) {
        for (i = 0; i < RES_MAX_NUM; ++i) {
            pchn->res[i] = NULL;
        }
        ipcctrl_err("ipcctrl chn resources init failed, chn_id=%d, ret=%d\n", chn_id, ret);
        goto CREATE_ERR;
    }

    return pchn;
CREATE_ERR:
    osl_free(pchn);
    return NULL;
}

s32 ipcctrl_channels_init(void)
{
    s32 ret;
    u32 array_reg[0x2] = { 0 }; // base_addr size
    void *base_addr = NULL;
    device_node_s *parent_node = NULL;
    device_node_s local_node = { 0 };
    device_node_s *chn_node = &local_node; // 宏替换，&chn_node这样不行
    struct ipcctrl_channel_t *pchn = NULL;

    parent_node = bsp_dt_find_node_by_path((const char *)IPCCTRL_ACORE_DEVICE_NAME);
    if (parent_node == NULL) {
        ipcctrl_err("didn't find ipcctrl dt node!\n");
        return IPCCTRL_ERR;
    }
    ret = bsp_dt_property_read_u32_array(parent_node, "reg_parm", array_reg, sizeof(array_reg) / sizeof(array_reg[0]));
    if (ret) {
        ipcctrl_err("ipcctrl reg parm get failed, ret=%d\n", ret);
        return IPCCTRL_ERR;
    }

    base_addr = ioremap(array_reg[0x0], array_reg[0x1]);
    if (base_addr == NULL) {
        ipcctrl_err("ipcctrl ioremap failed\n");
        return IPCCTRL_ERR;
    }
    bsp_dt_for_each_child_of_node(parent_node, chn_node) {
        pchn = ipcctrl_create_channel(chn_node, base_addr, array_reg[0x1]);
        if (pchn == NULL) {
            ipcctrl_err("ipcctrl channel create failed\n");
            return IPCCTRL_ERR;
        }
        pchn->dump_index = g_ipcctrl_chn_index;
        g_ipcctrl_chn[g_ipcctrl_chn_index] = pchn;
        g_ipcctrl_chn_index++;
        ipcctrl_dump_chn_fastptr_record(pchn);
    }
    return IPCCTRL_OK;
}

s32 ipcctrl_interrupt_init(void)
{
    s32 ret;
    u32 i;
    u32 irq_no;
    struct ipcctrl_channel_t *pchn = NULL;

    for (i = 0; i < g_ipcctrl_chn_index; ++i) {
        pchn = g_ipcctrl_chn[i];
        if (pchn == NULL || pchn->is_recv == 0) {
            continue;
        }
        // 设置中断寄存器状态 - 屏蔽所有bit位中断
        writel(0xffffffff, (void *)((char *)pchn->base_addr + IPCCTRL_CPU_INT_MSK_EN));
        // 挂接中断处理函数
        irq_no = pchn->irq_no;
        ret = request_irq(irq_no, (irq_handler_t)ipcctrl_int_handler, IRQF_NO_SUSPEND,
            "ipcctrl_irq", (void *)(uintptr_t)(pchn));
        if (ret) {
            ipcctrl_err("ipcctrl chn_id[%d] request irq failed, ret=%d\n", pchn->chn_id, ret);
            return IPCCTRL_ERR;
        }
        // 设置中断唤醒源
        ret = enable_irq_wake(irq_no);
        if (ret) {
            ipcctrl_err("ipcctrl chn_id[%d] enable irq wake failed, ret=%d\n", ret);
            return IPCCTRL_ERR;
        }
    }

    return IPCCTRL_OK;
}

s32 bsp_ipc_open(ipc_res_id_e ipc_res_id, struct ipc_handle **ppipcctrl_hdl)
{
    struct ipc_handle *pipcctrl_hdl = NULL;

    if (g_ipcctrl_init_status == 0 || ppipcctrl_hdl == NULL) {
        return IPCCTRL_ERR;
    }

    pipcctrl_hdl = ipcctrl_handle_get(ipc_res_id);
    if (pipcctrl_hdl == NULL) {
        ipcctrl_err("ipcctrl handle open failed, res_id=%d\n", ipc_res_id);
        return IPCCTRL_ERR;
    }
    *ppipcctrl_hdl = pipcctrl_hdl;
    return IPCCTRL_OK;
}

s32 bsp_ipc_send(struct ipc_handle *pipcctrl_hdl)
{
    unsigned long lock_flag = 0;
    struct ipcctrl_channel_t *pchn = NULL;
    struct ipcctrl_res_t *pres = NULL;

    if (ipcctrl_get_byhandle(pipcctrl_hdl, &pchn, &pres)) {
        return IPCCTRL_ERR;
    }

    spin_lock_irqsave(&g_modem_reset_flag_lock, lock_flag);
    if (g_modem_reset_flag && pchn->is_mdm) {
        spin_unlock_irqrestore(&g_modem_reset_flag_lock, lock_flag);
        return IPC_ERR_MODEM_RESETING; // 定义在接口头文件中，不可改
    }
    spin_unlock_irqrestore(&g_modem_reset_flag_lock, lock_flag);

    writel((u32)IPCCTRL_BIT_MASK(pres->res_bit), (void *)((char *)pchn->base_addr + IPCCTRL_CPU_INT_EN));
    ipcctrl_dump_trace(pchn->dump_index, pres->res_bit);

    return IPCCTRL_OK;
}

s32 bsp_ipc_connect(struct ipc_handle *pipcctrl_hdl, ipc_cbk routine, void *parameter)
{
    struct ipcctrl_channel_t *pchn = NULL;
    struct ipcctrl_res_t *pres = NULL;

    if (ipcctrl_get_byhandle(pipcctrl_hdl, &pchn, &pres)) {
        return IPCCTRL_ERR;
    }

    pres->ipc_int_table.routine = routine;
    pres->ipc_int_table.arg = parameter;
    writel((u32)IPCCTRL_BIT_MASK(pres->res_bit), (void *)((char *)pchn->base_addr + IPCCTRL_CPU_INT_MSK_DIS));

    return IPCCTRL_OK;
}

void bsp_ipc_modem_reset(drv_reset_cb_moment_e stage, int userdata)
{
    unsigned long lock_flag = 0;

    spin_lock_irqsave(&g_modem_reset_flag_lock, lock_flag);
    if (stage == MDRV_RESET_CB_BEFORE) {
        g_modem_reset_flag = 1;
    }
    if (stage == MDRV_RESET_RESETTING) {
        g_modem_reset_flag = 0;
    }
    spin_unlock_irqrestore(&g_modem_reset_flag_lock, lock_flag);
    return;
}

void bsp_ccore_ipc_disable(void)
{
    return;
}

void bsp_ccore_ipc_enable(void)
{
    return;
}

int bsp_ipc_init(void)
{
    s32 ret;

    spin_lock_init(&g_modem_reset_flag_lock);
    ret = ipcctrl_dump_init();
    if (ret) {
        ipcctrl_err("ipcctrl_dump_init failed, ret=%d\n");
    }
    ret = ipcctrl_channels_init();
    if (ret) {
        ipcctrl_err("ipcctrl_device_init failed\n");
        return IPCCTRL_ERR;
    }
    ret = ipcctrl_interrupt_init();
    if (ret) {
        ipcctrl_err("ipcctrl_interrupt_init failed\n");
        return IPCCTRL_ERR;
    }

    ipcctrl_err("ipcctrl init done\n");
    g_ipcctrl_init_status = 1;

    return IPCCTRL_OK;
}

EXPORT_SYMBOL(bsp_ipc_open);
EXPORT_SYMBOL(bsp_ipc_connect);
EXPORT_SYMBOL(bsp_ipc_send);
EXPORT_SYMBOL(bsp_ipc_modem_reset);
EXPORT_SYMBOL(bsp_ccore_ipc_enable);
EXPORT_SYMBOL(bsp_ccore_ipc_disable);

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
arch_initcall(bsp_ipc_init);
MODULE_LICENSE("GPL");
#endif