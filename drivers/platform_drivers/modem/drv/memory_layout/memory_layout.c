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

#include "memory_layout.h"
#include <linux/module.h>
#include <linux/version.h>
#include <mdrv_memory.h>
#include <product_config.h>
#include <bsp_sysboot.h>
#include <bsp_dt.h>
#include <securec.h>
#include <bsp_sec_call.h>
#include <bsp_version.h>

#ifdef BSP_CONFIG_PHONE_TYPE
#include <adrv_om.h>
#endif

#ifndef BSP_CONFIG_PHONE_TYPE
mem_layout g_mem_layout_info;

unsigned long mdrv_mem_region_get(const char *name, unsigned int *size)
{
    mem_node_info *mem_info = NULL;
    unsigned int max_rec;
    unsigned long phy_addr;
    unsigned int i;

    if (name == NULL || size == NULL) {
        MEM_ERR("[memory_layout]input error!\n");
        return 0;
    }

    mem_info = g_mem_layout_info.memory_info;
    max_rec = g_mem_layout_info.size / sizeof(mem_node_info);
    for (i = 0; i < max_rec; i++) {
        if (strcmp((mem_info + i)->name, name) == 0) {
            phy_addr = (unsigned long)((mem_info + i)->addr);
            *size = (mem_info + i)->size;
            return phy_addr;
        }
    }
    *size = 0;
    MEM_ERR("[memory_layout]get memory %s error!\n", name);
    return 0;
}
EXPORT_SYMBOL_GPL(mdrv_mem_region_get);

int bsp_memory_layout_init(void)
{
    int ret;
    unsigned long addr;
    void *virt_addr = NULL;

    MEM_ERR("[memory_layout]init start\n");
    addr = DDR_MEM_LAYOUT_ADDR;
    g_mem_layout_info.size = DDR_MEM_LAYOUT_SIZE;
    virt_addr = ioremap_wc(DDR_MEM_LAYOUT_ADDR, DDR_MEM_LAYOUT_SIZE);
    if (virt_addr == NULL) {
        MEM_ERR("[memory_layout]get virt_addr error\n");
        return ERROR;
    }
    ret = bsp_sysboot_set_modem_para(MODEM_MEM_LAYOUT_ADDR_OFFSET, (u32)addr);
    if (ret) {
        MEM_ERR("[memory_layout]set memory layout addr failed\n");
        return ERROR;
    }
    ret = bsp_sysboot_set_modem_para(MODEM_MEM_LAYOUT_SIZE_OFFSET, g_mem_layout_info.size);
    if (ret) {
        MEM_ERR("[memory_layout]set memory layout size failed\n");
        return ERROR;
    }
    g_mem_layout_info.memory_info = (mem_node_info *)(uintptr_t)virt_addr;

    MEM_ERR("[memory_layout]init ok\n");
    return OK;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
pure_initcall(bsp_memory_layout_init); /*lint !e528*/
#endif

#else
static int mem_disable_bbpds_memlayout(void)
{
    const bsp_version_info_s *verinfo = bsp_get_version_info();
    if ((verinfo != NULL) && (verinfo->plat_type != PLAT_ASIC)) {
        return 0;
    }

    if (get_mdm_bbpds_mem_flag() == 0) {
        return bsp_sec_call(FUNC_MEM_LAYOUT_CMD, MEM_LAYOUT_CMD_DISABLE_BBPDS);
    }

    return 0;
}

int bsp_memory_layout_init(void)
{
    MEM_ERR("[memory_layout]init start\n");
    if (mem_disable_bbpds_memlayout()) {
        MEM_ERR("[memory]mem_disable_bbpds_layout failed\n");
        return ERROR;
    }

    MEM_ERR("[memory_layout]init ok\n");
    return OK;
}
#endif /* #ifndef BSP_CONFIG_PHONE_TYPE */
