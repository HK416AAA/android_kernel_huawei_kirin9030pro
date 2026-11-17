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

/*lint --e{537}*/
#include <linux/module.h>
#include <bsp_dt.h>
#include <bsp_print.h>
#include <bsp_slice.h>

#undef THIS_MODU
#define THIS_MODU mod_slice

#define slice_err(fmt, ...) dpa_pr_err("<%s> "fmt"", __FUNCTION__, ##__VA_ARGS__)

#define SYSCOUNT_OK 0
#define SYSCOUNT_ERROR (-1)

struct timerslice_control {
    void *timerslice_base_addr;
    void *timerslice_base_addr_phy; /* 时间戳实地址 */
    void *timerslice_hrt_base_addr; /* udelay timer stamp addr */
    u32 hrt_slice_is_increase;
    u32 slice_is_increase;
    u32 hrt_slice_offset[0x2]; /* udelay timer stamp 偏移 */
    u32 slice_offset[2];     /* 32k slice offset */
    u32 hrt_slice_clock_freq;
    u32 slice_clock_freq;
    u32 is_inited_flag;
};

struct timerslice_control g_slice_ctrl = {0};

u32 bsp_get_slice_value(void)
{
    if (g_slice_ctrl.is_inited_flag) {
        u32 slice = readl((void *)((uintptr_t)g_slice_ctrl.timerslice_base_addr + g_slice_ctrl.slice_offset[0]));
        if (g_slice_ctrl.slice_is_increase) {
            return slice;
        } else {
            return (U32_MAX_VALUE - slice);
        }
    } else {
        return 0;
    }
}

u32 bsp_get_slice_value_hrt(void)
{
    if (g_slice_ctrl.is_inited_flag) {
        u32 slice = readl(
            (void *)((uintptr_t)g_slice_ctrl.timerslice_hrt_base_addr + g_slice_ctrl.hrt_slice_offset[0]));
        if (g_slice_ctrl.hrt_slice_is_increase) {
            return slice;
        } else {
            return (U32_MAX_VALUE - slice);
        }
    } else {
        return 0;
    }
}

u32 bsp_get_elapse_ms(void)
{
    u64 tmp;
    unsigned long timer_get;

    if (g_slice_ctrl.is_inited_flag) {
        timer_get = bsp_get_slice_value();
        tmp = (u64)(timer_get & U32_MAX_VALUE);
        tmp = tmp * SLICE_CONVERT_DELTA;
        tmp = div_u64(tmp, g_slice_ctrl.slice_clock_freq);
        return (u32)tmp;
    } else {
        return 0;
    }
}

u32 bsp_get_slice_freq(void)
{
    return g_slice_ctrl.slice_clock_freq;
}

u32 bsp_get_hrt_slice_freq(void)
{
    return g_slice_ctrl.hrt_slice_clock_freq;
}

int slice_info(device_node_s *node)
{
    void *vaddr = NULL;
    unsigned int regs[2] = {0, 0};
    u32 ret;

    ret = bsp_dt_property_read_u32_array(node, "reg", &regs[0], 2);
    if (ret) {
        slice_err("timer slice get reg failed.\n");
        return SYSCOUNT_ERROR;
    }

    g_slice_ctrl.timerslice_base_addr_phy = (void *)(uintptr_t)regs[0];
    vaddr = ioremap((phys_addr_t)(uintptr_t)regs[0], regs[1]);
    if (vaddr == NULL) {
        slice_err("timer slice iomap failed.\n");
        return SYSCOUNT_ERROR;
    }
    g_slice_ctrl.timerslice_base_addr = vaddr;

    ret = bsp_dt_property_read_u32(node, "increase_count_flag", &g_slice_ctrl.slice_is_increase);
    /* 32k slice使用2个32位寄存器计数 */
    ret += bsp_dt_property_read_u32_array(node, "offset", g_slice_ctrl.slice_offset, 2);
    ret += bsp_dt_property_read_u32(node, "clock-frequency", &g_slice_ctrl.slice_clock_freq);
    if (ret) {
        slice_err("timer slice property get failed.\n");
        return SYSCOUNT_ERROR;
    }
    return SYSCOUNT_OK;
}

int slice_init(device_node_s *p_node)
{
    device_node_s *node = NULL;

    node = bsp_dt_get_child_by_name(p_node, "timerslice");
    if (node == NULL) {
        slice_err("timer slice find_compatible_node failed.\n");
        return SYSCOUNT_ERROR;
    }

    if (!bsp_dt_device_is_available(node)) {
        slice_err("timer slice dts status is not ok.\n");
        return SYSCOUNT_ERROR;
    }
    if (slice_info(node) == SYSCOUNT_ERROR) {
        return SYSCOUNT_ERROR;
    }

    return SYSCOUNT_OK;
}

int hrt_slice_init(device_node_s *p_node)
{
    device_node_s *node = NULL;
    void *vaddr = NULL;
    unsigned int regs[2] = {0, 0};
    s32 ret;

    node = bsp_dt_get_child_by_name(p_node, "hrttimer_app");
    if (node == NULL) {
        slice_err("timer_hrtslice find_compatible_node failed.\n");
        return SYSCOUNT_ERROR;
    }
    if (!bsp_dt_device_is_available(node)) {
        slice_err("timer hrtslice dts status is not ok.\n");
        return SYSCOUNT_ERROR;
    }
    ret = bsp_dt_property_read_u32_array(node, "reg", &regs[0], 2);
    if (ret) {
        slice_err("timer hrtslice get reg failed.\n");
        return SYSCOUNT_ERROR;
    }
    /* 内存映射，获得基址 */
    vaddr = ioremap((phys_addr_t)(uintptr_t)regs[0], regs[1]);
    if (vaddr == NULL) {
        slice_err("hrttimer_app iomap failed.\n");
        return SYSCOUNT_ERROR;
    }
    g_slice_ctrl.timerslice_hrt_base_addr = vaddr;
    ret = bsp_dt_property_read_u32(node, "increase_count_flag", &g_slice_ctrl.hrt_slice_is_increase);
    if (ret) {
        slice_err("timer_hrtslice get increase_count_flag failed.\n");
        return SYSCOUNT_ERROR;
    }
    ret = bsp_dt_property_read_u32(node, "clock-frequency", &g_slice_ctrl.hrt_slice_clock_freq);
    if (ret) {
        slice_err("timer_hrtslice get frequency failed.\n");
        return SYSCOUNT_ERROR;
    }
    ret = bsp_dt_property_read_u32_array(node, "offset", g_slice_ctrl.hrt_slice_offset, 0x2);
    if (ret) {
        slice_err("timer_hrtslice get offset failed.\n");
        return SYSCOUNT_ERROR;
    }

    return SYSCOUNT_OK;
}

int bsp_slice_init(void)
{
    int ret;
    device_node_s *node = NULL;

    node = bsp_dt_find_compatible_node(NULL, NULL, "dpa,syscount");

    ret = slice_init(node);
    if (ret) {
        slice_err("slice_init failed.\n");
        return SYSCOUNT_ERROR;
    }
    ret = hrt_slice_init(node);
    if (ret) {
        slice_err(" hrt_slice_initfailed.\n");
        return SYSCOUNT_ERROR;
    }
    g_slice_ctrl.is_inited_flag = 1;
    slice_err("syscount init ok.\n");
    return SYSCOUNT_OK;
}

