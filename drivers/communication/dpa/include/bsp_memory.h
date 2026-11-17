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

#ifndef BSP_MEMORY_H
#define BSP_MEMORY_H

#include <bsp_print.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef phy_addr_t
typedef unsigned long phy_addr_t;
#endif

/**
 * @brief 共享内存属性.
 */
typedef enum {
    SHM_UNSEC = 0x0,
    SHM_SEC,
    SHM_NSRO,
    SHM_ATTR_MAX
} mdrv_shm_attr_e;

/**
 * @brief 申请共享内存
 * @par 描述:
 * 申请共享内存
 * @param[in] name: 要获取的共享内存段名称（名称在DTS中注册）name长度不超过32字节
 * @param[in] phy_addr: 分配的共享内存段的物理地址
 * @param[in] size: 分配的共享内存段的大小
 * @param[in] flag: 分配的共享内存段的属性，当前支持三种，对应枚举mdrv_shm_attr_e，分别为
 * SHM_UNSEC：非安全共享内存
 * SHM_SEC：安全共享内存
 * SHM_NSRO：非安全只读安全可读写共享内存
 * @retval NULL 申请失败
 * @retval 其它 返回共享内存段的虚拟地址
 * @see mdrv_shm_attr_e
 */
void *mdrv_mem_share_get(const char *name, unsigned long *addr, unsigned int *size, unsigned int flag);

/**
 * @brief 获取DDR内存布局
 * @par 描述:
 * 获取DDR内存布局
 * @param[in] name: 要获取的DDR内存段名称（名称在DTS中注册）name长度不超过16字节
 * ------名称-------------说明--------------
 * "mntn_ddr_dpa"       dpa维测内存空间
 * "dpa_mo"             dpa mo空间
 * "dpa_fw"             dpa fw空间
 * -----------------------------------------
 * @param[in] size: ddr内存段的大小
 * @retval 0 申请失败
 * @retval 其它 返回DDR内存段的物理地址
 */
unsigned long mdrv_mem_region_get(const char *name, unsigned int *size);


#ifdef __cplusplus
}
#endif
#endif
