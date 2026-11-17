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
#include <bsp_dt.h>
#include <bsp_dump.h>
#include <bsp_print.h>
#include "buserr_probe.h"
#include "buserr_base.h"
#include "buserr_pdlock.h"

#ifdef __cplusplus
extern "C" {
#endif

buserr_ctrl_s g_buserr_ctrl = { 0 };

buserr_ctrl_s* bsp_buserr_ctrl(void)
{
    return &g_buserr_ctrl;
}

struct buserr_sysctrl *bsp_buserr_sctrl_get_by_irq(u32 irq)
{
    if (g_buserr_ctrl.sctrl_peri.irq == irq) {
        return &g_buserr_ctrl.sctrl_peri;
    }
    return NULL;
}

void buserr_init_fail(struct buserr_sysctrl *sysctrl)
{
    u32 reg_id;

    if (sysctrl->err_state_reg != NULL) {
        for (reg_id = 0; reg_id < sysctrl->reg_sum; reg_id++) {
            if (sysctrl->err_state_reg[reg_id].err_state_bit != NULL) {
                kfree(sysctrl->err_state_reg[reg_id].err_state_bit);
                sysctrl->err_state_reg[reg_id].err_state_bit = NULL;
                sysctrl->err_state_reg[reg_id].bit_sum = 0;
            }
        }
        kfree(sysctrl->err_state_reg);
        sysctrl->err_state_reg = NULL;
    }
    (void)memset_s(sysctrl, sizeof(struct buserr_sysctrl), 0, sizeof(struct buserr_sysctrl));
}

int buserr_type_init(device_node_s *child, struct buserr_sysctrl *sysctrl, u32 reg_id, u32 bit_sum)
{
    struct property *prop = NULL;
    const __be32 *p = NULL;
    u32 i = 0;
    u32 j = 0;
    u32 u = 0;
    u32 v = 0;

    bsp_dt_property_for_each_u32(child, "err_type", prop, p, v) {
        if (j >= bit_sum) {
            bus_printf("j=%d exceed!\n", j);
            return -1;
        }
        sysctrl->err_state_reg[reg_id].err_state_bit[j++].err_type = v;
    }
    bsp_dt_property_for_each_u32(child, "err_state_bit", prop, p, u) {
        if (i >= bit_sum) {
            bus_printf("i=%d exceed!\n", i);
            return -1;
        }
        sysctrl->err_state_reg[reg_id].err_state_bit[i++].bit = u;
    }
    return 0;
}

int buserr_name_init(device_node_s *child, struct buserr_sysctrl *sysctrl, u32 reg_id, u32 bit_sum)
{
    const char *temp_name = NULL;
    u32 i = 0;
    int ret;

    for (i = 0; i < bit_sum; i++) {
        ret = bsp_dt_property_read_string_index(child, "err_name", (s32)i, &temp_name);
        if (ret || temp_name == NULL) {
            bus_printf("read err_name failed!\n");
            return -1;
        }
        ret = strncpy_s(sysctrl->err_state_reg[reg_id].err_state_bit[i].err_name,
                             ERR_NAME_LENGTH,
                             temp_name,
                             ERR_NAME_LENGTH - 1);
        if (ret) {
            bus_printf("copy err_name failed!\n");
            return -1;
        }
    }
    return 0;
}

int buserr_state_reg_analyze(device_node_s *dev, struct buserr_sysctrl *sysctrl)
{
    u32 ret, reg_offset, bit_sum;
    u32 reg_id = 0;
    device_node_s *child = NULL;

    bsp_dt_for_each_child_of_node(dev, child) {
        ret = (u32)bsp_dt_property_read_u32(child, "err_state_reg_id", &reg_id);
        ret |= (u32)bsp_dt_property_read_u32(child, "err_state_reg_offset", &reg_offset);
        ret |= (u32)bsp_dt_property_read_u32(child, "err_state_bit_sum", &bit_sum);
        if (ret || bit_sum == 0) {
            bus_printf("read value fail\n");
            return -1;
        }
        if (reg_id >= sysctrl->reg_sum) {
            bus_printf("reg_id=%d exceed!\n", reg_id);
            return -1;
        }
        sysctrl->err_state_reg[reg_id].err_state_reg_offset = reg_offset;
        sysctrl->err_state_reg[reg_id].bit_sum = bit_sum;
        sysctrl->err_state_reg[reg_id].err_state_bit =
            (struct buserr_state_bit *)kmalloc(bit_sum * (sizeof(struct buserr_state_bit)), GFP_KERNEL);
        if (sysctrl->err_state_reg[reg_id].err_state_bit == NULL) {
            bus_printf("malloc fail\n");
            return -1;
        }
        (void)memset_s(sysctrl->err_state_reg[reg_id].err_state_bit,
                       bit_sum * (sizeof(struct buserr_state_bit)), 0,
                       bit_sum * (sizeof(struct buserr_state_bit)));
        ret = buserr_type_init(child, sysctrl, reg_id, bit_sum);
        if (ret) {
            return -1;
        }

        ret = buserr_name_init(child, sysctrl, reg_id, bit_sum);
        if (ret) {
            return -1;
        }
    }
    return 0;
}

int buserr_sctrl_addr_init(device_node_s *dev, struct buserr_sysctrl *sysctrl)
{
    u32 phy_sysctrl_base_addr;
    int ret;

    ret = bsp_dt_property_read_u32(dev, "sysctrl_base_address", &phy_sysctrl_base_addr);
    if (ret) {
        bus_printf("rd sysctrl_base_addr fail\n");
        return -1;
    }
    sysctrl->base_addr = ioremap((phys_addr_t)((uintptr_t)phy_sysctrl_base_addr), IOREMAP_LENGTH);
    if (sysctrl->base_addr == NULL) {
        bus_printf("vir_enable_addr is null!\n");
        return -1;
    }

    return 0;
}

int buserr_child_irq_request(device_node_s *dev, struct buserr_sysctrl *sysctrl, const char *irq_name)
{
    int ret;
    if (dev == NULL) {
        bus_printf("not found, skip register\n");
        return 0;
    }

    sysctrl->irq = bsp_dt_irq_parse_and_map(dev, 0);
    if (sysctrl->irq <= 0 ) {
        bus_printf("get irq fail, irq = %d\n", sysctrl->irq);
        return -1;
    }
    ret = request_irq(sysctrl->irq, (irq_handler_t)buserr_int_handler, 0, irq_name, NULL);
    if (ret) {
        bus_printf("req irq fail\n");
        return -1;
    }
    return 0;
}

int buserr_child_cfg_init(const char *path, struct buserr_sysctrl *sysctrl, const char *irq_name)
{
    u32 size;
    int ret;
    device_node_s *dev = bsp_dt_find_compatible_node(NULL, NULL, path);
    if (dev == NULL) {
        bus_printf("skip get state_reg\n");
        return 0;
    }

    ret = bsp_dt_property_read_u32(dev, "err_state_reg_sum", &sysctrl->reg_sum);
    if (ret) {
        bus_printf("rd err_state_reg_sum fail\n");
        return -1;
    }
    if (sysctrl->reg_sum == 0) {
        return 0;
    }

    ret = buserr_sctrl_addr_init(dev, sysctrl);
    if (ret) {
        buserr_init_fail(sysctrl);
        return -1;
    }

    size = sysctrl->reg_sum * (sizeof(struct buserr_state_reg));
    sysctrl->err_state_reg = (struct buserr_state_reg *)kmalloc(size, GFP_KERNEL);
    if (sysctrl->err_state_reg == NULL) {
        bus_printf("malloc resource fail\n");
        buserr_init_fail(sysctrl);
        return -1;
    }
    (void)memset_s(sysctrl->err_state_reg, size, 0, size);

    ret = buserr_state_reg_analyze(dev, sysctrl);
    if (ret) {
        buserr_init_fail(sysctrl);
        return -1;
    }

    ret = buserr_child_irq_request(dev, sysctrl, irq_name);
    if (ret) {
        buserr_init_fail(sysctrl);
        return ret;
    }
    return 0;
}

int buserr_dts_cfg_init(void)
{
    int ret;
    ret = buserr_child_cfg_init("mdmperi_busprobe", &g_buserr_ctrl.sctrl_peri, "buserr_sys_irq");
    if (ret) {
        return -1;
    }
    return 0;
}

void buserr_irq_disable_check(void)
{
    if (g_buserr_ctrl.cfg.int_en == true) {
        return;
    }

    bus_printf("disable irq = %d!\n", g_buserr_ctrl.sctrl_peri.irq);
    disable_irq(g_buserr_ctrl.sctrl_peri.irq);
}

void buserr_rst_cfg_init(void)
{
    g_buserr_ctrl.cfg.int_en = true;
    g_buserr_ctrl.cfg.axi_rst = true;
    g_buserr_ctrl.cfg.qic_rst = true;
}

int bsp_buserr_init(void)
{
    int ret;
    bus_printf("[init]start\n");

    buserr_rst_cfg_init();

    ret = buserr_dts_cfg_init();
    if (ret) {
        return -1;
    }

    ret = bsp_pdlock_init();
    if (ret) {
        return -1;
    }

    ret = bsp_buserr_probe_init();
    if (ret) {
        return -1;
    }

    buserr_irq_disable_check();

    bus_printf("[init]ok\n");
    return 0;
}