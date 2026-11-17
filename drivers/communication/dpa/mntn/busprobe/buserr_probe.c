/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
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
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <securec.h>
#include <bsp_dump.h>
#include <bsp_print.h>
#include "buserr_base.h"
#include "buserr_probe.h"

#ifdef __cplusplus
extern "C" {
#endif

static LIST_HEAD(g_bus_notifier_list);
static DEFINE_SPINLOCK(g_bus_notifier_spin);

s32 bsp_buserr_register_hook(const char *name, buserr_exc_handler func, u32 type)
{
    int ret;
    buserr_notifier_s *hook_node = NULL;
    unsigned long flags = 0;

    if (name == NULL || func == NULL) {
        bus_printf("para err\n");
        return -1;
    }

    hook_node = (buserr_notifier_s*)kmalloc(sizeof(buserr_notifier_s), GFP_KERNEL);
    if (hook_node == NULL) {
        bus_printf("malloc node fail\n");
        return -1;
    }

    ret = memset_s(hook_node, sizeof(buserr_notifier_s), 0, sizeof(buserr_notifier_s));
    if (ret) {
        kfree(hook_node);
        bus_printf("memset node fail\n");
        return -1;
    }
    hook_node->func = func;
    hook_node->type = type;
    ret = strcpy_s(hook_node->name, BUS_NOTIFIER_NAME_LEN, name);
    if (ret) {
        kfree(hook_node);
        bus_printf("strcpy name fail\n");
        return -1;
    }

    spin_lock_irqsave(&g_bus_notifier_spin, flags);
    list_add_tail(&hook_node->hook_list, &g_bus_notifier_list);
    spin_unlock_irqrestore(&g_bus_notifier_spin, flags);

    return 0;
}

s32 bsp_buserr_unregister_hook(buserr_exc_handler func)
{
    buserr_notifier_s *temp_node = NULL;
    buserr_notifier_s *hook_node = NULL;
    unsigned long flags = 0;

    if (func == NULL) {
        return -1;
    }

    spin_lock_irqsave(&g_bus_notifier_spin, flags);

    list_for_each_entry(temp_node, &g_bus_notifier_list, hook_list)
    {
        if ((uintptr_t)(temp_node->func) == (uintptr_t)func) {
            hook_node = temp_node;
            break;
        }
    }
    if (hook_node == NULL) {
        spin_unlock_irqrestore(&g_bus_notifier_spin, flags);
        return -1;
    }

    list_del(&hook_node->hook_list);
    kfree(hook_node);
    hook_node = NULL;
    spin_unlock_irqrestore(&g_bus_notifier_spin, flags);

    return 0;
}

irqreturn_t bus_notify_call_chain(u32 type)
{
    irqreturn_t ret = 0;
    struct list_head *p = NULL;
    struct list_head *n = NULL;
    buserr_notifier_s *node = NULL;

    list_for_each_safe(p, n, &g_bus_notifier_list) {
        node = list_entry(p, buserr_notifier_s, hook_list);
        if ((node != NULL) && (node->type == type)) {
            ret = node->func();
        }
    }
    return ret;
}

irqreturn_t buserr_int_handler(int irq, void *base)
{
    u32 val, i, j;
    u32 type = BUS_ERR_MAGIC_NUM;
    irqreturn_t irq_ret = IRQ_HANDLED;
    struct buserr_sysctrl *sysctrl = bsp_buserr_sctrl_get_by_irq((u32)irq);
    if (sysctrl == NULL) {
        bus_printf("sysctrl is null ,irq no %d\n", irq);
        return IRQ_HANDLED;
    }

    disable_irq_nosync(sysctrl->irq);

    sysctrl->int_counter++;
    bus_printf("bus err counter = %d\n", sysctrl->int_counter);

    if ((sysctrl->base_addr == NULL) || (sysctrl->err_state_reg == NULL)) {
        bus_printf("base addr is null in irq!\n");
        enable_irq(sysctrl->irq);
        return IRQ_NONE;
    }
    for (i = 0; i < sysctrl->reg_sum; ++i) {
        val = readl((void *)((uintptr_t)sysctrl->base_addr + sysctrl->err_state_reg[i].err_state_reg_offset));
        bus_printf("bus err state reg(0x%x) = 0x%x\n", sysctrl->err_state_reg[i].err_state_reg_offset, val);
        if (val == 0) {
            continue;
        }

        for (j = 0; j < sysctrl->err_state_reg[i].bit_sum; ++j) {
            if (val & BIT(sysctrl->err_state_reg[i].err_state_bit[j].bit)) {
                bus_printf("bit %d, err bus name: %s !\n",
                           sysctrl->err_state_reg[i].err_state_bit[j].bit,
                           sysctrl->err_state_reg[i].err_state_bit[j].err_name);
                type = sysctrl->err_state_reg[i].err_state_bit[j].err_type;
                irq_ret = bus_notify_call_chain(type);
            }
        }
    }
    bus_printf("done\n");
    return irq_ret;
}

#ifdef __cplusplus
}
#endif

