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
#ifndef __DPA_DRA_H
#define __DPA_DRA_H

#include <linux/device.h>

#ifdef __cplusplus /* __cplusplus */
extern "C"
{
#endif /* __cplusplus */

struct dpa_dra_ops {
    unsigned long long (*dpa_data_alloc)(unsigned int size);
    void (*dpa_data_free)(unsigned long long addr);
    void *(*dpa_data_phys_to_virt)(unsigned long long addr);
    int (*dpa_dra_set_wlan_dev)(struct device *dev);
    int (*dpa_dra_remove_wlan_dev)(void);
};

/**
 * @brief 注册dpa dra内核API
 *
 * @par 描述:
 * 注册dpa dra内核API，注册后dra系列ops接口才能使用
 *
 * @attention
 * <ul><li>dpa host注册成功，内核才能使用dmi api</li></ul>
 *
 * @param[in] size, 报文长度
 *
 * @retval == 0,注册API成功。
 * @retval < 0,注册API不成功。
 *
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */

int dpa_dra_api_register(struct dpa_dra_ops *dra_ops);

/**
 * @brief 从dra内存池分配2K报文内存
 *
 * @par 描述:
 * 申请内存
 *
 * @attention
 * <ul><li>内存可以流转到其他子系统，但是其他子系统CPU不能访问。</li></ul>
 *
 * @param[in] size, 报文长度
 *
 * @retval == 0,没有分配成功或者函数不支持。
 * @retval > 0,表示分配成功，返回64位地址。
 *
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
unsigned long long dpa_data_alloc_ops(unsigned int size);

/**
 * @brief 归还2K报文内存到dra内存池
 *
 * @par 描述:
 * 归还内存
 *
 * @param[in] addr, 64位内存地址
 *
 * @retval -ENOSYS, 函数不支持。
 * @retval 0, 释放内存成功。
 *
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_data_free_ops(unsigned long long addr);

/**
 * @brief maa物理地址转为虚地址
 *
 * @par 描述:
 * MAA地址转换为ACPU看到的虚地址
 *
 * @param[in] addr, 64位内存地址
 *
 * @retval NULL, 函数不支持。
 * @retval 其他，返回虚地址。
 * 
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
void *dpa_data_phys_to_virt_ops(unsigned long long addr);

/**
 * @brief wlan配置device
 *
 * @par 描述:
 * wlan配置device，将dra地址映射smmu
 *
 * @param[in] dev, wlan device设备
 *
 * @retval 0, 成功。
 * @retval 非0，失败。
 * 
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_data_wlan_dev_probe_ops(struct device *dev);

/**
 * @brief wlandevice
 *
 * @par 描述:
 * wlan移除device，将dra地址解映射smmu
 *
 * @param[in] dev, wlan device设备
 *
 * @retval 0, 成功。
 * @retval 非0，失败。
 * 
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
int dpa_data_wlan_dev_remove_ops(void);

#ifdef CONFIG_DPA_DRA
/**
 * @brief 从dra内存池分配2K报文内存
 *
 * @par 描述:
 * 申请内存
 *
 * @attention
 * <ul><li>内存可以流转到其他子系统，但是其他子系统CPU不能访问。</li></ul>
 *
 * @param[in] size, 报文长度
 *
 * @retval == 0,没有分配成功。
 * @retval > 0,表示分配成功，返回64位地址。
 *
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
unsigned long long dpa_data_alloc(unsigned int size);

/**
 * @brief 归还2K报文内存到dra内存池
 *
 * @par 描述:
 * 归还内存
 *
 * @param[in] addr, 64位内存地址
 *
 * @retval NA。
 *
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
void dpa_data_free(unsigned long long addr);

/**
 * @brief 返回低36 bit 物理地址
 *
 * @par 描述:
 * 返回低XXbit 物理地址
 *
 * @param[in] addr, 64位内存地址
 *
 * @retval 低36 bit物理地址。
 *
 * @par 依赖:
 * <ul><li>dpa_dra.h：该接口声明所在的头文件。</li></ul>
 */
unsigned long long dpa_data_to_phy(unsigned long long addr);
#else
static inline unsigned long long dpa_data_alloc(unsigned int size)
{
    return 0;
}

static inline void dpa_data_free(unsigned long long addr)
{
    return;
}

static inline unsigned long long dpa_data_to_phy(unsigned long long addr)
{
    return 0;
}
#endif

#ifdef __cplusplus /* __cplusplus */
}
#endif /* __cplusplus */

#endif /* __DPA_SMS_H */
