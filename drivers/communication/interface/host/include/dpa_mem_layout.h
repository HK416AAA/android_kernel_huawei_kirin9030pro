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
#ifndef __DPA_MEM_LAYOUT_H
#define __DPA_MEM_LAYOUT_H

#include <linux/dma-mapping.h>

#ifdef __cplusplus /* __cplusplus */
extern "C"
{
#endif /* __cplusplus */

struct dpa_mem_ops {
    void *(*dpa_cma_alloc)(size_t size, dma_addr_t *dma_handle, gfp_t gfp);
    void (*dpa_cma_free)(size_t size, void *cpu_addr, dma_addr_t dma_handle);
    void *(*dpa_cma_cache_alloc)(size_t size, dma_addr_t *dma_handle, gfp_t gfp);
    void (*dpa_cma_cache_free)(size_t size, void *cpu_addr, dma_addr_t dma_handle);
};

/**
 * @brief 注册dpa mem内核API
 *
 * @par 描述:
 * 注册dpa mem内核API，注册后mem系列ops接口才能使用
 *
 * @attention
 * <ul><li>dpa host注册成功，内核才能使用mem api</li></ul>
 *
 * @param[in] ops, 回调函数
 *
 * @retval == 0,注册API成功。
 * @retval < 0,注册API不成功。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */

int dpa_mem_api_register(struct dpa_mem_ops *ops);

/**
 * @brief 同bsp_dpa_cma_alloc
 */
void *dpa_cma_alloc_ops(size_t size, dma_addr_t *dma_handle, gfp_t gfp);

/**
 * @brief 同bsp_dpa_cma_free
 */
void dpa_cma_free_ops(size_t size, void *cpu_addr, dma_addr_t dma_handle);

/**
 * @brief 同bsp_dpa_cma_cache_alloc
 */
void *dpa_cma_cache_alloc_ops(size_t size, dma_addr_t *dma_handle, gfp_t gfp);

/**
 * @brief 同bsp_dpa_cma_cache_free
 */
void dpa_cma_cache_free_ops(size_t size, void *cpu_addr, dma_addr_t dma_handle);

/**
 * @brief 申请dpa cma内存
 *
 * @par 描述:
 * 当前实现本质上就是bsp_dpa_cma_cache_alloc
 *
 * @attention
 * <ul><li>内存大小按page为单位。</li></ul>
 *
 * @param[in] size, 内存大小
 * @param[in] dma_handle, 物理地址指针
 * @param[in] gfp, 内存申请模式
 *
 * @retval == NULL,没有分配成功或者函数不支持。
 * @retval != NULL,表示分配成功，返回虚拟地址。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void *bsp_dpa_cma_alloc(size_t size, dma_addr_t *dma_handle, gfp_t gfp);

/**
 * @brief 释放dpa cma内存
 *
 * @par 描述:
 * 当前实现本质上就是bsp_dpa_cma_cache_free
 *
 * @param[in] size, 内存大小
 * @param[in] cpu_addr, 虚拟地址
 * @param[in] dma_handle, 物理地址
 *
 * @retval void。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void bsp_dpa_cma_free(size_t size, void *cpu_addr, dma_addr_t dma_handle);

/**
 * @brief 申请dpa cma cache内存
 *
 * @par 描述:
 * 申请内存
 * 内存在低4G空间，从DPA CMA申请, ACPU上为cache内存
 * 额外的，此内存在DPA子系统进行了cache的map，并做了一致性sc的map
 * 所以使用此内存，不要再进行sc的map。
 * 此内存难以进行ACPU和DPA实时互操作，基于cache line的单项同步仅需要在DPA上做DCC的管理
 *
 * @attention
 * <ul><li>内存大小按page为单位。</li></ul>
 *
 * @param[in] size, 内存大小
 * @param[in] dma_handle, 物理地址指针
 * @param[in] gfp, 内存申请模式
 *
 * @retval == NULL,没有分配成功或者函数不支持。
 * @retval != NULL,表示分配成功，返回虚拟地址。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void *bsp_dpa_cma_cache_alloc(size_t size, dma_addr_t *dma_handle, gfp_t gfp);

/**
 * @brief 释放dpa cma cache内存
 *
 * @par 描述:
 * 归还内存
 *
 * @param[in] size, 内存大小
 * @param[in] cpu_addr, 虚拟地址
 * @param[in] dma_handle, 物理地址
 *
 * @retval void。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void bsp_dpa_cma_cache_free(size_t size, void *cpu_addr, dma_addr_t dma_handle);

/**
 * @brief 申请预留dpa cma uncache内存
 *
 * @par 描述:
 * 内存在低4G空间，从DPA CMA申请, ACPU上为uncache内存
 * 额外的，此内存在DPA子系统进行了uncache的map，没有进行sc的map
 * 使用此内存，不要再进行sc的map,否则难以进行一致性维护
 * 此内存在ACPU和DPA上访问都不经过任何Cache，可进行共享互操作(当前主要UDX,DFA使用)
 *
 * @attention
 * <ul><li>内存大小按page为单位。</li></ul>
 *
 * @param[in] size, 内存大小
 * @param[in] dma_handle, 物理地址指针
 *
 * @retval == NULL,没有分配成功或者函数不支持。
 * @retval != NULL,表示分配成功，返回虚拟地址。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void *bsp_dpa_rsv_cma_alloc(size_t size, dma_addr_t *dma_handle);

/**
 * @brief 释放预留dpa cma uncache内存
 *
 * @par 描述:
 * 归还内存
 *
 * @param[in] size, 内存大小
 * @param[in] cpu_addr, 虚拟地址
 * @param[in] dma_handle, 物理地址
 *
 * @retval void。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void bsp_dpa_rsv_cma_free(size_t size, void *cpu_addr, dma_addr_t dma_handle);

/**
 * @brief 申请预留dpa cma cache内存
 *
 * @par 描述:
 * 内存在低4G空间，从DPA CMA申请, ACPU上为cache内存
 * 额外的，此内存在DPA子系统进行了uncache的map，并做了一致性sc的映射
 * 所以使用此内存，不要再进行sc的map
 * 此内存在ACPU和DPA上可进行共享互操作，由sc来保证一致性(当前主要PFA MAA-Table使用)
 *
 * @attention
 * <ul><li>内存大小按page为单位。</li></ul>
 *
 * @param[in] size, 内存大小
 * @param[in] dma_handle, 物理地址指针
 *
 * @retval == NULL,没有分配成功或者函数不支持。
 * @retval != NULL,表示分配成功，返回虚拟地址。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void *bsp_dpa_rsv_cma_cache_alloc(size_t size, dma_addr_t *dma_handle);

/**
 * @brief 释放预留dpa cma cache内存
 *
 * @par 描述:
 * 归还内存
 *
 * @param[in] size, 内存大小
 * @param[in] cpu_addr, 虚拟地址
 * @param[in] dma_handle, 物理地址
 *
 * @retval void。
 *
 * @par 依赖:
 * <ul><li>dpa_mem_layout.h：该接口声明所在的头文件。</li></ul>
 */
void bsp_dpa_rsv_cma_cache_free(size_t size, void *cpu_addr, dma_addr_t dma_handle);

#ifdef __cplusplus /* __cplusplus */
}
#endif /* __cplusplus */

#endif /* __DPA_SMS_H */
