/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
 *  @brief   飞龙架构2.0 maa模块对外头文件
 *  @file    mdrv_bmi_dra.h
 *  @version v1.0
 *  @date    2023.07.19
 *  @note    该文件增删改需通过接口变更评审
 *  <ul><li>v1.0|2023.07.19|创建文件</li></ul>
 *  @since
 */

#ifndef _MDRV_BMI_DRA_H_
#define _MDRV_BMI_DRA_H_

#include <linux/skbuff.h>

/**
 * @brief 重置skb指针
 *
 * @par 描述:
 * 重置skb指针
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  skb, sk_buff。
 * @param[out] NA, NA。
 *
 * @retval NA。
 * @par 依赖:
 * <ul><li>mdrv_bmi_dra.h：该接口声明所在的头文件。</li></ul>
 *
 * @see NA
 */
void mdrv_dra_reset_skb(struct sk_buff *skb);

/**
 * @brief 通过maa地址获取skb
 *
 * @par 描述:
 * 通过maa地址获取skb
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  addr, maa地址。
 * @param[out] struct sk_buff *, 获取的skb。
 *
 * @retval NA。
 * @par 依赖:
 * <ul><li>mdrv_bmi_dra.h：该接口声明所在的头文件。</li></ul>
 *
 * @see NA
 */
struct sk_buff *mdrv_dra_get_skb(unsigned long long addr);

/**
 * @brief 申请dra的skb
 *
 * @par 描述:
 * 申请dra上的skb
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[out]  NA
 * @param[in]  size，需要申请skb的大小
 *
 * @retval unsigned long long，已申请skb的大小
 *
 * @see NA
 */
unsigned long long mdrv_dra_alloc(unsigned int size);

/**
 * @brief 释放dra上的skb
 *
 * @par 描述:
 * 释放dra上的skb
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[out]  NA,NA
 * @param[in]  changed,需要释放skb大小
 *
 * @retval NA
 *
 * @see NA
 */
void mdrv_dra_free(unsigned long long changed);

/**
 * @brief 获取skb的dra地址
 *
 * @par 描述:
 * 获取skb的dra地址
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  skb, sk_buff。
 * @param[out]  unsigned long long，获取到的dra地址
 *
 * @retval NA
 *
 * @see NA
 */
unsigned long long mdrv_dra_skb_map(struct sk_buff *skb, unsigned int reserve);

/**
 * @brief 由dra地址获取skb
 *
 * @par 描述:
 * 由dra地址获取skb
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  addr, dra地址
 * @param[out]  struct sk_buff, 获取到的sk_buff
 *
 * @retval NA
 *
 * @see NA
 */
struct sk_buff *mdrv_dra_skb_unmap(unsigned long long addr);

/**
 * @brief 申请dra上的skb
 *
 * @par 描述:
 * 申请dra上的skb
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  size，需要申请skb的大小
 * @param[out]  NA
 *
 * @retval NULL, 申请失败
 * @retval 其他, struct sk_buff, 获取到的sk_buff
 *
 * @see NA
 */
struct sk_buff *mdrv_dra_skb_alloc(unsigned int size);

/**
 * @brief 通过skb获取dra地址
 *
 * @par 描述:
 * 通过skb获取dra地址
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  skb, sk_buff
 * @param[out] NA
 *
 * @retval NULL, 获取失败
 * @retval unsigned long long，获取到的dra地址
 * @par 依赖:
 * <ul><li>mdrv_bmi_dra.h：该接口声明所在的头文件。</li></ul>
 *
 * @see NA
 */
unsigned long long mdrv_dra_get_dra(struct sk_buff *skb);

/**
 * @brief 申请dra上的skb
 *
 * @par 描述:
 * 申请dra上的skb
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  size，需要申请skb的大小，
 * @param[out]  orig, skb对应的dra地址
 *
 * @retval NULL, 申请失败
 * @retval 其他, struct sk_buff, 获取到的sk_buff
 *
 * @see NA
 */
struct sk_buff *mdrv_dra_alloc_skb(unsigned int size, unsigned long long *orig);

/**
 * @brief 获取dra中的物理地址
 *
 * @par 描述:
 * 获取dra中的物理地址
 *
 * @attention
 * <ul><li> NA </li></ul>
 *
 * @param[in]  addr, dra地址
 * @param[out]  NA
 *
 * @retval NULL, 申请失败
 * @retval 其他, unsigned long long, 获取到dra中的物理地址
 *
 * @see NA
 */
unsigned long long mdrv_dra_to_phy(unsigned long long addr);
#endif