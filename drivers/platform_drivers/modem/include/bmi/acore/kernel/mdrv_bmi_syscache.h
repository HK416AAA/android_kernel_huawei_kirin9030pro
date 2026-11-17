/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2023. All rights reserved.
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

/**
 *  @brief   飞龙架构2.0 syscache模块对外头文件
 *  @file    mdrv_bmi_syscache.h
 *  @version v1.0
 *  @date    2024.10.11
 *  @note    该文件增删改需通过接口变更评审
 *  <ul><li>v1.0|2024.10.11|创建文件</li></ul>
 *  @since
 */

#ifndef _MDRV_BMI_SYSCACHE_H_
#define _MDRV_BMI_SYSCACHE_H_

#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/dma-mapping.h>

/**
 * @brief 刷新syscache
 *
 * @par 描述:
 * 刷新syscache
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  dev, 设备信息
 * @param[in]  addr, DMA地址
 * @param[in]  size, 刷新内存的大小
 * @param[in]  dir，DMA映射方向
 * @param[out]  NA
 *
 * @retval NA
 *
 * @see NA
 */
void mdrv_sc_dma_unmap_single(struct device *dev, dma_addr_t addr, size_t size, enum dma_data_direction dir);

/**
 * @brief 映射DMA地址
 *
 * @par 描述:
 * 映射DMA地址
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  dev, 设备信息
 * @param[in]  addr, DMA地址
 * @param[in]  size, 映射内存的大小
 * @param[in]  dir，DMA映射方向
 * @param[out]  NA
 *
 * @retval NULL, 申请失败
 * @retval 其他, dma_addr_t, 映射出的DMA地址
 *
 * @see NA
 */
dma_addr_t mdrv_sc_dma_map_single(struct device *dev, void *addr, size_t size, enum dma_data_direction dir);

/**
 * @brief 申请ringbuf内存
 *
 * @par 描述:
 * 申请ringbuf内存
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  dev, 设备信息
 * @param[in]  size, 分配内存的大小
 * @param[in]  gfp, 分配内存的标志位
 * @param[out]  phy_addr,实际的物理地址
 *
 * @retval NULL, 申请失败
 * @retval 其他，char *，申请到的内存虚拟地址
 *
 * @see NA
 */
char *mdrv_sc_alloc_ringbuf(struct device *dev, unsigned int size, unsigned long long *phy_addr, gfp_t gfp);

/**
 * @brief 释放ringbuf内存
 *
 * @par 描述:
 * 释放ringbuf内存
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  dev, 设备信息
 * @param[in]  size, 分配内存的大小
 * @param[in]  cpu_addr, 虚拟地址
 * @param[in]  dma_handle, 物理地址
 * @param[out]  NA
 *
 * @retval NA
 *
 * @see NA
 */
void mdrv_sc_free_ringbuf(struct device *dev, size_t size, void *cpu_addr, dma_addr_t dma_handle);
#endif